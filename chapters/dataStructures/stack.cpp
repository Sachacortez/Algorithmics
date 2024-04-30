#include<bits/stdc++.h>

using namespace std;

int main() {
    stack<int> s; 
    cout<<s.empty()<<endl;
    s.push(10);
    cout<<s.empty()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.empty()<<endl;
} 