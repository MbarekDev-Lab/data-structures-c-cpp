#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ============================================================================
// STRING UTILITY FUNCTIONS
// ============================================================================

// Calculate string length
int str_length(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

// Copy string from source to destination
void str_copy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Concatenate two strings
void str_concat(char *dest, const char *src)
{
    int i = 0, j = 0;

    // Find end of dest
    while (dest[i] != '\0')
        i++;

    // Copy src to end of dest
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

// Compare two strings (returns 0 if equal, <0 if s1<s2, >0 if s1>s2)
int str_compare(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

// Reverse a string in-place
void str_reverse(char *str)
{
    int left = 0;
    int right = str_length(str) - 1;

    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

// Convert string to uppercase
void str_to_upper(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
}

// Convert string to lowercase
void str_to_lower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

// Toggle case of each character
void str_toggle_case(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
        else if (islower(str[i]))
            str[i] = toupper(str[i]);
    }
}

// Count vowels in a string
int count_vowels(const char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            count++;
    }
    return count;
}

// Count consonants in a string
int count_consonants(const char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);
        if ((ch >= 'a' && ch <= 'z') &&
            !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'))
            count++;
    }
    return count;
}

// Count words in a string
int count_words(const char *str)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            in_word = 0;
        }
        else if (in_word == 0)
        {
            in_word = 1;
            count++;
        }
    }
    return count;
}

// Check if string is palindrome
int is_palindrome(const char *str)
{
    int left = 0;
    int right = str_length(str) - 1;

    while (left < right)
    {
        if (str[left] != str[right])
            return 0;
        left++;
        right--;
    }
    return 1;
}

// Find first occurrence of character in string
int find_char(const char *str, char ch)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
            return i;
    }
    return -1;
}

// Check if two strings are anagrams
int are_anagrams(const char *s1, const char *s2)
{
    if (str_length(s1) != str_length(s2))
        return 0;

    int freq[26] = {0};

    // Count frequency in s1
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (isalpha(s1[i]))
            freq[tolower(s1[i]) - 'a']++;
    }

    // Subtract frequency in s2
    for (int i = 0; s2[i] != '\0'; i++)
    {
        if (isalpha(s2[i]))
            freq[tolower(s2[i]) - 'a']--;
    }

    // Check if all frequencies are zero
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
            return 0;
    }
    return 1;
}

// Remove duplicates from string
void remove_duplicates(char *str)
{
    int seen[256] = {0};
    int write = 0;

    for (int read = 0; str[read] != '\0'; read++)
    {
        if (!seen[(unsigned char)str[read]])
        {
            seen[(unsigned char)str[read]] = 1;
            str[write++] = str[read];
        }
    }
    str[write] = '\0';
}

// ============================================================================
// ADVANCED CASE CONVERSION METHODS
// ============================================================================

// Method 1: Using ASCII arithmetic (most efficient)
void to_uppercase_ascii(char *str)
{
    // a = 97, A = 65, difference = 32
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
}

// Method 2: Using lookup tables
void to_uppercase_lookup(char *str)
{
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (str[i] == lower[j])
            {
                str[i] = upper[j];
                break;
            }
        }
    }
}

// Method 3: Using ctype.h (most portable)
void to_uppercase_ctype(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// Method 4: Using bitwise operation (fastest)
void to_uppercase_bitwise(char *str)
{
    // Clear the 6th bit (0x20) to convert lowercase to uppercase
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] &= ~0x20; // Clear bit 5 (0-indexed)
        }
    }
}

// Corresponding lowercase conversion methods
void to_lowercase_ascii(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
}

void to_lowercase_bitwise(char *str)
{
    // Set the 6th bit (0x20) to convert uppercase to lowercase
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] |= 0x20; // Set bit 5 (0-indexed)
        }
    }
}

// Demonstration of all methods
void demo_case_conversion_methods()
{
    printf("\n=== Case Conversion Methods Demonstration ===\n");

    // Method 1: ASCII arithmetic
    char str1[] = "hello world 123";
    printf("\nMethod 1 - ASCII Arithmetic:\n");
    printf("Before: %s\n", str1);
    to_uppercase_ascii(str1);
    printf("After:  %s\n", str1);

    // Method 2: Lookup table
    char str2[] = "data structures in c";
    printf("\nMethod 2 - Lookup Table:\n");
    printf("Before: %s\n", str2);
    to_uppercase_lookup(str2);
    printf("After:  %s\n", str2);

    // Method 3: ctype.h
    char str3[] = "programming in c";
    printf("\nMethod 3 - ctype.h (toupper):\n");
    printf("Before: %s\n", str3);
    to_uppercase_ctype(str3);
    printf("After:  %s\n", str3);

    // Method 4: Bitwise operation
    char str4[] = "efficient algorithm";
    printf("\nMethod 4 - Bitwise Operation:\n");
    printf("Before: %s\n", str4);
    to_uppercase_bitwise(str4);
    printf("After:  %s\n", str4);

    // Demonstrate lowercase conversion
    char str5[] = "CONVERT TO LOWERCASE";
    printf("\nLowercase Conversion (ASCII):\n");
    printf("Before: %s\n", str5);
    to_lowercase_ascii(str5);
    printf("After:  %s\n", str5);

    char str6[] = "BITWISE LOWERCASE";
    printf("\nLowercase Conversion (Bitwise):\n");
    printf("Before: %s\n", str6);
    to_lowercase_bitwise(str6);
    printf("After:  %s\n", str6);

    // Performance comparison explanation
    printf("\n=== Performance Notes ===\n");
    printf("1. ASCII Arithmetic:   Fast, simple, readable\n");
    printf("2. Lookup Table:       O(n*26) time, educational value\n");
    printf("3. ctype.h:           Most portable, locale-aware\n");
    printf("4. Bitwise:           Fastest, ~2x faster than arithmetic\n");
}

