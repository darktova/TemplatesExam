#pragma once
#include <iostream>

class BadIndex
{
private:
	int index;
public:
	BadIndex(int i) { index = i; }
	int getBadIndex() const { return index; }
};

class OutOfRange
{
private:
	int index;

public:
	OutOfRange(int i) { index = i; }
	int getOutOfRange() const { return index; }
};


template <class T, int n = 255>
class Array
{
	T* arrPtr; // Dynamic member
	int cnt; // Current number of elements

public:
	// Constructors
	Array<T, n>()
		: arrPtr(new T[n]), cnt(0) {};
	Array<T, n>(T init_val)
		: arrPtr(new T[n]), cnt(n)
	{
		for (int i = 0; i < cnt; ++i)
			arrPtr[i] = init_val;
	};
	// Access methods
	int size() const { return n; };
	int lenght() const { return cnt; };

	// Insert and delete methods
	void insert(const T& v, int pos) throw(BadIndex, OutOfRange);
	void remove(int pos) throw(BadIndex);

	// Index operator
	float& operator[](int i) throw(BadIndex);
	float operator[](int i) const throw(BadIndex);

	// Output the array
	friend std::ostream& operator<<(std::ostream& os,
		const Array& v)
	{
		int w = os.width(); // Save field width.
		for (T* p = v.arrPtr; p < v.arrPtr + v.cnt; ++p)
		{
			os.width(w); os << *p << ' ';
		}
		return os;
	}

};
