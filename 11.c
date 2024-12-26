#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
 
int n, a[20][20], visited1[20], visited2[20], source;
 
void read_data() {
    int i, j;
    scanf("%d", &n);
=======

int n, a[20][20], visited1[20], visited2[20], source;

void read_data() {
    int i, j;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
>>>>>>> 37406be (Added P)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}
<<<<<<< HEAD
 
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
 
=======

void print_data(int visited[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0)
            printf("\nVertex %d is not reachable", i);
        else
            printf("\nVertex %d is reachable", i);
    }
    printf("\n");
}

>>>>>>> 37406be (Added P)
void BFS() {
    int f = 0, r = 0, q[20], i, j;
    q[r] = source;
    visited1[source] = 1;
<<<<<<< HEAD
    printf("\nBFS Traversal: ");
    while (f <= r) {
        i = q[f++];
        printf("--%d--", i);
=======

    printf("\nBFS Traversal: ");
    while (f <= r) {
        i = q[f++];
        printf("%d ", i);

>>>>>>> 37406be (Added P)
        for (j = 0; j < n; j++) {
            if (a[i][j] == 1 && visited1[j] == 0) {
                visited1[j] = 1;
                q[++r] = j;
            }
        }
    }
    printf("\n");
}
<<<<<<< HEAD
 
void DFS(int src, int *cnt) {
    int j;
    printf("--%d--", src);
    visited2[src] = 1;
=======

void DFS(int src, int *cnt) {
    int j;
    printf("%d ", src);
    visited2[src] = 1;

>>>>>>> 37406be (Added P)
    for (j = 0; j < n; j++) {
        if (a[src][j] == 1 && visited2[j] == 0) {
            (*cnt)++;
            DFS(j, cnt);
        }
    }
}
<<<<<<< HEAD
 
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
=======

int main() {
    int i, choice, count;

    read_data();
    printf("\n\t\t*ADJACENCY MATRIX FOR CITIES HAS BEEN CREATED SUCCESSFULLY*\n");

    while (1) {
        printf("\n1. BFS\n2. DFS\n3. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (i = 0; i < n; i++)
                    visited1[i] = 0;

                printf("Enter the source vertex between 0 to %d: ", n - 1);
                scanf("%d", &source);

                if (source < 0 || source >= n) {
                    printf("Invalid source vertex\n");
                    break;
                }

                BFS();
                print_data(visited1);
                break;

            case 2:
                for (i = 0; i < n; i++)
                    visited2[i] = 0;

                printf("Enter the source vertex between 0 to %d: ", n - 1);
                scanf("%d", &source);

                if (source < 0 || source >= n) {
                    printf("Invalid source vertex\n");
                    break;
                }

                count = 0;
                printf("\nDFS Traversal: ");
                DFS(source, &count);
                printf("\n");

                print_data(visited2);

                if (count == n - 1)
                    printf("The graph is connected\n");
                else
                    printf("The graph is not connected\n");
                break;

            case 3:
                exit(0);

            default:
                printf("\nEnter a valid choice!\n");
        }
    }

>>>>>>> 37406be (Added P)
    return 0;
}
