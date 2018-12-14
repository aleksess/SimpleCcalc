#include "Calc.h"
#include <stdlib.h>
ROOT* initOp(char c, ROOT* l, ROOT* r)
{
    ROOT* root=malloc(sizeof(ROOT));
    root->op=c;
    root->left=l;
    root->right=r;
    return root;
}

ROOT* initNum(double x)
{
    ROOT* root=malloc(sizeof(ROOT));
    root->number=x;
    root->left=root->right=NULL;
}
void consolidate(ROOT* root)
{
    if (root->left==NULL && root->right==NULL) //root is number
        return;
    else    //root is operator
    {
        consolidate(root->left);
        consolidate(root->right);
        switch(root->op)
        {
            case '+':
            root->number=root->left->number+root->right->number;
            break;
            case '-':
            root->number=root->left->number-root->right->number;
            break;
            case '*':
            root->number=root->left->number*root->right->number;
            break;
            case '/':
            if (root->right->number!=0)
                root->number=root->left->number/root->right->number;
            break;
        }
        free(root->left);
        root->left=NULL;
        free(root->right);
        root->right=NULL;
        return;
    }
}