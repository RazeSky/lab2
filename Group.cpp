#include "Group.h"

Group::Group() {
	Value = nullptr;
	size = 0;
	number = 0;
	av_grade = 0;
	subject = "";
}

Group::Group(const Group& obj) {
	Value = obj.Value;
	size = obj.size;
	number = obj.number;
	av_grade = obj.av_grade;
	subject = obj.subject;
}

Group::~Group() {}

void Group::SetGroup() {
	setlocale(LC_ALL, "Rus");
	cout << "Введите номер группы:";
	cin >> this->number;
	cout << "Введите изучаемый предмет:";
	cin.ignore(256, '\n');
	getline(cin, this->subject);
}

int Group::GetSize() {
	return size;
}

void Group::Add() {
	Student* temp = new Student[size + 1];
	int i = 0;
	while (i < size) {
		temp[i] = Value[i];
		i++;
	}
	cin >> temp[size]; //добавление студентов
	//temp[size].SetStudent();
	size++;
	if (Value)
		delete[] Value;
	Value = temp;
}


void Group::Del() {
	if (size == 0)
		throw string("Unable to delete student. Group is empty");

	int number1; // номер студента
	cout << "Введите номер студента для удаления: ";
	cin >> number1; // считываем номер
	//cout << Value[number1];
	// если номер не входит в нужный интервал, бросаем исключение
	if (number1 < 1 || number1 > size)
		throw string("Номер студента должен быть от 1 до" + to_string(size));

	// сдвигаем студентов
	for (int i = number1; i < size; i++) {
		Value[i - 1] = Value[i];
	}
	Student* temp = new Student[size];
	int j = 0;
	for (int i = 0; i < size; i++)
		temp[j++] = Value[i];
	delete[] Value;
	Value = temp;
	size--; // уменьшаем размер
	cout << "Студент удален" << endl;
}

//void Group::Calculate() {
//	for (int i = 0; i < size; i++)
//	{
//		av_grade += Value[i].GetGrade();
//	}
//		
//	av_grade /= size;
//}
float Group::Calculate() {
		av_grade = 0;
		for (int i = 0; i < size; i++)
		{
			av_grade += Value[i].GetGrade();
		}
			
		return av_grade /= size;
	}
void Group::Ball() {
	int count = 0; // число студентов
	// проверяем каждого студенты
	cout<<number<<endl;
	for (int i = 0; i < GetSize(); i++) {
		// если балл выше 4, выводим его
		
			if (Value[i].GetGrade() >= 4)
			{
				// если это был 1 студент, то выводим инфу
				cout << Value[i] << endl;
				count++;
			}
	}
	// если не было ни одного студенты, то выводим это
	if (count == 0)
		cout << endl << "Нет студентов со средним баллом выше 4" << endl;
}
void Group::Expulsion()//на отчисление
{
	int count = 0; // число студентов

	// проверяем каждого студенты
	cout << number << endl;
	for (int i = 0; i < GetSize(); i++) {
		// если балл выше 4, выводим его

		if (Value[i].GetGrade() < 3)
		{
			// если это был 1 студент, то выводим инфу
			cout << Value[i] << endl;
			count++;
		}
	}

	// если не было ни одного студенты, то выводим это
	if (count == 0)
		cout << endl << "Нет студентов на отчисление" << endl;
}
ostream& operator<< (ostream& out, Group& obj) {
	for (int i = 0; i < obj.size; i++) {
		obj.Value[i].Print(out);
	}
	return out;
}


Group& Group::operator= (Group& obj) {
	Value = obj.Value;
	size = obj.size;
	number = obj.number;
	av_grade = obj.av_grade;
	subject = obj.subject;
	return *this;
}

void Group::Print(ostream& out) {
	out << endl << "Номер группы: " << number << endl
		<< "Изучаемый предмет: " << subject << endl
		<< "Размер группы: " << size << endl
		<< "Средний балл: " << av_grade << endl;
}

void Group::PrintStudents() {
	for (int i = 0; i < this->size; i++)
	{
		cout <<i+1<<". "<< Value[i];
	}
	
}
void  Group::Red_student(int x) {
	cout << Value[x];
	cin >> Value[x];
	
}
