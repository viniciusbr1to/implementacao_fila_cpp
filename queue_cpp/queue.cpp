#include <iostream>
#define queue_size 5
using namespace std;


struct int_queue{
       int queue[queue_size];
       int front, rear;
       int count;


int_queue(){
front = 0;
rear = -1;
count = 0;
}

bool is_empty(){
return count == 0;
}

bool is_full(){
return count == queue_size;
}

int enqueue(int value){
if(is_full()){
   return 1;
}

rear = (rear + 1) % queue_size;
queue[rear] = value;
count++;
return 0;
}

int dequeue(){
if(is_empty()){
   return 1;
}

    int value = queue[front];

front = (front + 1) % queue_size;
count--;
return value;
}

int peek(){
return queue[front];
}

int print(){
if(is_empty()){
   return 1;
}

cout << "| ";
for(int i = front; i <= rear; i++){
    cout << queue[i] << " | ";
}
cout << endl;
return 0;
}
};

void menu(){
cout << "-----------------------------------------------------------------\n";
cout << "|1. Enqueue             |5. Search           |9. Leave          |\n";
cout << "-----------------------------------------------------------------\n";
cout << "|2. Dequeue             |6. Clear            |\n";
cout << "-------------------------------------------\n";
cout << "|3. Peek                |7. Reverse          |\n";
cout << "-------------------------------------------\n";
cout << "|4. Size                |8. Print            |\n";
cout << "-------------------------------------------\n";
}
void clear(){
system("cls");
}
void pause(){
system("pause");
}


int main(){
    int_queue q;
    int option, value;


do{
menu();
cin >> option;
clear();


switch(option){
case 1:
cout << "Enter a number: ";
cin >> value;
clear();

if(q.enqueue(value) == 1){
   cout << "The queue is full.\n";
} else
   cout << "Number " << value << " entered successfully.\n";

break; 

case 2:
if(q.is_empty() == 1){
   cout << "The queue is empty.\n";
} else
   cout << "Number " << q.dequeue() << " removed successfully.\n";
   
break;

case 3:
if(q.is_empty() == 1){
   cout << "The queue is empty.\n";
} else
   cout << "The first number in the queue is " << q.peek() << ".\n";

break;

case 4:

break;

case 5:

break;

case 6:

break;

case 7:

break;

case 8:
if(q.print() == 1){
   cout << "The queue is empty.\n";
}

break;

default:
if(option != 9){
   cout << "Invalid option\n";
}

break;
}


pause();
clear();
} while(option != 9);


cout << "Shutting down the system...";
return 0;
}