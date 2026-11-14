# chunk delivery - r1047_splice.py

Delivery v2 canvas (R1044 build). Every section below
is its own fenced code block with a per-block heading;
the machine-readable parts sit between @@B/@@E markers
so block copies assemble with or without fence lines.

## the gates

```text
GATE file r1047_splice.py 9dca5da6a7b962c9d317b3eb0d4a00c8
GATE tgz payload.tgz ebecba145a0a87159ccaeb49ec2756e6
GATE b64 07c7a2e2a949ed63fed4903a7c72b6a4
GATE lines 137
GATE chunks 3
GATE verifier chunkcheck.sh 0e456ab399aef922bcdf2cf33e578767
GATE chunk splitaa fb795ec879d43ef4b35c9f0585aad1b9
GATE chunk splitab 4a6b37c17b4be2e1fd3db27c07732b4b
GATE chunk splitac c8c7eab48f99247ff461c123027d9ed5
```

## the user flow (Termux)

Extract the verifier, then run it against this canvas:

```sh
awk '/^@@B chunkcheck.sh/{o=1;next} /^@@E chunkcheck.sh/{o=0;next} o{print > "chunkcheck.sh"}' canvas.md
sh chunkcheck.sh canvas.md ~/r1044_work
```

Expect `chunks ok: 3, auto-repaired: 0, unrepairable: 0`
and `CHUNKCHECK: PASS - r1047_splice.py md5 9dca5da6a7b962c9d317b3eb0d4a00c8`.

Panel-copy fallback: copy each block below in order
into one canvas.md (fences optional), then the same
two commands. The B copies auto-repair copied
single-char damage; a both-copies hit prints the exact
chunk:line for paste-back.

## the verifier chunkcheck.sh

```sh
@@B chunkcheck.sh
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
@@E chunkcheck.sh
```

## chunk splitaa (b64 lines 1-60)

### splitaa manifest

```text
@@B splitaa-manifest
1 e387f73d
2 b93f7dce
3 ad4f4040
4 091edb69
5 5fa0c4dd
6 2389cbe0
7 4f2ee0d7
8 633123a6
9 fa9ef184
10 9c4defdd
11 cbf0606a
12 dd4d41a5
13 0044b256
14 2adb71ac
15 e5e45811
16 f5d04fa6
17 a0ac545c
18 e097f9c4
19 11bd14f6
20 6787c6db
21 6525bdd3
22 87145492
23 0e53bde7
24 2a0c56c4
25 48a80de0
26 a8c7e0d5
27 c15c6d64
28 0248d221
29 5843fb5c
30 9e0b86e5
31 8876c578
32 ee1a5152
33 04210126
34 c5b36f08
35 ae63d03f
36 82d43429
37 d2252606
38 6e697d11
39 05187083
40 41986b15
41 0b5a3635
42 96b6cd23
43 31548fc2
44 7f2280ac
45 4368d0b1
46 bb106a44
47 8fac76db
48 2210474a
49 21452691
50 617fce71
51 c991cae7
52 56841da6
53 2384d0bd
54 5828253f
55 1840f519
56 d837454c
57 ebd4158b
58 d1098175
59 8fedd42e
60 c2465952
@@E splitaa-manifest
```

### splitaa copy A

```
@@B splitaa-A
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
@@E splitaa-A
```

### splitaa copy B

```
@@B splitaa-B
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
@@E splitaa-B
```

## chunk splitab (b64 lines 61-120)

### splitab manifest

