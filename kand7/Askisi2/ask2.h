#include <iostream>
#include <string.h>

using namespace std;

class Student
{

private:
    char *am;
    string name;
    unsigned int semester;

public:
    // Constructors
    Student(const char *, string);
    Student(const char *, string, unsigned int);
    Student(const Student &);
    // Destructor
    ~Student();
    // Getters
    char *getAm();
    string getName();
    unsigned int getSemester();
    // Setters
    void setAm(const char *);
    void setName(string);
    void setSemester(unsigned int);
    // Print to any outstream
    void printInformation(ostream &);
    // Μετααύξηση
    void operator++(int);
    // Προαυξηση
    Student &operator++();
    // +=/-=
    Student &operator+=(const Student &);
    Student &operator-=(const Student &);
    Student &operator+=(unsigned int);
    Student &operator-=(unsigned int);
};