#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>

/**
 * A templated class for a Node in a search tree.
 * The getters for parent/left/right are virtual so
 * that they can be overridden for future kinds of
 * search trees, such as Red Black trees, Splay trees,
 * and AVL trees.
 */
template <typename Key, typename Value>
class Node
{
public:
    Node(const Key& key, const Value& value, Node<Key, Value>* parent);
    virtual ~Node();

    const std::pair<const Key, Value>& getItem() const;
    std::pair<const Key, Value>& getItem();
    const Key& getKey() const;
    const Value& getValue() const;
    Value& getValue();

    virtual Node<Key, Value>* getParent() const;
    virtual Node<Key, Value>* getLeft() const;
    virtual Node<Key, Value>* getRight() const;

    void setParent(Node<Key, Value>* parent);
    void setLeft(Node<Key, Value>* left);
    void setRight(Node<Key, Value>* right);
    void setValue(const Value &value);

protected:
    std::pair<const Key, Value> item_;
    Node<Key, Value>* parent_;
    Node<Key, Value>* left_;
    Node<Key, Value>* right_;
};

/*
  -----------------------------------------
  Begin implementations for the Node class.
  -----------------------------------------
*/

/**
* Explicit constructor for a node.
*/
template<typename Key, typename Value>
Node<Key, Value>::Node(const Key& key, const Value& value, Node<Key, Value>* parent) :
    item_(key, value),
    parent_(parent),
    left_(NULL),
    right_(NULL)
{

}

/**
* Destructor, which does not need to do anything since the pointers inside of a node
* are only used as references to existing nodes. The nodes pointed to by parent/left/right
* are freed by the BinarySearchTree.
*/
template<typename Key, typename Value>
Node<Key, Value>::~Node()
{

}

/**
* A const getter for the item.
*/
template<typename Key, typename Value>
const std::pair<const Key, Value>& Node<Key, Value>::getItem() const
{
    return item_;
}

/**
* A non-const getter for the item.
*/
template<typename Key, typename Value>
std::pair<const Key, Value>& Node<Key, Value>::getItem()
{
    return item_;
}

/**
* A const getter for the key.
*/
template<typename Key, typename Value>
const Key& Node<Key, Value>::getKey() const
{
    return item_.first;
}

/**
* A const getter for the value.
*/
template<typename Key, typename Value>
const Value& Node<Key, Value>::getValue() const
{
    return item_.second;
}

/**
* A non-const getter for the value.
*/
template<typename Key, typename Value>
Value& Node<Key, Value>::getValue()
{
    return item_.second;
}

/**
* An implementation of the virtual function for retreiving the parent.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getParent() const
{
    return parent_;
}

/**
* An implementation of the virtual function for retreiving the left child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getLeft() const
{
    return left_;
}

/**
* An implementation of the virtual function for retreiving the right child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getRight() const
{
    return right_;
}

/**
* A setter for setting the parent of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setParent(Node<Key, Value>* parent)
{
    parent_ = parent;
}

/**
* A setter for setting the left child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setLeft(Node<Key, Value>* left)
{
    left_ = left;
}

/**
* A setter for setting the right child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setRight(Node<Key, Value>* right)
{
    right_ = right;
}

/**
* A setter for the value of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setValue(const Value& value)
{
    item_.second = value;
}

/*
  ---------------------------------------
  End implementations for the Node class.
  ---------------------------------------
*/

/**
* A templated unbalanced binary search tree.
*/
template <typename Key, typename Value>
class BinarySearchTree
{
public:
    BinarySearchTree(); //TODO
    virtual ~BinarySearchTree(); //TODO
    virtual void insert(const std::pair<const Key, Value>& keyValuePair); //TODO
    virtual void remove(const Key& key); //TODO
    void clear(); //TODO
    bool isBalanced() const; //TODO
    void print() const;
    bool empty() const;

    template<typename PPKey, typename PPValue>
    friend void prettyPrintBST(BinarySearchTree<PPKey, PPValue> & tree);
public:
    /**
    * An internal iterator class for traversing the contents of the BST.
    */
    class iterator  // TODO
    {
    public:
        iterator();

        std::pair<const Key,Value>& operator*() const;
        std::pair<const Key,Value>* operator->() const;

