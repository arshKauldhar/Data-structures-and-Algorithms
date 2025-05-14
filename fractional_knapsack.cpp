#include<iostream>
using namespace std;

int get_index(int k){
    int h ;
    h = k%13;
    return h;
}

int main(){
    int key;
    int arr[12];
    cout << "Enter a number : ";
    cin>>key;
    int r = get_index(key);
    if (arr[r] == NULL) {
        arr[r]= key;
    }else if(arr[r] != NULL){
        while(arr[r]!= NULL){
            r++;
        }
        arr[r]= key;
    }else{
        cout<<"not possible";
    }
    return 0;
}
