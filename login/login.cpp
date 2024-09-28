#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a user
void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Store credentials in a file
    ofstream file("credentials.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!" << endl;
}

// Function to login a user
void loginUser() {
    string username, password, storedUsername, storedPassword;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Read stored credentials from file
    ifstream file("credentials.txt");
    bool found = false;
    while (file >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            found = true;
            break;
        }
    }
    file.close();

    if (found) {
        cout << "Welcome, " << username << "!" << endl;
        cout << "Login successfull"<< endl;
    } else {
        cout << "Incorrect credentials. Please try again." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}