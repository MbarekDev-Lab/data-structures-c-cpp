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

// ============================================================================
// MAIN
// ============================================================================

int main(int argc, const char *argv[])
{
    printf("=== String Operations Demonstration ===\n");

    demo_basic_operations();
    demo_case_operations();
    demo_string_analysis();
    demo_advanced_operations();
    demo_comparison();

    printf("\n=== End of Program ===\n");
    return 0;
}

// clang -o string_app Strings/String.c && ./string_app
// gcc -std=c17 -o string_app Strings/String.c && ./string_app