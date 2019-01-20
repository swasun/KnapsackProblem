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
