#include <iostream>
#include <string.h>
#include <limits.h>

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
	if (semester > 0 and semester < UINT_MAX){
		this->semester = semester;}
	else {
		//ΘΑ ΜΠΟΡΟΥΣΑ ΝΑ ΒΑΛΩ ΜΙΑ WHILE ΓΙΑ ΝΑ ΤΡΕΧΕΙ ΜΕΧΡΙ ΝΑ ΔΩΘΕΙ ΣΩΣΤΟ ΕΞΑΜΗΝΟ
		cout << "ΜΗ-ΠΡΟΣΙΜΑΣΜΕΝΟΣ ΑΡΙΘΜΟΣ ΕΚΤΟΣ ΟΡΙΩΝ.ΤΟ ΕΞΑΜΗΝΟ ΓΙΝΕΤΑΙ 1" << endl;
	}
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
void Student::printInformation(ostream &out) const
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
	//ΘΕΛΟΥΜΕ ΕΛΕΓΧΟ
	if (semester > 0 and semester < UINT_MAX)
	{
		//ΚΑΝΟΝΙΚΑ ΘΑ ΠΡΕΠΕΙ ΝΑ ΒΑΛΟΥΜΕ ΑΚΟΜΑ ΕΝΑΝ ΕΛΕΓΧΟ ΠΡΙΝ ΓΙΝΕΙ Η ΠΡΟΣΘΑΙΣΗ ΓΙΑ ΝΑ ΔΟΥΜΕ ΑΝ ΤΟ ΑΠΟΤΕΛΕΣΜΑ ΘΑ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΟ ΑΠΟ ΤΟ ΟΡΙΟ ΠΡΙΝ ΕΚΤΕΛΕΣΤΕΙ
		if ((this->semester+=semester) < UINT_MAX){
			this->semester = this->semester + semester;
		}
		else 
			cout << "Μη-προσιμασμένος ακέραιος εκτός ορίων" << endl;
		
	}
	else
		cout << "Μη-προσιμασμένος ακέραιος εκτός ορίων" << endl;
	return *this; 
}
// += ΣΕ ΜΕ ΑΛΛΟΝ ΦΟΙΤΗΤΗ
Student Student::operator+=(Student &s)
{
	//ΘΑ ΠΡΕΠΕΙ ΝΑ ΓΙΝΕΙ Ο ΙΔΙΟΣ ΕΛΕΓΧΟΣ ΓΙΑ ΤΗΝ ΠΡΟΣΘΑΙΣΗ ΚΑΙ ΕΔΩ
	if ((this->semester+=s.semester) < UINT_MAX){
		this->semester = this->semester + s.semester;
	}
	else cout << "Μη-προσιμασμένος ακέραιος εκτός ορίων" << endl;

	return *this;
}
Student Student::operator-=(unsigned int semester){
		if (this->semester>=semester){
			this->semester-=semester;
		}
		else
		cout << "Μη-προσιμασμένος ακέραιος εκτός ορίων" << endl;
		return *this;

}
Student Student::operator-=(Student &s){
	if (this->semester>s.semester){
			this->semester-=s.semester;	
		}
		else
		cout << "Μη-προσιμασμένος ακέραιος εκτός ορίων" << endl;
	return *this;
}
// (ΕΧΤΡΑ) ΥΠΕΡΦΟΤΩΣΗ ΤΟΥ = ΓΙΑ ΝΑ ΜΠΟΡΕΣΩ ΝΑ ΤΡΕΞΩ stud1 = ++std2. Ο stud1 έχει δημιουργηθεί πρίν.
Student& Student::operator=(const Student &s)
{
	if (!(this==&s)){
		delete[] this->am;
		int sizeAM = strlen(s.am);
		this->am = new char[sizeAM + 1];
		strcpy(this->am, s.am);
		this->name = s.name;
		this->semester = s.semester;
	}
	return *this;

}
int main()
{
	cout << "Ξεκινάει δημιουργία αντικειμένων με την χρήση των  κατασκευαστών...\n" << endl;
	Student student1("713242017024", "ΒΙΚΤΩΡ ΡΟΜΑΝΙΟΥΚ");
	Student student2("713242017025", "ΑΝΤΩΝΗΣ ΑΝΤΩΝΙΟΥ", 7);
	Student student3(student1);
	cout << "Εκτύπωση των στοιχείων κάθε φοιτητή" << endl;
	student1.printInformation(cout);
	student2.printInformation(cout);
	student3.printInformation(cout);
	printf("\n\n\n");
	// ΕΛΕΓΧΟΣ SETTERS
	cout << "Έλεγχος setters και getters" << endl;
	printf("\n\n");
	cout << "Αλλαγή εξαμήνου του πρώτου φοιτητή" << endl;
	student1.setSemester(15);
	cout << "Αλλαγή ονόματος του τρίτου φοιτητή" << endl;
	student3.setName("ΚΩΣΤΑΣ ΚΩΣΤΑΝΤΙΝΙΔΗΣ");
	cout << "Αλλαγή αριθμού μητρώου του δεύτερου φοιτητή" << endl;
	student2.setAm("ice45672");
	// ΕΛΕΓΧΟΣ GETTERS
	printf("\n\n");
	cout << "Το εξάμηνο του πρώτου φοιτητή πλέον ειναι : " << student1.getSemester() << endl;
	cout << "Το όνομα του τρίτου φοιτητή πλέον είναι : " << student3.getName() << endl;
	cout << "Ο αριθμός μητρώου του δεύτερου φοιτητή είναι : " << student2.getAm() << endl;
	// ΕΛΕΓΧΟΣ ΥΠΕΡΦΟΡΤΩΣΗΣ ΤΕΛΕΣΤΩΝ ++ ΠΡΟ-ΜΕΤΑ ΑΥΞΗΣΗΣ ΚΑΙ =+
	cout << "Το εξάμηνο του φοιτητή 1 είναι : " << student1.getSemester() << endl;
	printf("\n\n\n");
	cout << "Η ΠΡΟ όπως και η ΜΕΤΑ αύξηση επιστρέφουν αντικείμενο τύπου Student\n";
	cout << "Θα δημιουργήσουμε ένα φοιτητή student4 και εναν φοιτητή student5 και θα δούμε τις αλλαγές στο εξαμηνό τους μετα την χρήση των τελεστών προ-μετα αύξησης στον student1\n";
	Student student4("713242017033", "ΒΑΣΙΛΗΣ ΒΑΣΙΛΙΟΥ");
	printf("\n\n");
	cout << "Το τρέχον εξάμηνο του φοιτητή4 είναι : " << student4.getSemester() << endl;
	cout << "Προ-αύξηση στο student1\n";
	student4 = ++student1;
	printf("\n");
	cout << "Το εξάμηνο του student4 έγινε " << student4.getSemester() << " και το εξάμηνο του student1 έγινε : " << student1.getSemester() << endl;
	printf("\n");
	cout << "Μέτα-αύξηση στο student1\n";
	printf("\n");
	Student student5 = student4;
	student5 = student1++;
	cout << "Το εξάμηνο του student5 παρέμεινε " << student5.getSemester() << " επειδή επιστρέφεται η τιμή του student1 πριν αυξηθεί το εξάμηνο του"
		 << " και το εξάμηνο του student1 έγινε : " << student1.getSemester() << endl;
	printf("\n\n\n");
	cout << "Χρήση τελεστών -= με μη-προσημασμένο ακέραιο και φοιτητή" << endl;
	printf("\n");
	cout << "Εξάμηνο φοιτητή 1 πρίν το -= 5 είναι " << student1.getSemester() << endl;
	student1 -= 5;
	cout << "To εξάμηνο πλέον είναι : " << student1.getSemester() << endl;
	printf("\n");
	cout << "Το εξάμηνο του φοιτητή 2 είναι " << student2.getSemester() << endl;
	cout << "Αν εκτελέσουμε student1-=student2 θα πάρουμε : ";
	student1-=student2;
	cout << student1.getSemester() << endl;
	Student student6 = student1;
	printf("\n\n\n");
		cout << "Φτιάξε εναν student6 για να δοκιμάσουμε student6=student1-=2\n" << "Το εξάμηνο του student6 είναι : " << student6.getSemester() << endl;
	student6=student1-=1;
	cout <<"Tο εξάμηνο του φοιτητή 6 έγινε : " << student6.getSemester() << endl;


	return 0;
}
