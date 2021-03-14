#include <bits/stdc++.h>

using namespace std;

//题目描述
//        分别按照二叉树先序，中序和后序打印所有的节点。
//示例1
//        输入
//
//{1,2,3}
//
//返回值
//
//[[1,2,3],[2,1,3],[2,3,1]]
//
//备注:
//
//n≤10^6


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


class Solution {
private:
    vector<int> tmp;

    void dfs(TreeNode *root) {
        if (root) {
            tmp.emplace_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }
    }

    void dfs2(TreeNode *root) {
        if (root) {
            dfs2(root->left);
            tmp.emplace_back(root->val);
            dfs2(root->right);
        }
    }

    void dfs3(TreeNode *root) {
        if (root) {
            dfs3(root->left);
            dfs3(root->right);
            tmp.emplace_back(root->val);
        }
    }

public:
    /**
     *
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > threeOrders(TreeNode *root) {
        vector<vector<int>> res;
        dfs(root);
        res.push_back(tmp);
        tmp.clear();
        dfs2(root);
        res.push_back(tmp);
        tmp.clear();
        dfs3(root);
        res.push_back(tmp);
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

