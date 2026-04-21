#include "BisonActions.h"

/* MODULE INTERNAL STATE */

static CompilerState * _compilerState = NULL;
static Logger * _logger = NULL;

/** Shutdown module's internal state. */
void _shutdownBisonActionsModule() {
	if (_logger != NULL) {
		logDebugging(_logger, "Destroying module: BisonActions...");
		destroyLogger(_logger);
		_logger = NULL;
	}
	_compilerState = NULL;
}

ModuleDestructor initializeBisonActionsModule(CompilerState * compilerState) {
	_compilerState = compilerState;
	_logger = createLogger("BisonActions");
	return _shutdownBisonActionsModule;
}

/* IMPORTED FUNCTIONS */

/* PRIVATE FUNCTIONS */

static void _logSyntacticAnalyzerAction(const char * functionName);

/**
 * Logs a syntactic-analyzer action in DEBUGGING level.
 */
static void _logSyntacticAnalyzerAction(const char * functionName) {
	logDebugging(_logger, "%s", functionName);
}

/* PUBLIC FUNCTIONS */

Instruction * IncInstructionSemanticAction(int reg) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Instruction * instruction = malloc(sizeof(Instruction));
	instruction->type = INC;
	instruction->inc.reg = reg;
	instruction->next = NULL; // instruction->next is managed by BisonGrammar.y
	return instruction;
}

Instruction * ClrInstructionSemanticAction(int reg) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Instruction * instruction = malloc(sizeof(Instruction));
	instruction->type = CLR;
	instruction->clr.reg = reg;
	instruction->next = NULL; // instruction->next is managed by BisonGrammar.y
	return instruction;
}

Instruction * JeInstructionSemanticAction(int reg1, int reg2, int target) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Instruction * instruction = malloc(sizeof(Instruction));
	instruction->type = JE;
	instruction->je.reg1 = reg1;
	instruction->je.reg2 = reg2;
	instruction->je.target = target;
	instruction->next = NULL; // instruction->next is managed by BisonGrammar.y
	return instruction;
}

Instruction * PrintInstructionSemanticAction(int reg) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Instruction * instruction = malloc(sizeof(Instruction));
	instruction->type = PRINT;
	instruction->print.reg = reg;
	instruction->next = NULL; // instruction->next is managed by BisonGrammar.y
	return instruction;
}

Program * ProgramSemanticAction(Instruction * instruction) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Program * program = calloc(1, sizeof(Program));
	program->first = instruction;
	_compilerState->abstractSyntaxtTree = program;
	return program;
}
