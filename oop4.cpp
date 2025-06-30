#include <iostream>
using namespace std;

class Person {
public:
    string name;
    string id;
    string gender;
    int age;

    void accept(int x) {
        cout << x << " Person details:\n";
        cout << "Enter the Name: ";
        cin >> name;
        cout << "Enter the id: ";
        cin >> id;
        cout << "Enter the Gender: ";
        cin >> gender;
        cout << "Enter the Age: ";
        cin >> age;
    }

    void display() {
        cout << "Name: " << name << endl 
             << "Id: " << id << endl 
             << "Gender: " << gender << endl 
             << "Age: " << age << endl;
    }
};

class Doctor : virtual public Person {
public:
    string specialization;
    float experience;
    string availability;

    void acceptD() {
        cout << "Enter Specialization: ";
        cin >> specialization;
        cout << "Enter Experience: ";
        cin >> experience;
        cout << "Enter Availability: ";
        cin >> availability;
    }

    void displayD() {
        cout << "Specialization: " << specialization << endl 
             << "Experience: " << experience << endl 
             << "Availability: " << availability << endl;
    }
};

class Nurse : virtual public Person {
public:
    string department;
    float shift;

    void acceptN() {
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Shift: ";
        cin >> shift;
    }

    void displayN() {
        cout << "Department: " << department << endl 
             << "Shift: " << shift << endl;
    }
};

class AdministrativeStaff : public Doctor, public Nurse {
public:
    string position;

    void acceptA() {
        cout << "Enter Position: ";
        cin >> position;
    }

    void displayA() {
        cout << "Position: " << position << endl;
    }
};

int main() {
    Doctor D[5];
    Nurse N[5];
    AdministrativeStaff A[5];
    int ch,sizeN,sizeD;
    
      

    do {
        cout << "Menu\n1. Doctor\n2. Display Doctor Details\n3. Nurse\n4. Display Nurse Details\n5. Receptionist\n6. Exit\n";
        cin >> ch;
        
        switch (ch) {
        case 1: {
            cout << "Enter the Total no. of Doctor staff: ";
         
            cin >> sizeD;
            for (int i = 0; i < sizeD; i++) {
                D[i].accept(i + 1);
                D[i].acceptD();
            }
            break;
        }
        case 2: {
            for (int i = 0; i < sizeD; i++) { 
                cout << i + 1 << " Doctor Detail\n";
                D[i].display();
                D[i].displayD();
                cout << endl;
            }
            break;
        }
        case 3: {
            cout << "Enter the Total no. of Nurse staff: ";
            
            cin >> sizeN;
            for (int i = 0; i < sizeN; i++) {
                N[i].accept(i + 1);
                N[i].acceptN();
            }
            break;
        }
        case 4: {
            for (int i = 0; i < sizeN ; i++) { // Changed to 5 since it's a static array
                cout << i + 1 << " Nurse Detail\n";
                N[i].display();
                N[i].displayN();
                cout << endl;
            }
            break;
        }
        case 5: {
            int ava;
            cout << "Receptionist:\n";
            cout << "Ask About Info\n1. Doctor\n2. Nurse\n";
            cin >> ava;
            if (ava == 1) {
                string tempdoc;
                cout << "Enter name of doctor: ";
                cin >> tempdoc;
                bool found = false; 
                for (int i = 0; i < sizeD; i++) { 
                    if (tempdoc == D[i].name) {
                        cout << "Doctor Detail\n";
                        D[i].display();
                        D[i].displayD();
                        cout << endl;
                        found = true; 
                        break;
                    }
                }
                if (!found) {
                    cout << "Doctor not found.\n"; 
                }
            } else {
                string tempnur;
                cout << "Enter name of Nurse: ";
                cin >> tempnur;
                bool found = false; 
                for (int i = 0; i < sizeN; i++) { 
                    if (tempnur == N[i].name) {
                        cout << "Nurse is at " << N[i].department << "\nShift: " << N[i].shift << endl;
                        cout << i + 1 << " Nurse Detail\n";
                        N[i].display();
                        N[i].displayN();
                        cout << endl;
                        found = true; 
                        break;
                    }
                }
                if (!found) {
                    cout << "Nurse not found.\n"; 
                }
            }
            break;
        }
        }
    } while (ch != 6);

    return 0;
}
