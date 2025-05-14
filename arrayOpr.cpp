#include<iostream>
#include<conio.h>
using namespace std;
bool isEmpty(int);
bool noElement(int);
int arr[10],lastIndex;

void indexInsert(){
    int num,index;
    cout<<"enter index : ";
    cin>>index;
   
    if (isEmpty(lastIndex+1))
    {
        if (index <= lastIndex && index>0 ){
            cout<<"enter element: ";
            cin>>num;                                                                   
            for(int i=lastIndex; i>= index; i--)
            {    
                arr[i] = arr[i-1];
            }
            lastIndex++;
            arr[index]=num;
        }
        else{
            cout<<"Please enter a valid index\n";
        }
    }
    else{
    cout<<"Array is full"<<endl;
    }
}

void beforeIndexInsert(){
    int num,index;
    cout<<"enter index before which you want to insert an element : ";
    cin>>index;
    if (isEmpty(lastIndex+1))
    {
        if (index <= lastIndex && index>0 ){
        cout<<"enter element: ";
        cin>>num;
        for(int i=lastIndex; i>=index; i--){
        arr[i] = arr[i-1];
        }
        arr[index-1]=num;
        lastIndex++;
        }else{
            cout<<"Please enter a valid index"<<endl;
        }
    }
    else{
    cout<<"Array is full"<<endl;
    }
}

void afterIndexInsert(){
    int num,index;
    cout<<"enter index after which you want to insert : ";
    cin>>index;
    if (isEmpty(lastIndex+1))
    {
        if (index < lastIndex && index>=0 ){
        cout<<"enter element: ";
        cin>>num;
        for(int i=lastIndex; i>index; i--)
        arr[i] = arr[i-1];
        lastIndex++;
        arr[index+1]=num;
    } else{
            cout<<"Please enter a valid index";
        }
    }else{
    cout<<"Array is full"<<endl;
    }
}

void insertBeforeValue(){
    int value,i,j,num,flag=0;
    cout<<"Enter the value you want to find: ";
    cin>>value;
    if (isEmpty(lastIndex+1)){
        for(i=0; i<lastIndex; i++){
        if(arr[i]== value){
            cout<<"element found at index "<<i<<endl<<"Enter new element you want to insert before "<<value <<": ";
            cin>>num;
            flag = 1;
            for(j = lastIndex; j>=i; j--){
            arr[j]= arr[j-1];
            }
            arr[i] = num;
            lastIndex++;
            break;
        }
    }
    if(flag == 0){
        cout<<"element not found"<<endl<<"enter a valid number";
    }
    }else{
    cout<<"over flow"<<endl;
    }
}

void insertAfterValue(){
    int value,i,j,num,flag=0;
    cout<<"Enter the value you want to find: ";
    cin>>value;
    if (isEmpty(lastIndex+1)){
        for(int i = 0; i<lastIndex; i++){
        if(arr[i]==value){
            cout<<"value found at index "<<i<<endl<<"enter no. you want to insert after" <<value <<": ";
            cin>>num;
            flag = 1;
            for( j=lastIndex; j>i; j--){
                arr[j] = arr[j-1];
            }
            arr[i+1]=num;
            lastIndex++;
            break;
        }
    }if(flag == 0){
        cout<<"value not found"<<endl<<"please enter a valid value"<<endl;
    }
    }else{
    cout<<"over flow"<<endl;
    }
}

void indexDeletion(){
    if (!noElement(lastIndex)){
        int i,index;
        cout<<"Enter index from which you want to delete an element: ";
        cin>>index;
        if(index < lastIndex && index>=0){
        for( i=index; i<lastIndex-1; i++){
            arr[i]= arr[i+1];
        }
        lastIndex -= 1;
        }else{
            cout<<"Please enter a valid index";
        }
    }else {
    cout<<"under flow"<<endl;
    }
}

