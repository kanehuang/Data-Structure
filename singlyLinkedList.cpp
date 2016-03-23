//
//  main.cpp(same as singlyLinkedList.cpp)
//
//  Created by CKHuang on 1/23/16.
//  Copyright (c) 2016 CKHuang. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct Node{
    int val;
    Node *next;
};

class SinglyLinkedList {
public:
    void add(Node *&ptr, int v) {

        if (ptr == NULL) {
            ptr = new Node();
            ptr->val = v;
        }
        else {
            Node *tmp = new Node();
            tmp->val = v;
            tmp->next = ptr;
            ptr = tmp;
        }
    }
    
    int findMid(Node* head) {
        int i = 0;
        Node *ptr;
        while (1) {
            ptr = head;
            
            for (int j=0; j < i; j++) {
                ptr = ptr->next;
            }
            if (ptr->next == NULL) {
                break;
            }
            else {
                i+=2;
            }
        }
        return (i+2)/2;
    }
    
    /*
     *Recursive find middle value
     *@arg:
     *     ptr: pointer to LinkedList
     *     idx: current middle value index
     */
    Node* rFindMid(Node* ptr, Node* mid) {
        Node* tmp = ptr;
        if (mid->val > 1) {
            for (int j=0; j < 2; j++) {
                tmp = tmp->next;
            }
        }
        
        if (tmp->next == NULL) {
            return mid;
        }
        else {
            return rFindMid(tmp, mid->next);
        }
    }
    
    /*
     *Recursive print node value
     *@arg
     * ptr: pointer to LinkedList
     */
    void printList(Node* ptr) {
        if (ptr != NULL) {
            cout<<ptr->val<<endl;
           
            printList(ptr->next);
        }
    }
};

int main(int argc, const char * argv[]) {
    Node *head;
    SinglyLinkedList *s = new SinglyLinkedList();
    int size = 15;
    //create
    for (int i=0; i<size; i++) {
        s->add(head, i+1);
    }
    
    //Print Nodes' value
    s->printList(head);
    
    //Print middle node index
    Node* mid = s->rFindMid(head, head);
    cout<<"Middle node is:"<<mid->val<<endl;
    
    return 0;
}