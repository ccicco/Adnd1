#!/usr/bin/env python3
# ============================================================================
# r1060_patch.py -- R1060: regtest efficiency round.
#   1. The three lua registries (items/, dm/, monsters/) reuse ONE
#      lua_State per loadDirectory (was: one newstate+openlibs+close
#      per file - ~1,500 VM rounds per battery run). Every loaded lua
#      file is a pure `return { ... }` literal (verified across all
#      2,233 files of content/), and lua_settop(L, 0) between files
#      restores the exact fresh-state stack layout, so battery
#      output is byte-identical. loadFile keeps its fresh-state
#      entry (API parity); loadDirectory drives loadFileOnState.
#   2. tools/preflight.sh step 2: the one-shot 28-TU g++ compile is
#      now per-TU object compiles in a job pool (capped min(nproc,4),
#      phone OOM safety) plus one link. Same flags, same R515 warning
#      gate, same fresh-binary chain, same regtest exit authority,
#      failed TUs still name their file (BUILD FAIL). regtest.cpp is
#      NOT touched: census stays 1127.
# The edit spec rides below as a base64 JSON blob (no quoting
# hazards); each pair was proven to reproduce the patched file from
# the ded07fff pristine, byte for byte.
# Idempotent: rerun prints "already applied" and changes nothing.
# Mixed or drifted trees die LOUDLY naming the file and the remedy.
# ============================================================================
import base64
import hashlib
import json
import os
import sys

