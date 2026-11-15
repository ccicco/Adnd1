# chunk delivery - r1058_splice.py

> **THIS is the R1058 canvas (take 3).** Tool md5 `e6bcd985bedb669d8f0c866da6bf77d4`. If chunkcheck says `r1057_splice.py`, you saved the older round's canvas.

Delivery v2 canvas (R1044 build). Every section below
is its own fenced code block with a per-block heading;
the machine-readable parts sit between @@B/@@E markers
so block copies assemble with or without fence lines.

## the gates

```text
GATE file r1058_splice.py e6bcd985bedb669d8f0c866da6bf77d4
GATE tgz payload.tgz d34d21997547adbcdfff4ab757c62b7f
GATE b64 ec7a60517d883a65d2511be1d0d0ccce
GATE lines 392
GATE chunks 7
GATE verifier chunkcheck.sh 0e456ab399aef922bcdf2cf33e578767
GATE chunk splitaa 08ca8d4b5ec3b9d9111c41adbd4bc5f7
GATE chunk splitab 3d53e642e454e08292e318edf49a8577
GATE chunk splitac 5e70e8dc0dc92b33af919027cd50a40d
GATE chunk splitad b820417cd1f2b609b32139eecf8d29e7
GATE chunk splitae 7b53fbe6bc8d4feace91e6a0ec827878
GATE chunk splitaf 69bd3d4cc15f14683ad7acddf4e12759
GATE chunk splitag bca4639062043c6d996352b626387e9f
```

## the user flow (Termux)

Extract the verifier, then run it against this canvas:

```sh
awk '/^@@B chunkcheck.sh/{o=1;next} /^@@E chunkcheck.sh/{o=0;next} o{print > "chunkcheck.sh"}' canvas.md
sh chunkcheck.sh canvas.md ~/r1044_work
```

