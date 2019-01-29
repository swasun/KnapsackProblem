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

#include "branch_and_bound.h"
#include "object.h"
#include "solution.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

static void print_usage(char **argv) {
    printf("Usage: %s --help | --tests | <file_name>\n", argv[0]);
}

static int test_knapsack(char *file_name, int excepted_optimum, FILE *out_fd) {
    object *objects;
    solution *sol;
    int objects_number, max_weight;
    clock_t begin_clock, end_clock;

    if (!(objects = objects_load_from_file(file_name, &objects_number, &max_weight))) {
        fprintf(out_fd, "[ERROR] The loading of the file '%s' failed.\n", file_name);
        return 0;
    }

    fprintf(out_fd, "The weight capacity of the knapsack is: %d.\n", max_weight);

    begin_clock = clock();
    sol = branch_and_bound(objects, objects_number, max_weight);
    end_clock = clock();
    fprintf(out_fd, "Execution of the algorithm in %fs.\n", (double)(end_clock - begin_clock) / CLOCKS_PER_SEC);

    free((void *)objects);

    assert(sol->optimum == excepted_optimum);

    solution_print(sol, out_fd);

    solution_destroy(sol);

    return 1;
}

static void print_success(FILE *out_fd) {
    fprintf(out_fd, "======================== [SUCCESS] ========================\n\n");
}

static void print_failure(FILE *out_fd) {
    fprintf(out_fd, "======================== [FAILURE] ========================\n\n");
}

static int test_knapsack0(FILE *out_fd) {
    fprintf(out_fd, "[TEST KNAPSACK0]\n");
    if (test_knapsack("res/knapsack0", 103, out_fd)) {
        print_success(out_fd);
        return 1;
    }

    print_failure(out_fd);
    return 0;
}

static int test_knapsack1(FILE *out_fd) {
    fprintf(out_fd, "[TEST KNAPSACK1]\n");
    if (test_knapsack("res/knapsack1", 2077672, out_fd)) {
        print_success(out_fd);
        return 1;
    }

    print_failure(out_fd);
    return 0;
}

static int test_knapsack2(FILE *out_fd) {
    fprintf(out_fd, "[TEST KNAPSACK2]\n");
    if (test_knapsack("res/knapsack2", 2095878, out_fd)) {
        print_success(out_fd);
        return 1;
    }

    print_failure(out_fd);
    return 0;
}

static int test_knapsack3(FILE *out_fd) {
    fprintf(out_fd, "[TEST KNAPSACK3]\n");
    if (test_knapsack("res/knapsack3", 2132531, out_fd)) {
        print_success(out_fd);
        return 1;
    }

    print_failure(out_fd);
    return 0;
}

static int test_knapsack4(FILE *out_fd) {
    fprintf(out_fd, "[TEST KNAPSACK4]\n");
    if (test_knapsack("res/knapsack4", 2166542, out_fd)) {
        print_success(out_fd);
        return 1;
    }

    print_failure(out_fd);
    return 0;
}

static void test_all(FILE *out_fd) {
    assert(test_knapsack0(out_fd));
    assert(test_knapsack1(out_fd));
    assert(test_knapsack2(out_fd));
    assert(test_knapsack3(out_fd));
    assert(test_knapsack4(out_fd));

    fprintf(out_fd, "All the performed tests succeed.\n");
}

void run_instance(char *file_name, char **argv, FILE *out_fd) {
    object *objects;
    solution *sol;
    int objects_number, max_weight;
    clock_t begin_clock, end_clock;

    /* The loaded file returns a list of objects and a maximal weight */
    if (!(objects = objects_load_from_file(argv[1], &objects_number, &max_weight))) {
        fprintf(stderr, "[ERROR] Failed to load data file.\n");
        print_usage(argv);
        exit(EXIT_FAILURE);
    }

    fprintf(out_fd, "The weight capacity of the knapsack is: %d.\n", max_weight);

    /* We compute the time used to compute the optimum */
    begin_clock = clock();
    sol = branch_and_bound(objects, objects_number, max_weight);
    end_clock = clock();
    fprintf(out_fd, "Execution of the algorithm in %fs.\n", (double)(end_clock - begin_clock) / CLOCKS_PER_SEC);

    solution_print(sol, out_fd);

    solution_destroy(sol);

    free((void *)objects);
}

int main(int argc, char **argv) {
    FILE *out_fd;
    int out_file;

    if (argc == 1) {
        print_usage(argv);
        exit(EXIT_FAILURE);
    }

    out_fd = NULL;
    out_file = 0;

    if (argc > 2) {
        if (!(out_fd = fopen(argv[2], "w"))) {
            fprintf(stderr, "[ERROR] The creation of the output file failed.\n");
            print_usage(argv);
            exit(EXIT_FAILURE);
        }
        out_file = 1;
    }

    if (!out_file) {
        out_fd = stdout;
    }

    if (strcmp(argv[1], "--help") == 0) {
        if (out_file) {
            fclose(out_fd);
        }
        print_usage(argv);
        exit(EXIT_SUCCESS);
    }
    /* The "tests" parameter perform tests to the algorithm, form known values */
    else if (strcmp(argv[1], "--tests") == 0) {
        test_all(out_fd);
    }
    /* Else, we select the parameter as the input file name to load */
    else {
        run_instance(argv[1], argv, out_fd);
    }

    if (out_file) {
        fclose(out_fd);
    }

    exit(EXIT_SUCCESS);
}
