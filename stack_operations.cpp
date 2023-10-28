#include<iostream>
using namespace std;

#define maxsize 20

class stack{
    private:
    int arr[maxsize];
    int top;
    
    public:
    stack(){      //constructor
        top=-1;
    }

    public:
        void push(int x){
            if(top==maxsize-1){
                cout<<"Stack overflow"<<endl;
            }else{
                top++;
                arr[top]=x;
                cout<<"Top element is: "<<x<<endl;
            }
        }

        int pop(){
            int v;
            if(top==-1){
                cout<<"\n Stack underflow\n";
                return -1;
                }
                else {
                    v = arr[top];
                    top--;
                    return v;
                }
        }

        int peek(){
            if(top==-1){
                cout<<"\nStack is empty"<<endl;
                return -1;
            }
            return arr[top];
        }
};

int main(){
    stack s1;
    int n,x,c;
    char uc;
    do
    {
        cout<<"******Stack operations********";
        cout<<"\nPress 1 to push\n";
        cout<<"Press 2 to pop\n";
        cout<<"press 3 to peek\n";
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c){
            case 1:
                cout<<"Enter the element you want to push:  ";
                cin>>n;
                s1.push(n);
                break;
            
            case 2:
                x = s1.pop();
                if(x != -1){
                cout<<"popped element is : "<<x<<endl;
                }else{
                    cout<<"Top is : "<<x<<endl;
                }
                break;

            case 3:
                x=s1.peek();
                if(x != -1){
                    cout<<"The Top Element of Stack is: "<<x<<endl;
                }
                break;
            
            default:
                cout<<"Exit";
                exit(1);
        }

    cout<<"\nDo you want to continue...?(y/n)\n ";
    cin>>uc;
    }while( uc == 'y');

    return 0;
}





        

