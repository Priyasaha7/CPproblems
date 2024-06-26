#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int m;
    scanf("%d", &m);
    int *b = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    int *c = (int*)malloc((n + m) * sizeof(int));
    int i = 0, j = 0, k = 0;

    
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }


    while (i < n) {
        c[k++] = a[i++];
    }


    while (j < m) {
        c[k++] = b[j++];
    }

    
    for (int l = 0; l < k; l++) {
        printf("%d ", c[l]);
    }
    printf("\n");

    free(a);
    free(b);
    free(c);

    return 0;
}