Expect `chunks ok: 7, auto-repaired: 0, unrepairable: 0`
and `CHUNKCHECK: PASS - r1058_splice.py md5 e6bcd985bedb669d8f0c866da6bf77d4`.

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
1 85952285
2 9e42884c
3 a9449a1b
4 b736bffb
5 99848385
6 9eb3ad9e
7 bb3e7b1e
8 f22d91a7
9 a9beae98
10 3e985829
11 a445e465
12 4643b842
13 c5de50cc
14 6a2166f6
15 79824438
16 c7fca366
17 86acd7e0
18 ff297259
19 79fd23ee
20 f026f5cd
21 36547a2f
22 58404549
23 7f09d2ba
24 46f7ff07
25 131a93f5
26 62730cf5
27 6b29cba1
28 4286bb86
29 f18df99f
30 d266f1ed
31 ba89891c
32 65e64381
33 713f345f
34 868e77cc
35 6ed0aed1
36 10b30dbf
37 5a4b2ff8
38 7a0afd39
39 91e80e27
40 5858cc1b
41 d880d013
42 65943b2c
43 17608800
44 15d48655
45 cad361d7
46 215b36a7
47 ae6b55dd
48 238a2dbe
49 2bd4a811
50 57e7af79
51 2914e97e
52 990c0a1f
53 b546c4db
54 f5e022f0
55 759b33e3
56 94045d5f
57 6e08a249
58 aec06b46
59 fd27df87
60 fafb055a
@@E splitaa-manifest
```

### splitaa copy A

```
@@B splitaa-A
H4sICBbk+WoC/19kcF9wYXlsb2FkLnRnegDtvX1b28b2KLr/9qeYrZwUKdgGkzZpTWkPJaTN0zTJ
BXK67zWuj7BlULBlV5KB7CTf/a61ZkaakWYkmZDulx9+2gCe95k1623WS3eru/W/3/g3vwT+JIj/
9kU+2/xj+7m9/fjr/Hf8vre909v5G7v521/wWSWpH8Pwf/uf+dn5ls3TcB7s9Z5+9/XTJ72n32x3
t5989/jbp09bf7v//Nd/4t72N9+OkuUsHAfd5fsvdv+ffP21+f4/7n399Gnvb71vdp4+efxkZ3vn
Cdz/nceP4f5v/5X3P14s0sqNqin/D/08+PvWKom3zsJoK4iu2PJ9erGIHrcesAJgsA5LLwJ2hN8y
/i1USheLWZ8Kfj/cf/P61XFn6s/D2Xs2CTrXYYxVFlPW67FxvEiSztlicckuiNIkUOR+/R2LgzSM
w+ic+XHsv0/a7Am7DJYplCZpvBqnW7PFeThmSeDPExoJSq4Df7mIZkGSsN+zX0/CIMYZxeGizS5/
W0SXL/0JDNRmfjQRDS9/Cydbl7+E5xfsDL8NJudBwsIoCSdYPIWCNIh/jher5X6a+uPLxOu2HkDJ
77/sn7AXJ+zZ68Nj5sariE3jxZwWHgfLBW4XgEebQT/z5SINotTrw5cMdm3pxwkMglWV5VIhgzX6
KayOr535tEtirviBjRO7xdxe5xkbz/z5MpiI0unMT2HDsOfBztfDwdPhFv38erglagyebA8Hvd6Q
7R+w8zic8Nqy8PFw8O0Q5ge7NMHdxlPAWm1RATvuPZYlkT8P5CEpFfDrzmXwnncBBwYdhrGoMAuT
FAGAH9jxMggmz/1xuog9UWE5WyUsuAri93Tq7J9BvOj4cbY9Y3/mx3SAHAymEXN9WRjM/Qh377fX
zw5f8n1Yxoszub5ksYrHgSeO4ToOUziG8SLC09lK/TMAGrlPfH4TP/W3mJ+w3lOA3yls1uMncqVU
vS2mCoUbCZz4dcL2RIUwTfhJT/hG0crdhdyIg9e/vXl7cviMwG4LWlKtRE4OoDvlIPLq8HflrmQr
9ecsXuGE6R7o007i4Lx7wdzro+B86/oIZpWVn+C029nFfcJWPlSGqcXv5QHEwTiYwI4wP1WHkDOL
A7FxAn798Rju2oKuL37OgouQXy+aJdy8IFjm8M33KwnPIz9dxTAVgmA8UNk+9qPxhRgsmIdiGzia
Kcx1Gvvnc5yq+y2b+WfBDA5kHETJKsmuC1yYzg/48zuPoIZvLPQqjykaz1aTgBYbnMO60u54uez3
Hm8/oXt+AmPjLFI4x7PFJISF44LErREHTGtIGCztDG7vfFfcEKgwg62K/RmAGVyU9yxawHkDEpn5
CS4xAHBeQo+uXOFT9urtS4bIaxF5u4i8oMCfxXDl33f8JSBZGG3ppxcwQjibIZZZRYAmoOT9CO/L
aBrerJa8RyjlfY59GAfWKPrttloh4KQYLmIifwPELH5L3iet1tHr1ydsD8q750E6vp64Xuvo8OeT
w2P81lE2ymm9fLs/evbiCL8vXKX8Djmt50f7P0MV1+EQ5a8mcARbTouJj8OJi4DfkTzn7oXjtfbf
vHn54vDZ6Lf9o19xmK0tAQ1iQ5zWweGr47fHo58On78+OoQqeOzyy/3nJ4dH/LvvWi9eHYz2Xx38
8hq/cTdw5AcSAvSpbWRT458NnODT0cpPlsFsps2wVJUxMcWnG7Bvr9++eobjw4xbrecvXgK92GOD
Fl81Dbny4T++dNo66LNdKp+HSRJayi4Asi+C2cRYGAXXYlsNxaJkGYyNbQF7TosFk/n51tzSI5Zl
XQYTezGCYrF0eXEmSk3DYqnPSTBQ44j3PWy1xCUBDEz4t89c/BXoT5v+RraBo31AJ05MtLP//TT6
wYFT0C5xTs6QQKUXhBGwOvIB0S6C93y5AjzQ/x5wJNyzH/rfzxbwD/QFVfaYLOeYHG+vwwkg/a0O
KoYkBiNO0o4gqNMQzpAPHrBfD9+cZDwPR/h8FvANddaG/7pdMXbeaUYxcyQ0jZINiYmQ31jFUdJ6
dvh8dPT69xwYXec6ddrZHgFEpq9g4o7XFsUAg3qFuaHCCI5OHJxW88hPg9fT58ABFuv70XkwSsxt
oOj4ArCSsc3c2ua3YBKu5sZGM2ujl4voXG1ycaEt9uKiuNiLi9EsiM7Ti3KXFxcveYlePVn648BU
+xgLjoI/V7A/E7VRdK1NIrrWJ3GNN3c0XsxK+ydQq5MxWmMi/QeL2WoeGTrJ2mdQjozJqL/df1wa
DhFg0/Gg7q/R4jpSF7WcaotaTvX5zGnN2TzgFtM0nujzgH2SU0D+MumXWEqlPh+x2GVvG6sgDoHL
QBdhwqaLmE3abASMAZNXZCiRTCaahMgeScYH+XoXLiPc3xkwPWkATA/gIOCy/PM2xyhQg9ALdIr9
ACMB6OkS+KQ23lrBXeHf1BkXRdwZiC0Xoddn58CkTRJxcznfMlt0ruAyb4G8tezggewSsuKFA7z9
HagzxL9RKOhLQYENwuEum/qzGfIhvDo2d7fb28ThIbu/A6wjTHwxhTWc0b9AfSLB4/tz/wa+xi/g
X/8G5qeM7PodbOc9umabzD3rYHNvCHT3ZPT8lYprEL28SF4F11xey8HJSBGzYo6iwmQEVA1/u8xK
cJnwjespgHadvrk4OwbU+SKaBDfrjQH0ZoRYt8kovwcoJ/4WrrmMa2o2mmO7xoP4N7cbBNvVD/IM
jhdw7m9rryWZN11HNsS6K8Eh1lnFy7UXMVtvDS/XXsKs2QrmdVdDMINZkSTNTS+GIHlvAJmlCiJt
MAKnostCw0ssMg+0P96fvFslKcpp6wzkj0d+uSENRDhKfuU+bbNt+d/OY/rxxD4FVPU0n4b4Q5vL
6ELtwjChr8sTeuxpjIBCpCwwKjl6ZT6cHyHK1wxM9XHMoFo3ThNohXGC9NliBeD+fOafrzdMkI4m
1LQeli4unoXJHHj/dO1hJqJhk8XUAax1kMYQ2+spEPLNd/Sjt+1pbN+L6Gd/+QJ4iZcgZpqmkYt1
ykQ4uxhGo3N/WbfWAqf2Eyzr5eK6PFQuIubIjP/FHOIRZ4vrW4xlvoi1g5Uvn+kUl1NB+I9MK+Jy
rbJtnD1sTvE5x/oi2U9BxDpbWVCocRC/3KRiFS+iMA392fFskSaNhwh5o1GitaoY5dUiegMdvQki
f5a+bzxOxAX10bLQrmKkfdQsHwDfH6lyUN2WYaPRuNCqftf2gRWPw+Sy4UDiD7l7frG1ZcA5Klhf
LgqDqEqSrIgLNih8zBb4W1oBZNTtL+F63V6E9d3+Y/l//NkqaN7xzXJ0xVvUdX3sz4Kfl817TqD+
6HxZ3/H/k75fZ4f/TN832mHodp0dxm7rd/i68tbqOq4cx1Xd3NQMeNc1F7d6KNvltQ9WcXerhzLf
39JAuS4vE7OFXoxrCuxyNlfaoYDdFmJ0WawWneCrGUrH/NVhtuh2QcImyZaXj6LVbMbcBPtigKbl
65g4mfCf0MWFn7BtkpoTfFtwHK0DwBoRV+iT2M6A8gcJ83kNFOAZ1vDj97wVPcKlMC9/u9v1e+yG
ncEvZz3xCodV1Ic4kubTIAJJHi58Z+6/W8TUj+OIGc2Cc3+G6vr9Z4dHRYmbFC1rSSyXuaom418c
vATIZj/V+Wxb7zYWv6rvncdFeSXTHzYcgWsiVVIuh6oaJdM4Nh5F6i9vMZLQU6431PxWQ5F2c72B
ZusNJBSk63DMVQDwzXd65y8Lqtaa7jPVbPUSiqPoitjGgwnF7jpjCVXuepx91Yb1vrHy21I5q2h/
G3PeQrtcvbSn9UNniuA1RuaKZnVogS7zxaNQIKBRfId63llpWpmauSnXWbnVjw3rzdTOZYZCeRLT
loh/qtyEpEHKPF2H/yUp5MsXx5kqNdNL41uR+lIkSGVOJqWumiH55BWFSppeydgYheM2G/AXKHqv
GnqtXw8P34yOT47eHpwYxqM2+LZEX50DTYrDMVSYLybBjI39KFqkLEDWEVA3arMXSyjlb+hen1Ny
TqvxiZiUz654MKNpwNZos2XZKtosn2ebz4OaAzGmPxJ8Qwv88QUDuT8NI9GckdqeNyWOlg+ZQTOO
lrEe/Fuu8+YjlLsXvcpBJIuh9A1cFjIUhc6pnRhA6Rwqd4L5MpXWDXQMvJ9pHPyp7Ue2F8Is4wfB
JXDmJptlbtuDPUAB3v8WHt/o4PXbV4VjRQOCzjRiwoZA2huki4wvQ9MP4D5yGySxDbmVU58ll+ES
XxquL4JITGABO54GNykLE3a+iAKPT+H5i3+8fSOngHYEJy9OXuL7/YeW5ED6uYXA233GddkduPKd
CWlgmWJBQNwLvfnKh2PiM/QeBLlj5srEMpgbxD7avMCWKiNOc25E5wXMXSTIV6jtqXpi6GFu6WFO
/EKjLmaWLmbAB1R1AIRZbygJntgytam2eznJtbTnSFDtgNfX++CU1NIFFWpT0Ck1p5N6Y6CmnfLQ
8QLFe9lMIXRKY9EKy4j199NQ74TvCL9UidbXWt3MgitAmEjIksKEiP6t09UlUlimPtByeqZvCdK7
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
61 752ca28f
62 9882a33f
63 3eb4bd3d
64 2f1a7c5f
65 900082fa
66 cf1e35e6
67 f8322c26
68 dde0d109
69 961c23e7
70 9ae3023c
71 ead4742f
72 e11809f5
73 9210e9f3
74 5ea21740
75 eddb22a7
76 61c971d3
77 3471aa80
78 ea2832d1
79 1a6a0fbc
80 0696703e
81 dbea7013
82 a0f6cdd7
83 8962753f
84 bae5815c
85 9270cd6b
86 2c60b0a4
87 68a584d3
88 ef811e3b
89 15c62802
90 8097163f
91 eccdb5a1
92 b8bd46c2
93 9a300675
94 48893151
95 417fcc90
96 2abf8b3a
97 070fe11f
98 d1ea12e5
99 6aca2b77
100 8482507d
101 ce1ea872
102 9272b9dd
103 ed47a1b0
104 9032a103
105 b470dd2d
106 aa0e7686
107 db512540
108 a48030b4
109 35184e64
110 e9d51ead
111 34d0d987
112 0362b459
113 843bba71
114 6c8778d0
115 efcf2375
116 1c909ff4
117 8af61ff7
118 4e0bbc1e
119 a1b6e79a
120 65ecd9e9
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

