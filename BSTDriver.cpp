#include <iostream>
#include "bst.h"

using namespace std;

int main()
{

    bst tree1;
    bst tree2(48);
    int key1 = 63;
    int key2 = 82;
    int key3 = 13;
    int key4 = 25;
    int key5 = 51;
    int key6 = 75;
    int key7 = 6;
    int key8 = 31;
    int key9 = 10;
    int key10 = 55;
    int key11 = 99;
    int key12 = 50;
    int key13 = 48;
    
    tree2.insert(key1);
    tree2.insert(key2);
    tree2.insert(key3);
    tree2.insert(key4);
    tree2.insert(key5);
    tree2.insert(key6);
    tree2.insert(key7);
    tree2.insert(key8);
    tree2.insert(key9);
    tree2.insert(key10);
    tree2.insert(key11);
    
    // testing print
    cout << "Testing Print: \n";
    tree2.preOrderPrint();
    tree2.inOrderPrint();
    tree2.postOrderPrint();
    cout << endl << endl;
    
    //testing remove
    cout << "Testing Remove: \n";
    tree2.preOrderPrint();
    tree1.remove(key1);      // remove from an empty tree
    tree2.remove(key12);    // node doesn't exist in tree
    cout << "Remove 10 \n";
    tree2.remove(key9);     // remove a leaf
    tree2.preOrderPrint();
     cout << "Remove 51 \n";
    tree2.remove(key5);     // remove a node with one child
    tree2.preOrderPrint();
     cout << "Remove 63 \n";
    tree2.remove(key1);     // remove a node with 2 children
    tree2.preOrderPrint();
    cout << "Remove 82 \n";
    tree2.remove(key2);     // remove a node with 2 children
    tree2.preOrderPrint();
    cout << "Remove 48, root \n";    
    tree2.remove(key13);    // remove the root
    tree2.preOrderPrint();
    cout << endl << endl;

    
    tree2.clear();
    tree2.preOrderPrint();

    
    
    return 0;
}