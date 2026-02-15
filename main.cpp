#include <iostream>
using namespace std;

struct Student {
    string name;
    int roll;
    string mail;
    int marks;
    string id;
    string pass;
};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS] = {
    {"Shourjya Sarkar", 31, "shourjyasarkar131@gmail.com", 463, "2006", "shourjya2006"},
    {"Supriyo Adak", 43, "saptakchakraborti35@gmail.com", 478, "2007", "supriyo2007"},
    {"Sayan Das", 33, "sayandas566@gmail.com", 432, "2005", "sayan2005"}
};
int studentCount = 3;

// Function to sign up
void signUp() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Registration limit reached!\n";
        return;
    }

    Student newStudent;
    cout << "\n--- Sign Up ---\n";
    cout << "Enter Name: ";
     cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter Roll: ";
    cin >> newStudent.roll;
    cout << "Enter Email: ";
    cin >> newStudent.mail;
    cout << "Enter Marks: ";
    cin >> newStudent.marks;
    cout << "Create Student ID: ";
    cin >> newStudent.id;


    // Check ID uniqueness
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == newStudent.id) {
            cout << "ID already exists. Try again.\n";
            return;
        }
    }

    cout << "Set Password: ";
    cin >> newStudent.pass;

    students[studentCount++] = newStudent;
    cout << "\nRegistration Successful!\n";
}

// Function to logout
void logout() {
    string choice;
    cout << "\nDo you want to logout? (yes/no): ";
    cin >> choice;
    if (choice == "yes" || choice == "Yes") {
        cout << "Logged out successfully.\n";
    } else {
        cout << "You are still logged in.\n";
    }
}

void admin(){
for(int j=0;j<100;j++){
    string stdid;
    cout<<"Enter Student ID to edit for:";
    cin>>stdid;
    for(int i=0;i<studentCount;i++){
        if(students[i].id==stdid) {
            const string oldname=students[i].name;
		    cout<<"Edit Student Name: ";
	        cin.ignore();
	        getline(cin, students[i].name);
	        cout << "Edit Roll: ";
	        cin >> students[i].roll;
	        cout << "Edit Email: ";
	        cin >> students[i].mail;
	        cout << "Edit Marks: ";
	        cin >> students[i].marks;
            cout<<"The details of "<<oldname<<" has been upgraded successfully Admin.\n";
            
            string edit;
            cout<<"Do you want to check those? (Yes / No):";
            cin>>edit;
            if(edit=="Yes"||edit=="yes"){
                cout << "Name: " << students[i].name << endl;
                cout << "Roll: " << students[i].roll << endl;
                cout << "E-mail: " << students[i].mail << endl;
                cout << "Marks: " << students[i].marks << endl;
                logout();
            }
            else{
                logout();
            }
            break;
        }
    }
    break;
    }
}

// Function to login
void login() {
    string i_d;
    string password;
    bool found = false;

    cout << "\n--- Login ---\n";
    cout << "Enter Student ID: ";
    cin >> i_d;
    cout << "Enter Password: ";
    cin >> password;
    
    if(i_d=="Admin"||i_d=="admin"){
        found=true;
        if(password=="admin0001"){
            cout<<"Welcome Admin!\n";
    	    admin();
        }
        else{
        cout<<"You are not an admin! Sorry!";
        }
	}
    
    else{
    for (int i = 0; i < studentCount; i++) {
        if (i_d == students[i].id) {
            found = true;
            if (password == students[i].pass) {
                cout << "\nLogin Successful!\n";
                cout << "\n--- Profile ---\n";
                cout << "Name: " << students[i].name << endl;
                cout << "Roll: " << students[i].roll << endl;
                cout << "E-mail: " << students[i].mail << endl;
                cout << "Marks: " << students[i].marks << endl;
                logout();
            } else {
                cout << "Incorrect password!\n";
                string reset;
                cout << "Forgot password? (yes/no): ";
                cin >> reset;
                if (reset == "yes" || reset == "Yes") {
                    string new_pass;
                    cout << "Enter new password: ";
                    cin >> new_pass;
                    students[i].pass = new_pass;
                    cout << "Password reset successful.\n";
                }
            }
            break;
        }
    }

    if (!found) {
        cout << "Student ID not found.\n";
    }
    }
}

// Main flow controller
int main() {
    string choice;
    cout << "Welcome!\n";
    cout << "Do you want to Login or Sign Up? (login/signup): ";
    cin >> choice;

    if (choice == "signup") {
        signUp();
        cout << "\nPlease login now.\n";
        login();
    } else if (choice == "login") {
        login();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
