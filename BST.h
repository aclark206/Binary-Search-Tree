#ifndef VARIABLE
#define VARIABLE

struct Node 
{ 
    int data; 
    Node *right; 
    Node *left;
};

class bst{
  public:
    //constructors
    bst() : root(NULL) {}
    
    bst(int key);
    //copy constructor
    //performs a deep copy of the passed bst
    bst(const bst& copyTree);
    
    //destructor
    // deletes all the nodes in the tree
    ~bst(){ clear(); };
    
   
    // insert a new node into the bst
    // if the data is larger than the node data, go to the right, if it is smaller, go to the right. 
    void insert(int& item);
    
    // find
    // recurses through the tree to find the node with the data that matches item
    // returns a pointer to the node
     Node* find(Node* current, int& item);
    
    // remove
    // deletes the node that matches item,
    // nothing if no nodes match
    void remove(int& item);
    
    
    //PreOrderprint
    //prints a the data in the tree nodes by PreOrder--  order of root, left sub tree, right sub tree
   void preOrderPrint();
   
   // InOrderPrint
   //prints a the data in the tree nodes by InOrder--   left sub tree,  root, right sub tree
   void inOrderPrint();
   
   //PostOrderPrint
   //prints a the data in the tree nodes by PostOrder--   left sub tree,  right sub tree, root
   void postOrderPrint();

    
    //clear
    // deletes all the nodes in the tree.  
    // sets root to NULL
    // uses postOrder Traversal
    void clear();

  private:
    Node* root;
    
    // is called by the public copy constructor 
    // It uses a preorder traverse to recurse through the tree being copied and inserts the nodes into the constructed tree
    void recursiveCopy(Node* currentRoot);
        
    // is called by the public preOrderprint function to recurse through the tree
    // uses the PreOrder Traversal
    void recursivePreOrderPrint(Node* currentRoot);
    
    // is called by the public InOrderprint function to recurse through the tree
    // uses the InOrder Traversal
     void recursiveInOrderPrint(Node* currentRoot);
     
     // is called by the public PostOrderprint function to recurse through the tree
    // uses the PostOrder Traversal
     void recursivePostOrderPrint(Node* currentRoot);

    // recursiveClear
    // Called by the public clear() function
    //recurses through the tree using the PostOrder Traversal to delete all nodes from the tree
    void recursiveClear(Node* currentRoot);
    
    // removeFind
    //recurses through the tree to find the Node with the data that matches item 
    //returns a pointer to the parent Node of the Node to be removed
    // returns NULL if the item doesn't exist in the tree
    // assumes that the item to be found isn't it
    // assumes that the root isn't NULL
    Node* removeFind(Node* currentRoot, int item);
    
    // called by remove() function 
    // recursively finds the largest item in the tree with root currentRoot
    // returns a pointer to the rightmost node
    //assumes currentRoot is not NULL
    int recursiveRightmost(Node* currentRoot);

}; // end class def bst

#include "bst.cpp"
#endif