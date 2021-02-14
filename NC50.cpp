#include <bits/stdc++.h>

using namespace std;

//题目描述
//        将给出的链表中的节点每 k\ k k 个一组翻转，返回翻转后的链表
//        如果链表中的节点数不是 k\ k k 的倍数，将最后剩下的节点保持原样
//        你不能更改节点中的值，只能更改节点本身。
//要求空间复杂度  O(1)\ O(1) O(1)
//例如：
//给定的链表是1→2→3→4→51\to2\to3\to4\to51→2→3→4→5
//对于  k=2\ k = 2 k=2, 你应该返回 2→1→4→3→52\to 1\to 4\to 3\to 52→1→4→3→5
//对于  k=3\ k = 3 k=3, 你应该返回 3→2→1→4→53\to2 \to1 \to 4\to 53→2→1→4→5

// {1,2,3,4,5},2
// {2,1,4,3,5}

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

//class Solution {
//private:
//    pair<ListNode *, ListNode *> reverseList(ListNode *head) {
//        ListNode *pre = NULL;
//        ListNode *cur = head;
//        ListNode *next;
//        while (cur != NULL) {
//            next = cur->next;
//            cur->next = pre;
//            pre = cur;
//            cur = next;
//        }
//        return make_pair(pre, head);
//    }
//
//public:
//    /**
//     *
//     * @param head ListNode类
//     * @param k int整型
//     * @return ListNode类
//     */
//    ListNode *reverseKGroup(ListNode *head, int k) {
//        if (head == NULL || head->next == NULL || k == 1)
//            return head;
//        ListNode *hair = new ListNode(0);
//        hair->next = head;
//        ListNode *p = hair;
//        int i = 1;
//        ListNode *p1 = head, *p2 = head, *p3;
//        while (p2) {
//            p2 = p2->next;
//            if (p2 == NULL)
//                break;
//            ++i;
//            if (i % k == 0) {
//                p->next = NULL;
//                p3 = p2->next;
//                p2->next = NULL;
//                tie(p1, p2) = reverseList(p1);
//                p->next = p1;
//                p2->next = p3;
//                p = p2;
//                p1 = p2 = p3;
//                ++i;
//            }
//        }
//        return hair->next;
//    }
//};

class Solution {
private:
    ListNode *reverseList(ListNode *head, int k) {
        ListNode *tail = head;
        int i = 1;
        while (i < k && tail) {
            tail = tail->next;
            ++i;
        }
        if (tail == NULL)
            return head;
        tail = tail->next;
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *next;
        while (cur != tail) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = reverseList(tail, k);
        return pre;
    }

public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k == 1)
            return head;
        return reverseList(head, k);
    }
};

int main(int argc, char* argv[]) {

    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    int k = 2;
    Solution().reverseKGroup(head, k);

    return 0;
}

