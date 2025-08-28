# ALTAIR 8800

## PART 1: INTRODUCTION

### PART 1A: LOGIC

- George Boole created the field of Boolean algebra
- Boolean algebra consists of logic that is either true or false
- There are three basic elements, `AND`, `OR`, and `NOT`; they are respectively true when __all__ are true, when __any__ are true, or when the single input is false

---

`AND`: when __all__ are true
```
A -|----\
   | AND )- OUT
B -|----/
```

| A        | B        | OUT      |
|----------|----------|----------|
| false    | false    | false    |
| false    | __true__ | false    |
| __true__ | false    | false    |
| __true__ | __true__ | __true__ |

`OR`: when __any__ are true
```
A -\----\
    ) OR  >- OUT
B -/----/
```

| A        | B        | OUT      |
|----------|----------|----------|
| false    | false    | false    |
| false    | __true__ | __true__ |
| __true__ | false    | __true__ |
| __true__ | __true__ | __true__ |

`NOT`: when false (__invert__)
```
   |\--\
A -| NOT >- OUT
   |/--/
```

| A        | OUT      |
|----------|----------|
| false    | __true__ |
| __true__ | false    |

### PART 1B: ELECTRONIC LOGIC

- All of the previous (and future) truth tables can be created with transistors, relays, vacuum tubes (triode), or any other electronic switch not on this list
- There are three more common logic gates: `NAND`, `NOR`, and `XOR`, they are respectively an inverted `AND`, an inverted `OR`, and true when __one and only one__ input is true
- The new three, along with any other truth table, can be created using just `AND`, `OR`, and `NOT`
- These logic gates can be combined to create a flip-flop, which holds one bit of information
- `XOR` is logically `(NOT (A AND B)) AND (A OR B)`

---

`NAND`: inverted `AND`
```
A -|-----\
   | NAND )o- OUT
B -|-----/
```

| A        | B        | OUT      |
|----------|----------|----------|
| false    | false    | __true__ |
| false    | __true__ | __true__ |
| __true__ | false    | __true__ |
| __true__ | __true__ | false    |

`NOR`: inverted `OR`
```
A -\-----\
    ) NOR  >o- OUT
B -/-----/
```

| A        | B        | OUT      |
|----------|----------|----------|
| false    | false    | __true__ |
| false    | __true__ | false    |
| __true__ | false    | false    |
| __true__ | __true__ | false    |

`XOR`: when __one and only one__ input is true
```
A -\ \-----\
    ) ) XOR  >- OUT
B -/ /-----/
```

| A        | B        | OUT      |
|----------|----------|----------|
| false    | false    | false    |
| false    | __true__ | __true__ |
| __true__ | false    | __true__ |
| __true__ | __true__ | false    |
