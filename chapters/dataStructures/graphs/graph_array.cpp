#include<bits/stdc++.h>

#include<iostream>

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

using namespace std;
int main() {
    input;
    output;
    int vertAmount;
    cin >> vertAmount;     // Requesting the user the amount of vertices in the graph

    int graph[vertAmount][vertAmount];     // Creating an adjancency matrix to represent the graph
    memset(graph, 0, sizeof(graph));

    int edgesAmount;
    cin >> edgesAmount;     // Requesting the user the amount of edges in the graph

    for (int i = 0; i < edgesAmount; i++) {
        int vertOrigin, vertDest;
        cin >> vertOrigin >> vertDest;     // Reading the edges to update the matrix
        graph[vertOrigin][vertDest] = 1;     // 1 indicates there's an edge from origin vertex to destination vertex
    }

    for (int i = 0; i < vertAmount; i++) {
        for (int j = 0; j < vertAmount; j++) {
            cout << "[" << graph[i][j] << "]";     // Printing the matrix to visualize the graph
        }
        cout << endl;
    }

    return 0; 
}