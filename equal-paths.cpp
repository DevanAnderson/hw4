#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here

int calculatePath(Node* root){
    // if(root == nullptr){
    //     return 0;
    // }

    // int left = calculatePath(root->left);
    // int right = calculatePath(root->right);

    // if(left == -1 || right == -1 || left != right){
    //     return -1;
    // }

    // return left + 1;

    if(root == nullptr){
        return 0;
    }

    int left = calculatePath(root->left);
    int right = calculatePath(root->right);

    //if the left or right subtree height is different, return -1
    //to signal that not all paths are equal
    if(left == -1 || right == -1){
        return -1;
    }

    //only left child exists
    if(root->right == nullptr && root->left != nullptr){
        return left + 1;
    }
    //only right child exists
    else if(root->right != nullptr && root->left == nullptr){
        return right + 1;
    }
    //both children exist or neither children exist
    else{
        if(right == left){
            return left + 1;
        }
        //signal that the left and right height is different
        else{
            return -1;
        }
    }
}


bool equalPaths(Node * root)
{
    // Add your code below
    return calculatePath(root) != -1;


    // VOODOO
    // if(root->left == nullptr && root->right == nullptr){
    //     return true;
    // }
    // else if(root->left != nullptr && root->right != nullptr){
    //     bool left = equalPaths(root->left);
    //     bool right = equalPaths(root->right);
    //     return left == right;
    // }
    // else{
    //     return false;
    // }
}
