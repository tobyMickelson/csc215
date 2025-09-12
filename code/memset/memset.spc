# memset: dylan, toby, 2025
# instruction: STAX

# hand generated from assembled code; may not be up to date

c3 # JMP start
08
00

### VARS:
43 # label: start_address
00
2c # label: length
01
ab # label: value_to_write

### CODE:
# label: start
2a # load start_address to HL
03
00
eb # switch start_address from HL to DE
2a # load length to HL
05
00
3a # load value_to_write to A
07
00
47 # move value_to_write to B
# label: loop
78 # move value_to_write to A
12 # store value_to_write to the memory address in DE
13 # incriment register pair DE
2b # decriment register pair HL
47 # move value_to_write to B
7c # move high byte of length to A
b5 # bitwise or low byte of length (sets the zero bit if both are zero because decriment register pair does not)
c2 # jump to loop if the length (remaining byte to write at this point) is not zero
13
00
76 # halt if the correct number of bytes has been written

===

03:43 # start_address
04:00
05:2c # length
06:01
07:ab # value_to_write
