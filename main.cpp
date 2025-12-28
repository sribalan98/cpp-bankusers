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

    void setUserBalance(int userId, int amount) {
        for (auto& user : this->data) {
            if (user.id == userId) {
                user.balance += amount;
            }
        }
    }
    vector<User> getAllUsers() {
        return data;
    };

    int getBankWealth() const {
        int amount = 0;
        for (const auto& user : data) {
            amount += user.balance;
        }
        return amount;
    }

    User getUserById(int id) const {
        for (const auto& user : data) {
            if (user.id == id) {

                return user;
            }
        }
    }
};

int backspace();
int menufn();
void getBankAmount(const Bank & bank);
void addUser(Bank & bank);
void getAllUsers(Bank& bank);
void getUserById(Bank & bank);
void creditmoneyTouser(Bank & bank);
void debitmoneyTouser(Bank& bank);


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
                getAllUsers(bank);
                // bank.getAllUsers();
                backspace();
                break;
            case 4:
                getUserById(bank);
                backspace();
                break;
            case 5:
                creditmoneyTouser(bank);
                backspace();
                break;
            case 6:
                break;
            case 7:
                break;
            case 0:
                exit(0);
            default:
                exit(0);

        }
    }
    return 0;
}

int backspace() {
    again:
    int back;
    cout << "Press 0 to back to Menu : " << endl;
    cin >> back;
    if (back == 0) {
        return back;
    }
    goto again;
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

void getAllUsers(Bank& bank) {
    vector<User> users;
    users  = bank.getAllUsers();
    if (!users.empty()) {
        for (const auto& user : users) {
            cout << "{" << " Name : " << user.name << "; "
            << "Id : " << user.id  << "; " << "Balance : "
            << user.balance << "; " << "}" << endl;
        }
    } else {
    cout << "There is no users in the Bank" << endl;
    }
}
void getUserById(Bank& bank) {
    int id;
    cout << "Enter User ID : " << endl;
    cin >> id;
    User user = bank.getUserById(id);
    cout << "{" << " Name : " << user.name << "; "
                << "Id : " << user.id  << "; " << "Balance : "
                << user.balance << "; " << "}" << endl;
}


void creditmoneyTouser(Bank& bank) {
    int userId;
    int creditmoney;
    cout << "Enter User ID : " << endl;
    cin >> userId;
    User user = bank.getUserById(userId);
    cout <<  "The UserName  is : " << user.name << "; " << endl;
    cout << "Enter the Amount to Credit to the user : ";
    cin >> creditmoney;
    cout << endl;
    bank.setUserBalance(userId, creditmoney);
}



void debitmoneyTouser(Bank& bank) {
    int userId;
    int debitmoney;
    cout << "Enter User ID : " << endl;
    cin >> userId;
    User user = bank.getUserById(userId);
    cout <<  "The UserName  is : " << user.name << "; " << endl;
    cout  << "Enter the Amount to Debit to the user : ";
    cin >> debitmoney;
    cout << endl;
    bank.debitAmountToUser(userId, debitmoney);
}