#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node of the list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the start of the list
void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node in between the list
void insertInBetween(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode(data);
    }
}

// Function to display the list
void displayList(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int num;
    char choice;
    struct Node* head = NULL; // Initialize an empty list

    // Insert initial numbers into the list
    printf("Enter initial numbers into the list (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        insertAtEnd(&head, num);
    }

    // Display the initial list
    displayList(head);

    // Ask the user where to insert the number
    printf("Where do you want to insert the number? (S for start, E for end, B for in between): ");
    scanf(" %c", &choice);
    printf("Enter a number to insert: ");
    scanf("%d", &num);

    // Insert the number based on user choice
    switch (choice) {
        case 'S':
        case 's':
            insertAtStart(&head, num);
            break;
        case 'E':
        case 'e':
            insertAtEnd(&head, num);
            break;
        case 'B':
        case 'b':
            {
                int position;
                printf("Enter the position after which you want to insert the number: ");
                scanf("%d", &position);
                struct Node* temp = head;
                for (int i = 1; i < position; ++i) {
                    if (temp == NULL) {
                        printf("Invalid position.\n");
                        return 1;
                    }
                    temp = temp->next;
                }
                insertInBetween(temp, num);
            }
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // Display the updated list
    printf("Updated ");
    displayList(head);

    // Free dynamically allocated memory to prevent memory leaks
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

