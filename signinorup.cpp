#include <iostream>
#include <string>
using namespace std;
class MUser {
private:
    string name;
    string password;
    string role;
public:
    // ---------- Default Constructor ----------
    MUser() {
        cout << "Default Constructor Called!" << endl;
    }
    // ---------- Parameterized Constructor ----------
    MUser(string name, string password, string role) {
        this->name = name;           
        this->password = password;
        this->role = role;
        cout << "Parameterized Constructor Called!" << endl;
    }
    // ---------- Copy Constructor ----------
    MUser(const MUser& user) {
        name = user.name;
        password = user.password;
        role = user.role;
        cout << "Copy Constructor Called!" << endl;
    }
    // ---------- Destructor ----------
    ~MUser() {
        cout << "Destructor Called for user: " << name << endl;
    }
    // ---------- Sign In Function ----------
    bool signIn(string n, string p) {
        if (n == name && p == password) {
            return true;
        }
        else {
            return false;
        }
    }
    // ---------- Show Role ----------
    void showRole() {
        cout << "Role: " << role << endl;
    }
    // ---------- Show Data ----------
    void showData() {
        cout << "Name: " << name << " | Role: " << role << endl;
    }
};
// Main Function
int main() {
    // Header setup
    cout << "==========================================\n";
    cout << "          SIGN-IN / SIGN-UP APP          \n";
    cout << "==========================================\n\n";
    // Sign Up Section
    cout << "--- SIGN UP ---" << endl;
    string name, password, role;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Role (Admin/User): ";
    cin >> role;
    // Dynamic Object Creation (Heap Memory)
    MUser* user1 = new MUser(name, password, role);
    cout << "\nUser created successfully!\n";
    // Sign In Section
    cout << "\n--- SIGN IN ---" << endl;
    string n, p;
    cout << "Enter Name: ";
    cin >> n;
    cout << "Enter Password: ";
    cin >> p;
    if (user1->signIn(n, p)) {
        cout << "Login Successful!" << endl;
        user1->showData();
    }
    else {
        cout << "Invalid Credentials!" << endl;
    }
    cout << "\nCreating a copy of user1..." << endl;
    MUser user2 = *user1; 
    user2.showRole();
    delete user1;
    return 0;
}