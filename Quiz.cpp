#include<iostream>
#include "Header.h"
using namespace std;
int main()
{
	init();
	int action = 0;

	do
	{
		cout << "1. Add new quiz" << endl;
		cout << "2. Show and pass  quizes" << endl;
		cout << "3. Exit" << endl;
		cout << endl;
		cout << "Select action";
		cin >> action;
		switch (action)
		{
		case 1:
		{
			addQuiz();
		}
			break;

		case 2: 
		{
			showQuizes();
			passQuiz();
		}break;
		case 3:
		{
			cout << "Good bye!" << endl;
		}break;
		default:
			break;
		}
	} while (action!=3);
	return 0;
}