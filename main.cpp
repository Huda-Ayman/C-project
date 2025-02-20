#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

     string name = "";
     int number = 0;
     double balance = 0;
     int accNum = 0;
     string password = "";
     int choice2;
     bool logged = false;

   // إنشاء حساب
     int createAccount() {
     if (name != "") {
        cout << " You already have an account! Cannot create another one.\n";
        return 0;
    }

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Phone Number: ";
    cin >> number;
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Set a Password: ";
    cin >> password;
    cout << "Enter Initial Balance: ";
    cin >> balance;
    cout << "Account Created Successfully!\n";

    return 0;
}

  // تسجيل الدخول
     int login() {
     if (name == "") {
        cout << " No account found! Please create an account first.\n";
        return 0;
    }

     int accountNum;
     string inputPassword;
     cout << "Enter Account Number to Login: ";
     cin >> accountNum;

     if (accountNum == accNum) {
        cout << "Enter Password: ";
        cin >> inputPassword;

     if (inputPassword == password) {
             logged = true;
            cout << "Login Successful!\n";
        } else {
            cout << "Incorrect Password!\n";
        }
    } else {
        cout << "Wrong Account Number!\n";
    }
    return 0;
}

  // عرض تفاصيل الحساب
    int showAccount() {
    if (logged) {
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << number << endl;
        cout << "Account Number: " << accNum << endl;
        cout << "Balance: " << balance << "$" << endl;
    } else {
        cout << " You need to log in first!\n";
    }
    return 0;
}

  // تسجيل الخروج
    int logout() {
    if (!logged) {
        cout << "You are not logged in!\n";
        return 0;
    }

    logged = false;
    cout << "Logged Out Successfully!\n";
    return 0;
}

  // حذف الحساب
    int deleteAccount() {
    if (!logged) {
        cout << "You need to log in first!\n";
        return 0;
    }

    string confirmPassword;
    cout << "Enter your password to confirm deletion: ";
    cin >> confirmPassword;

    if (confirmPassword == password) {
        name = "";
        number = 0;
        accNum = 0;
        balance = 0;
        password = "";
        logged = false;

        cout << "Account Deleted Successfully!\n";
    } else {
        cout << "Incorrect password! Account deletion cancelled.\n";
    }

    return 0;
}

    int main() {
    system("color E5");
    int choice;

    while (true) {

        cout << "\t\t\t***********************************************************************" << endl;
        cout << "\t\t\t*                                                                     *" << endl;
        cout << "\t\t\t*              Welcome to Our Banking System                          *" << endl;
        cout << "\t\t\t*                                                                     *" << endl;
        cout << "\t\t\t***********************************************************************" << endl << endl << endl << endl;
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Show Account\n";
        cout << "4. Logout\n";
        cout << "5. Other\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) createAccount();
        else if (choice == 2) login();
        else if (choice == 3) showAccount();
        else if (choice == 4) logout();
        else if (choice == 6) {
            cout << "Thanks for using our banking service!\n";
            return 0;
        } else if (choice == 5) {
            do {
                cout << "\nBank System Menu:\n";
                cout << "(1) View Balance\n";
                cout << "(2) Deposit Money\n";
                cout << "(3) Withdraw Money\n";
                cout << "(4) Delete Account\n";
                cout << "(5) EXIT\n";
                cout << "Enter your choice: ";
                cin >> choice2;

         if (choice2 < 1 || choice2 > 5) {
                cout << "Invalid choice " << choice2 << ". Please choose a number (1-5): ";
                }
            } while (choice2 < 1 || choice2 > 5);

        switch (choice2) {
            case 1: //عرض المبلغ المتاح في الحساب
                  cout << "Your current balance is: $" << balance << endl;
            break;

            case 2: { //إضافة مبلغ للحساب
                  double deposit;
                  cout << "Enter amount to deposit: ";
                  cin >> deposit;

            while (deposit <= 0) {
                  cout << "Invalid deposit amount!\n";
                  cout << "Deposit must be a positive number.\n";
                  cout << "Enter a valid deposit amount: ";
                  cin >> deposit;
                }

                    balance += deposit;
                    cout << deposit << "$" << "deposited successfully.\n";
            break;
                }

            case 3: { //سحب مبلغ من الحساب
                 double withdrawal;
                 cout << "Enter amount to withdraw: ";
                 cin >> withdrawal;

                 while (withdrawal <= 0) {
                        cout << "Invalid withdrawal amount!\n";
                        cout << "Withdrawal must be a positive number.\n";
                        cout << "Enter a valid withdrawal amount: ";
                        cin >> withdrawal;
                    }

                if (balance >= withdrawal) {
                     balance -= withdrawal;
                    cout << withdrawal << "$" << "withdrawn successfully.\n";
                    } else {
                    cout << "Insufficient funds. Withdrawal denied.\n";
                    }
            break;
                }

            case 4: //حذف الحساب
                    deleteAccount();
            break;

            case 5: //خروج من البرنامج
                    cout << "Exiting. Thanks for using our banking service!\n";
            break;
            }
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

