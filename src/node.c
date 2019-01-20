#include "node.h"

#include <stdlib.h>
#include <string.h>

void node_print(node *n, FILE *fd) {
    if (n) {
        fprintf(fd, "node : level:%d profit:%d bound:%d weight:%f", n->level, n->profit, n->bound, n->weight);
    }
}

node *node_copy(node *n) {
    node *new_node;

    new_node = (node *)malloc(sizeof(node));
    memcpy(new_node, n, sizeof(node));

    return new_node;
}
