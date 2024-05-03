#include <iostream>  // For input/output
#include <queue>     // For priority_queue
#include <vector>    // For vector
#include <climits>   // For INT_MAX

// Function to implement Dijkstra's algorithm
std::vector<int> dijkstra(std::vector<std::vector<int>> graph, int start) {
    // Get the number of nodes in the graph
    int n = graph.size();

    // Initialize distances to all nodes as infinity
    std::vector<int> distances(n, INT_MAX);

    // Create a min-priority queue to select the edge with the smallest weight
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;

    // Distance from the start node to itself is always 0
    distances[start] = 0;

    // Add the start node into the queue
    queue.push(std::make_pair(0, start));

    // Continue until all nodes have been visited
    while (!queue.empty()) {
        // Select the edge with the smallest weight
        int current_node = queue.top().second;
        queue.pop();

        // Visit all the adjacent nodes of the current node
        for (int neighbor = 0; neighbor < n; neighbor++) {
            // Check if there is an edge from the current node to the neighbor
            if (graph[current_node][neighbor] != 0) {
                // Get the weight of the edge
                int weight = graph[current_node][neighbor];

                // If the current known distance to the neighbor is greater than the distance through the current node
                // Update the shortest known distance and enqueue the neighbor
                if (distances[current_node] + weight < distances[neighbor]) {
                    distances[neighbor] = distances[current_node] + weight;
                    queue.push(std::make_pair(distances[neighbor], neighbor));
                }
            }
        }
    }

    // Return the shortest distances from the start node to all other nodes
    return distances;
}