        bool operator==(const iterator& rhs) const;
        bool operator!=(const iterator& rhs) const;

        iterator& operator++();

    protected:
        friend class BinarySearchTree<Key, Value>;
        iterator(Node<Key,Value>* ptr);
        Node<Key, Value> *current_;
    };

public:
    iterator begin() const;
    iterator end() const;
    iterator find(const Key& key) const;
    Value& operator[](const Key& key);
    Value const & operator[](const Key& key) const;

protected:
    // Mandatory helper functions
    Node<Key, Value>* internalFind(const Key& k) const; // TODO
    Node<Key, Value> *getSmallestNode() const;  // TODO
    static Node<Key, Value>* predecessor(Node<Key, Value>* current); // TODO
    static Node<Key, Value>* successor(Node<Key, Value>* curent);// TODO
    // Note:  static means these functions don't have a "this" pointer
    //        and instead just use the input argument.

    // Provided helper functions
    virtual void printRoot (Node<Key, Value> *r) const;
    virtual void nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2) ;

    // Add helper functions here
    void deleteTree(Node<Key, Value>* root);
    int height(Node<Key, Value>* root) const;
    bool balanced(Node<Key, Value>* root) const;
protected:
    Node<Key, Value>* root_;
    // You should not need other data members
};

/*
--------------------------------------------------------------
Begin implementations for the BinarySearchTree::iterator class.
---------------------------------------------------------------
*/

/**
* Explicit constructor that initializes an iterator with a given node pointer.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator(Node<Key,Value> *ptr)
{
    current_ = ptr;
}

/**
* A default constructor that initializes the iterator to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator() 
{
    // TODO
    current_ = nullptr;
}

/**
* Provides access to the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> &
BinarySearchTree<Key, Value>::iterator::operator*() const
{
    return current_->getItem();
}

/**
* Provides access to the address of the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> *
BinarySearchTree<Key, Value>::iterator::operator->() const
{
    return &(current_->getItem());
}

/**
* Checks if 'this' iterator's internals have the same value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator==(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO
    return current_ == rhs.current_;
}

/**
* Checks if 'this' iterator's internals have a different value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator!=(
    const BinarySearchTree<Key, Value>::iterator& rhs) const 
{
    // TODO
    return current_ != rhs.current_;
}


/**
* Advances the iterator's location using an in-order sequencing
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator&
BinarySearchTree<Key, Value>::iterator::operator++()
{
    // TODO
    if(current_ == nullptr){
        return *this;
    }
    //check if there is a right child
    if(current_->getRight() == nullptr){
        //check if there is a parent, if there is a parent and the left child of the parent is not the current, continue traversing up the tree
        //will NOT cause a fault because of short circuiting (false and anything = false, true or anything = true, so no need to check second condition)
        //divine intellect
        while(current_->getParent() != nullptr && current_->getParent()->getLeft() != current_){
            current_ = current_->getParent();
        }
        current_ = current_->getParent();
        
    }
    else{
        current_ = current_->getRight();
        while(current_->getLeft() != nullptr){
            current_ = current_->getLeft();
        }
    }
    //we return *this because this is a pointer to the iterator object, and return type is an iterator object, so we need to dereference it
    return *this;
}


/*
-------------------------------------------------------------
End implementations for the BinarySearchTree::iterator class.
-------------------------------------------------------------
*/

/*
-----------------------------------------------------
Begin implementations for the BinarySearchTree class.
-----------------------------------------------------
*/

/**
* Default constructor for a BinarySearchTree, which sets the root to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::BinarySearchTree() 
{
    root_ = nullptr;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree()
{
    // TODO
    clear();
}

/**
 * Returns true if tree is empty
*/
template<class Key, class Value>
bool BinarySearchTree<Key, Value>::empty() const
{
    return root_ == NULL;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::print() const
{
    printRoot(root_);
    std::cout << "\n";
}

/**
* Returns an iterator to the "smallest" item in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::begin() const
{
    BinarySearchTree<Key, Value>::iterator begin(getSmallestNode());
    return begin;
}

/**
* Returns an iterator whose value means INVALID
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::end() const
{
    BinarySearchTree<Key, Value>::iterator end(NULL);
    return end;
}

/**
* Returns an iterator to the item with the given key, k
* or the end iterator if k does not exist in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::find(const Key & k) const
{
    Node<Key, Value> *curr = internalFind(k);
    BinarySearchTree<Key, Value>::iterator it(curr);
    return it;
}

/**
 * @precondition The key exists in the map
 * Returns the value associated with the key
 */
template<class Key, class Value>
Value& BinarySearchTree<Key, Value>::operator[](const Key& key)
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}
template<class Key, class Value>
Value const & BinarySearchTree<Key, Value>::operator[](const Key& key) const
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}

