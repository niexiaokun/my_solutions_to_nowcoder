#include <bits/stdc++.h>

using namespace std;

//题目描述
//        给定一个数组arr，返回arr的最长无的重复子串的长度(无重复指的是所有数字都不相同)。
//示例1
//        输入
//
//[2,3,4,5]
//
//返回值
//
//4
//
//示例2
//        输入
//复制
//
//[2,2,3,4,3]
//
//返回值
//
//3
//
//备注:
//
//1≤n≤10^5

class Solution {
public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int> &arr) {
        int n = arr.size();
        int l = 0;
        unordered_set<int> g;
        int res = 0;
        for (int r = 0; r < n; ++r) {
            while (g.count(arr[r])) {
                g.erase(arr[l]);
                ++l;
            }
            g.insert(arr[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

