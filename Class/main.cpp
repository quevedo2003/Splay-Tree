#include "splay_tree.h"
#include <fstream>

int main(int argc, char*argv[])
{
STree history;

    history.file_insert(argv[1]);
    history.preOrder();
    history.splaySearch("hello");
    history.preOrder();
    history.dot_gen("test.dot");
    return 0;
}
