#include<iostream>
using namespace std;
#define maxsize 20

class stack{
    private:
    int top;
    char a[maxsize];

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
            top++;
            a[top] = v;
        }
    }

    int pop(){
        if(top == -1)
        {
            cout<<"--------stack underflow--------"<<endl;
            return 0;
        }else{
            top--;
            return a[top];
        }
    }

    int peek(){
        if(top == -1){
            cout<<"--------stack is empty--------"<<endl;
            return -1;
        }else{
            return a[top];
        }
    }
};

bool isOperator(char c){
    if(c == '+'|| c=='-' || c=='*' || c=='/' || c=='^'){
        return true;
    }else{
        return false;
    }
}

int precedenceOfOp(char op) {
    if (op == '^'){
        return 3;
    }
    else if ((op == '*')||(op== '/')){
        return 2;
    }
    else if((op=='+') || (op=='-')) {
        return 1;
    }
    else{
        return -1;
    }
}

string InfixToPostfix( string infix){
    string postfix;
    stack s;
    for(int i=0; i<infix.length(); i++){
        if((infix[i]>='a' && infix[i]<='z') || (infix[i] >='A' && infix[i]<='Z'))
        {
            postfix += infix[i];
        }
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while((s.peek()!= '(') && (!s.empty()))
            {
                char temp = s.peek();
                postfix += temp; 
                s.pop();
            }
            if(s.peek()=='(')
			{
				s.pop();
			}
        }
        else if(isOperator(infix[i]))
        {
            if(s.empty()){
                s.push(infix[i]);
            }
            else 
            {
                if(precedenceOfOp(infix[i]) > precedenceOfOp(s.peek()))
                {
                    s.push(infix[i]);
                }
				else
				{
					while((!s.empty())&&( precedenceOfOp(infix[i])<=precedenceOfOp(s.peek())))
					{
						postfix+=s.peek();
						s.pop();
					}
					s.push(infix[i]);
                }
            }
        }
        else if(!isOperator(infix[i]))
        {
            cout<<"Invalid operator found"<<endl;
            return "";
        }
    }
    while(!s.empty()){
        postfix+= s.peek();
        s.pop();
    }

    return postfix;
}

int main(){
    char uc;
    do
    {
    string infix_exp, postfix_exp;
    cout<<"Enter the Infix Expression: "; 
    cin>>infix_exp;
    cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
    postfix_exp = InfixToPostfix(infix_exp);
    cout<<"POSTFIX EXPRESSION: "<<postfix_exp<<endl;
    
    cout<<"\n Do you want to continue..?(y/n)\n";
    cin>>uc;
    }while(uc == 'y');
    return 0;
}
