#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DatabaseException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException
{
};

class QueryTimeoutException : public DatabaseException
{
};

template <typename T>
class DatabaseConnector
{
    T databaseName;

public:
    DatabaseConnector(T name) : databaseName(name) {}

    void connect()
    {
        if (databaseName == "invalid_db")
        {
            throw ConnectionFailedException();
        }
        else if (databaseName == "slow_db")
        {
            throw QueryTimeoutException();
        }
    }
};

int main()
{
    try
    {
        DatabaseConnector<string> karachiDatabase("invalid_db");
        cout << "Attempting to connect to invalid_db..." << endl;
        karachiDatabase.connect();
    }
    catch (const ConnectionFailedException& e)
    {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }

    try
    {
        DatabaseConnector<string> lahoreDatabase("slow_db");
        cout << "Attempting to connect to slow_db..." << endl;
        lahoreDatabase.connect();
    }
    catch (const DatabaseException& e)
    {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    return 0;
}
