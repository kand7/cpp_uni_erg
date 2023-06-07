/* ΟΝΟΜΑ : ΒΙΚΤΩΡ
    ΕΠΩΝΥΜΟ : ΡΟΜΑΝΙΟΥΚ
    ΑΜ : 713242017024*/
// ΑΣΚΗΣΗ 3//
#include <iostream>
#include <string.h>
#include <cctype>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void openSelSubjectsFile(fstream &file)
{
    file.open("selected-subjects.csv", ios::out | ios::app);
    if (!file.good())
    {
        file.close();
    }
}

void openStudentsFile(fstream &file)
{
    file.open("students.csv", ios::out | ios ::app);
    if (!file.good())
    {
        file.close();
    }
}
void openPasSubjectsFile(fstream &file)
{
    file.open("passed-subjects.csv", ios::out | ios::app);
    if (!file.good())
    {
        file.close();
    }
}
class Subject
{
    // ΙΔΙΟΤΗΤΕΣ
private:
    string subjectID;
    string subjectName;
    unsigned int subjectHours;
    pair<string, unsigned int> subjectSemester;
    // ΜΕΘΟΔΟΙ
public:
    Subject(string, string, unsigned int, unsigned int); // ΚΑΤΑΣΚΕΥΑΣΤΗΣ ΜΑΘΗΜΑ
    void subjectInformation() const noexcept;            // ΕΚΤΥΠΩΣΗ ΠΛΗΡΟΦΟΡΙΩΝ ΣΤΗΝ ΚΟΝΣΟΛΑ
    // GETTERS
    string getSubjectID() const noexcept;
    string getSubjectName() const noexcept;
    unsigned int getSubjectHours() const noexcept;
    unsigned int getSubjectSemesterInt() const noexcept;
    string getSubjectSemesterString() const noexcept;
    // SETTERS
    void setSubjectID(string);
    void setSubjectName(string);
    void setSubjectHours(unsigned int);
    void setSubjectSemester(int);
};
Subject::Subject(string id, string name, unsigned int hours, unsigned int semester) : subjectID{id}, subjectName{name}, subjectHours{hours}
{
    subjectSemester.second = semester;
    if ((semester % 2) == 1)
        subjectSemester.first = "Χειμερινό";
    else if ((semester % 2) == 0)
        subjectSemester.first = "Εαρινό";
    else
        throw 5;
}
void Subject::subjectInformation() const
{
    cout << "Κωδικός Μαθήματος: " << subjectID << "\nΌνομα Μαθήματος: " << subjectName << "\nΏρες Διδασκαλίας: " << subjectHours << "\nΕξάμηνο: " << subjectSemester.first << ", " << subjectSemester.second << endl;
}
string Subject::getSubjectName() const
{
    return subjectName;
}
string Subject::getSubjectID() const
{
    return subjectID;
}
unsigned int Subject::getSubjectHours() const
{
    return subjectHours;
}
unsigned int Subject::getSubjectSemesterInt() const
{
    return subjectSemester.second;
}
string Subject::getSubjectSemesterString() const
{
    return subjectSemester.first;
}
void Subject::setSubjectID(string id)
{
    subjectID = id;
}
void Subject::setSubjectName(string name)
{
    subjectName = name;
}
void Subject::setSubjectHours(unsigned int hours)
{
    if (hours <= 0)
        throw 5;
    subjectHours = hours;
}
void Subject::setSubjectSemester(int semester)
{
    subjectSemester.second = semester;
    if ((semester % 2) == 1)
        subjectSemester.first = "Χειμερινό";
    else if ((semester % 2) == 0)
        subjectSemester.first = "Εαρινό";
    else
        throw 5;
}
typedef vector<Subject *> selSubjects;
typedef vector<pair<Subject *, double>> pasSubjects;
class Student
{
    // ΙΔΙΟΤΗΤΕΣ
private:
    char *am;
    string name;
    unsigned int semester;
    selSubjects selectedSubjects; // ΛΙΣΤΑ ΜΕ ΔΕΙΚΤΕΣ ΣΤΑ ΔΗΛΩΜΕΝΑ ΜΑΘΗΜΑΤΑ
    pasSubjects passedSubjects;   // ΛΙΣΤΑ ΜΕ ΔΕΙΚΤΕΣ ΣΤΑ ΠΕΡΑΣΜΕΝΑ ΜΑΘΗΜΑΤΑ ΚΑΙ ΤΟΝ ΑΝΤΙΣΤΟΙΧΟ ΒΑΘΜΟ
    // ΜΕΘΟΔΟΙ
public:
    // ΚΑΤΑΣΚΕΥΑΣΤΕΣ
    // Α
    Student(const char *, string);
    // Β
    Student(const char *, string, int);
    // Γ (ΑΝΤΙΓΡΑΦΕΑΣ)
    Student(const Student &);
    // ΜΠΟΡΟΥΜΕ ΝΑ ΠΕΡΑΣΟΥΜΕ ΚΑΙ ΛΙΣΤΑ ΜΕ ΜΑΘΗΜΑΤΑ ΠΟΥ ΕΧΕΙ ΠΕΡΑΣΕΙ ΚΑΤΑ ΤΗΝ ΔΗΜΙΟΥΡΓΙΑ ΤΟΥ ΑΝΤΙΚΕΙΜΕΝΟΥ
    // ΜΕΛΛΟΝΤΙΚΗ ΜΕΘΟΔΟΣ ΠΟΥ ΔΙΑΒΑΖΕΙ ΕΝΑ .csv ΑΡΧΕΙΟ ΚΑΙ ΦΤΙΑΧΝΕΙ ΑΠΟ ΑΥΤΟ ΜΙΑ ΔΟΜΗ pasSubjects
    Student(const char *, string, int, pasSubjects);
    // ΚΑΤΑΣΤΡΟΦΕΑΣ
    ~Student();
    // GETTERS
    char *getAm() const noexcept;
    string getName() const noexcept;
    unsigned int getSemester() const noexcept;
    // SETTER
    void setAm(const char *);
    void setName(string);
    void setSemester(unsigned int);
    // ΕΚΤΥΠΩΣΗ ΣΤΟΙΧΕΙΩΝ ΣΕ ΟΠΟΙΟΔΗΠΟΤΕ ΚΑΝΑΛΙ ΕΞΟΔΟΥ
    void printInformation(ostream &) const;
    void saveInformation() const;             // in development
    void addSubject(Subject *);               // ΠΡΟΣΘΗΚΗ ΜΑΘΗΜΑΤΟΣ ΣΤΑ ΔΗΛΩΜΕΝΑ
    void addPassedSubject(Subject *, double); // ΠΡΟΣΘΗΚΗ ΜΑΘΗΜΑΤΟΣ ΣΤΑ ΠΕΡΑΣΜΕΝΑ ΚΑΙ ΤΟΝ ΒΑΘΜΟ ΤΟΥ

