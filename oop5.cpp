#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
string postfix;
int top=-1;
char stack[10];

char topp(){
    if (top==-1)
    {
        return 0;
    }
    else{
    return stack[top];
}}

void push(char c){
    if(top==10){
        cout<<"Stack overflow\n";
    }
    else{
         top++;
         stack[top]=c;
    }
}

char pop(){
    if(top==-1){
      cout<<"Stack underflow\n";
    }
    else{
        return stack[top--];
    }
}

int incomingpriority(char x){
    if (x=='+' || x=='-')
    {
        return 1;
    }
    else if (x=='*' || x=='/')
    {
        return 3;
    }
    else if (x=='^')
    {
     return 6;
    }
    
    else if(x=='('){
        return 9;
    }
}

int onstackpriority(char x){
 if (x=='+' || x=='-')
    {
        return 2;
    }
    else if (x=='*' || x=='/')
    {
        return 4;
    }
    else if (x=='^')
    {
     return 5;
    }
    
    else {
        return 0;
    }

}




void infixtopostfix(char x[],int n){
    for (int i = 0; i < n; i++)
    {
        if (isalnum(x[i]))
        {
            postfix += x[i];
        }
        else if(x[i]=='('){
            push(x[i]);
        }
        else if(x[i]==')'){
            while (topp()!='(' && top!=-1)
            {
                postfix+=pop();
            }
            if (top != -1) {
                pop(); 
            }
            
        }
        else if(incomingpriority(x[i]) > onstackpriority(x[i])){
          push(x[i]);
        }
        else{
           while ( incomingpriority(x[i]) <= onstackpriority(topp())) {
    postfix += pop();
}

            push(x[i]); 
        }

        
        
    }
    
        while (top!=-1)
        {
            postfix+=pop();
        }
  


}
int main(){
    char infix[20];
    int n;
    cout<<"Enter the infix expression:\n";
    cin>>infix;
    n=strlen(infix);
    infixtopostfix(infix,n);
    
    cout<<"postfix expression is: \n";
    cout<<postfix;

    return 0;
}