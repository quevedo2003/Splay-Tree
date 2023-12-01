#include "splay_tree.h"
#include <fstream>


int main()
{
STree history;
    history.insert("test");
    history.insert("hello");
    history.insert("check");
    history.insert("new");
    history.preOrder();
    history.splaySearch("hello");
    history.preOrder();
    history.dot_gen("test.dot");
    return 0;
}
