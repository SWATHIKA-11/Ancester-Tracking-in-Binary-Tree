#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Print all ancestors of the target node (returns 1 if target is found)
int printAncestors(struct Node* root, int target) {
    if (root == NULL)
        return 0;

    if (root->data == target)
        return 1;

    // If target is in left or right subtree, current node is an ancestor
    if (printAncestors(root->left, target) ||
        printAncestors(root->right, target)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

// Free all nodes of the tree
void freeTree(struct Node* root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    /*
          1
         / \
        2   3
       / \
      4   5
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int target;
    printf("Enter the target node to find its ancestors: ");
    scanf("%d", &target);

    printf("Ancestors of node %d are: ", target);
    if (!printAncestors(root, target)) {
        printf("Node not found in the tree.");
    }

    freeTree(root);
    return 0;
}