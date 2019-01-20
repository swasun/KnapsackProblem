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
