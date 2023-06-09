/* ΟΝΟΜΑ : ΒΙΚΤΩΡ
    ΕΠΩΝΥΜΟ : ΡΟΜΑΝΙΟΥΚ
    ΑΜ : 713242017024*/
// ΑΣΚΗΣΗ 3//

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
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
// ΚΑΤΑΣΚΕΥΑΣΤΗΣ ΜΕ ΑΜ ΚΑΙ ΟΝΟΜΑΤΕΠΩΝΥΜΟ

// ΓΙΑ ΝΑ ΜΗΝ ΓΡΑΦΟΥΜΕ ΤΟΝ ΤΥΠΟ
using selSubjects = vector<Subject *>;
using pasSubjects = vector<pair<Subject *, double>>;

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
    Student(const char *, string);
    Student(const char *, string, int);
    Student(const Student &);
    // ΚΑΤΑΣΤΡΟΦΕΑΣ
    virtual ~Student(); // ΜΗΠΩΣ ΜΕΛΛΟΝΤΙΚΑ ΚΛΗΡΟΝΟΜΗΘΕΙ Η ΚΛΑΣΗ
    // GETTERS
    char *getAm() const noexcept;
    string getName() const noexcept;
    unsigned int getSemester() const noexcept;
    selSubjects getSelSubjects() const noexcept;
    pasSubjects getPasSubjects() const noexcept;
    // SETTER
    void setAm(const char *);
    void setName(string);
    void setSemester(int);
    // ΕΚΤΥΠΩΣΗ ΣΤΟΙΧΕΙΩΝ ΣΕ ΟΠΟΙΟΔΗΠΟΤΕ ΚΑΝΑΛΙ ΕΞΟΔΟΥ
    void printInformation(ostream &) const;
    // ΒΟΗΘΗΤΙΚΕΣ ΜΕΘΟΔΟΙ ΑΝΟΙΓΜΑΤΟΣ ΑΡΧΕΙΩΝ
    void openSelSubjectsFile(fstream &) const;
    void openStudentsFile(fstream &) const;
    void openPasSubjectsFile(fstream &) const;
    // ΑΠΟΘΗΚΕΥΣΗ ΣΤΑ ΑΡΧΕΙΑ .csv
    void saveInformation() const;
    // ΠΡΟΣΘΗΚΗ ΜΑΘΗΜΑΤΟΣ ΣΤΑ ΔΗΛΩΜΕΝΑ
    void addSubject(Subject *);
    // ΠΡΟΣΘΗΚΗ ΜΑΘΗΜΑΤΟΣ ΣΤΑ ΠΕΡΑΣΜΕΝΑ ΚΑΙ ΤΟΝ ΒΑΘΜΟ ΤΟΥ
    void addPassedSubject(Subject *, double);
    // ΥΠΟΛΟΓΙΣΜΟΣ Μ.Ο
    double avgCalc() const;
    // ΤΕΛΕΣΤΕΣ
    Student operator++(int); // ΜΕΤΑ-Α
    Student operator++();    // ΠΡΟ-Α
    Student operator+=(int);
    Student operator+=(const Student &);
    Student operator-=(int);
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
