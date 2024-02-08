#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::queue<int> q;
 
    q.push(0); // back pushes 0
    q.push(1); // q = 0 1
    q.push(2); // q = 0 1 2
    q.push(3); // q = 0 1 2 3

    q.pop(); // removes the front element, 0
 
    cout << "q: ";
    for (; !q.empty(); q.pop())
        cout << q.front() << ' ';
    cout << '\n';
}