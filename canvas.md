# chunk delivery - r1057_splice.py

Delivery v2 canvas (R1044 build). Every section below
is its own fenced code block with a per-block heading;
the machine-readable parts sit between @@B/@@E markers
so block copies assemble with or without fence lines.

## the gates

```text
GATE file r1057_splice.py 93b5a5ff990ffca1e9575a216e3cc26a
GATE tgz payload.tgz 4637b0159432e06c69b8aa8d51159035
GATE b64 073a35611d2cebc3f2334467b1ed8009
GATE lines 405
GATE chunks 7
GATE verifier chunkcheck.sh 0e456ab399aef922bcdf2cf33e578767
GATE chunk splitaa 663df7e676559bedd2614809968716dd
GATE chunk splitab 226ef5ddefa2efb9d6c31f20f8b7502d
GATE chunk splitac 2c02075dac2ab45f260c6129a1871941
GATE chunk splitad 8dc8d7ba91adc73e668688a98c3fb3e3
GATE chunk splitae 5ba1f0cd3fbf8651a8400cc50107d0c3
GATE chunk splitaf 4becc27fe441163e3a6e8c2b9aef37d5
GATE chunk splitag b83ad6b032a507c75ab0acf56d2aa59f
```

## the user flow (Termux)

Extract the verifier, then run it against this canvas:

```sh
awk '/^@@B chunkcheck.sh/{o=1;next} /^@@E chunkcheck.sh/{o=0;next} o{print > "chunkcheck.sh"}' canvas.md
sh chunkcheck.sh canvas.md ~/r1044_work
```

