#pragma once
#pragma once
#include <algorithm>

template <class T>
int interpolSearch(T key, T* vp, const int size)
{
	int left = 0, right = size - 1;

	while (left <= right && key >= vp[left] && key <= vp[right])
	{
		if (left == right)
			if (key == vp[left])
				return left;
			else
				return -1;

		int pos = left +
			(right - left) / (vp[right] - vp[left]) *
			(key - vp[left]);

		if (key == vp[pos])
			return pos;
		else if (key > vp[pos])
			left = pos + 1;
		else
			right = pos - 1;
	}

	return -1;
}

template <class T>
void insertionSort(T* arr, const int size)
{
	for (size_t i = 0; i < size; ++i)
		for (size_t j = i; j > 0 && arr[j - 1] > arr[j]; --j)
			std::swap(arr[j], arr[j - 1]);
}

template <class T>
void display(T* arr, const int size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}