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
// INTERACTIVE DEMO: Dynamic Array with user input
// ============================================================================

void Delete(struct Array *arr, int index);
int Get(struct Array arr, int index);
void Set(struct Array *arr, int index, int x);
int Max(struct Array arr);
int Min(struct Array arr);
float Avg(struct Array arr);
void Reverse(struct Array *arr);
void Reverse2(struct Array *arr);

void Append(struct Array *arr, int x) {
  if (arr->length < arr->size) {
    arr->A[arr->length] = x;
    arr->length++;
  } else {
    printf("Error: Array is full\n");
  }
}

void Insert(struct Array *arr, int index, int x) {
  int i;
  if (index >= 0 && index <= arr->length) {
    for (i = arr->length; i > index; i--) {
      arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
  }
}

void insertAppend_demo() {
  printf("\n=== DEMO: Insert and Append Operations ===\n");
  
  // Create a dynamic array (Insert works with struct Array, not ArrayFix)
  struct Array arr;
  arr.size = 10;
  arr.length = 5;
  arr.A = (int *)malloc(arr.size * sizeof(int));
  
  // Initialize with some values
  int initial[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < arr.length; i++) {
    arr.A[i] = initial[i];
  }
  
  printf("Initial array: ");
  display(arr);
  
  // Test Append
  printf("\nAppending 6...\n");
  Append(&arr, 6);
  display(arr);
  
  // Test Insert at index 2
  printf("\nInserting 99 at index 2...\n");
  Insert(&arr, 2, 99);
  display(arr);
  
  // Test Insert at beginning
  printf("\nInserting 0 at index 0...\n");
  Insert(&arr, 0, 0);
  display(arr);
  
  // Clean up
  free(arr.A);
}

// ============================================================================
// MAIN DEMO FUNCTION
// ============================================================================
void arraysADT_demo() {
  std::cout << "\n=== start Array ADT Demo ===\n";

  // Show both concepts
  // demo_fixed_array();

  // demo_dynamic_array();

  // Interactive demo
  // demo_interactive();

  insertAppend_demo();
}
