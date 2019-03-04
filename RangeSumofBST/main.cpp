//LeetCode.com Problem
//ID 938
//
//Description
// Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
// The binary search tree is guaranteed to have unique values.

//The two functions should work if you send a Binary Tree
#include <iostream>

using namespace std;

 int rangeSumBST(TreeNode* root, int L, int R) {
        int ans;
        ans = TreeSum(root,L,R);
        return ans;
    }

    int TreeSum(TreeNode* node, int L, int R){
        queue <TreeNode*> myQueue;
        int iSum = 0;
        if(node != NULL){
            myQueue.push(node);
            TreeNode *aux;
            while(!myQueue.empty()){
               aux = myQueue.front();
                myQueue.pop();
                if(aux->val >= L && aux->val <= R){
                    iSum = iSum + aux->val;
                }
                if(aux->left != NULL){
                    myQueue.push(aux->left);
                }
                if(aux->right != NULL){
                    myQueue.push(aux->right);
                }
            }

        }
        return iSum;
    }



