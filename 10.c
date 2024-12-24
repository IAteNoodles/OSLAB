#include <stdio.h>
#include <stdlib.h>
 
struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST NODE;
 
NODE* createtree(NODE *root, int data) {
    if (root == NULL) {
        NODE *temp;
        temp = (NODE*) malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < root->data)
        root->left = createtree(root->left, data);
    else if (data > root->data)
        root->right = createtree(root->right, data);
    return root;
}
 
void inorder(NODE *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
 
void preorder(NODE *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
 
void postorder(NODE *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}
 
NODE *search(NODE *root, int data) {
    if (root == NULL) {
        printf("\nElement not found\n");
        return NULL;
    }
    if (data < root->data)
        return search(root->left, data);
    else if (data > root->data)
        return search(root->right, data);
    else {
        printf("\nElement found: %d\n", root->data);
        return root;
    }
}
 
int main() {
    int data, ch, i, n;
    NODE *root = NULL;
 
    while (1) {
        printf("\n1. Create Binary Search Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
 
        switch (ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("\nEnter the elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = createtree(root, data);
                }
                break;
 
            case 2:
                printf("\nInorder Traversal:\n");
                inorder(root);
                printf("\n");
                break;
 
            case 3:
                printf("\nPreorder Traversal:\n");
                preorder(root);
                printf("\n");
                break;
 
            case 4:
                printf("\nPostorder Traversal:\n");
                postorder(root);
                printf("\n");
                break;
 
            case 5:
                printf("\nEnter the element to search: ");
                scanf("%d", &data);
                search(root, data);
                break;
 
            case 6:
                exit(0);
 
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}