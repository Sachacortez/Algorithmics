#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<string> vectorcito(10,"Sacha");
    vectorcito.push_back("Santiago");
    cout<<"The size of the vector is "<< vectorcito.size()<<endl;
    for(int i = 0 ; i < vectorcito.size() ; i++) {
    	cout<<i<<" "<< vectorcito[i]<<endl;
    }
    return 0;
}