// ============================================================================
// DEMONSTRATION FUNCTIONS
// ============================================================================

void demo_basic_operations()
{
    printf("\n=== Basic String Operations ===\n");

    char str1[] = "Hello, World!";
    printf("Original string: %s\n", str1);
    printf("Length: %d\n", str_length(str1));

    char str2[50];
    str_copy(str2, "C Programming");
    printf("Copied string: %s\n", str2);

    char str3[100] = "Hello";
    str_concat(str3, " World");
    printf("Concatenated: %s\n", str3);
}

void demo_case_operations()
{
    printf("\n=== Case Operations ===\n");

    char str[] = "Data Structures in C";
    printf("Original: %s\n", str);

    char upper[50];
    str_copy(upper, str);
    str_to_upper(upper);
    printf("Uppercase: %s\n", upper);

    char lower[50];
    str_copy(lower, str);
    str_to_lower(lower);
    printf("Lowercase: %s\n", lower);

    char toggle[50];
    str_copy(toggle, str);
    str_toggle_case(toggle);
    printf("Toggle case: %s\n", toggle);
}

void demo_string_analysis()
{
    printf("\n=== String Analysis ===\n");

    char str[] = "Data Structures in C";
    printf("String: %s\n", str);
    printf("Vowels: %d\n", count_vowels(str));
    printf("Consonants: %d\n", count_consonants(str));
    printf("Words: %d\n", count_words(str));

    char pal1[] = "madam";
    char pal2[] = "hello";
    printf("\n'%s' is palindrome: %s\n", pal1, is_palindrome(pal1) ? "Yes" : "No");
    printf("'%s' is palindrome: %s\n", pal2, is_palindrome(pal2) ? "Yes" : "No");
}

void demo_advanced_operations()
{
    printf("\n=== Advanced Operations ===\n");

    char str[] = "hello";
    printf("Original: %s\n", str);
    str_reverse(str);
    printf("Reversed: %s\n", str);

    printf("\nAnagram check:\n");
    printf("'listen' and 'silent': %s\n", are_anagrams("listen", "silent") ? "Anagrams" : "Not anagrams");
    printf("'hello' and 'world': %s\n", are_anagrams("hello", "world") ? "Anagrams" : "Not anagrams");

    char dup[] = "programming";
    printf("\nOriginal: %s\n", dup);
    remove_duplicates(dup);
    printf("After removing duplicates: %s\n", dup);
}

void demo_comparison()
{
    printf("\n=== String Comparison ===\n");

    int cmp1 = str_compare("apple", "banana");
    int cmp2 = str_compare("hello", "hello");
    int cmp3 = str_compare("zebra", "apple");

    printf("'apple' vs 'banana': %d (negative means first is less)\n", cmp1);
    printf("'hello' vs 'hello': %d (zero means equal)\n", cmp2);
    printf("'zebra' vs 'apple': %d (positive means first is greater)\n", cmp3);
}

// changing case of characters
char *to_uppercase(char *str)
{
    // A = 65, a = 97, difference = 32
    char A[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    /*int i = 0;
    while (str[i] != '\0')
    {
        for (int j = 0; j < 26; j++)
        {
            if (str[i] == a[j])
            {
                str[i] = A[j];
                break;
            }
        }
        i++;
    }*/

    /*int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        A[i] = A[i] + 32;
    }
    printf("%s", A);*/

    int i;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (A[i] > 65 && A[i] < 90) // Check for lowercase
        {
            str[i] -= 32; // Convert to uppercase
        }
    }
    return str;
}

// ============================================================================
// TOGGLE CASE METHODS (Multiple Implementations)
// ============================================================================

// Method 1: Toggle using ASCII arithmetic
void toggle_case_ascii(char *str)
{
    // A = 65, a = 97, difference = 32
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            // Uppercase → Lowercase
            str[i] += 32;
        }
        else if (str[i] >= 97 && str[i] <= 122)
        {
            // Lowercase → Uppercase
            str[i] -= 32;
        }
    }
}

