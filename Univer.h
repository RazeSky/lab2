#pragma once
#include "Group.h"
using namespace std;

class Univer {
private:
	Group* Value;
	int size;
	int count;
public:
	Univer();
	~Univer();
	int GetSize();
	void Add();
	void Reduct(int group,int ch);//редактирование
	void AddStudent(int group);
	void Del(int group);
	void DelStudent(int group);
	void Calculate(int group);
	void PrintStudents(int group); 
	void SRBall(int group);//средний балл
	void Ball_2(int group);//вывод студентов на отчисление
	
	friend ostream& operator<< (ostream& out, Univer& obj);
};