void DeleteByIndex(){
    if(!noElement(lastIndex)){
        int i,c,index;
        cout<<"Enter index After or Before you want to delete an element: ";
        cin>>index;
        if(index < lastIndex && index >=0){
        cout<<"Press 1 to delete an element before index "<<ends<<index<<endl;
        cout<<"press 2 to delete an element after index "<<ends<<index<<endl;
        cout<<"press any key for exit"<<endl;
        cin>>c;
        switch(c){
            case 1:
                if(index == 0){
                    cout<<"there is no element to delete before index"<<ends<<index;
                }else{
                for(i = index-1;i<lastIndex;i++){
                    arr[i]=arr[i+1];
                }
                lastIndex--;
                }
                break;
            case 2:
                if(index == lastIndex-1){
                    cout<<"There is no value to delete after index"<<" "<<index;
                }else{
                for(i = index+1;i<lastIndex;i++){
                    arr[i]=arr[i+1];
                }
                lastIndex--;
                }
                break;
            default:
                cout<<"exit";   
        }
        }else{
            cout<<"Please enter a valid index";
        }
    }else{
    cout<<"underflow"<<endl;
    }
}

void deleteByValue(){
    int i,c,value,index=0;
    if (!noElement(lastIndex)){
        cout<<"Enter value after or before which you want to delete an element: ";
        cin>>value;
        for(i =0;i<lastIndex;i++){
            if(arr[i]==value){
                index = i;
                cout<<"value found at index "<<i<<endl;
                break;
            }
        }if (arr[index] != value){
            cout<<"Value not found";
        }
       cout<<"Press 1 to delete an element before "<<value<<endl;
       cout<<"press 2 to delete an element after "<<value<<endl;
       cout<<"press any key for exit"<<endl;
       cin>>c;
        switch(c){
            case 1:
                if(index ==  0){
                    cout<<"there is no element to delete before "<<value<<endl;
                }else{
                for(i = index-1;i<lastIndex;i++){
                    arr[i]=arr[i+1];
                }
                lastIndex--;
                }
                break;
            case 2:
                if(index == lastIndex-1){
                    cout<<"there is no element to delete after "<<value<<endl;
                }else{
                for(i = index+1;i<lastIndex;i++){
                    arr[i]=arr[i+1];
                }
                lastIndex--;
                }
                break;
            default:
                cout<<"Exit";   
        }
    }else{
    cout<<"underflow"<<endl;
    }
}

bool isEmpty(int lastIndex){
    return(lastIndex<10);
}

bool noElement(int lastIndex){
    return (lastIndex<0) ;
}

int main()
{
    int c;
    char uc;
    cout<<"********Elements insertion and deletion at, before and after index and also by value********"<<endl;
    cout<<"ENTER NUMBER OF ELEMENTS YOU WANT IN AN ARRAY: "<<endl;
    cin>>lastIndex;
    if(lastIndex > (sizeof(arr)/sizeof(arr[0]))){
        cout<<"Last index can't be more than"<<10<<endl;
        return 1;
    }else{
    cout<<"ENTER ELEMENTS OF AN ARRAY: "<<endl;
    for(int i=0; i<lastIndex; i++){
    cin>>arr[i]; 
    }
    }
    do
    {
        cout<<"Press the following number according to your desired operation"<<endl;
        cout<<"Press 1 : to insert an element at user index"<<endl;
        cout<<"press 2 : to insert an element before the user index"<<endl;
        cout<<"press 3 : to insert an element after the after index"<<endl;
        cout<<"press 4 : to insert an element before any specific value in an array"<<endl;
        cout<<"press 5 : to insert an element after any specific value in an array"<<endl;
        cout<<"press 6 : to Delete an element from an array from user index"<<endl;
        cout<<"press 7 : to Delete an element before or after user index"<<endl;
        cout<<"press 8 : to Delete an element before or after the user value"<<endl;
        cout<<"***Enter your choice: "<<endl;
        cin>>c;
        switch(c){
            case 1:
                indexInsert();
                break;
            case 2:
                beforeIndexInsert();
                break;
            case 3:
                afterIndexInsert();
                break;
            case 4:
                insertBeforeValue();
                break;
            case 5:
                insertAfterValue();
                break;
            case 6:
                indexDeletion();
                break;
            case 7: 
                DeleteByIndex();
                break;
            case 8:
                deleteByValue();
                break;
            default:
                cout<<"Exit"<<endl;
                exit(1);
        }
        cout<<"The new array formed is : "<<endl;
        for(int i=0; i<lastIndex; i++){
        cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"\nDo you want to perform again..?(y/n)\n";
        cin>>uc;
    }while(uc == 'y');
    
    return 0;
}

