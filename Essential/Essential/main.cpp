//
//  main.cpp
//  Essential
//
//  Created by M'Barek Benraiss on 17.12.25.
//

#include <cstdlib>
#include <iostream>

#include "arrays/ArraysRep.hpp"
#include "arrays/2DArrays.hpp"
#include "quiz/Quiz.hpp"
#include "recursion/Combinatorics.hpp"

int main(int argc, const char *argv[]) {
  std::cout << "Start Program!" << '\n';

  // Demonstrate combinatorics
  std::cout << "C(5, 1) = " << nCr(5, 1) << '\n';
  std::cout << "C(5, 2) = " << nCr(5, 2) << '\n';
  std::cout << "C(10, 3) = " << nCr(10, 3) << '\n';
  std::cout << "C(10, 3) [recursive] = " << nCrRecursive(10, 3) << '\n';

  // Demonstrate array representation
  std::cout << "\nArray Representation:\n";
  arrayRepresentation();

  // Demonstrate quiz functions
  int a = 2048, sum = 0;
  std::cout << "\nSum of digits of " << a << ": ";
  foo(a, sum);
  std::cout << "\nSum = " << sum << "\n\n";

  int fResult = f(1);
  std::cout << "f(1) = " << fResult << '\n';

  // Demonstrate 2D array
  two_dimensional_array();






  return EXIT_SUCCESS;
}
