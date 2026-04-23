# Flex-Bison-Compiler

A base compiler example, developed with Flex and Bison.

* [Requirements](#requirements)
* [Configuration](#configuration)
* [Commands](#commands)
* [CI/CD](#cicd)
* [Recommended Extensions](#recommended-extensions)

## Requirements

* [Docker v28.3.2](https://www.docker.com/)

## Configuration

Set the following environment variables to control and configure the behaviour of the application:

| Name                  | Default | Description                                                                                                                                                           |
| :-------------------- | :-----: | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `ENVIRONMENT`         | `Local` | The active environment name. The available environments are: `Local`, `Development` and `Production`.                                                                 |
| `LOG_IGNORED_LEXEMES` | `true`  | When `true`, logs all of the ignored lexemes found with Flex at `DEBUGGING` level. To remove those logs from the console output set it to `false`.                    |
| `LOGGING_LEVEL`       | `ALL`   | The minimum level to log in the console output. From lower to higher, the available levels are: `ALL`, `DEBUGGING`, `INFORMATION`, `WARNING`, `ERROR` and `CRITICAL`. |

_Docker Compose_ can read the variables from an `.env` file too (see `compose.yaml` file).

## Commands

### Start

Rises an ephemeral container, ready to start development:

```bash
docker compose run --rm compiler
```

### Build

Builds or rebuilds the entire compiler:

```bash
src/main/bash/build.sh
```

### Run

Compiles a program:

```bash
src/main/bash/run.sh <program>
```

where `<program>` is the path to the file that represents its entry-point.

### Test

Executes every available unit-test under `src/test/c` folder:

```bash
src/main/bash/test.sh
```

### Stop

Logout, destroy the ephemeral containers and shutdowns the cluster:

```bash
exit
docker compose down
```

### Docker

| Command                                 | Description                                             |
| :-------------------------------------- | :------------------------------------------------------ |
| `docker builder prune --all`            | Removes all builds and complete build cache.            |
| `docker compose --progress=plain build` | Forces a build or rebuild of the images in the cluster. |
| `docker image prune`                    | Removes all of the dangling images from Docker.         |
| `docker network prune`                  | Removes unused networks from Docker.                    |
| `docker volume prune`                   | Removes unused volumes from Docker.                     |

## CI/CD

To trigger an automatic integration on every push or PR (_Pull Request_), you must activate _GitHub Actions_ in the _Settings_ tab. Use the following configuration:

| Key                                                        | Value                                               |
| :--------------------------------------------------------- | :-------------------------------------------------- |
| `Actions permissions`                                      | `Allow all actions and reusable workflows`          |
| `Allow GitHub Actions to create and approve pull requests` | `false`                                             |
| `Artifact and log retention`                               | `30 days`                                           |
| `Fork pull request workflows from outside collaborators`   | `Require approval for all outside collaborators`    |
| `Workflow permissions`                                     | `Read repository contents and packages permissions` |

## Recommended Extensions

* [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
* [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
* [Yash](https://marketplace.visualstudio.com/items?itemName=daohong-emilio.yash)





# Successor Counter Machine to C Compiler

A simple compiler from a Successor Counter Machine model (CLR, INC, JE) to C, implemented in C using Flex/Bison. 

## What is a Successor Counter Machine?


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









## Bibliography and references

<!-- 
TODO readme

credits:
https://github.com/agustin-golmar/Flex-Bison-Compiler/tree/v2.0.0



resources:
https://gnuu.org/2009/09/18/writing-your-own-toy-compiler/

https://westes.github.io/flex/manual/
https://www.gnu.org/software/bison/manual/bison.html

https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form
https://en.wikipedia.org/wiki/Abstract_syntax_tree
https://en.wikipedia.org/wiki/Compiler

https://en.wikipedia.org/wiki/Counter_machine
https://github.com/mzahnd/apuntes-9335-logica-computacional/blob/main/anexo/Lenguaje-S.pdf



 -->

