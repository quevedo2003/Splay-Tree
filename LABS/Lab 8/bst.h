#include <iostream>
#include <vector>
#include <cstdlib>

class Node{
    private:
        int data;
        Node* left_ptr;
        Node* right_ptr;

        
    public:
        Node();
        // Overloading
        Node(int data);
       
        ~Node();
        friend class BSTree;
};





class BSTree{
    private:
    
    Node* root;
    
    Node* insert(Node* root, int data);
    Node* remove(Node* root, int data);

    int height(Node* root);

    void preorder(Node* root, std::ostream& os);
    void inorder(Node* root, std::ostream& os);
    void postorder(Node* root, std::ostream& os);
    void destroy(Node* root);

    public:

    BSTree();
    BSTree(int data);
    // BSTree(std::vector<int> array);
    ~BSTree();

    void insert(int data);
    void remove(int data);
    
    void height();
    
    void preorder(std::ostream& os = std::cout);
    void inorder(std::ostream& os = std::cout);
    void postorder(std::ostream& os = std::cout);
    void destroy();

    bool search(int data);
    bool searchNode(Node* root, int data);
};