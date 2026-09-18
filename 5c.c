#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert a new node at the beginning
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a new node at the end
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to delete a node with a given value
void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
    {
        printf("The doubly linked list is empty.\n");
        return;
    }

    struct Node *current = *head;

    while (current != NULL)
    {
        if (current->data == key)
        {
            // If node is not the first node
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                // Node is the first node
                *head = current->next;
            }

            // If node is not the last node
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }

            free(current);

            printf("Node with data %d deleted from the doubly linked list.\n", key);
            return;
        }

        current = current->next;
    }

    printf("Node with data %d not found in the doubly linked list.\n", key);
}

// Function to display the elements of the doubly linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("The doubly linked list is empty.\n");
        return;
    }

    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;

    int choice, data, key;

    while (1)
    {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete a node\n");
        printf("4. Display\n");
        printf("5. Quit\n");

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
                printf("Enter data to delete: ");
                scanf("%d", &key);

                deleteNode(&head, key);
                break;

            case 4:
                printf("Doubly Linked List:\n");
                display(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}