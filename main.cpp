#include <iostream>

#include "ac-tree.h"

int main() {
    const ACTree ac;

    ac.addWord("a");
    ac.addWord("ag");
    ac.addWord("c");
    ac.addWord("caa");
    ac.addWord("gag");
    ac.addWord("gc");
    ac.addWord("gca");
    ac.generateLinks();
    ac.printTree();
    return 0;
}
