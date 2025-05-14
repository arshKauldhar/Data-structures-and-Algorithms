// #include<iostream>
// using namespace std;
// #define Maxsize 20

// class Queue{
//     private:
//     int front, rear;
//     int queue[Maxsize];
//     int size;

//     public:
//     Queue(){
//         front = -1;
//         rear = -1;
//         size =0;
//     }

//     bool is_empty(){
//         return (front == -1 && rear == -1);
//     }

//     bool is_full(){
//         return ((rear+1)%Maxsize == front);
//     }

//     void enqueue(int x){
//         if(is_full()){
//             cout<<"----Queue overflow----\n";
//         }else if(is_empty()){
//             front =0, rear = 0;
//             queue[rear] = x;
//             size++;
//         }else{
//             rear = (rear+1)%Maxsize;
//             queue[rear] = x;
//             size++;
//         }
//     }

//     int dequeue(){
//         int item;   
//         if(is_empty()){
//             cout<<"----Queue underflow----\n";
//             return -1;
//         }
//         item = queue[front];
//         if(front == rear){
//             front = -1;
//             rear = -1;
//         }else{
//             front = (front + 1) % Maxsize;
//         }
//         size--;
//         return item;
//     }

//     void display_queue(){
//         if(is_empty()){
//             cout<<"Queue is empty\n";
//             return;
//         }
//         cout<<"Queue is: ";
//         int i;
//         i = front;
//         if(i == rear){
//         cout<<queue[i]<<"";
//         }else{
//             while(i!=rear){
//                 cout<<queue[i]<<" ";
//                 if(i>=Maxsize-1)
//                 i=0;
//                 else
//                 i++;
//             }
//             cout<<queue[i]<<" ";
//         }
//     }

//     int Sum(){
//         int sum = 0;
//         int a;
//         for(int i =0; i<size; i++){
//             a = dequeue();
//             sum += a;
//             enqueue(a);
//         }
//         return sum;
//     }
// };

// int main(){
//     Queue q1;
//     cout<<"Enter values: ";
//     for(int i=0; i <= Maxsize-1; i++){
//         cin>>i;
//         cout<<" ";
//         if(i == -10000){
//             break;
//         }
//         q1.enqueue(i);
//     }
//     cout<<"Sum of elements is : "<<q1.Sum()<<"\n";
//     q1.display_queue();
//     return 0;
// }

#include<iostream>
using namespace std;
#define capacity 10

class Circular_Queue{
    private:
    int arr[capacity];
    int front, rear, size;

    public:
    Circular_Queue(){
        front = -1;
        rear = -1;
        size =0;
    }

    void enqueue(int x){
        if((rear+1)%capacity==front){
            cout << "\nOverflow\n";
        }else if((front == -1) && (rear == -1)){
            front = 0, rear = 0;
            arr[rear] = x;
            size++;
        }else{
            rear = (rear + 1 ) % capacity;
            arr[rear]=x;
            size++;
        }
    }

    int dequeue(){
        int item;
        if(front == -1 && rear == -1 ){
            cout << "\nUnderflow\n";
            return -1;
        }
        item = arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
            size--;
        }else{
            front=(front+1)%capacity;
            size--;
        }
        return item;
    }

    void Print_queue(){
        if((front == -1) && (rear == -1)){
            cout<<"Queue is empty";
            return;
        }
        int tempfront = front;
        if(tempfront == rear){
            cout<<arr[tempfront]<<" ";
        }else{
        while(tempfront != rear){
            cout<<arr[tempfront]<<" ";
            if(tempfront >= capacity-1){
                tempfront=0;
            }else{
                tempfront++;
            }
        }
        cout<<arr[tempfront]<<" ";
        }
    }

    int sum(){
        int s = 0;
        for(int i = 0 ;i<size;i++){
            int ele = dequeue();
            s+=ele;
            enqueue(ele);
        }
        return s;
    }
};

int main(){
    Circular_Queue q;
    int num;
    cout<<"Enter values(stop when -10000 comes): ";
    for(int i=0; i<capacity -1; i++){
        cin>>num;
        if(num == -10000){
            break;
        }
        q.enqueue(num);
    }
    cout<<"\nSum of elements in queue: "<<q.sum()<<endl;
    q.Print_queue();
    return 0;
}