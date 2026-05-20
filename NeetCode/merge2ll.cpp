#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

using namespace std;
using ll = long long;
using ld = long double;

const ll MAX = LLONG_MAX;
const ll MIN = LLONG_MIN;

struct Node {
    int val;
    Node* next;
    Node* prev;
};

Node* solve(Node* head1, Node* head2) {
    Node* curr = nullptr;
    Node* headMerged = nullptr;
    
    // utk segment fault
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    while (head1 != nullptr && head2 != nullptr){
        if (head1->val < head2->val) {
            if (curr == nullptr) {
                curr = head1;
                headMerged = curr;
            } else {
                curr->next = head1;
                curr = head1;
            }
            head1 = head1->next;
        } else {
            if (curr == nullptr) {
                curr = head2;
                headMerged = curr;
            } else {
                curr->next = head2;
                curr = head2;
            }
            head2 = head2->next;
        }

    }
    
    if (head1 != nullptr) {
        curr->next = head1;
    }

    if (head2 != nullptr) {
        curr->next = head2;
    }

    return headMerged;
}

void insert(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = nullptr;
    if (head == nullptr){

        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr){
        curr = curr->next;
    }

    curr->next = newNode;
}

void print(Node* head){
    Node* curr = head;

    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }

    cout << endl;
}


int main(){
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    insert(head1, 2);
    insert(head1, 3);
    insert(head1, 5);

    insert(head2, 1);
    insert(head2, 4);
    insert(head2, 6);

    // print(head1);
    // print(head2);

    Node* merged = solve(head1, head2);
    print(merged);
}