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

//* Method - I (Brute Force)
// Store the nodes in an array and whenever we get to kth index, reverse the last k nodes in the array and at the end rewire the enitre nodes

//. T.C -> O(3n), O(n) for iteration, O(n) for reversing, O(n) for rewiring
//. S.C -> o(n), for storing in the array
ListNode* bruteForce(ListNode* head, int k) {

        vector<ListNode*>arr;
        ListNode* temp = head;

        ListNode* ans = nullptr;

        int i = 0;
        while(temp) {

            arr.push_back(temp);
            i++;

            // If it is kth node, reverse the last k nodes
            if (i%k == 0) reverse(arr.begin()+(i-k), arr.begin()+i);

            // To store the head of the final answer
            if (i == k) ans = temp;

            temp = temp->next;

        }

        temp = ans;

        // Rewiring the entire LL from the nodes
        for (int i = 1; i < arr.size(); i++) {
            temp->next = arr[i];
            temp = arr[i];
        }

        temp->next = nullptr;

        return ans;
        
}

//* Method - II (Optimal Approach)