#include <stdio.h>
#include <stdlib.h>

// Define the TreeNode structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new TreeNode
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode != NULL) {
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to find the kth largest element in the BST
int kthLargest(struct TreeNode* root, int k) {
    TreeNode* curr = root;
    TreeNode* Klargest = NULL;
    int count = 0;
    while (curr != NULL) {
        if (curr->right == NULL) {
            if (++count == k)
                Klargest = curr;
            curr = curr->left;
        }
        else {
            TreeNode* succ = curr->right;
            while (succ->left != NULL && succ->left != curr)
                succ = succ->left;
            if (succ->left == NULL) {
                succ->left = curr;
                curr = curr->right;
            }
            else {
                succ->left = NULL;
                if (++count == k)
                    Klargest = curr;
                curr = curr->left;
            }
        }
    }
    return Klargest->val;
}

// Function to build a BST 
struct TreeNode* buildBST() {
    int val;
    struct TreeNode* root = NULL;

    while (1) {
        scanf("%d", &val);

        if (val == -1) {
            break;
        }

        if (root == NULL) {
            root = createNode(val);
        } else {
            // Insert the value into the BST
            struct TreeNode* current = root;
            while (1) {
                if (val < current->val) {
                    if (current->left == NULL) {
                        current->left = createNode(val);
                        break;
                    }
                    current = current->left;
                } else {
                    if (current->right == NULL) {
                        current->right = createNode(val);
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    return root;
}

// Function to free the memory of the tree
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct TreeNode* root = buildBST();

    int k;
    scanf("%d", &k);

    int kth_largest = kthLargest(root, k);
    printf("%d", kth_largest);

    freeTree(root);

    return 0;
}
