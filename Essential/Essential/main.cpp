//
//  main.cpp
//  Essential
//
//  Created by M'Barek Benraiss on 17.12.25.
//

#include <iostream>
#include <limits>
#include <vector>

long long nCr(int n, int r) {
    if (n < 0 || r < 0 || r > n) {
        return 0;
    }

    // Using symmetry: C(n, r) == C(n, n - r)
    if (r > n - r) {
        r = n - r;
    }

    long long result = 1;
    for (int i = 1; i <= r; ++i) {
         result = (result * static_cast<long long>(n - r + i)) / i;
    }
    return result;
}

// Memoized recursive computation of nCr using Pascal's identity.
long long nCrRecursive(int n, int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;

    // Use symmetry to shrink the problem
    if (r > n - r) r = n - r;

    static std::vector<std::vector<long long>> memo; // memo[n][r]

    // Ensure memo has size (n+1) x (r+1)
    if ((int)memo.size() <= n) memo.resize(n + 1);
    if ((int)memo[n].size() <= r) memo[n].resize(r + 1, -1);

    long long &cached = memo[n][r];
    if (cached != -1) return cached;

    cached = nCrRecursive(n - 1, r - 1) + nCrRecursive(n - 1, r);
    return cached;
}

int main(int argc, const char * argv[]) {
    std::cout << "Start Program!" << '\n';

    // Demonstrate a few combinations
    std::cout << "C(5, 1) = " << nCr(5, 1) << '\n';
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

    return EXIT_SUCCESS;
}