## chunk splitac (b64 lines 121-180)

### splitac manifest

```text
@@B splitac-manifest
121 54501d2d
122 28b4f097
123 4a150169
124 ae15afe6
125 7b9e4bfb
126 6590c197
127 bdde915d
128 8a230e9f
129 ffae6160
130 1e1c6554
131 1784c3da
132 45d20c91
133 c7a724f2
134 a541f101
135 1d667e78
136 48499af4
137 5bce11c7
138 ee2ff157
139 8c1c324b
140 42a91b8e
141 3c0246d1
142 83f43ff4
143 2b10b9a5
144 fcc5b3a8
145 2fda5cbe
146 eb1f996b
147 8eb0dae3
148 3c1ddac4
149 b046ea72
150 9d6ca813
151 ba52c89e
152 634ae749
153 dac3ba0c
154 7543f032
155 c18152ad
156 9c471306
157 8575359d
158 595ca6c6
159 68ab53f1
160 42f55fe7
161 7b2a858c
162 33fbe633
163 1328c1bb
164 b5fbf0ad
165 5db0a124
166 415e7629
167 670f9685
168 3de160f6
169 58fea656
170 a81e3fae
171 6af18f62
172 00e3ddb1
173 f968110f
174 b4739629
175 bdfc4e66
176 aa87e037
177 8d4d3d44
178 b80a2d14
179 92774bf8
180 62cd2ca1
@@E splitac-manifest
```

