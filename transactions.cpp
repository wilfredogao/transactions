#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
using namespace std;

class InMemoryDB { //header file, fig 1
    private:
        map<string, int> commitedTransactions;
        map<string, int> tempTransactions;
        bool started = false;
        void clearTemp();

    public:
        int get(string key);

        void put(string key, int val);

        void begin_transaction();

        void commit();

        void rollback();
};

int InMemoryDB::get(string key)
{
    if(commitedTransactions.find(key) != commitedTransactions.end()) //key exist
    {
         return commitedTransactions[key]; //gets transactions from commited
    }
    else
    {
        return -100;
    }
}

void InMemoryDB::put(string key, int val) 
{
    if (!started) //if transactions not begun
    {
        throw std::logic_error("Error, transactions not begun");
    }
    tempTransactions[key] = val; //put it into temp map
}

void InMemoryDB::begin_transaction() 
{
    if (started) 
    {
        throw std::logic_error("Error, transactions already in progress");
    }
    started = true;
}

void InMemoryDB::commit() 
{
    if (!started) 
    {
        throw std::logic_error("Error, no transactions to commit");
    }
    commitedTransactions.insert(tempTransactions.begin(), tempTransactions.end()); //inserts all transactions from temp into actual
    clearTemp(); //clears temp transactions
}

void InMemoryDB::rollback() {
    if (!started) 
    {
        throw std::logic_error("Error, no ongoing transactions");
    }

    clearTemp();
}

void InMemoryDB::clearTemp() //for clearing out temp transactions 
{
    tempTransactions.clear();
    started = false;
}

int main() {
    InMemoryDB inmemoryDB;

    string userInput, key = "";
    bool program = true;
    int value = 0;
    cout << "This is a transaction console application. Enter \"END\" to exit and \"HELP\" for a list of commands.\n";

    while (program){
        std::cin >> userInput;

        if (userInput == "END") 
        {
            program = false;
        } 
        else if (userInput == "HELP")
        {
            cout << "This application has 5 commands:\n"
                 << "\"GET\", \"PUT\", \"BEGIN TRANSACTION\", \"COMMIT\", \"ROLLBACK\":\n"
                 << "~BEGIN TRANSACTION: 1st Command, starts transactions\n"
                 << "~PUT A 4: Puts the value of 4 for A\n"
                 << "~COMMIT: Commits A into the database\n"
                 << "~GET A: Returns the value of A\n"
                 << "~ROLLBACK: Cancels any transactions that haven't been commited yet\n";
        }
        else if (userInput == "BEGIN") 
        {
            cin >> userInput; //takes in "TRANSACTION"
            if(userInput == "TRANSACTION")
            {
                inmemoryDB.begin_transaction();
                cout << "Transaction started.\n";
            }
            else
            {
                cout << "Invalid input. Try again.\n";
            }
        } 
        else if (userInput == "COMMIT") 
        {
            try 
            {
                inmemoryDB.commit();
                cout << "Transaction committed.\n";
            } 
            catch (const logic_error& e) 
            {
                cerr << e.what() << endl;
                exit(EXIT_FAILURE); //stop program on error
            }
        } 
        else if (userInput == "ROLLBACK") 
        {
            try 
            {
                inmemoryDB.rollback();
                cout << "Transaction rolled back.\n";
            } 
            catch (const logic_error& e) 
            {
                cerr << e.what() << endl;
                exit(EXIT_FAILURE); //stop program on error
            }
        } 
        else if (userInput == "PUT") 
        {
            cin >> key >> value;
            try 
            {
                inmemoryDB.put(key, value);
                cout << "Data added to transactions.\n";
            } 
            catch (const logic_error& e) 
            {
                cerr << e.what() << endl;
                exit(EXIT_FAILURE); //stop program on error
            }
        } 
        else if (userInput == "GET") 
        {
            cin >> key;
            cout << "Value: "; 
            value = inmemoryDB.get(key);
            if(value == -100)
            {
                cout << "Null, Key doesn't exist in database yet.\n";
            }
            else
            {
                cout << value << endl;
            }
        } 
        else 
        {
            cout << "Invalid input. Try again.\n";
        }
    }

    return 0;
}
