#include <iostream>
#include <string>
#include <vector>

using namespace std;





struct User {
    string name;
    int id;
    int balance;
};

class Bank {
private:

    vector<User> data;

public:
    int id = 1;

    void setUser(string name,int balance)  {
        const User user{name , id++ , balance};
        this->data.push_back(user); // push back method from vector.h
    };

    void getAllUsers() {
        for (const auto& user : this->data) {
            cout << "{" << " Name : " << user.name << "; "
            << "Id : " << user.id  << "; " << "Balance : "
            << user.balance << "; " << "}" << endl;
        }
    };

    int getBankWealth() const {
        int amount = 0;
        for (const auto& user : data) {
            amount += user.balance;
        }
        return amount;
    }

};
int backspace();
int menufn();
void getBankAmount(const Bank & bank);
void addUser(Bank & bank);

int main()
{
    Bank bank;

    while (1) {
        int menu = menufn();
        switch (menu) {
            case 1:
               getBankAmount(bank);
                backspace();
                break;
            case 2:
                addUser(bank);
                backspace();
                break;
            case 3:
                bank.getAllUsers();
                backspace();
                break;
            default:
                exit(0);

        }
    }
    return 0;
}

int backspace() {
    int back;
    cout << "Press 0 to back to Menu : " << endl;
    cin >> back;
    if (back == 0) {
        return back;
    }
}
int menufn() {
    int selection;
    cout << "Selection Menu : \n" <<
            "1 -> GET BANK WEALTH\n" <<
            "2 -> ADD USER\n" <<
            "3 -> GET ALL USERS\n" <<
            "4 -> GET USER BY ID\n" <<
            "5 -> CREDIT MONEY TO USER BY ID\n" <<
            "6 -> DEBIT MONEY TO USER BY ID\n" <<
            "7 -> REMOVE USER BY ID\n" <<
            "0 -> EXIT \n"
    << endl;
    cout << "Select an option :  ";
    cin >> selection;
    return selection;
}


void getBankAmount(const Bank& bank) {
    cout << "Total Bank Wealth is: " << bank.getBankWealth() << endl;
}

void addUser(Bank& bank) {
    string name;
    int openingBalance = 0;
    cout << "Enter the User Name  : " << endl;
    cin >> name;
    bank.setUser(name , openingBalance);
}