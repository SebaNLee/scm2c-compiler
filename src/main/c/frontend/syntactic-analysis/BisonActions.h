#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../support/logging/Logger.h"
#include "../../support/type/CompilerState.h"
#include "../../support/type/ModuleDestructor.h"
#include "../../support/type/TokenLabel.h"
#include "AbstractSyntaxTree.h"
#include "BisonParser.h"
#include <stdlib.h>

/** Initialize module's internal state. */
ModuleDestructor initializeBisonActionsModule();

/**
 * Bison semantic actions.
 */

Instruction * IncInstructionSemanticAction(int reg);
Instruction * ClrInstructionSemanticAction(int reg);
Instruction * JeInstructionSemanticAction(int reg1, int reg2, int target);
Instruction * PrintInstructionSemanticAction(int reg);
Program * ProgramSemanticAction(Instruction * instruction);

#endif
