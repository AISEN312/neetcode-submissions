#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string foreignDictionary(vector<string>&words){
        vector<vector<int>> adj(26);
        vector<bool> present(26,false);
        vector<vector<bool>> added(26,vector<bool>(26,false));
        for(const auto &w : words)
        for(char c:w)
        present[c - 'a'] = true;
        for(size_t i =0;i+1<words.size();++i){
            const string &a = words[i];
            const string &b = words[i+1];
            size_t len = min(a.size(),b.size());
            size_t j = 0;
            for(;j<len;++j){
                if(a[j] != b[j]){
                    int u = a[j] - 'a';
                    int v = b[j] - 'a';
                    if(!added[u][v]){
                        adj[u].push_back(v);
                        added[u][v] = true;
                    }
                    break;
                }
            }
            if (j == len && a.size() > b.size()) return "";
        }
        vector<int> state(26,0);
        string order;
        order.reserve(26);
        bool hasCycle = false;
        function<void(int)> dfs = [&](int u){
            if(hasCycle) return;
            state[u] = 1;
            for(int v: adj[u]){
                if(state[v] == 0) dfs(v);
                else if(state[v] == 1){hasCycle = true;return;}
                if (hasCycle) return;
            }
            state[u] = 2;
            order.push_back(char('a' + u));
        };
        for(int i = 0;i<26;++i){
            if(present[i] && state[i] == 0) dfs(i);
            if(hasCycle) return "";
        }
        reverse(order.begin(),order.end());
        return order;
    }
};
