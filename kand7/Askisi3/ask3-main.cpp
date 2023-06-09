
/* ΟΝΟΜΑ : ΒΙΚΤΩΡ
    ΕΠΩΝΥΜΟ : ΡΟΜΑΝΙΟΥΚ
    ΑΜ : 713242017024*/
// ΑΣΚΗΣΗ 3//

// To compile run -> g++ ask3-student.cpp ask3-subject.cpp ask3-main.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "ask3-subjects.h"
#include "ask3-students.h"

using namespace std;

/* Error Codes*/
/*
5 : ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
6 : ΜΗΔΕΝΙΚΕΣ-ΑΡΝΗΤΙΚΕΣ ΩΡΕΣ ΔΙΔΑΣΚΑΛΙΑΣ ΜΑΘΗΜΑΤΟΣ
7 : ΤΟ ΜΑΘΗΜΑ ΥΠΑΡΧΕΙ ΗΔΗ ΣΤΑ ΔΗΛΩΜΕΝΑ ΜΑΘΗΜΑΤΑ ΤΟΥ ΦΟΙΤΗΤΗ
8 : ΤΟ ΜΑΘΗΜΑ ΕΙΝΑΙ ΗΔΗ ΠΕΡΑΣΜΕΝΟ, ΓΙΑΤΙ ΝΑ ΤΟ ΞΑΝΑΔΗΛΩΣΕΙΣ/ΒΑΛΕΙΣ ΣΤΑ ΠΕΡΑΣΜΕΝΑ
9 : Ο ΒΑΘΜΟΣ ΔΕΝ ΜΠΟΡΕΙ ΝΑ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΟΣ ΤΟΥ 5 Η ΜΕΓΑΛΥΤΕΡΟΣ ΤΟΥ 10
*/

