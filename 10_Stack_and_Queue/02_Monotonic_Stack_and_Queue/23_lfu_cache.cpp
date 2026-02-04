#include <bits/stdc++.h>
using namespace std;

// Initialise two unordered map. One for key and the Node (similar to the LRU, only here the Node also contains the freq of that Node) and one for freq and Doubly-Linked List for that freq group.

// Inside the updateFreqMap function, we take the initial freq of the node and remove the node from freqMap if exists, we also update the minFreq just incase the current minFreq group becomes zero. Then, we increase the freq of the given node and add it to new freq group using LRU method

// Whenever we do a get, first update the freqMap and then return the value.

// Whenever we do a put, if the key exists, then just update the mp and freqMap maps and return. If size of the cache has hit the max, then delete the LRU node from the LFU cache, remove the ndoe from freqMap and also from mp and decrease the currSize. After deletion or if we want to insert a new element (when size hasn't reached), just create a new node, udpate the freqMap and mp and increase the currSize, also update the minFreq back to 1


//. T.C -> O(1) for all operations in average cases
class LFUCache {
public:

    // Indivisual Nodes
    class Node {

        public:

        int key;
        int val;
        int freq; // initialised to 0 when created a new node (as now updated till the node is added in a DLL)
        
        Node* next;
        Node* prev;

        Node(int key1, int val1) {

            key = key1;
            val = val1;
            freq = 0;
            next = nullptr;
            prev = nullptr;

        }
    };

    // Doubly Linked List (head, tail, size)
    class List {

        public:

        int size;
        Node* head;
        Node* tail;

        List() {

            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            
            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        void insertNodeAfterHead(Node* node) {

            Node* front = head->next;
            Node* previous = head;

            node->next = front;
            node->prev = previous;

            front->prev = node;
            previous->next = node;

            size++;
        }

        void removeNode(Node* node) {
            Node* front = node->next;
            Node* previous = node->prev;

            previous->next = front;
            front->prev = previous;

            node->next = nullptr;
            node->prev = nullptr;

            size--;
        }
    };

    int maxSize;
    int currSize;

    // Minimum Frequency that has some non-dummy nodes in it
    int minFreq;

    unordered_map<int, List*>freqMap;
    unordered_map<int, Node*>mp;

    LFUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
        minFreq = 0;
    }

    // Updated whenever a node is get or put
    // This is used to update the freqMap map for a new node.
    void updateFreqMap(Node* node) {

        // Initial freq of a node (if node is new, it will be zero)
        int freq = node->freq;

        // If DLL exists for the frew, then remove the node from that DLL (as we remove it from here)
        if (freqMap.find(freq) != freqMap.end()) {
            freqMap[freq]->removeNode(node);

            // If freq of the node is same as minFreq and after removing the node from the DLL, the size becomes 0, then the node gets inserted later in the next freq layer (hence the minFreq increases)
            if (freq == minFreq && freqMap[minFreq]->size == 0) {
    minFreq++;
}

        }

        // Frequency increases (as we are updating)
        freq++;

        // If no DLL for the freq, create one
        if (freqMap.find(freq) == freqMap.end()) {
            freqMap[freq] = new List();
        }

        // Updated the freq in node
        node->freq = freq;

        // Insert the node after the dummy head of the DLL of that freq (Similar to LRU concept)
        freqMap[freq]->insertNodeAfterHead(node);

    }
    
    int get(int key) {

        if (mp.find(key) == mp.end()) return -1;

        // Simply update for the node
        updateFreqMap(mp[key]);

        return mp[key]->val;
        
    }
    
    void put(int key, int value) {

        // If exists, just update the value and the freqMap
        if (mp.find(key) != mp.end()) {

            mp[key]->val = value;
            updateFreqMap(mp[key]);

            return;
        }

        // If size is full and new nodes is needed to insert
        else if (currSize == maxSize) {

            // This is the LFU Key that needs to be evicted
            Node* lfuKey = freqMap[minFreq]->tail->prev;

            // Remove from the freqMap
            freqMap[minFreq]->removeNode(lfuKey);
            // Remove from the map
            mp.erase(lfuKey->key);
            // Decrese the currSize
            currSize--;

        }

        Node* newNode = new Node(key, value);

        // Update the freqMap and mp
        updateFreqMap(newNode);
        mp[key] = newNode;

        // Increase size
        currSize++;

        // Update the minFreq back to 1 when a new node is added
        minFreq = 1; 
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */