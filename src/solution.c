/*******************************************************************************
 * Copyright (C) 2019 Charly Lamothe, Doulkifouli Abdallah-Ali                 *
 *                                                                             *
 * This file is part of KnapsackProblem.                                       *
 *                                                                             *
 *   Licensed under the Apache License, Version 2.0 (the "License");           *
 *   you may not use this file except in compliance with the License.          *
 *   You may obtain a copy of the License at                                   *
 *                                                                             *
 *   http://www.apache.org/licenses/LICENSE-2.0                                *
 *                                                                             *
 *   Unless required by applicable law or agreed to in writing, software       *
 *   distributed under the License is distributed on an "AS IS" BASIS,         *
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
 *   See the License for the specific language governing permissions and       *
 *   limitations under the License.                                            *
 *******************************************************************************/

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
