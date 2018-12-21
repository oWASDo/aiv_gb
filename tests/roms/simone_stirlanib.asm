SECTION "MAIN", ROM0[$100]

cpl 
jr z, $03
jr nz, $03
inc h
inc l
finish:
halt 