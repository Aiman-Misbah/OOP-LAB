#include <iostream>
using namespace std;

class Doctor
{
private:
    string name;
    string specialization;
    int experience;

public:
    Doctor(string name, string specialization, int experience) : name(name), specialization(specialization), experience(experience) {}

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

class Hospital
{
private:
    string name;
    Doctor *doctors[5];
    int doctorCount;

public:
    Hospital(string name) : name(name), doctorCount(0) {}

    void addDoctor(Doctor *doctor)
    {
        if (doctorCount < 5)
        {
            doctors[doctorCount++] = doctor;
        }
        else
        {
            cout << "Cannot Hire More Doctors, Maximum Limit Of Doctors Achieved! " << endl;
        }
    }

    void display() const
    {
        cout << "Hospital Name: " << name << endl;
        if (doctorCount == 0)
        {
            cout << "No Doctors Assigned Currently! " << endl;
        }
        else
        {
            cout << "----------Doctors Working Here----------" << endl;
            for (int i = 0; i < doctorCount; i++)
            {
                doctors[i]->display();
                cout << endl;
            }
        }
    }

    ~Hospital()
    {
        for (int i = 0; i < doctorCount; i++)
        {
            delete doctors[i];
        }
    }
};

int main()
{
    Doctor *doc1 = new Doctor("Dr. Lubna Rehman", "Consultant Gynaecologist", 10);
    Doctor *doc2 = new Doctor("Dr. Hamza Imran", "General Physician", 2);
    Doctor *doc3 = new Doctor("Dr. Nabiha Asif", "Dermatologist", 7);
    Doctor *doc4 = new Doctor("Dr. Urooj Amir", "Cardiologist", 1);
    Doctor *doc5 = new Doctor("Dr. Humaid Imran", "Neurologist", 6);

    Hospital hosp1("AKAR Hospital");
    hosp1.addDoctor(doc1);
    hosp1.addDoctor(doc2);
    hosp1.addDoctor(doc3);
    cout << endl;
    hosp1.display();

    Hospital hosp2("Aga Khan Hospital");
    hosp2.addDoctor(doc4);
    hosp2.addDoctor(doc5);

    hosp2.display();

    return 0;
}

