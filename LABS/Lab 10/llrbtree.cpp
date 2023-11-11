#include "llrbtree.h"

/*
 * Node Class Functions
*/

BSTNode::BSTNode(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->color = true;
}

BSTNode::~BSTNode(){
//Destructor
}

/*
 * Tree Class Functions
*/

/*
 * Private Functions
*/

bool llrbtree::isRed(BSTNode* root){
    if(root == nullptr){
        return false;
    }

    return root->color;
}

BSTNode* llrbtree::insert(int data, BSTNode* root) {
    if(!root){
        return new BSTNode(data);
    }

    if(data < root->data){
        root->left = insert(data, root->left);
    } 
    else{
        root->right = insert(data, root->right);
    }

    // Set color of new node to RED
    // root->color = true;

    // Perform LLRB rotations and color flips as needed
   

    if(isRed(root->right) && !isRed(root->left)){
        root = rotateLeft(root);
    }

    if(isRed(root->left) && isRed(root->left->left)){
        root = rotateRight(root);
    }

    if(isRed(root->left) && isRed(root->right)){
        flipColors(root);
    }

    return root;
}



BSTNode* llrbtree::remove(int data, BSTNode* root){
    if(!root){
        return nullptr;
    }

    // We found what we're looking for, delete it.
    if(data == root->data){
        BSTNode* temp;
        // This is a leaf node
        if(root->left == root->right){
            delete root;
            return nullptr;
        }

        // This node has 1 child
        if(!root->left != !root->right){
            // Set temp to whichever child exists
            root->left ? temp = root->left : temp = root->right;

            delete root;
            return temp;
        }

        // This node has 2 children
        // Find the in-order successor
        temp = root->right;

        while(temp->left){
            temp = temp->left;
        }

        // Copy the data to this node and delete the original
        root->data = temp->data;
        root->right = remove(temp->data, root->right);
        return root;
    }

    // This is not the Node we're looking for, recursively find the data we want to delete
    if(data < root->data){
        root->left = remove(data, root->left);
    }else{
        root->right = remove(data, root->right);
    }

    return root;
}

BSTNode* llrbtree::find_ios(BSTNode* root, bool& disconnect){
    if(!root->left){
        disconnect = true;
        return root;
    }
    BSTNode* temp = find_ios(root->left, disconnect);

    if(disconnect){
        root->left = nullptr;
        disconnect = false;
    }

    return temp;
}

int llrbtree::height(BSTNode* root){
    if(!root){
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left + 1 : right + 1);
}

void llrbtree::preorder(BSTNode* root, std::ostream& os) {
    if(!root){
        return;
    }

    os << root->data << ":" << root->color << " ";
    this->preorder(root->left, os);
    this->preorder(root->right, os);
}

// Similar modifications for inorder and postorder functions

void llrbtree::inorder(BSTNode* root, std::ostream& os) {
    if(!root){
        return;
    }

    this->inorder(root->left, os);
    os << root->data << ":" << root->color << " ";
    this->inorder(root->right, os);
}

void llrbtree::postorder(BSTNode* root, std::ostream& os) {
    if(!root){
        return;
    }

    this->postorder(root->left, os);
    this->postorder(root->right, os);
    os << root->data << ":" << root->color << " ";
}


void llrbtree::destroy(BSTNode* root){
    if(!root){
        return;
    }

    this->destroy(root->left);
    this->destroy(root->right);
    delete root->left;
    delete root->right;
}

bool llrbtree::search(int data, BSTNode* root){
    if(!root){
        return false;
    }

    if(data == root->data){
        return true;
    }

    if(data < root->data){
        return this->search(data, root->left);
    }else{
        return this->search(data, root->right);
    }
}


BSTNode* llrbtree::rotateLeft(BSTNode* grandparent) {
    BSTNode* parent = grandparent->right;
    grandparent->right = parent->left;
    parent->left = grandparent;
    parent->color = grandparent->color;
    grandparent->color = true;  
    return parent;
}


BSTNode* llrbtree::rotateRight(BSTNode* grandparent) {
    BSTNode* parent = grandparent->left;
    grandparent->left = parent->right;
    parent->right = grandparent;
    parent->color = grandparent->color;
    grandparent->color = true;  
    return parent;
}

void llrbtree::flipColors(BSTNode* height){
    height->color = true;        
    height->left->color = false; 
    height->right->color = false; 
}


/*
 * Public Functions
*/

llrbtree::llrbtree(){
    this->_root = nullptr;
}

llrbtree::~llrbtree(){
    delete this->_root;
}

void llrbtree::insert(int data){
    this->_root = this->insert(data, this->_root);
    _root->color = false;
}

void llrbtree::remove(int data){
    this->_root = this->remove(data, this->_root);
}

int llrbtree::height(){
    return this->height(this->_root);
}

void llrbtree::preorder(std::ostream& os){
    this->preorder(this->_root, os);
    os << "\n";
}

void llrbtree::inorder(std::ostream& os){
    this->inorder(this->_root, os);
    os << "\n";
}

void llrbtree::postorder(std::ostream& os){
    this->postorder(this->_root, os);
    os << "\n";
}

bool llrbtree::search(int data){
    return this->search(data, this->_root);
}