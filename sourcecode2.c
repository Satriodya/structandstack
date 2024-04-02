#include <stdio.h>
#include <stdlib.h>

int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
    int sum = 0;
    int count = 0;
    int maxCount = 0;
    int i = 0, j = 0;

    while (i < a_count && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
        count++;
    }

    maxCount = count;

    while (j < b_count && i >= 0) {
        sum += b[j];
        j++;

        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
        }

        if (sum <= maxSum && i + j > maxCount) {
            maxCount = i + j;
        }
    }

    return maxCount;
}

int main() {
    int g;
    scanf("%d", &g);

    for (int g_itr = 0; g_itr < g; g_itr++) {
  
        int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);

        int* a = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int* b = malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        int result = twoStacks(maxSum, n, a, m, b);

        printf("%d\n", result);

        free(a);
        free(b);
    }

    return 0;
}
