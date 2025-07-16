#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<iterator>
#include<utility>
#include<functional>
#include<bitset>
#include<tuple>
#include<limits>
#include<cmath>
#include <numeric>
using namespace std;

int main() {
    // VECTOR
    vector<int> vec = {3, 1, 4};
    vec.push_back(5);
    vec.pop_back();
    vec.insert(vec.begin(), 9);
    vec.erase(vec.begin());
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    cout << "Vector front: " << vec.front() << ", back: " << vec.back() << "\n";

    // LIST (Doubly Linked List)
    list<int> lst = {10, 20, 30};
    lst.push_front(5);
    lst.push_back(35);
    lst.pop_front();
    lst.pop_back();

    // DEQUE
    deque<int> dq = {1, 2, 3};
    dq.push_front(0);
    dq.push_back(4);
    dq.pop_front();
    dq.pop_back();

    // STACK
    stack<int> st;
    st.push(100); st.push(200);
    cout << "Stack top: " << st.top() << "\n";
    st.pop();

    // QUEUE
    queue<int> q;
    q.push(10); q.push(20);
    cout << "Queue front: " << q.front() << ", back: " << q.back() << "\n";
    q.pop();

    // PRIORITY QUEUE (Max Heap)
    priority_queue<int> pq;
    pq.push(30); pq.push(10); pq.push(20);
    cout << "PQ top (max): " << pq.top() << "\n";
    pq.pop();

    // PRIORITY QUEUE (Min Heap)
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(3); min_pq.push(1); min_pq.push(2);
    cout << "Min PQ top: " << min_pq.top() << "\n";

    // SET
    set<int> s = {5, 1, 9};
    s.insert(7);
    s.erase(5);
    cout << "Set contains 7? " << (s.count(7) ? "Yes" : "No") << "\n";

    // MULTISET
    multiset<int> ms;
    ms.insert(10); ms.insert(10);
    cout << "Multiset count(10): " << ms.count(10) << "\n";

    // MAP
    map<string, int> m;
    m["a"] = 1;
    m["b"] = 2;
    cout << "Map b: " << m.at("b") << "\n";

    // MULTIMAP
    multimap<int, string> mm;
    mm.insert({1, "one"});
    mm.insert({1, "uno"});
    for (auto it = mm.begin(); it != mm.end(); ++it)
    cout << it->first << ": " << it->second << "\n";


    // UNORDERED MAP
    unordered_map<string, int> um;
    um["x"] = 100;
    um["y"] = 200;

    // UNORDERED SET
    unordered_set<int> us = {1, 2, 3};

    // PAIR
    pair<int, char> pr = {1, 'A'};
    cout << "Pair: " << pr.first << ", " << pr.second << "\n";

    // TUPLE
    tuple<int, string, float> tp = make_tuple(1, "Data", 3.14f);
    cout << "Tuple: " << get<0>(tp) << ", " << get<1>(tp) << ", " << get<2>(tp) << "\n";

    // BITSET
    bitset<8> bs(string("10101100"));
    cout << "Bitset: " << bs << ", set bits: " << bs.count() << "\n";

    // ALGORITHMS
    vector<int> a = {3, 1, 4, 2};
    sort(a.begin(), a.end());                         // Sort
    reverse(a.begin(), a.end());                      // Reverse
    rotate(a.begin(), a.begin() + 1, a.end());        // Rotate
    next_permutation(a.begin(), a.end());             // Next Permutation
    prev_permutation(a.begin(), a.end());             // Previous Permutation
    cout << "Binary Search 2? " << binary_search(a.begin(), a.end(), 2) << "\n";
    cout << "Lower Bound of 2: " << *lower_bound(a.begin(), a.end(), 2) << "\n";
    cout << "Upper Bound of 2: " << *upper_bound(a.begin(), a.end(), 2) << "\n";
    int sum = accumulate(a.begin(), a.end(), 0);
    cout << "Sum: " << sum << "\n";

    // NUMERIC LIMITS
    cout << "INT_MAX: " << numeric_limits<int>::max() << "\n";
    cout << "DBL_MIN: " << numeric_limits<double>::min() << "\n";

    return 0;
}
