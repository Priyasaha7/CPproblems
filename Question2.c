#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1)
        return 0; // Not a prime number
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0; // Not a prime number
    }
    return 1; // Prime number
}

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);

    int count = 0;
    int num = 2; // Start from the first prime number

    while (count < N) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
            num += 2; // Skip every alternate prime number
        } else {
            num++;
        }
    }

    return 0;
}

