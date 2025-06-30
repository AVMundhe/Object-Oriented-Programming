#include <iostream>
#include <stdexcept>  // For exception handling
#include <string>

using namespace std;

class Television {
public:
    string model;
    int screenSize;
    double price;

 
    friend istream& operator>>(istream& GheunTak, Television& tv) {
        cout << "Enter model (up to 4 digits): ";
        GheunTak >> tv.model;

        cout << "Enter screen size (in inches): ";
        GheunTak >> tv.screenSize;

        cout << "Enter price: ";
        GheunTak >> tv.price;

      
        if (tv.model.length() > 4) {
            throw 1;  
        }
        if (tv.screenSize < 12 || tv.screenSize > 70) {
            throw 2; 
        }
        if (tv.price < 0 || tv.price > 5000) {
            throw 3;  
        }

        return GheunTak;
    }

    
    friend ostream& operator<<(ostream& DeunTak, const Television& tv) {
        DeunTak << "Model: " << tv.model << endl;
        DeunTak << "Screen size: " << tv.screenSize << " inches" << endl;
        DeunTak << "Price: Rs." << tv.price << endl;
        return DeunTak;
    }

    
};

int main() {
    Television tv;  
    try {
        cin >> tv; 
    } catch (int e) {
       if (e==1)
       {
        cout << "Invalid Model\n";
       }
       else if (e==2)
       {
        cout << "Invalid Screen Size\n";
       }
       else if (e==3)
       {
        cout << "Invalid Price";
       }    
    }

    cout << "Television details: " << endl;
    cout << tv;  
    return 0;
}
