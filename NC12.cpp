#include <bits/stdc++.h>

using namespace std;

//题目描述
//        输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//        例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

// [1,2,3,4,5,6,7],[3,2,4,1,6,5,7]
// {1,2,5,3,4,6,7}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<int, int> f;

    TreeNode *constructBST(vector<int> &pre, vector<int> &vin, int l1, int r1, int l2, int r2) {
        if (l1 > r1 || l2 > r2)
            return NULL;
        int v = pre[l1];
        int index = f[v];
        TreeNode *root = new TreeNode(v);
        root->left = constructBST(pre, vin, l1 + 1, l1 + index - l2, l2, index - 1);
        root->right = constructBST(pre, vin, l1 + index - l2 + 1, r1, index + 1, r2);
        return root;
    }

public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        int n = pre.size();
        for (int i = 0; i < n; ++i) {
            f[vin[i]] = i;
        }
        return constructBST(pre, vin, 0, n - 1, 0, n - 1);
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

