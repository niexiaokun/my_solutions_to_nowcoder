#include <bits/stdc++.h>

using namespace std;

//题目描述
//        给你一个n（1≤n≤10^5），和一个长度为n的数组，在不同时选位置相邻的两个数的基础上，求该序列的最大子序列和（挑选出的子序列可以为空）。
//示例1
//        输入
//复制
//
//3,[1,2,3]
//
//返回值
//
//4
//
//说明
//
//        有[],[1],[2],[3],[1,3] 4种选取方式其中[1,3]选取最优，答案为4
//
//        示例2
//输入
//
//4,[4,2,3,5]
//
//返回值
//
//9
//
//说明
//
//        其中[4,5]的选取方案是在满足不同时选取相邻位置的数的情况下是最优的答案
//
//        备注:
//
//输入的值在int范围内

//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     * 计算
//     * @param n int整型 数组的长度
//     * @param array int整型vector 长度为n的数组
//     * @return long长整型
//     */
//    long long subsequence(int n, vector<int>& array) {
//        vector<vector<int>> dp(n, vector<int>(2));
//        dp[0][0] = array[0];
//        for(int i = 1; i < n; ++i){
//            dp[i][0] = dp[i-1][1] + array[i];
//            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
//        }
//        return max(dp[n-1][0], dp[n-1][1]);
//    }
//};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算
     * @param n int整型 数组的长度
     * @param array int整型vector 长度为n的数组
     * @return long长整型
     */
    long long subsequence(int n, vector<int>& array) {
        int a = array[0];
        int b = 0;
        int tmp;
        for(int i = 1; i < n; ++i){
            tmp = a;
            a = b + array[i];
            b = max(tmp, b);
        }
        return max(a, b);
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

