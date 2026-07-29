/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* curr = head;

        while (prev != tail) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return tail;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1)
            return head;

        ListNode* dummy=new ListNode(-1);
        dummy->next = head;

        ListNode* prevGroup = dummy;
        ListNode* start = head;

        while (start) {
            ListNode* end = start;
            int cnt = 1;

            while (cnt < k && end) {
                end = end->next;
                cnt++;
            }

            if (!end)
                break;

            ListNode* nextGroup = end->next;
            ListNode* newHead = reverse(start, end);
            prevGroup->next = newHead;
            start->next = nextGroup;
            prevGroup = start;
            start = nextGroup;
        }

        return dummy->next;
    }
};