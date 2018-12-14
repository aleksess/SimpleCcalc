#include "Calc.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
extern size_t position;
extern char expression[500];
int main()
{
    fflush(stdin);
    scanf("%[^\n]s", expression);
    position=0;
    ROOT* prime=Parse_expression();
    consolidate(prime);
    printf("%lg \n", prime->number);
    free(prime);

    return 0;
}