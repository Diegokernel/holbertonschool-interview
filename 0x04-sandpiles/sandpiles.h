#ifndef SANDPILES_H
#define SANDPILES_H

#include "stddef.h"
#include "stdio.h"
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int is_unstable(int grid[3][3]);
static void print_grid(int grid[3][3]);
void check_piles(int grid[3][3], int overs[3][3]);
void add_sandpiles(int grid1[3][3], int grid2[3][3]);
#endif
