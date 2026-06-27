class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    bfs(i, j, vis, grid, n, m);
                }
            }
        }
        return count;
    }

private:
    void bfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m) {
        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newRow = row + drow[k];
                int newCol = col + dcol[k];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = true;  // Mark as visited immediately
                    q.push({newRow, newCol});
                }
            }
        }
    }
};