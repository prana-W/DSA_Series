#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void explainList() {
    list<int> ls;

    ls.push_back(2);    //{2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5); // {5,2,4}
    ls.emplace_front(); // Similar to push_front

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap

    //! Note
    //* insert in vectors are costly as compared to push_front in list

    // push_front is cheap show me the insert... (wait, what?)
}

//* Both feaatures of vector and list
void explainDeque() {
    deque<int> dq;

    dq.push_back(1);     //{1}
    dq.emplace_back(2);  //{1,2}
    dq.push_front(4);    //{4,1,2}
    dq.emplace_front(3); //{3,4,1,2}

    dq.pop_back();  // {3,4,1}
    dq.pop_front(); // {4,1}

    dq.back();
    dq.front();

    // rest functions same as vector
    // begin, end, rbegin, rend , clear, insert, size, swap
}

//***Stack --> LIFO (Last in First out)

void explainStack() //! O(1) --> everything happens in constant time
{
    stack<int> st;
    st.push(1);    // {1}
    st.push(2);    // {2,1}
    st.push(3);    // {3,2,1}
    st.push(3);    // {3,3,2,1}
    st.emplace(5); // {5,3,3,2,1}

    //! There are no indexes in stack. So st[2] for example is wrong!

    cout << st.top(); // it gives 5 but 5 is still on the top
                      

    st.pop();           // st looks like {3,3,2,1}
    cout << st.top();   // 3
    cout << st.size();  // 4
    cout << st.empty(); // false

    stack<int> st1, st2;
    st1.swap(st2);
}
