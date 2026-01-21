#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
        int data;
        Node* next;
        Node* back;

    public:
        Node (int data1, Node* next1, Node* back1) {
            data = data1;
            next = next1;
            back = back1;
        }

    public:
        Node (int data1) {
            data = data1;
            next = nullptr;
            back = nullptr; 
        }
};

//* Method - I (Optimal Solution)

//. T.C -> O(n)
//. S.C -> O(1), no extra space apart from returning the answer
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        
        Node* tail = head;
        
        while(tail->next) {
            tail = tail->next;
        }
        
        vector<pair<int, int>>ans;
        
        Node* low = head;
        Node* high = tail;
        
        //! In condition, we check that low and high are not the same node and also low->back isn't equal to high (when both pass each other)
        while(low != high && low->back != high) {
            int sum = ((low->data) + (high->data));
            
            if (sum < target) low = low->next;
            else if (sum > target) high = high->back;
            else {
                ans.emplace_back(low->data, high->data);
                low = low->next;
                high = high->back;
            }
        }
        
        return ans;
        
}