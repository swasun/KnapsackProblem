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

#include "object.h"
#include "utils.h"

#include <errno.h>
#include <stdlib.h>

object *objects_load_from_file(char *file_name, int *objects_number, int *max_weight) {
    FILE *input_file;
    char line[MAX_LINE];
    int i, weight, value;
    object *objects;

    input_file = NULL;
    *objects_number = 0;
    *max_weight = 0;
    i = 0;
    weight = 0;
    value = 0;
    objects = NULL;

    if (!(input_file = fopen(file_name, "r"))) {
        perror("input_file");
        return NULL;
    }

    *objects_number = get_lines_number(input_file) - 1;

    fgets(line, MAX_LINE, input_file);
    sscanf(line, "%d\n", max_weight);

    objects = (object *)malloc(*objects_number * sizeof(object));

    while (fgets(line, MAX_LINE, input_file)) {
        sscanf(line, "%d %d\n", &weight, &value);
        objects[i].weight = weight;
        objects[i].value = value;
        i++;
    }

    fclose(input_file);

    return objects;
}

double object_compute_ratio(object obj) {
    return (double)obj.value / obj.weight;
}

void object_print(object *obj, FILE *fd) {
    fprintf(fd, "object : weight:%d value:%d ratio:%lf", obj->weight, obj->value, object_compute_ratio(*obj));
}

void objects_print(object *objects, int objects_number, FILE *fd) {
    int i;

    for (i = 0; i < objects_number; i++) {
        object_print(&objects[i], fd);
        fprintf(fd, "\n");
    }
}

void objects_quicksort_by_desc_ratio(object *objects, int objects_number) {
    int i, j, temp_value, temp_weight;
    double pivot;

    if (objects_number < 2) {
        return;
    }

    pivot = object_compute_ratio(objects[objects_number / 2]);

    for (i = 0, j = objects_number - 1; ; i++, j--) {
        while (object_compute_ratio(objects[i]) > pivot) {
            i++;
        }
        while (object_compute_ratio(objects[j]) < pivot) {
            j--;
        }

        if (i >= j) {
            break;
        }

        temp_value = objects[i].value;
        temp_weight = objects[i].weight;
        objects[i].value = objects[j].value;
        objects[i].weight = objects[j].weight;
        objects[j].value = temp_value;
        objects[j].weight = temp_weight;
    }

    objects_quicksort_by_desc_ratio(objects, i);
    objects_quicksort_by_desc_ratio(objects + i, objects_number - i);
}
