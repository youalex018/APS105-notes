typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node* head;
} LinkedList;
  
// Push to the front of the linked list
void pushfront(LinkedList* ll, int data) {
    Node* newNode = createNode(data);
    newNode->next = ll->head;
    ll->head = newNode;
}