#include "cintarray.h"
//=====================================================================================================================
CIntArray::CIntArray(int sz) :_size(sz) {
	if (sz < 1 || sz >= INT_MAX)
		throw CBadSizeException(sz);

	try {
		_data = new int[sz] {};
	}
	catch (const std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
		throw;
	}
};
//--------------------------------------------------------------------------------------------------------------------	
CIntArray::CIntArray(const CIntArray& other):_size(other._size) {
	try {
		_data = new int[other._size];
	}
	catch (const std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
		throw;
	}
	for (int i = 0; i < other._size; i++)
		_data[i] = other._data[i];
}
//--------------------------------------------------------------------------------------------------------------------
CIntArray::~CIntArray() {
	if (_data)
		delete[] _data;
	_size = 0;
}
//--------------------------------------------------------------------------------------------------------------------
int& CIntArray::operator[](const int& idx) {
	if (idx < 0 || idx >= _size)
		throw CBadRangeException(idx);
	return _data[idx];
}
//--------------------------------------------------------------------------------------------------------------------
CIntArray& CIntArray::operator=(const CIntArray& rhs) {
	if (this == &rhs)
		return *this;
	clear();

	try {
		_data = { new int[rhs._size] };
	}
	catch (const std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
		throw;
	}

	for (int i = 0; i < rhs._size; i++)
		_data[i] = rhs._data[i];

	_size = rhs._size;
	return *this;
}
//--------------------------------------------------------------------------------------------------------------------
int CIntArray::add(int val) {
	if (!_data) {
		_data = new int[1] {val};
		_size = 1;
	}else{	
		int* tmp_arr = nullptr;
		try {
			tmp_arr = new int[_size + 1];
		}
		catch (const std::bad_alloc& e) {
			std::cout << e.what() << std::endl;
			throw;
		}
		for (int i = 0; i < _size; i++)
			tmp_arr[i] = _data[i];

		tmp_arr[_size++] = val;
		delete[] _data;
		_data = tmp_arr;
	}

}
//--------------------------------------------------------------------------------------------------------------------
//if idx 0 - adding to begining of array
int CIntArray::insert(int val, int idx) {
	if (idx < 0)
		throw CBadRangeException(idx);

	if (!_data) {
		if (!idx) {
			_data = new int[1] {val};
			_size = 1;
		}
		else {
			try {
				_data = new int[idx] {};
			}
			catch (const std::bad_alloc& e) {
				std::cout << e.what() << std::endl;
				throw;
			}
			_data[idx - 1] = val;
			_size = idx;
		}
	}
	else {
		int* tmp_arr = nullptr;

		int new_size{ _size + 1 + (idx > _size ? idx - _size : 0) };

		try {
 			tmp_arr = new int[new_size] {0};
		}
		catch (const std::bad_alloc& e) {
			std::cout << e.what() << std::endl;
			throw;
		}

		if (!idx) {
			tmp_arr[0] = val;
			for (int i = 0,j=1; i < _size; i++,j++)
				tmp_arr[j] = _data[i];
		}
		else {	
			for (int i = 0; i < (idx<=_size ? idx : _size); i++)
				tmp_arr[i] = _data[i];

			tmp_arr[idx] = val;

			for (int i = idx,j=idx+1; j < new_size; i++,j++)
				tmp_arr[j] = _data[i];
		}
		delete[] _data;
		_data = tmp_arr;
		_size = new_size;
	}
}
//--------------------------------------------------------------------------------------------------------------------
int CIntArray::remove(int idx) {
	int res(-1);

	if (idx < 0 || idx >= _size)
		return res;
	if (_data) {
		int* tmp_data = new int[_size - 1] {};
		for (int i = 0; i < idx; i++)
			tmp_data[i] = _data[i];

		for (int i = idx,j=++idx; j < (_size-1); i++,j++)
			tmp_data[i] = _data[j];
		delete[] _data;
		_data = tmp_data;
		_size--;
		res = _size;
	}
	return res;
}
//--------------------------------------------------------------------------------------------------------------------
int CIntArray::clear() {
	if (_data) {
		delete[] _data;
		_data = nullptr;
	}
	_size = 0;
	return _size;
}
//--------------------------------------------------------------------------------------------------------------------
int CIntArray::resize(int new_size) {

	if (_size == new_size)
		return _size;

	if(new_size<=1 || new_size>=INT_MAX)
		throw CBadSizeException(new_size);

	int* tmp_arr = nullptr;

	try {
		tmp_arr = new int[new_size] {};
	}
	catch (const std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
		throw;
	}

	for (int i = 0; i < (new_size >= _size ? _size : new_size); i++) {
		tmp_arr[i] = _data[i];
	}

	delete[] _data;
	_data = tmp_arr;
	_size = new_size;

	return _size;
}
//--------------------------------------------------------------------------------------------------------------------
int CIntArray::index_of(int val) {
	int res(-1);
	if (_data) {
		for (int i = 0; i < _size; i++) {
			if (val == _data[i]) {
				res = i;
				break;
			}
		}
	}
	return res;
}
//--------------------------------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, const CIntArray& arr) {
	if (arr._data) {
		for (int i = 0; i < arr._size;i++) {
			out << "Item #" << i << ": " << arr._data[i] << std::endl;
		}
	}else out << "The array is empty"<< std::endl;
	return out;
}
//--------------------------------------------------------------------------------------------------------------------
int CIntArray::random_fill() {
	int res{-1};

	std::random_device rd;
	std::uniform_int_distribution<int> dist(0, _size - 1);

	for (int i = 0; i < _size;i++) {
		_data[i] = dist(rd);
	}

	return res;
}
