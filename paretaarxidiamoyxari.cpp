#include <iostream>
#include <string.h>

using namespace std;


class Student{
	
		private:
			char * am;
			string name;
			unsigned int semester;
			
		public:
			//Constructors
			Student(const char*,string);
			Student(const char*,string,unsigned int);
			Student(const Student&);
			void printInfo();
			//Getters
			char* getAm();
			string getName();
			unsigned int getSemester();
			//Setters
			void setAm(const char*);
			void setName(string);
			void setSemester(unsigned int);
};
//Consturctor A
Student::Student(const char* am,string name){
	int sizeAm = strlen(am);
	this->name = name;
	this->semester = 1;
	this->am = new char[sizeAm+1];
	for (int i = 0; i < sizeAm; i++){
		this->am[i] = am[i];
	}
	
}
//Consturctor B
Student::Student(const char* am,string name,unsigned int semester){
	int sizeAm = strlen(am);
	this->name = name;
	this->semester = semester;
	this->am = new char[sizeAm+1];
	strcpy(this->am,am);
}
//Consturctor C
Student::Student(const Student &stud){
	int sizeAm = strlen(stud.am);
	this->am = new char[sizeAm+1];
	strcpy(this->am,stud.am);
	this->name = stud.name;
	this->semester = stud.semester;
}
//Getter AM
char * Student::getAm(){
	int amSize = strlen(this->am);
	char* studentsAm = new char[amSize+1];
	strcpy(studentsAm,this->am);
	return studentsAm;
}
//Getter Name
string Student::getName(){
	return this->name;
}
//Getter Semester
unsigned int Student::getSemester(){
	return this->semester;
}
//Setter AM
void Student::setAm(const char* am){
	delete [] this->am;
	int sizeAm = strlen(am);
	this->am = new char[sizeAm+1];
	strcpy(this->am,am);
}
//Setter Name
void Student::setName(string name){
	this->name = name;
}
//Setter Semester
void Student::setSemester(unsigned int semester){
	this->semester = semester;
}
void Student::printInfo(){
	for (int i = 0; i < strlen(this->am); i++){
		cout << this->am[i];
	}
	cout << "\nName : " << this->name << " Semester : " << this->semester << endl;
}
main(){
	Student student1 = Student("16665","Viktor Romanyuk");
	Student student2 = Student("69696969", "Aggelos Yo",11);
	Student student3 = Student(student2);
	student1.printInfo();
	student2.printInfo();
	student3.printInfo();
	return 0;
}
