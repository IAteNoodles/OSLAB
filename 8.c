#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct node {
    struct node *prev;
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node *next;
} *first = NULL, *last = NULL, *temp = NULL, *temp2 = NULL;
 
int count = 0;
 
void create() {
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
 
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
 
    temp->prev = temp->next = NULL;
 
    printf("\nEnter ssn, name, department, designation, salary, and phone number of employee: ");
    scanf("%d %s %s %s %f %d", &ssn, name, dept, desg, &sal, &phno);
 
    temp->ssn = ssn;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    temp->phno = phno;
 
    count++;
}
 
void insertbeg() {
    create();
    if (first == NULL) {
        first = last = temp;
    } else {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}
 
void insertend() {
    create();
    if (first == NULL) {
        first = last = temp;
    } else {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}
 
void displaybeg() {
    temp2 = first;
    if (temp2 == NULL) {
        printf("List empty to display\n");
        return;
    }
    printf("\nLinked list elements from beginning:\n");
    while (temp2 != NULL) {
        printf("%d %s %s %s %.2f %d\n", temp2->ssn, temp2->name, temp2->dept, temp2->desg, temp2->sal, temp2->phno);
        temp2 = temp2->next;
    }
    printf("Number of employees = %d\n", count);
}
 
void deleteend() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
 
    if (first == last) {
        printf("%d %s %s %s %.2f %d\n", last->ssn, last->name, last->dept, last->desg, last->sal, last->phno);
        free(last);
        first = last = NULL;
    } else {
        temp2 = last->prev;
        temp2->next = NULL;
        printf("%d %s %s %s %.2f %d\n", last->ssn, last->name, last->dept, last->desg, last->sal, last->phno);
        free(last);
        last = temp2;
    }
    count--;
}
 
void deletebeg() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
 
    temp = first;
    if (first == last) {
        first = last = NULL;
    } else {
        first = first->next;
        first->prev = NULL;
    }
 
    printf("%d %s %s %s %.2f %d\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
    free(temp);
    count--;
}
 
int main() {
    int ch, n, i;
 
    printf("-----------------MENU--------------------\n");
    printf("1 - Create a DLL of n employees\n");
    printf("2 - Display from beginning\n");
    printf("3 - Insert at end\n");
    printf("4 - Delete at end\n");
    printf("5 - Insert at beginning\n");
    printf("6 - Delete at beginning\n");
    printf("7 - Exit\n");
    printf("------------------------------------------\n");
 
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
 
        switch (ch) {
            case 1:
                printf("\nEnter number of employees: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    insertend();
                }
                break;
            case 2:
                displaybeg();
                break;
            case 3:
                insertend();
                break;
            case 4:
                deleteend();
                break;
            case 5:
                insertbeg();
                break;
            case 6:
                deletebeg();
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
 
    return 0;
}