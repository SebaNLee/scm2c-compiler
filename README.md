# Successor Counter Machine to C Compiler

A simple compiler from a Successor Counter Machine model (CLR, INC, JE) to C, implemented in C using Flex/Bison. 

### What is a Successor Counter Machine?

It is a minimal computational model built on really simple register operations. Despite its instruction set, it is computationally universal. This project focuses on a subset (called *Successor Counter Machine*) of the more broader *Counter Machine* model.

*Counter Machines*, in general, emerged from the pursuit of finding the smallest possible set of instructions for universal computation, which showed that even simple operations like increment, reset, and conditional jump were more than enough to express any algorithm.

Interestingly, this highly theorical approach of *Counter Machines* has a real-world counterpart: assembly languages (such as *x86-64 NASM*). The similarity between both instruction sets is quite notable. So, rather than mere coincidence, this suggests a form of convergence: both theorical analysis and practical engineering arrive at the same small set of fundamental operations, differing only in the level of abstraction. One aimed at studying computability and the other at achieving maximum efficiency.

### Instructions

These are the available instructions of the SCM:

| Instruction                                | Specification                                                                 |
| :----------------------------------------- | :---------------------------------------------------------------------------- |
| `INC <register>`                           | Increments the value stores in the register by 1.                             |
| `CLR <register>`                           | Sets the value of the register to 0.                                          |
| `JE <register>, <register>, <instruction>` | Jumps to the specified instruction if both registers contains the same value. |
| `PRINT <register>`                         | Prints to STDOUT the stored value of the register.                            |

Where: 

- `<register>` denotes a register of the form rx, where $x \in \mathbb{N}$ (e.g., r0, r1, r2, ...).
-  `<instruction>` denotes the $i$-th instruction in the program.

> Note: If the instruction index specified in `JE` is greater than the existing instructions, the program terminates.

## Devs

#### Docker

Rises an ephemeral container, ready to start development:

```
docker compose run --rm compiler
```

Logout, destroy the ephemeral containers and shutdowns the cluster:

```
exit
docker compose down
```

#### Scripts

Builds or rebuilds the entire compiler:

```
src/main/bash/build.sh
```

Compiles SCM to C:

```
src/main/bash/run.sh <program>
```

Compiles SCM to C, then compiles C with gcc and executes the binary:

```
src/main/bash/run-and-execute.sh <program>
```

Executes every available unit-test under `src/test/scm` folder:

```
src/main/bash/test.sh
```

> Note: Some example SCM programs are provided in the `/program` directory. Ready to use with the `src/main/bash/run-and-execute.sh` script!

## Bibliography and references

#### Main references

Compiler based on Flex-Bison-Compiler by Agustín Golmar [[GitHub](https://github.com/agustin-golmar/Flex-Bison-Compiler)]

Writing Your Own Toy Compiler Using Flex, Bison and LLVM by Loren Segal [[gnuu.org](https://gnuu.org/2009/09/18/writing-your-own-toy-compiler/)]

#### Aditional references

Lexical Analysis With Flex [[docs](https://westes.github.io/flex/manual/)]

Bison Mnaul [[docs](https://www.gnu.org/software/bison/manual/bison.html)]

Counter machine [[Wikipedia](https://en.wikipedia.org/wiki/Counter_machine)]

Compiler [[Wikipedia](https://en.wikipedia.org/wiki/Compiler)]

Backus-Naur form [[Wikipedia](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form)]

Abstract syntax tree [[Wikipedia](https://en.wikipedia.org/wiki/Abstract_syntax_tree)]

Tuing Completeness [[Wikipedia](https://en.wikipedia.org/wiki/Turing_completeness)]

Lenguaje S [[GitHub](https://github.com/mzahnd/apuntes-9335-logica-computacional/blob/main/anexo/Lenguaje-S.pdf)]
