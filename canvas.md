# chunk delivery - r1055_splice.py

Delivery v2 canvas (R1044 build). Every section below
is its own fenced code block with a per-block heading;
the machine-readable parts sit between @@B/@@E markers
so block copies assemble with or without fence lines.

## the gates

```text
GATE file r1055_splice.py 31244f93c4fa4750baa4b4f6cd175384
GATE tgz payload.tgz 9675a50633f2d948826c1def6375e525
GATE b64 1791b4dc56be097e0c5920900461956e
GATE lines 272
GATE chunks 5
GATE verifier chunkcheck.sh 0e456ab399aef922bcdf2cf33e578767
GATE chunk splitaa 29af32cc280f53834d0f1f4edcb84619
GATE chunk splitab 066d27d131b4e9c7874d1ec2d9fd27cc
GATE chunk splitac 11220acd07db2b7c0cabf4c3d73b3314
GATE chunk splitad efabfe0a476a383d16f70c50b0ca3355
GATE chunk splitae 740c1dfa40c3da7137a96fb6ec3389f1
```

## the user flow (Termux)

Extract the verifier, then run it against this canvas:

```sh
awk '/^@@B chunkcheck.sh/{o=1;next} /^@@E chunkcheck.sh/{o=0;next} o{print > "chunkcheck.sh"}' canvas.md
sh chunkcheck.sh canvas.md ~/r1044_work
```

