#include <stdio.h>


int isPrime(int num) {
    if (num <= 1)
        return 0; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0; 
    }
    return 1; 
}

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);

    int count = 0;
    int num = 2;

    while (count < N) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
            num += 2; 
        } else {
            num++;
        }
    }

    return 0;
}