// Method 2: Toggle using lookup tables
void toggle_case_lookup(char *str)
{
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; str[i] != '\0'; i++)
    {
        // Check if uppercase, convert to lowercase
        for (int j = 0; j < 26; j++)
        {
            if (str[i] == upper[j])
            {
                str[i] = lower[j];
                break;
            }
            else if (str[i] == lower[j])
            {
                str[i] = upper[j];
                break;
            }
        }
    }
}

// Method 3: Toggle using ctype.h
void toggle_case_ctype(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isupper((unsigned char)str[i]))
        {
            str[i] = tolower((unsigned char)str[i]);
        }
        else if (islower((unsigned char)str[i]))
        {
            str[i] = toupper((unsigned char)str[i]);
        }
    }
}

// Method 4: Toggle using bitwise XOR (fastest)
void toggle_case_bitwise(char *str)
{
    // XOR with 0x20 (32) toggles bit 5, which flips case
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z'))
        {
            str[i] ^= 0x20; // Toggle bit 5
        }
    }
}

// Method 5: Toggle using conditional operator (compact)
void toggle_case_ternary(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32
                                                                                                   : str[i];
    }
}

// Demonstration of toggle case methods
void demo_toggle_case_methods()
{
    printf("\n=== Toggle Case Methods Demonstration ===\n");

    // Method 1: ASCII arithmetic
    char str1[] = "Hello World 123";
    printf("\nMethod 1 - ASCII Arithmetic:\n");
    printf("Before: %s\n", str1);
    toggle_case_ascii(str1);
    printf("After:  %s\n", str1);
    toggle_case_ascii(str1); // Toggle back
    printf("Toggle back: %s\n", str1);

    // Method 2: Lookup table
    char str2[] = "Data STRUCTURES in C";
    printf("\nMethod 2 - Lookup Table:\n");
    printf("Before: %s\n", str2);
    toggle_case_lookup(str2);
    printf("After:  %s\n", str2);

    // Method 3: ctype.h
    char str3[] = "ProGRamMinG";
    printf("\nMethod 3 - ctype.h:\n");
    printf("Before: %s\n", str3);
    toggle_case_ctype(str3);
    printf("After:  %s\n", str3);

    // Method 4: Bitwise XOR
    char str4[] = "BiTwIsE OpErAtIoN";
    printf("\nMethod 4 - Bitwise XOR:\n");
    printf("Before: %s\n", str4);
    toggle_case_bitwise(str4);
    printf("After:  %s\n", str4);

    // Method 5: Ternary operator
    char str5[] = "TerNaRy ExAmPLe";
    printf("\nMethod 5 - Ternary Operator:\n");
    printf("Before: %s\n", str5);
    toggle_case_ternary(str5);
    printf("After:  %s\n", str5);

    // Demonstrate XOR properties
    printf("\n=== XOR Toggle Properties ===\n");
    char demo[] = "ABC";
    printf("Original: %s\n", demo);
    printf("Binary: A='%c' (0x%02X = 0b01000001)\n", demo[0], demo[0]);
    demo[0] ^= 0x20;
    printf("XOR 0x20: '%c' (0x%02X = 0b01100001) - toggled to lowercase\n", demo[0], demo[0]);
    demo[0] ^= 0x20;
    printf("XOR 0x20: '%c' (0x%02X = 0b01000001) - toggled back to uppercase\n", demo[0], demo[0]);

    printf("\n=== Performance Notes ===\n");
    printf("1. ASCII Arithmetic: Simple, readable, O(n) time\n");
    printf("2. Lookup Table:     O(n*26) time, educational\n");
    printf("3. ctype.h:         Portable, locale-aware\n");
    printf("4. Bitwise XOR:     Fastest, single operation per char\n");
    printf("5. Ternary:         Compact, one-liner logic\n");
}

// ============================================================================
// MAIN clang -o string_app Strings/String.c && ./string_app
// ============================================================================

int main(int argc, const char *argv[])
{
    printf("=== String Operations Demonstration ===\n");

    // Test toggle_case_ascii function
    printf("\n=== Testing toggle_case_ascii Function ===\n");
    char test1[] = "Hello World!";
    printf("Original:     %s\n", test1);
    toggle_case_ascii(test1);

    printf("After toggle: %s\n", test1);
    toggle_case_ascii(test1);
    printf("Toggle back:  %s\n\n", test1);

    char test2[] = "ProGRamMinG In C 2024";
    printf("Original:     %s\n", test2);
    toggle_case_ascii(test2);
    printf("After toggle: %s\n", test2);

    char test3[] = "ABC123xyz";
    printf("\nOriginal:     %s\n", test3);
    toggle_case_ascii(test3);
    printf("After toggle: %s\n", test3);

    printf("\n");
    demo_basic_operations();
    demo_case_operations();
    demo_string_analysis();
    demo_advanced_operations();
    demo_comparison();
    demo_case_conversion_methods();
    demo_toggle_case_methods();

    printf("\n=== End of Program ===\n");
    return 0;
}

// clang -o string_app Strings/String.c && ./string_app
// gcc -std=c17 -o string_app Strings/String.c && ./string_app