#include <bits/stdc++.h>

using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
    
    SinglyLinkedListNode(int val) : data(val), next(nullptr) {}
};

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    if (llist == NULL || llist ->next == NULL) 
        return llist; 
  
    SinglyLinkedListNode* rest = reverse(llist->next); 
    llist->next->next = llist; 
    llist->next = NULL; 
  
    return rest; 
}
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
    int tests;
    cin >> tests;

    while (tests--) {
        SinglyLinkedListNode* list = nullptr;
        int llist_count;
        cin >> llist_count;

        for (int i = 0; i < llist_count; i++) {
            int data;
            cin >> data;
            insertNode(list, data);
        }
        list = reverse(list);
        cout << "Reversed list:" << endl;
        printLinkedList(list);
    }

    return 0;
}