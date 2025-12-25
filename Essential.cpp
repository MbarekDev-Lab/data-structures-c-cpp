//
//  Essential.cpp
//
//
//  Created by M'Barek Benraiss on 16.12.25.
//

extern "C" {
#include "ArrayDSA/ArrayMenuusing_C /ArrayMenu.hpp"
}
#include "ArrayDSA/array_ADT/ArrayADT.hpp"

#include <cstdlib>
#include <iostream>

int main(int argc, const char *argv[]) {
  std::cout << "Start Program!" << '\n';

  // arraysADT demo array
   arraysADT_demo();

  // arraysMenue demo arrays
  //arraysMenu();

  std::cout << "End Program!" << '\n';
  return EXIT_SUCCESS;
}
 