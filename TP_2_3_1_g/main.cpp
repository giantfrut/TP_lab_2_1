#include "Student.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Student>& students);
void changeObject(Marray<Student>& students);
void deleteObject(Marray<Student>& students);
void print(Marray<Student>& students);
void searchObjects(Marray<Student>& students);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Student> students;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			addObject(students);
			break;
		case 2:
			changeObject(students);
			break;
		case 3:
			deleteObject(students);
			break;
		case 4:
			print(students);
			break;
		case 5:
			searchObjects(students);
			break;
		case 0:

			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. �������� ������" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. ������� ������" << endl;
	cout << "4. ������� ������" << endl;
	cout << "5. ������� ������� �������� � ������ �����, ������� ������ ���� 2" << endl;
	cout << "0. �����" << endl;
	cout << "�������� ����� ����: ";
}

void addObject(Marray<Student>& students) {
	Student student;
	student.inputFromConsole();
	students += student;
	students.sort();
}

void changeObject(Marray<Student>& students) {
	if (students.getSize() > 0) {
		print(students);
		cout << "������� ����� �������� ��� ���������: ";
		students[safeInput(1, students.getSize()) - 1].change();
	}
	else
		cout << "������ ��������� ����. ������ ��������\n";
	students.sort();
}

void deleteObject(Marray<Student>& students) {
	if (students.getSize() > 0) {
		print(students);
		cout << "������� ����� �������� ��� ��������: ";
		students -= safeInput(1, students.getSize()) - 1;
	}
	else
		cout << "������ ��������� ����. ������ �������\n";
	students.sort();
}

void print(Marray<Student>& students) {
	if (students.getSize() == 0)
		cout << "������ ��������� ����.\n";
	else {
		cout << "������ ���������\n";
		for (int i = 0; i < students.getSize(); i++) {
			cout << i + 1 << ". �������\n";
			students[i].printToConsole();
		}
	}
}

void searchObjects(Marray<Student>& students) {
	if (students.getSize() == 0)
		cout << "������ ��������� ����\n";
	else {
		bool isPrint = false;
		for (int i = 0; i < students.getSize(); i++) {
			Marray<pair<string, int>> objects = students[i].gettObjects();
			for (int j = 0; j < objects.getSize(); j++)
				if (objects[j].second == 2) {
					isPrint = true;
					cout << students[i].getNumberGroup() << " " << students[i].getSecondName() << endl;
				}
		}
			
		if (!isPrint)
			cout << "��������� ���� �� � ����� 2 ���\n";
	}
}