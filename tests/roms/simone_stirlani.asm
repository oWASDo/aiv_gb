SECTION "MAIN", ROM0[$100]


ld hl, $0016
ld [hl+], a
INC HL
INC H
DEC H
LD H, $05
DAA
ADD HL,HL
LD A,[HL+]
DEC HL
INC L
DEC L
LD L, $08
CPL
JR Z, jump2
jr nc, jump
jump:
jump2:

halt