#include <bits/stdc++.h>
using namespace std;

class ListNode {

    public:
        int data;
        ListNode* next;
        ListNode* back;

    public:
        ListNode (int data1, ListNode* next1, ListNode* back1) {
            data = data1;
            next = next1;
            back = back1;
        }

    public:
        ListNode (int data1) {
            data = data1;
            next = nullptr;
            back = nullptr; 
        }
};

//* Method - I (Brute Force)

// Make a set data structure and keep on adding new Nodes in it. We will iterate in the LL, if there is a cycle, we will find it during the iteration and will hence return from there, else if there is no cycle, we will iterate the entire LL and reach the end, hence returing false

//. T.C -> O(n*log(n))
//. S.C -> O(n)
bool bruteForce(ListNode *head) {

    set<ListNode*>st;

    ListNode* temp = head;

    while(temp) {

        if(st.find(temp) != st.end()) return true;
        st.insert(temp);

        temp = temp->next;
    }

    return false;
        
}

//* Method - II (Optimal Approach)
//! Turtle and Hare Algorithm (Floyd's Cycle Detection)

// we will have a turtle and hare. Hare will be at greater speed than the turtle (here we take 2x speed). If there is no loop, hare will reach the end (nullptr) and hence we return false. If there is a loop, then hare will enter the loop (cycle) first and then turtle. If Hare has 2x speed and Turtle as x speed, then their relative circulation motion speed is x speed. So, it will appear as Turtle is static inside the loop and hare is rotatin by a speed of x. Hence if there is a loop, then it is gurantted they will meet somewhere. Hence if they meet, then there surely would be a loop (cycle) and hence return true

//. T.C -> O(n)
//. S.C -> O(1)
bool optimalApproach(ListNode *head) {

        if(!head || !head->next) return false;

        ListNode* turtle = head;
        ListNode* hare = head;

        while(hare && hare->next) {

            turtle = turtle->next;
            hare = hare->next->next;

            if (turtle == hare) return true;
            
        }
        
        return false;
}