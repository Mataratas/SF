#include "tiarray.h"
#include "tiarray.cpp"


void custom_quit() {
	std::cout << "\nTest Over\n";
}
void custom_terminate() {
	std::cout << "\nExit due to uncaught exception\n";
	exit(69);
}

void test_int_array();
void test_float_array();
void test_char_array();
void test_string_array();

//==========================================================================================================
auto main() -> int {

	atexit(custom_quit);
	set_terminate(custom_terminate);

	int choice(0);

	setlocale(LC_ALL, "");

	std::cout << "Выберите тип данных массива:\n\t1 - Int\n\t2 - Float\n\t3 - Char\n\t4 - string\n\t0 - выход:\n";

	std::cin >> choice;

	while (choice){
		switch (choice){
			case 1:
				test_int_array();
				break;
			case 2:
				test_float_array();
				break;
			case 3:
				test_char_array();
				break;
			case 4:
				test_string_array();
				break;
			default:
				break;
		}
		std::cout << "Выберите тип данных массива:\n\t1 - Int\n\t2 - Float\n\t3 - Char\n\t4 - string\n\t0 - выход:\n"; 
		std::cin >> choice;
	}

	return 0;

}
//==========================================================================================================
void test_int_array() {
	int arr_size{ 10 }, search_value(0), found_idx{ -1 };
	CTypeArray<int>* arr_t = nullptr;
	try {
		arr_t = new CTypeArray<int>(arr_size);
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

	arr_t->random_fill();
	std::cout << "Array after creation and random fill:\n";
	std::cout << *arr_t << std::endl;

	search_value = 13;

	std::cout << "Inserting value "<< search_value<< " to begining of the array. Resulting array:\n";
	arr_t->insert(search_value);
	std::cout << *arr_t << std::endl;

	search_value = 118;
	std::cout << "Adding value " << search_value << " to the end of the array. Resulting array:\n";
	arr_t->add(search_value);
	std::cout << *arr_t << std::endl;

	found_idx = 9;
	search_value = -121;

	std::cout << "Inserting value " << search_value << " to index "<< found_idx<<" of the array. Resulting array:\n";
	arr_t->insert(search_value, found_idx);
	std::cout << *arr_t << std::endl;

	found_idx = 3;
	search_value = 1169;
	(*arr_t)[found_idx] = search_value;
	std::cout << "Updating value through index operation:  array[" << found_idx << "] = " << search_value << ".Resulting array:\n";
	arr_t->Show();

	arr_size = 15;
	std::cout << "Increasing array size to  " << arr_size << ". Resulting array:\n";
	arr_t->resize(arr_size);
	std::cout << *arr_t << std::endl;

	found_idx = 17;
	search_value = 188;
	std::cout << "Inserting value " << search_value << " to index " << found_idx << ",exeeding the array size. Resulting array:\n";
	arr_t->insert(search_value, found_idx);
	std::cout << *arr_t << std::endl;

	search_value = -121;
	std::cout << "Looking for value " << search_value << " in the array. Result: ";
	found_idx = arr_t->index_of(search_value);
	if (found_idx == -1)
		std::cout << "Value " << search_value << " not found\n";
	else
		std::cout << "Value " << search_value << " found at index "<< found_idx<<"\n";

	std::cout << "Removing the value " << search_value << " from the array. Resulting array:\n";
	arr_t->remove(found_idx);
	std::cout << *arr_t << std::endl;

	arr_size = 10;
	std::cout << "Decreasing array size to  " << arr_size << ". Resulting array:\n";
	arr_t->resize(arr_size);
	std::cout << *arr_t << std::endl;

	delete arr_t;

}
//----------------------------------------------------------------------------------------------------------
void test_float_array() {
	int arr_size{ 10 }, found_idx{ -1 };
	float search_value(0.0f);
	CTypeArray<float>* arr_t = nullptr;
	try {
		arr_t = new CTypeArray<float>(arr_size);
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


	std::cout << "Array after creation and initial fill:\n";
	arr_t->random_fill();

	std::cout << *arr_t << std::endl;

	search_value = 133.6f;

	std::cout << "Inserting value " << search_value << " to begining of the array. Resulting array:\n";
	arr_t->insert(search_value);
	std::cout << *arr_t << std::endl;

	search_value = 118.8f;
	std::cout << "Adding value " << search_value << " to the end of the array. Resulting array:\n";
	arr_t->add(search_value);
	std::cout << *arr_t << std::endl;

	found_idx = 7;
	search_value = -121.1f;

	std::cout << "Inserting value " << search_value << " to index " << found_idx << " of the array. Resulting array:\n";
	arr_t->insert(search_value, found_idx);
	std::cout << *arr_t << std::endl;

	found_idx = 3;
	search_value = 1169.05f;
	(*arr_t)[found_idx] = search_value;
	std::cout << "Updating value through index operation:  array[" << found_idx << "] = " << search_value << ".Resulting array:\n";
	arr_t->Show();

	arr_size = 15;
	std::cout << "Increasing array size to  " << arr_size << ". Resulting array:\n";
	arr_t->resize(arr_size);
	std::cout << *arr_t << std::endl;

	found_idx = 17;
	search_value = 188.01f;
	std::cout << "Inserting value " << search_value << " to index " << found_idx << ",exeeding the array size. Resulting array:\n";
	arr_t->insert(search_value, found_idx);
	std::cout << *arr_t << std::endl;

	search_value = -121.1f;
	std::cout << "Looking for value " << search_value << " in the array. Result: ";
	found_idx = arr_t->index_of(search_value);
	if (found_idx == -1)
		std::cout << "Value " << search_value << " not found\n";
	else
		std::cout << "Value " << search_value << " found at index " << found_idx << "\n";

	std::cout << "Removing the value " << search_value << " from the array. Resulting array:\n";
	arr_t->remove(found_idx);
	std::cout << *arr_t << std::endl;

	arr_size = 10;
	std::cout << "Decreasing array size to  " << arr_size << ". Resulting array:\n";
	arr_t->resize(arr_size);
	std::cout << *arr_t << std::endl;


	delete arr_t;
}
//----------------------------------------------------------------------------------------------------------
void test_char_array() {
	int arr_size{ 10 }, found_idx{ -1 };
	char search_value('\0');
	CTypeArray<char>* arr_t = nullptr;

	try {
		arr_t = new CTypeArray<char>(arr_size);
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

	std::cout << "Array after creation and initial fill:\n";
	arr_t->random_fill();

	std::cout << *arr_t << std::endl;

	search_value = 'W';

	std::cout << "Inserting value " << search_value << " to begining of the array. Resulting array:\n";
	arr_t->insert(search_value);
	std::cout << *arr_t << std::endl;

	search_value = 'G';
	std::cout << "Adding value " << search_value << " to the end of the array. Resulting array:\n";
	arr_t->add(search_value);
	std::cout << *arr_t << std::endl;

	found_idx = 7;
	search_value = 'l';

	std::cout << "Inserting value " << search_value << " to index " << found_idx << " of the array. Resulting array:\n";
	arr_t->insert(search_value, found_idx);
	std::cout << *arr_t << std::endl;

	found_idx = 3;
	search_value = 'T';
	(*arr_t)[found_idx] = search_value;
	std::cout << "Updating value through index operation:  array[" << found_idx << "] = " << search_value << ".Resulting array:\n";
	arr_t->Show();

	arr_size = 15;
	std::cout << "Increasing array size to  " << arr_size << ". Resulting array:\n";
	arr_t->resize(arr_size);
	std::cout << *arr_t << std::endl;

	found_idx = 17;
	search_value = 'F';
	std::cout << "Inserting value " << search_value << " to index " << found_idx << ",exeeding the array size. Resulting array:\n";
	arr_t->insert(search_value, found_idx);
	std::cout << *arr_t << std::endl;

	search_value = 'T';
	std::cout << "Looking for value " << search_value << " in the array. Result: ";
	found_idx = arr_t->index_of(search_value);
	if (found_idx == -1)
		std::cout << "Value " << search_value << " not found\n";
	else
		std::cout << "Value " << search_value << " found at index " << found_idx << "\n";

	std::cout << "Removing the value " << search_value << " from the array. Resulting array:\n";
	arr_t->remove(found_idx);
	std::cout << *arr_t << std::endl;

	arr_size = 10;
	std::cout << "Decreasing array size to  " << arr_size << ". Resulting array:\n";
	arr_t->resize(arr_size);
	std::cout << *arr_t << std::endl;



	delete arr_t;
}
//----------------------------------------------------------------------------------------------------------
void test_string_array() {
	int arr_size{ 10 }, found_idx{ -1 };
	std::string search_value("");
	CTypeArray<std::string>* arr_t = nullptr;
	try {
		arr_t = new CTypeArray<std::string>(arr_size);
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

	std::cout << "Array after creation and initial fill:\n";
	arr_t->random_fill();

	std::cout << *arr_t << std::endl;

	search_value = "Long";

	std::cout << "Inserting value " << search_value << " to begining of the array. Resulting array:\n";
	arr_t->insert(search_value);
	std::cout << *arr_t << std::endl;

	search_value = "to";
	std::cout << "Adding value " << search_value << " to the end of the array. Resulting array:\n";
	arr_t->add(search_value);
	std::cout << *arr_t << std::endl;

	found_idx = 8;
	search_value = "bad";

	std::cout << "Inserting value " << search_value << " to index " << found_idx << " of the array. Resulting array:\n";
	arr_t->insert(search_value, found_idx);
	std::cout << *arr_t << std::endl;

	found_idx = 11;
	search_value = "needed";
	(*arr_t)[found_idx] = search_value;
	std::cout << "Updating value through index operation:  array[" << found_idx << "] = " << search_value << ".Resulting array:\n";
	arr_t->Show();

	arr_size = 15;
	std::cout << "Increasing array size to  " << arr_size << ". Resulting array:\n";
	arr_t->resize(arr_size);
	std::cout << *arr_t << std::endl;

	found_idx = 17;
	search_value = "The end";
	std::cout << "Inserting value " << search_value << " to index " << found_idx << ",exeeding the array size. Resulting array:\n";
	arr_t->insert(search_value, found_idx);
	std::cout << *arr_t << std::endl;

	search_value = "bad";
	std::cout << "Looking for value " << search_value << " in the array. Result: ";
	found_idx = arr_t->index_of(search_value);
	if (found_idx == -1)
		std::cout << "Value " << search_value << " not found\n";
	else
		std::cout << "Value " << search_value << " found at index " << found_idx << "\n";

	std::cout << "Removing the value " << search_value << " from the array. Resulting array:\n";
	arr_t->remove(found_idx);
	std::cout << *arr_t << std::endl;

	arr_size = 10;
	std::cout << "Decreasing array size to  " << arr_size << ". Resulting array:\n";
	arr_t->resize(arr_size);
	std::cout << *arr_t << std::endl;



	delete arr_t;

}
//----------------------------------------------------------------------------------------------------------