/**
* An  method to  into a Binary Search Tree.
* The tree will not remain balanced when ing.
* Recall: If key is already in the tree, you should 
* overwrite the current value with the updated value.
*/
template<class Key, class Value>
void BinarySearchTree<Key, Value>::insert(const std::pair<const Key, Value> &keyValuePair)
{
    if(root_ == nullptr){
        root_ = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, nullptr);
        return;
    }

    Node<Key, Value>* current = root_;
    while(1){
        if(keyValuePair.first < current->getKey()){
            if(current->getLeft() != nullptr){
                current = current->getLeft();
            }
            else{
                current->setLeft(new Node<Key, Value>(keyValuePair.first, keyValuePair.second, current));
                current->getLeft()->setParent(current);
                return;
            }
        }
        else if(keyValuePair.first > current->getKey()){
            if(current->getRight() != nullptr){
                current = current->getRight();
            }
            else{
                current->setRight(new Node<Key, Value>(keyValuePair.first, keyValuePair.second, current));
                current->getRight()->setParent(current);
                return;
            }
        }
        else{
            current->setValue(keyValuePair.second);
            return;
        }
    }

    // //we do not want to lost track of the root node so we create a temp pointer
    // if(root_ == nullptr){
    //     root_ = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, nullptr);
    //     return;
    // }

    // Node<Key, Value>* temp = root_;


    // while(1){
    //     if(keyValuePair.first < current->getKey()){
    //         if(current->getLeft() == nullptr){
    //             current->setLeft(new Node<Key, Value>(keyValuePair.first, keyValuePair.second, current));
    //             return;
    //         }
    //         current = current->getLeft();
    //     }
    //     else if(keyValuePair.first > current->getKey()){
    //         if(current->getRight() == nullptr){
    //             current->setRight(new Node<Key, Value>(keyValuePair.first, keyValuePair.second, current));
    //             return;
    //         }
    //         current = current->getRight();
    //     }
    //     else{
    //         current->setValue(keyValuePair.second);
    //         return;
    //     }
    // }
}


