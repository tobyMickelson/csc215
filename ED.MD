# ED

## "Turorial"

For all occurrences of `n` (except for the lowercase version of the `N` command), it repersents any number from -65535 to 65535. Positive means forwards and negative means backwards.

If file is a text file, convert `\n` to `\r\n` (on MacBooks):<br>
`perl -pe 's/\n/\r\n/g' lf.ext > crlf.ext`

Load file to CP/M disk:<br>
`A:R FILENAME.EXT`

Opening the file:<br>
`A:ED FILENAME.EXT`

Enabling file numbers (***V***erify):<br>
`V`

***A***ppend (load) file to buffer:<br>
`0A`

***T***ype (print) entire buffer:<br>
`#T`

Move down ***L***ines:<br>
`nL` or `n`

Move forward ***C***haracters:<br>
`nC`

***i***nsert text case-sensitive:<br>
`i<text to insert>^z`

***D***elete characters:<br>
`nD`

Save and ***E***xit:<br>
`E`

***Q***uit without save:<br>
`Q` then `Y`

## List of Commands

| Character     | Context              | Usage                                                                                   |
|---------------|----------------------|-----------------------------------------------------------------------------------------|
| `0`           | `0`                  | For `A` at least, repersents half the buffer                                            |
| `#`           | `#`                  | Repersents the number `65535`                                                           |
| `^L`          | `^L`                 | Repersents a `<cr><lf>` for strings                                                     |
| `^Z`          | `^Z`                 | End of string                                                                           |
| `^U` and `^X` | `^U` or `^X`         | Clears the current console line                                                         |
| `A`           | `nA`                 | ***A***ppend the next `n` lines of the source file to the memory buffer                 |
| `B`           | `[-]B`               | Jump to top of ***B***uffer, bottom of `-` if provided                                  |
| `C`           | `nC`                 | Move forward `n` ***C***haracters                                                       |
| `D`           | `nD`                 | ***D***elete the next `n` characters                                                    |
| `E`           | `E`                  | Save and ***E***xit                                                                     |
| `F`           | `nF<string>`         | ***F***ind the `n`th occurrence of the string                                           |
| `H`           | `H`                  | Close and reopen file (***H***ead)                                                      |
| `I`           | `I<string>`          | ***I***nsert string                                                                     |
| `J`           | ``                   |                                                                                         |
| `K`           | `nK`                 | ***K***ill (delete) next `n` lines                                                      |
| `L`           | `nL` or `n`          | Move down `n` ***L***ines                                                               |
| `M`           | `nM<command(s)>`     | ***M***acro (repeat) commands `n` times                                                 |
| `N`           | `nN`                 | ***N***ext (or `n`th) occurrence of autoscan                                            |
| `O`           | `O` `<Y\|N>`         | Return to ***O***riginal file                                                           |
| `P`           | `nP`                 | Move and ***P***rint the next `n` ***P***ages                                           |
| `Q`           | `Q` `<Y\|N>`         | ***Q***uit without saving                                                               |
| `R`           | ``                   |                                                                                         |
| `S`           | `nS<string><string>` | ***S***ubstitute the next `n` occurrences of first string with second string            |
| `T`           | `nT`                 | ***T***ype the next `n` lines                                                           |
| `U`           | `[-]U`               |                                                                                         |
| `V`           | `[-\|0]V`            | Enable or disable if `-` line number ***V***erify; if `0` shows free/total buffer stats |
| `W`           | `nW`                 | ***W***rite the `n` lines of buffer to file                                             |
| `Z`           | `nZ`                 | Sleep (?***Z***leep?) `n` (supposed) seconds                                            |
<!-- `X` has no definition despite not returning an error -->

For the commands that handle input (`A`, `F`, `I`, `J`, `M`, `R`, `S`), the uppercase version of the command translates all
characters to uppercase and the lowercase version keeps the case of the provided input
