#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//* similar to stack but FIFO --> First in First Out
//. O(1) --> all happens in constant time

void explainQueue() {
  queue<int> q;
  q.push(1);    //{1}
  q.push(2);    // {1,2}
  q.emplace(4); // {1,2,4}

  q.back() += 5;    // 9 --> here back will mean 4
  cout << q.back(); // prints last element 9

  // Q is {1,2,9}
  cout << q.front(); // prints 1

  q.pop(); // {2,9} --> deletes the front one

  cout << q.front(); // prints 2

  // size swap empty same as stack
}

// ** Priority Queue **

//. push --> O(log n)
//. top --> O(1)
//. pop --> O(log n)

void explainPQ() {

 //! Maximum Heap
 // the element stays in a descending order inside it (or lexically dedcreasing in case of strings)

  priority_queue<int> pq;

  pq.push(5);     // {5}
  pq.push(2);     // {5,2}
  pq.push(8);     // {8,5,2}
  pq.emplace(10); // {10,8,5,2}

  cout << pq.top(); // prints 10

  pq.pop(); // {8,5,2} --> 10 poped (removed)

  cout << pq.top(); // prints 8

  // size, swap, empty function same as others

  //! Minimum Heap
  // Below is the syntax for minimum Heap (ascending order of elements)

  priority_queue<int, vector<int>, greater<int>> pq; // -> for minimum element at the top

  pq.push(5);     // {5}
  pq.push(2);     // {2,5}
  pq.push(8);     // {2,5,8}
  pq.emplace(10); // {2,5,8,10}

  cout << pq.top(); // prints 2

}
