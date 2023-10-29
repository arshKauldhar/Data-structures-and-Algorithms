#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class list{
    private:
    node *head;

    public:
    list(){
        head = nullptr;
    }
    ~list(){}

    void insert_first(int n){
        node *temp=new node();
        temp->data =n ;
        temp->next = head;
        head = temp;
    }

    void insert_last(int n ){
        if (head == nullptr){
            insert_first(n);
            return;
        }
        node *cur, *prev;
        cur = head;
        while(cur != nullptr){
            prev = cur;
            cur = cur->next;
        }
        node *temp = new node();
        temp-> data = n;
        temp->next = nullptr;
        prev->next = temp;
    }

    void add_particular_Pos(int pos, int n){
        node *cur,*prev;
        cur = head;
        for(int i =0; i<pos-1; i++){
            prev = cur;
            cur = cur->next;
        }
        node *temp = new node();
        temp->data = n;
        temp->next = cur;
        prev->next = temp;
    }

    void delete_first(){
        if(head == nullptr){
            cout<<"There is no Node to delete\n";
            return ;
        }
        node *temp;
        temp = head;
        head = head->next;
        cout<<"Deleted element is: "<<temp->data<<"\n";
        delete temp;
    }

    void delete_last(){
        node *cur, *prev;
        cur = head;
        while(cur->next != nullptr){
            prev = cur;
            cur = cur->next;
        }
        prev->next = nullptr;
        cout<<"Deleted element is: "<<cur->data<<"\n";
        delete cur;
    }

    void delete_particular_Pos(int pos){
        node *cur,*prev;
        cur = head;
        for(int i=0; i<pos-1; i++){
            prev = cur;
            cur= cur->next;
        }
        prev->next = cur->next;
        cout<<"Deleted element is: "<<cur->data<<"\n";
        delete cur;
    }

    void display(){
        node *cur;
        cur = head;
        if(cur == nullptr){
            cout<<"There is no node";
        }else{
        cout<<"The linked list formed is: ";
        while(cur != nullptr){
            cout<<cur->data<<"->";
            cur = cur->next;
        }
        cout<<"NULL";
        cout<<"\n";
        }
    }

    bool find_value(int val){                 //searching operation
        node *cur;
        cur = head;
        while(cur!= nullptr){
            if(cur->data==val){
                cout<<"Value found in list"<<endl;
                break;
            }
            cur = cur->next;
        }
        if(cur == nullptr)
            return false;
        else
            return true;
    }

    void add_after_value(int val, int n){
        node *cur;
        cur = head;
        if(find_value(val)){
            while(cur->data != val){
                cur = cur->next;
            }
            node *temp = new node();
            temp->data = n;
            temp->next = cur->next;
            cur->next = temp;
        }else{
            cout<<"Value not found in the list\n";
        }
    }

    void delete_value(int val){
        node *cur , *prev;
        cur = head;
        if(find_value(val)){
        while(cur->data != val){
            prev = cur;
            cur= cur->next;
        }
        node *temp;
        temp = cur;
        prev->next = cur->next;
        cout<<"Deleted element is :"<<temp->data<<"\n";
        delete temp;
        }else{
            cout<<"Value not found in the list\n";
        }
    }

    void reverse_list(){
        node *cur, *prev, *next;
        next = nullptr;
        prev = nullptr;
        cur = head;
        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

};

int main(){
    list l;
    char user_ch;
    int ch;
    do {
        cout<<"1. press 1 to insert "<<endl<<"2. press 2 to delete"<<endl<<"3. press 3 to reverse a list"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                int n1,val;
                cout<<"1. --insert at first--"<<endl;
                cout<<"2. --insert at last--"<<endl;
                cout<<"3. --insert at particular position--"<<endl;
                cout<<"4. --insert after a value--"<<endl;
                cin>>n1;
                switch(n1){
                    case 1:
                    cout<<"Enter number to insert:"<<endl;
                    cin>>val;
                    l.insert_first(val);
                    break;

                    case 2:
                    cout<<"Enter number to insert:"<<endl;
                    cin>>val;
                    l.insert_last(val);
                    break;

                    case 3:
                    int pos, val;
                    cout<<"Enter position and value to insert:"<<endl;
                    cin>>pos>>val;
                    l.add_particular_Pos(pos, val);
                    break;

                    case 4:
                    int v;
                    cout<<"Enter the value after which you want to add new node:"<<endl;
                    cin>>v;
                    cout<<"Enter value to be added:"<<endl;
                    cin>>val;
                    l.add_after_value(v,val);
                    break;
                }
                break;
            case 2:
                int n2;
                cout<<"1. --Delete first--"<<endl;
                cout<<"2. --Delete last--"<<endl;
                cout<<"3. --Delete from particular postion--"<<endl;
                cin>>n2;
                switch(n2){
                    case 1:
                    l.delete_first();
                    break;

                    case 2:
                    l.delete_last();
                    break;

                    case 3:
                    int p;
                    cout<<"Enter position of element to delete:"<<endl;
                    cin>>p;
                    l.delete_particular_Pos(p);
                    break;
                }
                break;

            case 3:
                l.reverse_list();
                break;
            default:
                cout<<"EXIT\n";
                exit(1);
        }
        l.display();
        cout<<"Do you want to continue('y' for YES/ 'n' for NO)..?\n";
        cin>>user_ch;
       
    }while(user_ch == 'y');
    return 0;
}
