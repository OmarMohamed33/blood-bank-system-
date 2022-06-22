#pragma once
template<class T>
class Arrlist
{
	int element;
	int size;
	T* arr;
public:
	Arrlist();
	int length();
	bool Full();
	void Expend();
	void Append(T);
	T At(int);
	void insertAt(int, T);
	void DeleteAt(int);
	~Arrlist();
};

