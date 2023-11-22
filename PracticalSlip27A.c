#include <stdio.h>

#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

// Function to initialize the circular queue
void Initialize() {
    front = rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to check if the circular queue is full
int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

// Function to insert an element into the circular queue
void insert(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot insert %d.\n", data);
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        circularQueue[rear] = data;
        printf("%d inserted into the queue.\n", data);
    }
}

// Function to delete an element from the circular queue
int delete() {
    int deletedItem;
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete.\n");
        return -1;
    } else if (front == rear) {
        deletedItem = circularQueue[front];
        front = rear = -1;
    } else {
        deletedItem = circularQueue[front];
        front = (front + 1) % MAX_SIZE;
    }
    return deletedItem;
}

// Function to display the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        printf("Circular Queue: ");
        while (1) {
            printf("%d ", circularQueue[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int main() {
    Initialize();
    
    insert(1);
    insert(2);
    insert(3);
    display();
    
    int deleted = delete();
    if (deleted != -1) {
        printf("Deleted: %d\n", deleted);
    }
    
    insert(4);
    insert(5);
    display();
    
    insert(6); // Should display "Queue is full."
    
    return 0;
}
