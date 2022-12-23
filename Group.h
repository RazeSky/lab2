#pragma once
#include "Student.h"
using namespace std;

class Group {
private:
	Student* Value;
	int size;
	int number;
	float av_grade;
	string subject;
public:
	Group();
	Group(const Group& obj);
	~Group();
	void SetGroup();
	int GetSize();
	void Add();
	void Del();
	float Calculate();
	void Ball();
	void Expulsion();
	void Red_student(int x);
	friend ostream& operator<< (ostream& out, Group& obj);
	Group& operator= (Group& obj);
	void Print(ostream& out);
	void PrintStudents();
};