    // ΤΕΛΕΣΤΕΣ
    // ΟΙ ΤΥΠΟΥ ΕΠΙΣΤΡΟΦΗΣ ΕΙΝΑΙ ΟΛΟΙ Student, ΘΑ ΜΠΟΡΟΥΣΑΜΕ ΝΑ ΔΩΣΟΥΜΕ ΚΑΙ ΑΝΑΦΟΡΑ

    Student operator++(int); // ΜΕΤΑ-Α
    Student operator++();    // ΠΡΟ-Α
    Student operator+=(unsigned int);
    Student operator+=(const Student &);
    Student operator-=(unsigned int);
    Student operator-=(Student &);
    Student &operator=(const Student &); // ΓΙΑ ΝΑ ΜΠΟΡΕΣΩ ΝΑ ΚΑΝΩ student4 = ++student3;
    void operator+=(Subject *) noexcept;
    bool operator==(const Student &) const noexcept;
    bool operator!=(const Student &) const noexcept;
    bool operator<(const Student &) const noexcept;
    bool operator<=(const Student &) const noexcept;
    bool operator>(const Student &) const noexcept;
    bool operator>=(const Student &) const noexcept;
};
// ΚΑΤΑΣΚΕΥΑΣΤΗΣ ΜΕ ΑΜ ΚΑΙ ΟΝΟΜΑΤΕΠΩΝΥΜΟ
Student::Student(const char *am, string name)
{
    this->name = name;
    this->semester = 1;
    this->am = new char[strlen(am) + 1];
    strcpy(this->am, am);
}
// ΚΑΤΑΣΚΕΥΑΣΤΗΣ ΜΕ ΟΛΑ ΤΑ ΣΤΟΙΧΕΙΑ
Student::Student(const char *am, string name, int semester)
{
    this->am = new char[strlen(am) + 1];
    strcpy(this->am, am);
    this->name = name;
    if (semester <= 0)
        throw 20;
    else
        this->semester = semester;
}
// ΚΑΤΑΣΚΕΥΑΣΤΗΣ ΜΕ ΜΑΘΗΜΑΤΑ ΚΑΤΑ ΤΗΝ ΔΗΜΙΟΥΡΓΙΑ ΤΟΥ ΑΝΤΙΚΕΙΜΕΝΟΥ
Student::Student(const char *am, string name, int semester, pasSubjects passedSubjects)
{
    this->am = new char[strlen(am) + 1];
    strcpy(this->am, am);
    this->name = name;
    if (semester <= 0)
        throw 20;
    else
        this->semester = semester;
    this->passedSubjects = passedSubjects;
}
// ΚΑΤΑΣΚΕΥΑΣΤΗΣ ΑΠΟ ΑΛΛΟ ΑΝΤΙΚΕΙΜΕΝΟ - COPY CONSTRUCTOR
Student::Student(const Student &stud)
{
    this->am = new char[strlen(stud.am) + 1];
    strcpy(this->am, stud.am);
    this->name = stud.name;
    this->semester = stud.semester;
}
// ΚΑΤΑΣΤΡΟΦΕΑΣ
Student::~Student()
{
    delete[] this->am;
}
// GETTER AM
char *Student::getAm() const
{
    return this->am;
}
// GETTER NAME
string Student::getName() const
{
    return this->name;
}
// GETTER SEMESTER
unsigned int Student::getSemester() const
{

    return this->semester;
}
// SETTER AM
void Student::setAm(const char *am)
{
    delete[] this->am;
    this->am = new char[strlen(am) + 1];
    strcpy(this->am, am);
}
// SETTER NAME
void Student::setName(string name)
{
    this->name = name;
}
// SETTER SEMESTER
void Student::setSemester(unsigned int semester)
{
    if (semester < 0)
        throw 20;
    else
        this->semester = semester;
}
void Student::printInformation(ostream &out) const
{
    out << "AΡΙΘΜΟΣ ΜΗΤΡΩΟΥ: " << this->am << "\nΟΝΟΜΑΤΕΠΩΝΥΜΟ: " << this->name << "\nΕΞΑΜΗΝΟ: " << this->semester << endl;
    out << "---Δηλωμένα Μαθήματα---\n";
    for (auto i : selectedSubjects)
    {
        i->subjectInformation(out);
        printf("\n");
    }
    out << "---Περασμένα Μαθήματα---\n";
    for (auto i : passedSubjects)
    {
        out << i.first->getSubjectName() << "\t";
        out << i.second << endl;
    }
}
void Student::saveInformation() const
{
    double avg = 0;
    try
    {
        fstream studFile;
        openStudentsFile(studFile);
        fstream selFile;
        openSelSubjectsFile(selFile);
        fstream passFile;
        openPasSubjectsFile(passFile);
        studFile << string(getAm()) << "," << getName() << "," << getSemester() << endl;
        for (auto subject : selectedSubjects)
        {
            selFile << subject->getSubjectID() << "," << subject->getSubjectName() << "," << subject->getSubjectHours() << "," << subject->getSubjectSemester() << endl;
        }
        for (auto subject : passedSubjects)
        {
            avg += subject.second;
            passFile << subject.first->getSubjectID() << "," << subject.first->getSubjectName() << "," << subject.first->getSubjectSemester() << endl;
        }
        passFile << (avg / passedSubjects.size()) << endl;
    }
    catch (int e)
    {
        cout << "Error Reading - Opening Files\n";
    }
}
// ΜΕΤΑ-ΑΥΞΗΣΗ
Student Student::operator++(int)
{
    // ΧΡΕΙΑΖΟΜΑΣΤΕ ΕΝΑ TEMP ΑΝΤΙΚΕΙΜΕΝΟ ΤΟ ΟΠΟΙΟ ΘΑ ΕΠΙΣΤΡΑΦΕΙ ΤΗ ΠΑΛΙΑ ΤΙΜΗ ΤΟΥ ΑΝΤΙΚΕΙΜΕΝΟΥ ΠΡΙΝ ΤΗΝ ΑΥΞΗΣΗ
    Student temp = *this;
    this->semester++;
    return temp;
}
// ΠΡΟ-ΑΥΞΗΣΗ
Student Student::operator++()
{
    this->semester = this->semester + 1;
    return *this;
}
// += ΜΕ ΜΗ-ΠΡΟΣΙΜΑΣΜΕΝΟ ΑΚΕΡΑΙΟ
Student Student::operator+=(unsigned int semester)
{
    this->semester = this->semester + semester;
    return *this;
}
// += ΣΕ ΜΕ ΑΛΛΟΝ ΦΟΙΤΗΤΗ
Student Student::operator+=(const Student &s)
{
    this->semester = this->semester + s.semester;
    return *this;
}
Student Student::operator-=(unsigned int semester)
{
    if (this->semester > semester)
    {
        this->semester -= semester;
    }
    else
        cout << "Μη-προσιμασμένος ακέραιος εκτός ορίων" << endl;
    return *this; // ΘΑ ΕΠΙΣΤΡΑΦΗ ΤΟ ΑΠΟΤΕΛΕΣΜΑ ΑΝ ΟΛΑ ΕΙΝΑΙ ΕΝΤΑΞΗ Ή ΘΑ ΠΑΡΑΜΕΙΝΕΙ Η ΠΑΛΙΑ ΤΙΜΗ
}
Student Student::operator-=(Student &s)
{
    if (this->semester > s.semester)
    {
        this->semester -= s.semester;
    }
    else
        cout << "Μη-προσιμασμένος ακέραιος εκτός ορίων" << endl;
    return *this; // ΘΑ ΕΠΙΣΤΡΑΦΗ ΤΟ ΑΠΟΤΕΛΕΣΜΑ ΑΝ ΟΛΑ ΕΙΝΑΙ ΕΝΤΑΞΗ Ή ΘΑ ΠΑΡΑΜΕΙΝΕΙ Η ΠΑΛΙΑ ΤΙΜΗ
}
// (ΕΧΤΡΑ) ΥΠΕΡΦΟΤΩΣΗ ΤΟΥ = ΓΙΑ ΝΑ ΜΠΟΡΕΣΩ ΝΑ ΤΡΕΞΩ stud1 = ++std2. Ο stud1 έχει δημιουργηθεί πρίν.
Student &Student::operator=(const Student &s)
{
    if (!(this == &s))
    {
        delete[] this->am;
        this->am = new char[strlen(s.am) + 1];
        strcpy(this->am, s.am);
        this->name = s.name;
        this->semester = s.semester;
    }
    return *this;
}
void Student::addSubject(Subject *sub)
{
    if (binary_search(selectedSubjects.begin(), selectedSubjects.end(), sub))
    {

        cout << "Found";
        throw 10;
    }
    else
        selectedSubjects.push_back(sub);
}
void Student::addPassedSubject(Subject *sub, double mark)
{
    for (int i = 0; i < passedSubjects.size(); i++)
    {
        if ((passedSubjects[i].first) == sub)
        {
            throw 10;
        }
    }
    if (mark < 5 || mark > 10)
        throw 5;
    else
    {
        passedSubjects.push_back(make_pair(sub, mark));
    }
}
void Student::operator+=(Subject *sub) noexcept
{
    addSubject(sub);
}
bool Student::operator==(const Student &stud) const noexcept
{
    if (this->semester == stud.semester)
        return true;
    else
        return false;
}
bool Student::operator!=(const Student &stud) const noexcept
{
    if (this->semester != stud.semester)
        return true;
    else
        return false;
}
bool Student::operator<(const Student &stud) const noexcept
{
    if (this->semester < stud.semester)
        return true;
    else
        return false;
}
bool Student::operator<=(const Student &stud) const noexcept
{
    if (this->semester <= stud.semester)
        return true;
    else
        return false;
}
bool Student::operator>(const Student &stud) const noexcept
{
    if (this->semester > stud.semester)
        return true;
    else
        return false;
}
bool Student::operator>=(const Student &stud) const noexcept
{
    if (this->semester >= stud.semester)
        return true;
    else
        return false;
}
int main()
{
    int i = 0;
    vector<Subject *> allSubjects;
    allSubjects.push_back(new Subject("2131", "Μαθηματικά", 5, 10));
    allSubjects.push_back(new Subject("1321", "Φυσική", 7, 2));
    allSubjects.push_back(new Subject("1121", "Γλώσσα", 4, 8));
    allSubjects.push_back(new Subject("8902", "Χημεία", 6, 1));
    Student a("71324", "ΒΙΚΤΩΡ", 5);
    // for (auto i : allSubjects)
    // {
    //     i->printInformation(cout);
    //     printf("\n");
    // }

    try
    {
        a += allSubjects[0];
        a += allSubjects[1];
        a += allSubjects[2];
        a += allSubjects[3];
    }
    catch (int e)
    {
        cout << "Το μάθημα υπάρχει ήδη στην δηλωμένη λίστα\n";
    }
    while (i < allSubjects.size())
    {
        try
        {
            double mark;
            char passed;
            cout << "Μάθημα " << allSubjects[i]->getSubjectName() << endl;
            cout << "Το έχεις περάσει (Y/N); : ";
            cin >> passed;
            if (tolower(passed) == 'y')
            {
                cout << "Δώσε βαθμό: ";
                cin >> mark;
                a.addPassedSubject(allSubjects[i], mark);
                i++;
            }
            else
            {
                i++;
                continue;
            }
        }
        catch (int e)
        {
            if (e == 5)
                cout << "Λάθος Βαθμός\n";
            if (e == 10)
                cout
                    << "Το μάθημα υπάρχει ήδη στην δηλωμένη λίστα\n";
        }
    }
    printf("\n");
    a.saveInformation();
}
