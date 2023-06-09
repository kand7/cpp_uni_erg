/* ΟΝΟΜΑ : ΒΙΚΤΩΡ
    ΕΠΩΝΥΜΟ : ΡΟΜΑΝΙΟΥΚ
    ΑΜ : 713242017024*/
// ΑΣΚΗΣΗ 3//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "ask3-subjects.h"

using namespace std;

/* Error Codes*/
/*
5 : ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
6 : ΜΗΔΕΝΙΚΕΣ-ΑΡΝΗΤΙΚΕΣ ΩΡΕΣ ΔΙΔΑΣΚΑΛΙΑΣ ΜΑΘΗΜΑΤΟΣ
7 : ΤΟ ΜΑΘΗΜΑ ΥΠΑΡΧΕΙ ΗΔΗ ΣΤΑ ΔΗΛΩΜΕΝΑ ΜΑΘΗΜΑΤΑ ΤΟΥ ΦΟΙΤΗΤΗ
8 : ΤΟ ΜΑΘΗΜΑ ΕΙΝΑΙ ΗΔΗ ΠΕΡΑΣΜΕΝΟ, ΓΙΑΤΙ ΝΑ ΤΟ ΞΑΝΑΔΗΛΩΣΕΙΣ/ΒΑΛΕΙΣ ΣΤΑ ΠΕΡΑΣΜΕΝΑ
9 : Ο ΒΑΘΜΟΣ ΔΕΝ ΜΠΟΡΕΙ ΝΑ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΟΣ ΤΟΥ 5 ΚΑΙ ΜΕΓΑΛΥΤΕΡΟΣ ΤΟΥ 10
*/

Subject::Subject(string id, string name, unsigned int hours, int semester) : subjectID{id}, subjectName{name}, subjectHours{hours}
{
    if (semester <= 0)
        throw 5; // ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
    subjectSemester.second = semester;
    if ((semester % 2) == 1)
        subjectSemester.first = "Χειμερινό";
    else if ((semester % 2) == 0)
        subjectSemester.first = "Εαρινό";
}
// ΠΛΗΡΟΦΟΡΙΕΣ ΜΑΘΗΜΑΤΟΣ
void Subject::printSubjectInformation(ostream &out) const
{
    if (out.good())
        out << "Κωδικός Μαθήματος: " << getSubjectID() << "\nΌνομα Μαθήματος: " << getSubjectName() << "\nΏρες Διδασκαλίας: " << getSubjectHours() << "\nΕξάμηνο: " << getSubjectSemesterString() << ", " << getSubjectSemesterInt() << endl
            << endl;
    else
    {
        cout << "ΠΡΟΒΛΗΜΑ ΜΕ ΤΟ ΚΑΝΑΛΙ" << endl;
    }
}
// GETTERS
string Subject::getSubjectName() const noexcept
{
    return subjectName;
}
string Subject::getSubjectID() const noexcept
{
    return subjectID;
}
unsigned int Subject::getSubjectHours() const noexcept
{
    return subjectHours;
}
unsigned int Subject::getSubjectSemesterInt() const noexcept
{
    return subjectSemester.second;
}
string Subject::getSubjectSemesterString() const noexcept
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
void Subject::setSubjectHours(int hours)
{
    if (hours <= 0)
        throw 6; // ΜΗΔΕΝΙΚΕΣ-ΑΡΝΗΤΙΚΕΣ ΩΡΕΣ ΔΙΔΑΣΚΑΛΙΑΣ ΜΑΘΗΜΑΤΟΣ
    subjectHours = hours;
}
void Subject::setSubjectSemester(int semester)
{
    if (semester <= 0)
        throw 5; // ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
    subjectSemester.second = semester;
    if ((semester % 2) == 1)
        subjectSemester.first = "Χειμερινό";
    else if ((semester % 2) == 0)
        subjectSemester.first = "Εαρινό";
}