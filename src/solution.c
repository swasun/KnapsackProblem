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

#include "solution.h"

#include <stdlib.h>

solution *solution_create() {
    solution *sol;

    sol = (solution *)malloc(sizeof(solution));
    sol->variables = NULL;
    sol->variables_number = 0;
    sol->optimum = 0;

    return sol;
}

void solution_destroy(solution *sol) {
    int i;

    if (sol) {
        if (sol->variables) {
            for (i = 0; i < sol->variables_number; i++) {
                variable_destroy(sol->variables[i]);
            }
            free((void *)sol->variables);
        }
        free((void *)sol);
    }
}

void solution_add(solution *sol, object *obj, node *n) {
    if (sol->variables) {
        sol->variables = (variable **)realloc(sol->variables, (sol->variables_number + 1) * sizeof(variable *));
    } else {
        sol->variables = (variable **)malloc(sizeof(variable *));
    }
    sol->variables[sol->variables_number] = variable_create(obj, n);
    sol->variables_number++;
}

void solution_print(solution *sol, FILE *fd) {
    int i;

    fprintf(fd, "\nThe optimum is %d.\n\n", sol->optimum);
    fprintf(fd, "Variables and nodes:\n\n");
    for (i = 0; i < sol->variables_number; i++) {
        variable_print(sol->variables[i], fd);
        fprintf(fd, "\n");
    }
    fprintf(fd, "\n");
}
