#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int8_t getBalance () const;
    void setBalance (int8_t balance);
    void updateBalance(int8_t diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    int8_t balance_;    // effectively a signed char
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
int8_t AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(int8_t balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(int8_t diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);
    
    // Add helper functions here
    void insertFix(AVLNode<Key, Value>* child);
    void rotateRight(AVLNode<Key, Value>* node);
    void rotateLeft(AVLNode<Key, Value>* node);
    void removeFix(AVLNode<Key, Value>* n, int8_t diff);

};

/*
 * Recall: If key is already in the tree, you should 
 * overwrite the current value with the updated value.
 */
template<class Key, class Value>
void AVLTree<Key, Value>::insert(const std::pair<const Key, Value> &new_item)
{
    AVLNode<Key, Value>* n = new AVLNode<Key, Value>(new_item.first, new_item.second, nullptr);

    if(!this->root_){
        this->root_ = n;
        return;
    }

    AVLNode<Key, Value>* current = dynamic_cast<AVLNode<Key, Value>*>(this->root_);

    //traverse the tree
    while(1){
        //if the key of the new item is less than currents key, go to the left
        if(n->getKey() < current->getKey()){
            //if there is nothing to the left, then insert the new node
            if(!current->getLeft()){
                current->setLeft(n);
                n->setParent(current);
                break;
            }
            current = current->getLeft();
        }
        //if the key of the new item is grater than currents key, go to the right
        else if(n->getKey() > current->getKey()){
            //if there is nothing to the right, then insert the new node
            if(!current->getRight()){
                current->setRight(n);
                n->setParent(current);
                break;
            }
            current = current->getRight();
        }
        //if the keys are equal, change the value at current's key
        else{
            current->setValue(n->getValue());
            delete n;
            return;
        }
    }

    if(current->getBalance() == 1 || current->getBalance() == -1){
        current->setBalance(0);
    }
    else{
        //if n is the left child of current, update currents balance to -1
        if(current->getLeft() == n){
            current->setBalance(-1);
        }
        //if n is the right child of current, updates current balabce to 1
        else{
            current->setBalance(1);
        }
        insertFix(n);
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::insertFix(AVLNode<Key, Value>* child){
    //if the there is no parent or the parent is the root, return;
    if(!child->getParent() || child->getParent() == this->root_){
        return;
    }

    AVLNode<Key, Value>* parent = child->getParent();
    AVLNode<Key, Value>* grandparent = parent->getParent();

    //if the grandparent is null, return
    if(!grandparent){
        return;
    }

    //if parent is the left child of grandparent
    if(parent == grandparent->getLeft()){
        grandparent->updateBalance(-1);

        if(grandparent->getBalance() == 0){
            return;
        }
        else if(grandparent->getBalance() == -1){
            insertFix(parent);
            return;
        }
        else if(grandparent->getBalance() == -2){
            //zig zig (left left)
            if(parent->getLeft() == child){
                parent->setBalance(0);
                grandparent->setBalance(0);
                rotateRight(grandparent);
            }
            //zig zag (left right)
            else{
                if(child->getBalance() == -1){
                    parent->setBalance(0);
                    grandparent->setBalance(1);
                }
                else if(child->getBalance() == 0){
                    parent->setBalance(0);
                    grandparent->setBalance(0);
                }
                else{
                    parent->setBalance(-1);
                    grandparent->setBalance(0);
                }
                child->setBalance(0);
                rotateLeft(parent);
                rotateRight(grandparent);
            }
        }
    }
    //if parent is the right child of grandparent
    else{
        grandparent->updateBalance(1);

        if(grandparent->getBalance() == 0){
            return;
        }
        else if(grandparent->getBalance() == 1){
            insertFix(parent);
            return;
        }
        else if(grandparent->getBalance() == 2){
            //zig zig (right right)
            if(parent->getRight() == child){
                parent->setBalance(0);
                grandparent->setBalance(0);
                rotateLeft(grandparent);
            }
            //zig zag (right left)
            else{
                if(child->getBalance() == -1){
                    parent->setBalance(1);
                    grandparent->setBalance(0);
                }
                else if(child->getBalance() == 0){
                    parent->setBalance(0);
                    grandparent->setBalance(0);
                }
                else{
                    parent->setBalance(0);
                    grandparent->setBalance(-1);
                }
                child->setBalance(0);

                rotateRight(parent);
                rotateLeft(grandparent);
            }
        }
    }
}



template<class Key, class Value>
void AVLTree<Key, Value>::rotateRight(AVLNode<Key, Value>* node){

    AVLNode<Key, Value>* left = node->getLeft();
    
    //if we are rotating about the root, then there is no parent
    if(node == this->root_){
        this->root_ = left;
        left->setParent(nullptr);
    }
    //if there is a parent, then we need to update its right or left child depending upon which child "n" is
    else{
        left->setParent(node->getParent());
        if(node->getParent()->getLeft() == node){
            node->getParent()->setLeft(left);
        }
        else if(node->getParent()->getRight() == node){
            node->getParent()->setRight(left);
        }
    }

    //set the left child of node to the right child of its (former) left child
    node->setLeft(left->getRight());
    //set the parent of node to be its (former) left child
    node->setParent(left);
    //set the left nodes right child to be node
    left->setRight(node);

    //if the new left child of the node rotated about is not null, update its parent
    if(node->getLeft()){
        node->getLeft()->setParent(node);
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::rotateLeft(AVLNode<Key, Value>* node){

    AVLNode<Key, Value>* right = node->getRight();

    //if we are rotating about the root, then there is no parent
    if(node == this->root_){
        this->root_ = right;
        right->setParent(nullptr);
    }
    //if we are not rotating about the root, then we need to update its left or right child depending upon which child "n" is
    else{
        right->setParent(node->getParent());
        if(node->getParent()->getLeft() == node){
            node->getParent()->setLeft(right);
        }
        else{
            node->getParent()->setRight(right);
        }
    }

    //set the parent of n to be its right child
    node->setParent(right);
    //set the right child of n to be right's left child
    node->setRight(right->getLeft());
    //set rights left child to be n
    right->setLeft(node);

    //if the new right child is not null, update its parent
    if(node->getRight()){
        node->getRight()->setParent(node);
    }
}



/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */
template<class Key, class Value>
void AVLTree<Key, Value>:: remove(const Key& key)
{
    //if the tree is empty, do nothing
    if(!this->root_){
        return;
    }
    //if there is just one node, delete the node and assign root to nullptr
    if(this->root_->getKey() == key && !this->root_->getLeft() && !this->root_->getRight()){
        delete this->root_;
        this->root_ = nullptr;
        return;
    }

    AVLNode<Key, Value>* current = dynamic_cast<AVLNode<Key, Value>*>(this->root_);
    
    //traversing the tree
    while(1){
        //not found
        if(!current){
            return;
        }

        //if the key is less than current, go to the left
        if(key < current->getKey()){
            current = current->getLeft();
        }
        //if the key is greater than current, go to the right
        else if(key > current->getKey()){
            current = current->getRight();
        }
        //found the node
        else{
            break;
        }
    }

    //check if the node has 2 children, swap with its predecessor
    if(current->getLeft() && current->getRight()){
        nodeSwap(current, dynamic_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key, Value>::predecessor(current)));
    }

    AVLNode<Key, Value>* parent = current->getParent();

    int8_t diff = 0;
    //updating balance
    if(parent){
       if(parent->getLeft() == current){
        diff += 1;
       }
       else{
        diff += -1;
       }
    }

    //delete and update pointers

    //if the parent is not nullptr (current is the root node)
    if(parent){
        //if current has no children
        if(!current->getLeft() && !current->getRight()){
            if(parent->getLeft() == current){
                parent->setLeft(nullptr);
            }
            else{
                parent->setRight(nullptr);
            }
        }
        //if curent has a left child
        else if(current->getLeft() && !current->getRight()){
            if(parent->getLeft() == current){
                parent->setLeft(current->getLeft());
                current->getLeft()->setParent(parent);
            }
            else{
                parent->setRight(current->getLeft());
                current->getLeft()->setParent(parent);
            }
        }
        //current has a right child
        else{
            if(parent->getLeft() == current){
                parent->setLeft(current->getRight());
                current->getRight()->setParent(parent);
            }
            else{
                parent->setRight(current->getRight());
                current->getRight()->setParent(parent);
            }
        }
    }
    //if the parent is nullptr (current is the root node)
    else{
        if(!current->getLeft() && !current->getRight()){
            delete current;
            this->root_ = nullptr;
            return;
        }
        else if(current->getLeft() && !current->getRight()){
            current->getLeft()->setParent(nullptr);
            this->root_ = current->getLeft();
        }
        else{
            current->getRight()->setParent(nullptr);
            this->root_ = current->getRight();
        }
    }
    delete current;
    removeFix(parent, diff);
}

template<class Key, class Value>
void AVLTree<Key, Value>::removeFix(AVLNode<Key, Value>* n, int8_t diff){
    //if n is null, return
    if (!n){
        return;
    }

    //compute the next calls recursive arguments before altering the tree 
    AVLNode<Key, Value>* parent = n->getParent();
    int8_t ndiff = 0;

    if(parent){
        if(n->getParent()->getLeft() == n){
            ndiff = 1;
        }
        else{
            ndiff = -1;
        }
    }


    if(diff == -1){
        //case 1
        if(n->getBalance() + diff == -2){

            AVLNode<Key, Value>* child = n->getLeft();
            //case 1a
            if(child->getBalance() == -1){
                rotateRight(n);
                n->setBalance(0);
                child->setBalance(0);

                removeFix(parent, ndiff);
            }
            //case 1b
            else if(child->getBalance() == 0){
                rotateRight(n);
                n->setBalance(-1);
                child->setBalance(1);
            }
            //case 1c
            else if(child->getBalance() == 1){
                AVLNode<Key, Value>* grandchild = child->getRight();
                rotateLeft(child);
                rotateRight(n);

                if(grandchild->getBalance() == 1){
                    child->setBalance(-1);
                    n->setBalance(0);
                }
                else if(grandchild->getBalance() == 0){
                    child->setBalance(0);
                    n->setBalance(0);
                }
                else if(grandchild->getBalance() == -1){
                    child->setBalance(0);
                    n->setBalance(1);
                }
                grandchild->setBalance(0);
                removeFix(parent, ndiff);
            }
        }
        //case 2
        else if(n->getBalance() + diff == -1){
            n->setBalance(-1);
        }
        //case 3
        else{
            n->setBalance(0);
            removeFix(parent, ndiff);
        }
    }
    else if(diff == 1){
        //case 1
        if(n->getBalance() + diff == 2){
            
            AVLNode<Key, Value>* child = n->getRight();

            //case 1a
            if(child->getBalance() == 1){
                rotateLeft(n);
                n->setBalance(0);
                child->setBalance(0);

                removeFix(parent, ndiff);
            }
            //case 1b
            else if(child->getBalance() == 0){
                rotateLeft(n);
                n->setBalance(1);
                child->setBalance(-1);
            }
            //case 1c
            else if(child->getBalance() == -1){
                AVLNode<Key, Value>* grandchild = child->getLeft();
                rotateRight(child);
                rotateLeft(n);

                if(grandchild->getBalance() == -1){
                    n->setBalance(0);
                    child->setBalance(1);
                }
                else if(grandchild->getBalance() == 0){
                    n->setBalance(0);
                    child->setBalance(0);
                }
                else if(grandchild->getBalance() == 1){
                    n->setBalance(-1);
                    child->setBalance(0);
                }
                grandchild->setBalance(0);

                removeFix(parent, ndiff);
            }
        }
        //case 2
        else if(n->getBalance() + diff == 1){
            n->setBalance(1);
        }
        //case 3
        else if(n->getBalance() + diff == 0){
            n->setBalance(0);
            removeFix(parent, ndiff);
        }
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    int8_t tempB = n1->getBalance();
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}
#endif
