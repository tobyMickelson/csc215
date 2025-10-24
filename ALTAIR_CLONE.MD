# ALTAIR 8800 CLONE USAGE

Loading CP/M and connecting to the Altair 8800 Clone does not nessicarly have
to happen in that order and vice versa

## Loading CP/M:

1. Power on the Altair 8800 Clone
2. Jump to memory address FF00h (377000o, left 8 switches on, right 8 off)
3. Run
4. When done and no command is running on the Altair 8800 Clone, the power
   switch can be flicked off; there is no shutdown procedure

## Connecting to the Altair 8800 Clone

1. In a shell, run `minicom altair`
2. To view options, press `^a` followed by `z`
3. To quit, press `^a` followed by `q`
