#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef struct FIO {
	string Name;
	string SurName;
	string LastName;
};

class Student {
private:
	FIO Value;
	int grade[5];
public:
	Student();
	Student(const Student& obj);
	~Student();
	friend ostream& operator<< (ostream& out, Student& obj);//оператор ввода в поток
	friend istream& operator>>(istream& in, Student& obj); // оператор считывания из потока
	/*void SetStudent();*/
	float GetGrade();
	void Print(ostream& out);
};