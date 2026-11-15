# chunk delivery - r1060_patch.py

> **THIS is the R1060 canvas (regtest efficiency round - NOT a splice round).** Tool md5 `e1e07ab65f18123e7a39f09239b42948`. The patch touches 7 tracked files (3 registry cpps + their 3 headers + tools/preflight.sh) - no lua, no frags, no regtest.cpp, census STAYS 1127. Run TWICE: first prints `R1060 PATCH OK: 7 files, 53 pairs applied`; second prints `R1060 PATCH: already applied, 0 files changed`. Then preflight as usual. If chunkcheck says a different round, you saved the wrong canvas. NOTE: this patch round does not remove a tree-root canvas.md by itself - delete it manually after the commit.

Delivery v2 canvas (R1044 build). Every section below
is its own fenced code block with a per-block heading;
the machine-readable parts sit between @@B/@@E markers
so block copies assemble with or without fence lines.
# chunk delivery - r1060_patch.py

Delivery v2 canvas (R1044 build). Every section below
is its own fenced code block with a per-block heading;
the machine-readable parts sit between @@B/@@E markers
so block copies assemble with or without fence lines.

## the gates

```text
GATE file r1060_patch.py e1e07ab65f18123e7a39f09239b42948
GATE tgz payload.tgz c3a83cf96acb64730bb444f21a5bc996
GATE b64 1b1bbb6e0d530343e676b6d55541d3f8
GATE lines 165
GATE chunks 3
GATE verifier chunkcheck.sh 0e456ab399aef922bcdf2cf33e578767
GATE chunk splitaa 3465ce6ac635ea8c668df4143c0df61c
GATE chunk splitab f2499faf89c2f78d9a4c43a932ff18dc
GATE chunk splitac 9bc6b168fa0ae4321ca540545e998cd3
```

## the user flow (Termux)

Extract the verifier, then run it against this canvas:

```sh
awk '/^@@B chunkcheck.sh/{o=1;next} /^@@E chunkcheck.sh/{o=0;next} o{print > "chunkcheck.sh"}' canvas.md
sh chunkcheck.sh canvas.md ~/r1044_work
```

