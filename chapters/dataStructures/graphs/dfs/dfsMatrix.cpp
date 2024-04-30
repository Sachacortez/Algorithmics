#include <bits/stdc++.h>

using namespace std;

#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
vector<string> graph(1000);
int vis[1000][1000];
int vx[] = {-1, 1, 0, 0, -1, -1, 1, 1};     // These are all directions like up, down, right and left
int vy[] = {0, 0, 1, -1, 1, -1, 1, -1};     // of a determined plot

void dfs(int row, int column) {
    vis[row][column] = true;
    for (int i = 0; i < 8; i++)
    {
        int newRow = row + vx[i];
        int newColumn = column + vy[i];
        if (newRow >= 0 && newRow <= 3 
            && newColumn >= 0 && newColumn <= 4 
            && graph[newRow][newColumn] == '1')
        {
            if (!vis[newRow][newColumn])
            {
                dfs(newRow, newColumn);
            }
        }
    }
}

int main() {
    int rows, columns;
    cin >> rows >> columns;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < rows; i++) {
        cin >> graph[i]; 
    }
    int countIslands = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (!vis[i][j] && graph[i][j] == '1') {
                dfs(i, j);
                countIslands++;
            }
        }
    }
}