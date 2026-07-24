#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // 0: uncolored, 1: Color A, -1: Color B

        for (int i = 0; i < n; ++i) {
            // Skip if the node is already colored
            if (color[i] != 0) continue;

            // Start BFS traversal from node i
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    // Assign opposite color if uncolored
                    if (color[v] == 0) {
                        color[v] = -color[u];
                        q.push(v);
                    } 
                    // Same color adjacent nodes -> not bipartite
                    else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};