#include "splay_tree.h"
#include <fstream>
//Also Including the time measurement header here to allow for easier access across dif directories
#include "time_measurement.h"

// NODE FUNCTIONS

// Allocate a new node with the given value and NULL left and right pointers.
STNode::STNode(std::string data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}
// Node destructor.
STNode::~STNode()
{
}

///////////////////////////////////////////////////////////////////////////////////////////

// TREE FUNCTIONS

// Function to rignt roate node.
STNode *STree::rightRotate(STNode *x)
{
    STNode *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
// Function to left rotate node.
STNode *STree::leftRotate(STNode *x)
{
    STNode *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// This function modifies the tree and returns the modified root.
// It takes the data number requested and brings it to the top.
STNode *STree::splay(STNode *root, std::string data, int& node_count)
{
    // Base cases:
    // If the root is NULL or the data is present at the root, return the root
    if (root == nullptr || root->data == data)
    {
        node_count++;
        return root;
    }

    // data lies in the left subtree
    if (root->data > data)
    {
        // If the left child is NULL, return the root (data not found)
        if (root->left == nullptr)
        {
            node_count++;
            return root;
        }

        // data is in the left subtree
        if (root->left->data > data)
        {
            // Zig-Zig (Left Left)
            // Recursively bring the data as the root of left-left
            root->left->left = splay(root->left->left, data, node_count);

            // Perform a right rotation for the root, followed by the second rotation
            root = rightRotate(root);
        }
        else if (root->left->data < data)
        {
            // Zig-Zag (Left Right)
            // Recursively bring the data as the root of left-right
            root->left->right = splay(root->left->right, data, node_count);

            // Perform a left rotation for root->left if needed
            if (root->left->right != nullptr)
            {
                root->left = leftRotate(root->left);
            }
        }

        // Does a second rotation for the root, if necessary
        // Return the updated root
        if (root->left == nullptr)
        {
            node_count++;
            return root;
        }
        else
        {
            node_count++;
            return rightRotate(root);
        }
    }
    else
    {
        // Data lies in the right subtree
        // If the right child is NULL, return the root (data not found)
        if (root->right == nullptr)
        {
            node_count++;
            return root;
        }

        // data is in the right subtree
        if (root->right->data > data)
        {
            // Zag-Zig (Right Left)
            // Recursively bring the data as the root of right-left
            root->right->left = splay(root->right->left, data, node_count);

            // Perform a right rotation for root->right if needed
            if (root->right->left != nullptr)
            {
                root->right = rightRotate(root->right);
            }
        }
        else if (root->right->data < data)
        {
            // Zag-Zag (Right Right)
            // Recursively bring the data as the root of right-right
            root->right->right = splay(root->right->right, data, node_count);

            // Perform a left rotation for the root if needed
            root = leftRotate(root);
        }

        // Perform a second rotation for the root, if necessary
        // Return the updated root
        if (root->right == nullptr)
        {
            node_count++;
            return root;
        }
        else
        {
            node_count++;
            return leftRotate(root);
        }
    }
}

// Private function to perform splaying search
STNode *STree::splaySearch(std::string data, STNode *root, int& node_count)
{
    return splay(root, data, node_count); // Splay the found/positioned node or return current root
}
// Public search function to find stord item.
STNode *STree::splaySearch(std::string data)
{
    int node_count = 0;
    this->root = splaySearch(data, this->root, node_count);
    std::cout <<"Node counter = " << node_count << std::endl;
    return this->root;
}

// Private function to print preorder traversal of the tree as well as print to the terminal.
void STree::preOrder(STNode *root)
{
    if (root != nullptr)
    {
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
// Public function to print tree in preorder.
void STree::preOrder()
{
    this->preOrder(this->root);
    std::cout << "\n";
}

// Private function to inset new nodes into the tree.
STNode *STree::insert(std::string data, STNode *root)
{
    if (!root)
    {
        return new STNode(data);
    }
    int count_node = 0;
    root = splay(root, data, count_node);

    if (root->data == data)
    {
        return root;
    }
    STNode *temp = new STNode(data);
    if (root->data > data)
    {
        temp->right = root;
        temp->left = root->left;
        root->left = nullptr;
    }
    else
    {
        temp->left = root;
        temp->right = root->right;
        root->right = nullptr;
    }
    return temp;
}
// Public function to insert  new nodes into the tree.
void STree::insert(std::string data)
{
    this->root = this->insert(data, this->root);
}

// Default constructor.
STree::STree()
{
    this->root = nullptr;
}
// Destructor.
STree::~STree()
{
    delete this->root;
}

// Public function to write the DOT representation of the tree to a file
void STree::dot_gen(const std::string &filename)
{
    std::ofstream dotFile(filename);

    if (!dotFile.is_open())
    {
        std::cout << "Unable to open file: " << filename << std::endl;
        return;
    }

    dotFile << "digraph SplayTree {" << std::endl;

    dot_gen(root, dotFile);

    dotFile << "}" << std::endl;

    dotFile.close();
}
// Private function to recursively traverse and write nodes to DOT file
void STree::dot_gen(STNode *node, std::ofstream &dotFile)
{
    if (node != nullptr)
    {
        dotFile << "\t" << node->data << ";" << std::endl;

        if (node->left != nullptr)
        {
            dotFile << "\t" << node->data << " -> " << node->left->data << ";" << std::endl;
            dot_gen(node->left, dotFile);
        }

        if (node->right != nullptr)
        {
            dotFile << "\t" << node->data << " -> " << node->right->data << ";" << std::endl;
            dot_gen(node->right, dotFile);
        }
    }
}


void STree::toJsonHelper(STNode* node, std::ostream& out){
    
    if(node != nullptr){
        out << "{\"name\": \"" << node->data << "\", \"children\": [";
        toJsonHelper(node->left, out);
        out << ",";
        toJsonHelper(node->right, out);
        out << "]}";
    }
    else{
        out << "null";
    }

}

std::string STree::toJson(){
  
    std::ostringstream jsonStream;
    toJsonHelper(root, jsonStream);
    return jsonStream.str();

}