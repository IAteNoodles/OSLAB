#include <stdio.h>
#include <stdlib.h>
 
int n, a[20][20], visited1[20], visited2[20], source;
 
void read_data() {
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}
 
void print_data(int visited[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("\nVertex %d is not reachable\n", i);
        } else {
            printf("\nVertex %d is reachable\n", i);
        }
    }
}
 
void BFS() {
    int f = 0, r = 0, q[20], i, j;
    q[r] = source;
    visited1[source] = 1;
    printf("\nBFS Traversal: ");
    while (f <= r) {
        i = q[f++];
        printf("--%d--", i);
        for (j = 0; j < n; j++) {
            if (a[i][j] == 1 && visited1[j] == 0) {
                visited1[j] = 1;
                q[++r] = j;
            }
        }
    }
    printf("\n");
}
 
void DFS(int src, int *cnt) {
    int j;
    printf("--%d--", src);
    visited2[src] = 1;
    for (j = 0; j < n; j++) {
        if (a[src][j] == 1 && visited2[j] == 0) {
            (*cnt)++;
            DFS(j, cnt);
        }
    }
}
 
int main() {
    int i, choice, connected_count;
    read_data();
    while (1) {
        printf("\n1. BFS\n2. DFS\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                for (i = 0; i < n; i++) {
                    visited1[i] = 0;
                }
                scanf("%d", &source);
                BFS();
                print_data(visited1);
                break;
 
            case 2:
                for (i = 0; i < n; i++) {
                    visited2[i] = 0;
                }
                scanf("%d", &source);
                connected_count = 0;
                printf("\nDFS Traversal: ");
                DFS(source, &connected_count);
                printf("\n");
                print_data(visited2);
                if (connected_count == n - 1) {
                    printf("The graph is connected\n");
                } else {
                    printf("The graph is not connected\n");
                }
                break;
 
            case 3:
                exit(0);
 
            default:
                printf("\nEnter a proper choice\n");
        }
    }
    return 0;
}