```text
@@B splitab-manifest
61 ae052bdc
62 d36ed69c
63 275024c5
64 eaff7b3b
65 896ceaac
66 52241cf2
67 8e7442bf
68 f39597f7
69 e1a3f474
70 503c1306
71 603dee1a
72 b9be8c18
73 fef4c7ea
74 4df03471
75 d0a18ce8
76 57bed9ca
77 7454d9e0
78 5d855718
79 1d15387f
80 cc52e7ff
81 c5ef2c5a
82 3b5e5ffa
83 f98c64c5
84 30fb879f
85 4c3d5895
86 abcfe3a9
87 89617d2e
88 9337d624
89 64e0ac74
90 c1a042b1
91 33247d79
92 04e587d8
93 92ca410f
94 ea64d6a3
95 7e3dbe02
96 a52f812f
97 a941e7a6
98 3564f8ad
99 cbffb902
100 09217b48
101 2ec25fac
102 6a25f91b
103 2e62fd2c
104 a9debd07
105 8411006a
106 4504f48f
107 abda8700
108 1213c7f9
109 ce3f71ea
110 cc5f32df
111 b9eb843f
112 b2f9f667
113 fcd4f66d
114 d205f898
115 0a4ebd6d
116 bfcdba22
117 87a440ab
118 8462ac41
119 25cb32ae
120 68e39c0b
@@E splitab-manifest
```

### splitab copy A

```
@@B splitab-A
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
@@E splitab-A
```

### splitab copy B

```
@@B splitab-B
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
@@E splitab-B
```

## chunk splitac (b64 lines 121-137)

### splitac manifest

```text
@@B splitac-manifest
121 194c50c4
122 7c739d70
123 c33d7d70
124 5f64103b
125 7b2811fe
126 56a927c6
127 076fb32d
128 98e0b2db
129 188650d3
130 9be8d0b0
131 c8f463c3
132 64f2370a
133 8b16043f
134 507906b3
135 10e9c2b6
136 cfe10f16
137 9be928a9
@@E splitac-manifest
```

### splitac copy A

```
@@B splitac-A
p/6cDpbbjspGk9R8ZcgSPZVvqomSfJqrE1OLtAhHlkDhOxeb4nwQ46ukcMMn7vzE9z3dhKMPPlth
Z2Oxx/sxPHXIH1ZhCxLOXsbJNLIOHbzEstRC5dDASzwKJ8du+h5uEqseGciIgySnkyjxAb1JWFyx
puQeXAZBGydx/QqoTm+3dLLUuna9HqhzUEdFuz+ZeLI+BV5uvaurR2pvqk5SfhwCcuUppkgshXd0
C0Yj9/FNWu7wZ9Ok3KCWRZOUyCvAkVFHJAaoZwiUt+iNw+xDlPFLukqqyNdiORsLaMOwMm/yTWeH
wnfw4hoDl5IYuZdvx0IuQZrRK70UrbRykpWXnSML6uPOhRHy9VZTt98x5mRkqfc/v3v77Rvx01+M
R0xh7jLObSvG1uoQFaD1li+HsgxAJzfrl11Jpd1v2pCBJC2tw0neIIrLbpavGlFP6dVn1uOFG//0
+0lwD4bzmhN+e0rDIAnvVaQ3BJY1d7dvd43FQnsvsNfZud03F8PU5mMY7XH4IUKRL9mEhv48/XB4
nE2ljWFtcCg+2ie02LzkCr7xphJ9MpBzxMu5s4HdqUMftr94y46q9dg5AJMO1y7338+Ck7Pv5fgE
7r7tJZBcFr+HoSYn+81dhFzyvnwdlXbttGJt0xKUeTx2VV3qEaeFD2CZG9B0/Lq60g8pD2cuma2y
perHNIlc9AmNkxo+OXMrJui6bVmmvMyp3R2fWQ3YdZu7Nusrn1GvFEPzyNptOu6bpYTEk8/8jm7D
fqFkjc4ZII+ucqDYLO1pO/BUoMn18PMSzho8WYJfmBbdnEvdZR3YxcpFy2VNc6jlmhreaJAfGO2V
ZXSTSiPaR4EYusxui3Rms4Q0WpOPnOZkKZaALMSTEpbZbT1nqcOUrxoMPXMvOXAPfjWwxJdVWkjy
c+kQDMU8r8I5SY4iTX0+hf36S+c9A2Id30Sxd25sAswi8gzM92JWgPQRF3s6BmUc68/jgGf6uLly
yYTx3WgYtS6B9vq8F3iWR28AXob+lUQzTs7QdLcIag0APAhmuAhSgPkeHe/eeoV/eQ8xB/ggxgX4
6Elurwn6lnOgfQV6bWhQ64DQo0/xP1SdjRqfqdMkyYKAWewIPO0bD3sl9eMYflUGZIafexYJTO+q
0WA3tfFkda2u1bW6VtfqWl2ra3WtrtW1ulbX6lpdq2t1ra7VtbpW1+paXatrda2u1bW6Vtei6/8B
Hncm8wCgAAA=
@@E splitac-A
```

