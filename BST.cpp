#include <iostream>
using namespace std;

// constructor
 bst::bst(int key){
     
     root = new Node;
     root->data = key;
     root->right = NULL;
     root->left = NULL;
     
} 

// copy constructor
//uses a preorder traversal so that the tree will be ordered the same
bst::bst(const bst& copyTree){
    recursiveCopy(copyTree.root);
    
}

// insert a new node into the bst
// if the data is larger than the node data, go to the right, if it is smaller, go to the right. 
//if the data already exists in the tree, it will not be inserted 
void bst::insert(int& item){
    if (root == NULL){
        root = new Node;
        root->data = item;
        root->right = NULL;
        root->left = NULL;
    }
    else{
    
        Node* current = find(root, item);
        
         if (item > current->data){
             current->right = new Node;
             current->right->data = item;
             current->right->right = NULL;
             current->right->left = NULL;
         }
         else if (item < current->data){
             current->left = new Node;
             current->left->data = item;
             current->left->right = NULL;
             current->left->left = NULL;
         }
         // else (item == current->data)  and item already exists in the tree and does not need to be inserted


    }
    
} // end insert

    // find
    // recurses through the tree to find the node with the same key as item
    // returns a pointer the node with the same key as item
    // if there is no identical item, it returns a pointer to the node onto which the
    // node should be added
    Node* bst::find(Node* current, int& item){
        
        //if the item to be inserted is larger than the data in the current node, look right
        // if the right branch is empty return
        // otherwise recurse further
        if (item > current->data){
           
            if (current->right == NULL)
                return current;
            else
                find(current->right, item);
             
        }
        //if the item to be inserted is smaller than the data in the current node, look right
        // if the right branch is empty return
        // otherwise recurse further
        else if (item < current->data){
           
            if (current->left == NULL)
                return current;
            else
                find(current->left, item);
             
        }
        else // (item == current->data)
            return current;
        
        
        
        
    }// end bst::find
    
    //print
    //prints a the data in the tree nodes by order of root, left sub tree, right sub tree
   void bst::preOrderPrint(){
       
       if (root == NULL){
           cout << "Tree is empty" << endl;
       }
       else
            recursivePreOrderPrint(root);
            cout << endl;
        
   }// end bst::preOrderPrint()
   
       //prints a the data in the tree nodes by order of root, left sub tree, right sub tree
   void bst::inOrderPrint(){
       
       if (root == NULL){
           cout << "Tree is empty" << endl;
       }
       else
            recursiveInOrderPrint(root);
            cout << endl;
        
   }// end bst::inOrderprint()
   
   //PostOrderPrint
   //prints a the data in the tree nodes by PostOrder--   left sub tree,  right sub tree, root
   void bst::postOrderPrint(){
             
       if (root == NULL){
           cout << "Tree is empty" << endl;
       }
       else
            recursivePostOrderPrint(root);
            cout << endl;
        
   }// end bst::postOrderprint()
   
    //clear
    // deletes all the nodes in the tree.  
    // sets root to NULL
    // uses postOrder Traversal
    void bst::clear(){
        if (root == NULL){
            return;
        }
        else{
            recursiveClear(root);
            root = NULL;
        }

        
    }// end bst::clear()
    
    // remove
    // deletes the node that matches item,
    // nothing if no nodes match
    void bst::remove(int& item){
        
        // first find the node to be removed
        Node* removedParent= NULL;  //will point to the parent of the node to be deleted
        
        if (root == NULL){
            cout << "[remove]Error: Tree is empty.  No nodes to remove.\n";
        }
        else {
            // find the Parent node to the node we wish to remove
            if (root->data == item){
                removedParent = root;
            }
            else {
                removedParent = removeFind(root, item);
            };
            
            if (removedParent != NULL){ // if the node exists in the tree
                
                // We have a pointer to the Parent to the Node to be removed,
                // Now find a pointer to the Node to be removed
                Node* tobeRemoved = NULL;
                if (removedParent->data == item){ //item to be removed is the root
                    tobeRemoved = removedParent;
                }
                else if (removedParent->data > item)
                    tobeRemoved = removedParent->left;
                else
                    tobeRemoved = removedParent->right; 
              
                
                // remove the node
                // 3 cases exist to remove the node
                // Case 1: The node is a leaf
                // Case 2: The node has one child
                // Case 3: The node has 2 children
                
                              
                // Case 1:  remove a leaf node
                if (tobeRemoved->left == NULL && tobeRemoved->right == NULL){
                     if (removedParent->data > item)
                        removedParent->left = NULL;
                    else
                        removedParent->right = NULL;
                    
                    delete tobeRemoved;
                    
                } // end Case 1
                
                
                //Case 3: remove a node with 2 children
                else if (!(tobeRemoved->left == NULL || tobeRemoved->right == NULL)){
                   // cout << " Case 3." << endl;
                   
                   // find the inorder predessessor, or rightmost node on the left
                   int replaceData = recursiveRightmost(tobeRemoved->left);
                   
                   
                  // cout << "rightmostNode data = " << rightmostNode->data << endl;
                   
                   //remove the rightmostNode
                   remove(replaceData);
                   // replace it with the node to delete
                   tobeRemoved->data = replaceData;
                    
                    //clean up pointers
                    tobeRemoved = NULL;
                   
                   
                } // end Case 3
                
                
                // Case 2: remove a node with 1 child
                else {
                    //cout << " Case 2." << endl;
                    
                    // set Parent node pointing to the child of the node to be removed
                    if (removedParent->data > item){
                        
                        if (tobeRemoved-> left == NULL)
                            removedParent->left = tobeRemoved->right;
                        else 
                            removedParent->left = tobeRemoved->left; 
                    }

                    else{
                         if (tobeRemoved-> left == NULL)
                            removedParent->right = tobeRemoved->right;
                        else 
                            removedParent->right = tobeRemoved->left; 
                    }   
                    
                    // delete node
                    delete tobeRemoved;

                    
                } // end Case 2
                
            } // end if (removedParent != NULL)
            
            else { // the node didn't exist
                cout << "[remove] The node didn't exist.  No nodes were removed. \n";
            }

        } // end else root != NULL
        
    }// end remove()
    
    
    
    
    
    // removeFind
    //recurses through the tree to find the Node with the data that matches item 
    //returns a pointer to the parent Node of the Node to be removed
    // returns NULL if the item doesn't exist in the tree
    // assumes that the item to be found isn't it
    // assumes that the root isn't NULL
    
    Node* bst::removeFind(Node* currentRoot, int item){
        
        //if the item to be inserted is larger than the data in the current node, look right
        // if the right branch is empty return
        // otherwise recurse further
        if (item > currentRoot->data){
           
            if (currentRoot->right == NULL) //item doesn't exist
                return NULL;
            else if (currentRoot->right->data == item){ //item found
                return currentRoot;
            }
            else //keep recursing
                removeFind(currentRoot->right, item);
             
        }
        //if the item to be inserted is smaller than the data in the current node, look right
        // if the right branch is empty return
        // otherwise recurse further
        else if (item < currentRoot->data){
           
            if (currentRoot->left == NULL)
                return NULL;
            else if (currentRoot->left->data == item){ //item found
                return currentRoot;
            }
            else
                removeFind(currentRoot->left, item);
             
        }
        else // (item == current->data)
            return currentRoot;
    } // end removeFind
    
    
    // called by remove function 
    // recursively finds the largest item in the tree with root currentRoot
    // returns a pointer to the rightmost node
    //assumes currentRoot is not NULL
    int bst:: recursiveRightmost(Node* currentRoot){

        if (currentRoot->right == NULL ){ // rightmost node found
            return currentRoot->data;
        }
        else //keep digging down to the right
            recursiveRightmost(currentRoot->right);
            
    }
    
    // is called by the public copy constructor 
    // It uses a preorder traverse to recurse through the tree being copied and inserts the nodes into the constructed tree
    void bst::recursiveCopy(Node* currentRoot){
        if (currentRoot ==NULL)
            return;
        else {
            this->insert(currentRoot->data);
            recursiveCopy(currentRoot->left);
            recursiveCopy(currentRoot->right);
        }
    } // end bst::recursivePreOrderPrint
   
   // is called by the public print function to recurse through the tree
    // prints the root, then prints the left sub tree and then the right sub tree
    void bst::recursivePreOrderPrint(Node* currentRoot){
        if (currentRoot ==NULL)
            return;
        else {
            cout << currentRoot->data << " ";
            recursivePreOrderPrint(currentRoot->left);
            recursivePreOrderPrint(currentRoot->right);
        }
    } // end bst::recursivePreOrderPrint

    
    // is called by the public preOrderprint function to recurse through the tree
    // uses the InOrder Traversal
     void bst::recursiveInOrderPrint(Node* currentRoot){
        if (currentRoot ==NULL)
            return;
        else {
            recursiveInOrderPrint(currentRoot->left);
            cout << currentRoot->data << " ";
            recursiveInOrderPrint(currentRoot->right);
        }
    } // end bst::recursiveInOrderPrint


     // is called by the public preOrderprint function to recurse through the tree
    // uses the PostOrder Traversal
     void bst::recursivePostOrderPrint(Node* currentRoot){
        if (currentRoot ==NULL)
            return;
        else {
            recursivePostOrderPrint(currentRoot->left);
            recursivePostOrderPrint(currentRoot->right);
            cout << currentRoot->data << " ";
        }
    } // end bst::recursiveInOrderPrint
    
    
    // recursiveClear
    // Called by the public clear() function
    //recurses through the tree using the PostOrder Traversal to delete all nodes from the tree
    void bst::recursiveClear(Node* currentRoot){
        if (currentRoot ==NULL)
            return;
        else {
            recursiveClear(currentRoot->left);
            recursiveClear(currentRoot->right);
            // delete node
            currentRoot->left = NULL;
            currentRoot->right = NULL;
            delete currentRoot;
        }      
        
    }// end std::recursiveClear()