// ΜΕΘΟΔΟΣ Η ΟΠΟΙΑ ΔΕΝ ΕΙΝΑΙ FRIEND ΚΑΙ ΜΑΣ ΕΠΙΤΡΕΠΕΙ ΝΑ ΚΑΝΟΥΜΕ cout << student_object ή ΣΕ ΟΠΟΙΟΔΗΠΟΤΕ ΑΛΛΟ ΚΑΝΑΛΙ
ostream &operator<<(ostream &out, const Student &stud)
{
    if (out.good())
    {
        out << "AΡΙΘΜΟΣ ΜΗΤΡΩΟΥ: " << stud.getAm() << "\nΟΝΟΜΑΤΕΠΩΝΥΜΟ: " << stud.getName() << "\nΕΞΑΜΗΝΟ: " << stud.getSemester() << endl;
        out << "---Δηλωμένα Μαθήματα---\n";
        for (auto &i : stud.getSelSubjects())
        {
            i->printSubjectInformation(out);
        }
        out << "---Περασμένα Μαθήματα---\n";
        for (auto &i : stud.getPasSubjects())
        {
            out << i.first->getSubjectID() << "\t";
            out << i.first->getSubjectName() << "\t";
            out << i.second << endl;
        }

        out << "Μ.Ο: " << stud.avgCalc() << endl;
    }
    else
        out << "ΠΡΟΒΛΗΜΑ ΜΕ ΤΟ ΚΑΝΑΛΙ" << endl;
    return out;
}
// ΜΕΘΟΔΟΣ ΠΟΥ ΑΡΧΙΚΟΠΟΙΕΙ ΤΙΣ ΣΤΗΛΕΣ ΣΤΑ csv ΑΡΧΕΙΑ
void createCSV()
{
    fstream studFile, selFile, passFile;
    studFile.open("students.csv", ios::out);
    selFile.open("selected-subjects.csv", ios::out);
    passFile.open("passed-subjects.csv", ios::out);
    if (studFile.good() && selFile.good() && passFile.good())
    {
        studFile << "AM"
                 << ","
                 << "ΟΝΟΜΑ"
                 << ","
                 << "ΕΞΑΜΗΝΟ" << endl;

        selFile << "AM"
                << ","
                << "ΚΩΔΙΚΟΣ ΜΑΘΗΜΑΤΟΣ"
                << ","
                << "ΟΝΟΜΑ ΜΑΘΗΜΑΤΟΣ"
                << ","
                << "ΩΡΕΣ ΜΑΘΗΜΑΤΟΣ"
                << ","
                << "ΕΞΑΜΗΝΟ" << endl;
        passFile << "ΑΜ"
                 << ","
                 << "ΚΩΔΙΚΟΣ ΜΑΘΗΜΑΤΟΣ"
                 << ","
                 << "ΟΝΟΜΑ ΜΑΘΗΜΑΤΟΣ"
                 << ","
                 << "ΕΞΑΜΗΝΟ"
                 << "," << endl;
    }
    studFile.close();
    selFile.close();
    passFile.close();
}
int main()
{
    createCSV();
    vector<Subject *> allSubjects; // ΔΥΝΑΜΙΚΟΣ ΠΙΝΑΚΑΣ ΠΟΥ ΘΑ ΠΕΡΙΕΧΕΙ ΟΛΑ ΤΑ ΜΑΘΗΜΑΤΑ ΠΟΥ ΦΤΙΑΞΑΜΕ
    allSubjects.push_back(new Subject("2131", "Μαθηματικά", 5, 4));
    allSubjects.push_back(new Subject("1321", "Φυσική", 7, 1));
    allSubjects.push_back(new Subject("1121", "Γλώσσα", 4, 2));
    allSubjects.push_back(new Subject("8902", "Χημεία", 6, 3));
    allSubjects.push_back(new Subject("8302", "Αγγλικά", 2, 3));
    allSubjects.push_back(new Subject("1032", "Κατανεμημένα Συστήματα", 5, 8));
    allSubjects.push_back(new Subject("5203", "Δίκτυα Υπολογιστών", 4, 5));
    allSubjects.push_back(new Subject("0013", "Στατιστική και Πιθανότητες", 7, 3));
    allSubjects.push_back(new Subject("8080", "Δομές Δεδομένων", 6, 4));
    allSubjects.push_back(new Subject("8111", "Ψηφιακές Επικοινωνίες", 6, 8));
    allSubjects.push_back(new Subject("8112", "Σήματα και Συστήματα", 4, 4));
    allSubjects.push_back(new Subject("5332", "Γραμμική Άλγεβρα", 7, 1));
    allSubjects.push_back(new Subject("0032", "Θεωρία Υπολογισμού", 4, 7));

    try
    {
        // ΕΧΟΥΜΕ try-catch ΕΠΕΙΔΗ ΜΠΟΡΕΙ ΝΑ ΠΕΤΑΞΕΙ EXCEPTION ΣΕ ΠΕΡΙΠΤΩΣΗ ΠΟΥ ΤΟ ΕΞΑΜΗΝΟ ΠΟΥ ΒΑΛΑΜΕ ΕΙΝΑΙ ΑΡΝΗΤΙΚΟ Η ΜΗΔΕΝ
        Student a("71324", "ΒΙΚΤΩΡ ΡΟΜΑΝΙΟΥΚ", 5);
        Student b("80321", "ΒΑΣΙΛΗΣ ΒΑΣΙΛΙΟΥ", 12);
        Student c("90441", "ΓΙΩΡΓΟΣ ΓΕΩΡΓΙΟΥ", 5);
        Student d("15311", "ΔΗΜΗΤΡΗΣ ΔΗΜΗΤΡΙΟΥ", 4);
        Student e("00031", "ΚΩΣΤΑΣ ΚΩΣΤΑΝΤΙΝΟΥ", 2);
        // ΑΝ ΔΩΣΟΥΜΕ ΜΑΘΗΜΑ ΣΕ ΦΟΙΤΗΤΗ ΤΟ ΟΠΟΙΟ ΕΧΕΙ ΔΗΛΩΣΕΙ ΗΔΗ ΠΕΤΑΕΙ EXCEPTION.
        a.addSubject(allSubjects[0]);
        a.addSubject(allSubjects[1]);
        a.addSubject(allSubjects[2]);
        b.addSubject(allSubjects[5]);
        b.addSubject(allSubjects[8]);
        b.addSubject(allSubjects[1]);
        c.addSubject(allSubjects[10]);
        c.addSubject(allSubjects[3]);
        c.addSubject(allSubjects[0]);
        d.addSubject(allSubjects[6]);
        d.addSubject(allSubjects[7]);
        d.addSubject(allSubjects[8]);
        a.addPassedSubject(allSubjects[1], 5);
        a.addPassedSubject(allSubjects[9], 5.8);
        a.addPassedSubject(allSubjects[10], 8.9);
        b.addPassedSubject(allSubjects[1], 6.3);
        b.addPassedSubject(allSubjects[9], 9.2);
        b.addPassedSubject(allSubjects[5], 7.8);
        c.addPassedSubject(allSubjects[4], 5.3);
        c.addPassedSubject(allSubjects[2], 8.8);
        c.addPassedSubject(allSubjects[0], 5.9);
        d.addPassedSubject(allSubjects[11], 10);
        d.addPassedSubject(allSubjects[6], 9.8);
        d.addPassedSubject(allSubjects[3], 8.3);

        b.setSemester(10);
        c -= 2;
        d += -3;

        cout << "a : " << a << endl;
        a.saveInformation(); // ΓΙΑ ΝΑ ΜΗΝ ΕΧΟΥΜΕ ΔΙΠΛΗ ΓΡΑΜΜΗ ΣΤΟ .csv
        a = b;               // ΣΕ ΑΥΤΗΝ ΤΗΝ ΠΕΡΙΠΤΩΣΗ ΟΤΑΝ ΚΑΤΑΣΤΡΑΦΟΥΝ ΤΑ ΑΝΤΙΚΕΙΜΕΝΑ ΘΑ ΔΟΥΜΕ ΣΤΟ .csv ΑΡΧΕΙΟ ΔΥΟ ΙΔΙΕΣ ΕΓΓΡΑΦΕΣ ΕΠΕΙΔΗ Η ΣΥΝΑΡΤΗΣΗ ΑΠΟΘΗΚΕΥΣΗΣ ΣΤΟ ΑΡΧΕΙΟ ΤΡΕΧΕΙ ΚΑΤΑ ΤΗΝ
        // ΕΚΤΕΛΕΣΗ ΤΟΥ DESTRUCTOR. ΘΑ ΜΠΟΡΟΥΣΑΜΕ ΝΑ ΚΑΝΟΥΜΕ MANUALLY SAVE, ΩΣΤΕ ΝΑ ΑΝΤΙΜΕΤΩΠΙΣΟΥΜΕ ΑΥΤΟ ΤΟ ΠΡΟΒΛΗΜΑ
        a = a;
        cout << "a έγινε : " << a << endl;

        if (a > c)
        {
            cout << "a > c\n";
        }
        else if (a < b)
        {
            cout << "a < c\n";
        }
        else
        {
            cout << "a == c\n";
        }

        cout << "\n"
             << a << "\n"
             << c << "\n"
             << d << "\n"
             << e << endl;
        fstream output;
        output.open("output.txt", ios::out);
        output << "\n"
               << a << "\n"
               << c << "\n"
               << e << "\n"
               << d << endl;
        b.saveInformation();
        c.saveInformation();
        d.saveInformation();
        e.saveInformation(); // ΘΑ ΔΟΥΜΕ ΠΩΣ ΔΕΝ ΕΜΦΑΝΙΖΕΤΑΙ ΚΑΤΙ ΣΤΟ csv ΑΡΧΕΙΟ ΕΠΕΙΔΗ ΔΕΝ ΕΧΕΙ ΠΕΡΑΣΜΕΝΑ/ΔΗΛΩΜΕΝΑ ΜΑΘΗΜΑΤΑ
        output.close();
        //  d+=-4; EXCEPTION
        // c-=5; EXCEPTION
        // c.addPassedSubject(allSubjects[2], 8.3); EXCEPTION
        // c.addPassedSubject(allSubjects[3],11.3); EXCEPTION
        //  d.addSubject(allSubjects[6]); EXCEPTION
        //  b.setSemester(-10); //EXCEPTION
    }
    catch (int e)
    {
        // 5 : ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ
        // 6 : ΜΗΔΕΝΙΚΕΣ-ΑΡΝΗΤΙΚΕΣ ΩΡΕΣ ΔΙΔΑΣΚΑΛΙΑΣ ΜΑΘΗΜΑΤΟΣ
        // 7 : ΤΟ ΜΑΘΗΜΑ ΥΠΑΡΧΕΙ ΗΔΗ ΣΤΑ ΔΗΛΩΜΕΝΑ ΜΑΘΗΜΑΤΑ ΤΟΥ ΦΟΙΤΗΤΗ
        // 8 : ΤΟ ΜΑΘΗΜΑ ΕΙΝΑΙ ΗΔΗ ΠΕΡΑΣΜΕΝΟ, ΓΙΑΤΙ ΝΑ ΤΟ ΞΑΝΑΔΗΛΩΣΕΙΣ/ΒΑΛΕΙΣ ΣΤΑ ΠΕΡΑΣΜΕΝΑ
        // 9 : Ο ΒΑΘΜΟΣ ΔΕΝ ΜΠΟΡΕΙ ΝΑ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΟΣ ΤΟΥ 5 ΚΑΙ ΜΕΓΑΛΥΤΕΡΟΣ ΤΟΥ 10
        if (e == 5)
            cout << "ΜΗΔΕΝΙΚΟ-ΑΡΝΗΤΙΚΟ ΕΞΑΜΗΝΟ" << endl;
        else if (e == 6)
            cout << "ΜΗΔΕΝΙΚΕΣ-ΑΡΝΗΤΙΚΕΣ ΩΡΕΣ ΔΙΔΑΣΚΑΛΙΑΣ ΜΑΘΗΜΑΤΟΣ" << endl;
        else if (e == 7)
            cout << "ΤΟ ΜΑΘΗΜΑ ΥΠΑΡΧΕΙ ΗΔΗ ΣΤΑ ΔΗΛΩΜΕΝΑ ΜΑΘΗΜΑΤΑ ΤΟΥ ΦΟΙΤΗΤΗ" << endl;
        else if (e == 8)
            cout << "ΤΟ ΜΑΘΗΜΑ ΕΙΝΑΙ ΗΔΗ ΠΕΡΑΣΜΕΝΟ, ΓΙΑΤΙ ΝΑ ΤΟ ΞΑΝΑΔΗΛΩΣΕΙΣ/ΒΑΛΕΙΣ ΣΤΑ ΠΕΡΑΣΜΕΝΑ" << endl;
        else if (e == 9)
            cout << "Ο ΒΑΘΜΟΣ ΔΕΝ ΜΠΟΡΕΙ ΝΑ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΟΣ ΤΟΥ 5 Η ΜΕΓΑΛΥΤΕΡΟΣ ΤΟΥ 10" << endl;
        else
            cout << "ΑΓΝΩΣΤΟ EXCEPTION" << endl;
    }
    catch (...)
    {
        cout << "ΑΓΝΩΣΤΟ EXCEPTION" << endl;
    }
    return 0;
}