%{

#include "../../support/type/TokenLabel.h"
#include "AbstractSyntaxTree.h"
#include "BisonActions.h"

/**
 * The error reporting function for Bison parser.
 *
 * @todo Add location to the grammar and "pushToken" API function.
 *
 * @see https://www.gnu.org/software/bison/manual/html_node/Error-Reporting-Function.html
 * @see https://www.gnu.org/software/bison/manual/html_node/Tracking-Locations.html
 */
void yyerror(const YYLTYPE * location, const char * message) {}

%}

// You touch this, and you die.
%define api.pure full
%define api.push-pull push
%define api.value.union.name SemanticValue
%define parse.error detailed
%locations

%union {
	/** There is no separaction of Terminals and Non-terminals. */
	signed int integer;
	TokenLabel token;

	Instruction * instruction;
	Program * program;
}

/**
 * Destructors. This functions are executed after the parsing ends, so if the
 * AST must be used in the following phases of the compiler you shouldn't used
 * this approach for the AST root node ("program" non-terminal, in this
 * grammar), or it will drop the entire tree even if the parsing succeeds.
 *
 * @see https://www.gnu.org/software/bison/manual/html_node/Destructor-Decl.html
 */
%destructor { destroyInstruction($$); } <instruction>

/** There is no separaction of Terminals and Non-terminals. */
%token <integer> INTEGER
%token <integer> REGISTER
%token <token> INC
%token <token> CLR
%token <token> JE
%token <token> PRINT
%token <token> COMMA
%token <token> NEWLINE

%token <token> IGNORED
%token <token> UNKNOWN

%type <instruction> instruction
%type <program> program

/**
 * Precedence and associativity.
 *
 * @see https://en.cppreference.com/w/cpp/language/operator_precedence.html
 * @see https://www.gnu.org/software/bison/manual/html_node/Precedence.html
 */

// Note: no associativity in Succesor Counter Machines :p.

%%

// IMPORTANT: To use λ in the following grammar, use the %empty symbol.

program: instruction												{ $$ = ProgramSemanticAction($1); }
	;

instruction: INC REGISTER NEWLINE instruction						{ $$ = IncInstructionSemanticAction($2); $$->next = $4; }
	| CLR REGISTER NEWLINE instruction								{ $$ = ClrInstructionSemanticAction($2); $$->next = $4; }
	| JE REGISTER COMMA REGISTER COMMA INTEGER NEWLINE instruction	{ $$ = JeInstructionSemanticAction($2, $4, $6); $$->next = $8; }
	| PRINT REGISTER NEWLINE instruction							{ $$ = PrintInstructionSemanticAction($2); $$->next = $4; }
	| %empty														{ $$ = NULL; }
	;

%%
