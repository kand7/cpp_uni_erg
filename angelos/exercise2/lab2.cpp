#include <iostream>
#include <string.h>

using namespace std;

class Student
{
public:
    Student(const char *, string);
    Student(const char *, string, unsigned int);
    Student(Student &);

    ~Student();

    char *getId() const;
    string getFullName() const;
    unsigned int getCurrentSemester() const;

    void setId(char *);
    void setFullName(string);
    void setCurrentSemester(unsigned int);

    void printInfo();
    Student &operator++();
    Student &operator+=(int);
    Student &operator-=(int);

private:
    char *id;
    string fullName;
    unsigned int currentSemester;
};

int main(int argc, char **argv)
{
    Student st1("ice18390094", "Angelos Tzortzis");
    Student st2("ice18390175", "Ioannis Palasis", 10);
    Student st3(st1);

    st1.printInfo();
    st2.printInfo();
    st3.printInfo();

    return 0;
}

Student::Student(const char *id, string fullName)
{
    int size = strlen(id);
    this->id = new char[size + 1];
    strcpy(this->id, id);
    this->fullName = fullName;
    this->currentSemester = 1;
}

Student::Student(const char *id, string fullName, unsigned int currentSemester)
{
    int size = strlen(id);
    this->id = new char[size + 1];
    strcpy(this->id, id);
    this->fullName = fullName;
    this->currentSemester = currentSemester;
}

Student::Student(Student &copyStudent)
{
    int size = strlen(copyStudent.id);
    this->id = new char[size + 1];
    strcpy(this->id, copyStudent.id);
    this->fullName = copyStudent.fullName;
    this->currentSemester = copyStudent.currentSemester;
}

Student::~Student()
{
}

void Student::setId(char *id)
{
    int size = strlen(id);
    this->id = new char[size + 1];
    strcpy(this->id, id);
}

void Student::setFullName(string fullName)
{
    this->fullName = fullName;
}

void Student::setCurrentSemester(unsigned int currentSemester)
{
    this->currentSemester = currentSemester;
}

void Student::printInfo()
{
    cout << "Name: " << this->fullName << ", I.D.: " << this->id << ", Semester: " << this->currentSemester << "." << endl;
}

Student &Student::operator++()
{
}

Student &Student::operator+=(int addSemester)
{
}

Student &Student::operator-=(int subSemester)
{
}

char *Student::getId() const
{
    return this->id;
}

string Student::getFullName() const
{
    return this->fullName;
}

unsigned int Student::getCurrentSemester() const
{
    return this->currentSemester;
}
