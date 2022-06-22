#include "Arrlist.h"
#include <cassert>
template<class T>
Arrlist<T>::Arrlist()
{
	element = 0;
	size = 30;
	arr = new T[size];
}

template<class T>
int Arrlist<T>::length()
{
	return element;
}

template<class T>
bool Arrlist<T>::Full()
{
	return (element == size);
}

template<class T>
void Arrlist<T>::Expend()
{
	size =size * 2;
	T* tmp = new T[size];
	for(int i=0;i<element;i++)
	{
		tmp[i] = arr[i];
	}
	delete[]arr;
}

template<class T>
void Arrlist<T>::Append(T val)
{
	if (Full())
		Expend();
	arr[element] = val;
	element++;
}

template<class T>
T Arrlist<T>::At(int pos)
{
	assert(pos >= 0 && pos < element);
	return (arr[pos]);
}

template<class T>
void Arrlist<T>::insertAt(int pos, T val)
{
	if (Full())
		Expend();
	assert(pos >=0 && pos < element);
	for (int i = element-1; i > pos; i--)
		arr[i] = arr[i - 1];
	arr[pos] = val;
	element++;
}

template<class T>
void Arrlist<T>::DeleteAt(int pos)
{

	assert(pos >= 0 && pos < element);
	for (int i = pos; i < element; i++)
		arr[i] = arr[i + 1];
	element--;
}


template<class T>
Arrlist<T>::~Arrlist()
{
	delete[]arr;
}
