#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList(){
        head = NULL;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;

        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtPosition(int data,int position) {
        if(position <= 0) {
            cout << "Position should be greater than 0\n";
        }

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            int i = 1;
            while(i < position - 1 && temp->next != head) {
                temp = temp->next;
                i++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFirst() {
        if(head == NULL) {
            cout << "List is empty\n";
        }
        Node* temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
    }

    void deleteLast() {
        if(head == NULL) {
            cout << "List is empty\n";
        }
        Node* temp = head;
        Node* prev = NULL;
        while(temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }

    void deleteFromPosition(int position) {
        if(head == NULL || position <= 0) {
            cout << "Invalid operation\n";
            return;
        }
        if(position == 1){
            deleteFirst();
        }
        Node* temp = head;
        Node* prev = NULL;
        int i = 1;
        while(i < position && temp->next != head) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        delete temp;
    }

    void display() {
        if(head == NULL) {
            cout << "List is empty\n";
        }
        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while(temp != head);
        cout <<"HEAD"<< endl;
    }
};
int main() {
    CircularLinkedList cll;
    int n,pos,val;
    char uc;
    do{
        cout<<"1. -- insert at first--\n";
        cout<<"2. -- insert at last--\n";
        cout<<"3. -- insert at particular postion--\n";
        cout<<"4. -- delete head node--\n";
        cout<<"5. -- delete last--\n";
        cout<<"6. -- delete from particular position--\n";
        cout<<"Enter your choice: \n";
        cin>>n;
        switch(n){
            case 1:
            cout<<"Enter value to insert at first: ";
            cin>>val;
            cll.insertAtBeginning(val);
            break;

            case 2:
            cout<<"Enter value to insert at last: ";
            cin>>val;
            cll.insertAtEnd(val);
            break;

            case 3:
            cout<<"Enter value & position where you want to insert node: ";
            cin>>val>>pos;
            cll.insertAtPosition(val,pos);
            break;

            case 4:
            cll.deleteFirst();
            break;

            case 5:
            cll.deleteLast();
            break;

            case 6: 
            cout<<"Enter position from where you want to delete node: ";
            cin>>pos;
            cll.deleteFromPosition(pos);
            break;

            default:
            cout<<"--EXIT--\n";
        }
        cll.display();

        cout<<"\nDo you want to continue('y' for yes/ 'n' for No): ";
        cin>>uc;

    }while(uc == 'y');
    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value)
	{
		data=value;
	    next=NULL;
	} 
};

class CircularLinkedList
 {
private:
    Node* head;

public:
    CircularLinkedList()
	 {
    	head=NULL;
     }

    void insertAtBeginning(int value) 
	{
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Make it circular
            head = newNode; // Update head to the new node
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            head->next = head; // Make it circular
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Make it circular
        }
    }

    void insertAtNthPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position. Please enter a position greater than or equal to 1." << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (!head) {
            if (position == 1) {
                head = newNode;
                head->next = head; // Make it circular
            } else {
                cout << "Invalid position. List is empty." << endl;
            }
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp->next != head; ++i) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty. Deletion not possible." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        if (temp == head) {
            delete head;
            head = NULL;
        } else {
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty. Deletion not possible." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == head) {
            delete head;
            head = NULL;
        } else {
            prev->next = head;
            delete temp;
        }
    }

    void deleteAtNthPosition(int position) {
        if (!head) {
            cout << "List is empty. Deletion not possible." << endl;
            return;
        }

        if (position == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        for (int i = 1; i < position && temp->next != head; ++i) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == head) {
            cout << "Invalid position for deletion." << endl;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList myList;
    int choice, value, position;

    do {
        cout << "\n1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Nth Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Nth Position\n";
        cout << "7. Display Circular Linked List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert at the beginning: ";
                cin >> value;
                myList.insertAtBeginning(value);
                cout << "Circular Linked List: ";
                myList.display();
                break;
            case 2:
                cout << "Enter the value to insert at the end: ";
                cin >> value;
                myList.insertAtEnd(value);
                cout << "Circular Linked List: ";
                myList.display();
                break;
            case 3:
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Enter the position: ";
                cin >> position;
                myList.insertAtNthPosition(value, position);
                cout << "Circular Linked List: ";
                myList.display();
                break;
            case 4:
                myList.deleteAtBeginning();
                cout << "Deleted at the beginning." << endl;
                cout << "Circular Linked List: ";
                myList.display();
                break;
            case 5:
                myList.deleteAtEnd();
                cout << "Deleted at the end." << endl;
                cout << "Circular Linked List: ";
                myList.display();
                break;
            case 6:
                cout << "Enter the position to delete: ";
                cin >> position;
                myList.deleteAtNthPosition(position);
                cout << "Circular Linked List: ";
                myList.display();
                break;
            case 7:
                cout << "Circular Linked List: ";
                myList.display();
                break;
            case 8:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 8);

    return 0;
}