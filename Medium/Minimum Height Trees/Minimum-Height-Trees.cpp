class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_matrix(n);
        vector<int> vertex_degree(n, 0);
        for (auto &edge: edges) { // initialize adjacency matrix for this tree
            adj_matrix[edge[0]].push_back(edge[1]);
            adj_matrix[edge[1]].push_back(edge[0]);
            vertex_degree[edge[0]]++;
            vertex_degree[edge[1]]++;
        }
        
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (vertex_degree[i] == 1) {
                q.push(i);
                vertex_degree[i]--;
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            int s = q.size();
            result.clear();
            for (int i = 0; i < s; i++) {
                int front = q.front();
                q.pop();
                result.push_back(front);
                for (auto node: adj_matrix[front]) {
                    vertex_degree[node]--;
                    if (vertex_degree[node] == 1) {
                        q.push(node);
                    }
                }
            }
            
        }
        if (n == 1) result.push_back(0);
        return result;
    }
};