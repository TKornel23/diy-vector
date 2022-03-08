#include <iostream>
#include <vector>
#include "vector.h"

int main()
{
	oe::vector<int> v1;
	oe::vector<bool> v2;

	oe::vector<int> v3(5);
	oe::vector<int> v4(10, 8);
	/*oe::vector<int> v5({3,4,5,6,8,10});*/

	oe::vector<int> v6 = v3;
	v3 = v4;

	v1.push_back(1);
	v1.push_back(13);
	v1.push_back(15);
	for (size_t i = 0; i < v4.size(); i++)
	{
		v4[i] = i + 4;
	}

	for (size_t i = 0; i < v4.size(); i++)
	{
		std::cout << v1[i] << std::endl;
	}

	/*oe::vector<int>::iterator it = v4.begin(); it != v4.end(); ++it)
	{
		std::cout << *it << std::endl;
	}*/

	for (const auto& e : v4)
	{
		std::cout << e << std::endl;
	}
}