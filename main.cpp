#include <iostream>
#include <string>
#include <vector>

using namespace std;
int menufn();
struct User {
    string name;
    int age;
    int balance;
};

class Bank {
private:

    vector<User> data;

public:

    const void setUser(string name,int age,int balance) {
        const User user{name , age , balance};
        this->data.push_back(user); // push back method from vector.h
    };

    void getUser() {
        for (const auto& user : this->data) {
            cout << user.name << endl;
        }
    };
};

int main()
{




    // Bank bank;
    // bank.setUser("sribalan",25,0);
    // bank.setUser("kalaiselvi",35,0);
    //
    // bank.getUser();

    while (1) {
        int menu = menufn();
        switch (menu) {
            case 1:
            cout << "1 selected" << endl;
                break;
            default:
                exit(0);

        }
    }
    return 0;
}

int menufn() {
    int selection;
    cout << "Select the Menu" << endl;
    cin >> selection;
    return selection;
}