#include <stdio.h>

int main() {
    int n = 5; // Number of processes
    int m = 3; // Number of resources
    int i, j, k;

    // Allocation Matrix
    int alloc[5][3] = {
        {0, 1, 0}, // P0
        {2, 0, 0}, // P1
        {3, 0, 2}, // P2
        {2, 1, 1}, // P3
        {0, 0, 2}  // P4
    };

    // Maximum Requirement Matrix
    int max[5][3] = {
        {7, 5, 3}, // P0
        {3, 2, 2}, // P1
        {9, 0, 2}, // P2
        {2, 2, 2}, // P3
        {4, 3, 3}  // P4
    };

    // Available Resources
    int avail[3] = {3, 3, 2};

    int f[n], ans[n], ind = 0;
    int need[n][m];

    // Initialize finish array to 0
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    // Calculate the Need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Banker's Algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) { // If the process is not finished
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) { // If the process can be safely executed
                    ans[ind++] = i;
                    for (j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                    f[i] = 1; // Mark the process as finished
                }
            }
        }
    }

    // Check if the system is in a safe state
    int flag = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) { // If any process is not finished
            flag = 0;
            printf("The following system is not safe\n");
            break;
        }
    }

    // If the system is safe, print the safe sequence
    if (flag == 1) {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++) {
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d\n", ans[n - 1]);
    }

    return 0;
}
