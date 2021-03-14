#include <bits/stdc++.h>

using namespace std;

//题目描述
//        假设你有一个数组，其中第 i\ i i 个元素是股票在第 i\ i i 天的价格。
//你有一次买入和卖出的机会。（只有买入了股票以后才能卖出）。请你设计一个算法来计算可以获得的最大收益。
//示例1
//        输入
//复制
//
//[1,4,2]
//
//返回值
//
//3
//
//示例2
//        输入
//
//[2,4,1]
//
//返回值
//
//2


class Solution {
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> dp(n);
        dp[0] = prices[0];
        for (int i = 1; i < n; ++i)
            dp[i] = min(dp[i - 1], prices[i]);
        int x = INT_MIN;
        int res = 0;
        for (int i = n - 1; i > 0; --i) {
            x = max(x, prices[i]);
            res = max(res, x - dp[i - 1]);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

