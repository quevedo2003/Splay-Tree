#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>

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
        //Setting up a counter variable
        STNode* splaySearch(std::string data, STNode* root, int& node_count);
        STNode* insert(std::string data, STNode* root);
        STNode* remove(std::string data, STNode* root);
        void preOrder(STNode* root);
        void dot_gen(STNode *node, std::ofstream &dotFile);

       //Json
       void toJsonHelper(STNode* node, std::ostream& out);

    public:
        STree();
        ~STree();
        void file_insert(std::string file_name);
        STNode* rightRotate(STNode*);
        STNode* leftRotate(STNode*);
        STNode* splay(STNode*, std::string, int& node_count);
        STNode* splaySearch(std::string);
        void insert(std::string data);
        void remove(std::string data);
        void preOrder();
        void dot_gen(const std::string &filename);

        
        
        std::string toJson();

};

#endif