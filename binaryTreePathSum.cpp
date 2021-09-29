//#include "algoheaders.hpp"
#include <iostream>
using namespace std;
// Problem Statement

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(0) {
        val = x;
        left = right = nullptr;
    }
};

bool TreePathSum(TreeNode *root, int S){
    if(root==nullptr) 
        return false;

    if ( S == root->val && root->left == nullptr && root->right == nullptr ) 
        return true;
    return TreePathSum(root->left, S - root->val) || TreePathSum(root->right, S - root->val);
}

int main(void) {
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    cout << "Tree has path: " << TreePathSum(root, 23) << endl;
    cout << "Tree has path: " << TreePathSum(root, 16) << endl;
}