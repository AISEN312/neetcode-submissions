#include <vector>
using namespace std;

class Solution {
private:
    
    
    bool isCyclic(int curr, vector<vector<int>>& adj, vector<int>& state) {
     
        if (state[curr] == 1) return true;
         if (state[curr] == 2) return false;
        state[curr] = 1;
        for (int neighbor : adj[curr]) {
            if (isCyclic(neighbor, adj, state)) {
                return true; 
            }
        }

        state[curr] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for (const auto& relation : prerequisites) {
            adj[relation[1]].push_back(relation[0]);
        }
        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (isCyclic(i, adj, state)) {
                    return false; 
                }
            }
        }

        return true;
    }
};