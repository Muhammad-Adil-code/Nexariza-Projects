#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Account {
    string username;
    string password;
    double balance;
    vector<string> transactions;
};

void saveData(vector<Account>& accounts) {
    ofstream file("credit.THT");
    for (const auto& account : accounts) {
        file << account.username << "," << account.password << "," << account.balance << ",";
        for (const auto& transaction : account.transactions) {
            file << transaction << ";";
        }
        file << endl;
    }
    file.close();
}

void loadData(vector<Account>& accounts) {
    ifstream file("credit.THT");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, password, balanceStr, transactionsStr;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, balanceStr, ',');
        getline(ss, transactionsStr, ',');
        double balance = stod(balanceStr);
        vector<string> transactions;
        stringstream transactionsSS(transactionsStr);
        string transaction;
        while (getline(transactionsSS, transaction, ';')) {
            transactions.push_back(transaction);
        }
        Account account = {username, password, balance, transactions};
        accounts.push_back(account);
    }
    file.close();
}

void createAccount(vector<Account>& accounts) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    Account newAccount = {username, password, 0.0, {}};
    accounts.push_back(newAccount);
    saveData(accounts);
    cout << "Your Account created successfully!" << endl;
}

void login(vector<Account>& accounts) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    for (auto& account : accounts) {
        if (account.username == username && account.password == password) {
            cout << "You Login Your account successfully!" << endl;
            // Display account menu
            int choice;
            do {
                cout << "1. Deposit money" << endl;
                cout << "2. Withdraw money" << endl;
                cout << "3. Check account balance" << endl;
                cout << "4. View transaction history" << endl;
                cout << "5. Logout" << endl;
                cin >> choice;
                switch (choice) {
                    case 1:
                        double amount;
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        account.balance += amount;
                        account.transactions.push_back("You Deposited amount->" + to_string(amount));
                        saveData(accounts);
                        break;
                    case 2:
                        amount;
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        if (account.balance >= amount) {
                            account.balance -= amount;
                            account.transactions.push_back("Withdrew" + to_string(amount));
                            saveData(accounts);
                        } else {
                            cout << "Insufficient balance!" << endl;
                        }
                        break;
                    case 3:
                        cout << "Your Account balance is: " << account.balance << endl;
                        break;
                    case 4:
                        cout << "Your Transaction history is:" << endl;
                        for (const auto& transaction : account.transactions) {
                            cout << transaction << endl;
                        }
                        break;
                    case 5:
                        cout << "Logged out successfully!" << endl;
                        return;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } while (true);
        }
    }
    cout << "Invalid username or password. Please try again." << endl;
}

int main() {
    vector<Account> accounts;
    loadData(accounts);
    int choice;
    do {
        cout << "1. Create account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                login(accounts);
                break;
            case 3:
                cout << "Exiting program.... Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);
    return 0;
}