#ifndef ABSTRACT_SYNTAX_TREE_HEADER
#define ABSTRACT_SYNTAX_TREE_HEADER

#include "../../support/logging/Logger.h"
#include "../../support/type/ModuleDestructor.h"
#include <stdlib.h>

/** Initialize module's internal state. */
ModuleDestructor initializeAbstractSyntaxTreeModule();

/**
 * This type definitions allows self-referencing types (e.g., an expression
 * that is made of another expressions, such as talking about you in 3rd
 * person, but without the madness).
 */

typedef enum InstructionType InstructionType;

typedef struct Instruction Instruction;
typedef struct Program Program;

/**
 * Node types for the Abstract Syntax Tree (AST).
 * 
 * Note:
 * In this case, this would be a Degenerate Tree (a.k.a. linked list). Lol.
 * Just for pedagogic reasons will mantain the tree structure, although inefficient.
 */

enum InstructionType {
	CLR,
	INC,
	JE,
	PRINT
};

struct Instruction {
	Instruction * next;
	InstructionType type;
	union {
		struct {
			int reg;
		} clr;

		struct {
			int reg;
		} inc;

		struct {
			int reg1;
			int reg2;
			int target;
		} je;

		struct {
			int reg;
		} print;
	};
};

struct Program {
	Instruction * first;
};

/**
 * Node recursive super-duper-trambolik-destructors.
 */

void destroyInstruction(Instruction * instruction);
void destroyProgram(Program * program);

#endif
