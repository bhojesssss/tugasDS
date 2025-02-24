#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;          // Stores data
    struct Node* next; // Pointer to the next node
};

// Function to insert at the beginning
void insertAtBeginning(struct Node** head, int value)
{
    // Step 1: Create new node and allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Step 2: Assign value to the new node   
    newNode->data = value; 

    // Step 3: Link new node to current head
    newNode->next = *head; 

    // Step 4: Update head to new node
    *head = newNode;       
}

// Function to insert at the end
void insertAtEnd(struct Node** head, int value)
{
    // Step 1: Create new node and allocate memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Step 2: Assign value to the new node
    newNode->data = value; 

    // Step 3: New node will point to null because it will be the last node
    newNode->next = NULL;  

    // Step 4: If list is empty (head is Null) , new node becomes head
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }

    // Step 5: Traverse to last node
    struct Node* temp = *head; 
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Step 6: Link last node to new node
    temp->next = newNode; 
}

// Function to insert at a specific position
void insertAtPosition(struct Node** head, int value, int position)
{
    // Step 1: If inserting at the beginning, call InsertAtBeginning function
    if (position == 0) 
    {
        insertAtBeginning(head, value);
        return;
    }

    // Step 2: Create new node and allocate memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 

    // Step 3: Assign value to the new node
    newNode->data = value;

    // Step 4: Traverse to (position-1)th node
    struct Node* temp = *head; 
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    // Step 5: Check if position is out of bounds
    if (temp == NULL) 
    {
        printf("Position out of bounds!\n");
        return;
    }

    // Step 6: Link new node to the next node
    newNode->next = temp->next;
    
    // Step 7: Link previous node to new node
    temp->next = newNode; 
}

// Function to delete a node by value
void deleteNode(struct Node** head, int value)
{
    // Step 1: If list is empty
    if (*head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }

    // Step 2: If head node is the target
    if ((*head)->data == value) 
    {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Step 3: Find node before the target
    struct Node* temp = *head; 
    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    // Step 4: If value not found
    if (temp->next == NULL) 
    {
        printf("Value not found!\n");
        return;
    }

    // Step 5: Unlink the terget node
    struct Node* toDelete = temp->next; 
    temp->next = temp->next->next;

    // Step 6: free the target node
    free(toDelete);
}

// Function to search for an element
int search(struct Node* head, int value)
{
    // Step 1: Start from head
    struct Node* temp = head; 

    // Step 2: Traverse list
    while (temp != NULL) 
    {
        // Step 3: If value found
        if (temp->data == value) 
        {
            return 1;
        }
        temp = temp->next;
    }

    // Step 4: If not found, return false (0)
    return 0; 
}

// Function to display the linked list
void display(struct Node* head)
{
    // Step 1: Start from head
    struct Node* temp = head; 

    // Step 2: Traverse and print each node
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    // Step 3: Print end of list
    printf("NULL\n"); 
}

int main()
{
    //Initialize the empty linked list
    struct Node* head = NULL; 

    insertAtEnd(&head, 10);   // Insert 10 at the end
    insertAtEnd(&head, 20);   // Insert 20 at the end
    insertAtEnd(&head, 30);   // Insert 30 at the end
    display(head); // Output: 10 -> 20 -> 30 -> NULL

    insertAtBeginning(&head, 5);  // Insert 5 at the beginning
    display(head); // Output: 5 -> 10 -> 20 -> 30 -> NULL

    insertAtPosition(&head, 15, 2); // Insert 15 at index 2
    display(head); // Output: 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    deleteNode(&head, 10); // Delete node with value 10
    display(head); // Output: 5 -> 15 -> 20 -> 30 -> NULL

    //Search for the node that containt the value 20
    if (search(&head,20))
    {
        //If found
        printf("Found\n");
    }
    else
    {
        //If not found
        printf("Not found!\n");
    }
    
    //NOTES
    //-> Use struct Node** to pass by referance to modify the actuall linked list then pass the address to the function using &head
    //-> Use malloc() to allocate memory and free() to realease memory and avoid memory leaks
}
