#ifndef SOLUTION_H
#define SOLUTION_H

#include "object.h"
#include "node.h"
#include "variable.h"

#include <stdio.h>

typedef struct {
    variable **variables;
    int variables_number;
    int optimum;
} solution;

solution *solution_create();

void solution_destroy(solution *sol);

void solution_add(solution *sol, object *obj, node *n);

void solution_print(solution *sol, FILE *fd);

#endif
