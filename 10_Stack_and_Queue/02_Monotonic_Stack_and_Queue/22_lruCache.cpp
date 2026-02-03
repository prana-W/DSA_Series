#include <bits/stdc++.h>
using namespace std;

// Use DLL to keep track of timing of the cache. Most recent is after the dummy head and least recently used is before the dummy tail

// Whenever we try to get any valu, update the Node position and then return

// If we are simply updating the value in put, just update the Node, else if the size is full, delete the LRY key (before tail), when adding, make a new Node, insert it after the head and also add it to the map

//. T.C -> O(1), all operations take O(1) in average time due to unordered_map
class LRUCache {
public:
    // Initialising a Node (modified) class
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key1, int val1) {
            key = key1;
            val = val1;
        }
    };

    int size;
    Node* head = new Node(-1, -1); // dummy head
    Node* tail = new Node(-1, -1); // dummy tail

    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        size = capacity;

        head->next = tail;
        tail->prev = head;
    }

    // Takes a node and inserts it after the dummy head
    void insertAfterHead(Node* node) {

        node->next = head->next;
        node->next->prev = node;

        head->next = node;
        node->prev = head;
    }

    // Removes the Node from a position (doesn't free the memory)
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    //! Returns the value from a key
    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        // Adds the Node after the head, as it is used
        Node* node = mp[key];
        removeNode(node);
        insertAfterHead(node);

        return node->val;
    }

    void put(int key, int value) {

        // When the key already exists, just update the DLL and the value of the node
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            removeNode(node);
            insertAfterHead(node);

            node->val = value;

            return;
        } 
        // When the cache is full, delete the LRU node, the node before the dummy tail (also free the memory)
        else if (mp.size() == size) {
            // Removing LRU Key
            Node* lruNode = tail->prev;
            mp.erase(lruNode->key);
            removeNode(lruNode);
            delete (lruNode);
        }

        // Make a new Node and add it to map and DLL
        // Adding new Key
        Node* newNode = new Node(key, value);
        insertAfterHead(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */