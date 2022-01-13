#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void copy_grid(int from[3][3], int to[3][3]);
void make_topple(int grid[3][3], int i, int j);
void simple_sand_sum(int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif