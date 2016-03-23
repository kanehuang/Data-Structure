//
//  main.cpp
//  BinarySearchTree
//
//  Created by CKHuang on 2/8/16.
//  Copyright (c) 2016 CKHuang. All rights reserved.
//

#include <iostream>
#define MAX 131073
using namespace std;

class BinarySearchTree {
public:
    int array[MAX];
    int idx = 0;
    const int min = INT_MIN;
    
    //initialize binary search tree
    BinarySearchTree() {
        for (int i = 1; i < MAX; i++) {
            array[i] = INT_MIN;
        }
    }
    
    //find next node to be removed in BST
    int aFindNext(int i, int v) {
        int index = searchIdx(i, v);
        
        int result = INT_MIN;
        int lnext = index*2;
        int rnext = index*2+1;
        
        if (array[lnext] != INT_MIN) {
            rnext = lnext*2+1;
            while (array[rnext] != INT_MIN) {
                rnext = rnext*2+1;
            }
            result = rnext / 2;
        }
        else if (array[rnext] != INT_MIN) {
            lnext = rnext*2;
            while (array[lnext] != INT_MIN) {
                lnext = lnext * 2;
            }
            result = lnext / 2;
        }

        return result;
    }

    //search value index in array
    int searchIdx(int idx, int v) {
        while (1) {
            if (array[idx] == INT_MIN) {
                return INT_MIN;
            }

            if (array[idx] == v) {
                break;
            }
            else if (array[idx] > v) {
                idx = 2*idx;
            }
            else {
                idx = 2*idx+1;
            }
        }
        return idx;
    }
    
    //Array remove
    int aRemove(int v) {
//        cout<<"Remove:"<<v<<endl;
        int index = searchIdx(idx, v);
        int next = aFindNext(idx, v);
        int result = INT_MIN;
        
        if (index == INT_MIN) {
            return INT_MIN;
        }
        
        //leaf
        if (next == INT_MIN) {
            array[index] = INT_MIN;
            array[0]--;
            return 1;
        } else { //not leaf
            int nchild = aFindNext(idx, array[next]);
            if (nchild != INT_MIN) {

                while (nchild != INT_MIN) {
                    array[index] = array[next];
                    array[next] = array[nchild];
                    index = next;
                    next = nchild;
                    nchild = aFindNext(nchild, array[nchild]);
                }
                array[next] = INT_MIN;
                array[0]--;
            }
            else {
                array[index] = array[next];
                array[next] = INT_MIN;
                array[0]--;
            }
            
            return 2;
        }
        
        return result;
    }
    
    void arrInsert(int v) {
        if (idx == 0) {
            array[++idx] = v;
            array[0] = 1;
        }
        else {
            int cnt = idx;
            while (array[cnt] != INT_MIN) {
                if (v < array[cnt]){
                    cnt = 2 * cnt;
                } else {
                    cnt = 2 * cnt+1;
                }
            }
            array[cnt] = v;
            array[0]++;
        }
    }
    
    void aPrint() {
        int i=1;
        int cnt = 0;
        cout<<"print Tree:";
        for (; i < MAX; i++) {
            if (array[i] != INT_MIN) {
                cout<<array[i]<<" ";
                cnt++;
                
                if (cnt >= array[0]) {
                    break;
                }
            }
        }
        cout<<endl;
    }
};

int main(int argc, const char * argv[]) {
    BinarySearchTree bst;
    int size = 15;
    
    for (int i = 1; i<=size; i++) {
        bst.arrInsert(i);
    }
    bst.aPrint();
    bst.aRemove(2);
    bst.aRemove(10);
    bst.aPrint();
    return 0;
}
