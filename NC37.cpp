#include <bits/stdc++.h>

using namespace std;

//题目描述
//        给出一组区间，请合并所有重叠的区间。
//示例1
//        输入
//复制
//
//[[10,30],[20,60],[80,100],[150,180]]
//
//返回值
//
//[[10,60],[80,100],[150,180]]


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        int n = intervals.size();
        if(n == 0)
            return res;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            if(a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        });
        Interval x = intervals[0];
        for(int i = 1; i < n; ++i){
            if(x.end >= intervals[i].start){
                x.end = max(x.end, intervals[i].end);
            }else{
                res.emplace_back(x);
                x = intervals[i];
            }
        }
        res.emplace_back(x);
        return res;
    }
};


int main(int argc, char* argv[]) {

    return 0;
}

