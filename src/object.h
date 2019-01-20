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

#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>

typedef struct {
    int weight, value;
} object;

/**
 * Load a list of objects with a maximal capacity specified, from a file.
 * The format is the following:
 * * * * * * * * * *
 * maximal_weight   *
 * weight_1 value_1 *
 *        ...       *
 * weight_n value_n *
 * * * * * * * * * *
 */
object *objects_load_from_file(char *file_name, int *objects_number, int *max_weight);

/**
 * Compute the ratio value/weight of an object.
 */
double object_compute_ratio(object obj);

void object_print(object *obj, FILE *fd);

/**
 * Print the values of the object list.
 */
void objects_print(object *objects, int objects_number, FILE *fd);

/**
 * Sort the list of objects specified in parameters using
 * the Quicksort algorithm, using a value/weight comparaison
 * function.
 * The list is sorted in decending order.
 *
 * Inspired from: https://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C
 *
 */
void objects_quicksort_by_desc_ratio(object *objects, int objects_number);

#endif
