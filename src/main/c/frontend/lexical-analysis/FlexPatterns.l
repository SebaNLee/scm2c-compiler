%top{

#include "../../support/type/CompilationStatus.h"
#include "../../support/type/FlexContext.h"
#include "../../support/type/TokenLabel.h"
#include "../syntactic-analysis/AbstractSyntaxTree.h"
#include "../syntactic-analysis/BisonParser.h"

}

%{

/**
 * @see https://westes.github.io/flex/manual/Definitions-Section.html#Definitions-Section
 */

extern CompilationStatus InstructionLexemeAction(TokenLabel label);
extern CompilationStatus RegisterLexemeAction();
extern CompilationStatus IntegerLexemeAction();
extern CompilationStatus CommaLexemeAction();
extern CompilationStatus NewlineLexemeAction()
extern CompilationStatus IgnoredLexemeAction();
extern CompilationStatus UnknownLexemeAction();
extern CompilationStatus EOFLexemeAction();

%}

/**
 * Flex contexts (a.k.a. start conditions).
 *
 * @see https://westes.github.io/flex/manual/Start-Conditions.html
 */
%x IMPORT_EXPRESSION
%x MULTILINE_COMMENT

/**
 * Reusable patterns.
 *
 * @see https://westes.github.io/flex/manual/Matching.html
 * @see https://westes.github.io/flex/manual/Patterns.html
 */
whitespace			[[:space:]]+

%%

%{

/**
 * @see https://westes.github.io/flex/manual/Rules-Section.html#Rules-Section
 */

%}

"INC"                               { return InstructionLexemeAction(INC); }
"CLR"                               { return InstructionLexemeAction(CLR); }
"JE"                                { return InstructionLexemeAction(JE); }
"PRINT"                             { return InstructionLexemeAction(PRINT); }

r[[:digit:]]+                       { return RegisterLexemeAction(); }
[[:digit:]]+                        { return IntegerLexemeAction(); }

","                                 { return CommaLexemeAction(); }
\n                                  { return NewlineLexemeAction(); }

{whitespace}						{ return IgnoredLexemeAction(); }
.									{ return UnknownLexemeAction(); }

<<EOF>>								{ return EOFLexemeAction(); }

%%

/**
 * @see https://westes.github.io/flex/manual/User-Code-Section.html#User-Code-Section
 */

#include "FlexActions.h"
#include "FlexExport.h"
