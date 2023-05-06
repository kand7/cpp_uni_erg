/*
    Ονοματεπώνυμο: Άγγελος Τζώρτζης
    Α.Μ.: ice18390094
    Άσκηση 2.
    Κωδικοποιήση: UTF-8
*/

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
    void setId(const char *);
    void setFullName(string);
    void setCurrentSemester(unsigned int);

    // Methods.
    void printInfo(ostream &);
    Student &operator++();   // Prefix operator.
    Student operator++(int); // Postfix operator.
    Student &operator+=(unsigned int);
    Student &operator-=(unsigned int);

    // Class variables.
private:
    char *id;
    string fullName;
    unsigned int currentSemester;
};

int main(int argc, char **argv)
{
    // Δημιουργία αντικειμένων με όλους τους constructors που έχουμε.
    Student st1("ice18390094", "Άγγελος Τζώρτζης");
    Student st2("ice00000001", "John Cena", 10);
    Student st3(st1);

    // Εκτύπωση των πληροφοριών των αντικειμένων.
    cout << "Before changes:" << endl;
    // Μπορούμε να επιλέξουμε όποιο κανάλι θέλουμε για έξοδο και εδώ επιλέγουμε το cout.
    st1.printInfo(cout);
    st2.printInfo(cout);
    st3.printInfo(cout);

    // Λειτουργία των setters.
    st1.setCurrentSemester(2);
    st2.setFullName("Michael Bisping");
    st3.setId("ice00000002");

    cout << endl;
    cout << "Getters example:" << endl;
    // Έλεγχος ειτουργία των getters.
    cout << "st1 id: " << st1.getId() << endl;
    cout << "st2 semester: " << st2.getCurrentSemester() << endl;
    cout << "st3 full name: " << st3.getFullName() << endl;

    // Έλεγχος υπερφόρτωσης τελεστών.
    st1++;
    ++st2;
    st3 += 5;

    cout << endl;
    // Εκτυπώνουμε τις πληροφορίες των αντικειμένων για να επιβεβαιώσουμε ότι έγιναν οι αλλαγές.
    cout << "After using the overloaded operators:" << endl;
    st1.printInfo(cout); // Tο εξάμηνο θα βγεί καθώς το αλλάξαμε σε 2 και μετα αυξήθηκε κατα 1.
    st2.printInfo(cout);
    st3.printInfo(cout);

    return 0;
}

Student::Student(const char *id, string fullName)
{
    int size = strlen(id);

    // Δεσμέυουμε χώρο για τον καινούριο αριθμό μητρώου.
    this->id = new char[size + 1];
    // Αντιγράφουμε τον αριθμό μητρώου του ορίσματος στον χώρο που δεσμέυσαμε.
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

void Student::setId(const char *id)
{
    // Διαγράφουμε την μνήμη του παλιού αριθμού μητρώου.
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

//
void Student::printInfo(ostream &out)
{
    // Γράφουμε στο κανάλι της επιλογής μας.
    out << "Name: " << this->fullName << ", I.D.: " << this->id << ", Semester: " << this->currentSemester << "." << endl;
}

Student &Student::operator++()
{
    ++this->currentSemester;
    return *this;
}

Student Student::operator++(int)
{
    // Εφόσον είναι τελεστής μεταύξησης θέλουμε να επιστρέφεται η τιμή πρίν αυξήσουμε το εξάμηνο.
    Student temp = *this;
    this->currentSemester++;
    return temp;
}

Student &Student::operator+=(unsigned int addSemester)
{
    this->currentSemester += addSemester;
    return *this;
}

Student &Student::operator-=(unsigned int subSemester)
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
