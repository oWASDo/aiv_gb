SECTION "MAIN", ROM0[$100]


ld hl, $0016
halt 
;
;jp end
;INC HL
;jp end
;INC H
;jp end
;DEC H
;jp end
;LD H, $05
;jp end
;DAA
;jp end
;ADD HL,HL
;jp end
;LD A,[HL+]
;jp end
;DEC HL
;jp end
;INC L
;jp end
;DEC L
;jp end
;LD L, $08
;jp end
;CPL
;JR Z, jump2
;jr nc, jump
;jump:
;jump2:
;
