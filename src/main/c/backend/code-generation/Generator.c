#include "Generator.h"

/* MODULE INTERNAL STATE */

const char _indentationCharacter = ' ';
const char _indentationSize = 4;
static Logger * _logger = NULL;

/** Shutdown module's internal state. */
void _shutdownGeneratorModule() {
	if (_logger != NULL) {
		logDebugging(_logger, "Destroying module: Generator...");
		destroyLogger(_logger);
		_logger = NULL;
	}
}

ModuleDestructor initializeGeneratorModule() {
	_logger = createLogger("Generator");
	return _shutdownGeneratorModule;
}

/** PRIVATE FUNCTIONS */

static char * _indentation(const unsigned int indentationLevel);
static void _generateEpilogue();
static int _countInstructions(Instruction * instr);
static void _generateInstruction(const unsigned int indentationLevel, Instruction * instruction, int count);
static void _generateProgram(Program * program);
static void _generatePrologue(void);
static void _output(const unsigned int indentationLevel, const char * const format, ...);

/**
 * Creates the epilogue of the generated C code.
 */
static void _generateEpilogue() {
	_output(1, "return 0;\n");
	_output(0, "}\n");
}

/**
 * Counts the total amount of instructions in the SCM program.
 */
static int _countInstructions(Instruction * instruction) {
	int count = 0;
	while (instruction != NULL) {
		count++;
		instruction = instruction->next;
	}
	return count;
}

/**
 * Generates the output of an instruction.
 */
static void _generateInstruction(const unsigned int indentationLevel, Instruction * instruction, int count) {
	switch (instruction->type) {
		case INST_INC:
			_output(indentationLevel, "r[%d]++;\n", instruction->inc.reg);
			break;
		case INST_CLR:
			_output(indentationLevel, "r[%d] = 0;\n", instruction->clr.reg);
			break;
		case INST_JE:
			if (instruction->je.target >= 0 && instruction->je.target < count)
			{
				_output(indentationLevel, "if (r[%d] == r[%d]) goto L%d;\n", instruction->je.reg1, instruction->je.reg2, instruction->je.target);
			}
			else {
				_output(indentationLevel, "if (r[%d] == r[%d]) return L%d;\n", instruction->je.reg1, instruction->je.reg2, count);
			}
			break;
		case INST_PRINT:
			_output(indentationLevel, "printf(\"%%d\\n\", r[%d]);\n", instruction->print.reg);
			break;
		default:
			logError(_logger, "The specified instruction type is unknown: %d", instruction->type);
			break;
	}
}

/**
 * Generates the output of the program.
 */
static void _generateProgram(Program * program) {
	int count = _countInstructions(program->first);
	int index = 0;
	Instruction * curr = program->first;
	while (curr != NULL) {
		_output(0, "L%d:\n", index); 
		_generateInstruction(1, curr, count);
		curr = curr->next;
		index++;
	}
}

/**
 * Creates the prologue of the generated C code.
 *
 */
static void _generatePrologue(void) {
	_output(0, "#include <stdio.h>\n\n");
	_output(0, "int main()\n");
	_output(0, "{\n");
	_output(1, "// arbitrary max register number\n");
	_output(1, "int r[1024] = {0};\n\n");
}

/**
 * Generates an indentation string for the specified level.
 */
static char * _indentation(const unsigned int level) {
	return indentation(_indentationCharacter, level, _indentationSize);
}

/**
 * Outputs a formatted string to standard output. The "fflush" instruction
 * allows to see the output even close to a failure, because it drops the
 * buffering.
 */
static void _output(const unsigned int indentationLevel, const char * const format, ...) {
	va_list arguments;
	va_start(arguments, format);
	char * indentation = _indentation(indentationLevel);
	char * effectiveFormat = concatenate(2, indentation, format);
	vfprintf(stdout, effectiveFormat, arguments);
	fflush(stdout);
	free(effectiveFormat);
	free(indentation);
	va_end(arguments);
}

/** PUBLIC FUNCTIONS */

void executeGenerator(CompilerState * compilerState) {
	logDebugging(_logger, "Generating final output...");
	_generatePrologue();
	_generateProgram(compilerState->abstractSyntaxtTree);
	_generateEpilogue();
	logDebugging(_logger, "Generation is done.");
}
