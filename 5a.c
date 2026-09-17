#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    // If list is empty
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

// Function to insert a new node at a specific position
void insertAtPosition(struct Node **head, int data, int position)
{
    if (position < 0)
    {
        printf("Invalid position. Position must be non-negative.\n");
        return;
    }

    // Insert at beginning
    if (position == 0)
    {
        insertAtBeginning(head, data);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    struct Node *current = *head;
    int currentPosition = 0;

    while (current != NULL && currentPosition < position - 1)
    {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL)
    {
        printf("Invalid position. Position exceeds the length of the list.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The list is already empty.\n");
        return;
    }

    struct Node *temp = *head;

    *head = (*head)->next;

    free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The list is already empty.\n");
        return;
    }

    // If there is only one node
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *current = *head;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("The list is already empty.\n");
        return;
    }

    if (position < 0)
    {
        printf("Invalid position. Position must be non-negative.\n");
        return;
    }

    // Delete first node
    if (position == 0)
    {
        deleteAtBeginning(head);
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;

    int currentPosition = 0;

    while (current != NULL && currentPosition < position)
    {
        prev = current;
        current = current->next;
        currentPosition++;
    }

    if (current == NULL)
    {
        printf("Invalid position. Position exceeds the length of the list.\n");
        return;
    }

    prev->next = current->next;

    free(current);
}

// Function to display the elements of the list
void display(struct Node *head)
{
    struct Node *current = head;

    if (current == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;

    int choice, data, position;

    while (1)
    {
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at a specific position\n");
        printf("7. Display\n");
        printf("8. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);

                insertAtBeginning(&head, data);
                break;

            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);

                insertAtEnd(&head, data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);

                printf("Enter position to insert at: ");
                scanf("%d", &position);

                insertAtPosition(&head, data, position);
                break;

            case 4:
                deleteAtBeginning(&head);
                break;

            case 5:
                deleteAtEnd(&head);
                break;

            case 6:
                printf("Enter position to delete at: ");
                scanf("%d", &position);

                deleteAtPosition(&head, position);
                break;

            case 7:
                display(head);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}