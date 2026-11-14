-- encounter table def: castle_type
-- The R67 castle family (R1038 de-wire): CASTLE TABLE I, size class and type
-- (DMG Appendix C Premium reprint p.182-183, OCR-verified).
-- band = the percentile column; size = the size class token (small/medium/large); type = the printed castle type string (the artillery rows key onto it).
-- DO NOT hand-edit: tools/r1038_splice.py is the only writer.

return {
  key = "castle_type",
  rows = {
    { band = {1,10}, size = "small", type = "small shell keep" },
    { band = {11,25}, size = "small", type = "tower" },
    { band = {26,35}, size = "small", type = "moat house or friary" },
    { band = {36,45}, size = "medium", type = "large shell keep" },
    { band = {46,65}, size = "medium", type = "small walled castle with keep" },
    { band = {66,80}, size = "medium", type = "medium walled castle with keep" },
    { band = {81,88}, size = "large", type = "concentric castle" },
    { band = {89,95}, size = "large", type = "large walled castle with keep" },
    { band = {96,100}, size = "large", type = "fortress complex" },
  },
}
