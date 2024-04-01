#include <stdio.h>


int powerMod(int a, int b, int m) {
    int result = 1;
    a = a % m; 

    while (b > 0) {
        
        if (b & 1)
            result = (result * a) % m;


        b = b >> 1; 
        a = (a * a) % m; 
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
