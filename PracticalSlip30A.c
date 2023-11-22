#include <stdio.h>
#include <stdlib.h>

// Structure for the circular queue
struct CircularQueue {
    int front, rear;
    int* array;
    int capacity;
};

// Function to initialize the circular queue
struct CircularQueue* initialize(int capacity) {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

// Function to insert an element into the circular queue
void insert(struct CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Insertion failed.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    printf("Inserted: %d\n", item);
}

// Function to delete an element from the circular queue
int delete(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Deletion failed.\n");
        return -1;
    }

    int deletedItem = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    printf("Deleted: %d\n", deletedItem);
    return deletedItem;
}

// Function to display the circular queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) {
        printf("%d ", queue->array[i]);
    }
    printf("%d\n", queue->array[i]);
}

int main() {
    struct CircularQueue* queue = initialize(5);

    insert(queue, 1);
    insert(queue, 2);
    insert(queue, 3);
    insert(queue, 4);

    display(queue);

    delete(queue);
    delete(queue);

    display(queue);

    insert(queue, 5);
    insert(queue, 6);

    display(queue);

    insert(queue, 7);

    return 0;
}
