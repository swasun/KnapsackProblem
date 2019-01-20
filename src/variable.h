#ifndef VARIABLE_H
#define VARIABLE_H

#include "object.h"
#include "node.h"

#include <stdio.h>

typedef struct {
    object *obj;
    node *n;
} variable;

variable *variable_create(object *obj, node *n);

void variable_destroy(variable *var);

void variable_print(variable *var, FILE *fd);

#endif
