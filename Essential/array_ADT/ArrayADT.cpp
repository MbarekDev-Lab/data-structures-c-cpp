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

int Delete(struct Array *arr, int index);
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

// ============================================================================
// IMPORTANT: Understanding arr->length vs arr.length
// ============================================================================
// arr->length means:
//   - arr is a POINTER to a struct (struct Array *arr)
//   - We're accessing the 'length' member through the pointer
//   - Equivalent to: (*arr).length
//
// This does NOT mean the struct is on the heap!
// The struct can be on STACK or HEAP - it depends on how it was created:
//
// STACK example:
//   struct Array arr;        // Struct on stack
//   Insert(&arr, 0, 5);      // Pass address (pointer) - struct still on stack!
//
// HEAP example:
//   struct Array *arr = malloc(sizeof(struct Array));  // Struct on heap
//   Insert(arr, 0, 5);       // Pass pointer - struct is on heap
//
// The -> operator just means "access through pointer", not "on heap"
// ============================================================================

// implenting Insert
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

// ============================================================================
// DEMO: Showing -> operator with struct on STACK vs HEAP
// ============================================================================
void demo_pointer_operator() {
  printf("\n=== DEMO: Understanding -> operator ===\n");

  // CASE 1: Struct on STACK, but we use -> when passing pointer
  printf("\n--- Case 1: Struct on STACK ---\n");
  struct Array arr_stack; // Struct itself is on STACK
  arr_stack.size = 10;
  arr_stack.length = 0;
  arr_stack.A = (int *)malloc(10 * sizeof(int)); // Only A points to HEAP

  printf("arr_stack is on STACK\n");
  printf("arr_stack.A points to HEAP\n");
  printf("Using arr_stack.length (dot operator - direct access)\n");

  // Pass address - now we use -> operator, but struct is still on STACK!
  Insert(&arr_stack, 0, 100);
  printf("After Insert(&arr_stack, ...): arr_stack.length = %d\n",
         arr_stack.length);

  // CASE 2: Struct on HEAP, we use -> operator
  printf("\n--- Case 2: Struct on HEAP ---\n");
  struct Array *arr_heap = (struct Array *)malloc(sizeof(struct Array));
  arr_heap->size = 10; // Must use -> because arr_heap is a pointer
  arr_heap->length = 0;
  arr_heap->A = (int *)malloc(10 * sizeof(int));

  printf("arr_heap is a POINTER to struct on HEAP\n");
  printf("arr_heap->A also points to HEAP\n");
  printf("Using arr_heap->length (arrow operator - through pointer)\n");

  Insert(arr_heap, 0, 200); // Pass pointer directly
  printf("After Insert(arr_heap, ...): arr_heap->length = %d\n",
         arr_heap->length);

  printf("\nKEY POINT: -> operator means 'access through pointer', ");
  printf("NOT 'struct is on heap'!\n");

  // Cleanup
  free(arr_stack.A);
  free(arr_heap->A);
  free(arr_heap);
}

// implement InsertAppend :
void insertAppend_demo() {
  printf("\n=== DEMO: Insert and Append Operations ===\n");

  // Create a dynamic array (Insert works with struct Array, not ArrayFix)
  // NOTE: This struct is on STACK, but we pass its address (pointer)
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

// Demonstrate -> Delete
// Deletes element at given index and returns the deleted value
int Delete(struct Array *arr, int index) {
  int x = 0;
  int i;

  if (index >= 0 && index < arr->length) {
    x = arr->A[index]; // Save the value to delete

    // Shift all elements after index to the left
    for (i = index; i < arr->length - 1; i++) {
      arr->A[i] = arr->A[i + 1];
    }

    arr->length--; // Decrement length ONCE after shifting
    return x;      // Return deleted value
  }
  return 0; // Invalid index
}

// ============================================================================
// DEMO: Delete operation
// ============================================================================
void demo_delete() {
  printf("\n=== DEMO: Delete Operation ===\n");

  struct Array arr;
  arr.size = 10;
  arr.length = 5;
  arr.A = (int *)malloc(arr.size * sizeof(int));

  // Initialize with values
  int initial[] = {10, 20, 30, 40, 50};
  for (int i = 0; i < arr.length; i++) {
    arr.A[i] = initial[i];
  }

  printf("Initial array: ");
  display(arr);

  // Delete element at index 2 (value 30)
  printf("\nDeleting element at index 2...\n");
  int deleted = Delete(&arr, 2);
  printf("Deleted value: %d\n", deleted);
  printf("Array after deletion: ");
  display(arr);

  // Delete element at index 0 (first element)
  printf("\nDeleting element at index 0...\n");
  deleted = Delete(&arr, 0);
  printf("Deleted value: %d\n", deleted);
  printf("Array after deletion: ");
  display(arr);

  // Try invalid index
  printf("\nTrying to delete at invalid index 10...\n");
  deleted = Delete(&arr, 10);
  printf("Returned value: %d (0 means invalid index)\n", deleted);
  printf("Array unchanged: ");
  display(arr);

  free(arr.A);
}

// ============================================================================
// LinearSearch FUNCTION
// ============================================================================

void swap(int *x, int *y) {
  int temp;
  *x = *y;
  *y = temp;
}

int LinearSearch(struct Array arr, int key) {
  int i;
  for (i = 0; i < arr.length; i++) {
    if (key == arr.A[i]) {
      swap(&arr.A[i], &arr.A[i - 1]);
      return i; // Return index if found
    }
  }
  return -1; // Return -1 if not found
}

int BinarySearch(struct Array arr, int key) {
  int l, mid, h;
  l = 0;
  h = arr.length - 1;

  while (l <= h) {
    mid = (l + h) / 2;
    if (key == arr.A[mid]) {
      return mid;
    } else if (key < arr.A[mid]) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}

int LinearSearch(int a[], int l, int h, int key) {
  int mid;
  if (l <= h) {
    mid = (l + h) / 2;
    if (key == a[mid]) {
      return mid;
    } else if (key < a[mid]) {
      return LinearSearch(a, l, mid - 1, key);
    } else {
      return LinearSearch(a, mid + 1, h, key);
    }
  }
  return -1;
}

int Get(struct Array arr, int index) {
  if (index >= 0 && index < arr.length) {
    return arr.A[index];
  } else {
    return -1;
  }

  return -1;
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

  // Demonstrate -> operator (stack vs heap)
  demo_pointer_operator();

  insertAppend_demo();

  // Demonstrate Delete operation
  demo_delete();

  struct Array arr;
  arr.size = 10;
  arr.length = 5;
  arr.A = (int *)malloc(arr.size * sizeof(int));
  if (arr.A == nullptr) {
    printf("Memory allocation failed for demo array\n");
    return;
  }
  int demo_vals[] = {10, 20, 30, 40, 50};
  for (int i = 0; i < arr.length; i++) {
    arr.A[i] = demo_vals[i];
  }

  printf("%d\n", LinearSearch(arr, 15));
  display(arr);

  printf("%d\n", LinearSearch(arr, 10));
  display(arr);

  printf("%d\n", LinearSearch(arr.A, 0, arr.length, 5));
  display(arr); // we got index

  free(arr.A);

  std::cout << "\n=== end Array ADT Demo ===\n";
}

/*
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

  // Demonstrate -> operator (stack vs heap)
  demo_pointer_operator();

  insertAppend_demo();

  // Demonstrate Delete operation
  demo_delete();

  struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};

  printf("%d\n", LinearSearch(arr, 15));
  display(arr);

  printf("%d\n", LinearSearch(arr, 10));
  display(arr);

  std::cout << "\n=== end Array ADT Demo ===\n";
}
*/
