/* ΟΝΟΜΑ : ΒΙΚΤΩΡ
    ΕΠΩΝΥΜΟ : ΡΟΜΑΝΙΟΥΚ
    ΑΜ : 713242017024*/
// ΑΣΚΗΣΗ 3//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "ask3-students.h"

using namespace std;

/* Error Codes*/
/*
5 : ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
6 : ΜΗΔΕΝΙΚΕΣ-ΑΡΝΗΤΙΚΕΣ ΩΡΕΣ ΔΙΔΑΣΚΑΛΙΑΣ ΜΑΘΗΜΑΤΟΣ
7 : ΤΟ ΜΑΘΗΜΑ ΥΠΑΡΧΕΙ ΗΔΗ ΣΤΑ ΔΗΛΩΜΕΝΑ ΜΑΘΗΜΑΤΑ ΤΟΥ ΦΟΙΤΗΤΗ
8 : ΤΟ ΜΑΘΗΜΑ ΕΙΝΑΙ ΗΔΗ ΠΕΡΑΣΜΕΝΟ, ΓΙΑΤΙ ΝΑ ΤΟ ΞΑΝΑΔΗΛΩΣΕΙΣ/ΒΑΛΕΙΣ ΣΤΑ ΠΕΡΑΣΜΕΝΑ
9 : Ο ΒΑΘΜΟΣ ΔΕΝ ΜΠΟΡΕΙ ΝΑ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΟΣ ΤΟΥ 5 ΚΑΙ ΜΕΓΑΛΥΤΕΡΟΣ ΤΟΥ 10
*/
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
    if (semester <= 0)
        throw 5; // ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
    this->am = new char[strlen(am) + 1];
    strcpy(this->am, am);
    this->name = name;
    this->semester = semester;
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
    //saveInformation(); uncomment ΓΙΑ ΝΑ ΓΡΑΦΟΝΤΑΙ ΤΑ ΔΕΔΟΜΕΝΑ ΣΤΟ ΑΡΧΕΙΟ ΚΑΤΑ ΤΗΝ ΔΙΑΓΡΑΦΗ ΤΟΥ ΑΝΤΙΚΕΙΜΕΝΟΥ
    delete[] this->am;
}
// GETTER AM
char *Student::getAm() const noexcept
{
    return this->am;
}
// GETTER NAME
string Student::getName() const noexcept
{
    return this->name;
}
// GETTER SEMESTER
unsigned int Student::getSemester() const noexcept
{
    return this->semester;
}
// GETTER ΠΙΝΑΚΑ ΜΕ ΠΕΡΑΣΜΕΝΑ ΜΑΘΗΜΑΤΑ
pasSubjects Student::getPasSubjects() const noexcept
{
    return this->passedSubjects;
}
// GETTER ΠΙΝΑΚΑ ΜΕ ΔΗΛΩΜΕΝΑ ΜΑΘΗΜΑΤΑ
selSubjects Student::getSelSubjects() const noexcept
{
    return this->selectedSubjects;
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
void Student::setSemester(int semester)
{
    if (semester <= 0)
        throw 5; // ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
    this->semester = semester;
}
// ΕΚΤΥΠΩΣΗ ΠΛΗΡΟΦΟΡΙΩΝ ΓΙΑ ΦΟΙΤΗΤΗ ΚΑΙ ΤΑ ΜΑΘΗΜΑΤΑ ΤΟΥ (ΣΕ ΟΠΟΙΟΔΗΠΟΤΕ ΚΑΝΑΛΙ)
void Student::printInformation(ostream &out) const
{
    if (out.good())
    {
        out << "AΡΙΘΜΟΣ ΜΗΤΡΩΟΥ: " << getAm() << "\nΟΝΟΜΑΤΕΠΩΝΥΜΟ: " << getName() << "\nΕΞΑΜΗΝΟ: " << getSemester() << endl;
        out << "---Δηλωμένα Μαθήματα---\n";
        for (auto &i : getSelSubjects())
        {
            i->printSubjectInformation(out);
        }
        out << "---Περασμένα Μαθήματα---\n";
        for (auto &i : getPasSubjects())
        {
            out << i.first->getSubjectName() << "\t";
            out << i.second << endl;
        }

        out << "Μ.Ο: " << avgCalc() << endl;
    }
    else
        out << "ΠΡΟΒΛΗΜΑ ΜΕ ΤΟ ΚΑΝΑΛΙ" << endl;
}
// ΜΕΘΟΔΟΙ ΑΝΟΙΓΜΑΤΟΣ ΑΡΧΕΙΟΥ ΓΙΑ ΑΠΟΘΗΚΕΥΣΗΣ ΔΕΔΟΜΕΝΩΝ
void Student::openSelSubjectsFile(fstream &file) const
{
    file.open("selected-subjects.csv", ios::out | ios::app);
    if (!file.good())
    {
        file.close();
    }
}
void Student::openStudentsFile(fstream &file) const
{
    file.open("students.csv", ios::out | ios ::app);
    if (!file.good())
    {
        file.close();
    }
}
void Student::openPasSubjectsFile(fstream &file) const
{
    file.open("passed-subjects.csv", ios::out | ios::app);
    if (!file.good())
    {
        file.close();
    }
}
// ΑΠΟΘΗΚΕΥΣΗ ΔΕΔΟΜΕΝΩΝ ΣΕ .csv ΑΡΧΕΙΟ
void Student::saveInformation() const
{
    double sum = 0;
    fstream studFile, selFile, passFile;
    openStudentsFile(studFile);
    openSelSubjectsFile(selFile);
    openPasSubjectsFile(passFile);
    studFile << string(getAm()) << "," << getName() << "," << getSemester() << endl;
    if (selectedSubjects.size() != 0)
    {
        for (auto subject : selectedSubjects)
        {
            selFile << getAm() << "," << subject->getSubjectID() << "," << subject->getSubjectName() << "," << subject->getSubjectHours() << "," << subject->getSubjectSemesterInt() << endl;
        }
    }
    if (passedSubjects.size() != 0)
    {

        for (auto subject : passedSubjects)
        {
            sum += subject.second;
            passFile << getAm() << "," << subject.first->getSubjectID() << "," << subject.first->getSubjectName() << "," << subject.first->getSubjectSemesterInt() << "," << subject.second << endl;
        }
        passFile << ","
                 << ","
                 << ","
                 << "," << (sum / passedSubjects.size()) << endl;
    }
    studFile.close();
    selFile.close();
    passFile.close();
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
Student Student::operator+=(int semester)
{
    if (((int)this->semester + semester <= 0))
        throw 5; // ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
    this->semester = this->semester + semester;
    return *this;
}
// += ΣΕ ΜΕ ΑΛΛΟΝ ΦΟΙΤΗΤΗ
Student Student::operator+=(const Student &s)
{
    this->semester = this->semester + s.semester;
    return *this;
}
Student Student::operator-=(int semester)
{
    if (((int)this->semester - semester) <= 0)
        throw 5; // ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
    this->semester -= semester;
    return *this;
}
Student Student::operator-=(Student &s)
{
    if (((int)this->semester - s.semester) <= 0)
        throw 5; // ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
    this->semester -= s.semester;
    return *this;
}
//  ΥΠΕΡΦΟΤΩΣΗ ΤΟΥ = ΓΙΑ ΝΑ ΜΠΟΡΕΣΩ ΝΑ ΤΡΕΞΩ stud1 = ++std2. Ο stud1 έχει δημιουργηθεί πρίν.
Student &Student::operator=(const Student &s)
{
    if (!(this == &s))
    {
        delete[] this->am;
        this->am = new char[strlen(s.am) + 1];
        strcpy(this->am, s.am);
        this->name = s.name;
        this->semester = s.semester;
        this->passedSubjects = s.passedSubjects;
        this->selectedSubjects = s.selectedSubjects;
    }
    return *this;
}
void Student::addSubject(Subject *sub)
{
    if (binary_search(selectedSubjects.begin(), selectedSubjects.end(), sub))
    {
        throw 7; // ΤΟ ΜΑΘΗΜΑ ΥΠΑΡΧΕΙ ΗΔΗ ΣΤΑ ΔΗΛΩΜΕΝΑ ΜΑΘΗΜΑΤΑ ΤΟΥ ΦΟΙΤΗΤΗ
    }
    for (const auto &subject : passedSubjects)
    {
        if (subject.first == sub)
        {
            throw 8; // ΤΟ ΜΑΘΗΜΑ ΕΙΝΑΙ ΗΔΗ ΠΕΡΑΣΜΕΝΟ, ΓΙΑΤΙ ΝΑ ΤΟ ΞΑΝΑΔΗΛΩΣΕΙΣ/ΒΑΛΕΙΣ ΣΤΑ ΠΕΡΑΣΜΕΝΑ
        }
    }
    selectedSubjects.push_back(sub);
}
void Student::addPassedSubject(Subject *sub, double mark)
{
    for (int i = 0; i < passedSubjects.size(); i++)
    {
        if ((passedSubjects[i].first) == sub)
        {
            throw 8; // ΤΟ ΜΑΘΗΜΑ ΕΙΝΑΙ ΗΔΗ ΠΕΡΑΣΜΕΝΟ, ΓΙΑΤΙ ΝΑ ΤΟ ΞΑΝΑΔΗΛΩΣΕΙΣ/ΒΑΛΕΙΣ ΣΤΑ ΠΕΡΑΣΜΕΝΑ
        }
    }
    if (mark < 5 || mark > 10)
        throw 9; // Ο ΒΑΘΜΟΣ ΔΕΝ ΜΠΟΡΕΙ ΝΑ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΟΣ ΤΟΥ 5 ΚΑΙ ΜΕΓΑΛΥΤΕΡΟΣ ΤΟΥ 10
    else
    {
        passedSubjects.push_back(make_pair(sub, mark));
    }
}
// ΥΠΟΛΟΓΙΣΜΟΣ Μ.Ο ΑΠΟ ΤΑ ΠΕΡΑΣΜΕΝΑ ΜΑΘΗΜΑΤΑ
double Student::avgCalc() const
{
    if (passedSubjects.size() != 0)
    {
        double sum = 0;
        for (const auto &pasSub : passedSubjects)
        {
            sum += pasSub.second;
        }
        return (sum / passedSubjects.size());
    }
    else
        return 0;
}
// ΝΕΕΣ ΥΠΕΡΦΟΡΤΩΣΕΙΣ ΤΕΛΕΣΤΩΝ
void Student::operator+=(Subject *sub) noexcept
{
    addSubject(sub);
}
bool Student::operator==(const Student &stud) const noexcept
{
    return (this->semester == stud.semester) ? true : false;
}
bool Student::operator!=(const Student &stud) const noexcept
{
    return (this->semester != stud.semester) ? true : false;
}
bool Student::operator<(const Student &stud) const noexcept
{
    return (this->semester < stud.semester) ? true : false;
}
bool Student::operator<=(const Student &stud) const noexcept
{
    return (this->semester <= stud.semester) ? true : false;
}
bool Student::operator>(const Student &stud) const noexcept
{
    return (this->semester > stud.semester) ? true : false;
}
bool Student::operator>=(const Student &stud) const noexcept
{
    return (this->semester >= stud.semester) ? true : false;
}
