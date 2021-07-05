#include <iostream>

#include "search.h"
#include "Array.h"

int main()
{
	const int v1_size = 8,
		v2_size = 8;
	double v1[v1_size] = {
		1.4, 1.8, -12.44, 33,
		-1522.477, 877.8, 700, 0 
	};
	
	short v2[v2_size] = {
		1, 0, -124, 33, 
		-157, 87, 700, -4
	};

	/// Ex. 1
	// Sort
	insertionSort<double>(v1, v1_size);
	insertionSort<short>(v2, v2_size);

	// Display
	display<double>(v1, v1_size);
	display<short>(v2, v2_size);

	// Search
	const double v1_key = 1.4;
	const short v2_key = -4;
	std::cout << interpolSearch<double>(v1_key, v1, v1_size) << '\n'
		<< interpolSearch<short>(v2_key, v2, v2_size) << '\n';



	/// Ex. 2
	// Define arrays
	Array<double, v1_size> arr1;
	Array<short, v2_size> arr2;

	const Array<double, 1> tmp(1, v1[0]);

	// Insert data into arrays
	arr1.insert(*v1, 0);
	arr2.insert(*v2, 0);
	
	// Display arrays
	std::cout << arr1 << '\n' 
		<< arr2 << '\n';

	return 0;
}
