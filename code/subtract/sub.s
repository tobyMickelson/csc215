// a - b = res

#define NUM_A $0080
#define NUM_B $0081
#define RES   $0082

LDA NUM_B
MOV B,A
LDA NUM_A
SUB B
STA RES
