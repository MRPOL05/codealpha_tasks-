#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userExists(const string &username) {
    ifstream file("database/" + username + ".txt");
    return file.good();
}

void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    
    if (userExists(username)) {
        cout << "Username already exists! Try another.\n";
        return;
    }
    
    cout << "Enter a password: ";
    cin >> password;
    
    ofstream file("database/" + username + ".txt");
    if (!file) {
        cout << "Error creating user file!\n";
        return;
    }
    file << username << endl << password;
    file.close();
    
    cout << "Registration successful!\n";
}

bool loginUser() {
    string username, password, storedUser, storedPass;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    
    ifstream file("database/" + username + ".txt");
    if (!file) {
        cout << "User does not exist!\n";
        return false;
    }
    
    getline(file, storedUser);
    getline(file, storedPass);
    file.close();
    
    if (username == storedUser && password == storedPass) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Invalid credentials!\n";
        return false;
    }
}

int main() {
    int choice;
    
    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    cout << "Welcome to the system!\n";
                }
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option, try again!\n";
        }
    }
}
