#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    int *temp = (int *)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        float mini = 0, maxi = 0, count = 0;
        float avg = 0;
        int mode = 0;
        
        for(int j = 0; j <= i; j++) {
            sum += v[j];
            count++;
            temp[j] = v[j];
        }
        
        avg = sum / count;
        
        for(int j = 0; j <= i; j++) {
            for(int k = j + 1; k <= i; k++) {
                if(temp[j] > temp[k]) {
                    int tempVal = temp[j];
                    temp[j] = temp[k];
                    temp[k] = tempVal;
                }
            }
        }
        
        int maxCount = 0;
        int currentCount = 1;
        int currentMode = temp[0];
        
        for(int j = 1; j <= i; j++) {
            if(temp[j] == temp[j - 1]) {
                currentCount++;
            } else {
                if(currentCount > maxCount) {
                    maxCount = currentCount;
                    currentMode = temp[j - 1];
                }
                currentCount = 1;
            }
        }
        
        if(currentCount > maxCount) {
            maxCount = currentCount;
            currentMode = temp[i];
        }
        
        mode = currentMode;
        mini = temp[0];
        maxi = temp[i];
        
        printf("min, max, sum, average, and mode after addition of %d are %f, %f, %d, %f, %d\n", v[i], mini, maxi, sum, avg, mode);
    }
    
    free(v);
    free(temp);
    return 0;
}
