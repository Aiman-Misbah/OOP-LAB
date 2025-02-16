#include <iostream>
using namespace std;

struct Transaction
{
    double amount;
    string type;
    string reason;
};

class Wallet
{
private:
    string ownerName;
    double totalBalance;
    Transaction transactionHistory[15];
    int countTransactions;

public:
    Wallet(string name, double defaultBalance)
    {
        ownerName = name;
        totalBalance = defaultBalance;
        countTransactions = 0;
    }

    void recordTransactions(double amount, string type, string reason)
    {
        if (countTransactions < 15)
        {
            transactionHistory[countTransactions] = {amount, type, reason};
            countTransactions++;
        }
        else
        {
            for (int i = 0; i < 14; i++)
            {
                transactionHistory[i] = transactionHistory[i + 1];
            }
            transactionHistory[14] = {amount, type, reason};
            countTransactions = 15;
        }
    }

    void addMoney(double amount)
    {
        if (amount > 0)
        {
            totalBalance += amount;
            recordTransactions(amount, "Deposited", "NIL");
            cout << "$" << amount << " Deposited To The Account!" << endl;
            cout << "Balance: $" << totalBalance << endl
                 << endl;
        }
        else
        {
            cout << "Error, Please Enter A Value Greater than 0!" << endl;
        }
    }

    void spendMoney(double amount, string reason)
    {
        if (amount > 0)
        {
            if (amount > totalBalance)
            {
                cout << "Error, Insufficient Balance!" << endl;
                return;
            }
            totalBalance -= amount;
            recordTransactions(amount, "Withdrawn", reason);
            cout << "$" << amount << " Withdrawn From The Account!" << endl;
            cout << "Balance: $" << totalBalance << endl
                 << endl;

            checkCash();
        }
        else
        {
            cout << "Error, Please Enter A Value Greater than 0!" << endl
                 << endl;
        }
    }

    void displayHistory()
    {
        if (countTransactions > 0)
        {
            for (int i = 0; i < countTransactions; i++)
            {
                if (transactionHistory[i].type == "Withdrawn")
                {
                    cout << "Transaction#" << (i + 1) << ": " << endl;
                    cout << "Amount: $" << transactionHistory[i].amount << " - " << transactionHistory[i].type << " (" << transactionHistory[i].reason << ")" << endl
                         << endl;
                }
                else
                {
                    cout << "Transaction#" << (i + 1) << ": " << endl;
                    cout << "Amount: $" << transactionHistory[i].amount << " - " << transactionHistory[i].type << endl
                         << endl;
                }
            }
        }
        else
        {
            cout << "No Transactions Done!" << endl;
        }
    }

    void checkCash()
    {
        if (totalBalance < 100)
        {
            cout << "WARNING: Balance is lower than $100!" << endl
                 << endl;
        }
    }
};

int main()
{
    Wallet wallet("Saad", 0);
    cout << endl;
    cout << "-----------ADDING MONEY----------" << endl
         << endl;
    wallet.addMoney(12.50);
    wallet.addMoney(8.75);
    wallet.addMoney(14.20);
    wallet.addMoney(9.60);
    wallet.addMoney(10.30);
    wallet.addMoney(13.90);
    wallet.addMoney(11.80);

    cout << "-----------SPENDING MONEY----------" << endl
         << endl;
    wallet.spendMoney(5.00, "Coffee");
    wallet.spendMoney(7.25, "Snacks");
    wallet.spendMoney(12.10, "Lunch");
    wallet.spendMoney(8.90, "Groceries");
    wallet.spendMoney(9.40, "Bus Pass");
    wallet.spendMoney(14.75, "Movie Ticket");
    wallet.spendMoney(10.50, "Internet Data");
    wallet.spendMoney(11.30, "Bakery Items");

    cout << "-----------DISPLAYING TRANSACTION HISTORY----------" << endl
         << endl;
    wallet.displayHistory();

    return 0;
}
