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

#ifndef NODE_H
#define NODE_H

#include <stdio.h>

/**
 * Structure that represent a node of the tree.
 */
typedef struct {
    int level, profit, bound;
    float weight;
} node;

void node_print(node *n, FILE *fd);

node *node_copy(node *n);

#endif
