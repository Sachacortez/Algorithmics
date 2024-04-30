#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

bool vis[10000];
vector<int> graph[10000];
int members;

void dfs(int first) {
    stack<int> s;
    s.push(first);
    while(!s.empty()) {
        int current = s.top();     //The vertex we handle at the moment is the one on top of the stack
        s.pop();
        if(!vis[current]) {
            vis[current] = true;
            members++;
        }
        for(int i = 0 ; i < graph[current].size(); i++) {
            int buddy = graph[current][i];
            if(!vis[buddy]) {
                s.push(buddy);
            }
        }
    }
}

int main() {
    input;
    int vertAmount, edgeAmount;
    cin>>vertAmount>>edgeAmount;
    for(int i = 0 ; i< edgeAmount; i++) {
        int first, last;
        cin>>first>>last;
        graph[first].push_back(last);     // Outward edge 
        graph[last].push_back(first);     // Inward edge
    }
    int countGroups = 0;
    for (int i = 1 ; i <= vertAmount; i++) {
        if(!vis[i]) {
            countGroups++;
            members = 0;
            dfs(i);
            cout<<"Group "<< i <<" has "<< members <<" members."<<endl;
        }
    }
    cout<<"The amount of groups is "<< countGroups<<endl;
    return 0;
}