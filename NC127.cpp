#include <bits/stdc++.h>

using namespace std;

//题目描述
//        给定两个字符串str1和str2,输出两个字符串的最长公共子串
//题目保证str1和str2的最长公共子串存在且唯一。
//示例1
//        输入
//
//"1AB2345CD","12345EF"
//
//返回值
//
//"2345"
//
//备注:
//
//1≤∣str1∣,∣str2∣≤5000

class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        int len = 0;
        int l = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(str1[i] == str2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    if(dp[i+1][j+1] > len){
                        len = dp[i+1][j+1];
                        l = i - len + 1;
                    }
                }
            }
        }
        return str1.substr(l, len);
    }
};

int main(int argc, char* argv[]) {

    string s1 = "1AB2345CD";
    string s2 = "12345EF";

    cout << Solution().LCS(s1, s2) << endl;

    s1 = "2LQ74WK8Ld0x7d8FP8l61pD7Wsz1E9xOMp920hM948eGjL9Kb5KJt80";
    s2 = "U08U29zzuodz16CBZ8xfpmmn5SKD80smJbK83F2T37JRqYfE76vh6hrE451uFQ100ye9hog1Y52LDk0L52SuD948eGjLz0htzd5YF9J1Y6oI7562z4T2";

    cout << Solution().LCS(s1, s2) << endl;

    return 0;
}