Expect `chunks ok: 5, auto-repaired: 0, unrepairable: 0`
and `CHUNKCHECK: PASS - r1055_splice.py md5 31244f93c4fa4750baa4b4f6cd175384`.

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
1 cee91310
2 a85adae9
3 ea90b8bc
4 7a2f7538
5 114d3eac
6 1589db40
7 c8e0a6a6
8 b501874b
9 d077764f
10 d694f3e9
11 1532a446
12 42861054
13 409c22a5
14 c8c4a67c
15 b344c51a
16 96eaa04d
17 eeae67c7
18 ce9aaa48
19 c97b9a45
20 b5299e98
21 24871e30
22 98a1c7cd
23 30a25bd0
24 22bfa51d
25 f0ea3f1b
26 a6daa7e3
27 f963c85d
28 80c05522
29 624ca8c8
30 04049c8e
31 a00bb59b
32 e9354056
33 a899cf8b
34 f1862fa9
35 f04dae6e
36 01259bec
37 f2dc7095
38 708a71a6
39 4acee29a
40 d3a95859
41 34bf1dd1
42 e241a066
43 7d745724
44 f6a05a4e
45 ade0961b
46 bdc0fb98
47 78d227f0
48 9bb046a1
49 29764e17
50 2c9dfe4e
51 b9eadc9e
52 24c3bdf0
53 e0571abe
54 4a43fe4f
55 8a29bb31
56 baf7e832
57 707d6268
58 72bdf89d
59 9401c0d7
60 4619a99e
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
61 6945d6fe
62 816413d8
63 fbf918cb
64 babc2e51
65 e4785153
66 8a7a45e5
67 5bd250c4
68 09f91a8a
69 52f47209
70 06cc5bad
71 022a1089
72 3eee6c96
73 5ae553a5
74 4bc55c5d
75 c6d47ed2
76 a7822937
77 3a339bb1
78 db34e451
79 ac58785d
80 f0dce7bd
81 9de5a825
82 88624e69
83 8739a23d
84 300f0027
85 e4de811b
86 0094e664
87 36e511d0
88 b9eb7835
89 54bc392b
90 33a93785
91 c316215f
92 f347a436
93 375a4748
94 60679eee
95 ee933715
96 a54c9e69
97 209bf80f
98 ef7278fc
99 40c3681f
100 f08185a1
101 f7e0e79b
102 9fc6220a
103 cc01af10
104 e45a6b68
105 40c5a082
106 d2df3eba
107 2789685a
108 313bf649
109 1773eef6
110 8a17bf2e
111 b8f7bcca
112 50a61d26
113 ee56943f
114 67312a3a
115 8bb23023
116 9868f89b
117 8f9abde0
118 72ab732a
119 4f5eae8a
120 37f80e6f
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
121 ee08a62c
122 73ad850c
123 d1cfa23b
124 21f1e263
125 694364ae
126 f8450d5e
127 05d002c5
128 536a6f8f
129 bf4f403e
130 63a80b66
131 ff10c7bf
132 8671325d
133 48dece17
134 26fafde4
135 3ea9f7fe
136 4475b69c
137 549a0f38
138 3bc67a8c
139 161c4c13
140 667eb0d6
141 5118307c
142 3be2eeb5
143 c76767ba
144 cfaa1bba
145 e819b59d
146 5a552def
147 9c861bbe
148 d4b18cdc
149 14ccdff2
150 403d8b3e
151 fd61b08f
152 861dbb3a
153 503b658c
154 d0e6df37
155 1b220938
156 561b6425
157 e0f57d29
158 3639ae54
159 5303bf49
160 6291024c
161 fe7a4b6d
162 cb9623c1
163 282cc92a
164 24fc6b33
165 0847bb7d
166 5169f68e
167 9df34af6
168 c840cf5a
169 1411fb8e
170 0f2fd023
171 7999b342
172 ca0965e6
173 b7c17ef0
174 f99d5e0b
175 4d36ec43
176 81610270
177 552ea072
178 f4d8cb25
179 26e80165
180 2fc3fd49
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
ZE+FP8caUJjK6OHqxp0vqffjEX8gm6CdtAQFEReQAm0DH70BZg+TMMp5PPI1U6zS6g6Ww5F+1oOg
gWjQRcAgHAo+iTEyiJsVwGj8Wk7lYAFMvb7AOjjnMWpfDG7FaFlHspQHm8TJqN2+InJ/mIbBhHsK
4JcXT9OyUBwSU52eUjUJw8KhguACqI8HNTJz5z/QL3zWZ1jyJPDmX6TPh+7wQnBZoVk4CC4v2b6O
iT+gnQmuVAqbN5A0jshdUGkfGELCTu5P+/LSyYYdH8qnuBt0VAEQIXm6mL3xxk91VyCgF/IpGgCa
9nJIjAOQCRoNBAZj44DOk2hP9T7YmlSmVg5HjF38liWsuGdmo/oLLoP51yXepMHtmn11MAtGAlD1
bdLgls2eEeQc9Nhl8dHnNfNf2W/K0IDUTkE16XPp8hK9ui/Z0ytDu22NqaVmTiZrttFcwkGL4sQw
Ff2k/iL28IijQXNKef+lHKi1jJpvM3icwWAPCDtlkgxiTGPKSrRcudG+NbHSIHWX79nI5TlCTVvn
cxfUK8NXNT+l4odNxQul4Clbj0kU+XRGIxXaqeng+BFWrPjp7GVTB0x7SaQj/aaBd839unMexpv1
Aj2gogtLbGm0ndFpZacex3GAYmeq85IJMvRBCZEsgtra3kLA1FhH5j+fO5oZ7jXQTZUfDDVgnpuy
ODNwGf6BwVJF4ZGsuWeVgr3YZ2l0uVMEE9UFmQIFhlKrBCEelTkutW1G9dtvTMK82Nc3V1ocVgkl
QobK+vMItIAAWR/tcQmaope0AC0PDJEW++mkpDmlypCgup8FQxelQA1yWiYGCmyJHMjyaiz6D5WD
aLkYRAUpOOm8PsBIvZM/oRzsSjmIlooBnoivIgJ4QPUw/H+p4dcqdC1dDRRgoyD85w3+3blPRdqq
WKuGOC/jrAL7wNhljBXhm8t4ysHuk534MnpSAUMZG33BbL+K1z57wbYF0PZX4J9fyT49UnUZFzXo
r6X9fzfGYqa6L6KknKgETSTaiqrairCtHQG087vpdl+WjKweYzVqeNkIK7BLx7dmpqtwLpxHIyPp
atSyDJx7kJY8QTCGz9i33xIc/FptUehcLkY52uWDlY2HhiQdmD+bPCtBwsuXUglaIs34Cy/Uskz8
0iqYzJpMLWcpbFZUcHKzCjiFN1sT1/qD1xpefeaHfdZyKq1VoAljEpAXptF8mQ73lBYh1iYpWcvl
r+UD5k3ig01hfUlozF3WmLtiYxSkbmyMJPtGE+0qPCLmvgxVys2gevpK+m+c8nnKJ0gLZ4gmzLwN
sL76hnFaEb+COyBUZrAN2aM6dAheADZWzVQtqH7ZXFWBHwy1gp2rJQgsNXdV6AdmGi0iym9YyR5C
yL87E2MvHzMcyjtS6FCElzIS0Fk8QSGKwGtoYX88kgBP6Hnwv4wnQJ82fCGd1tpNBZjSmiNGXFjA
Zm50ydwpnu5+xPsa8GROUIJH0EDnPi+HxrNV+W0tn4A42ZCAkpmz+T7n3lSg1QoMfjBEQ1EjeoN4
sKZHeaSXGPQsOuvSjyyt/Plq46JnQNKTFQeIZ43Iyx3ncCJrRNWGJJm/Bz9kHEUN1nuZ1cFPs3Op
vcoVYHoSuU3l/yjOGA+WZTQK3eSRhQbReRdlRBdSd4tnQ4bM2yogc+X0QvprGYRMUHUMJULsl234
75+yLlYvcDacl1ax8sc/b1lLJF8WpzfawPo3BsxUUSStL/Z5rxekA06DviWylhbnvKoI1e2q8aLA
+y1zTSQM84/34a2ftHwSxLXPTNkkmeBXFiPJ8sUjD6M6RiqhKJ1ba1msWMm9CRjXn0sKSSP7c1X1
KLoZ4It19Uo3DIZ0Ez5HMF5ngukpaf3MNcMZfOIHC097IBICTGd1FfFfTDnH0zN9zDloZeXonhbL
0Wll6f7pgMw6+ep0Tp5fueIzFbXqjH3SCi7x1cAcIc7vKKRFw9KJ0HVXVvWOV8lJlVOujkuhrEc+
scXVbjeEBTe6olydXGhIkS5D/qJexFvLUgDI4oqRZR1jltA4UKv9TcM4UVpKq0WgWui8P/zxaNA5
+h9TyQctq+3o+OigDIjXhDA8zJ1TfEldCUNfqchGrqSE3l+Z65QF/aWXCywJ/FOC+GE47Q+ysBUa
NLk0ig+2tR5nung97lLKIZUfIi1DBQyzAVgtSJSw0i4wLsTlItJ8jOgqkaCFWFBBFbX1mQw2UhKi
5F54PaBUMvugxiOVcx3HiAYR9SdTe/itZEqYg0xN4/deSTBedRczTXha7wFZs0rMw3pMRqcSAiSI
q6kwIvyFEgDWR32Kc3EyvvtOAfqRjFtVwIJZEW5j49wdSYb008qU2LvBOECGoOLF68BIJBSGhIFX
x5LaQ17NOouTo5f3lIS+yhvOBJxyz1kW0fkMhAZQCgOYwkfkBV3t9npsr8e8d5JELQHMyocH8TSU
6TRn6SGr1keOMOILKVBixFbCZsRYvCehoOn5GCibBz6d11ZpX0NfQF1OSQUVQgbCqRthKZl0amSS
QOoCwwiFPKw6NBc8ma84No+s/OqZNqGnDMOWiRV54aisuuCJZ0QTjEYu7Xdpv/nmCdVnGod9oMf7
fMA/pT7BH5ubYBmBbUQh0u3sqoYsaUJGTe9nH8vJociyi0QaUVtck1mA1C8XBjNCSbwpwOYScPDu
mQJQSegpVfMoAFdFeNfZswI8XYebv+hrLy2eUoCvjgcugKcXlmIosIwPp9htAyUYFNxgpx7erirv
ymxTZGzN0E+8AaQmL/vg994WwWSF8BqFxNd4GnKDvaaS2wVo9Q7ORjHDqQBfmegUUt5x7g0930l8
/0n/UzpMzmk6pq4QsK/RZJQpBEI1gzHRahCP8igoPUA+zKR9WU3yepEYA308oJLkMsVcEFAMLy55
VbjSi+HNZngeSVgS7KyGOVOIobnJMV5I8AhPlaRWKYV7hHR5URRGse000nZEYGb1+4Vw2csr1taU
TQOLIjhOeU/TqJzLq4aICc1S9njeWiOmTFAq3VeOSITvlKPpNvviEWECOXaqsWk9VxJbUDg1q9HI
UopY1ryKwgxyFFMnzZ9RsHwuUsVv1rURARPF3dPeUZX39VEPPgEGn8LfWeTpOuM3EaUOQXXaAaUI
LE32lmGQc9OSpuBWQygk8yRMH68+DX+PWfg1Z1+pbCxJ+i1P/DUQprqiDTRrIfWa2Knx9RhTX41H
8qpUfPcK6Y0ls/oRRtcLWQehVlFx6+nTckpS7SD2HA0NTaYXeOnZYCk+NcYPUGIqaxnKlkJdfrNk
NN8U/AI1zLqcJ4L2S/lSTFW7x0f7eWeGnl8rBqN2D6TxbNyMmavjlOzMu11o8jTUUSrUOKX6GTBL
nP5KY6epZCWl15yZWnQGanm/1K7u5KgQwzTpI+/8stKNMG1enVUQGoc2nWOFNNjVJbqAUSTUA4m3
ow4/IjelUUCqDyng5YWeV8VtHsXMRxPcalRSX0SRTC+5zyEpJLtWD4kgzSwumAn+PsxmWz7z+x7Q
v/OVAbol/rJ5tkLqPC0gRT9WiY+MvFtcvzxlzyt1wOfy5cJgMn0VK6p1f1bUs4bczpnNqOz5SnZU
uQnlzth+aV3e9LoD6XLNaqhogPnKcq50TGqiV75HoDNx4gH8+IHt7IGExRXmd/qSy19y6aVqcx1Q
ukssegrP456hQl0QNf2puh15ppEF1FkSq0DiLCNEesTiTMTKOL8SLd1Y3jneX6HlwsYGz8bogEK5
lFe5vtAp1HbIFQJLaxYYJQmXMuHGXytXADkpWl2SNPtNEasK0zTzDupV10FPmrMl1vIokGN4Bpkx
TAfh7kFTeoCz1NAhwejG/RxpOkOXYtEGmbu/Z/ptvWzm47af2eLcq62AzrGkEM8ABWZTCIAs/pgW
GJ65N/YM7wFtNal4F/ekjV1/mr6pYKRkUHkZ50jBhpd/YkxaJo5xZgrsqIUZqUSzO+PC3pYiv9Ov
dJF/Ut3ZJgBCrSsF5ayMk0mRsjGLNd94WjGxSKrM70UWAdldt59ySYMpowesZi+xjcesBV3Da8k4
e0ZokGgs4OiswAPuuShjRMmNz/Yq3E2JGeEZrlNAvs7iFbGYDij+RefzN4ntFkdkzbwI8CFhL1hz
ebMlQ7H6MMAQAJFUW7kLv/RJ1lccj/+44TBBf9arvt+odV/zOogc/ZoeohoXys248tSOP9GvbuBK
xQeWsdYO6TAPHf7bpJTivfTEENHV8USPkpzSmiq8Hi4V3FiujNIqscU6+t24WCM2X/UU68LS8NZY
dwn//lANBnzEuLm0MCxf2VrNP1yNIVXF4rh3Um7ajNLKEmvz6UvmVHFe3X5ukTjhFbfU726z/1XG
oLVdOgZu877UVjmT/3RK62vvKbfub0/5vEEng+YNpXi4sle+fEcZuazinggOMmQlVzZU7Tg1RPkt
Z+SWbzmr8GGrBVzD32n7GvGXMON8d/n2VUmpvMMGVivccOcdrMz/c6Iv2sLqQ7n6Hpbyw269h+W2
gry7Y+FO63iXcnYtigDC8/w61eAyVAo77fx0IJHxo3s3zm5MSV+46+jkcmv/XuNzR2lW8hr/YE4N
@@E splitac-B
```

## chunk splitad (b64 lines 181-240)

### splitad manifest

```text
@@B splitad-manifest
181 435601c7
182 24a40857
183 8e6be193
184 190efbae
185 6a2229bd
186 5508d553
187 2fea9115
188 30c894ca
189 9a713402
190 75f99f56
191 e8f0bd74
192 e19c4ff5
193 0da8314e
194 4476d083
195 780af010
196 d816daea
197 a0044e96
198 272fcc2e
199 e6b1c785
200 a17fd9c8
201 4b81fc77
202 b1403116
203 6e7a231a
204 fbc50623
205 50832407
206 624d8de3
207 1f4cff25
208 1eff11c3
209 daed35a5
210 984084b6
211 8faeea88
212 90870f54
213 80670304
214 3d27816f
215 bfb84e00
216 1e1f25b7
217 cd08ab27
218 eab794a4
219 3a0a9fcf
220 1eb5ee11
221 707d3efc
222 ff95ca64
223 42f166df
224 d6d08ed0
225 bb0ab94b
226 807739fd
227 1a7b68fb
228 fb8fb1b0
229 887daccf
230 c9fe8bbb
231 3366ffde
232 408c5b87
233 e8d761be
234 5bbda897
235 135e9489
236 43376090
237 a6ba63ef
238 6998ed01
239 d9deb856
240 38844a0e
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

## chunk splitae (b64 lines 241-272)

### splitae manifest

```text
@@B splitae-manifest
241 88bd790b
242 636ad12f
243 419e1686
244 802c2722
245 779f78ad
246 fa0a901b
247 628c018d
248 b6bf59ac
249 e3934ee8
250 11c5472c
251 6dcb6c4b
252 ce443faa
253 05c3db16
254 4cc2c052
255 9692adb8
256 546b027a
257 2030bb32
258 2bec10c2
259 ad7a3c8b
260 77fb2117
261 c646f154
262 f720583c
263 eb07c39c
264 74590c66
265 a14bd671
266 ef2d8454
267 e38995a2
268 8634ed2f
269 6f99e16b
270 4ea5d80a
271 49608682
272 e5d314e0
@@E splitae-manifest
```

### splitae copy A

```
@@B splitae-A
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
QAEA
@@E splitae-A
```

### splitae copy B

```
@@B splitae-B
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
QAEA
@@E splitae-B
```
