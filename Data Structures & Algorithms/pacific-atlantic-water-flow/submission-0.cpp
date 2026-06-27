
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        if (h.empty()) return {};
        int m = h.size(), n = h[0].size();
        vector<vector<char>> p(m, vector<char>(n, 0)), a(m, vector<char>(n, 0));
        auto bfs = [&](queue<pair<int,int>> q, vector<vector<char>>& vis) {
            int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
            while (!q.empty()) {
                auto [r,c] = q.front(); q.pop();
                for (auto &d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && h[nr][nc] >= h[r][c]) {
                        vis[nr][nc] = 1;
                        q.emplace(nr, nc);
                    }
                }
            }
        };

        queue<pair<int,int>> pq, aq;
        for (int i = 0; i < m; ++i) { pq.emplace(i,0); p[i][0]=1; aq.emplace(i,n-1); a[i][n-1]=1; }
        for (int j = 0; j < n; ++j) { pq.emplace(0,j); p[0][j]=1; aq.emplace(m-1,j); a[m-1][j]=1; }
        bfs(pq, p); bfs(aq, a);

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (p[i][j] && a[i][j]) res.push_back({i,j});
        return res;
    }
};
