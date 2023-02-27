
#include <iostream>
#include "HashTable.h"
#include <vector>
#include <unordered_map>

int main()
{
	int a = 1;
	int b = 7;
	auto s = (a <=> b);
	//if(s == 0)

	Node node1(2, "sas");
	Node node2(2, "sas");

	std::cout << (2 <= node1) << '\n';
	std::cout << (node1 > 1) << '\n';
	std::cout << (node1 <= 1) << '\n';
	std::cout << (node2 >= node1) << '\n';
	std::cout << (1 == node1) << '\n';
	std::cout << (1 != node1) << '\n';
	std::cout << (node1 == 2) << '\n';
	std::cout << (node1 != 1) << '\n';
	
	std::unordered_map <float, const char*> map{ {1, "sas"}};

	


	
	
	
}


