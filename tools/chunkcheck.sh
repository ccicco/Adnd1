#!/bin/sh
# chunkcheck.sh - the delivery-v2 chunk canvas verifier.
# Usage: sh chunkcheck.sh <canvas.md> [workdir]
# Extracts every @@B <name>/@@E <name> block, reassembles the
# b64 payload from the A copies (auto-repairing damaged lines
# from the B copies against the per-line LH manifest), gates
# every chunk md5, the b64 stream, the tgz and the file md5,
# then unpacks. Exit 0 only on all gates pass.
f=$1
[ -n "$f" ] || { echo "usage: sh chunkcheck.sh <canvas.md> [workdir]"; exit 1; }
[ -f "$f" ] || { echo "chunkcheck: cannot open canvas $f"; exit 1; }
case $f in /*) ;; *) f=$(pwd)/$f ;; esac
wd=${2:-.}
mkdir -p "$wd" 2>/dev/null || { echo "chunkcheck: cannot mkdir $wd"; exit 1; }
wd=$(cd "$wd" 2>/dev/null && pwd) || exit 1
cd "$wd" || exit 1

# ---- extract every @@B/@@E block -----------------------------------
awk '
/^@@B / { out = substr($0, 5); of = 1; next }
/^@@E / { of = 0; out = ""; next }
of { print > out }
' "$f"

# ---- the gates -----------------------------------------------------
g_file_path=$(grep "^GATE file " "$f" | tail -1 | cut -d" " -f3)
g_file_md5=$(grep "^GATE file " "$f" | tail -1 | cut -d" " -f4)
g_tgz=$(grep "^GATE tgz " "$f" | tail -1 | cut -d" " -f4)
g_b64=$(grep "^GATE b64 " "$f" | tail -1 | cut -d" " -f3)
g_lines=$(grep "^GATE lines " "$f" | tail -1 | cut -d" " -f3)
g_chunks=$(grep "^GATE chunks " "$f" | tail -1 | cut -d" " -f3)
if [ -z "$g_file_md5" ] || [ -z "$g_b64" ] || [ -z "$g_lines" ] \
   || [ -z "$g_chunks" ] || [ -z "$g_tgz" ] || [ -z "$g_file_path" ]; then
    echo "chunkcheck: missing GATE lines - canvas incomplete"
    exit 1
fi

# ---- reassemble, per-line repair from B ----------------------------
ok=0
repaired=0
unrepairable=0
: > payload.b64
chunk_list=$(grep "^GATE chunk " "$f" | cut -d" " -f3)
n_seen=0
for c in $chunk_list; do
    n_seen=$((n_seen + 1))
    g_c=$(grep "^GATE chunk $c " "$f" | tail -1 | cut -d" " -f4)
    a="$c-A"
    b="$c-B"
    if [ ! -f "$a" ] || [ ! -f "$b" ] || [ ! -f "$c-manifest" ]; then
        echo "chunkcheck: $c copy A/B or manifest block missing"
        unrepairable=$((unrepairable + 1))
        continue
    fi
    awk -v a="$a" -v b="$b" -v c="$c" '
        BEGIN {
            na = 0
            while ((getline l < a) > 0) A[++na] = l
            nb = 0
            while ((getline l < b) > 0) B[++nb] = l
        }
        { H[++m] = $2 }   # manifest line: <lineno> <hash>
        END {
            rep = 0; bad = 0
            n = na
            if (nb < n) n = nb
            if (m < n) n = m
            if (na != nb || na != m) {
                printf "chunkcheck: %s block drift A=%d B=%d M=%d\n", \
                       c, na, nb, m > "/dev/stderr"
                bad++
            }
            for (i = 1; i <= n; i++) {
                cmd = "printf \"%s\\n\" \"" A[i] \
                      "\" | md5sum | cut -c1-8"
                cmd | getline ha
                close(cmd)
                if (ha == H[i]) { print A[i]; continue }
                cmd = "printf \"%s\\n\" \"" B[i] \
                      "\" | md5sum | cut -c1-8"
                cmd | getline hb
                close(cmd)
                if (hb == H[i]) { print B[i]; rep++; continue }
                printf "chunkcheck: %s line %d needs paste-back\n", \
                       c, i > "/dev/stderr"
                bad++
            }
            printf "%d\n", rep > "rep.tmp"
            printf "%d\n", bad > "bad.tmp"
        }
    ' "$c-manifest" > "$c-fixed"
    rep=$(cat rep.tmp 2>/dev/null || echo 1)
    badn=$(cat bad.tmp 2>/dev/null || echo 1)
    rm -f rep.tmp bad.tmp
    repaired=$((repaired + rep))
    if [ "$badn" != "0" ]; then
        unrepairable=$((unrepairable + badn))
        continue
    fi
    h=$(md5sum "$c-fixed" | cut -d" " -f1)
    if [ "$h" != "$g_c" ]; then
        echo "chunkcheck: chunk $c repaired md5 $h, gate $g_c"
        unrepairable=$((unrepairable + 1))
        continue
    fi
    cat "$c-fixed" >> payload.b64
    ok=$((ok + 1))
done
if [ "$n_seen" != "$g_chunks" ]; then
    echo "CHUNKCHECK: FAIL - chunks seen $n_seen, gate $g_chunks"
    exit 1
fi
echo "chunks ok: $ok, auto-repaired: $repaired, unrepairable: $unrepairable"
if [ "$unrepairable" != "0" ]; then
    echo "CHUNKCHECK: FAIL - repair flagged above"
    exit 1
fi

# ---- the stream gates ----------------------------------------------
nl=$(wc -l < payload.b64)
if [ "$nl" != "$g_lines" ]; then
    echo "CHUNKCHECK: FAIL - b64 lines $nl, gate $g_lines"
    exit 1
fi
h=$(md5sum payload.b64 | cut -d" " -f1)
if [ "$h" != "$g_b64" ]; then
    echo "CHUNKCHECK: FAIL - b64 md5 $h, gate $g_b64"
    exit 1
fi
base64 -d payload.b64 > payload.tgz 2>/dev/null \
    || { echo "CHUNKCHECK: FAIL - base64 decode"; exit 1; }
h=$(md5sum payload.tgz | cut -d" " -f1)
if [ "$h" != "$g_tgz" ]; then
    echo "CHUNKCHECK: FAIL - tgz md5 $h, gate $g_tgz"
    exit 1
fi
tar xzf payload.tgz 2>/dev/null \
    || { echo "CHUNKCHECK: FAIL - tar unpack"; exit 1; }
if [ ! -f "$g_file_path" ]; then
    echo "CHUNKCHECK: FAIL - $g_file_path missing after unpack"
    exit 1
fi
h=$(md5sum "$g_file_path" | cut -d" " -f1)
if [ "$h" != "$g_file_md5" ]; then
    echo "CHUNKCHECK: FAIL - $g_file_path md5 $h, gate $g_file_md5"
    exit 1
fi
echo "CHUNKCHECK: PASS - $g_file_path md5 $h"
exit 0
