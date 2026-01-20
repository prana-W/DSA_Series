#include <bits/stdc++.h>
using namespace std;

class ListNode {

    public:
        int val;
        ListNode* next;
        ListNode* back;

    public:
        ListNode (int data1, ListNode* next1, ListNode* back1) {
            val = data1;
            next = next1;
            back = back1;
        }

    public:
        ListNode (int data1) {
            val = data1;
            next = nullptr;
            back = nullptr; 
        }
};

//* Method - I (Optimal Approach)
// We iterate both the LL simulateneoulsy adn include the val if that node exists, else we don't. Keep on doing it and adding the answer to a new LL (this is to avoid modifying the input LL)

//. T.C -> O(max(l1, l2))
//. S.C -> O(max(l1, l2)), this is return the answer
ListNode* optimalApproach(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        int carry = 0;

        while(temp1 || temp2) {

            int sum = carry;

            if (temp1) sum += temp1->val;
            if (temp2) sum += temp2->val;

            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;

            carry = sum/10;            

            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }

        if (carry) {
            ListNode* newNode = new ListNode(carry);

            curr->next = newNode;
        }

        return dummy->next;
        
}