#include "Quiz.hpp"
#include "Combinatorics.hpp"
#include <cstdio>

int f(int n)
{
    static int i = 1;
    if (n >= 5) return n;

    n = n + i;
    i++;
    return f(n);
}

void foo(int n, int &sum)
{
    int k = 0, j = 0;

    if (n == 0) return;

    k = n % 10;   // last digit
    j = n / 10;   // remaining number
    sum = sum + k;

    foo(j, sum);
    std::printf("%d", k);
}
