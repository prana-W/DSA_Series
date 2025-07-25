#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//* Doubly Linked List
void explainList() {
  list<int> ls;

  ls.push_back(2);    //{2}
  ls.emplace_back(4); // {2,4}

  ls.push_front(5);    // {5,2,4}
  ls.emplace_front(6); // {6, 5, 2, 4}

  // rest functions same as vector
  // begin, end, rbegin, rend, clear, insert, size, swap

  //! Note
  //* insert in vectors are costly as compared to push_front in list

  // cout << ls[2] << endl; //! Can't access the elements directly!!! To have all these features and access of elements like an array/vector, use deque

  for (auto element : ls) {
    cout << element << endl;
  }

  // push_front is cheap, show me the insert... (wait, what?)
}

//* Double Ended Queue
void explainDeque() {
  deque<int> dq;

  dq.push_back(1);     //{1}
  dq.emplace_back(2);  //{1,2}
  dq.push_front(4);    //{4,1,2}
  dq.emplace_front(3); //{3,4,1,2}

  dq.pop_back();  // {3,4,1}
  dq.pop_front(); // {4,1}

  cout << dq.back() << endl;
  cout << dq.front() << endl;

  cout << dq[0] << endl; // Can be accessed unlike lists

  // rest functions same as vector
  // begin, end, rbegin, rend , clear, insert, size, swap
}

//* List vs Deque *//

/*

Lists: We can insert/delete any element in O(1) Time complexity anywhere. But we can't access them directly like in an array. Hence, access has a O(n) Time complexity

Deque: We can insert/delete element in the front and back in O(1) but for inserting/deleting anywhere else, we might require O(n) Time complexity. Although, here just like an array/vector, we can have direct access using the index and have O(1) TC.


*/

//* Stack --> LIFO (Last in First out)

void explainStack() //! O(1) --> everything happens in constant time
{
  stack<int> st;
  st.push(1);    // {1}
  st.push(2);    // {2,1}
  st.push(3);    // {3,2,1}
  st.push(3);    // {3,3,2,1}
  st.emplace(5); // {5,3,3,2,1}

  //! There are no indexes in stack. So st[2] for example is wrong!

  cout << st.top() << endl; // 5

  st.pop();                   // st looks like {3,3,2,1}
  cout << st.top() << endl;   // 3
  cout << st.size() << endl;  // 4
  cout << st.empty() << endl; // false (checks if empty or not)

  stack<int> st1, st2;
  st1.swap(st2); // swaping two stacks
}

int main() {
  explainDeque();
}
