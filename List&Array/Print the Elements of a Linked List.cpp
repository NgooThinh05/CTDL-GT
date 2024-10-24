#include <bits/stdc++.h>

using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
    
    SinglyLinkedListNode(int val) : data(val), next(nullptr) {}
};

void printLinkedList(SinglyLinkedListNode* head) {
    while(head != NULL){
        cout << head ->data << endl;
        head = head -> next;
    }

}

void insertNode(SinglyLinkedListNode*& head, int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        SinglyLinkedListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int main() {
    int n;
    cin >> n;
    SinglyLinkedListNode* list = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(list, data);
    }
    printLinkedList(list);
    return 0;
}