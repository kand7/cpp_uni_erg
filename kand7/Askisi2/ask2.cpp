#include <iostream>
#include <string.h>
#include "ask2.h"

using namespace std;
// Consturctor A
Student::Student(const char *am, string name)
{
	int sizeAm = strlen(am);
	this->name = name;
	this->semester = 1;
	this->am = new char[sizeAm + 1];
	for (int i = 0; i < sizeAm; i++)
	{
		this->am[i] = am[i];
	}
}
// Consturctor B
Student::Student(const char *am, string name, unsigned int semester)
{
	int sizeAm = strlen(am);
	this->name = name;
	this->semester = semester;
	this->am = new char[sizeAm + 1];
	strcpy(this->am, am);
}
// Consturctor C
Student::Student(const Student &stud)
{
	int sizeAm = strlen(stud.am);
	this->am = new char[sizeAm + 1];
	strcpy(this->am, stud.am);
	this->name = stud.name;
	this->semester = stud.semester;
}
// Destructor
Student::~Student()
{
	delete[] this->am;
}
// Getter AM
char *Student::getAm()
{
	int amSize = strlen(this->am);
	char *studentsAm = new char[amSize + 1];
	strcpy(studentsAm, this->am);
	return studentsAm;
}
// Getter Name
string Student::getName()
{
	return this->name;
}
// Getter Semester
unsigned int Student::getSemester()
{
	return this->semester;
}
// Setter AM
void Student::setAm(const char *am)
{
	delete[] this->am;
	int sizeAm = strlen(am);
	this->am = new char[sizeAm + 1];
	strcpy(this->am, am);
}
// Setter Name
void Student::setName(string name)
{
	this->name = name;
}
// Setter Semester
void Student::setSemester(unsigned int semester)
{
	this->semester = semester;
}
void Student::printInformation(ostream &out)
{
	out << "AM : ";
	for (int i = 0; i < strlen(this->am); i++)
	{
		out << this->am[i];
	}
	out << ", Name : " << this->name << ", Semester : " << this->semester << endl;
}
void Student::operator++(int)
{
	this->semester++;
}
Student &Student::operator++()
{
	++this->semester;
	return *this;
}
Student &Student::operator+=(const Student &st)
{
	this->semester += st.semester;
	return *this;
}
Student &Student::operator-=(const Student &st)
{
	this->semester -= st.semester;
	return *this;
}
Student &Student::operator+=(unsigned int a)
{
	this->semester += a;
	return *this;
}
Student &Student::operator-=(unsigned int a)
{
	this->semester -= a;
	return *this;
}
int main()
{
	Student student1 = Student("16665", "Viktor Romanyuk");
	Student student2 = Student("69696969", "Aggelos Yo", 11);
	Student student3 = Student(student2);
	student1.printInformation(cout);
	student2.printInformation(cout);
	student3.printInformation(cout);
	student1++;
	cout << student1.getSemester();
	++student1;
	printf("\n");
	cout << student1.getSemester();
	student1 += student3;
	cout << " " << student1.getSemester();
	student1 -= student3;
	cout << " " << student1.getSemester();
	student1 += 10000;
	cout << " " << student1.getSemester();
	return 0;
}
