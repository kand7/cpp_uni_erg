
#include <iostream>
#include <string.h>

using namespace std;

class Student
{
public:
    // Constructors.
    Student(const char *, string);
    Student(const char *, string, unsigned int);
    Student(Student &);
    // Destructor.
    ~Student();

    // Getters.
    char *getId() const;
    string getFullName() const;
    unsigned int getCurrentSemester() const;

    // Setters.
    void setId(char *);
    void setFullName(string);
    void setCurrentSemester(unsigned int);

    // Methods.
    void printInfo(ostream&);
    Student &operator++();    // Prefix operator.
    Student &operator++(int); // Postfix operator.
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
    Student st2("ice00000001", "John Cena", 10);
    Student st3(st1);

    st1.printInfo(cout);
    st2.printInfo(cout);
    st3.printInfo(cout);

    st1++;
    ++st2;
    st3 += 5;

    cout << endl;

    st1.printInfo(cout);
    st2.printInfo(cout);
    st3.printInfo(cout);

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
    delete[] id;
}

void Student::setId(char *id)
{
    delete[] this->id;
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

void Student::printInfo(ostream& out)
{
    out << "Name: " << this->fullName << ", I.D.: " << this->id << ", Semester: " << this->currentSemester << "." << endl;
}

Student &Student::operator++()
{
    ++this->currentSemester;
    return *this;
}

Student &Student::operator++(int)
{
	Student tmp = *this;
    this->currentSemester++;
    return tmp;
}

Student &Student::operator+=(int addSemester)
{
    this->currentSemester += addSemester;
    return *this;
}

Student &Student::operator-=(int subSemester)
{
    this->currentSemester -= subSemester;
    return *this;
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

