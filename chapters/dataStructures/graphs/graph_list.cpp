#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
    input;
    int vertAmount;
    std::cin >> vertAmount;         // Get the amount of vertices in graph

    vector<int> graph[vertAmount]; // Adjacency list to represent graph 
    
    int edgeAmount;
    cin >> edgeAmount;     // Get the amount of edges in the graph

    for (int i = 0; i < edgeAmount; i++) {
        int nodoOrigen, nodoDestino;
        cin >> nodoOrigen >> nodoDestino;     // Reading edges to insert in adjacency list
        graph[nodoOrigen].push_back(nodoDestino);     // Now we add the destination vertex to the list of
    }                                                 // the origin vertex to represent an edge

    for (int i = 0; i < vertAmount; i++) {     // To print list
        for (int j = 0; j < graph[i].size(); j++) {
            cout << "[" << graph[i][j] << "]";     // Print each vertex connected to vertex 'i'.
        }
        cout << std::endl;
    }

    return 0; 
}