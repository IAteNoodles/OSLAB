#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define max_size 5

int stack[max_size], top = -1, item;

void push() {
    if(top == (max_size - 1)) {
        printf("\nStack Overflow:");
    } else {
        printf("Enter the element to be inserted:\t");
        scanf("%d", &item);
        top = top + 1;
        stack[top] = item;
    }
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow:");
    } else {
        item = stack[top];
        top = top - 1;
        printf("\nThe popped element: %d\t", item);
    }
}

void pali() {
    int num = 0, temp, digit, revnum = 0, k = 0;
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    } else {
        while(top != -1) {
            pop();
            num = num * 10 + item;
            revnum = item * pow(10, k) + revnum;
            k = k + 1;
        }
        printf("\nReverse Number of %d is: %d\n", num, revnum);
        if(num == revnum)
            printf("The stack contains a Palindrome number\n");
        else
            printf("The stack does not contain a Palindrome number\n");
    }
}

void display() {
    int i;
    if(top == -1) {
        printf("\nStack is Empty:");
    } else {
        printf("\nThe stack elements are:\n");
        for(i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice = 1;
    while(choice) {
        printf("\n\n--------STACK OPERATIONS-----------\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Palindrome\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("-----------------------");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                pali();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice:\n");
                break;
        }
    }
    return 0;
}
