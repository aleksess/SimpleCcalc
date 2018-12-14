#ifndef PARSER_H
#define PARSER_H
#include "Calc.h"
#include <stddef.h>
size_t position;
char expression[100];
ROOT* Parse_expression();
ROOT* Parse_sum();
ROOT* Parse_mult();
ROOT* Parse_term();
ROOT* Parse_value();
ROOT* Parse_paren();
void skip_whitespace();
char look_ahead();

#endif