#include "Univer.h"

Univer::Univer() {
	Value = nullptr;
	size = 0;
}

Univer::~Univer() {}

int Univer::GetSize() {
	return size;
}

void Univer::Add() {
	Group* temp = new Group  [size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = Value[i];
	}
	/*if (size == 0)
	{
		temp[0].SetGroup();
	}*/
	
	temp[size].SetGroup();
	
	if (Value)
		delete[] Value;
	Value = temp;
	size++;
}

void Univer::AddStudent(int group) {
	Value[group].Add();
}

void Univer::Del(int group) {
	if (size == 0) {
		cout << "Группы отсутствуют!" << endl;
		return;
	}
	if (size == 1) {
		delete[] Value;
		Value = nullptr;
		size--;
	}
	else {
		Group* temp = new Group[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (i != group)
				temp[j++] = Value[i];
		}	
		delete[] Value;
		Value = temp;
		size--;
	}
}
void Univer::Reduct(int group, int ch)
{
	if (ch == 1)
	{
		Group* temp = new Group[size];

		for (int i = 0; i < size; i++)
		{
			temp[i] = Value[i];
		}

		temp[group].SetGroup();

		if (Value)
			delete[] Value;
		Value = temp;
	}
	else if (ch == 2)
	{
		Value[group].PrintStudents();
		Group* temp = new Group[size];

		for (int i = 0; i < size; i++)
		{
			temp[i] = Value[i];
		}
		cout << "Введите номер студента для изменения:" << endl;
		int x;
		cin >> x;
		x -= 1;
		temp[group].Red_student(x);
		//temp[group].SetGroup();

		if (Value)
			delete[] Value;
		Value = temp;
	}
	
}
void Univer::DelStudent(int group) {
	Value[group].PrintStudents();
	Value[group].Del();
	
}

void Univer::Calculate(int group) {//средний балл группы
	
	Value[group].Calculate()/GetSize();
	
}

void Univer::PrintStudents(int group) {
	Value[group].PrintStudents();
}
void Univer::SRBall(int group) {//средний балл студента
	Value[group].Ball();
}
void Univer::Ball_2(int group)//отчисление
{
	Value[group].Expulsion();
}
ostream& operator<< (ostream& out, Univer& obj) {
	for (int i = 0; i < obj.size; i++) {
		obj.Value[i].Print(out);
	}
	return out;
}
