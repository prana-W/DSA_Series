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
// Go to each node in LL1 and consider that node as target node, now iterate the other LL2, for each node in LL1, to check if it also exists
//. T.C .-> O(n*m)
//. S.C -> O(1)

//* Method - II (Better Solution)
// Iterate LL1 and store all the elements inside a set, now iterate second LL2 and check if the node exists inside the set, if it does, then they surely intersect and return that Node
//. T.C -> O(n + m*log(n)), considering ordered set is used
//. S.C -> O(n), to store the nodes of LL1

//* Method - III (Optimal Solution)
// Iterate thorugh each LL and find the absoulute difference iof the number of nodes and find which LL is longer, let's say LL1 is greater in length than LL2, then keep on iterating the LL1 till it iterates for delta steps, i.e., reach a node of LL1, from which the distance between that node and its tail is same as the total length of LL2, now iterate both the nodes (in LL1 at that node and LL2 from head) one a a time till they meet at a common point (if exists)

//. T.C -> O(max(l1, l2) + abs(l1 - l2) + min(l1, l2)), max() to find the total count of both the LLs and get theri differece (since done simultaneously), abs() to travel the delta portion and min() to travel till the ened
//. S.C -> O(1)
// Utility function to get the difference in lengths of two linked lists
int getDifference(ListNode* head1, ListNode* head2) {
    int len1 = 0, len2 = 0;

    while (head1 || head2) {
        if (head1) {
            len1++;
            head1 = head1->next;
        }
        if (head2) {
            len2++;
            head2 = head2->next;
        }
    }

    return (len1 - len2);  // If negative, length of list2 > length of list1, else vice-versa
}

ListNode* optimalApproach(ListNode* head1, ListNode* head2) {
    int diff = getDifference(head1, head2);
    
    if (diff < 0) 
        while (diff++ != 0) head2 = head2->next;
    else 
        while (diff-- != 0) head1 = head1->next;
    
    // Traverse both lists and compare node by node
    while (head1) {
        if (head1 == head2) return head1;  // Intersection point found
        head2 = head2->next;
        head1 = head1->next;
    }

    return head1;
}

//* Method - IV (Optimal Solution - II)
// See notes

//. T.C -> O(l1 + l2)
//. S.C -> O(1)
ListNode *optimalIIApproach(ListNode *head1, ListNode *head2) {

    ListNode* d1 = head1;
    ListNode* d2 = head2;
    
    // Traverse both lists, when one reaches the end, redirect it to the head of the other list, if no itnersection, they will ionce reach NULL at the same instant, hence making them equal and hence they break
    //! Concept: nullptr == nullptr -> true
    while (d1 != d2) {
        d1 = d1 == NULL ? head2 : d1->next;
        d2 = d2 == NULL ? head1 : d2->next;
    }
    
    return d1; // If they meet, return the intersection node, otherwise NULL (d1 would become NULL if they don't meet)
}