#include "cintarray.h"


void custom_quit() {
	std::cout << "\nGame Over\n";
}
void custom_terminate() {
	std::cout << "\nExit due to uncaught exception\n";
	exit(69);
}
//==========================================================================================================
int main() {

	atexit(custom_quit);
	set_terminate(custom_terminate);
	
	int arr_size{10};
	
	CIntArray intv, intv_copy;

	try {
		intv = CIntArray(arr_size);
	}
	catch (const CBadSizeException& e) {
		std::cerr << "Failed to create array:";
		std::cerr << e.what();
		exit(1);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Failed to allocate memory for the array:";
		std::cerr << e.what();
		exit(1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception:";
		std::cerr << e.what();
	}

		
	intv.random_fill();

	std::cout << "\nInitial array:\n";
	std::cout << intv << std::endl;


/*
	intv_copy.insert(129);
	std::cout << "The copy of the array after insert:\n";
	std::cout << intv_copy << std::endl;


	intv_copy.add(-795);
	std::cout << "The copy of the array after add:\n";
	std::cout << intv_copy << std::endl;

*/
	//return 0;

	try {
		intv_copy = CIntArray(intv);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Failed to allocate memory for the array copy:";
		std::cerr << e.what();
		exit(1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception:";
		std::cerr << e.what();
	}

	std::cout << "The copy of the array:\n";
	std::cout << intv_copy << std::endl;

	try {
		intv[0] = 5;
		intv[1] = 3;
		intv[intv.size()-1] = 169;
		intv[intv.size()+5] = 160989;
	}
	catch (const CBadRangeException& e) {
		std::cerr << "Access by index failed:";
		std::cerr << e.what();
	} 


	std::cout << "\nUpdated Array:\n";
	std::cout << intv << std::endl;

	int search_value = 8;

	int found_idx = intv.index_of(search_value);

	if(found_idx==-1)
		std::cout << "Index of value " << search_value << ": not found\n";
	else
		std::cout << "Index of value " << search_value << ": " << found_idx<<std::endl;

	arr_size = 15;

	try {
		if (-1 == intv.resize(arr_size))
			std::cout << "Failed to resize the array to " << arr_size << std::endl;
	}
	catch (const CBadRangeException& e) {
		std::cerr << "Resize failed:";
		std::cerr << e.what();
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Failed to allocate memory for the new array size:";
		std::cerr << e.what();
		exit(1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception:";
		std::cerr << e.what();
	}

	
	std::cout << "Array after resize to "<< arr_size <<":\n";
	std::cout << intv << std::endl;
	
	intv[10] = 961;

	found_idx = 9;
	
	if (intv.remove(found_idx)) {
		std::cout << "Array after removing value of index " << found_idx << ":\n";
		std::cout << intv << std::endl;

	}

	arr_size = 10;

	try {
		if (-1 == intv.resize(arr_size))
			std::cout << "Failed to resize the array to " << arr_size << std::endl;
	}
	catch (const CBadRangeException& e) {
		std::cerr << "Resize failed:";
		std::cerr << e.what();
	}
	catch (const std::exception& e) {
		std::cerr << "Exception:";
		std::cerr << e.what();
	}

	std::cout << "Array after resize to " << arr_size << ":\n";
	std::cout << intv << std::endl;

	
	search_value = 789;

	try {
		intv.add(search_value);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Failed to allocate memory for the new array size:";
		std::cerr << e.what();
		exit(1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception:";
		std::cerr << e.what();
	}

	std::cout << "Array after adding new value ("<< search_value <<") to the end of array\n";
	std::cout << intv << std::endl;


	search_value = 333;

	try {
		intv.insert(search_value); //to begining of array
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Failed to allocate memory for the new array size:";
		std::cerr << e.what();
		exit(1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception:";
		std::cerr << e.what();
	}

	std::cout << "Array after adding new value ("<< search_value <<") to begining of array\n";
	std::cout << intv << std::endl;


	search_value = 444;
	found_idx = 13;

	try {
		intv.insert(search_value, found_idx); 
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Failed to allocate memory for the new array size:";
		std::cerr << e.what();
		exit(1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception:";
		std::cerr << e.what();
	}

	std::cout << "Array after inserting new value (" << search_value << ") to index["<< found_idx<<"] of array\n";
	std::cout << intv << std::endl;

	
	search_value = 789;
	found_idx = intv.index_of(search_value);

	if (found_idx == -1)
		std::cout << "Index of value " << search_value << ": not found\n";
	else
		std::cout << "Index of value " << search_value << ": " << found_idx << std::endl;


	return 0;
}