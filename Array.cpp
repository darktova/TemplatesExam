#include "Array.h"

template<class T, int n>
void Array<T, n>::insert(const T& v, int pos)
throw(BadIndex, OutOfRange)
{
	if (pos < 0 || pos > cnt)
		throw BadIndex(pos);
	if (n < cnt + v.cnt)
		throw OutOfRange(pos);

	for (int i = cnt - 1; i >= pos; --i)
		arrPtr[i + v.cnt] = arrPtr[i];
	for (int i = 0; i < v.cnt; ++i)
		arrPtr[i + pos] = v.arrPtr[i];
	cnt = cnt + v.cnt;
}

template<class T, int n>
void Array<T, n>::remove(int pos) throw(BadIndex)
{
	if (pos >= 0 && pos < cnt)
	{
		for (int i = pos; i < cnt - 1; ++i)
			arrPtr[i] = arrPtr[i + 1];
		--cnt;
	}
	else
		throw BadIndex(pos);
}

template<class T, int n>
float& Array<T, n>::operator[](int i) throw(BadIndex)
{
	if (i < 0 || i >= cnt) throw BadIndex(i);
	return arrPtr[i];
}

template<class T, int n>
float Array<T, n>::operator[](int i) const throw(BadIndex)
{
	if (i < 0 || i >= cnt) throw BadIndex(i);
	return arrPtr[i];
}