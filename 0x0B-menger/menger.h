#ifndef MENGER_H
#define MENGER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menger(int level);
void fill_sponge(int **grid, int x_start, int x_end, int y_start, int y_end);
void draw_sponge(int **grid, int size);
int **alloc_grid(int width, int height);
void free_grid(int **grid, int height);

#endif /* MENGER_H */