### splitac copy A

```
@@B splitac-A
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
@@E splitac-A
```

### splitac copy B

```
@@B splitac-B
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
@@E splitac-B
```

## chunk splitad (b64 lines 181-240)

### splitad manifest

```text
@@B splitad-manifest
181 255d21b4
182 7dd93067
183 5bf27a68
184 2109c9ff
185 1153fc2a
186 2f2d58d9
187 58b22a92
188 37b3e816
189 a1f6fb57
190 db749af7
191 560381d2
192 d4b0eb74
193 b93eb6ac
194 3f4d570e
195 952ce818
196 891353fd
197 d850aa70
198 38c245b2
199 11e985c1
200 cf6de3b7
201 6e90e0b9
202 fdc1adc3
203 8badc88f
204 bba66915
205 51a37b6c
206 5a5cd030
207 ae533c31
208 246a1ed7
209 20f5af7b
210 dd8c2452
211 d7ec8cbe
212 ff7eabdb
213 124963fa
214 e45c6a58
215 bd90bbd7
216 4deedc3c
217 ea7fa187
218 2481bec8
219 b5fd2783
220 721e0ab7
221 de004e66
222 d8449eb9
223 eaa59707
224 4abe838f
225 86ec843c
226 b6b22bde
227 6b6325b4
228 925ea1c2
229 e0c0a0da
230 d71603ae
231 5c416bd0
232 53b572ef
233 e91ad17d
234 b4ae9a6f
235 01b057cd
236 81a9c732
237 284f603a
238 70c90884
239 b6f3a4b7
240 596c1d86
@@E splitad-manifest
```

