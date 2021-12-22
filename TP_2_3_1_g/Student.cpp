#include "Student.h"

Student::Student() : secondName("Не задано"), iniciales("Не задано"), numberGroup(0)
{
	cout << "Вызван конструктор Student" << endl;
}

Student::Student(string secondName, string iniciales, int numberGroup, Marray<std::pair<string, int>> objects) :
	secondName(secondName), iniciales(iniciales), numberGroup(numberGroup), objects(objects)
{
	cout << "Вызван конструктор Student" << endl;
}

Student::Student(const Student& student) : secondName(student.secondName), iniciales(student.iniciales), numberGroup(student.numberGroup), objects(student.objects)
{
	cout << "Вызван конструктор копирования Student" << endl;
}

Student::~Student()
{
	cout << "Вызван деструктор Student" << endl;
}

void Student::inputFromConsole()
{
	cout << "Введите фамилию: ";
	getline(cin, secondName);
	cout << "Введите инициалы(A.A.): ";
	iniciales = inputIniciales();
	cout << "Введите номер группы: ";
	numberGroup = safeInput(1, INT32_MAX);
	cout << "Введите количество предметов: ";
	int countMarks = safeInput(1, INT32_MAX);
	for (int i = 0; i < countMarks; i++) {
		cout << "Введите " << i + 1 << " предмет: ";
		string tmp;
		getline(cin, tmp);
		cout << "Введите оценку по этому предмету: ";
		objects += make_pair(tmp, safeInput(1, 5));
	}
}

void Student::printToConsole()
{
	cout << "ФИО: " << secondName << " " << iniciales << endl;
	cout << "Номер группы: " << numberGroup << endl;
	cout << "Предметы: ";
	for (int i = 0; i < objects.getSize(); i++)
		cout << i + 1 << ". " << objects[i].first << " " << objects[i].second << endl;
}

void Student::change()
{
	objects.clear();
	cout << "Введите новую фамилию: ";
	getline(cin, secondName);
	cout << "Введите новые инициалы: ";
	getline(cin, iniciales);
	cout << "Введите новый номер группы: ";
	numberGroup = safeInput(1, INT32_MAX);
	cout << "Введите новое количество предметов: ";
	int countMarks = safeInput(1, INT32_MAX);
	for (int i = 0; i < countMarks; i++) {
		cout << "Введите " << i + 1 << " предмет: ";
		string tmp;
		getline(cin, tmp);
		cout << "Введите оценку по этому предмету: ";
		objects += make_pair(tmp, safeInput(1, 5));
	}
}

double Student::getAverageMark() {
	int sum = 0;
	for (int i = 0; i < objects.getSize(); i++)
		sum += objects[i].second;
	return double(sum) / double(objects.getSize());
}

Student& Student::operator=(const Student& student) {
	if (this == &student)
		return *this;
	secondName = student.secondName;
	iniciales = student.iniciales;
	numberGroup = student.numberGroup;
	objects = student.objects;
	return *this;
}

bool Student::operator>(Student& student) {
	return getAverageMark() > student.getAverageMark();
}