SPEC = json.loads(base64.b64decode(
    "eyJpdGVtcy9NaXNjSXRlbVJlZ2lzdHJ5LmgiOiB7Im1kNV9wcmlzdGluZSI6ICJmMjgzYjllYTQ4"
    "NjRhMzhhYzg3ODRlM2QxZGU0MWYwYiIsICJtZDVfZ29sZGVuIjogIjRiYzA1MjY1MmEzNDdlMGVk"
    "ZWUzYmEyN2U4ZDYzNjU1IiwgInBhaXJzIjogW1siI2luY2x1ZGUgPHZlY3Rvcj5cbiIsICIjaW5j"
    "bHVkZSA8dmVjdG9yPlxuXG4vLyBSMTA2MDogZm9yd2FyZCBkZWNsYXJhdGlvbiwgaWRlbnRpY2Fs"
    "IHRvIGx1YS5oJ3MgdHlwZWRlZiAtIHRoZVxuLy8gaGVhZGVyIGRvZXMgbm90IG5lZWQgdGhlIHJl"
    "YWwgbHVhLmggZm9yIHRoZSBzaGFyZWQtc3RhdGUgZW50cnkuXG50eXBlZGVmIHN0cnVjdCBsdWFf"
    "U3RhdGUgbHVhX1N0YXRlO1xuIl0sIFsiICAgIGJvb2wgbG9hZEZpbGUoY29uc3Qgc3RkOjpzdHJp"
    "bmcmIHBhdGgsIGNvbnN0IHN0ZDo6c3RyaW5nJiBrZXkpO1xuIiwgIiAgICBib29sIGxvYWRGaWxl"
    "KGNvbnN0IHN0ZDo6c3RyaW5nJiBwYXRoLCBjb25zdCBzdGQ6OnN0cmluZyYga2V5KTtcbiAgICAv"
    "LyBSMTA2MDogc2hhcmVkLXN0YXRlIGVudHJ5IC0gbG9hZERpcmVjdG9yeSByZXVzZXMgb25lIGx1"
    "YV9TdGF0ZVxuICAgIC8vIGFjcm9zcyBmaWxlcyAob25lIFZNICsgb3BlbmxpYnMgcGVyIGRpcmVj"
    "dG9yeSwgd2FzIHBlciBmaWxlKS5cbiAgICBib29sIGxvYWRGaWxlT25TdGF0ZShsdWFfU3RhdGUq"
    "IEwsIGNvbnN0IHN0ZDo6c3RyaW5nJiBwYXRoLFxuICAgICAgICAgICAgICAgICAgICAgICAgIGNv"
    "bnN0IHN0ZDo6c3RyaW5nJiBrZXkpO1xuIl1dfSwgIml0ZW1zL01pc2NJdGVtUmVnaXN0cnkuY3Bw"
    "IjogeyJtZDVfcHJpc3RpbmUiOiAiZWQ0MGE1YjNiNzg0OTk4ZmM5ZjgyMTIyZmM2MzRkZjkiLCAi"
    "bWQ1X2dvbGRlbiI6ICJjMjI0ZjRhYTE4N2M1M2YwODNjOWY1ZDkwZTc3N2JmZSIsICJwYWlycyI6"
    "IFtbIi8vIG1vbnN0ZXJzL01vbnN0ZXJSZWdpc3RyeS5jcHA6IGEgZnJlc2ggbHVhX1N0YXRlIHBl"
    "ciBmaWxlLFxuLy8gbHVhTF9kb2ZpbGUsIHRoZSBmaWxlIG11c3QgbGVhdmUgYSB0YWJsZSBvbiB0"
    "aGUgc3RhY2ssIHR5cGVkXG4iLCAiLy8gbW9uc3RlcnMvTW9uc3RlclJlZ2lzdHJ5LmNwcCAoUjEw"
    "NjA6IG9uZSBsdWFfU3RhdGUgcGVyXG4vLyBsb2FkRGlyZWN0b3J5IHdpdGggbHVhX3NldHRvcChM"
    "LCAwKSBiZXR3ZWVuIGZpbGVzIC0gd2FzIGFcbi8vIGZyZXNoIHN0YXRlIHBlciBmaWxlKSwgbHVh"
    "TF9kb2ZpbGUsIHRoZSBmaWxlIG11c3QgbGVhdmUgYVxuLy8gdGFibGUgb24gdGhlIHN0YWNrLCB0"
    "eXBlZFxuIl0sIFsiLy8gd2l0aG91dCB1bndpbmRpbmcgLSBsb2FkRmlsZSBjbG9zZXMgdGhlIGx1"
    "YV9TdGF0ZSwgc28gYVxuLy8gdHJhbnNpZW50IGltYmFsYW5jZSBvbiBhIGR5aW5nIGxvYWQgbGVh"
    "a3Mgbm90aGluZy5cbiIsICIvLyB3aXRob3V0IHVud2luZGluZyAtIGV2ZXJ5IGNhbGxlciByZXNl"
    "dHMgdGhlIHN0YXRlIGFmdGVyd2FyZHNcbi8vIChsb2FkRmlsZSBjbG9zZXMgaXQ7IGxvYWREaXJl"
    "Y3RvcnkgbHVhX3NldHRvcChMLCAwKXMgYmVmb3JlXG4vLyB0aGUgbmV4dCBmaWxlKSwgc28gYSB0"
    "cmFuc2llbnQgaW1iYWxhbmNlIG9uIGEgZHlpbmcgbG9hZFxuLy8gbGVha3Mgbm90aGluZy5cbiJd"
    "LCBbIiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgY29uc3Qgc3RkOjpzdHJpbmcmIGtl"
    "eSkge1xuIiwgIiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgY29uc3Qgc3RkOjpzdHJp"
    "bmcmIGtleSkge1xuICAgIC8vIFIxMDYwOiBmcmVzaC1zdGF0ZSBlbnRyeSBrZXB0IGZvciBBUEkg"
    "cGFyaXR5OyB0aGUgZGlyZWN0b3J5XG4gICAgLy8gcGF0aCByZXVzZXMgb25lIFZNIHZpYSBsb2Fk"
    "RmlsZU9uU3RhdGUgKHdhcyBwZXIgZmlsZSkuXG4iXSwgWyIgICAgbHVhTF9vcGVubGlicyhMKTsg"
    "ICAvLyByZWdpc3RyeSBmaWxlcyBtYXkgdXNlIHN0cmluZyBjb25jYXQgaW4gY29tbWVudHNcbiIs"
    "ICIgICAgbHVhTF9vcGVubGlicyhMKTsgICAvLyByZWdpc3RyeSBmaWxlcyBtYXkgdXNlIHN0cmlu"
    "ZyBjb25jYXQgaW4gY29tbWVudHNcbiAgICBjb25zdCBib29sIG9rID0gbG9hZEZpbGVPblN0YXRl"
    "KEwsIHBhdGgsIGtleSk7XG4gICAgbHVhX2Nsb3NlKEwpO1xuICAgIHJldHVybiBvaztcbn1cbiJd"
    "LCBbIlxuICAgIGlmIChsdWFMX2RvZmlsZShMLCBwYXRoLmNfc3RyKCkpICE9IExVQV9PSykge1xu"
    "IiwgIlxuYm9vbCBNaXNjSXRlbVJlZ2lzdHJ5Ojpsb2FkRmlsZU9uU3RhdGUobHVhX1N0YXRlKiBM"
    "LFxuICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgY29uc3Qgc3RkOjpzdHJp"
    "bmcmIHBhdGgsXG4gICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBjb25zdCBz"
    "dGQ6OnN0cmluZyYga2V5KSB7XG4gICAgaWYgKGx1YUxfZG9maWxlKEwsIHBhdGguY19zdHIoKSkg"
    "IT0gTFVBX09LKSB7XG4iXSwgWyIgICAgICAgIG1fZXJyb3JzLnB1c2hfYmFjayhidWYpO1xuICAg"
    "ICAgICBsdWFfY2xvc2UoTCk7XG4iLCAiICAgICAgICBtX2Vycm9ycy5wdXNoX2JhY2soYnVmKTtc"
    "biJdLCBbIiAgICAgICAgbV9lcnJvcnMucHVzaF9iYWNrKGtleSArIFwiOiBmaWxlIG11c3QgcmV0"
    "dXJuIGEgdGFibGVcIik7XG4gICAgICAgIGx1YV9jbG9zZShMKTtcbiIsICIgICAgICAgIG1fZXJy"
    "b3JzLnB1c2hfYmFjayhrZXkgKyBcIjogZmlsZSBtdXN0IHJldHVybiBhIHRhYmxlXCIpO1xuIl0s"
    "IFsiICAgICAgICBtX2Vycm9ycy5wdXNoX2JhY2soa2V5ICsgXCI6IFwiICsgZXJyKTtcbiAgICAg"
    "ICAgbHVhX2Nsb3NlKEwpO1xuIiwgIiAgICAgICAgbV9lcnJvcnMucHVzaF9iYWNrKGtleSArIFwi"
    "OiBcIiArIGVycik7XG4iXSwgWyIgICAgICAgICAgICAgICAgICAgICAgICAgICArIFwiJyBkb2Vz"
    "IG5vdCBtYXRjaCBmaWxlIHN0ZW1cIik7XG4gICAgICAgIGx1YV9jbG9zZShMKTtcbiIsICIgICAg"
    "ICAgICAgICAgICAgICAgICAgICAgICArIFwiJyBkb2VzIG5vdCBtYXRjaCBmaWxlIHN0ZW1cIik7"
    "XG4iXSwgWyIgICAgICAgIGx1YV9jbG9zZShMKTtcbiIsICIiXSwgWyIgICAgbV9kZWZzW2RlZi5r"
    "ZXldID0gZGVmO1xuICAgIGx1YV9jbG9zZShMKTtcbiIsICIgICAgbV9kZWZzW2RlZi5rZXldID0g"
    "ZGVmO1xuIl0sIFsiICAgICAgICByZXR1cm4gR2V0TGFzdEVycm9yKCkgPT0gRVJST1JfRklMRV9O"
    "T1RfRk9VTkQgPyAwIDogLTE7XG4gICAgfVxuIiwgIiAgICAgICAgcmV0dXJuIEdldExhc3RFcnJv"
    "cigpID09IEVSUk9SX0ZJTEVfTk9UX0ZPVU5EID8gMCA6IC0xO1xuICAgIH1cbiAgICAvLyBSMTA2"
    "MDogb25lIGx1YV9TdGF0ZSBmb3IgdGhlIHdob2xlIGRpcmVjdG9yeSAod2FzOiBvbmUgcGVyIGZp"
    "bGUpLlxuICAgIGx1YV9TdGF0ZSogTCA9IGx1YUxfbmV3c3RhdGUoKTtcbiAgICBsdWFMX29wZW5s"
    "aWJzKEwpOyAgIC8vIHJlZ2lzdHJ5IGZpbGVzIG1heSB1c2Ugc3RyaW5nIGNvbmNhdCBpbiBjb21t"
    "ZW50c1xuIl0sIFsiICAgICAgICBpZiAobG9hZEZpbGUoZGlyUGF0aCArIFwiXFxcXFwiICsgZm5h"
    "bWUsIGtleSkpICsrY291bnQ7XG4iLCAiICAgICAgICBpZiAobG9hZEZpbGVPblN0YXRlKEwsIGRp"
    "clBhdGggKyBcIlxcXFxcIiArIGZuYW1lLCBrZXkpKSArK2NvdW50O1xuICAgICAgICBsdWFfc2V0"
    "dG9wKEwsIDApOyAgIC8vIFIxMDYwOiByZXNldCB0aGUgc3RhY2sgYmV0d2VlbiBmaWxlc1xuIl0s"
    "IFsiICAgIEZpbmRDbG9zZShoKTtcbiIsICIgICAgRmluZENsb3NlKGgpO1xuICAgIGx1YV9jbG9z"
    "ZShMKTtcbiJdLCBbIiAgICBpZiAoIWQpIHJldHVybiAtMTtcbiIsICIgICAgaWYgKCFkKSByZXR1"
    "cm4gLTE7XG4gICAgLy8gUjEwNjA6IG9uZSBsdWFfU3RhdGUgZm9yIHRoZSB3aG9sZSBkaXJlY3Rv"
    "cnkgKHdhczogb25lIHBlciBmaWxlLFxuICAgIC8vIH4xLDUwMCBuZXdzdGF0ZStvcGVubGlicytj"
    "bG9zZSByb3VuZHMgcGVyIGJhdHRlcnkgcnVuKS5cbiAgICBsdWFfU3RhdGUqIEwgPSBsdWFMX25l"
    "d3N0YXRlKCk7XG4gICAgbHVhTF9vcGVubGlicyhMKTsgICAvLyByZWdpc3RyeSBmaWxlcyBtYXkg"
    "dXNlIHN0cmluZyBjb25jYXQgaW4gY29tbWVudHNcbiJdLCBbIiAgICAgICAgaWYgKGxvYWRGaWxl"
    "KGRpclBhdGggKyBcIi9cIiArIGZuYW1lLCBrZXkpKSArK2NvdW50O1xuIiwgIiAgICAgICAgaWYg"
    "KGxvYWRGaWxlT25TdGF0ZShMLCBkaXJQYXRoICsgXCIvXCIgKyBmbmFtZSwga2V5KSkgKytjb3Vu"
    "dDtcbiAgICAgICAgbHVhX3NldHRvcChMLCAwKTsgICAvLyBSMTA2MDogcmVzZXQgdGhlIHN0YWNr"
    "IGJldHdlZW4gZmlsZXNcbiJdLCBbIiAgICBjbG9zZWRpcihkKTtcbiIsICIgICAgY2xvc2VkaXIo"
    "ZCk7XG4gICAgbHVhX2Nsb3NlKEwpO1xuIl1dfSwgImRtL0VuY291bnRlclRhYmxlUmVnaXN0cnku"
    "aCI6IHsibWQ1X3ByaXN0aW5lIjogIjMzOTliYWMzMDE5MGVjNzRhMjI2OWE1OGYzNTQwZTg0Iiwg"
    "Im1kNV9nb2xkZW4iOiAiM2I2ZmQ0YzQzY2ZmMDAxMGU1OGVjYzk2ZGJmNDJlYmYiLCAicGFpcnMi"
    "OiBbWyIjaW5jbHVkZSA8dmVjdG9yPlxuIiwgIiNpbmNsdWRlIDx2ZWN0b3I+XG5cbi8vIFIxMDYw"
    "OiBmb3J3YXJkIGRlY2xhcmF0aW9uLCBpZGVudGljYWwgdG8gbHVhLmgncyB0eXBlZGVmIC0gdGhl"
    "XG4vLyBoZWFkZXIgZG9lcyBub3QgbmVlZCB0aGUgcmVhbCBsdWEuaCBmb3IgdGhlIHNoYXJlZC1z"
    "dGF0ZSBlbnRyeS5cbnR5cGVkZWYgc3RydWN0IGx1YV9TdGF0ZSBsdWFfU3RhdGU7XG4iXSwgWyIg"
    "ICAgYm9vbCBsb2FkRmlsZShjb25zdCBzdGQ6OnN0cmluZyYgcGF0aCwgY29uc3Qgc3RkOjpzdHJp"
    "bmcmIGtleSk7XG4iLCAiICAgIGJvb2wgbG9hZEZpbGUoY29uc3Qgc3RkOjpzdHJpbmcmIHBhdGgs"
    "IGNvbnN0IHN0ZDo6c3RyaW5nJiBrZXkpO1xuICAgIC8vIFIxMDYwOiBzaGFyZWQtc3RhdGUgZW50"
    "cnkgLSBsb2FkRGlyZWN0b3J5IHJldXNlcyBvbmUgbHVhX1N0YXRlXG4gICAgLy8gYWNyb3NzIGZp"
    "bGVzIChvbmUgVk0gKyBvcGVubGlicyBwZXIgZGlyZWN0b3J5LCB3YXMgcGVyIGZpbGUpLlxuICAg"
    "IGJvb2wgbG9hZEZpbGVPblN0YXRlKGx1YV9TdGF0ZSogTCwgY29uc3Qgc3RkOjpzdHJpbmcmIHBh"
    "dGgsXG4gICAgICAgICAgICAgICAgICAgICAgICAgY29uc3Qgc3RkOjpzdHJpbmcmIGtleSk7XG4i"
    "XV19LCAiZG0vRW5jb3VudGVyVGFibGVSZWdpc3RyeS5jcHAiOiB7Im1kNV9wcmlzdGluZSI6ICIy"
    "ODQwZDI2ZjI2MWJhNjMxZDY4OTcwZWE5NTc1ODI3NiIsICJtZDVfZ29sZGVuIjogIjVmYzI0MmQy"
    "OTZjZTU0NmI1ZjhmNzViYjI3MjNmMTZkIiwgInBhaXJzIjogW1siLy8gZm9sbG93cyBpdGVtczo6"
    "TWlzY0l0ZW1SZWdpc3RyeS5jcHA6IGEgZnJlc2ggbHVhX1N0YXRlIHBlciBmaWxlLFxuLy8gbHVh"
    "TF9kb2ZpbGUsIHRoZSBmaWxlIG11c3QgbGVhdmUgYSB0YWJsZSBvbiB0aGUgc3RhY2ssIHR5cGVk"
    "IGdldHRlcnNcbiIsICIvLyBmb2xsb3dzIGl0ZW1zOjpNaXNjSXRlbVJlZ2lzdHJ5LmNwcCAoUjEw"
    "NjA6IG9uZSBsdWFfU3RhdGUgcGVyXG4vLyBsb2FkRGlyZWN0b3J5IHdpdGggbHVhX3NldHRvcChM"
    "LCAwKSBiZXR3ZWVuIGZpbGVzIC0gd2FzIGEgZnJlc2hcbi8vIHN0YXRlIHBlciBmaWxlKSwgbHVh"
    "TF9kb2ZpbGUsIHRoZSBmaWxlIG11c3QgbGVhdmUgYSB0YWJsZSBvbiB0aGVcbi8vIHN0YWNrLCB0"
    "eXBlZCBnZXR0ZXJzXG4iXSwgWyIgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAg"
    "IGNvbnN0IHN0ZDo6c3RyaW5nJiBrZXkpIHtcbiIsICIgICAgICAgICAgICAgICAgICAgICAgICAg"
    "ICAgICAgICAgICAgIGNvbnN0IHN0ZDo6c3RyaW5nJiBrZXkpIHtcbiAgICAvLyBSMTA2MDogZnJl"
    "c2gtc3RhdGUgZW50cnkga2VwdCBmb3IgQVBJIHBhcml0eTsgdGhlIGRpcmVjdG9yeVxuICAgIC8v"
    "IHBhdGggcmV1c2VzIG9uZSBWTSB2aWEgbG9hZEZpbGVPblN0YXRlICh3YXMgcGVyIGZpbGUpLlxu"
    "Il0sIFsiICAgIGx1YUxfb3BlbmxpYnMoTCk7XG4iLCAiICAgIGx1YUxfb3BlbmxpYnMoTCk7XG4g"
    "ICAgY29uc3QgYm9vbCBvayA9IGxvYWRGaWxlT25TdGF0ZShMLCBwYXRoLCBrZXkpO1xuICAgIGx1"
    "YV9jbG9zZShMKTtcbiAgICByZXR1cm4gb2s7XG59XG4iXSwgWyJcbiAgICBpZiAobHVhTF9kb2Zp"
    "bGUoTCwgcGF0aC5jX3N0cigpKSAhPSBMVUFfT0spIHtcbiIsICJcbmJvb2wgRW5jb3VudGVyVGFi"
    "bGVSZWdpc3RyeTo6bG9hZEZpbGVPblN0YXRlKGx1YV9TdGF0ZSogTCxcbiAgICAgICAgICAgICAg"
    "ICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBjb25zdCBzdGQ6OnN0cmluZyYgcGF0aCxc"
    "biAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBjb25zdCBzdGQ6"
    "OnN0cmluZyYga2V5KSB7XG4gICAgaWYgKGx1YUxfZG9maWxlKEwsIHBhdGguY19zdHIoKSkgIT0g"
    "TFVBX09LKSB7XG4iXSwgWyIgICAgICAgIG1fZXJyb3JzLnB1c2hfYmFjayhidWYpO1xuICAgICAg"
    "ICBsdWFfY2xvc2UoTCk7XG4iLCAiICAgICAgICBtX2Vycm9ycy5wdXNoX2JhY2soYnVmKTtcbiJd"
    "LCBbIiAgICAgICAgbHVhX2Nsb3NlKEwpO1xuIiwgIiJdLCBbIiAgICB9XG5cbiAgICBsdWFfY2xv"
    "c2UoTCk7XG4iLCAiICAgIH1cblxuIl0sIFsiICAgIG1fZXJyb3JzLnB1c2hfYmFjayhrZXkgKyBc"
    "IjogXCIgKyBlcnIpO1xuICAgIGx1YV9jbG9zZShMKTtcbiIsICIgICAgbV9lcnJvcnMucHVzaF9i"
    "YWNrKGtleSArIFwiOiBcIiArIGVycik7XG4iXSwgWyIgICAgICAgIHJldHVybiBHZXRMYXN0RXJy"
    "b3IoKSA9PSBFUlJPUl9GSUxFX05PVF9GT1VORCA/IDAgOiAtMTtcbiAgICB9XG4iLCAiICAgICAg"
    "ICByZXR1cm4gR2V0TGFzdEVycm9yKCkgPT0gRVJST1JfRklMRV9OT1RfRk9VTkQgPyAwIDogLTE7"
    "XG4gICAgfVxuICAgIC8vIFIxMDYwOiBvbmUgbHVhX1N0YXRlIGZvciB0aGUgd2hvbGUgZGlyZWN0"
    "b3J5ICh3YXM6IG9uZSBwZXIgZmlsZSkuXG4gICAgbHVhX1N0YXRlKiBMID0gbHVhTF9uZXdzdGF0"
    "ZSgpO1xuICAgIGx1YUxfb3BlbmxpYnMoTCk7XG4iXSwgWyIgICAgICAgIGlmIChsb2FkRmlsZShk"
    "aXJQYXRoICsgXCJcXFxcXCIgKyBmbmFtZSwga2V5KSkgKytjb3VudDtcbiIsICIgICAgICAgIGlm"
    "IChsb2FkRmlsZU9uU3RhdGUoTCwgZGlyUGF0aCArIFwiXFxcXFwiICsgZm5hbWUsIGtleSkpICsr"
    "Y291bnQ7XG4gICAgICAgIGx1YV9zZXR0b3AoTCwgMCk7ICAgLy8gUjEwNjA6IHJlc2V0IHRoZSBz"
    "dGFjayBiZXR3ZWVuIGZpbGVzXG4iXSwgWyIgICAgRmluZENsb3NlKGgpO1xuIiwgIiAgICBGaW5k"
    "Q2xvc2UoaCk7XG4gICAgbHVhX2Nsb3NlKEwpO1xuIl0sIFsiICAgIGlmICghZCkgcmV0dXJuIC0x"
    "O1xuIiwgIiAgICBpZiAoIWQpIHJldHVybiAtMTtcbiAgICAvLyBSMTA2MDogb25lIGx1YV9TdGF0"
    "ZSBmb3IgdGhlIHdob2xlIGRpcmVjdG9yeSAod2FzOiBvbmUgcGVyIGZpbGUsXG4gICAgLy8gfjEs"
    "NTAwIG5ld3N0YXRlK29wZW5saWJzK2Nsb3NlIHJvdW5kcyBwZXIgYmF0dGVyeSBydW4pLlxuICAg"
    "IGx1YV9TdGF0ZSogTCA9IGx1YUxfbmV3c3RhdGUoKTtcbiAgICBsdWFMX29wZW5saWJzKEwpO1xu"
    "Il0sIFsiICAgICAgICBpZiAobG9hZEZpbGUoZGlyUGF0aCArIFwiL1wiICsgZm5hbWUsIGtleSkp"
    "ICsrY291bnQ7XG4iLCAiICAgICAgICBpZiAobG9hZEZpbGVPblN0YXRlKEwsIGRpclBhdGggKyBc"
    "Ii9cIiArIGZuYW1lLCBrZXkpKSArK2NvdW50O1xuICAgICAgICBsdWFfc2V0dG9wKEwsIDApOyAg"
    "IC8vIFIxMDYwOiByZXNldCB0aGUgc3RhY2sgYmV0d2VlbiBmaWxlc1xuIl0sIFsiICAgIGNsb3Nl"
    "ZGlyKGQpO1xuIiwgIiAgICBjbG9zZWRpcihkKTtcbiAgICBsdWFfY2xvc2UoTCk7XG4iXV19LCAi"
    "bW9uc3RlcnMvTW9uc3RlclJlZ2lzdHJ5LmgiOiB7Im1kNV9wcmlzdGluZSI6ICJmZjI4OGFjMmYy"
    "MDcwMGJiYWYxYWI4NDA1Yjc2ZTg5OSIsICJtZDVfZ29sZGVuIjogImVjM2E0MTMyZDZhZDNhNmEw"
    "NmY1YzljMjkxNDI5MjVmIiwgInBhaXJzIjogW1siI2luY2x1ZGUgPHZlY3Rvcj5cbiIsICIjaW5j"
    "bHVkZSA8dmVjdG9yPlxuXG4vLyBSMTA2MDogZm9yd2FyZCBkZWNsYXJhdGlvbiwgaWRlbnRpY2Fs"
    "IHRvIGx1YS5oJ3MgdHlwZWRlZiAtIHRoZVxuLy8gaGVhZGVyIGRvZXMgbm90IG5lZWQgdGhlIHJl"
    "YWwgbHVhLmggZm9yIHRoZSBzaGFyZWQtc3RhdGUgZW50cnkuXG50eXBlZGVmIHN0cnVjdCBsdWFf"
    "U3RhdGUgbHVhX1N0YXRlO1xuIl0sIFsiICAgIGJvb2wgbG9hZEZpbGUoY29uc3Qgc3RkOjpzdHJp"
    "bmcmIHBhdGgsIGNvbnN0IHN0ZDo6c3RyaW5nJiBrZXkpO1xuIiwgIiAgICBib29sIGxvYWRGaWxl"
    "KGNvbnN0IHN0ZDo6c3RyaW5nJiBwYXRoLCBjb25zdCBzdGQ6OnN0cmluZyYga2V5KTtcbiAgICAv"
    "LyBSMTA2MDogc2hhcmVkLXN0YXRlIGVudHJ5IC0gbG9hZERpcmVjdG9yeSByZXVzZXMgb25lIGx1"
    "YV9TdGF0ZVxuICAgIC8vIGFjcm9zcyBmaWxlcyAob25lIFZNICsgb3BlbmxpYnMgcGVyIGRpcmVj"
    "dG9yeSwgd2FzIHBlciBmaWxlKS5cbiAgICBib29sIGxvYWRGaWxlT25TdGF0ZShsdWFfU3RhdGUq"
    "IEwsIGNvbnN0IHN0ZDo6c3RyaW5nJiBwYXRoLFxuICAgICAgICAgICAgICAgICAgICAgICAgIGNv"
    "bnN0IHN0ZDo6c3RyaW5nJiBrZXkpO1xuIl1dfSwgIm1vbnN0ZXJzL01vbnN0ZXJSZWdpc3RyeS5j"
    "cHAiOiB7Im1kNV9wcmlzdGluZSI6ICI4YmViZDVjMGQ3MDRlZTBmYjE1N2E4OTY2YzQ5ZWZlYSIs"
    "ICJtZDVfZ29sZGVuIjogImRiYTMwZDM2MjVlYjUxMzdiYzYzOTE1ODJlMjc3OTVlIiwgInBhaXJz"
    "IjogW1siICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIGNvbnN0IHN0ZDo6c3RyaW5nJiBr"
    "ZXkpIHtcbiIsICIgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgY29uc3Qgc3RkOjpzdHJp"
    "bmcmIGtleSkge1xuICAgIC8vIFIxMDYwOiBmcmVzaC1zdGF0ZSBlbnRyeSBrZXB0IGZvciBBUEkg"
    "cGFyaXR5OyB0aGUgZGlyZWN0b3J5XG4gICAgLy8gcGF0aCByZXVzZXMgb25lIFZNIHZpYSBsb2Fk"
    "RmlsZU9uU3RhdGUgKHdhcyBwZXIgZmlsZSkuXG4iXSwgWyIgICAgbHVhTF9vcGVubGlicyhMKTsg"
    "ICAvLyByZWdpc3RyeSBmaWxlcyBtYXkgdXNlIGJhc2ljIG1hdGggaWYgZGVzaXJlZFxuIiwgIiAg"
    "ICBsdWFMX29wZW5saWJzKEwpOyAgIC8vIHJlZ2lzdHJ5IGZpbGVzIG1heSB1c2UgYmFzaWMgbWF0"
    "aCBpZiBkZXNpcmVkXG4gICAgY29uc3QgYm9vbCBvayA9IGxvYWRGaWxlT25TdGF0ZShMLCBwYXRo"
    "LCBrZXkpO1xuICAgIGx1YV9jbG9zZShMKTtcbiAgICByZXR1cm4gb2s7XG59XG4iXSwgWyJcbiAg"
    "ICBpZiAobHVhTF9kb2ZpbGUoTCwgcGF0aC5jX3N0cigpKSAhPSBMVUFfT0spIHtcbiIsICJcbmJv"
    "b2wgTW9uc3RlclJlZ2lzdHJ5Ojpsb2FkRmlsZU9uU3RhdGUobHVhX1N0YXRlKiBMLFxuICAgICAg"
    "ICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBjb25zdCBzdGQ6OnN0cmluZyYgcGF0aCxc"
    "biAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgY29uc3Qgc3RkOjpzdHJpbmcm"
    "IGtleSkge1xuICAgIGlmIChsdWFMX2RvZmlsZShMLCBwYXRoLmNfc3RyKCkpICE9IExVQV9PSykg"
    "e1xuIl0sIFsiICAgICAgICBtX2Vycm9ycy5wdXNoX2JhY2soYnVmKTtcbiAgICAgICAgbHVhX2Ns"
    "b3NlKEwpO1xuIiwgIiAgICAgICAgbV9lcnJvcnMucHVzaF9iYWNrKGJ1Zik7XG4iXSwgWyIgICAg"
    "ICAgIGx1YV9jbG9zZShMKTtcbiIsICIiXSwgWyIgICAgZGVmLmlzTGVhZGVyID0gbHVhR2V0Qm9v"
    "bChMLCBcImlzTGVhZGVyXCIsIGZhbHNlKTtcblxuICAgIGx1YV9jbG9zZShMKTtcbiIsICIgICAg"
    "ZGVmLmlzTGVhZGVyID0gbHVhR2V0Qm9vbChMLCBcImlzTGVhZGVyXCIsIGZhbHNlKTtcblxuIl0s"
    "IFsiICAgICAgICByZXR1cm4gR2V0TGFzdEVycm9yKCkgPT0gRVJST1JfRklMRV9OT1RfRk9VTkQg"
    "PyAwIDogLTE7XG4gICAgfVxuIiwgIiAgICAgICAgcmV0dXJuIEdldExhc3RFcnJvcigpID09IEVS"
    "Uk9SX0ZJTEVfTk9UX0ZPVU5EID8gMCA6IC0xO1xuICAgIH1cbiAgICAvLyBSMTA2MDogb25lIGx1"
    "YV9TdGF0ZSBmb3IgdGhlIHdob2xlIGRpcmVjdG9yeSAod2FzOiBvbmUgcGVyIGZpbGUpLlxuICAg"
    "IGx1YV9TdGF0ZSogTCA9IGx1YUxfbmV3c3RhdGUoKTtcbiAgICBsdWFMX29wZW5saWJzKEwpOyAg"
    "IC8vIHJlZ2lzdHJ5IGZpbGVzIG1heSB1c2UgYmFzaWMgbWF0aCBpZiBkZXNpcmVkXG4iXSwgWyIg"
    "ICAgICAgIGlmIChsb2FkRmlsZShkaXJQYXRoICsgXCJcXFxcXCIgKyBmbmFtZSwga2V5KSkgKytj"
    "b3VudDtcbiIsICIgICAgICAgIGlmIChsb2FkRmlsZU9uU3RhdGUoTCwgZGlyUGF0aCArIFwiXFxc"
    "XFwiICsgZm5hbWUsIGtleSkpICsrY291bnQ7XG4gICAgICAgIGx1YV9zZXR0b3AoTCwgMCk7ICAg"
    "Ly8gUjEwNjA6IHJlc2V0IHRoZSBzdGFjayBiZXR3ZWVuIGZpbGVzXG4iXSwgWyIgICAgRmluZENs"
    "b3NlKGgpO1xuIiwgIiAgICBGaW5kQ2xvc2UoaCk7XG4gICAgbHVhX2Nsb3NlKEwpO1xuIl0sIFsi"
    "ICAgIGlmICghZCkgcmV0dXJuIC0xO1xuIiwgIiAgICBpZiAoIWQpIHJldHVybiAtMTtcbiAgICAv"
    "LyBSMTA2MDogb25lIGx1YV9TdGF0ZSBmb3IgdGhlIHdob2xlIGRpcmVjdG9yeSAod2FzOiBvbmUg"
    "cGVyIGZpbGUsXG4gICAgLy8gfjEsNTAwIG5ld3N0YXRlK29wZW5saWJzK2Nsb3NlIHJvdW5kcyBw"
    "ZXIgYmF0dGVyeSBydW4pLlxuICAgIGx1YV9TdGF0ZSogTCA9IGx1YUxfbmV3c3RhdGUoKTtcbiAg"
    "ICBsdWFMX29wZW5saWJzKEwpOyAgIC8vIHJlZ2lzdHJ5IGZpbGVzIG1heSB1c2UgYmFzaWMgbWF0"
    "aCBpZiBkZXNpcmVkXG4iXSwgWyIgICAgICAgIGlmIChsb2FkRmlsZShkaXJQYXRoICsgXCIvXCIg"
    "KyBmbmFtZSwga2V5KSkgKytjb3VudDtcbiIsICIgICAgICAgIGlmIChsb2FkRmlsZU9uU3RhdGUo"
    "TCwgZGlyUGF0aCArIFwiL1wiICsgZm5hbWUsIGtleSkpICsrY291bnQ7XG4gICAgICAgIGx1YV9z"
    "ZXR0b3AoTCwgMCk7ICAgLy8gUjEwNjA6IHJlc2V0IHRoZSBzdGFjayBiZXR3ZWVuIGZpbGVzXG4i"
    "XSwgWyIgICAgY2xvc2VkaXIoZCk7XG4iLCAiICAgIGNsb3NlZGlyKGQpO1xuICAgIGx1YV9jbG9z"
    "ZShMKTtcbiJdXX0sICJ0b29scy9wcmVmbGlnaHQuc2giOiB7Im1kNV9wcmlzdGluZSI6ICJhYTVi"
    "OGQyZjk5MTNmMGJmYjQ4MTA1NGQxNzMyN2JkMSIsICJtZDVfZ29sZGVuIjogIjdhYTE2YzcxNWFk"
    "ZWIwODYwMjRmYzZhNzE3MmYyYTJjIiwgInBhaXJzIjogW1siIyBuZXZlciByYW4gKHRoZSA3YTg2"
    "ZWU3IGxlc3NvbikuIFN0ZXBzIHJlbnVtYmVyZWQgdG8gNS5cbiIsICIjIG5ldmVyIHJhbiAodGhl"
    "IDdhODZlZTcgbGVzc29uKS4gU3RlcHMgcmVudW1iZXJlZCB0byA1LlxuIyBSMTA2MDogdGhlIHN0"
    "ZXAtMiBidWlsZCBpcyBwYXJhbGxlbCAtIHBlci1UVSBvYmplY3QgY29tcGlsZXNcbiMgaW4gYSBq"
    "b2IgcG9vbCAoY2FwcGVkIGF0IG1pbihucHJvYywgNCk7IG9uZSBnKysgcGVyIHBob25lXG4jIGNv"
    "cmUgaXMgYW4gT09NIHJpc2ssIGFuZCB0aGUgcmVndGVzdC5jcHAgbWVnYS1UVSBkb21pbmF0ZXNc"
    "biMgdGhlIHdhbGwgY2xvY2sgYW55d2F5KSBwbHVzIG9uZSBsaW5rLiBTYW1lIGZsYWdzIHBlciBU"
    "VSwgdGhlXG4jIHNhbWUgUjUxNSB3YXJuaW5nIGdhdGUgKHBlci1UVSBzdGRlcnIgbWVyZ2VkIGlu"
    "dG8gdGhlIHdhcm5maWxlXG4jIGluIGZpbGUgb3JkZXIgYWZ0ZXIgdGhlIHBvb2wgZHJhaW5zKSwg"
    "dGhlIHNhbWUgZnJlc2gtYmluYXJ5XG4jIGNoYWluIGFuZCByZWd0ZXN0LWV4aXQgYXV0aG9yaXR5"
    "IC0gYSBmYWlsZWQgVFUgc3RpbGwgbmFtZXMgaXRzXG4jIGZpbGUgKEJVSUxEIEZBSUwpLiBTdGVw"
    "IDIgc3RheXMgdGhlIHJvdW5kJ3MgY29tcGlsZSBvcmFjbGU7XG4jIHRoZSBiYXR0ZXJ5IHJ1biBp"
    "dHNlbGYgZ2FpbnMgdGhlIFIxMDYwIHNoYXJlZC1sdWFfU3RhdGVcbiMgcmVnaXN0cmllcyAoaXRl"
    "bXMvLCBkbS8sIG1vbnN0ZXJzLyAtIG9uZSBWTSBwZXIgbG9hZERpcmVjdG9yeVxuIyBpbnN0ZWFk"
    "IG9mIHBlciBmaWxlKS5cbiJdLCBbIiMgLVdzdHJpbmctY29tcGFyZSBmaXhlcyksIHNvIEFOWSB3"
    "YXJuaW5nIG5vdyBlbmRzIFJFRC5cbiIsICIjIC1Xc3RyaW5nLWNvbXBhcmUgZml4ZXMpLCBzbyBB"
    "Tlkgd2FybmluZyBub3cgZW5kcyBSRUQuXG4jIFIxMDYwOiB0aGUgb25lLXNob3QgMjgtVFUgZysr"
    "IGNvbXBpbGUgaXMgbm93IHBlci1UVSBvYmplY3RcbiMgY29tcGlsZXMgaW4gYSBqb2IgcG9vbCBw"
    "bHVzIG9uZSBsaW5rLiBUaGUgcG9vbCBpcyBjYXBwZWQgYXRcbiMgbWluKG5wcm9jLCA0KSAtIG9u"
    "ZSBnKysgcGVyIHBob25lIGNvcmUgaXMgYW4gT09NIHJpc2ssIGFuZCB0aGVcbiMgcmVndGVzdC5j"
    "cHAgbWVnYS1UVSBkb21pbmF0ZXMgdGhlIHdhbGwgY2xvY2sgYW55d2F5LiBQZXItVFVcbiMgc3Rk"
    "ZXJyIGlzIG1lcmdlZCBpbnRvICR3YXJuZmlsZSBpbiBmaWxlIG9yZGVyIGFmdGVyIHRoZSBwb29s"
    "XG4jIGRyYWlucyAobm8gY29uY3VycmVudC1hcHBlbmQgcmFjZXMpLCBhIGZhaWxlZCBUVSBzdGls"
    "bCBuYW1lc1xuIyBpdHMgZmlsZSAoQlVJTEQgRkFJTCksIGFuZCB0aGUgZnJlc2gtYmluYXJ5IGNo"
    "YWluIGlzIGtlcHQ6IGFcbiMgZmFpbGVkIGNvbXBpbGUgb3IgbGluayBuZXZlciBydW5zIHJlZ3Rl"
    "c3QuXG4iXSwgWyJpZiBnKysgLXN0ZD1jKysxNyAtSS4gLUlcIiRQUkVGSVgvaW5jbHVkZS9sdWE1"
    "LjRcIiBcXFxuICBydWxlcy9lbmdpbmUvZGljZS5jcHAgcnVsZXMvZW5naW5lL2NoYXJhY3Rlci5j"
    "cHAgcnVsZXMvZW5naW5lL2NsYXNzZXMuY3BwIHJ1bGVzL2VuZ2luZS9jb21iYXQuY3BwIFxcXG4g"
    "IHJ1bGVzL2VuZ2luZS9zYXZlcy5jcHAgcnVsZXMvZW5naW5lL3R1cm4uY3BwIHJ1bGVzL2VuZ2lu"
    "ZS9yYWNlcy5jcHAgXFxcbiAgZG0vZG0uY3BwIGRtL2R1bmdlb24uY3BwIGRtL2VuY291bnRlcnMu"
    "Y3BwIFxcXG4gIGRtL0VuY291bnRlclRhYmxlUmVnaXN0cnkuY3BwIGRtL3RyZWFzdXJlLmNwcCBt"
    "b25zdGVycy9Nb25zdGVyUmVnaXN0cnkuY3BwIHNwZWxscy9zcGVsbHMuY3BwIFxcXG4gIGFiaWxp"
    "dGllcy9hYmlsaXRpZXMuY3BwIGl0ZW1zL2l0ZW1zLmNwcCBpdGVtcy9NaXNjSXRlbVJlZ2lzdHJ5"
    "LmNwcCBhaS9hY3Rvci5jcHAgXFxcbiAgZ2FtZS9zdGF0ZV9jb3JlLmNwcCBnYW1lL3N0YXRlX2R1"
    "bmdlb24uY3BwIFxcXG4gIGdhbWUvc3RhdGVfY29tYmF0LmNwcCBnYW1lL3N0YXRlX3Rvd24uY3Bw"
    "IFxcXG4gIGdhbWUvc3RhdGVfb3ZlcmxhbmQuY3BwIGdhbWUvc3RhdGVfc2VhLmNwcCBcXFxuICBt"
    "b25zdGVycy9Nb25zdGVyWHAuY3BwIFxcXG4gIHNwZWxsZWZmZWN0cy9zcGVsbGVmZmVjdHMuY3Bw"
    "IHJlZ3Rlc3QuY3BwIFxcXG4gIC1vIHJlZ3Rlc3QgLUxcIiRQUkVGSVgvbGliXCIgLWxsdWE1LjQg"
    "Mj5cIiR3YXJuZmlsZVwiIFxcXG4gICYmIC4vcmVndGVzdCB8IHRlZSBcIiRiYXRmaWxlXCIgfCBn"
    "cmVwIC12ICdhdWRpdDogYmFkIDAkJzsgdGhlblxuIiwgIm9iamRpcj0kKG1rdGVtcCAtZClcbiMg"
    "UjEwNjA6IHRoZSBwb29sIHNpemUgLSBtaW4obnByb2MsIDQpLCBuZXZlciBiZWxvdyAxLlxuam9i"
    "cz0kKG5wcm9jIDI+L2Rldi9udWxsIHx8IGVjaG8gMSlcbmNhc2UgXCIkam9ic1wiIGluICcnfCpb"
    "ITAtOV0qKSBqb2JzPTEgOzsgZXNhY1xuWyBcIiRqb2JzXCIgLWd0IDQgXSAmJiBqb2JzPTRcblsg"
    "XCIkam9ic1wiIC1sdCAxIF0gJiYgam9icz0xXG5idWlsZF90dXM9XCJydWxlcy9lbmdpbmUvZGlj"
    "ZS5jcHAgcnVsZXMvZW5naW5lL2NoYXJhY3Rlci5jcHAgcnVsZXMvZW5naW5lL2NsYXNzZXMuY3Bw"
    "IHJ1bGVzL2VuZ2luZS9jb21iYXQuY3BwIFxcXG5ydWxlcy9lbmdpbmUvc2F2ZXMuY3BwIHJ1bGVz"
    "L2VuZ2luZS90dXJuLmNwcCBydWxlcy9lbmdpbmUvcmFjZXMuY3BwIFxcXG5kbS9kbS5jcHAgZG0v"
    "ZHVuZ2Vvbi5jcHAgZG0vZW5jb3VudGVycy5jcHAgXFxcbmRtL0VuY291bnRlclRhYmxlUmVnaXN0"
    "cnkuY3BwIGRtL3RyZWFzdXJlLmNwcCBtb25zdGVycy9Nb25zdGVyUmVnaXN0cnkuY3BwIHNwZWxs"
    "cy9zcGVsbHMuY3BwIFxcXG5hYmlsaXRpZXMvYWJpbGl0aWVzLmNwcCBpdGVtcy9pdGVtcy5jcHAg"
    "aXRlbXMvTWlzY0l0ZW1SZWdpc3RyeS5jcHAgYWkvYWN0b3IuY3BwIFxcXG5nYW1lL3N0YXRlX2Nv"
    "cmUuY3BwIGdhbWUvc3RhdGVfZHVuZ2Vvbi5jcHAgXFxcbmdhbWUvc3RhdGVfY29tYmF0LmNwcCBn"
    "YW1lL3N0YXRlX3Rvd24uY3BwIFxcXG5nYW1lL3N0YXRlX292ZXJsYW5kLmNwcCBnYW1lL3N0YXRl"
    "X3NlYS5jcHAgXFxcbm1vbnN0ZXJzL01vbnN0ZXJYcC5jcHAgXFxcbnNwZWxsZWZmZWN0cy9zcGVs"
    "bGVmZmVjdHMuY3BwIHJlZ3Rlc3QuY3BwXCJcbmJ1aWxkX2ZhaWw9MFxudHVfbj0wXG50dV9ydW5u"
    "aW5nPTBcbmZvciBmIGluICRidWlsZF90dXM7IGRvXG4gIHR1X249JCgodHVfbiArIDEpKVxuICAj"
    "IFIxMDYwOiBob2xkIGF0IHRoZSBwb29sIGNhcDsgd2FpdCAtbiByZWFwcyBvbmUgZmluaXNoZWQg"
    "am9iLlxuICBpZiBbIFwiJHR1X3J1bm5pbmdcIiAtZ2UgXCIkam9ic1wiIF07IHRoZW5cbiAgICB3"
    "YWl0IC1uXG4gICAgdHVfcnVubmluZz0kKCh0dV9ydW5uaW5nIC0gMSkpXG4gIGZpXG4gIGcrKyAt"
    "c3RkPWMrKzE3IC1JLiAtSVwiJFBSRUZJWC9pbmNsdWRlL2x1YTUuNFwiIC1jIFwiJGZcIiBcXFxu"
    "ICAgICAgLW8gXCIkb2JqZGlyL3R1JHR1X24ub1wiIDI+XCIkb2JqZGlyL3R1JHR1X24uZXJyXCIg"
    "fHwgXFxcbiAgICAgIGVjaG8gXCIkZlwiID4gXCIkb2JqZGlyL3R1JHR1X24uZmFpbGVkXCIgJlxu"
    "ICB0dV9ydW5uaW5nPSQoKHR1X3J1bm5pbmcgKyAxKSlcbmRvbmVcbndhaXRcbnR1X249MFxuZm9y"
    "IGYgaW4gJGJ1aWxkX3R1czsgZG9cbiAgdHVfbj0kKCh0dV9uICsgMSkpXG4gIGNhdCBcIiRvYmpk"
    "aXIvdHUkdHVfbi5lcnJcIiA+PiBcIiR3YXJuZmlsZVwiXG4gIGlmIFsgLWYgXCIkb2JqZGlyL3R1"
    "JHR1X24uZmFpbGVkXCIgXTsgdGhlblxuICAgIGVjaG8gXCJCVUlMRCBGQUlMOiAkZlwiXG4gICAg"
    "YnVpbGRfZmFpbD0xXG4gIGZpXG5kb25lXG5pZiBbIFwiJGJ1aWxkX2ZhaWxcIiA9IDAgXSAmJiBc"
    "XFxuICAgZysrIFwiJG9iamRpclwiL3R1Ki5vIC1vIHJlZ3Rlc3QgLUxcIiRQUkVGSVgvbGliXCIg"
    "LWxsdWE1LjQgXFxcbiAgICAgICAyPj5cIiR3YXJuZmlsZVwiOyB0aGVuXG4gIC4vcmVndGVzdCB8"
    "IHRlZSBcIiRiYXRmaWxlXCIgfCBncmVwIC12ICdhdWRpdDogYmFkIDAkJ1xuIl0sIFsicm0gLWYg"
    "XCIkd2FybmZpbGVcIlxuIiwgInJtIC1mIFwiJHdhcm5maWxlXCJcbnJtIC1yZiBcIiRvYmpkaXJc"
    "IlxuIl1dfX0="
))

