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

Node* head = nullptr;
// Node* prev = nullptr;

void insert(int val){
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = newNode;
}

Node* solve(Node* head) {
    Node* curr = head;
    Node* prev = nullptr, *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main(){
    insert(10);
    insert(20);
    insert(30);

    Node* curr = head;
    curr = solve(curr);
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }

}