### splitac copy B

```
@@B splitac-B
p/6cDpbbjspGk9R8ZcgSPZVvqomSfJqrE1OLtAhHlkDhOxeb4nwQ46ukcMMn7vzE9z3dhKMPPlth
Z2Oxx/sxPHXIH1ZhCxLOXsbJNLIOHbzEstRC5dDASzwKJ8du+h5uEqseGciIgySnkyjxAb1JWFyx
puQeXAZBGydx/QqoTm+3dLLUuna9HqhzUEdFuz+ZeLI+BV5uvaurR2pvqk5SfhwCcuUppkgshXd0
C0Yj9/FNWu7wZ9Ok3KCWRZOUyCvAkVFHJAaoZwiUt+iNw+xDlPFLukqqyNdiORsLaMOwMm/yTWeH
wnfw4hoDl5IYuZdvx0IuQZrRK70UrbRykpWXnSML6uPOhRHy9VZTt98x5mRkqfc/v3v77Rvx01+M
R0xh7jLObSvG1uoQFaD1li+HsgxAJzfrl11Jpd1v2pCBJC2tw0neIIrLbpavGlFP6dVn1uOFG//0
+0lwD4bzmhN+e0rDIAnvVaQ3BJY1d7dvd43FQnsvsNfZud03F8PU5mMY7XH4IUKRL9mEhv48/XB4
nE2ljWFtcCg+2ie02LzkCr7xphJ9MpBzxMu5s4HdqUMftr94y46q9dg5AJMO1y7338+Ck7Pv5fgE
7r7tJZBcFr+HoSYn+81dhFzyvnwdlXbttGJt0xKUeTx2VV3qEaeFD2CZG9B0/Lq60g8pD2cuma2y
perHNIlc9AmNkxo+OXMrJui6bVmmvMyp3R2fWQ3YdZu7Nusrn1GvFEPzyNptOu6bpYTEk8/8jm7D
fqFkjc4ZII+ucqDYLO1pO/BUoMn18PMSzho8WYJfmBbdnEvdZR3YxcpFy2VNc6jlmhreaJAfGO2V
ZXSTSiPaR4EYusxui3Rms4Q0WpOPnOZkKZaALMSTEpbZbT1nqcOUrxoMPXMvOXAPfjWwxJdVWkjy
c+kQDMU8r8I5SY4iTX0+hf36S+c9A2Id30Sxd25sAswi8gzM92JWgPQRF3s6BmUc68/jgGf6uLly
yYTx3WgYtS6B9vq8F3iWR28AXob+lUQzTs7QdLcIag0APAhmuAhSgPkeHe/eeoV/eQ8xB/ggxgX4
6Elurwn6lnOgfQV6bWhQ64DQo0/xP1SdjRqfqdMkyYKAWewIPO0bD3sl9eMYflUGZIafexYJTO+q
0WA3tfFkda2u1bW6VtfqWl2ra3WtrtW1ulbX6lpdq2t1ra7VtbpW1+paXatrda2u1bW6Vtei6/8B
Hncm8wCgAAA=
@@E splitac-B
```
