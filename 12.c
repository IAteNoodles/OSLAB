#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
 
struct employee {
    int id;
    char name[15];
};
typedef struct employee EMP;
 
EMP emp[MAX];
int a[MAX];
 
int create(int num) {
    return num % MAX;
}
 
int getemp(EMP emp[], int key) {
    scanf("%d", &emp[key].id);
    getchar();
    fgets(emp[key].name, 15, stdin);
    emp[key].name[strcspn(emp[key].name, "\n")] = 0;
    return key;
}
 
void display() {
    int i, ch;
    while (1) {
        printf("\n1. Display All\n2. Filtered Display\n3. Exit");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("\nThe hash table is:\n");
            printf("\nHTKey\tEmpID\tEmpName\n");
            for (i = 0; i < MAX; i++) {
                printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
            }
        } else if (ch == 2) {
            printf("\nFiltered hash table:\n");
            printf("\nHTKey\tEmpID\tEmpName\n");
            for (i = 0; i < MAX; i++) {
                if (a[i] != -1) {
                    printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
                }
            }
        } else if (ch == 3) {
            exit(0);
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }
}
 
void linear_prob(int key, int num) {
    int flag = 0, i, count = 0;
    if (a[key] == -1) {
        a[key] = getemp(emp, key);
    } else {
        for (i = 0; i < MAX; i++) {
            if (a[i] != -1) {
                count++;
            }
        }
        if (count == MAX) {
            printf("\nHash table is full\n");
            display();
            exit(1);
        }
        for (i = key; i < MAX; i++) {
            if (a[i] == -1) {
                a[i] = num;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            for (i = 0; i < key; i++) {
                if (a[i] == -1) {
                    a[i] = num;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) {
            printf("\nCollision avoided successfully using LINEAR PROBING\n");
        }
    }
}
 
void main() {
    int num, key, i;
    int ans = 1;
    printf("\nCollision handling by linear probing: \n");
    for (i = 0; i < MAX; i++) {
        a[i] = -1;
    }
    do {
        scanf("%d", &num);
        key = create(num);
        linear_prob(key, num);
        scanf("%d", &ans);
    } while (ans);
    display();
}
