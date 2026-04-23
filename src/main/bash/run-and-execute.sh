#! /bin/bash

set -euo pipefail

BASE_PATH="$(dirname "$0")/../../.."
cd "$BASE_PATH"

INPUT="$1"
shift 1
cat "$INPUT" | ".build/Flex-Bison-Compiler" "$@"

mv program/output.c "$INPUT".c

# compile C and run binary
gcc "$INPUT.c" -o "$INPUT.out" -std=c99 -pedantic

echo "C output:"

./"$INPUT.out"
rm "$INPUT.out"