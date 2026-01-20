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
// Iterate both the LLs simulatenously, if we reach the end of one LL and the other LL still ahs some remining nodes, then keep on adding new Nodes with the value 0, to the shorter LL. This is so we can add both and the final result doesn't effect
// Now both have the same size at the end, now simply add them node-by-node and carry-on the carry 

//. T.C -> O(2*max(l1, l2))
//. S.C -> O(abs(l1-l2)), new Nodes are created to match the length of the larger LL
ListNode* optimalApproach(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* prev1 = nullptr;

        ListNode* temp2 = l2;
        ListNode* prev2 = nullptr;

        while(temp1 && temp2) {
            if(temp2->next && !temp1->next) {
                temp1->next = new ListNode(0);
            }
            else if (temp1->next && !temp2->next) {
                temp2->next = new ListNode(0);
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        temp1 = l1;
        temp2 = l2;

        int carry = 0;

        while(temp1 && temp2) {
            int sum = temp1->val + temp2->val + carry;

            temp1->val = sum%10;

            carry = sum/10;            

            if(temp1->next) temp1 = temp1->next;
            else break;

            temp2 = temp2->next;
        }

        if (carry) {
            ListNode* newNode = new ListNode(carry);

            temp1->next = newNode;
        }

        return l1;
        
}