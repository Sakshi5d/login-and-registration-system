#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// function to check if a user exists in the file
bool userExists(string username, string password) {
    ifstream infile("users.txt");
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        string name, pass;
        if (iss >> name >> pass) {
            if (name == username && pass == password) {
                return true;
            }
        }
    }
    return false;
}

// function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // check if the user already exists
    if (userExists(username, password)) {
        cout << "User already exists" << endl;
        return;
    }

    // add the new user to the file
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "User registered successfully" << endl;
}

// function to handle the login process
void login() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // check if the user exists
    if (userExists(username, password)) {
        cout << "Login successful" << endl;
    }
    else {
        cout << "Invalid username or password" << endl;
    }
}

// main function
int main() {
    int choice;

    while (true) {
        // display the menu
        cout << "1. Register\n2. Login\n3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Exiting program" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}