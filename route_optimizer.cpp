#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// A pair to store the vertex and its distance (weight)
typedef pair<int, int> pii;

class Graph {
    int V; // Number of vertices (locations)
    vector<vector<pii>> adj; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add a road (edge) between two locations
    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight)); // Assuming two-way roads
    }

    // Dijkstra's Algorithm to find the shortest delivery routes
    void shortestPath(int src) {
        // Priority queue to store vertices that are being preprocessed (min-heap)
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        // Vector for distances, initialized to infinity
        vector<int> dist(V, numeric_limits<int>::max());

        // Insert source itself in priority queue and initialize its distance as 0
        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second; // Get the vertex with minimum distance
            pq.pop();

            // Iterate through all adjacent vertices of u
            for (auto x : adj[u]) {
                int v = x.first;
                int weight = x.second;

                // If there is a shorter path to v through u
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        // Print the calculated shortest distances
        cout << "Delivery Hub (Source: " << src << ") to Destinations:\n";
        for (int i = 0; i < V; ++i) {
            cout << "Location " << i << " \t Distance: " << dist[i] << " mins\n";
        }
    }
};

int main() {
    // Create a graph with 5 locations (0 = Main Hub, 1-4 = Delivery Stops)
    int V = 5;
    Graph g(V);

    // Adding roads (u, v, time_in_minutes)
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);

    // Calculate shortest paths from the Main Hub (Node 0)
    g.shortestPath(0);

    return 0;
}