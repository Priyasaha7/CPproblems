#include <stdio.h>

// Function to calculate (a^b) % m
int powerMod(int a, int b, int m) {
    int result = 1;
    a = a % m; // Take modulo of base

    while (b > 0) {
        // If b is odd, multiply result with base and take modulo
        if (b & 1)
            result = (result * a) % m;

        // b must be even now
        b = b >> 1; // b = b/2
        a = (a * a) % m; // Update base
    }
    return result;
}

int main() {
    int a, b, m;
    printf("Enter values for a, b, and m: ");
    scanf("%d %d %d", &a, &b, &m);
    int result = powerMod(a, b, m);
    printf("%d\n", result);
    return 0;
}