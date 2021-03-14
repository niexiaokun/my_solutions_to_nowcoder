#include <bits/stdc++.h>

using namespace std;

//题目描述
//
//        有一个整数数组，请你根据快速排序的思路，找出数组中第K大的数。
//
//给定一个整数数组a,同时给定它的大小n和要找的K(K在1到n之间)，请返回第K大的数，保证答案存在。
//示例1
//        输入
//
//[1,3,5,2,2],5,3
//
//返回值
//
//2



class Solution {
private:
    int findk(vector<int> &a, int l, int r, int k) {
        while (l <= r) {
            swap(a[l], a[rand() % (r - l + 1) + l]);
            int v = a[l];
            int i = l + 1, j = r;
            while (true) {
                while (i <= r && a[i] > v) ++i;
                while (j > l && a[j] < v) --j;
                if (i >= j)
                    break;
                swap(a[i], a[j]);
                ++i, --j;
            }
            swap(a[j], a[l]);
            if (j + 1 == k)
                return a[j];
            else if (j + 1 < k)
                l = j + 1;
            else
                r = j - 1;
        }
        return -1;
    }

public:
    int findKth(vector<int> a, int n, int K) {
        srand(time(nullptr));
        return findk(a, 0, n - 1, K);
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

