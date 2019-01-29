/*************************************************************************************
 * MIT License                                                                       *
 *                                                                                   *
 * Copyright (C) 2017 Charly Lamothe, Doulkifouli Abdallah-Ali                       *
 *                                                                                   *
 * This file is part of KnapsackProblem.                                             *
 *                                                                                   *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy    *
 *   of this software and associated documentation files (the "Software"), to deal   *
 *   in the Software without restriction, including without limitation the rights    *
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell       *
 *   copies of the Software, and to permit persons to whom the Software is           *
 *   furnished to do so, subject to the following conditions:                        *
 *                                                                                   *
 *   The above copyright notice and this permission notice shall be included in all  *
 *   copies or substantial portions of the Software.                                 *
 *                                                                                   *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
 *   SOFTWARE.                                                                       *
 *************************************************************************************/

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
