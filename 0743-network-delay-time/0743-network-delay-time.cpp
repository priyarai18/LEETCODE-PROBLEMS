class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Adjacency List: {neighbor, weight}
        vector<pair<int,int>> adj[n + 1];

        for (auto &it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        // Min Heap: {distance, node}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto x : adj[node]) {

                int nbr = x.first;
                int wt = x.second;

                if (dist[node] + wt < dist[nbr]) {

                    dist[nbr] = dist[node] + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};