#include <iostream>
using namespace std;

class Account
{
protected:
    int accountNumber;
    float balance;

public:
    Account(int accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

    virtual void displayDetails() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
    virtual ~Account() {}
};

class SavingsAccount : public Account
{
private:
    float interestRate;

public:
    SavingsAccount(int accountNumber, float balance, float interestRate) : Account(accountNumber, balance), interestRate(interestRate) {}

    void displayDetails() const override
    {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account
{
private:
    float overdraftLimit;

public:
    CheckingAccount(int accountNumber, float balance, float overdraftLimit) : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    void displayDetails() const override
    {
        Account::displayDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main()
{
    SavingsAccount account1(101, 5000.75, 3.5);
    CheckingAccount account2(102, 4310.75, 1032.67);
    cout << endl;
    cout << "----------Details Of Savings Account----------" << endl;
    account1.displayDetails();
    cout << endl;
    cout << "----------Details Of Checking Account----------" << endl;
    account2.displayDetails();
    cout << endl;
    return 0;
}
