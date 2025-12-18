//
//  main.cpp
//  Essential
//
//  Created by M'Barek Benraiss on 17.12.25.
//

#include <cstdlib>
#include <iostream>

#include "recursion/Combinatorics.hpp"
#include "recursion/Quiz.hpp"

int main(int argc, const char *argv[]) {
  std::cout << "Start Program!" << '\n';

  // Demonstrate a few combinations
  /*std::cout << "C(5, 1) = " << nCr(5, 1) << '\n';
  std::cout << "C(5, 2) = " << nCr(5, 2) << '\n';
  std::cout << "C(10, 3) = " << nCr(10, 3) << '\n';
  std::cout << "C(10, 3) [recursive] = " << nCrRecursive(10, 3) << '\n';

  // int n, r;
  // std::cout << "Enter n and r: ";
  // if (std::cin >> n >> r) {
  //     std::cout << "C(" << n << ", " << r << ") = " << nCr(n, r) << '\n';
  // } else {
  //     std::cerr << "Invalid input." << '\n';
  // }

  int a = 2048, sum = 0;
  foo(a, sum);
  std::cout << "\nSum of digits = " << sum << "\n\n";

  int fResult = f(1);
  std::cout << "f(1) = " << fResult << '\n';*/

  int A[5] = {2, 4, 6, 8, 10};
  int *p;
  int i;

  p = (int *)malloc(5 * sizeof(int));
  p[0] = 3;
  p[1] = 5;
  p[2] = 7;
  p[3] = 9;
  p[4] = 11;

  // Debug: print values right after assignment
  std::cout << "Debug p values: ";
  for (int j = 0; j < 5; ++j) {
    std::cout << p[j] << " ";
  }
  std::cout << "\n";

  for (i = 0; i < 5; i++) {
    std::cout << A[i] << std::endl;
  }

  std::cout << std::endl;

  for (i = 0; i < 5; i++) {
    std::cout << p[i] << std::endl;
  }

  free(p);
  return EXIT_SUCCESS;
}
