#include <iostream>
#include "stackarray.h"

using namespace std;

int main()
{
	StackArray *arr = new StackArray;
	
	int option = 0;
	int num;
	
	while (option != 6)
	{
		cout << "\nWELCOME TO THE STACK OPERATIONS\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Top\n";
		cout << "4. Check if Empty\n";
		cout << "5. Print Stack\n";
		cout << "6. Exit\n";
		cout << "Choose: ";
		cin >> option;
		
		switch(option)
		{
			case 1:
				cout << "Enter a num: ";
				cin >> num;
				arr->pushArr(num);
				break;
			case 2:
				cout << "Popping...\n";
				arr->popArr();
				break;
			case 3:
				cout << "Top Element: " << arr->topArr() << endl;
				break;
			case 4:
				cout << (arr->isEmptyArr()) ? "Stack is Empty.\n" : "Stack is not empty.\n";
				break;
			case 5:
				arr->printArr();
				break;
			case 6:
				cout << "Exiting...";
				return 0;
		}
	}
	
	return 0;
}
