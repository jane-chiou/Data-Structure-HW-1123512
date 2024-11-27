// 邱涵楨
// 1123512
// 113.11.28
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// define a tree struction named TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}// initialize the pointer
};

// establish a binary tree
TreeNode* buildTree(vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);// establish root node
    queue<TreeNode*> q; // use queue to store nodes
    q.push(root); // let the first value become root node
    int i = 1;

    while (i < values.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // deal with the left child node
        if (i < values.size() && values[i] != -1) {
            curr->left = new TreeNode(values[i]);
            q.push(curr->left);
        }
        i++;

        // deal with the right child node
        if (i < values.size() && values[i] != -1) {
            curr->right = new TreeNode(values[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// use recursion to calculate the diameter of the binary tree
pair<int, int> calculateDiameter(TreeNode* root, int& diameter) {
    if (!root) return make_pair(0, 0); // nullptr return height and diameter are all zero

    pair<int, int> leftResult = calculateDiameter(root->left, diameter);
    pair<int, int> rightResult = calculateDiameter(root->right, diameter);

    int leftHeight = leftResult.first;  // abstract the height of the left subtree
    int rightHeight = rightResult.first; // abstract the height of the right subtree

    // the update diameter is the maximum value of the sum of the heights of the left and right subtrees
    diameter = max(diameter, leftHeight + rightHeight);

    // return the current height and diameter of the node
    return make_pair(1 + max(leftHeight, rightHeight), diameter);
}

int getDiameter(TreeNode* root) {
    int diameter = 0;
    calculateDiameter(root, diameter);
    return diameter;
}

int main() {
    vector<int> values;
    int val;
    while (cin >> val) {
        values.push_back(val);
        if (cin.peek() == '\n') break; // stop the input by press the enter button
    }

    TreeNode* root = buildTree(values);
    int diameter = getDiameter(root);

    cout << diameter << endl;
    return 0;
}