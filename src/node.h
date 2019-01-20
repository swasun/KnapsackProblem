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
