#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

bool vis[10000];
vector<int> graph[10000];

void dfs (int first) {
    stack<int> st;
    st.push(first);
    while(!st.empty()) {
        int current = st.top();     // To get the first element from the stack
        st.pop();
        if(!vis[current]) {
            vis[current] = true;     // Mark current as visited 
            for(int i = 0; i < graph[current].size(); i++ ){
                int buddy = graph[current][i];     // We pay its buddies a visit
                if(!vis[buddy]) {     // If buddy hasn't been visited yet
                    st.push(buddy);
                } 
            }   
        }
    }
}


int main() {
    input;
    int vertices, edges;
    cin>>vertices>>edges;     // We read the amount of vertices and edges present in the graph
    for(int i = 0 ; i < edges; i++ ) {
        int first, last;
        cin>>first>>last;
        graph[first].push_back(last);
    }
    int s,t;     // Origin and destination
    cin>>s>>t;
    dfs(s);
    if(vis[t]) {     // If t was possible to visit 
        cout<<"There is connection"<<endl;
    } else {
        cout<<"There is no connection"<<endl;
    }
}