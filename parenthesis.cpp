#include<iostream>
#include<string>
#include<stack>
using namespace std;


bool isbalanced(string exp){
    stack <char> s;
    for (int i=0 ;i<=exp.length(); i++){
        if(exp[i]== '(' || exp[i] == '[' || exp[i] == '{' )
        {
            s.push(exp[i]);
        }
        else if(exp[i]== ')' || exp[i] == ']' || exp[i] == '}')
        {
            if(s.empty() )
            {
               return false;
            }
            char Top= s.top();
            s.pop();
            if(exp[i] == ')' && Top!= '(' || exp[i] == ']' && Top!= '[' || exp[i] == '}' && Top!= '{'){
                return false;
            }   
        } 
    }
    return s.empty();
}

int main() {
    string exp;
    cin>>exp;
    if(isbalanced(exp)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<< "ImBalanced" <<endl;
    }
    return 0;
}




