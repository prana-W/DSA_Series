#include <iostream>
#include <vector>
using namespace std;

// * Vector
//? It is a container (dynamic array)
void explainVectors() {
  vector<int> v;

  v.push_back(1);
  v.emplace_back(2); // push_back and emplace_back works the same

  //* but generally emplace_back is faster than push_back()

  vector<pair<int, int>> vec;

  vec.push_back({1, 2});  // For pushing back a pair, we need to specify the curly braces
  vec.emplace_back(1, 2); // For pushing using emplace, there is no need of the braces

  vector<int> v2(5, 100); // First is the size and the other is default value of each element

  vector<int> v3(5); // The number is the size of the vector

  vector<int> v4(5, 10);
  vector<int> v5(v4); // To copy v4 into v5, we do this!

  // ------------------------------- //

  //* Iterators
  //? iterators point to the memory address
  // It helps us to access and iterate through elements of any data structure

  vector<int>::iterator it = v4.begin();
  it++;
  cout << *(it) << " ";

  it = it + 2;
  cout << *(it) << " ";

  vector<int>::iterator it = v4.end(); //! end will not point to last element (it point to  memory address after the last element)
  //? it will point right after last element

  vector<int>::reverse_iterator it = v4.rend();   // Treat the vector as reversed. Then that's end (so before the first element actually, as the end means one after the last element)
  vector<int>::reverse_iterator it = v4.rbegin(); // This will point to the last element

  cout << v4[0] << " " << v4.at(0) << " ";

  cout << v4.back() << " "; // End element of the back

  //! NOTE:
  // v.end() is an iterator pointing to the memory address just after the last element of the array/vector!!!

  for (vector<int>::iterator it = v.begin(); it != v4.end(); it++) {
    cout << *(it) << " ";
  }

  cout << endl;

  //! auto
  //? It automatically assigns the required data-type (here vector iterator of int type)
  for (auto it = v4.begin(); it != v4.end(); it++) {
    cout << *(it) << " ";
  }

  cout << endl;

  {
    auto a = "string";
    // here a will be assigned as a string data type automatically!!
  }

  //! for-each loop
  // 'element' is the element of the v vector here!!!!
  for (auto element : v) {
    cout << element << " ";
  }

  // * Deletion of vectors
  // {10,20,30,50}
  v.erase(v.begin() + 1); // {10, 30, 50}

  // v.erase(v.begin() + 1, v.begin() + 3); // [start,end) - end is the after the last element

  // * Insert Function

  vector<int> v(2, 100);          // {100,100}
  v.insert(v.begin(), 300);       // {300, 100, 100}
  v.insert(v.begin() + 1, 2, 10); //* Inserting multiple elements {300, 10, 10, 100, 100} -

  vector<int> myVector(2, 50);                           // {50,50}
  v.insert(v.begin(), myVector.begin(), myVector.end()); // {50, 50, 300, 10, 10, 100, 100} //* Inserting some part of other vector into another vector

  // {10,20}
  cout << v.size(); // 2

  //{10,20}
  v.pop_back(); //{10}

  // v --> {10,20};
  // v2 --> {30,40};

  //* Swaping a vector
  v.swap(v2); // v --> {30,40}, v2 --> {10,20}

  v.clear(); //* erases the entire vector

  cout << v.empty(); //* Return a boolean (true if any element)
}