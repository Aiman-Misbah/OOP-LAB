#include <iostream>
using namespace std;

class Manager;

class Account
{
private:
    int accNumber;
    double balance;

public:
    Account(int accNum, double initialAmount)
    {
        accNumber = accNum;
        balance = initialAmount;
    }

    friend class Manager;
    friend void transferFunds(Account &sender, Account &receiver, double amount);
};

class Manager
{
public:
    void deposit(Account &userAcc, double amount)
    {
        if (amount > 0)
        {
            userAcc.balance += amount;
            cout << "Deposited $" << amount << " to account " << userAcc.accNumber << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(Account &userAcc, double amount)
    {
        if (amount > 0 && amount <= userAcc.balance)
        {
            userAcc.balance -= amount;
            cout << "Withdrew $" << amount << " from account " << userAcc.accNumber << endl;
        }
        else
        {
            cout << "Withdrawal failed. Insufficient balance or invalid amount." << endl;
        }
    }

    void showDetails(const Account &userAcc)
    {
        cout << "Account Number: " << userAcc.accNumber << endl;
        cout << "Balance: $" << userAcc.balance << endl;
    }
};

void transferFunds(Account &sender, Account &receiver, double amount)
{
    if (amount > 0 && sender.balance >= amount)
    {
        sender.balance -= amount;
        receiver.balance += amount;
        cout << "Transferred $" << amount << " from account " << sender.accNumber
             << " to account " << receiver.accNumber << endl;
    }
    else
    {
        cout << "Transfer failed. Not enough balance or invalid amount." << endl;
    }
}

int main()
{
    Account accOne(11101, 8000.0);
    Account accTwo(22202, 3000.0);
    Manager bankOps;
    cout << "Initial State:" << endl;
    bankOps.showDetails(accOne);
    bankOps.showDetails(accTwo);
    cout << endl;
    bankOps.deposit(accOne, 2000);
    bankOps.withdraw(accTwo, 500);
    cout << endl;
    transferFunds(accOne, accTwo, 2500);
    cout << endl;
    cout << "Final State:" << endl;
    bankOps.showDetails(accOne);
    bankOps.showDetails(accTwo);
    cout << endl;
    return 0;
}
