#include<iostream>
using namespace std;
#define maxsize 10

class stack{
    private:
    int top;
    int a[maxsize];

    public:
    stack(){
        top = -1;
    }

    bool empty(){
        return top == -1;
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
            return a[top--];
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

class queue{
    private :
    stack enq , deq;
    public:
    queue() { }

    void enqueue (int x)
    {
        if(enq.empty() && deq.empty()){
            enq.push(x);
        }
        else if(enq.empty())
        {
            while(!deq.empty())
            {
                enq.push(deq.pop());
            }
            enq.push(x);
        }
        else{
            enq.push(x);
        }
    }

    void dequeue(){
        if(enq.empty() && deq.empty())
        {
            cout<<"------Queue is Empty------"<<endl;
            return;
        }
        if(deq.empty())
        {
            while(!enq.empty())
            {
                deq.push(enq.pop());
            }
        }
        cout<<"------Deleted element is------"<<ends<<deq.pop()<<endl;
    }
};

int main()
{
    int ch, v;
    char uc;
    queue q;

    do
    {
        cout << "Press 1 to insert " << endl;
        cout << "Press 2 to delete " << endl;
        cout<< "Press any key to Exit--" <<endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "--Enter value--" << endl;
            cin >> v;
            q.enqueue(v);
            break;
        }
        case 2:
        {
            q.dequeue();
            break;
        }
        default:
            exit(1);
        }

        cout<<"\n Do you want to perform again..?('y' for yes/ 'n' for no)\n";
        cin>>uc;
    } while (uc == 'y');

    return 0;
}
