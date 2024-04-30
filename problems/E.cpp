#include <bits/stdc++.h>

using namespace std;

#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
vector<string> graph;

int vx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int vy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int rows, columns;

void dfs(int row, int column) {
    graph[row][column] = '.';     // dfs will only be entered if cell has #
    for (int i = 0; i < 8; i++) {     // Now we visit the 8 possible directions
        int newRow = row + vx[i];
        int newColumn = column + vy[i];
        if (newRow >= 0 && newColumn >= 0 && newRow < rows && newColumn < columns && graph[newRow][newColumn] == '#') {
            dfs(newRow, newColumn);
        }
    }
}

int main() {
    input;
    while (cin >> rows >> columns && rows != 0 || columns != 0) {
        graph.clear();
        for (int i = 0; i < rows; i++) {
            string row;
            cin >> row;
            graph.push_back(row);
        }
        int amebas = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (graph[i][j] == '#') {     // If I'm on a black spot
                    dfs(i, j);
                    amebas++;
                }
            }
        }
        cout << amebas << endl;
    }
}