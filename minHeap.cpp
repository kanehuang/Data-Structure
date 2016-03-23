//
//  main.cpp
//  assignment3
//
//  Created by CKHuang on 3/11/16.
//  Copyright (c) 2016 CKHuang. All rights reserved.
//

#include <iostream>
using namespace std;

class minHeap {
public:
    int* heap = NULL;
    int size = 0;
    
    //Initialize min heap
    minHeap(int size) {
        heap = new int[size];
    }
    
    
    void insert(int x) {
        ++size;
        heap[size] = x;
        percolateUp(size);
        print();
    }
    
    //Delete the min node in the minHeap
    int deleteMin() {
        if (heap == NULL) {
            return -1;
        }
        
        int del = heap[1];
        heap[1] = heap[size];
        size--;
        if (size > 1) {
            percolateDown(1);
        }
        print();
        
        return del;
    }
    
    //Reorder minHeap after insertion
    void percolateUp(int x) {
        heap[0] = heap[x];
        while (heap[x/2] > heap[0]) {
            heap[x] = heap[x/2];
            x = x/2;
        }
        heap[x] = heap[0];
    }
    
    //Reorder minHeap after deletion
    void percolateDown(int x) {
        int t = heap[x];
        int left = 2 * x;
        int right = 2 * x + 1;
        int desc = 0;

        while (left <= size) {
            if (left == size) {
                if (t > heap[size]) {
                    heap[x] = heap[size];
                    x = size;
                } else {
                    break;
                }
            }
            
            if (heap[left] <= heap[right]) {
                desc = left;
            } else {
                desc = right;
            }

            if (t > heap[desc]) {
                heap[x] = heap[desc];
                x = desc;
            } else {
                break;
            }
            left = 2 * x;
            right = 2 * x + 1;
        }
        heap[x] = t;
    }
    
    //print minHeap
    void print() {
        cout<<"Heap:";
        for (int i=1; i<=size; i++) {
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }
    
    //Delete dynamic variables
    void deleteAry() {
        delete heap;
    }
};

int main(int argc, const char * argv[]) {
//    int a[] = {13, 14, 16, 19, 21, 27, 68, 65, 26, 32, 31, 30, 40, 88, 70, 50, 99, 37, 80, 120, 57, 73, 33, 46, 43};
    int a[25];
    for (int i=1; i<26; i++) {
        int t = 100 - i*2;
        a[i] = t;
    }
    
    int size = sizeof(a)/sizeof(int);

    minHeap h(size);
    for (int i=1; i<= size; i++) {
        h.insert(a[i]);
    }
    int input;
    char yesno;
    
    for (int i=0; i<4; i++) {
        cout<<"insert:";
        cin >> input;
        h.insert(input);

        cout<<"delete(y/n):";
        cin>>yesno;
        if (yesno == 'y') {
            int del = h.deleteMin();
            cout<<"delete:"<<del<<endl;
        } else {
            h.print();
        }
    }
    h.deleteAry();
    
    return 0;
}
