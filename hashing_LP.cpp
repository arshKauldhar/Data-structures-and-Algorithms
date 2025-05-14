#include<iostream>
using namespace std;

#define tableSize 10
int lastindex =0;

class HashTable {
private:
    int arr[tableSize];

public:
    HashTable() {
        for(int i = 0; i < tableSize; i++) {
            arr[i] = -1;
        }
    }

    int hash(int key) {
        return key % tableSize;
    }

    void insert(int key) {
        int index = hash(key);
        if(lastindex != 10){
        while(arr[index] != -1) {
            index = (index + 1) % tableSize;
        }
        arr[index] = key;
        lastindex++;
        }else{
            cout<<"Hash table is full.\n";
        }
    }

    bool search(int key) {
        int index = hash(key);
        while(arr[index] != -1) {
            if(arr[index] == key) {
                return true;
            }
            index = (index + 1) % tableSize;
        }
        return false;
    }

    void display() {
        cout<<"The hash table formed is :\n";
        for(int i = 0; i < tableSize; i++) {
            if(arr[i] != -1) {
                cout << "Key: " << arr[i] << ", Index: " << i << endl;
            }
        }
    }
};

int main() {
    HashTable ht;
    char uc;
    int key,n;
    do{
    cout<<"1.--insert key--\n";
    cout<<"2.--search key--\n";
    cout<<"Enter your choice: ";
    cin>>n;
    switch(n){
        case 1:
            cout<<"\nEnter element to be inserted: ";
            cin>>key;
            ht.insert(key);
            ht.display();
            break;
        case 2:
            cout<<"\nEnter key you want to search: ";
            cin>>key;
            if(ht.search(key)){
                cout<<"Search successful\n";
            }else{
                cout<<"Element not found in the Hash table.\n";
            }
            break;
        default:
            cout<<"Exit";
            exit(0);
    }
    cout<<"\nDo you want to continue('y' for yes/ 'n' for No): ";
    cin>>uc;

    }while(uc == 'y');
    return 0;
}