Expect `chunks ok: 7, auto-repaired: 0, unrepairable: 0`
and `CHUNKCHECK: PASS - r1057_splice.py md5 93b5a5ff990ffca1e9575a216e3cc26a`.

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
1 c5006ede
2 8040f660
3 437ff204
4 7a25ef49
5 511ea62d
6 9a442118
7 593c45c3
8 ad1b689f
9 9af0ee40
10 0ff21941
11 4cd5d688
12 57383174
13 c9700795
14 5cd7cbd9
15 deb2d500
16 12191787
17 31c5a437
18 5cff52f6
19 bb9af0b9
20 887c2c2a
21 6f27b084
22 4ff245b6
23 8e3b28f2
24 068edbc6
25 26b4f94c
26 48fc692c
27 54e7aa66
28 1bdcad82
29 235cef7a
30 1c089b71
31 63c5c16e
32 f3acf9b4
33 69ae062f
34 5bc1e611
35 c2063a7d
36 12d2e63f
37 f09b28d2
38 2a947c49
39 c83ba8fa
40 1db4240e
41 d1440de7
42 bfb271d6
43 5a8bd4c4
44 c2854e55
45 f8f7fc9a
46 001001e2
47 87086547
48 bd75ed3c
49 0d8b9495
50 6e1bf5d2
51 a88fddd3
52 608bb8f0
53 7dca7ffc
54 8ec4a903
55 da9214a3
56 df262b7d
57 a1f49bab
58 66f2dfb1
59 6d77421c
60 20e928a6
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
61 306d7b97
62 1e7b3a33
63 7b52a300
64 68abaf63
65 9425dcd8
66 e8b8092e
67 ee802a10
68 883ac46e
69 d4d4dd2a
70 59991379
71 5616ffff
72 195d3a73
73 a82e4a35
74 645500bc
75 60b8d0b9
76 fb95358c
77 29913fa8
78 9991420e
79 85c09f08
80 b5e466bd
81 0d9522e5
82 44fd1a68
83 bfb56a0e
84 579e9cae
85 c4ef24ff
86 5e277c9d
87 f9db9e82
88 1117033c
89 00657400
90 a9f3be13
91 ea21d339
92 79940c80
93 b641d32d
94 4ec500f8
95 c58ba373
96 a6bbc242
97 26c39b7e
98 d13c3a91
99 dce7499e
100 789b3766
101 67574777
102 dd50d928
103 28c4a730
104 e1a49420
105 de8e9019
106 fb4d682b
107 d96011dc
108 d696fc50
109 fe714fe2
110 689d8973
111 252c1e05
112 85c3ac6b
113 b5dfebb3
114 a8a04e03
115 2aecc473
116 05bf7895
117 59b4e268
118 5118170e
119 81491e56
120 35306dc8
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
121 4e0616b4
122 3c53c790
123 f3bf4209
124 e5c7e95a
125 fbc5ec26
126 b58fe688
127 2958d2a9
128 60d9a624
129 41cfc7f3
130 6e9ad478
131 9c607651
132 c7486b40
133 074931c2
134 b3c3991b
135 5c8fffee
136 19099a9d
137 3708edbd
138 cb847518
139 62f23471
140 7176dc7f
141 ae25930b
142 8d5146ad
143 14ff5a4f
144 fd35d762
145 98a594e3
146 dff80a59
147 51256b87
148 10e90a1a
149 8380e239
150 2140022d
151 5681f798
152 2bd405be
153 9051c1bb
154 2ba3c970
155 c9167e32
156 498de77b
157 fd13237d
158 167e94c9
159 b0fd02a9
160 6cde5442
161 125a5f2c
162 d9dd03e1
163 a30d845e
164 bca5ae5c
165 f3d5df30
166 aae4ca1d
167 f94a40e8
168 f889e60b
169 18c8c361
170 894af8fc
171 7b16940a
172 c510f3e0
173 5837e52a
174 cae60aca
175 f7bfda38
176 ac9e5b5f
177 9b599185
178 0eb9232f
179 6c477ce8
180 026fc55a
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
181 0df41c18
182 1564e50e
183 6bb2870f
184 6b65f70d
185 24167227
186 fb3d12e3
187 88c9002c
188 9bdabab4
189 3533b7e4
190 d463cc60
191 7806e372
192 c5b2ad1c
193 eacf5b8b
194 2736d0d4
195 ab8b818b
196 1ba21120
197 6d122bcc
198 76e9c800
199 e7aea0b0
200 c3690832
201 cab41369
202 45abcf3b
203 b4eb20d5
204 9496cb38
205 dab87e1f
206 e65eb248
207 80e4e357
208 555ba161
209 2e1e8f65
210 b50f180d
211 4e41ebb9
212 6dabee8b
213 26d0ca82
214 4b070931
215 fc069f87
216 a465db27
217 ca2bbae6
218 0fc355fb
219 76365822
220 d72b939f
221 705ff658
222 9930a99f
223 b6fad803
224 6b9a4751
225 107e6c61
226 84f80346
227 f1e03a01
228 430e744a
229 c5a475b0
230 2e9a924c
231 1de478c5
232 dc91f5d6
233 ef7f70c2
234 425a9aa3
235 28fade0c
236 151d4171
237 e89bcecc
238 728bf2b9
239 9131b04c
240 10176878
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
241 ead40a55
242 9324b8ff
243 9b05eb6c
244 83b41f2b
245 8d5b35a1
246 67f9e2bc
247 fca4cccd
248 9fbd1c8e
249 468f03eb
250 39848ffc
251 19ff0568
252 9454ab86
253 3041ac4c
254 34700f64
255 4748bfde
256 2a129104
257 07703712
258 0e17c766
259 3bd67727
260 d7164ef8
261 54f5d69e
262 00014dac
263 2b2866cf
264 c7491e8c
265 cf8085f6
266 fe1b7145
267 efc753fc
268 ab3ab3d0
269 6a405456
270 c8abdf98
271 c2536126
272 805f5d40
273 b7686140
274 19b55e81
275 6453a5bc
276 c152155d
277 0dbfec1c
278 ec380e97
279 76acb850
280 8c69c3e8
281 557e71a2
282 a19e13a5
283 f4dd817b
284 feeab005
285 84185ec8
286 ddac4800
287 a17bc62f
288 8e7bbebe
289 e27a5abf
290 32f89c7d
291 13700c8c
292 dd8eaff3
293 b273f47d
294 652969c0
295 bb13115c
296 63a65018
297 2307e7ed
298 aecb2868
299 d2312431
300 2cc8ff41
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
heC+26CIaNcTiR9FridLbcn/6HJfro9+OWwW+6jrHzDy8tjPtTz3z7zAk3JLFlXRl2RfBtvBomNQ
cMZZnGjero62vRwtuKbYl473FWHyHZyD/KIYLHEavtCS5Dk5+Z6Npwwj2HB7Kq+4pdmk17smPH7g
86NNdHzz43eMx6aXeEpPzTGyzyhrRTDn/uIH+oUnFpBS2uo9Fidktecfyx4xTpMP2F9illA8yegj
BdGgQcsrFzik15V4MV0syUst0n+qvR0H08fqMQXwBSXqPXBki/6DuWYIxB9uu2I/sUn7R2J1huO1
Z58Lw7xYy+UJM/ux4AiSNDPQS5i1f0wD9MzLyQaphHN1TJDKdSCJeJC3U2J/0KgjBsI4iln40th8
kcF5bKUt9KDjCerglx8fM5HLwNUoySSJyFXIzn1PYiMnPureSFYSziLl88eP7ECFxAuIFFCEkfYm
GSTr6PPj70qeNQtQcjxaCHSBEW9M7MsagKuwx8JAzQHjEL9jGTMQJdC7MDlpzXO4WYcrawfyYprc
kL7LOvJ1htH5p1qkZtgp//rSfOt+BHUTdu5jU8KWhnu2pLX778gO7Smp/U/Ka0Qcm++0HfyFMdii
2iG9AVKtUFZIkhjimTzkIo9bPnNmF+mVlHqYXaDcYY4syQp53izL51K2pwrpQj5PAqrFrEK6CJuf
hxnqjBTYzfnShnh9CbfsFIRCblQjAVjENKdlzswiwbvIRr9fvGGNGUF4Ac4OT4QzpOZDAC+gKkk/
aQlF1DRmlhRFpyfn70/fnDFfGJykt6X4M7cUdjXyxx+9FrBOUVTNuc577DUKdBIJOr3BY0N+TuFn
7xg98eVc1+MGcU9y4u2umhOG5wLhExdObrl7imHe+CVLGUWfR5nns4rRPf9XwPzY73Q6g/3/W594
X1S+uHmivPipJtenERI2mLWisPnPK07sluyj1VFGwQ2FQOHr7HQ3Zrr1LNiKuA/LkTBUIZMTR0fQ
7UGOca8tAkdhYuk9eG1+eaOELIJVqjVcVFdvEHxuPSk5/GN2SacMP6nF3vZL85ewtol/yzCOh1Wz
EhL1JRI1H5eU3IWDwzuCS0+5xKPsSHSLh5wHLXMmB226EpLT32AILs0DwKF/VY8R+bFAcnDa1FEh
BeHSy5f74WQfzYnTUaOLNzOMdne/yT2aufG705MXwzclANmkZkdZsXaRJVF6w28l/nTUo/xHVt19
+OcH1t1ToMKKPQk9yYAjEQbi4z6+9Pohe8y2B9CV2pLegDM3xZ/vvmNla61Phu8YgkIXBJlnh5Cz
NoCitOcgAcrWYL/a+l6rlXeVx3moHdI4XH6viXeNHvTf3TMj/oTxihOqODAjoV8y36AgSDfD+jlh
coZczSkFt1TfTda5Jq2x32LhyJiruaXtOTmBoeZsr00ikJxXXTT3YYrz9nDi0GUFdHwjP8SsTiHU
HdCODUc1O6a+w4epADG5XW3+LQ4BbskqzwGjcKifAkYnoipvlkmA9zNEV1Gnp2UV4sIITzyaix28
NPdm4Q6mctTK0l+Mz4IkC6I39Dg42cDkzCVZKT7Ra/Iq4NL8xdIbiuvWJ1vWGcQVmTLfwrpQHCOV
myyJzWH7XDC2MICcxJ0LR97kWXmYtqUkDOgEoO+gzB4XNqKdg4wIG/L3ePUAJrrgE1X0Z+QGpP10
xphfy0UX4swznYVZJehaoz2dKJAvAMgKQSz8Cdq1pJdYe0r2ElhOIS/na9zSINDKCh8yJR0LDJO7
ahTfXJ+8zGL4z1XYYqNImpgRfh5dhR7N9r8niRRSiiR09Uwe3pfVXOwNczJW5Z3/NJZ9M8HtASsJ
xxQsqpKZRFoFYq20FBgY6aoclv1wwEqurl1GE3/P6hi8J/P3Zkur8n3aob8BAb6LlSHlW3pfx82+
f1fTfj3dr6D5+kmpp/UH/N4hnLbLhyuUw6RN/pSuT88oV4+ZeThpk4oepuYXESrx3Cu3VGU72VWH
8pSURaX/vE0Gp9LOALYZ/Pts8BU22v+s7VWnKTeYv2LuPEUUrJ8LwzyAMKkMRxtKExFT2MaGmMJZ
2NWmUToMI/piEDQXmqMxj60tzHJ5YvYNET9R5vuEiiI7/RVq3JPK+9rpguID5P4l5ZtCEhYUX9Bs
2/2DPzgjrg36FzcXKc/tXLFWXYxwo0MPJHO5mswFeLf4QzI6X5lX3f4JiEMZOvNXzOkJa0O4Dc2W
nrnzFhOcFNfD9DKkLC7zO+bTw79RMpoeGrQmmsyMK4G9jjAdfwsLI60GWfmwyngWS4HvqI9jgDOZ
0DD9Cj55ISKwpOxa4k3Hkl98QCcghYPwGMsPIoMYrnv5IndF5oHi/oeB8c3Hsr9KHnP+bGHZ9Iu1
aeXdxg8qtPyxROta0kTKrkCwPHyq+sX89LT0axi2grTKLQoYcKDhB8C36uIZDDENgvy3BqaXRIQz
qTGkgURknqxUsSpWA1wUM2OpTxoDZYjj8UgZEQdQ45tVHS4ObsOovtpGqg9B6MQ1o2g8ACkNcXDD
PZlwkZ8QyxTZW7UDlsqk3EOcDSKx93v25wCfiA6q34mWexImZt6p8k/005LM2+QOkTtaPIF9nnzM
ZZfDd+9evTw5Hr4+PP1LnkQBgEpBH1EakAOtK1fdMEbbXkSFO8eFdHFjqKzc4FzgbKqvbclOIjjV
OlblzCJnqoTFFN1ocFqralxEJo7M56DFunWkjOmbxL0SWSyiWCsWHblLfxrPZvFNkKSdK08HAmuV
0aLhKvE0TloNii6CjoiZ+xjIrkp4WyuSV7n5QxwXkYc5bRQaIv5C+bi2+DUxXVdsmfJ3qpZsndb9
zJh0stg6fE7NVRCAn8lEbyBtjBfmX3srHPqKAQp5RzTTBB3hjeXqcszojiQONeosF0kqwWSiNoge
mchN6tZlS+dngc5AKo/s9AdemQwKD40WNZUuOnKElJcNfieEOMOteUVCwhUazUJayDJgkS8YViJ3
6xzj6jNg6AOy2gNUlZ8kMRTbK2KoiQeaOE1FDeS4YlJ6PMkxsb8ptLU44vleue2b8rDm+ek5TDkW
HaPNAn98xdkJugeSY5fkmkqWz2rO3RKcNgySCDhGxvj7W4mkbTs+X23VP52jUpAETkd9cjHApcVu
VQdwReXAxbKDEB3iYxjWOsouLniboL9C1BM8QXw3+PKKhznwb+EW8IAFk0sM8KE3puMpl71P/nb6
EoPMoLiIyuE3/cLYmSzx1Tzxgog/m6EvwbSMhKXH8wRLWkb8EdBUKJCUU6HFUSmutTnmKaPoGuAI
1x49MKKUkgEW7fMtvnq2G3/NFLPy2l97rcZ2zS9nR6y/6ccvOLpV6UPqUqGrqRKsievEfFnpphEe
VXtKPb2XeHn1rOW3Tr14Xvzfbe4x73o5VwN7nu2mk1/mCLFPvCFvxtpzfo/5lMdqe2ZirQnfWjnh
FmcR8rni2XCFtwhm6LJwzTzyQuYyJFYcqGwjMwo+GMkKXJ8uyiN1PgQQVdgr82iZVV5JEdQVwI0G
+q352Rh11NIjMvKTMRvG83nDsHyVx2NWPhwjjoIDXdHk64dkaGb9G7atUhihk4pLUZLLG7XeF1rC
ke5eNRM/haUJvwpbJn4co1EGYjxFXwnCmo++ANMdePWPQpkTnxRuFvpEtLuVadD8KnCQYgTodWLK
ip0X/8i6e9bybn3zLm9uzpy9jac2d7zZMA26QLDNuuYYv8cm1ISFO++f3DyMN7nf9NpCk0NNVxio
c9YxRTnDlIGx8/uPJgC2zABuKlfy8uwDfo+hCuito9U+cWEdKtCi0j89t/AD22S0GX88KINByzWh
5DEKQ688mzKNdMWNnDziKd/c1XdWeBIi5fTgox1UDhDJ06TmDGFMJBdodIhUlNWveYiUVlLeRDs/
/hMPiNUeOejwQGHRQMndAR6asrUU95jOqDHBOhrkY+JSwJ+uQiN7cpzK+VLElPf9QQPnkHt4aqx5
ImqnYn4y2p+6oD0lMBV+TCb7n/xW3e91o/tfzg5rXC6QwDhDhErIEuXp5ozM+LJEwdqM6QgqC8J9
ts0LgsytZyyTeZqZWsOvIW6ZiYpn+JKswL6Go6Pp5T0DE2/iWLDqsp5MuP6ty/lAVf0II5d4Q8uW
QTgtE/8Irl5CfGZsJmDuWC0/uXBXtzZqjs2CxKDG73XsGmlTZYJGkpJyV6VDTHqwaFGcohyFQIae
Nrki85p5+rMlhmiM7irnrSgfBVN861xOx1YSCaZROaBXfYdj/3oO9HhneKMdramG5EJjJfOZejdX
B5HDoyxzjlcRmZTEdUZM03gc+jMyaJoelI/hJE/ugW4N2BzoGjjnJUWH9HKqYiKc4qUOxiPW5nrb
2HgxfPnmCM0Ij2hFi6hnbn1/VKL6yF9Owkz9xCO1lz4Pwh1KsU9yLYrCogD7R+ULxi9OlOghGdv8
ZqnuiWGDvTpK1QRS3+QFYuGTpkSxUkGRrYX/ohZyU+0Bf7ZZPe3UR5PVZoojdPGVtmKZX0k34shv
I9+IaUOHkgPH0WdEyo6HNaRXLvDOidrqTURWERF7z1fVcNw5OU2Uoe/VOmXwvePZeilzblXbi1xb
@@E splitae-B
```

## chunk splitaf (b64 lines 301-360)

### splitaf manifest

```text
@@B splitaf-manifest
301 99dfeab5
302 f7ec9cc6
303 df638c85
304 aefee84b
305 c320163b
306 39cf091d
307 03913dff
308 0b61e639
309 b679c263
310 2cb9d8e7
311 6f20100d
312 610ed527
313 52cf44ac
314 d6c722d2
315 ecbc5357
316 0efadeaf
317 71bbf7e3
318 a79630f0
319 fd847270
320 8e1d36e3
321 ed4a0c3f
322 ce5bb4fb
323 449301b5
324 315f97c1
325 b2b27cfd
326 e598878b
327 c85f2bee
328 b22355fb
329 b50f7a3e
330 4d6273c7
331 c18ed343
332 0b66089a
333 41bb5b6e
334 b696251a
335 0ab3115d
336 5410111f
337 65213a36
338 3c85a69b
339 343845c4
340 f58feb33
341 408a9c1a
342 56a3d43f
343 76040edf
344 d482f988
345 01edd23d
346 50f4a515
347 dea7671d
348 91024645
349 b0119908
350 7f3ed1ea
351 da4c0b3b
352 7c95e0f3
353 9114e54a
354 a9a1c549
355 93a3e506
356 ee192168
357 cabfd2aa
358 5ec5f794
359 3eaae4d6
360 bda76e56
@@E splitaf-manifest
```

### splitaf copy A

```
@@B splitaf-A
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
@@E splitaf-A
```

### splitaf copy B

```
@@B splitaf-B
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
@@E splitaf-B
```

## chunk splitag (b64 lines 361-405)

### splitag manifest

```text
@@B splitag-manifest
361 99193396
362 ed305e3c
363 4b14e031
364 bce2919f
365 29ff44a9
366 257a9f78
367 1ec1f470
368 ca522eef
369 494f6ed3
370 da44733b
371 a34ad219
372 e9484901
373 9d50eb58
374 dfc13f24
375 acec3011
376 81900a6b
377 83b720c8
378 dfdbca25
379 efef9840
380 00836b53
381 1598f007
382 9eb9f17c
383 b75f4206
384 3cf915e6
385 21340019
386 aeed0de1
387 07e08816
388 6015c9c6
389 bf725fe8
390 f2401210
391 9d4bcf51
392 712205fe
393 7ef75a80
394 7cbab05f
395 8807c51e
396 ff8ed83d
397 ec1025b4
398 916432b2
399 2b435f79
400 db8c8bb1
401 a15618e9
402 f80118e9
403 b9c17032
404 d872de7c
405 3d7be3ac
@@E splitag-manifest
```

### splitag copy A

```
@@B splitag-A
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
@@E splitag-A
```

### splitag copy B

```
@@B splitag-B
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
@@E splitag-B
```
