; memset: dylan, toby, 2025
; instruction: STAX

JMP 8 ; START

ADDR: DW 43h ; start addr.
LEN: DW 12Ch ; length
VALUE: DB ABh ; value to write

START:
    LHLD ADDR ; store
    XCHG
    LHLD LEN
    LDA VALUE
    MOV B,A
LOOP:
    MOV A,B
    STAX D
    INX D
    DCX H
    MOV B,A
    MOV A,H
    ORA L
    JNZ LOOP
    HLT
