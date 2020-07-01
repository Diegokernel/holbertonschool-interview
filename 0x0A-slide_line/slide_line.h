#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

#include <stdio.h>
#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void slide_line_to_left(int *line, int size_i);
void slide_line_to_rigth(int *line, int size_i);

#endif /* SLIDE_LINE */
