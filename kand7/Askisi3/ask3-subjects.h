/* ΟΝΟΜΑ : ΒΙΚΤΩΡ
    ΕΠΩΝΥΜΟ : ΡΟΜΑΝΙΟΥΚ
    ΑΜ : 713242017024*/
// ΑΣΚΗΣΗ 3//

#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* Error Codes*/
/*
5 : ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
6 : ΜΗΔΕΝΙΚΕΣ-ΑΡΝΗΤΙΚΕΣ ΩΡΕΣ ΔΙΔΑΣΚΑΛΙΑΣ ΜΑΘΗΜΑΤΟΣ
7 : ΤΟ ΜΑΘΗΜΑ ΥΠΑΡΧΕΙ ΗΔΗ ΣΤΑ ΔΗΛΩΜΕΝΑ ΜΑΘΗΜΑΤΑ ΤΟΥ ΦΟΙΤΗΤΗ
8 : ΤΟ ΜΑΘΗΜΑ ΕΙΝΑΙ ΗΔΗ ΠΕΡΑΣΜΕΝΟ, ΓΙΑΤΙ ΝΑ ΤΟ ΞΑΝΑΔΗΛΩΣΕΙΣ/ΒΑΛΕΙΣ ΣΤΑ ΠΕΡΑΣΜΕΝΑ
9 : Ο ΒΑΘΜΟΣ ΔΕΝ ΜΠΟΡΕΙ ΝΑ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΟΣ ΤΟΥ 5 ΚΑΙ ΜΕΓΑΛΥΤΕΡΟΣ ΤΟΥ 10
*/

class Subject
{

private:
    // ΙΔΙΟΤΗΤΕΣ
    string subjectID;
    string subjectName;
    unsigned int subjectHours;
    pair<string, unsigned int> subjectSemester;
    // ΜΕΘΟΔΟΙ
public:
    Subject(string, string, unsigned int, int);    // ΚΑΤΑΣΚΕΥΑΣΤΗΣ ΜΑΘΗΜΑ
    void printSubjectInformation(ostream &) const; // ΕΚΤΥΠΩΣΗ ΠΛΗΡΟΦΟΡΙΩΝ ΣΤΕ ΚΑΝΑΛΙ ΕΞΟΔΟΥ
    // GETTERS
    string getSubjectID() const noexcept;
    string getSubjectName() const noexcept;
    unsigned int getSubjectHours() const noexcept;
    unsigned int getSubjectSemesterInt() const noexcept;
    string getSubjectSemesterString() const noexcept;
    // SETTERS
    void setSubjectID(string);
    void setSubjectName(string);
    void setSubjectHours(int);
    void setSubjectSemester(int);
};
