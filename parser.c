#include "parser.h"
extern char expression[100];
extern size_t position;

void skip_whitespace()
{
    while(expression[position]==' ')
        position++;   
}
char look_ahead()
{
    skip_whitespace();
    return expression[position];
}



ROOT* Parse_expression()
{
    ROOT* root=Parse_sum();
    return root;
}

ROOT* Parse_sum()
{
    ROOT* root=Parse_mult();
    char c=look_ahead();
    while (c=='+' || c=='-')
    {
        position++;
        root=initOp(c,root, Parse_mult());
        c=look_ahead();
    }
    return root;
}
ROOT* Parse_mult()
{
    ROOT* root=Parse_term();
    char c=look_ahead();
    while (c=='*' || c=='/')
    {
        position++;
        root=initOp(c, root, Parse_term());
        c=look_ahead();
    }
    return root;
}
ROOT* Parse_term()
{
    char c=look_ahead();
    if (isdigit(c))
        return Parse_value();
    else if (c=='(')
        return Parse_paren();
}
ROOT* Parse_value()
{
    ROOT* root;
    double num=0;
    while(isdigit(expression[position]))
    {
        num*=10;
        num+=expression[position]-'0';
        position++;
    }
    if (expression[position]=='.')
    {
        position++;
        double temp=0.1;
        while (isdigit(expression[position]))
        {
            num+=(temp*(expression[position]-'0'));
            temp/=10;
            position++;
        }
    }
    root=initNum(num);
    return root;
}
ROOT* Parse_paren()
{
    position++; 
    ROOT* root = Parse_sum();
    if (look_ahead() == ')')
    {
        position++;
        return root;
    }
}
