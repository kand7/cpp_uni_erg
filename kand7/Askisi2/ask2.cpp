#include <iostream>
#include <string.h>
#include "ask2.h"
#include <limits.h>
using namespace std;
// ΚΑΤΑΣΚΕΥΑΣΤΗΣ ΜΕ ΑΜ ΚΑΙ ΟΝΟΜΑΤΕΠΩΝΥΜΟ
Student::Student(const char *am, string name)
{
	int sizeAm = strlen(am);
	this->name = name;
	this->semester = 1;
	this->am = new char[sizeAm + 1];
	// ΤΡΟΠΟΣ Α
	/*
	for (int i = 0; i < sizeAm; i++)
	{
		this->am[i] = am[i];
	}*/
	// ΤΡΟΠΟΣ Β
	strcpy(this->am, am);
}
// ΚΑΤΑΣΚΕΥΑΣΤΗΣ ΜΕ ΟΛΑ ΤΑ ΣΤΟΙΧΕΙΑ
Student::Student(const char *am, string name, unsigned int semester)
{
	int sizeAm = strlen(am);
	this->name = name;
	this->semester = semester;
	this->am = new char[sizeAm + 1];
	strcpy(this->am, am);
}
// ΚΑΤΑΣΚΕΥΑΣΤΗΣ ΑΠΟ ΑΛΛΟ ΑΝΤΙΚΕΙΜΕΝΟ - COPY CONSTRUCTOR
Student::Student(const Student &stud)
{
	int sizeAm = strlen(stud.am);
	this->am = new char[sizeAm + 1];
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
char *Student::getAm()
{
	return this->am;
}
// GETTER NAME
string Student::getName()
{
	return this->name;
}
// GETTER SEMESTER
unsigned int Student::getSemester()
{

	return this->semester;
}
// SETTER AM
void Student::setAm(const char *am)
{
	delete[] this->am;
	int sizeAm = strlen(am);
	this->am = new char[sizeAm + 1];
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
	this->semester = semester;
}
void Student::printInformation(ostream &out)
{
	// ΕΚΤΥΠΩΣΗ ΜΕ ΤΗΝ ΧΡΗΣΗ FOR
	/*
	out << "AM : ";

	for (int i = 0; i < strlen(this->am); i++)
	{
		out << this->am[i];
	}
	*/
	// out << ", Name : " << this->name << ", Semester : " << this->semester << endl;
	out << "AΡΙΘΜΟΣ ΜΗΤΡΩΟΥ : " << this->am << " , ΟΝΟΜΑΤΕΠΩΝΥΜΟ : " << this->name << " , ΕΞΑΜΗΝΟ : " << this->semester << endl;
}
// ΜΕΤΑ-ΑΥΞΗΣΗ
Student Student::operator++(int)
{
	// ΧΡΕΙΑΖΟΜΑΣΤΕ ΕΝΑ TEMP ΑΝΤΙΚΕΙΜΕΝΟ ΤΟ ΟΠΟΙΟ ΘΑ ΕΠΙΣΤΡΑΦΕΙ. Η ΠΑΛΙΑ ΤΙΜΗ ΤΟΥ ΚΑΝΟΝΙΚΟΥ ΜΑΣ ΑΝΤΙΚΕΙΜΕΝΟΥ ΠΡΙΝ ΤΗΝ ΑΥΞΗΣΗ
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
Student Student::operator+=(unsigned int semester)
{
	if (semester > 0 and semester < UINT_MAX)
	{
		this->semester = this->semester + semester;
	}
	else
		cout << "Μη-προσιμασμένος ακέραιος εκτός ορίων" << endl;
	return *this;
}
Student Student::operator+=(Student &s)
{
	if (s.semester > 0 and s.semester < UINT_MAX)
	{
		this->semester = this->semester + s.semester;
	}
	else
		cout << "Μη-προσιμασμένος ακέραιος εκτός ορίων" << endl;
	return *this;
}
Student Student::operator=(const Student &s)
{
	delete[] this->am;
	int sizeAM = strlen(s.am);
	this->am = new char[sizeAM + 1];
	strcpy(this->am, s.am);
	this->name = s.name;
	this->semester = s.semester;
	return *this;
}
int main()
{
	cout << "Ξεκινάει δημιουργία αντικειμένων με την χρήση των  κατασκευαστών..." << endl;
	Student student1("713242017024", "ΒΙΚΤΩΡ ΡΟΜΑΝΙΟΥΚ");
	Student student2("713242017025", "ΑΝΤΩΝΗΣ ΑΝΤΩΝΙΟΥ", 7);
	Student student3(student1);
	cout << "Εκτύπωση των στοιχείων κάθε φοιτητή" << endl;
	student1.printInformation(cout);
	student2.printInformation(cout);
	student3.printInformation(cout);
	// ΕΛΕΓΧΟΣ SETTERS
	cout << "Έλεγχος setters και getters" << endl;
	cout << "Αλλαγή εξαμήνου του πρώτου φοιτητή" << endl;
	student1.setSemester(15);
	cout << "Αλλαγή ονόματος του τρίτου φοιτητή" << endl;
	student3.setName("ΚΩΣΤΑΣ ΚΩΣΤΑΝΤΙΝΙΔΗΣ");
	cout << "Αλλαγή αριθμού μητρώου του δεύτερου φοιτητή" << endl;
	student2.setAm("ice45672");
	// ΕΛΕΓΧΟΣ GETTERS
	cout << "Το εξάμηνο του πρώτου φοιτητή πλέον ειναι : " << student1.getSemester() << endl;
	cout << "Το όνομα του τρίτου φοιτητή πλέον είναι : " << student3.getName() << endl;
	cout << "Ο αριθμός μητρώου του δεύτερου φοιτητή είναι : " << student2.getAm() << endl;
	// ΕΛΕΓΧΟΣ ΥΠΕΡΦΟΡΤΩΣΗΣ ΤΕΛΕΣΤΩΝ ++ ΠΡΟ-ΜΕΤΑ ΑΥΞΗΣΗΣ ΚΑΙ =+
	cout << "Το εξάμηνο του φοιτητή 1 είναι : " << student1.getSemester() << endl;
	cout << "Η ΠΡΟ όπως και η ΜΕΤΑ αύξηση επιστρέφουν αντικείμενο τύπου Student\n";
	cout << "Θα δημιουργήσουμε ένα φοιτητή student4 και εναν φοιτητή student5 και θα δούμε τις αλλαγές στο εξαμηνό τους μετα την χρήση των τελεστών προ-μετα αύξησης στον student1\n";
	Student student4("713242017033", "ΒΑΣΙΛΗΣ ΒΑΣΙΛΙΟΥ");
	cout << "Το τρέχον εξάμηνο του φοιτητή4 είναι : " << student4.getSemester() << endl;
	cout << "Προ-αύξηση στο student1\n";
	student4 = ++student1;
	cout << "Το εξάμηνο του student4 έγινε " << student4.getSemester() << " και το εξάμηνο του student1 έγινε : " << student1.getSemester() << endl;
	cout << "Μέτα-αύξηση στο student1\n";
	Student student5 = student4;
	student5 = student1++;
	cout << "Το εξάμηνο του student5 παρέμεινε " << student5.getSemester() << " επειδή επιστρέφεται η τιμή του student1 πριν αυξηθεί το εξάμηνο του"
		 << " και το εξάμηνο του student1 έγινε : " << student1.getSemester() << endl;
	return 0;
}
