#include<iostream>
using namespace std;
#define X 3

class Person {
protected:
	char* name;
	int age;
public:
	Person() = default;
	Person(const char* n, int a) :age(a) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		//cout << "Person Constructor\n";
	}
	void Print() {
		cout << "Name: " << name << "\tAge: " << age << "\t";
	}
	void Input() {
		char buff[20];
		cout << "Enter Name: ";
		cin.getline(buff, 20);
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter age: ";
		cin >> age;
	}
	~Person() {
		delete[]name;
		//cout << "Person Destructor\n";
	}
	char* getName() const {
		return name;
	}
	int getAge() const {
		return age;
	}
	void setAge(const int newAge) {
		age = newAge;
	}
	void setName(const char* newName) {
		if (name != nullptr) {
			delete[] name;
		}
		name = new char[strlen(newName) + 1];
		strcpy_s(name, strlen(newName) + 1, newName);
	}
};

class Student : public Person {
	char* university;
public:
	Student() = default;
	Student(const char* n, int a, const char* Univer) :Person(n, a) {
		university = new char[strlen(Univer) + 1];
		strcpy_s(university, strlen(Univer) + 1, Univer);
		//cout << "Person Constructor\n";
	}
	~Student() {
		delete[] university;
		//cout << "Student Destructor\n";
	}
	void Input(const char* Univer) {
		delete[] university;
		university = new char[strlen(Univer) + 1];
		strcpy_s(university, strlen(Univer) + 1, Univer);

		Person::Input();
	}
	void Print() {
		//cout << "Name: " << name << "\tAge: " << age << "\t";
		Person::Print();
		cout << "University: " << university << endl;
	}
	char* getUniversity() const {
		return university;
	}
	void setUniversity(const char* univer) {
		if (university != nullptr) {
			delete[] university;
		}
		university = new char[strlen(univer) + 1];
		strcpy_s(university, strlen(univer) + 1, univer);
	}
};


class Teacher : public Person
{
	char* School;
	int Salary;
	string arrayObj[X];
public:
	Teacher() = default;
	Teacher(const char* n, int a, const char* school, const int salary, const string arrayobj[]) :Person(n, a) {
		School = new char[strlen(school) + 1];
		strcpy_s(School, strlen(school) + 1, school);
		Salary = salary;
		for (int i = 0; i < X; i++) {
			arrayObj[i] = arrayobj[i];
		}
	}
	~Teacher() {
		delete[] School;
	}
	void Print() {
		Person::Print();
		cout << "\tSchool: " << School << "\tSalary: " << Salary << "\tObjects: ";
		for (int i = 0; i < X; i++) {
			cout << arrayObj[i] << "\t";
		}
		cout << endl;
	}
	int getSalary() const {
		return Salary;
	}
	char* getSchool() const {
		return School;
	}
	string getarrayObjects() const {
		return arrayObj[0];
	}
	void setSalary(const int newSalary) {
		Salary = newSalary;
	}
	void setSchool(const char* newSchool) {
		if (School != nullptr) {
			delete[] School;
		}
		School = new char[strlen(newSchool) + 1];
		strcpy_s(School, strlen(newSchool) + 1, newSchool);
	}
	void setarrayObjects(const string newArrayObj) {
		for (int i = 0; i < X; i++) {
			arrayObj[i] = newArrayObj[i];
		}
	}
};

class Driver : public Person {
	char* carNumber;
	char* serialNumber;
	int driverLicense;
public:
	Driver() = default;
	Driver(const char* n, int a, const char* carnum, const char* serialnum, const int license) :Person(n, a) {
		carNumber = new char[strlen(carnum) + 1];
		strcpy_s(carNumber, strlen(carnum) + 1, carnum);
		serialNumber = new char[strlen(serialnum) + 1];
		strcpy_s(serialNumber, strlen(serialnum) + 1, serialnum);
		driverLicense = license;
	}
	~Driver() {
		delete[] carNumber;
		delete[] serialNumber;
	}
	void Print() {
		Person::Print();
		cout << "\tCar number: " << carNumber << "\tSerial number: " << serialNumber << "\tDriver license: " << driverLicense << endl;
	}
	char* getcarNumber() const {
		return carNumber;
	}
	char* getseriaLNumber() const {
		return serialNumber;
	}
	int getdriverLicense() const {
		return driverLicense;
	}
	void setcarNumber(const char* newCarNum) {
		if (carNumber != nullptr) {
			delete[] carNumber;
		}
		carNumber = new char[strlen(newCarNum) + 1];
		strcpy_s(carNumber, strlen(newCarNum) + 1, newCarNum);
	}
	void setseriaLNumber(const char* newSerialNum) {
		if (serialNumber != nullptr) {
			delete[] serialNumber;
		}
		serialNumber = new char[strlen(newSerialNum) + 1];
		strcpy_s(serialNumber, strlen(newSerialNum) + 1, newSerialNum);
	}
	void setarrayObjects(const int newLicense) {
		driverLicense = newLicense;
	}
};

class Doctor : public Person {
	char* speciality;
	int workExperience;
	bool familyDoctor;
public:
	Doctor() = default;
	Doctor(const char* n, int a, const char* specials, const int workexperience, const bool familyDoc) :Person(n, a) {
		speciality = new char[strlen(specials) + 1];
		strcpy_s(speciality, strlen(specials) + 1, specials);
		workExperience = workexperience;
		familyDoctor = familyDoctor;
	}
	~Doctor() {
		delete[] speciality;
	}
	void Print() {
		Person::Print();
		cout << "\tSpecialyty: " << speciality << "\tWork experience: " << workExperience << "\tFamily doctor: ";
		if (familyDoctor)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}

		cout << endl;
	}
	char* getspeciaLty() const {
		return speciality;
	}
	int getworkExperience() const {
		return workExperience;
	}
	bool getfamilyDoctor() const {
		return familyDoctor;
	}
	void setspeciaLty(const char* newSpecials) {
		if (speciality != nullptr) {
			delete[] speciality;
		}
		speciality = new char[strlen(newSpecials) + 1];
		strcpy_s(speciality, strlen(newSpecials) + 1, newSpecials);
	}
	void setworkExperience(const int newWorkExperience) {
		workExperience = newWorkExperience;
	}
	void setfamilyDoctor(const int newFamilyDoc) {
		familyDoctor = newFamilyDoc;
	}
};

int main() {
	cout << "Start data!\n";
	Student* obj = new Student("Anna", 20, "ITStep");
	obj->Print();
	obj->Input("MGU");
	obj->Print();
	cout << endl;

	string predmeti[X] = { "C#", ".NET", "Javascript" };
	Teacher obj2("Aslan", 20, "ITStep", 75400, predmeti);
	obj2.Print();
	Driver obj3("Maksym", 18, "BH4884HO", "BXK395621", 38492);
	obj3.Print();
	Doctor obj4("Yan", 29, "Dentist", 25, false);
	obj4.Print();

	cout << "\nUpdated data:\n";
	obj2.setSchool("Ohr Sameach");
	obj2.Print();
	obj3.setAge(31);
	obj3.Print();
	obj4.setfamilyDoctor(true);
	obj4.Print();
	cout << "End data!\n";
}