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
// Iterate and store all the elments in a set, whenever a ListNode is repeated, return that instantly as that is our head of the Loop.

//. T.C -> O(n*log(x))
//. S.C -> O(n)
ListNode *bruteForce(ListNode *head) {

        set<ListNode*>st;

        ListNode* temp = head;

        while(temp) {
            if (st.find(temp) != st.end()) {
                return temp;
            }

            st.insert(temp);
            temp = temp->next;
        }

        return nullptr;
        
}

//* Method - II (Optimal Approach)
// See notes
// When turtle and hare meet, they are (n-m) into the loop. If we put turtle back into head and move both turtle and hare @ the same speed of x, they would again meet at a point and that would be the starting node of the cycle

//. T.C -> O(n)
//. S.C -> O(1)
ListNode *optimalApproach(ListNode *head) {

        if (!head) return nullptr;

        ListNode* turtle = head;
        ListNode* hare = head;

        while(hare && hare->next) {
        
            // Move turtle @ x speed and hare @ 2x speed
            turtle = turtle->next;
            hare = hare->next->next;

            if(turtle == hare) {
                turtle = head;

                // Move both turtle and hare with the same speed
                while(turtle != hare) {
                    turtle = turtle->next;
                    hare = hare->next;
                }

                // turtle and hare meet
                return turtle;
            }

        }

        return nullptr;
        
}