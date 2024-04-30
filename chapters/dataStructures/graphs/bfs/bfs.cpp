#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

bool vis[10000];
vector<int> graph[10000];
int levels[10000];
void bfs (int first) {
    queue<int> q;
    q.push(first);
    levels[first] = 0;
    while(!q.empty()){ 
        int current = q.front();     // Get what's on the front of the queue
        q.pop();
        if(!vis[current]) {
            vis[current] = true;     // The current node is marked as visited 
            for(int i = 0; i < graph[current].size(); i++ ){
                int buddy = graph[current][i];     // Paying a visit to buddies
                levels[buddy] = levels[current] + 1;
                if(!vis[buddy]) {     // Has buddy been visited?
                    q.push(buddy);
                } 
            }   
        }
    }
}


int main() {
    input;
    int vertices, edges;
    cin>>vertices>>edges; // 11 19
    for(int i = 0 ; i < edges; i++ ) {
        int first, last;
        cin>>first>>last;
        graph[first].push_back(last);
    }
    int S,T;
    cin>>S>>T;     // To know if S can get to T
    bfs(S);
    if(vis[T]) {     // T could be visited
        cout<<"There is a connection"<<endl;
    } else {
        cout<<"There is no connection"<<endl;
    }
}