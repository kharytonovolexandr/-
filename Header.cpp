#include "Header.h"
#include<fstream>
quiz* quizes;
int countQuizes = 0;
const int countQuestions = 5;
const string fileName = "Quizes.txt";

void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			quiz getQuiz;
			fin >> getQuiz.title;
			if (getQuiz.title != "")
			{
				for (int i = 0; i < countQuestions; i++)
				{
					fin >> getQuiz.Questions[i].quesyionText;
					fin >> getQuiz.Questions[i].trueAnswer;
				}
			}
			else { break; }

			insertQuiz(getQuiz);
		}
	}
	else {
		cout << "ERROR! File not open." << endl;
	}
}

void addQuiz()
{
	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();

	if (isOpen == true)
	{
		quiz* temp = new quiz[countQuizes + 1];
		for (int i = 0; i < countQuizes; i++)
		{
			temp[i] = quizes[i];
		}

		cout << "Enter quiz title:";
		cin >> temp[countQuizes].title;
		for (int i = 0; i < countQuestions; i++)
		{
			cout << "Enter" << i + 1 << "/5 question:";
			cin >> temp[countQuizes].Questions[i].quesyionText;
			cout << "Enter correct answer";
			cin >> temp[countQuizes].Questions[i].trueAnswer;

		}
		fout << temp[countQuizes].title << endl;
		for (int i = 0; i < countQuestions; i++)
		{
			fout << temp[countQuizes].Questions[i].quesyionText;
			fout << temp[countQuizes].Questions[i].trueAnswer;
		}
		countQuizes++;
		quizes = new quiz[countQuizes];
		for (int i = 0; i < countQuizes; i++)
		{
			quizes[i] = temp[i];
		}
		delete[]temp;
	}
	else
	{
		cout << "ERROR! File not open." << endl;
	}
}

void showQuizes()
{
	for (int i = 0; i < countQuizes; i++)
	{
		cout << i + 1 << ". " << quizes[i].title << endl;
	}
	cout << endl;
}

void passQuiz()
{
	int selectQuiz = 0;
	int score = 0;

	cout << "Enter number quiz for start pass:";
	cin >> selectQuiz;
	selectQuiz--;

	cout << endl;
	cout << "You start passing " << quizes[selectQuiz].title << endl;
	for (int i = 0; i < countQuestions; i++)
	{
		cout << quizes[selectQuiz].Questions[i].quesyionText << endl;
		string tempAnswer = "";
		cout << "Your answer: ";
		cin >> tempAnswer;

		if (quizes[selectQuiz].Questions[i].trueAnswer==tempAnswer)
		{
			cout << "It's right answer. (+20 score)" << endl;
			score += 20;
		}
		else {
			cout << "Wrong answer." << endl;

		}
		cout << "Your result: " << score << "/100" << endl;
	}
}

void insertQuiz(quiz Quiz)
{
	quiz* temp = new quiz[countQuizes + 1];
	for (int i = 0; i < countQuizes; i++)
	{
		temp[i] = quizes[i];
	}
	countQuizes++;
	quizes = new quiz[countQuizes];
	for (int i = 0; i < countQuizes; i++)
	{
		quizes[i] = temp[i];
	}
	delete[]temp;
}