def md5(s):
    return hashlib.md5(s.encode()).hexdigest()

def main():
    here = os.path.dirname(os.path.abspath(__file__))
    if os.path.basename(here) != "tools":
        sys.exit("R1060 PATCH DIE: run me as tools/r1060_patch.py "
                 "(this file must live in tools/ of the Adnd1 repo)")
    root = os.path.dirname(here)
    state = {}
    contents = {}
    for rel, s in SPEC.items():
        path = os.path.join(root, rel)
        if not os.path.isfile(path):
            sys.exit("R1060 PATCH DIE: " + rel + " is missing - "
                     "run from the Adnd1 repo root")
        with open(path) as fh:
            src = fh.read()
        contents[rel] = src
        m = md5(src)
        if m == s["md5_golden"]:
            state[rel] = "applied"
        elif m == s["md5_pristine"]:
            state[rel] = "pristine"
        else:
            if "R1060" in src:
                sys.exit("R1060 PATCH DIE: " + rel + " is in a MIXED "
                         "state (R1060 marks present, md5 " + m
                         + " matches neither pristine " + s["md5_pristine"]
                         + " nor patched " + s["md5_golden"] + "). "
                         "Remedy: git checkout -- " + rel
                         + " (if not meant to be patched) or re-fetch "
                         "pristine ded07fff and inspect by hand.")
            sys.exit("R1060 PATCH DIE: " + rel + " has DRIFTED (md5 "
                     + m + ", expected pristine " + s["md5_pristine"]
                     + "). Remedy: git checkout -- " + rel
                     + " and rerun; the patch needs the ded07fff "
                     "state of this file.")
    todo = [r for r, st in state.items() if st == "pristine"]
    done = [r for r, st in state.items() if st == "applied"]
    if todo and done:
        sys.exit("R1060 PATCH DIE: mixed splice state - patched: "
                 + ", ".join(sorted(done)) + " / pristine: "
                 + ", ".join(sorted(todo))
                 + ". Remedy: make the tree uniformly one or the "
                   "other (git checkout -- <file> to revert a patched "
                   "one), then rerun.")
    if not todo:
        print("R1060 PATCH: already applied, 0 files changed "
              "(all %d files verified at their patched md5)"
              % len(SPEC))
        return
    # dry-run EVERY pair of EVERY file in memory first: sequential
    # replacement (each pair is proven unique against the text as
    # mutated by the earlier pairs), nothing written until all md5s
    # verify
    finals = {}
    npairs = 0
    for rel in todo:
        src = contents[rel]
        for i, (old, new) in enumerate(SPEC[rel]["pairs"]):
            n = src.count(old)
            if n != 1:
                sys.exit("R1060 PATCH DIE: pair %d of %s does not match "
                         "exactly once (count %d) - the file is not the "
                         "ded07fff pristine. Remedy: git checkout -- %s"
                         % (i + 1, rel, n, rel))
            src = src.replace(old, new, 1)
            npairs += 1
        got = md5(src)
        if got != SPEC[rel]["md5_golden"]:
            sys.exit("R1060 PATCH DIE: post-verify md5 mismatch for "
                     + rel + " (" + got + ") - nothing was written; "
                     "inspect the file.")
        finals[rel] = src
    # all verified: write
    for rel in todo:
        with open(os.path.join(root, rel), "w") as fh:
            fh.write(finals[rel])
        print("patched: " + rel + " (%d pairs)"
              % len(SPEC[rel]["pairs"]))
    print("R1060 PATCH OK: %d files, %d pairs applied "
          "(regtest.cpp untouched - census stays 1127). "
          "Now run: ./tools/preflight.sh > ~/pf.txt 2>&1 && tail ~/pf.txt"
          % (len(todo), npairs))

main()
