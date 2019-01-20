#include "variable.h"

#include <stdlib.h>
#include <string.h>

variable *variable_create(object *obj, node *n) {
    variable *var;

    var = (variable *)malloc(sizeof(variable));
    var->obj = (object *)malloc(sizeof(object));
    memcpy(var->obj, obj, sizeof(object));
    var->n = node_copy(n);

    return var;
}

void variable_destroy(variable *var) {
    if (var) {
        if (var->obj) {
            free((void *)var->obj);
        }
        if (var->n) {
            free((void *)var->n);
        }
        free((void *)var);
    }
}

void variable_print(variable *var, FILE *fd) {
    if (var) {
        node_print(var->n, fd);
        fprintf(fd, "\n");
        object_print(var->obj, fd);
        fprintf(fd, "\n");
    }
}
