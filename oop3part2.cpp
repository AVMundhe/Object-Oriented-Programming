#include<iostream>
using namespace std;

class complex{    
public:
float real;
float imaginary;

complex(){
  real=0;
  imaginary=0;   
}

void input(int x){
    cout<<"Equation: "<<x+1<<endl;
    cout<<"Enter the Real Part: ";
    cin>>real;
    cout<<"Enter the Imaginary Part: ";
    cin>>imaginary;
    display();
}

void display(){
    cout<<real<<" + i("<<imaginary<<")"<<endl;
}

friend complex operator *(complex &b ,complex &a);

friend complex operator +(complex &b ,complex &a);

friend complex operator -(complex &b ,complex &a);

friend complex operator /(complex &b ,complex &a);


};


complex operator *(complex &b ,complex &a){
   complex temp;

   temp.real=(b.real * a.real) - (b.imaginary*a.imaginary);
   temp.imaginary=(b.real * a.imaginary) + (b.imaginary * a.real);

    return temp;
}



complex operator +(complex &b ,complex &a){
  complex temp;
  
  temp.real=(b.real+a.real);
  temp.imaginary=(b.imaginary+a.imaginary);

  return temp;
}

complex operator -(complex &b ,complex &a){
  complex temp;
  
  temp.real=(b.real-a.real);
  temp.imaginary=(b.imaginary-a.imaginary);

  return temp;
}


complex operator /(complex &b ,complex &a){
  complex temp;

  temp.real=((b.real*a.real)+(b.imaginary*a.imaginary))/((b.imaginary*b.imaginary)+(a.imaginary*a.imaginary));
  temp.imaginary=((a.real*b.imaginary)-(b.real*a.imaginary))/((b.imaginary*b.imaginary)+(a.imaginary*a.imaginary));

  return temp;
}



int main(){
    complex number[3];
    int ch;
    do
    {   cout<<"Menu\n1.Addition\n2.Substraction\n3.Multiply\n4.Divide\n5.Exit\n";
        cin>>ch;
         switch (ch)
        {
         
        case 1:

        for(int i=0;i<2;i++)
        {
           number[i].input(i); 
        }

        number[2] = number[0] + number[1];

        cout<<"\nAddition is: \n";
        number[2].display();
        
        break; 

        case 2:

         for(int i=0;i<2;i++)
        {
           number[i].input(i); 
        }

        number[2] = number[0] - number[1];

        cout<<"\nSubstraction is: \n";
        number[2].display();
        
        break; 

        case 3:

        for(int i=0;i<2;i++)
        {
           number[i].input(i); 
        }

        number[2] = number[0] * number[1];

        cout<<"\nAnswer is: \n";
        number[2].display();
        
        break; 

        case 4:

        for ( int i = 0; i < 2; i++)
        {
           number[i].input(i); 
        }
        
         number[2] = number[0] / number[1];

        cout<<"\nAnswer is: \n";
        number[2].display();
        
        break; 


        break;

        case 5:
        break; 
       
        default:
            cout<<"Wrong choice...\n";
            break;
        }
    } while (ch!=5);
    

    return 0;
}