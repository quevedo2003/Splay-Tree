#include "bst.h"

//Same as linked list class with a bit of differences

Node::Node(){
    this->data = 0;     //Default Initializes data to be 0 
    this->left_ptr = nullptr; //Making left and right pointers null
    this->right_ptr = nullptr;
}
//One argument, the data
Node::Node(int data){
    this->data = data; //Makes data's member equal to data, gets access to private member
    this->left_ptr = nullptr; //Pointers equals nullpointer(reached its end)
    this->right_ptr = nullptr;
}


Node::~Node(){
//Small enough program to not need a destructor.
}

//Sets root to nothing
BSTree::BSTree(){
    this->root = nullptr;
}

//Sets root to input data
BSTree::BSTree(int data){
   this->root = new Node(data);
}

//Destructor
BSTree::~BSTree(){
    destroy();
}




//Private insert -Does the actual recursive work for inserting
Node* BSTree::insert(Node* root, int data){
    
    if(root == nullptr){
       return new Node(data);
    }
   
    if(data < root->data){
        root->left_ptr = insert(root->left_ptr, data);
    }
    else if(data > root->data){
        root->right_ptr = insert(root->right_ptr,data);
    }


    return root;

}

//Public method - Public interface so that anyone can simply input data into the BSTree, calls private version
//Good way of exposing us to public and private members
void BSTree::insert(int data){
    this->root = insert(this->root, data);
}


//Private Version
 Node* BSTree::remove(Node* root, int data){
   //If there is nothing in the tree, return nothing
    if(root == nullptr){
        return root;
    }
    //If the data is less than the root data then remove it from left subtree
    if(data < root->data){
        root->left_ptr = remove(root->left_ptr, data);
    } //Else remove from right
    else if( data > root->data){
        root->right_ptr = remove(root->right_ptr, data);
    }
    else{//If the current node has the data to be removed
    //If the current node has no left child, replace it with right
        if(root->left_ptr == nullptr){
            Node* temp = root->right_ptr;
            delete root;
            return temp;
        } //Same as above but switched
        else if(root->right_ptr == nullptr){
            Node* temp = root->left_ptr;
            delete root;
            return temp;
        }
        //If current node has both left and right
        //Find minimum node in the right subtree to replace the current node
          Node* min = root->right_ptr;
          while (min->left_ptr != nullptr){
            min = min->left_ptr;
         }
        //Replace the data of the current node with the minimum data from the right subtree
        root->data = min->data;
        //Recursively remove the node with the minmium data from the right subtree
        root->right_ptr = remove(root->right_ptr, min->data);

    }

  return root;


 }
//Public version
void BSTree::remove(int data){
    root = remove(root, data);
}

//Destroy everything from the ground up, this is called by the destructor
void BSTree::destroy(Node* root){
  
    if(root != nullptr){
        destroy(root->left_ptr);
        destroy(root->right_ptr);
        delete root;
    }

}
//Public version
void BSTree::destroy(){
    destroy(root);
    root = nullptr;
}



//Returns the height of the tree
int BSTree::height(Node* root){
    // int height_of_tree, root_node, actual_height;
    //If tree is empty it has a height of 0
    if(root == nullptr){
        return 0;
    }
  
  int  left_height = height(root->left_ptr);
  int  right_height = height(root->right_ptr);

   int root_node = 1; //Must account for root node
   int actual_height = std::max(left_height,right_height);
   int height_of_tree = actual_height + root_node;


    return height_of_tree;

}



//Current, left, right
void BSTree::preorder(Node* root, std::ostream& os){
    //If empty tree, nothing to report
    if(root == nullptr){
        return;
    }

    //Goes current
    os << root->data << ' ';
   
    //Then goes left
    preorder(root->left_ptr, os);

    //Then goes right
    preorder(root->right_ptr, os);
    //  os <<std::endl;

}
//Public version
void BSTree::preorder(std::ostream& os){
    preorder(root, os);
}


//Left, Current, Right
void BSTree::inorder(Node* root, std::ostream& os){
    if(root == nullptr){
        return;
    }

    // Goes left
    inorder(root->left_ptr, os);

    // Then current
    os << root->data << ' ';

    // Then right
    inorder(root->right_ptr, os);
}

//Public version
void BSTree::inorder(std::ostream& os){
    inorder(root, os);
}

// Left, Right, Current
void BSTree::postorder(Node* root, std::ostream& os){

    if(root == nullptr){
        return;
    }

    //Goes left
    postorder(root->left_ptr, os);

    //Then goes right
    postorder(root->right_ptr, os);

    //Then current
    os << root->data << ' ';
    //  std::cout << std::endl;
    // os <<std::endl;
}
//Public version
void BSTree::postorder(std::ostream& os){
    postorder(root, os);
}

//This will be called in the main file
bool BSTree::search(int data) {
    //calls the search node method
   return this->searchNode(this->root, data);
}

bool BSTree::searchNode(Node* root, int data){
    //If tree is empty data is clearly not there
    if(root == nullptr){
        return false;
    }
    //If the data is the root data then return true
    if(data == root->data){
        return true;
    } //Else, traverse through the binary search tree by comparing the data with each node
    else if(data < root->data){
        return searchNode(root->left_ptr, data);
    }
    else{
        return searchNode(root->right_ptr, data);
    }
}