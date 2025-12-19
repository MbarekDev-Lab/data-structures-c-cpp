//
//  2DArrays.cpp
//  Essential
//
//  Demonstrates a simple 2D array and iteration order.
//

#include "2DArrays.hpp"
#include <cstdio>
#include <cstdlib>

void two_dimensional_array() {
  // Declare a 2D array
  int A[3][4] = {
      {1, 2, 3, 4},
      {4, 5, 6, 4},
      {4, 5, 6, 4},
  };

  // Declare a pointer array
  int *B[3];

  // Declare a pointer pointer array
  int **C;

  /*int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }*/

  B[0] = (int *)malloc(4 * sizeof(int));
  B[1] = (int *)malloc(4 * sizeof(int));
  B[2] = (int *)malloc(4 * sizeof(int));

  /*int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }*/

  C = (int **)malloc(3 * sizeof(int *));
  C[0] = (int *)malloc(4 * sizeof(int));
  C[1] = (int *)malloc(4 * sizeof(int));
  C[2] = (int *)malloc(4 * sizeof(int));

  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
}
