#include <iostream>
#include <ctime>
using namespace std;

class ATM
{
private:
    int pin;
    int balance;
    int accountenumber;
    string username;
    string branch;
    string address;

public:
    ATM(){
    pin = 12345;
    balance = 20000;
    accountenumber = 8080;
    username ="Man";
    branch ="Rajkot";
    address ="Rajkot";
    };               
    void welcome();
    void help();
    void checkPin();
    void menu();
    void deposit();
    void withdraw();
    void checkBalance();
};



void ATM::welcome()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "=============================\n";
    cout << "        WELCOME TO ATM\n";
    cout << "=============================\n";
    cout << "Date: " << dt;
    cout << "1. Access Account\n";
    cout << "2. Help\n";
    cout << "Enter Choice: ";
}


void ATM::help()
{
    cout << "\nATM HELP SCREEN\n";
    cout << "You must have correct PIN to access account.\n";
    cout << "Contact bank for help.\n";
}


void ATM::checkPin()
{
    int p;
    cout << "Enter ATM PIN: ";
    cin >> p;

    if (p == pin)
    {
        cout << "PIN Correct\n";
        menu();
    }
    else
    {
        cout << "Incorrect PIN. No more attempts allowed.\n";
    }
}


void ATM::menu()
{
    int choice;

    do
    {
        cout << "\nATM MENU\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
            deposit();
        else if (choice == 2)
            withdraw();
        else if (choice == 3)
            checkBalance();

    } while (choice != 0);
}


void ATM::deposit()
{
    int amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    balance = balance + amount;

    cout << "Account holder name : " << username <<  endl;
    cout << "Account holder address : " << address << endl;
    cout << "Branch address : " << branch << endl;
    cout << "Account number : " <<accountenumber << endl;
    cout << "New Balance: " << balance << endl;
}


void ATM::withdraw()
{
    int amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount > balance)
        cout << "Insufficient balance\n";
    else
    {
        balance = balance - amount;
        cout << "Withdraw Successful\n";

        cout << "Account holder name : " << username <<  endl;
        cout << "Account holder address : " << address << endl;
        cout << "Branch address : " << branch << endl;
        cout << "Account number : " <<accountenumber << endl;
        cout << "Remaining Balance: " << balance << endl;
    }
}

void ATM::checkBalance()
{
    cout << "Current Balance: " << balance << endl;
}


int main()
{
    ATM a;
    int ch;

    a.welcome();
    cin >> ch;

    if (ch == 1)
        a.checkPin();
    else if (ch == 2)
        a.help();
    else
        cout << "Invalid Choice\n";

    return 0;
}