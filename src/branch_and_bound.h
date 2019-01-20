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

#ifndef BRANCH_AND_BOUND_H
#define BRANCH_AND_BOUND_H

#include "object.h"
#include "solution.h"

/**
 * Algorithm of branch and bound.
 * 
 * Use a queue that contains three nodes and compute the upper bound.
 * At each iteration, it test the branch of the next node, got with
 * the queue_front() function, and deleted directly with the queue_pop()
 * function.
 * It compute new interesting branches with the internal bound() function
 * (deleted at the beginning of the while() loop).
 */
solution *branch_and_bound(object *objects, int objects_number, int max_weight);

#endif
