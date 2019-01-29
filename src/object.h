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
