#include<iostream>
#include<math.h>
using namespace std;
#define maxsize 20

class stack{
    private:
    int top;
    int a[maxsize];

    public:
    stack(){
        top = -1;
    }

    int empty(){
        if(top == -1){
            return 1;
        }else{
            return 0;
        }
    }

    void push(int v){
        if(top == maxsize-1){
            cout<<"-------stack overflow--------"<<endl;
        }
        else{
            ++top;
            a[top] = v;
        }
    }

    int pop(){
        if(top == -1)
        {
            cout<<"--------stack underflow--------"<<endl;
            return 0;
        }else{
            return a[top--];
        }
    }
};
    int postfix_Eval(string exp){
        stack s;
        for(int i =0; i<exp.length(); i++){
            char ch = exp[i];
            if(ch >= '0' && ch <='9'){
                s.push(ch - '0');
            }
            else if (ch == ' ') {
            continue;
            }
            else if(ch=='+' || ch == '-' || ch == '*' || ch == '/'){
                int a = s.pop();
                int b =s.pop();
                
                switch (ch){
                    case '+':
                             s.push(b+a);
                             break;
                    case '-':
                            s.push(b-a);
                            break;
                    case '*':
                            s.push(b*a);
                            break;
                    case '/':
                            if(a!=0){
                            s.push(b/a);
                            }else{
                                cout<<"\nError: division by zero";
                                exit(1);
                            }
                            break;
                }
            }
        }
        if(!s.empty()){
            return s.pop();
        }else{
            cout<<"\n Invalid expression";
        }
        return ' ';
    }


int main(){
    string postfix_exp;
    cout << "Enter the Postfix Expression: "; 
    cin >> postfix_exp ;
    int res = postfix_Eval(postfix_exp);
    cout<<"Result : "<<res;
    return 0;
}
