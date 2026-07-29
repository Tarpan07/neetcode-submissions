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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int rem=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(temp1 && temp2){
            int data1= temp1->val;
            int data2=temp2->val;
            ListNode* newNode= new ListNode((data1+data2+rem)%10);
            rem=(data1+data2+rem)/10;
            temp->next=newNode;
            temp=temp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            int sum = rem + temp1->val;
            ListNode* newNode = new ListNode(sum % 10);
            rem = sum / 10;
            temp->next=newNode;
            temp=temp->next;
            temp1=temp1->next;
        }
        while(temp2){
            int sum = rem + temp2->val;
            ListNode* newNode = new ListNode(sum % 10);
            rem = sum / 10;
            temp->next=newNode;
            temp=temp->next;
            temp2= temp2->next;
        }
        if(rem){
            ListNode * newNode= new ListNode(1);
            temp->next=newNode;
        }
        return dummy->next;
    }
};
