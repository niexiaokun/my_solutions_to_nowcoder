#include <bits/stdc++.h>

using namespace std;


//题目描述
//        判断给定的链表中是否有环。如果有环则返回true，否则返回false。
//你能给出空间复杂度的解法么？


struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)
                return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}

