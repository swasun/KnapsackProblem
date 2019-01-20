/*******************************************************************************
 * Copyright (C) 2019 Charly Lamothe                                           *
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
