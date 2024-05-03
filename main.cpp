#include <iostream>
#include <vector>
#include <fstream>
#include "input.cpp"
#include "dijkstra.cpp"


int main() {
	std::vector<std::vector<int>> matrix = input("input.txt");

	std::vector<int> distances = dijkstra(matrix, 0);

	for (int i = 0; i < distances.size(); i++) {
        std::cout << "The shortest distance from node 0 to node " << i << " is " << distances[i] << std::endl;
    }

	return 0;
}

