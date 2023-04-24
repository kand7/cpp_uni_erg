#include <iostream>
#include <string.h>

using namespace std;

class Student
{
    // ΙΔΙΟΤΗΤΕΣ
private:
    char *am;
    string name;
    unsigned int semester;
    // ΜΕΘΟΔΟΙ
public:
    // ΚΑΤΑΣΚΕΥΑΣΤΕΣ
    Student(const char *, string);
    Student(const char *, string, unsigned int);
    Student(const Student &);
    // ΚΑΤΑΣΤΡΟΦΕΑΣ
    ~Student();
    // GETTERS
    char *getAm();
    string getName();
    unsigned int getSemester();
    // SETTER
    void setAm(const char *);
    void setName(string);
    void setSemester(unsigned int);
    // ΕΚΤΥΠΩΣΗ ΣΤΟΙΧΕΙΩΝ ΣΕ ΟΠΟΙΟΔΗΠΟΤΕ ΚΑΝΑΛΙ ΕΞΟΔΟΥ
    void printInformation(ostream &);
    // ΜΕΤΑΑΥΞΗΣΗ
    void operator++(int);
    // ΠΡΟΑΥΞΗΣΗ
    Student &operator++();
    // ΤΕΛΕΣΤΗΣ +=
    Student operator+=(const Student &);
};