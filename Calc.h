#ifndef CALC_H
#define CALC_H
#include <stddef.h>
typedef struct ROOT
{
    struct ROOT* left;
    struct ROOT* right;
    union
    {
        char op;
        double number;
    };
}ROOT;
ROOT* initOp(char c, ROOT* l, ROOT* r);
ROOT* initNum(double x);
void consolidate(ROOT* r);




#endif