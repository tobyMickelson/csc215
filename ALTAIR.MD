# ALTAIR 8800

## PART 1: INTRODUCTION

### PART 1A: LOGIC

- George Boole created the field of Boolean algebra
- Boolean algebra consists of logic that is either true or false
- There are three basic elements, `AND`, `OR`, and `NOT`; they are respectively true when __all__ are true, when __any__ are true, or when the single input is false

---

`AND`: when __all__ are true

| A        | B        | OUT      |
|----------|----------|----------|
| false    | false    | false    |
| false    | __true__ | false    |
| __true__ | false    | false    |
| __true__ | __true__ | __true__ |

`OR`: when __any__ are true

| A        | B        | OUT      |
|----------|----------|----------|
| false    | false    | false    |
| false    | __true__ | __true__ |
| __true__ | false    | __true__ |
| __true__ | __true__ | __true__ |

`NOT`: when false (__invert__)

| A        | OUT      |
|----------|----------|
| false    | __true__ |
| __true__ | false    |
