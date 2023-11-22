#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node.
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data.
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list.
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the end of the linked list.
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete a node from a specific position.
struct Node* deleteNode(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }
    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    int count = 0;
    while (count < position - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }
    if (current->next == NULL) {
        printf("Invalid position. Cannot delete.\n");
        return head;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Create linked list\n");
        printf("2. Display linked list\n");
        printf("3. Insert node at the end\n");
        printf("4. Delete node from specific position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create linked list
                head = NULL; // Reset the list
                printf("Linked list created.\n");
                break;
            case 2:
                // Display linked list
                displayList(head);
                break;
            case 3:
                // Insert node at the end
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                printf("Node inserted at the end.\n");
                break;
            case 4:
                // Delete node from specific position
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteNode(head, position);
                printf("Node deleted from position %d.\n", position);
                break;
            case 5:
                // Exit
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
