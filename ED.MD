# ED

If file is a text file, convert `\n` to `\r\n` (on MacBooks):
`perl -pe 's/\n/\r\n/g' lf.ext > crlf.ext`

Load file to CP/M disk:
`A:R FILENAME.EXT`

Opening the file:
`A:ED FILENAME.EXT`

Enabling file numbers (***V***erify):
`V`

***A***ppend (load) file to buffer:
`0A`

***T***ype (print) entire buffer:
`#T`

Move up or down ***L***ines:
`nL` or `n`
where `n` is the number of line moves down if positive and up if negative

Move forward and backward **C**haracters:
`nC`
where `n` is the number of character moves forward if positive and backward if negative

***i***nsert text case-sensitive:
`i<text to insert>^z`

***I***nsert text uppercase:
`I<text to insert>^z`

***K***ill (delete) lines:
`nK`
where `n` is the number of line moves down if positive and up if negative

Save and ***E***xit:
`E`

***Q***uit without save:
`Q` then `Y`

<-- table: to be completed eventually
| Character | Context | Usage |
|-----------|---------|-------|
| `A`       | `nA`    | Append the next `n` lines of the source file to the memory buffer |
| `B` | `+/-B` |  |
| `C` | `` |  |
| `D` | `` |  |
| `E` | `` |  |
| `F` | `` |  |
| `G` | `` |  |
| `H` | `` |  |
| `I` | `` |  |
| `J` | `` |  |
| `K` | `` |  |
| `L` | `` |  |
| `M` | `` |  |
| `N` | `` |  |
| `O` | `` |  |
| `P` | `` |  |
| `Q` | `` |  |
| `R` | `` |  |
| `S` | `` |  |
| `T` | `` |  |
| `U` | `` |  |
| `V` | `` |  |
| `W` | `nW` | Write the first `n` lines of buffer to  |
| `X` | `` |  |
| `Y` | `` |  |
| `Z` | `` |  |
| `` | `` |  |
| `` | `` |  |
| `` | `` |  |
-->
