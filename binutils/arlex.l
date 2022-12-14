%option noinput nounput noyywrap

%{
/* arlex.l - Strange script language lexer */

/* Please review: $(src-dir)/SPL-README for Licencing info. */

#define DONTDECLARE_MALLOC
#include "ansidecl.h"
#include "libiberty.h"
#include "arparse.h"

#ifndef YY_NO_UNPUT
#define YY_NO_UNPUT
#endif

extern int yylex (void);

int linenumber;
%}

%a 10000
%o 25000

%%

"ADDLIB"   	{ return ADDLIB; }
"ADDMOD"   	{ return ADDMOD; }
"CLEAR"   	{ return CLEAR; }
"CREATE"   	{ return CREATE; }
"DELETE"   	{ return DELETE; }
"DIRECTORY"   	{ return DIRECTORY; }
"END"   	{ return END; }
"EXTRACT"   	{ return EXTRACT; }
"FULLDIR"   	{ return FULLDIR; }
"HELP"   	{ return HELP; }
"LIST"		{ return LIST; }
"OPEN"   	{ return OPEN; }
"REPLACE"   	{ return REPLACE; }
"VERBOSE"   	{ return VERBOSE; }
"SAVE"   	{ return SAVE; }
"addlib"   	{ return ADDLIB; }
"addmod"   	{ return ADDMOD; }
"clear"   	{ return CLEAR; }
"create"   	{ return CREATE; }
"delete"   	{ return DELETE; }
"directory"   	{ return DIRECTORY; }
"end"   	{ return END; }
"extract"   	{ return EXTRACT; }
"fulldir"   	{ return FULLDIR; }
"help"   	{ return HELP; }
"list"		{ return LIST; }
"open"   	{ return OPEN; }
"replace"   	{ return REPLACE; }
"verbose"   	{ return VERBOSE; }
"save"   	{ return SAVE; }
"+\n"           { linenumber ++; }
"("             { return '('; }
")"             { return ')'; }
","             { return ','; }
[A-Za-z0-9/\\$:.\-\_]+  {
		yylval.name =  xstrdup (yytext);
		return FILENAME;
		}
"*".* 		{ }
";".* 		{ }
" "		{ }
"\n"	 	 { linenumber ++; return NEWLINE; }

%%