/**
* A remove method to remove a specific key from a Binary Search Tree.
* Recall: The writeup specifies that if a node has 2 children you
* should swap with the predecessor and then remove.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::remove(const Key& key)
{
    // TODO

    //traverse to find node with key
    Node<Key, Value>* temp = root_;

    //traverse until we find the node
    while(1){
        //key was not found
        if(temp == nullptr){
            return;
        }

        //if the key is less than temp, go left
        if(key < temp->getKey()){
            temp = temp->getLeft();
        }
        //if the key is greater than temp, go right
        else if(key > temp->getKey()){
            temp = temp->getRight();
        }
        //if we found the key, stop traversing and break out of loop
        else{
            break;
        }
    }

    //if there are two children, then swap with its predecessor
    if(temp->getRight() != nullptr && temp->getLeft() != nullptr){
        nodeSwap(predecessor(temp), temp);
    }

    //now that there are less than 2 children

    //if there are no children
    if(temp->getRight() == nullptr && temp->getLeft() == nullptr){
        //check if we are at the root node
        if(temp->getParent() == nullptr){
            delete temp;
            root_ = nullptr;
            return;
        }
        //check if temp is parents left child
        if(temp->getParent()->getLeft() == temp){
            temp->getParent()->setLeft(nullptr);
        }
        //if temp is parents right child
        else{
            temp->getParent()->setRight(nullptr);
        }
    }
    //no right child
    else if(temp->getRight() == nullptr){
        //check if we are at the root
        if(temp->getParent() == nullptr){
            root_ = temp->getLeft();
            root_->setParent(nullptr);
            delete temp;
            return;
        }
        //set left childs parent to its grandparent
        temp->getLeft()->setParent(temp->getParent());

        //if temp is its parents left child
        if(temp->getParent()->getLeft() == temp){
            //set parents left child to its grandchild
            temp->getParent()->setLeft(temp->getLeft());
        }
        //if temp was its parents right child
        else{
            temp->getParent()->setRight(temp->getLeft());
        }
        delete temp;
    }
    //no left child
    else{
        //check if we are at the root
        if(temp->getParent() == nullptr){
            root_ = temp->getRight();
            root_->setParent(nullptr);
            delete temp;
            return;
        }
        //set right childs parent to grandparent
        temp->getRight()->setParent(temp->getParent());

        //if temp is its parents left child
        if(temp->getParent()->getLeft() == temp){
            //set parent
            temp->getParent()->setLeft(temp->getRight());
        }
        //if temp was its parents right child
        else{
            temp->getParent()->setRight(temp->getRight());
        }
        delete temp;
    }


//VOODOO
//     Node<Key, Value>* temp = root_;

//     //traverse to find the key
//     while(1){

//         //key not found
//         if(temp == nullptr){
//             return;
//         }
//         if(key > temp->getKey()){
//             temp = temp->getRight();
//         }
//         else if(key < temp->getKey()){
//             temp = temp->getLeft();
//         }
//         else{
//             break;
//         }
//     }

//     //after we find the node

//     //if there are less than 2 child nodes, treat it like a linked list
//     if(temp->getLeft() == nullptr){
//         //left child does not exist

//         //set right childs parent to temps parent
//         Node<Key, Value>* temp2 = temp->getRight();
//         temp2->setParent(temp->getParent());

//         //set parent's left child to temps child (if temp was parents left child)
//         if(temp->getParent()->getLeft() == temp){
//             temp->getParent()->setLeft(temp2);
//         }
//         //set parents right child to temps child (if temp was parents right child)
//         else{
//             temp->getParent()->setRight(temp2);
//         }
//         delete temp;
//     }
//     else if(temp->getRight() == nullptr){
//         //right child does not exist

//         //set left childs parent to temps parent
//         Node<Key, Value>* temp2 = temp->getLeft();
//         temp2->setParent(temp->getParent());

//         //set parents left child to temps child (if temp was parents left child)
//         if(temp->getParent()->getLeft() == temp){
//             temp->getParent()->setLeft(temp2);
//         }
//         //set parents right child to temps child (if temp was parents right child)
//         else{
//             temp->getParent()->setRight(temp2);
//         }
//         delete temp;
//     }
//     //if both children exist
//     else{
//         nodeSwap(temp, predecessor(temp));
//         remove(key);
//     }
}

template<class Key, class Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::predecessor(Node<Key, Value>* current)
{
    // TODO
    //if the left subtree exists
    if(current->getLeft() != nullptr){
        //take a step to go to the left subtree and traverse right as much as possible
        current = current->getLeft();
        while(current->getRight() != nullptr){
            current = current->getRight();
        }
        return current;
    }
    //if the left subtree does not exist, travel the ancestor chain until the left child is not the current
    while(current->getParent() != nullptr && current->getParent()->getLeft() == current){
        current = current->getParent();
    }
    return current->getParent();
}

template<class Key, class Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::successor(Node<Key, Value>* current){
    if(current->getRight() != nullptr){
        current = current->getRight();
        while(current->getLeft() != nullptr){
            current = current->getLeft();
        }
        return current;
    }

    while(current->getParent() != nullptr || current->getParent()->getRight() == current){
        current = current->getParent();
    }
    return current->getParent();
}


/**
* A method to remove all contents of the tree and
* reset the values in the tree for use again.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear()
{
    deleteTree(root_);
    root_ = nullptr;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::deleteTree(Node<Key, Value>* root){
    if(root == nullptr){
        return;
    }

    //delete left subtree
    deleteTree(root->getLeft());
    //delete right subtree
    deleteTree(root->getRight());
    delete root;
}


/**
* A helper function to find the smallest node in the tree.
*/
template<typename Key, typename Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::getSmallestNode() const
{
    if(root_ == nullptr){
        return nullptr;
    }
    Node<Key, Value> *temp = root_;
    while(temp->getLeft() != nullptr){
        temp = temp->getLeft();
    }
    return temp;
}

