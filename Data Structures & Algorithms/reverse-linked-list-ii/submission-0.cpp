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
public:
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* leftPrev = &dummy;
        for (int i = 1; i < left; i++)
            leftPrev = leftPrev->next;

        ListNode* start = leftPrev->next;
        ListNode* end = start;
        for (int i = left; i < right; i++)
            end = end->next;

        ListNode* rightNext = end->next;
        end->next = nullptr;

        ListNode* reversedHead = reverse(start);
        leftPrev->next = reversedHead;
        start->next = rightNext;

        return dummy.next;
    }
};