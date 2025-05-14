#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){ 
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class doubly__ll{
    private:
       Node *head;
    public:
    doubly__ll(){
        head = nullptr;
    }
    void insert_at_first(int data){
        Node *n = new Node(data);
        n->next = head;
        if(head != nullptr){
        head->prev = n;
        }
        head = n;            
    }
    void insert_at_last(int data){
        if(head == nullptr)
        {
            insert_at_first(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *temp = head;
        while (temp->next != nullptr){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insert_at_position(int data,int pos){
        Node* newNode = new Node(data);
        if (pos <= 0) {
            cout << "Invalid position.\n ";
            return;
        }
        if (!head && pos == 1) {
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }
        if (temp) {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        } else {
            cout << "Invalid position. ";
        }
    }  
    void display(){
        Node *temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" <->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void delete_head(){
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    void delete_position(int pos){
        if (!head) {
            cout << "List is empty. Deletion not possible.";
        }
        if (pos <= 0) {
            cout << "Invalid position. ";
            return;
        }
        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = NULL;
            }
            delete temp;    
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos && temp; ++i) {
            temp = temp->next;
        }
        if (temp) {
            temp->prev->next = temp->next;
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            delete temp;
        } else {
            cout << "Invalid position.\n ";
        }
    }
};

int main(){
    doubly__ll d;
    char uc;
    int n,val,pos;
    do{
        cout<<"1. -- insert at first--\n";
        cout<<"2. -- insert at last--\n";
        cout<<"3. -- insert at particular postion--\n";
        cout<<"4. -- delete head node--\n";
        cout<<"5. -- delete from particular position--\n";
        cout<<"Enter your choice: \n";
        cin>>n;
        switch(n){
            case 1:
            cout<<"Enter value to insert at first: ";
            cin>>val;
            d.insert_at_first(val);
            break;

            case 2:
            cout<<"Enter value to insert at last: ";
            cin>>val;
            d.insert_at_last(val);
            break;

            case 3:
            cout<<"Enter value & position where you want to insert node: ";
            cin>>val>>pos;
            d.insert_at_position(val,pos);
            break;

            case 4:
            d.delete_head();
            break;

            case 5: 
            cout<<"Enter position from where you want to delete node: ";
            cin>>pos;
            d.delete_position(pos);
            break;

            default:
            cout<<"--EXIT--\n";
        }
        d.display();
        cout<<"\nDo you want to continue('y' for yes/ 'n' for No): ";
        cin>>uc;
    }while(uc == 'y');
    return 0;
}