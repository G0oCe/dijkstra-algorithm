#include <iostream>
#include <vector>
#include <fstream>
#include "input.cpp"


int main()
{
	std::vector<std::vector<int>> labyrinth = input("input.txt");

	std::ofstream OutputFile("output.txt");

    output(labyrinth, OutputFile);


	return 0;
}