/**
* Helper function to find a node with given key, k and
* return a pointer to it or NULL if no item with that key
* exists
*/
template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::internalFind(const Key& key) const
{
    Node<Key, Value>* temp = root_;
    while(temp != nullptr){
        if(key < temp->getKey()){
            temp = temp->getLeft();
        }
        else if(key > temp->getKey()){
            temp = temp->getRight();
        }
        else{
            break;
        }
    }
    return temp;
}

/**
 * Return true iff the BST is balanced.
 */
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isBalanced() const
{
    // TODO
    return balanced(root_);
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::balanced(Node<Key, Value>* root) const{
    if(root == nullptr){
        return true;
    }

    //balance factor is defined as the right minus the left
    int balanceFactor = height(root->getRight()) - height(root->getLeft());

    //return false if the balance factor is greater than 1 or less than -1
    if(balanceFactor < -1 || balanceFactor > 1){
        return false;
    }

    //return true if the left and right subtrees are balanced
    return balanced(root->getLeft()) && balanced(root->getRight());
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>::height(Node<Key, Value>* root) const{
    if(root == nullptr){
        return 0;
    }

    int left = height(root->getLeft()) + 1;
    int right = height(root->getRight()) + 1;

    //return the max height of the two
    if(left > right){
        return left;
    }
    else{
        return right;
    }
}




template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2)
{
    if((n1 == n2) || (n1 == NULL) || (n2 == NULL) ) {
        return;
    }
    Node<Key, Value>* n1p = n1->getParent();
    Node<Key, Value>* n1r = n1->getRight();
    Node<Key, Value>* n1lt = n1->getLeft();
    bool n1isLeft = false;
    if(n1p != NULL && (n1 == n1p->getLeft())) n1isLeft = true;
    Node<Key, Value>* n2p = n2->getParent();
    Node<Key, Value>* n2r = n2->getRight();
    Node<Key, Value>* n2lt = n2->getLeft();
    bool n2isLeft = false;
    if(n2p != NULL && (n2 == n2p->getLeft())) n2isLeft = true;


    Node<Key, Value>* temp;
    temp = n1->getParent();
    n1->setParent(n2->getParent());
    n2->setParent(temp);

    temp = n1->getLeft();
    n1->setLeft(n2->getLeft());
    n2->setLeft(temp);

    temp = n1->getRight();
    n1->setRight(n2->getRight());
    n2->setRight(temp);

    if( (n1r != NULL && n1r == n2) ) {
        n2->setRight(n1);
        n1->setParent(n2);
    }
    else if( n2r != NULL && n2r == n1) {
        n1->setRight(n2);
        n2->setParent(n1);

    }
    else if( n1lt != NULL && n1lt == n2) {
        n2->setLeft(n1);
        n1->setParent(n2);

    }
    else if( n2lt != NULL && n2lt == n1) {
        n1->setLeft(n2);
        n2->setParent(n1);

    }


    if(n1p != NULL && n1p != n2) {
        if(n1isLeft) n1p->setLeft(n2);
        else n1p->setRight(n2);
    }
    if(n1r != NULL && n1r != n2) {
        n1r->setParent(n2);
    }
    if(n1lt != NULL && n1lt != n2) {
        n1lt->setParent(n2);
    }

    if(n2p != NULL && n2p != n1) {
        if(n2isLeft) n2p->setLeft(n1);
        else n2p->setRight(n1);
    }
    if(n2r != NULL && n2r != n1) {
        n2r->setParent(n1);
    }
    if(n2lt != NULL && n2lt != n1) {
        n2lt->setParent(n1);
    }


    if(this->root_ == n1) {
        this->root_ = n2;
    }
    else if(this->root_ == n2) {
        this->root_ = n1;
    }

}

/**
 * Lastly, we are providing you with a print function,
   BinarySearchTree::printRoot().
   Just call it with a node to start printing at, e.g:
   this->printRoot(this->root_) // or any other node pointer

   It will print up to 5 levels of the tree rooted at the passed node,
   in ASCII graphics format.
   We hope it will make debugging easier!
  */

// include print function (in its own file because it's fairly long)
#include "print_bst.h"

/*
---------------------------------------------------
End implementations for the BinarySearchTree class.
---------------------------------------------------
*/

#endif