Expect `chunks ok: 3, auto-repaired: 0, unrepairable: 0`
and `CHUNKCHECK: PASS - r1060_patch.py md5 e1e07ab65f18123e7a39f09239b42948`.

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
1 f65f6742
2 9692f73e
3 5a41150d
4 52497369
5 4dd12b0b
6 2ff08283
7 7a25b7e4
8 e03c9f44
9 a396e0b0
10 9601a996
11 58b9c68e
12 21297095
13 323ec039
14 e6d220da
15 51f2b74c
16 9918b060
17 19cea0fe
18 b85a41e7
19 a5cef2ec
20 fc42e1c8
21 db0fab07
22 d8b10681
23 fd67bed3
24 917d4494
25 4c71bb07
26 abcc8216
27 329d4d0d
28 a2a945ef
29 6d028b57
30 d39fc000
31 45f053e1
32 7d0fd464
33 803c394e
34 2757b947
35 8e5dbad0
36 7a091ec0
37 1a7ef4f3
38 3782b506
39 b3035b4e
40 78978e65
41 99f65d1d
42 5d77958e
43 a1bf6e36
44 da992593
45 3e464c40
46 2b36e4ee
47 ced556e4
48 593beadc
49 49b368b3
50 c8750164
51 f3312dfc
52 0bbcfa3a
53 5609e6ef
54 487ca665
55 eb261301
56 58cb0289
57 5bca4be7
58 b6fbaeb2
59 8300100a
60 e0c77538
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
H4sICCv8+WoC/19kcF9wYXlsb2FkLnRnegDtfflzo0iWf/9cfwXriZ6wo1wuQJKrVLM98dVtZCFb
FxJMTPQiQAKJQy3QubH7t+97mSSgy0d1z8Tsd0sRtmUpeZn5js87MknuPt99/n/P+vbB0k1r+dM/
5MXT16W/PJ/Lp+/xc4EXBfEnbvvTP+G1CiN9Cd3/9H/zJX7lvMjxrF+EL8X8l/svRaFwd1/IfckV
7j/89OP1//1rKfD3/K8LPTLsu8XuH2f/9/n8Bfu/L+SF/E9CQfxyn/tyzxegnSAK+fufOP6faf/L
IIheZNQr3/8vff3p3z6vwuXnseN/tvw1t9hFduDnPvyJ++UPfAG5Qz3jPn3iuvjJN25pTSMrjDhr
MnEMx/KNHbcMVr55BxdxnHDH9W2Li+ylZXHuSsfmThgtHSvkrp3I8sLPt5zpwS8v8MPIWoafb6DN
KrS4p3aNkIAXXPhrL9Iji1tYS84NdLPqLC0jCpY77nqjh9+4wLc439qE2OhjsLB81xmHHw03CC1G
BC+dOK7FfeL+W7gt8DynyHSoIflurEfQP4x+5d/ccbU1vseuLBP7Z1QIBSfkdG6xWlrcfyytaLX0
uf/k7u7uuP/6D86FSS11l7uG652JAxfrxjII4QLXZTTEWzGXI5RCLphwRuBHlh99vrnldJ909mto
RVGwuG7dcvwNN7aijWX59AJGYwk8D+AXsNbirK1uRNwE/rU/ERZw8NuYc66+C1bRLRcGbHbscvh4
sYpwIuNdZH1yTBiAY+juHZlyHSc5t6xFyDlRmCXMrofmyPvSs8Qt9KUT7W7+ciQXc+msYXiM3JNP
BEi1QrzjoiBww8+LpTVxnakd3YU2jNlacOI3MiOQ56fQDiJO/PqpP+CmHz8Cm7wFZT4bhB9sUHLY
IBjPoF/WBobtg4RmwZhbQD/ctaEvFiAKz/Gv/cUyMG7zN7eJXtioPE9PMhfqEwtmwi3cVUg0ynX8
+R3X0z2Lm7j6NARO4vtuQShwG33pO/6UUZnC5OKvKbvAInVgg2Hrjh9/kZjK1ok4fQWWipxLBjLR
Yegm1x+EwArHdTkfLwJuOLHiXpcHUqvK1UtSCzQ0pnZnLBYZnrSf+sDblWFb5jfOsPxwhdT0XcgJ
gvgF2Y/2aJkwgnBhGdwSRA9KYLnASx3VeqyH1n2ea/ae2tzYBQ5e+wH32yqI6GRtfa8vzRDEbemG
DcKHwYEFcsDVNehoFMC44L25MsjQOYIYMCsygcky8IAGfg5mxX+ZTCZwIeCB4wPzUBO5SbAkb3Ck
kml5iwBtA2EG7BIb+6CQV7q7hHh3x4FYXbCxK2I4wGp/CpPxg8iGwSIF2dlC30AStHESwdsIcCjk
TMfiWk+DaktFHkNbMiQyRCSE/ywtzzJ3d380kDowoWUUM5n9Z+uhDXjF/p2Fgc/eByF7F+7CDx96
z7UK9wtpcYeWFV5TSnfj+7xpGYFpXX9ALbiyds2F2VAiY1ds66P2rDfqumOl6WqiuzcfmoWWN3We
nPIXyRPmbaW4MTz4vOGutJ50L1Wanjyb7tWZ66r9Tv6KkmzPura8t211P809VbuuLHa2WmPAy0N1
ozpSCJdFWlWZaGIx1BrKSpoFU2nWddR9SZBnqiB7tX27arpyQ5nHJLXhYK96tV1bHOS1qrpvzwaC
5Gymkl+29VFzjySGQuhIortSxa0A3U2fHzRXzXXXxqxgjEm30kwfFmYxyfGDMtd6pa+mp8zMRnH3
7G5Xo0Z+3dqVe3K/JMrVYKp5xZ0p1ndapTzXhu1QHTVtmPx6DF3rQ2CU312oYj2MSUoP3bXU2Apq
rxA0c/LUfHA3GjTTnFIE3wWasl21dl+nekOxYeI7qdFdayN5OvaKvNQouNqwMzUbtis9NN2YpDrc
TGGkNoiBjIaQ6ZX3egNGNexERq4LIxpMtWGBN/w5zKDAW6OyC+Q96aENn8HsKuXQHNYnMclBfAmS
HQltXgWJPwnbleTyoVQHHlZKU6nRXI9F6LpRtLWathg3BoEqFldGrjOFLudPswVqx4Lx0jOgtzKQ
nYZSo70e+20ee9eqwT003wHb/aZTXmqj+YJ0haJzoJtK2RmDFgDT1uqw29CHWzbxx8tkNjDioFUp
z8ZiYQ+TA33s3D9BW9DNlbZTp7qoFB77EUgduyitY5JZyRqibRueMm+NKAMk0ENUd6nCx5PuLoxY
M6xeeaeNlD0RlVhwUcRMPEqxbzbqPEqW8K3yFTSgPjO84t7YlT2ckLErBeSyutaWKuF0nCu7Y2+7
UH15alAtIF3FJGmPmyno3R546hoOJfPYK8QTOuVZXyzQYfRsIulYxL8xvaxtXhIL5WedzeCFH6DB
JP6ahF3BnMAsJM/ltaGwb/HCwhDbTYSagaf4ADVEX9VcecNGCTYMaESgwQDdArKLsTcA9Ck5oOq8
3KgJ6qzttPdT/qk/z2ueXNBm053cl3bwXpT33bk2mzutSslhoxx2hJForscNsFWHANZMnkm8Bgil
9mv5tigLsqhunqrt2dNQFbTqfKP1jVxbbHoAcIhUG3Xo7oyddM9GWY/GkoNSFgg/NUAfmBx739OG
Jo4cRFiYGQ+le6lRm2p+0zXE6YHFoWhjkkzCKAKEB2zWrxfnY5EYXhjbPGkD3QpohGOAENMbTNVe
mVeHzRC+B1Qq8zFJHewboUEVQ7y8AHo2B3AjvCFdDNGWu67hy+s+e+9mUb+9MSqlYDCrbRJUx8kU
AfjLWR0jKhzjZjgW6/NuwwVkavPjHFjTgwnOJZ54ru2aAJBGxZaZQVZKm8de2dFG3Zw2BEfQwAkr
ezRCov6NOqg88loDA2wHqHCMd6lZUICMSb6ZbzEUg9U4YwRDMR9DL3QxbC8BXhgvCZzWU3wkl4ku
rzeKAqCPMPZN0FPUVWPa6sVM8FwUyQyghMAGIX0GNmDwhvg1Hc1D0wZFWiCaSw03Ur16qILLiqVr
A1QU0NKo7dPZMInnqB/R0TfvEo+HYsnpYN/jnAIGCyAHHlIjbcAnNRQRdLYAdm2PG1vkKfKZ6aX5
IKc8IRhZ98B+qUd8aFPRVOyzE9ZHnS8xQtXAQSfuDP2xPz9RCKIJcJnqKR4ojhsrFI96PPaUPPA5
kTZhWC8Rj+HVV4bogi/ugE8WHHW4tcde20VdJcb34BLREFRnFgZ8O2VY00z0sjym7ultP+c8I3GJ
jYhN3OrNp9aB5/t+0lmnCz0kpJn/qUtbuQqgBhYCfmWvV4Q9VbYyBizozgCmy6Bg2hokXh7U5lPG
S4gqQFkKTzHrtYwtg0jIiJB/0I7XK0deEd3bg7ZQYxOISRLFGBRXDC4eH0wbPONGG0kQ0KDSYNCS
d0Yg2eFOIl3EALgGaFmNG65j7Gz5sR+yUaJLB+XYpVDLHG05UkfzqQkqTGIfEg6QMGGmjlA78sjP
aDxEX98mJpKQfLnn93TJQtYXeyZ+nAUwsT8vLqUqnwm5lOexSy2PxUTox5Mwi0j+CxMLsSixHY7B
qqAddcKoERBLmg/KDuBjre8hJvKFE1V346YN10N7BnSXRyKEpkQ8aJxxiOC1Jzj5x8p8IVVqRam2
VTpK8bm3owrIeIkqDiRVr7geV8pnswpQ5RQ2Uu0Ish7y0SknjuItwcl3WE/MS8bD9/2k8WcSuZ0J
Q3vlRET6UJ0+Ynow2E60RpECWirSlSoUYYRS8NhLDFLq89N+XSmP+GIrJnVgKVRswgRQfAdGum/5
ZQFC2wk4jpm+sx1zqCaakFoPDp74cEiV1oY4CPoVokgkPMhMMBqJyg5CWYh/ChtQ8WAkNjGkCFRf
8TDAZrwEfTrGzLFShOiiCWgvr4wHQKF60UHH+kj0trSU6hvMKw+cM6AVQ3Vz1CToTf2zYkhOqup0
0sBHpUj9TQ+NNGIu74QxbJSn/MFwdfq4KxsYe1J1L0cwUT5jNTaEEbbqbd1RRVqwPCkJBsM38Qs1
AUN/IHGPE8f3OLJMkpIVz1lbPnIcb+FvTBLYDPyDj8B3G5SPp0p0+YeQau7KEFcpTNUhW12D5gP2
dWd67JtJOjAU3i2qA7182yhe6z4med5aLo7m0AcpRUj5tf1QxPy9sGSoPnJNRGnMrxOIfWWCx6QY
DUaSkcrm31ShwMF2BcPLT7uiwvcb9b1ZowoGEDx9BmzoKs1eX2hOunNX7irFJxYFC134qKj0553p
8660kSDjbfVriVgmyqlCofERq6uZrlnb2oCZdVSwJEmZLmDQAPpKbzAv9ka81uzXlEl/XhzA+2dl
UKhJ1a9TuQJpQoXfpv5HSPJwloDHJDEPZ/l0GhGXIQCU4rjThMQZ4SGbi5cCTA1Ap9eQHMYJtJag
emOwaLkHYonJBtN+pVSUYviFmDIXl06C1AjLsesrbiAAZzauD5t7YoS7OLx6SN1YkrA0BBtCAoAW
knbtaIwOCbfXtkFPFwAj4CyEKKlmFXjjvMQXmlMKslUXDMEGJNyiJjCqb40RgxCvYCeZ7oCFBOCb
wyV4PkhMOudQ/aiLNMogvgh4zSTuErdE8dHFXrcxjGgrdSi4gPgk3X8EtHkU22sTZpVIPeNkDDFF
@@E splitaa-B
```

## chunk splitab (b64 lines 61-120)

### splitab manifest

```text
@@B splitab-manifest
61 b968b13b
62 e36b9c31
63 0ee83104
64 bb870ae6
65 c07b9ee2
66 6c08668a
67 1dbe996d
68 54ed410f
69 1df9ee23
70 b832e9d1
71 d02b0e90
72 70caab02
73 460badac
74 9fc6fa69
75 1439d3c0
76 a6c29208
77 941bf062
78 5554c549
79 002779a8
80 b518b84e
81 330ca6f7
82 7d1d710e
83 03b96756
84 4c2b4ec5
85 22c0f594
86 a441dd89
87 5fe7b022
88 1fa7dd12
89 88e1f4ff
90 9aea9caf
91 fb0fbfb1
92 d61fb276
93 7684f164
94 aff038d9
95 6e38672a
96 b40ce50a
97 cfe86ec0
98 e1938207
99 e1ce982c
100 edfd13cf
101 91e288de
102 8ff482c7
103 149bc7c7
104 dfdde338
105 6347cf85
106 537cdb11
107 a38e7d24
108 95ba5617
109 547e0d2b
110 190e4bf8
111 5d125aee
112 04f7d0cc
113 912f524f
114 03e803ab
115 b1f314b3
116 34910f21
117 5cfbf5a3
118 3d695f23
119 0c103a5a
120 4a4493f8
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

