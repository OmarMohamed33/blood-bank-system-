#pragma once
template<class T>
class Arr
{
	int element;
	int size;
	T* arr;
public:
	Arr();
	int length();
	bool Full();
	void Expend();
	void Append(T);
	T At(int);
	void insertAt(int, T);
	void DeleteAt(int);
	~Arr();
};

