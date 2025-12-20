#include "ArrayADT.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>

// ============================================================================
// CONCEPT 1: DYNAMIC ARRAY (using pointer)
// ============================================================================
// A pointer (int *A) can point to dynamically allocated memory
// - Can resize at runtime with malloc/realloc
// - Memory is on the heap
// - Size can be determined at runtime
// - CANNOT be initialized with {1,2,3} syntax
// ============================================================================
struct Array {
  int *A;     // Pointer to dynamically allocated memory
  int size;   // Maximum capacity
  int length; // Current number of elements
};

// ============================================================================
// CONCEPT 2: FIXED-SIZE ARRAY
// ============================================================================
// A fixed-size array (int A[5]) is allocated on the stack
// - Size is fixed at compile time
// - CAN be initialized with {1,2,3} syntax
// - Cannot be resized (no realloc)
// - Memory is on the stack
// ============================================================================
struct ArrayFix {
  int A[5];   // Fixed-size array (5 elements max)
  int size;   // Maximum capacity (should be 5 or less)
  int length; // Current number of elements
};

// Display function for dynamic array
void display(struct Array arr) {
  printf("\n[Dynamic Array] Elements are: ");
  for (int i = 0; i < arr.length; i++) {
    printf("%d ", arr.A[i]);
  }
  printf("\n");
}

// Display function for fixed array
void display(struct ArrayFix arr) {
  printf("\n[Fixed Array] Elements are: ");
  for (int i = 0; i < arr.length; i++) {
    printf("%d ", arr.A[i]);
  }
  printf("\n");
}

// ============================================================================
// DEMONSTRATION: Fixed-Size Array
// ============================================================================
void demo_fixed_array() {
  printf("\n=== DEMO: Fixed-Size Array ===\n");

  // Fixed-size arrays CAN be initialized with {1,2,3} syntax
  struct ArrayFix arr_fix = {{1, 2, 3, 4, 5}, 5, 5};

  printf("Initialized with: ");
  display(arr_fix);

  // Modify elements
  arr_fix.A[0] = 10;
  arr_fix.length = 3; // Only show first 3 elements

  printf("After modification: ");
  display(arr_fix);
}

// ============================================================================
// DEMONSTRATION: Dynamic Array (Pointer-based)
// ============================================================================
void demo_dynamic_array() {
  printf("\n=== DEMO: Dynamic Array (Pointer-based) ===\n");

  struct Array arr;

  // Must allocate memory first before using
  arr.size = 10;
  arr.length = 0;
  arr.A = (int *)malloc(arr.size * sizeof(int));

  if (arr.A == nullptr) {
    printf("Memory allocation failed!\n");
    return;
  }

  // Now we can assign values
  int initial_values[] = {2, 3, 4, 5, 6};
  arr.length = 5;
  for (int i = 0; i < arr.length; i++) {
    arr.A[i] = initial_values[i];
  }

  printf("Initialized with: ");
  display(arr);

  // Can resize dynamically
  arr.size = 20;
  arr.A = (int *)realloc(arr.A, arr.size * sizeof(int));
  printf("Resized to capacity: %d\n", arr.size);

  // CANNOT do this:
  // struct Array arr = {{1, 2, 3}, 10, 3};  // ERROR: Can't initialize pointer
  // with {}

  // Clean up
  free(arr.A);
}

// ============================================================================
// INTERACTIVE DEMO: Dynamic Array with user input
// ============================================================================
void demo_interactive() {
  printf("\n=== INTERACTIVE DEMO: Dynamic Array ===\n");

  struct Array arr;
  int n, i;

  printf("Enter size of array: ");
  scanf("%d", &arr.size);

  // Allocate memory
  arr.A = (int *)malloc(arr.size * sizeof(int));
  if (arr.A == nullptr) {
    printf("Memory allocation failed!\n");
    return;
  }

  arr.length = 0;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  if (n > arr.size) {
    printf("Warning: n (%d) > size (%d). Resizing...\n", n, arr.size);
    arr.size = n;
    arr.A = (int *)realloc(arr.A, arr.size * sizeof(int));
  }

  printf("Enter all %d elements (space-separated): ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr.A[i]);
  }

  arr.length = n;

  display(arr);

  // Clean up
  free(arr.A);
}

// ============================================================================
// MAIN DEMO FUNCTION
// ============================================================================
void arraysADT_demo() {
  std::cout << "\n=== Array ADT Demo ===\n";

  // Show both concepts
  demo_fixed_array();
  demo_dynamic_array();

  // Interactive demo
  demo_interactive();
}
