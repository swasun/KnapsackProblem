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