### splitad copy A

```
@@B splitad-A
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
@@E splitad-A
```

### splitad copy B

```
@@B splitad-B
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
@@E splitad-B
```

## chunk splitae (b64 lines 241-300)

### splitae manifest

```text
@@B splitae-manifest
241 3ec3f549
242 3815638b
243 ebed7fe1
244 7f0bba4a
245 11027645
246 090d1da3
247 6143d355
248 ab3e90e4
249 ce16d2f9
250 0b58327c
251 100cada7
252 50e33c82
253 14a83797
254 4c86f539
255 931f3c3d
256 1a505d89
257 23892ddb
258 e578c9c4
259 d4dcdfe1
260 63057cfa
261 e02b302e
262 3e35432e
263 2d19fde0
264 e03157aa
265 4bd0bae1
266 7ccb0560
267 75823fbb
268 522beee8
269 83cdc93d
270 3398c93a
271 4f9d3814
272 54c1aa8b
273 3b37a45d
274 84381e9a
275 6908bfe9
276 ad21b41d
277 6d84a060
278 d780aedc
279 2f843cdc
280 808e6104
281 52ae77a8
282 df744bd3
283 6311158b
284 4626e968
285 8b1fa6dd
286 64ef3a7a
287 2ffd2d94
288 bbd8d865
289 ae760078
290 807bd6d4
291 90b69730
292 13152f16
293 60e7328a
294 26590571
295 16355928
296 1bd58a95
297 63f26cc8
298 0e0bfd80
299 c330cfb4
300 f95abfb8
@@E splitae-manifest
```

### splitae copy A

```
@@B splitae-A
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
@@E splitae-A
```

### splitae copy B

```
@@B splitae-B
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
@@E splitae-B
```

## chunk splitaf (b64 lines 301-360)

### splitaf manifest

```text
@@B splitaf-manifest
301 ed63b63c
302 e5c3e61c
303 5abbfbf6
304 e10c207e
305 73d94510
306 055992ed
307 d4c145a6
308 d8172f14
309 1a5696a4
310 fb098253
311 e34f2963
312 c6ec32ea
313 9560dbd5
314 23f6c49d
315 078e33f6
316 32d47475
317 e4c5eb98
318 f7e8111d
319 744d2d26
320 5aa9c627
321 109cfc65
322 f5a7d337
323 31bb2dc7
324 8c040ac6
325 cdb117ee
326 bcff3720
327 a4ca4582
328 7f93ed13
329 af413b4e
330 34693424
331 67d98f4f
332 6fcc8e82
333 c2692bf0
334 ca0fee1b
335 1b4d1df5
336 cc273fe5
337 fae22741
338 99d216fd
339 533d920b
340 fc20afcd
341 9813354c
342 bc9c3297
343 26c72a97
344 702b9d0f
345 e3f1713f
346 928b7fde
347 4731165a
348 eee8f413
349 2d9c62de
350 1730198c
351 b2f36a56
352 5d92a329
353 cc42bb9d
354 50abe94f
355 f2f50aed
356 deb8a9b5
357 13f9c892
358 c83c51f1
359 a8f55b00
360 319cc55f
@@E splitaf-manifest
```

### splitaf copy A

```
@@B splitaf-A
+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
@@E splitaf-A
```

### splitaf copy B

```
@@B splitaf-B
+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
@@E splitaf-B
```

## chunk splitag (b64 lines 361-392)

### splitag manifest

```text
@@B splitag-manifest
361 cc0e1eb8
362 bd546244
363 1aef0504
364 73bffa46
365 a3a6611f
366 3b218761
367 0d0df096
368 8c734cb9
369 207e3308
370 dc99f882
371 e6792784
372 622f4d85
373 5d8d0247
374 d55f36ef
375 04c5abc7
376 df81c0d8
377 b5cb072e
378 c21173e3
379 df1c71a7
380 dcfe6318
381 9b87264d
382 339acec7
383 ea05f18e
384 0eb674fb
385 c048ec8c
386 ba315735
387 9824ab12
388 ae284185
389 93d19bfc
390 2d86c402
391 46b959de
392 cd12cd95
@@E splitag-manifest
```

### splitag copy A

