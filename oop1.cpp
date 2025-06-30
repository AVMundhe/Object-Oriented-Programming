#include <iostream>
#include <string>
using namespace std;

class Bank {
public:
    float deposit;
    string name;
    long account;  
    float withdrawal;

    void depositMoney() {
        float depositAmount;
        cout << "Enter the amount to deposit: ";
        cin >> depositAmount;
        deposit += depositAmount;
        cout<<"Amount deposited successfully\nTotal amount in account is: "<<deposit;
        cout << "\n";
    }

    void accept() {
        cout << "\nEnter the name of Account Holder: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the Account number: ";
        cin >> account;
        cout << "Enter Your Current Balance: ";
        cin >> deposit;
        cout << "\n";
    }

    void display() {
        cout<<"|"<<name<<"\t|"<<account<<"\t|"<<deposit<<"\n";
     
    }

    void withdraw() {
        if (deposit <= 0) {
            cout << "You have currently a Null Account\nCan't withdraw Money...\n";
            return;
        }
        cout << "Enter the amount to withdraw: ";
        cin >> withdrawal;
        if (withdrawal > deposit) {
            cout << "You don't have that much money in your Account to withdraw...\n";
        } else {
            deposit -= withdrawal;
            cout<<"Amount Deducted Successfully\n Remaining Balance is: "<<deposit<<endl;
        }
    }
};

int main() {
    int choice,i,n,flag=1;
    long temp;
    Bank b[10];

    do {
        cout << "Enter Your Choice:\n"
             << "1. Accept New Account Holder\n"
             << "2. Withdraw an amount\n"
             << "3. Display information\n"
             << "4. Deposit money\n"
             << "5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"Enter the Total No. of Account Holders: ";
                cin>>n;
                for ( i = 0; i < n; i++)
                {
                      b[i].accept();
                }            
                break;
            case 2:
                cout<<"Enter Your Account Number: ";
                cin>>temp;
                for ( i = 0; i < n; i++)
                {
                    if (temp==b[i].account)
                    {   flag=0;
                        b[i].withdraw();
                        break;
                    }
                    
                }    
                if (flag==1)
                {
                    cout<<"Account NO. Not available\n";
                }
                flag=1;                 
                break;
            case 3:
                cout<<"|Name\t|Account|Total Amount\n";
                for ( i = 0; i < n; i++)
                {
                     b[i].display();
                }
                break;
            case 4:
              cout<<"Enter Your Account Number: ";
                cin>>temp;
                for ( i = 0; i < n; i++)
                {
                    if (temp==b[i].account)
                    {   flag=0;
                         b[i].depositMoney();
                        break;
                    }
                    
                }    
                if (flag==1)
                {
                    cout<<"Account Not available\n";
                }
                flag=1;                  
                break;
            case 5:
                cout <<"\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}


