#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(0) {
        val = x;
        left = right = nullptr;
    }
};
/*
Given a binary tree, populate an array to represent its level-by-level traversal. 
You should populate the values of all nodes of each level from left to right in separate sub-arrays.
queue.front()
queue.pop()
queue.push()
*/

vector<vector<int>> levelOrderTraversal(TreeNode *root){
    queue<TreeNode *> q;
    vector<vector<int>> arr;

    q.push(root);

    while(!q.empty()){
        vector<int> currentLevel;
        int size = q.size();
        for(int i = 0; i<size; i++){
            TreeNode * node = q.front();
            currentLevel.push_back(node->val);
            q.pop();

            if(node->left!=nullptr)
                q.push(node->left);
            if(node->right!=nullptr)
                q.push(node->right);
        }
        arr.push_back(currentLevel);
    }
    return arr;
}

int main(void) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<vector<int>> result = levelOrderTraversal(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}