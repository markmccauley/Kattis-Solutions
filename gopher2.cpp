#include <bits/stdc++.h>

using namespace std; 

struct Point {
    double xval, yval;

    double distance(Point p) {
        double xd = xval - p.xval;
        double yd = yval - p.yval;
        return sqrt(xd*xd + yd*yd);
    }
};
    
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) { 
    bool visited[rGraph.size()]; 
    memset(visited, 0, sizeof(visited)); 
  
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
  
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
  
        for (int i = 0; i < rGraph.size(); i++) 
        { 
            if (visited[i] == false && rGraph[u][i] > 0) 
            { 
                q.push(i); 
                parent[i] = u; 
                visited[i] = true; 
            } 
        } 
    } 
  
    return (visited[t] == true);
} 
  
int fordFulkerson(vector<vector<int>>& graph, int s, int t) { 
    int u, v; 
    vector<vector<int>> rGraph(graph.size(), vector<int>(graph.size()));  

    for (u = 0; u < graph.size(); u++) {
        for (v = 0; v < graph.size(); v++) { 
             rGraph[u][v] = graph[u][v]; 
        }
    }
  
    vector<int> parent(graph.size()); 
    int max_flow = 0;  
  
    while (bfs(rGraph, s, t, parent)) { 
        int path_flow = INT_MAX; 
        for (v = t; v != s; v = parent[v]) { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 
  
        for (v = t; v != s; v = parent[v]) { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
   
        max_flow += path_flow; 
    } 
  
    return max_flow; 
} 
  
int main() {  
    int n, m; 
    double s, v;
    while (cin >> n >> m >> s >> v) {
        vector<Point> gophers(n);
        vector<Point> holes(m);
        int nodes = n + m + 2;
        int source = nodes - 1;
        int sink = nodes - 2;
        vector<vector<int>> graph(nodes, vector<int>(nodes));

        for (int i = 0; i < n; i++) {
            cin >> gophers[i].xval >> gophers[i].yval;
        }

        for (int i = 0; i < m; i++) {
            cin >> holes[i].xval >> holes[i].yval;
        }

        for (int i = 0; i < n; i++) {
            Point gopher = gophers[i];
            for (int j = 0; j < m; j++) {
                Point hole = holes[j];
                double dist = hole.distance(gopher);
                double seconds = dist / v;
            
                if (seconds <= s) {
                    graph[i][j+n] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            graph[source][i] = 1;
        }

        for (int i = n; i < n + m; i++) {
            graph[i][sink] = 1;
        }

        int flow = fordFulkerson(graph, source, sink);

        cout << n - flow << endl;
    } 
}
