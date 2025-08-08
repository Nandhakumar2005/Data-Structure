#include<stdio.h>
int size = 0,front = 0,rear = -1,capacity;
void Enqueue(int circularQ[],int value) {
    if (size == capacity){return;}
    else{
        rear=(front+size)%capacity;
        circularQ[rear] = value;
        size++;
    }
}
void Dequeue() {
    if (size == 0){return;}
    else if(front == rear){
        front = 0;
        rear = -1;
    }else{
        front = (front + 1)%capacity;
    }
    size--;
}
void Display(int circularQ[]) {
    printf("Circular Queue:");
    if (front<=rear){
        for(int i=front;i<=rear;i++){
            printf("%d\t",circularQ[i]);
        }
    }
    else{
        for(int i = front;i<=capacity-1;i++){
            printf("%d\t",circularQ[i]);
        }
        for(int i = 0;i<=rear;i++){
            printf("%d\t",circularQ[i]);
        }
    }
}
int main(){
    printf("\nEnter the capacity of queue:");
    scanf("%d",&capacity);
    printf("\n");
    int circularQ[capacity];

while(1){
      int value,choice;
      printf("-------------Main menu-------------\n");
      printf("\n1.Enqueue\t2.Dequeue\t3.Exit\n");
      printf("\nEnter your choice:\n");
      scanf("%d",&choice);
      
      switch(choice){
          case 1:if(size==capacity){
              printf("Queue is full!(overflow)\n");
          }else{
              printf("\n Enter the element:\n");
              scanf("%d",&value);
              Enqueue(circularQ,value);
              Display(circularQ);
              printf("\n");
          }
          break;
          case 2:if(size==0){
              printf("Queue empty!\n");
          }else{
              Dequeue();
              Display(circularQ);
              printf("\n");
          }
          break;
          case 3:return 0;
          default:printf("invalid choice!\n");
        
        }
    
    }return 0;
}
