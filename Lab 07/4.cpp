#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string contact, string addr)
        : name(n), age(a), contactNumber(contact), address(addr) {}

    virtual void displayInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Address: " << address << endl;
    }

    virtual void updateInfo(string newContact, string newAddress)
    {
        contactNumber = newContact;
        address = newAddress;
    }

    virtual ~Person() {}
};

class Patient : public Person
{
private:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string contact, string addr, int id, string history, string doctor)
        : Person(n, a, contact, addr), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person
{
private:
    string specialization;
    double consultationFee;
    int numberOfPatients;

public:
    Doctor(string n, int a, string contact, string addr, string spec, double fee, int numPatients)
        : Person(n, a, contact, addr), specialization(spec), consultationFee(fee), numberOfPatients(numPatients) {}

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: $" << consultationFee << endl;
        cout << "Number of Patients: " << numberOfPatients << endl;
    }
};

class Nurse : public Person
{
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string contact, string addr, string ward, string shift)
        : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person
{
private:
    string department;
    double salary;

public:
    Administrator(string n, int a, string contact, string addr, string dept, double sal)
        : Person(n, a, contact, addr), department(dept), salary(sal) {}

    void updateInfo(string newContact, string newAddress) override
    {
        Person::updateInfo(newContact, newAddress);
    }

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main()
{
    Patient patient1("Ali Khan", 30, "03123456789", "Karachi", 101, "Diabetes", "Dr. Ahmed");
    Doctor doctor1("Dr. Ahmed", 45, "03219876543", "Lahore", "Cardiologist", 2000.0, 20);
    Nurse nurse1("Sara Hassan", 28, "03001234567", "Islamabad", "ICU", "Night");
    Administrator admin1("Bilal Saeed", 50, "03337654321", "Peshawar", "Finance", 150000.0);

    cout << "--- Patient Information ---" << endl;
    patient1.displayInfo();
    cout << endl;

    cout << "--- Doctor Information ---" << endl;
    doctor1.displayInfo();
    cout << endl;

    cout << "--- Nurse Information ---" << endl;
    nurse1.displayInfo();
    cout << endl;

    cout << "--- Administrator Information ---" << endl;
    admin1.displayInfo();
    cout << endl;

    return 0;
}

