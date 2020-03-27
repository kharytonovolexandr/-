#pragma once
#include<iostream>
#include<string>
using namespace std;

struct question
{
	string quesyionText;
	string trueAnswer;

};
struct quiz
{
	string title;
	question Questions[5];
};
void init();
void addQuiz();
void showQuizes();
void insertQuiz(quiz Quiz);
void passQuiz();