## chunk splitac (b64 lines 121-165)

### splitac manifest

```text
@@B splitac-manifest
121 420a2847
122 ebe31e72
123 26f95d0a
124 b45e6060
125 93e0929f
126 9627a0c9
127 da656b3e
128 c654f3fa
129 79ea0541
130 e1654167
131 4b158a42
132 90ecd64a
133 ef8d66f2
134 d2a43899
135 d83b248c
136 f220e68f
137 c7ec7069
138 de80dea4
139 f76918be
140 fbbf6bb1
141 42fee02e
142 089fe84e
143 1b851118
144 3c02ce99
145 0a088fa6
146 93285d7a
147 31a52b82
148 72f73dcc
149 e8a8588c
150 fae98b55
151 856f5b7e
152 80bf4c08
153 7f9745d4
154 655c5e6a
155 8275a4e0
156 91aa86cd
157 66c76a5e
158 d980ee08
159 448a1e88
160 3bbd5950
161 473afa61
162 8b36c3ae
163 a6a2604b
164 782af014
165 ade687de
@@E splitac-manifest
```

### splitac copy A

```
@@B splitac-A
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
P14/Xv9nXv8DSWBosQB4AAA=
@@E splitac-A
```

### splitac copy B

```
@@B splitac-B
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
P14/Xv9nXv8DSWBosQB4AAA=
@@E splitac-B
```
