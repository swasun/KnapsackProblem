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

#include "branch_and_bound.h"
#include "queue.h"
#include "node.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Print a node of the three.
 * Specialized function for a queue.
 */
void queue_print_node(void *data) {
    node *n = (node *)data;

    node_print(n, stdout);
}

/**
 * Allocate a node in a queue.
 */
void *queue_alloc_node(void *data) {
    node *n = (node *)malloc(sizeof(node));
    memcpy(n, (node *)data, sizeof(node));
    return (void *)n;
}

/**
 * Perform the "bound" operation of the branch and bound algorithm.
 * We compute the current maximum profit and the current maximum weight
 * beginning from the specified node, then if possible, we utilise the
 * fractional method to optimize the computed profit.  
 */
int bound(object *objects, int objects_number, int max_weight, node *u) {
    int profit_bound, i, weight;

    if (u->weight >= max_weight) {
        return 0;
    }

    /* Initialize the profit of the specified node */
    profit_bound = u->profit;

    /* Initialize the tree level after the specified node */
    i = u->level + 1;

    /* Initialize the weight of the node from the specified node */
    weight = u->weight;

    /**
     * While we didn't reach the maximum node number and
     * while we didn't reach the maximum weight:
     *     - We increase the total weight with the weight of the current object
     *     - We increase the total profit with the value of the current object
     */
    while ((i < objects_number) && (weight + objects[i].weight <= max_weight)) {
        weight = weight + objects[i].weight;
        profit_bound = profit_bound + objects[i].value;
        i++;
    }

    /**
     * If we didn't reach the maximal number of node,
     * we use the fractional method to compute the better
     * profit, and then increase the chances of completely fill
     * the knapsack.
     * Example (from knapsack0 file):
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * The maximal weight = 1000                                           *
     * The computed profit bound = 99                                      *
     * The maximal weight computed = 950                                   *
     * Thus, the remaining weight is = 1000-950=50                         *
     * The last indexed object is objects[j] of value 14 and of weight 143 *
     * We compute the ratio = 14/143=0.097902                              *
     * profit_bound = profit_bound + (max_weight - weight) * ratio         *
     * profit_bound = 99 + (50 * 0.097902) = approximately 103             *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     */
    if (i < objects_number) {
        profit_bound = profit_bound + (max_weight - weight) * object_compute_ratio(objects[i]);
    }

    return profit_bound;
}

solution *branch_and_bound(object *objects, int objects_number, int max_weight) {
    queue *q;
    node u, v;
    int max_profit, max_profit_found;
    solution *sol;

    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    max_profit = 0;
    sol = solution_create();

    /* We sort the object list per ratio value/weight in descending order */
    objects_quicksort_by_desc_ratio(objects, objects_number);

    /**
     * We initialize the queue with the specified allocation function
     * and the print function for the debugging.
     */
    q = queue_create(queue_alloc_node);
    queue_set_display_func(q, queue_print_node);

    /* The queue must not be empty to execute the first turn of the loop */
    queue_push(q, (void *)&u);

    /* While there's still branchs of the tree to explore */
    while (!queue_empty(q)) {
        max_profit_found = 0;

        /* Get the next node */
        u = *(node *)queue_front(q);
        /* Delete the node we just got */
        queue_pop(q);

        /* If we just begins the exploration, we initialize the level to 0 */
        if (u.level == -1) {
            v.level = 0;
        }

        /* We incremente the level of the node of the tree */
        v.level = u.level + 1;
        /* We incremente the weight and the profit from the object of the current level */
        v.weight = u.weight + objects[v.level].weight;
        v.profit = u.profit + objects[v.level].value;

        /**
         * If the weight is still letter than the maximal weight, and that the
         * profit is better that the best known profit, we update it.
         */
        if (v.weight <= max_weight && v.profit > max_profit) {
            max_profit = v.profit;
            max_profit_found = 1;
        }

        /* We prune the tree */
        v.bound = bound(objects, objects_number, max_weight, &v);
        /* If the computed profit is the best, we add the node to the tree */
        if (v.bound > max_profit) {
            queue_push(q, (void *)&v);
            if (max_profit_found) {
                solution_add(sol, &objects[v.level], &v);
            }
        }

        /* We test with u without the sum of the object of level v.level */
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(objects, objects_number, max_weight, &v);
        /* If the computed profit is the best, we add this node to the tree */
        if (v.bound > max_profit) {
            queue_push(q, (void *)&v);
        }
    }

    /* Deallocation of the queue */
    queue_destroy(q);

    /* Set the optimum profit */
    sol->optimum = max_profit;

    return sol;
}
