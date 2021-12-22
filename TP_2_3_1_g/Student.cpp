#include "Student.h"

Student::Student() : secondName("�� ������"), iniciales("�� ������"), numberGroup(0)
{
	cout << "������ ����������� Student" << endl;
}

Student::Student(string secondName, string iniciales, int numberGroup, Marray<std::pair<string, int>> objects) :
	secondName(secondName), iniciales(iniciales), numberGroup(numberGroup), objects(objects)
{
	cout << "������ ����������� Student" << endl;
}

Student::Student(const Student& student) : secondName(student.secondName), iniciales(student.iniciales), numberGroup(student.numberGroup), objects(student.objects)
{
	cout << "������ ����������� ����������� Student" << endl;
}

Student::~Student()
{
	cout << "������ ���������� Student" << endl;
}

void Student::inputFromConsole()
{
	cout << "������� �������: ";
	getline(cin, secondName);
	cout << "������� ��������(A.A.): ";
	iniciales = inputIniciales();
	cout << "������� ����� ������: ";
	numberGroup = safeInput(1, INT32_MAX);
	cout << "������� ���������� ���������: ";
	int countMarks = safeInput(1, INT32_MAX);
	for (int i = 0; i < countMarks; i++) {
		cout << "������� " << i + 1 << " �������: ";
		string tmp;
		getline(cin, tmp);
		cout << "������� ������ �� ����� ��������: ";
		objects += make_pair(tmp, safeInput(1, 5));
	}
}

void Student::printToConsole()
{
	cout << "���: " << secondName << " " << iniciales << endl;
	cout << "����� ������: " << numberGroup << endl;
	cout << "��������: ";
	for (int i = 0; i < objects.getSize(); i++)
		cout << i + 1 << ". " << objects[i].first << " " << objects[i].second << endl;
}

void Student::change()
{
	objects.clear();
	cout << "������� ����� �������: ";
	getline(cin, secondName);
	cout << "������� ����� ��������: ";
	getline(cin, iniciales);
	cout << "������� ����� ����� ������: ";
	numberGroup = safeInput(1, INT32_MAX);
	cout << "������� ����� ���������� ���������: ";
	int countMarks = safeInput(1, INT32_MAX);
	for (int i = 0; i < countMarks; i++) {
		cout << "������� " << i + 1 << " �������: ";
		string tmp;
		getline(cin, tmp);
		cout << "������� ������ �� ����� ��������: ";
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