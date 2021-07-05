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

class OutOfRange {};

template <class T, int n = 256>
class Array
{
	T arr[n];
	int cnt; // Current number of elements

public:
	// Constructors
	Array<T, n>() : cnt(0) {};
	Array<T, n>(int n, const T& init_val);

	// Access methods
	int size() const { return n; };
	int lenght() const { return cnt; };

	Array& operator+=(float val) throw(OutOfRange)
	{
		append(val); return *this;
	}
	Array& operator+=(const Array& v) throw(OutOfRange)
	{
		append(v); return *this;
	}
	void append(T val) throw(OutOfRange);
	void append(const Array& v) throw(OutOfRange);

	// Insert and delete methods
	void insert(T v, int pos) throw(BadIndex, OutOfRange);
	void insert(const Array<T, n>& v, int pos) throw(BadIndex, OutOfRange);
	void remove(int pos) throw(BadIndex);

	// Index operator
	const T& operator[](int i) throw(BadIndex)
	{
		if (i < 0 || i >= cnt) throw BadIndex(i);
		return arr[i];
	}

	T operator[](int i) const throw(BadIndex)
	{
		if (i < 0 || i >= cnt) throw BadIndex(i);
		return arr[i];
	}

	// Output the array
	friend std::ostream& operator<<(std::ostream& os,
		const Array& v);
};
