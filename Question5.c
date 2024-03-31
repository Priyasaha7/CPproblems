#include <stdio.h>
#include <stdbool.h>

int lowerbound(int v[], int size, int x) {
    int upper = size - 1, lower = 0, mid;
    while (upper > lower) {
        mid = (upper + lower) / 2;
        if (v[mid] < x)
            lower = mid + 1;
        else
            upper = mid;
    }
    return v[lower];
}

int upperbound(int v[], int size, int x) {
    int upper = size - 1, lower = 0, mid;
    while (upper > lower) {
        mid = (upper + lower) / 2;
        if (v[mid] <= x)
            lower = mid + 1;
        else
            upper = mid;
    }
    return v[lower];
}

bool ispresent(int v[], int size, int x) {
    int upper = size - 1, lower = 0, mid;
    while (upper >= lower) {
        mid = (upper + lower) / 2;
        if (v[mid] == x)
            return true;
        else if (v[mid] < x)
            lower = mid + 1;
        else
            upper = mid - 1;
    }
    return false;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int v[n];
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    int x;
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    // Assuming array is sorted before applying functions
    printf("Lower bound: %d\n", lowerbound(v, n, x));
    printf("Upper bound: %d\n", upperbound(v, n, x));
    if (ispresent(v, n, x)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}