```
@@B splitag-A
rNJqtR6QV7ZgAmfTToKmkp2KT6vFncJnUzRsj9xlW+gs28zkyDCN/XNxTHDOuchpic279NMLqLRI
uvibYQlHr1+ftNnLt/ujZy+O9MEohkF3tvKV/RDsmOwvuAmT1JCCDAsLpA5mK6VOB/q0g/Emm9iL
HDYPkwToVQHAS8ZBaNewgNFcmgqlTHO1ZbgblwEaAVKeUkPylIlHK0WL0uqFYDdVi9FH5ZFAGOKr
ti1XT5YJ18AENpsTBcJpNilKFIghjvm7gYnxVIIrV0YYFIBbtn11Nygrk22z+crRNdqyPNMSaaxq
ZFgBSQKattBGIctQy2U34RvSJwN48X2S+mk4FsGZhU2bNE54UJb2uIxHpWTtIJrvsQ/ZfBzucQbb
lXQvnD57nG+s46epP75MYsCmE7XwU0tjyZ+/eHmoXHWydt0DSSlZzsLUhbV5g47yfM1tZoXNK12N
OqwAvJe4OCq4rMiGguDUYrIZO9p+gbwDYyt9CMNDZWvKqh4uy25rl4ePDbQeO7BeAJNwimMQcJfh
ZTMzE+5bSmOXBvZaJnRktE7azI2mVMii+PQcvBiS0ESU/fT65Bc29efh7D2bhDH/OrmQGMx8TPyI
OF++RfC2pUggArwSjCJ/4XgaAqQbv7gkic25PgrOXVOcSygBJOIaSyg2lrlICR3fV88OBxSXO7mw
Iy/aogrEBd2oO4rUcC61ybiumU+pT3hYj76OeTHxwLciYVYROzqxDM0PzKa/moRpERocJLcPH05O
gc4jnvbPKtAzzsu+SCytWiT2XUXUCaPiyVK4dlN2MPIG5kTsc+aI/TcgI5VRUciySrwRawlA9LA8
I8AiZSzAQ/Jo3AfeuN7tAWgaVTEXeEuqWuO1jryKHm6c8paUjBD+Z27JAzYOomTFsRuSIv4nFxoE
aoLVjHE1B4evjt8ej/afnxwe5QtTF8UbAxdlcc4SyWgF/w4tgTcvby9/xsi49rkfVjPrBa4d67sC
zxU44zCZhrOCMbKd3uYI/ejw55PD4xNPwZ5kVhmvIjYPcv/UEvpaLoDrW0gV6MV2E+pBHAQ65Wv0
AVay/+bNyxeHz0a/7R/9iiB8sV3UcCMyfcrGPsgsk4AhG7OI+sxX8wT5M+z0fQf5kXEwYWkcAA1M
Qy3FXxQEE+5rRvzTNLxZLROQ1NlVr6MqzdU+Zsgd6bif1xKt/ckkILTpQ9U0QGq3mGlpB6/CJFxE
GGkHRw78ePa+nOdovgLmBc80uQyXWHHezUoBDGfvuSkrH1QRLpYxupY4WCWEeaDUWzhsR2wN+84p
NTuGnT84ZK9/LUmh/OJs22/OtnJ1fjp8/vrosABE2aVpcx6seHseMncM09W6EBzMEqMN4JPDCOYJ
hxgFYmDUSCdZIf2Vg1nmnCWwYpTXhN/dQjFJLXtcH8Hl+iUv4HJFViRkEVEIuzYPUoys+8FNBjtD
4DYHj4den5UeEwgpK0TqUz2qznJUogDTL8YVfSBSsvIooSwOJ0HRaFnEEU2gCN3jokjxo5TGU18P
a7LiJlP0+oLdQr2T6eHXFXGZjUFIxAbVt4IxzNnEAUXwFIoYbcJcQ/ZiKX6MxbRZI2Ml1A2hSAEr
5cHYVC4PWJ00SEiq4rc9TptgtwyVFpDbi1cHo/1XB7+8PpKsUJwWLgrHbmE0nq0mJVzrR+MLgBl6
lkLBQFxUTF5Fjy4pl8DobzGqjxOmL4q2BYMZ51txGlShpQrOylSxfJgFUEHnzpTo/uPtbyon7xez
CTk4TI4DoIMnJSzgp0pcadptWBXQGMC8Ck1TZsf1X217USvnCJ6PoFS2wLh7/KTpbvMbiaqC54eo
CiN8gt4QBUUYqcaYmtWJGFYQf4Mu12fyb89nizN/ZmCsuIxlYghyhhn60muImV7HoXA84PhotvJd
dUJF8BYXkM+IGpNecsRFQQkiglzgqx2vIxQRCjbVV2yjQfVk/2j/Z0+VFR2vS0O6pF1s1om8XcZ+
4tTLdCNCCaqoLE3KTrMvJ21qPimAeuhB95cheU/7ViWmhy+fd44P9l8ZOVjn+f6Ll33yUzkrerHI
aYvLPe7ZyW7PzrFSX8sFukbnpLdwHa2UuNfWepWEmK8s6w+TmRdSkDgkwPKaU70EjhOzLSeOpPXj
nt6vBEPoUgZJ0XuAAlS/IXlus5Jo4fBG7Yw7UwsRsfDuObJHqdbTh1e5H85jG6C8n9Ft0u622QJ9
a6LguijtSl+g5y/+8faNKoCt6KbX6b9IdZwzYf61pDrY3qRThnnw/JXXBesJagr/lnFoJhuIJWQI
MSuQAxquiHrj/GvcMZjEiDiI0Yh4itEIZZTRSDAUXGBp/e3+c/+5/9x/7j/3n/vP/ef+c/+5/9x/
7j/3n/vP/ef+c/+5/9x/7j/3n/vPf+vn/wcWoBevALgBAA==
@@E splitag-A
```

### splitag copy B

```
@@B splitag-B
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
@@E splitag-B
```
