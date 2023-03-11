#pragma once
#include <iostream>
#include <exception>
#include <limits>
#include <random>
#include <string>
//--------------------------------------------------------------------------------------------------------------------
class CIntArray {
public:
	CIntArray() :_size(0), _data(nullptr) {};
	CIntArray(int);
	CIntArray(const CIntArray&);
	~CIntArray();

	CIntArray& operator=(const CIntArray&);

	int size() const { return _size; }
	int random_fill();

	int& operator[](const int&);
	int insert(int, int = 0);
	int add(int); //puts value to the end of array
	int remove(int);
	int clear();
	int resize(int);
	int index_of(int);//finds index of value in array (returns -1 if not found)

	friend std::ostream& operator<<(std::ostream&, const CIntArray&);

private:
	int _size;
	int* _data;
};
//--------------------------------------------------------------------------------------------------------------------
class CBadSizeException:public std::exception {
public:
	CBadSizeException(int v) {
		_info = "Invalid array size passed to constructor:";
		_info += std::to_string(v);
	};
	virtual const char* what() const override { return _info.c_str(); };
private:
	std::string _info;
};
//--------------------------------------------------------------------------------------------------------------------
class CBadRangeException :public std::exception {
public:
	CBadRangeException(int v){
		_info = "Invalid array item index:";
		_info += std::to_string(v);
	};
	virtual const char* what() const override {	return	_info.c_str();}
private:
	std::string _info;
};
//--------------------------------------------------------------------------------------------------------------------