// Including necessary libraries
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Using standard namespace and chrono namespace
using namespace std;
using namespace std::chrono;

// Node structure for Binary Search Tree
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node *newNode(int item) {
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with given key in BST
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

// Function to build balanced BST from sorted array
struct Node* buildBalancedBST(int nums[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct Node *root = newNode(nums[mid]);

    root->left = buildBalancedBST(nums, start, mid - 1);
    root->right = buildBalancedBST(nums, mid + 1, end);

    return root;
}

// Function to do inorder traversal of BST
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Function to do preorder traversal of BST
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to check if a number is unique in an array
bool isUnique(int nums[], int num, int size) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == num) {
            return false;
        }
    }
    return true;
}

// Main function
int main() {
    srand(time(0));
    int n;
    
    // Loop to run the program 3 times
    for(int i = 0; i < 3; i++){
        cout << "Enter the size of the tree: ";
        cin >> n;

        // Generate n unique random numbers
        int* nums = new int[n];
        for (int i = 0; i < n; i++) {
            int num;
            do {
                num = rand() % n + 1;
            } while (!isUnique(nums, num, i));
            nums[i] = num;
        }

        // Best case: balanced BST
        sort(nums, nums + n);
        auto start = high_resolution_clock::now();
        struct Node *root = buildBalancedBST(nums, 0, n - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Best case execution time: " << duration.count() << " microseconds" << endl;
        preOrder(root);
        cout << "\n";

        // Average case:
        random_shuffle(nums, nums + n);
        start = high_resolution_clock::now();
        root = NULL;
        for(int i = 0; i < n; i++) {
            root = insert(root, nums[i]);
        }
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Average case execution time: " << duration.count() << " microseconds" << endl;
        preOrder(root);
        cout << "\n";

        // Worst case: skewed tree
        sort(nums, nums + n, greater<int>());
        start = high_resolution_clock::now();
        root = NULL;
        for(int i = 0; i < n; i++) {
            root = insert(root, nums[i]);
        }
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Worst case execution time: " << duration.count() << " microseconds" << endl;
        inorder(root);
        cout << "\n";

        delete[] nums;
        cout<<"----------------------------------------------------------------------------------\n\n";
    }
    return 0;
}

