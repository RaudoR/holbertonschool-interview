#ifndef SLIDE_H
#define SLIDE_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void slide_non_zero(int *line, size_t size);
void slide_zero(int *line, size_t size);
void reverse(int *line, size_t size);

#endif