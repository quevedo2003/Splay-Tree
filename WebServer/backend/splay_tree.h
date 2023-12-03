#include <iostream>
#include <ostream>
#include <string>
class STNode
{
    private:
        std::string data;
        STNode* left;
        STNode* right;

    public:
        STNode(std::string data);
        ~STNode();

    friend class STree;
};


class STree
{
    private:
        
        STNode* root;
        STNode* splaySearch(std::string data, STNode* root);
        STNode* insert(std::string data, STNode* root);
        STNode* remove(std::string data, STNode* root);
        void preOrder(STNode* root);
        void dot_gen(STNode *node, std::ofstream &dotFile);

    public:
        STree();
        ~STree();
        STNode* rightRotate(STNode*);
        STNode* leftRotate(STNode*);
        STNode* splay(STNode*, std::string);
        STNode* splaySearch(std::string);
        void insert(std::string data);
        void remove(std::string data);
        void preOrder();
        void dot_gen(const std::string &filename);
};
