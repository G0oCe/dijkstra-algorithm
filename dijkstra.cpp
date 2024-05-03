#include <iostream>
#include <queue>
#include <vector>
#include <climits>


std::vector<int> dijkstra(std::vector<std::vector<int>> graph, int start) {
    int n = graph.size();
    std::vector<int> distances(n, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;

    distances[start] = 0;
    queue.push(std::make_pair(0, start));

    while (!queue.empty()) {
        int current_node = queue.top().second;
        queue.pop();

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (graph[current_node][neighbor] != 0) {
                int weight = graph[current_node][neighbor];

                if (distances[current_node] + weight < distances[neighbor]) {
                    distances[neighbor] = distances[current_node] + weight;
                    queue.push(std::make_pair(distances[neighbor], neighbor));
                }
            }
        }
    }

    return distances;
}