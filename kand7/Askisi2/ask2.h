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
    // Α
    Student(const char *, string);
    // Β
    Student(const char *, string, unsigned int);
    // Γ (ΑΝΤΙΓΡΑΦΕΑΣ)
    Student(const Student &);
    // ΚΑΤΑΣΤΡΟΦΕΑΣ
    ~Student();
    // GETTERS
    char *getAm() const;
    string getName() const;
    unsigned int getSemester() const;
    // SETTER
    void setAm(const char *);
    void setName(string);
    void setSemester(unsigned int);
    // ΕΚΤΥΠΩΣΗ ΣΤΟΙΧΕΙΩΝ ΣΕ ΟΠΟΙΟΔΗΠΟΤΕ ΚΑΝΑΛΙ ΕΞΟΔΟΥ
    void printInformation(ostream &) const;
    // ΜΕΤΑΑΥΞΗΣΗ
    // ΟΙ ΤΥΠΟΥ ΕΠΙΣΤΡΟΦΗΣ ΕΙΝΑΙ ΟΛΟΙ Student, ΘΑ ΜΠΟΡΟΥΣΑΜΕ ΝΑ ΔΩΣΟΥΜΕ ΚΑΙ ΑΝΑΦΟΡΑ
    Student operator++(int);
    // ΥΛΟΠΟΙΗΘΗΚΕ ΚΑΙ Η ΠΡΟΑΥΞΗΣΗ ΓΙΑ ΕΞΑΣΚΗΣΗ
    Student operator++();
    // ΤΕΛΕΣΤΗΣ +=
    Student operator+=(unsigned int);
    Student operator+=(Student &);
    Student operator-=(unsigned int);
    Student operator-=(Student &);
    Student & operator=(const Student &); // ΓΙΑ ΝΑ ΜΠΟΡΕΣΩ ΝΑ ΚΑΝΩ student4 = ++student3;
};