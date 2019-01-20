A program that computes the Knapsack problem using branch-and-bound (fractional method) (School Project, Algorithmic and Operations Reseach class, 2017).

## Usage

```
mkdir obj && mkdir bin
./bin/knapsack --help

Usage: ./bin/knapsack --help | --tests | <file_name>
```

## Using the code

```c
#include "branch_and_bound.h"
#include "object.h"
#include "solution.h"

object *objects;
solution *sol;
int objects_number, max_weight;

/* The loaded file returns a list of objects and a maximal weight */
if (!(objects = objects_load_from_file(argv[1], &objects_number, &  max_weight))) {
    fprintf(stderr, "[ERROR] Failed to load data file.\n");
    exit(EXIT_FAILURE);
}

fprintf(stdout, "The weight capacity of the knapsack is: %d.\n", max_weight);

sol = branch_and_bound(objects, objects_number, max_weight);

solution_print(sol, stdout);

solution_destroy(sol);

free((void *)objects);
```

## Experiments

```
./bin/knapsack res/knapsack0
The weight capacity of the knapsack is: 1000.
Execution of the algorithm in 0.000052s.

The optimum is 103.

Variables and nodes:

node : level:0 profit:25 bound:103 weight:231.000000
object : weight:231 value:25 ratio:0.108225

node : level:1 profit:37 bound:103 weight:343.000000
object : weight:112 value:12 ratio:0.107143

node : level:2 profit:50 bound:103 weight:467.000000
object : weight:124 value:13 ratio:0.104839

node : level:3 profit:73 bound:103 weight:689.000000
object : weight:222 value:23 ratio:0.103604

node : level:4 profit:83 bound:103 weight:787.000000
object : weight:98 value:10 ratio:0.102041

node : level:5 profit:99 bound:103 weight:950.000000
object : weight:163 value:16 ratio:0.098160
```

```
./bin/knapsack res/knapsack1
The weight capacity of the knapsack is: 2000.
Execution of the algorithm in 0.004980s.

The optimum is 2077672.

Variables and nodes:

[...]
```

```
./bin/knapsack res/knapsack2
The weight capacity of the knapsack is: 2000.
Execution of the algorithm in 0.006011s.

The optimum is 2095878.

Variables and nodes:

[...]
```

```
./bin/knapsack res/knapsack3
The weight capacity of the knapsack is: 2000.
Execution of the algorithm in 0.031755s.

The optimum is 2132531.

Variables and nodes:

[...]
```

```
./bin/knapsack res/knapsack4
The weight capacity of the knapsack is: 2000.
Execution of the algorithm in 0.604614s.

The optimum is 2166542.

Variables and nodes:

[...]
```
