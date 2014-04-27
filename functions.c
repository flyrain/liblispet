#include "lispet.h"
extern int x(int addr);

static lval* builtin_x(lenv* e, lval* a)
{   
    LASSERT_NUM("x", a, 1);
    LASSERT_TYPE("x", a, 0, LVAL_NUM);
 
    lval* v = lval_take(a,0); 
    v->num = x(v->num);
    return v;
}

void lenv_add_extern_fun(lenv *e){
    lenv_add_builtin(e, "x", builtin_x);
}
