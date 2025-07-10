#include<iostream>
using namespace std;

// Node class represents each element (node) in the linked list
class Node {
public:
    int data;      // Data stored in the node
    Node* next;    // Pointer to the next node

    // Constructor to initialize a node
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor to show which node is being deleted (for debugging)
    ~Node() {
        cout << "Node with value " << data << " deleted.\n";
    }
};

// Function to print the entire linked list
void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert a new node at the beginning (head) of the list
void InsertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Insert a new node at the end (tail) of the list
void InsertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// Insert a new node at a specific position in the list
void InsertAtMid(Node* &head, Node* &tail, int pos, int d) {
    // Insert at beginning
    if (pos == 1) {
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse to the node before the position
    while (count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    // If position is beyond list, insert at tail
    if (temp == NULL || temp->next == NULL) {
        InsertAtTail(tail, d);
        return;
    }

    // Insert new node
    Node* nodeInsert = new Node(d);
    nodeInsert->next = temp->next;
    temp->next = nodeInsert;
}

// Delete the first node (head) of the list
void DeleteHead(Node* &head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete the last node (tail) of the list
void DeleteTail(Node* &head, Node* &tail) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    // If only one node exists
    if (head->next == NULL) {
        delete head;
        head = tail = NULL;
        return;
    }

    // Traverse to the second last node
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;
    temp->next = NULL;
    tail = temp;
}

// Delete a node from a specific position
void DeleteAtPosition(Node* &head, Node* &tail, int pos) {
    // If position is first
    if (pos == 1) {
        DeleteHead(head);
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int count = 1;

    // Traverse to the target position
    while (count < pos && curr != NULL) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    // If position is invalid
    if (curr == NULL) {
        cout << "Position is out of range.\n";
        return;
    }

    // If deleting tail
    if (curr == tail) {
        DeleteTail(head, tail);
        return;
    }

    // Delete node
    prev->next = curr->next;
    delete curr;
}

// Delete the entire linked list
void DeleteEntireList(Node* &head, Node* &tail) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    cout << "Entire list deleted.\n";
}

// Main function to run the menu-driven program
int main() {
    // Start with one node with value 10
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    int choice, value, position;

    // Menu-driven loop
    do {
        cout << "\n\nMenu:\n";
        cout << "1 = Print Linked List\n";
        cout << "2 = Insert At Head\n";
        cout << "3 = Insert At Tail\n";
        cout << "4 = Insert At Position\n";
        cout << "5 = Delete Head\n";
        cout << "6 = Delete Tail\n";
        cout << "7 = Delete At Position\n";
        cout << "8 = Delete Entire List\n";
        cout << "9 = Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform action based on user choice
        switch (choice) {
            case 1:
                print(head);
                break;

            case 2:
                cout << "Enter value to insert at head: ";
                cin >> value;
                InsertAtHead(head, value);
                break;

            case 3:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                InsertAtTail(tail, value);
                break;

            case 4:
                cout << "Enter position to insert at: ";
                cin >> position;
                cout << "Enter value to insert: ";
                cin >> value;
                InsertAtMid(head, tail, position, value);
                break;

            case 5:
                DeleteHead(head);
                break;

            case 6:
                DeleteTail(head, tail);
                break;

            case 7:
                cout << "Enter position to delete: ";
                cin >> position;
                DeleteAtPosition(head, tail, position);
                break;

            case 8:
                DeleteEntireList(head, tail);
                break;

            case 9:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Please enter a valid choice!\n";
        }
    } while (choice != 9);

    return 0;
}
