#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void displayList(Node* head) {
    cout << "List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int countSize(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void insertAtHead(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if (tail == NULL)
        tail = head;
}

void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(Node*& head, Node*& tail, int val, int pos) {
    int size = countSize(head);
    if (pos < 1 || pos > size + 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1) {
        insertAtHead(head, tail, val);
        return;
    }
    if (pos == size + 1) {
        insertAtTail(head, tail, val);
        return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;


    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    displayList(head);


    insertAtHead(head, tail, 5);
    displayList(head);


    insertAtPosition(head, tail, 15, 3);
    displayList(head);


    return 0;
}
