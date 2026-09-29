#include <stdio.h>
#include "draw.h"

/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}

// Prints a triangle of specified height whose left edge is at col leftCol.
void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}

void print_arrow(int leftCol, int size)
{
  // we will call print_triangle to form tip of arrow
  print_triangle(leftCol, size);
  // the shaft has to be centered under the tip at column 10
  // a 3 wide shaft covers colums 9, 10, 11
  int shaftWidth= 3; // shaft width set to 3
  // starts with shaftWidth / 2 columns to the left of center
  // left col is 10
  // size is (5, 5)
  // 3 / 2 integer divison leaves 1
  // shaftLeft = 10 - 1
  int shaftLeft = leftCol + size - shaftWidth / 2; 
  for (int row = 0; row < size; row++) {
    int col;
    for (col = 0; col < shaftLeft; col++) putchar(' ');
    for (       ; col < shaftLeft + shaftWidth; col++) putchar('*');
    putchar('\n');
  }
}
