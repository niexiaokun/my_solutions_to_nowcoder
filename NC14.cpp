#include <bits/stdc++.h>

using namespace std;

//题目描述
//        给定一个二叉树，返回该二叉树的之字形层序遍历，（第一层从左向右，下一层从右向左，一直这样交替）
//例如：
//给定的二叉树是{3,9,20,#,#,15,7},
//
//该二叉树之字形层序遍历的结果是
//
//[
//[3],
//[20,9],
//[15,7]
//]
//
//示例1
//        输入
//
//{1,#,2}
//
//返回值
//
//[[1],[2]]


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        deque<TreeNode *> dq;
        dq.emplace_back(root);
        int a = 1;
        while (!dq.empty()) {
            vector<int> tmp;
            if (a) {
                for (int i = dq.size(); i > 0; --i) {
                    TreeNode *cur = dq.back();
                    tmp.emplace_back(cur->val);
                    dq.pop_back();
                    if (cur->left)
                        dq.emplace_front(cur->left);
                    if (cur->right)
                        dq.emplace_front(cur->right);
                }
            } else {
                for (int i = dq.size(); i > 0; --i) {
                    TreeNode *cur = dq.front();
                    tmp.emplace_back(cur->val);
                    dq.pop_front();
                    if (cur->right)
                        dq.emplace_back(cur->right);
                    if (cur->left)
                        dq.emplace_back(cur->left);
                }
            }
            res.push_back(tmp);
            a = 1 - a;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

