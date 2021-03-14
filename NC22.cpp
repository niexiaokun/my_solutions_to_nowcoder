#include <bits/stdc++.h>

using namespace std;

//题目描述
//        给出两个有序的整数数组 和 ，请将数组 合并到数组 中，变成一个有序的数组
//        注意：
//可以假设 数组有足够的空间存放 数组的元素， 和 中初始的元素数目分别为 和

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        vector<int> aux(m);
        for (int i = 0; i < m; ++i)
            aux[i] = A[i];
        int i = 0, j = 0;
        for (int k = 0; k < m + n; ++k) {
            if (i >= m)
                A[k] = B[j++];
            else if (j >= n)
                A[k] = aux[i++];
            else if (aux[i] < B[j])
                A[k] = aux[i++];
            else
                A[k] = B[j++];
        }
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

