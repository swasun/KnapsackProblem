#include "solution.h"

#include <stdlib.h>

solution *solution_create() {
    solution *sol;

    sol = (solution *)malloc(sizeof(solution));
    sol->variables = NULL;
    sol->variables_number = 0;
    sol->optimum = 0;

    return sol;
}

void solution_destroy(solution *sol) {
    int i;

    if (sol) {
        if (sol->variables) {
            for (i = 0; i < sol->variables_number; i++) {
                variable_destroy(sol->variables[i]);
            }
            free((void *)sol->variables);
        }
        free((void *)sol);
    }
}

void solution_add(solution *sol, object *obj, node *n) {
    if (sol->variables) {
        sol->variables = (variable **)realloc(sol->variables, (sol->variables_number + 1) * sizeof(variable *));
    } else {
        sol->variables = (variable **)malloc(sizeof(variable *));
    }
    sol->variables[sol->variables_number] = variable_create(obj, n);
    sol->variables_number++;
}

void solution_print(solution *sol, FILE *fd) {
    int i;

    fprintf(fd, "\nThe optimum is %d.\n\n", sol->optimum);
    fprintf(fd, "Variables and nodes:\n\n");
    for (i = 0; i < sol->variables_number; i++) {
        variable_print(sol->variables[i], fd);
        fprintf(fd, "\n");
    }
    fprintf(fd, "\n");
}
