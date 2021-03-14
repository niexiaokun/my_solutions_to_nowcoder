#include <bits/stdc++.h>

using namespace std;

//题目描述
//        给定一个数组，找出其中最小的K个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。如果K>数组的长度，那么返回一个空的数组
//        示例1
//输入
//
//[4,5,1,6,2,7,3,8],4
//
//返回值
//
//[1,2,3,4]



class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int n = input.size();
        if (k == 0 || k > n)
            return {};
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i)
            pq.emplace(input[i]);
        for (int i = k; i < n; ++i) {
            if (input[i] < pq.top()) {
                pq.pop();
                pq.emplace(input[i]);
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.emplace_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

