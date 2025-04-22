#include <iostream>
using namespace std;

class Patient
{
protected:
    string name;
    string id;

public:
    Patient(string n, string i)
    {
        name = n;
        id = i;
    }

    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;
};

class InPatient : public Patient
{
    int daysAdmitted;
    double dailyRate;
    double medicationCost;

public:
    InPatient(string n, string i, int days, double rate, double meds)
        : Patient(n, i)
    {
        daysAdmitted = days;
        dailyRate = rate;
        medicationCost = meds;
    }

    void displayTreatment()
    {
        cout << "In-Patient Treatment Plan for " << name << " (ID: " << id << "):" << endl;
        cout << "- Room stay for " << daysAdmitted << " days" << endl;
        cout << "- Daily rate: $" << dailyRate << endl;
        cout << "- Medication charges: $" << medicationCost << endl;
    }

    double calculateCost()
    {
        return (daysAdmitted * dailyRate) + medicationCost;
    }
};

class OutPatient : public Patient
{
    int numberOfVisits;
    double consultationFee;
    double labCharges;

public:
    OutPatient(string n, string i, int visits, double consult, double lab)
        : Patient(n, i)
    {
        numberOfVisits = visits;
        consultationFee = consult;
        labCharges = lab;
    }

    void displayTreatment()
    {
        cout << "Out-Patient Treatment Plan for " << name << " (ID: " << id << "):" << endl;
        cout << "- Number of visits: " << numberOfVisits << endl;
        cout << "- Consultation fee per visit: $" << consultationFee << endl;
        cout << "- Lab charges: $" << labCharges << endl;
    }

    double calculateCost()
    {
        return (numberOfVisits * consultationFee) + labCharges;
    }
};

int main()
{
    Patient *p1 = new InPatient("Areeba Shah", "IP0345", 4, 3250.50, 1250.75);
    Patient *p2 = new OutPatient("Zayan Malik", "OP7712", 3, 850.00, 490.25);

    cout << "=== Patient Records ===" << endl
         << endl;

    p1->displayTreatment();
    cout << "Total Cost: $" << p1->calculateCost() << endl
         << endl;

    p2->displayTreatment();
    cout << "Total Cost: $" << p2->calculateCost() << endl;

    delete p1;
    delete p2;

    return 0;
}

