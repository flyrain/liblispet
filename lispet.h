#ifndef _LISPET_H_
#define _LISPET_H_
struct lval;
struct lenv;
typedef struct lval lval;
typedef struct lenv lenv;

typedef lval* (*lbuiltin)(lenv*, lval*);

struct lval{
    int type;

    // Basic
    long num;
    char* err;
    char* sym;
    char* str;

    // Function
    lbuiltin builtin;
    lenv* env;
    lval* formals;
    lval* body;

    // Expression
    int count;
    lval ** cell;
};

struct lenv{
    lenv* par;
    int count;
    char ** syms;
    lval** vals;
};


//lval types
enum {LVAL_NUM, LVAL_ERR, LVAL_SYM, LVAL_STR, LVAL_FUN, LVAL_SEXPR, LVAL_QEXPR};


#define LASSERT(args, cond, fmt, ...) \
    if (!(cond)) {lval* err = lval_err(fmt, ##__VA_ARGS__); lval_del(args); return err;}

#define LASSERT_TYPE(func, args, index, expect) \
    LASSERT(args, args->cell[index]->type == expect,    \
        "Function '%s' passed incorrect type for argument %i. Got %s, Expected %s.", \
            func, index, ltype_name(args->cell[index]->type), ltype_name(expect)) 
        
#define LASSERT_NUM(func, args, expect)                \
    LASSERT(args, args->count == expect, \
        "Function '%s' passed incorrect number of arguments. Got %i, Expected %i.", \
            func, args->count, expect)



void lval_del(lval* v);
lval* lval_err(char * fmt, ...);
lval* lval_copy(lval* v);
lval* lval_pop(lval* v, int i);
lval* lval_take(lval* v, int i);
lval* lval_call(lenv* e, lval* f, lval*a);
char* ltype_name(int t);

void lenv_add_builtin(lenv* e, char* name, lbuiltin func);


int lispet(int need_interactive); 

#endif /* _LISPET_H_ */
