//
// Created by rotar on 07/01/2025.
//

#include "ac-tree.h"

#include <iostream>

ACTree::ACTree() {
    auto* rootNode = new ACNode(' ');
    this->root = rootNode;
}

void ACTree::printSubtree(const ACNode *node, const int depth) { // NOLINT(*-no-recursion)
    for(int i = 0; i < depth; i++) {
        std::cout<<"-";
    }
    std::cout<<"("<<node->getChar()<<")";
    if(!node->getOutput().empty()) {
        std::cout<<" ("<<node->getOutput()<<")";
    }
    std::cout<<"\n";
    for(const ACNode* nextNode : node->getNext()) {
        printSubtree(nextNode, depth+1);
    }
}

void ACTree::printTree() const {
    printSubtree(root, 1);
}

void ACTree::addWord(const std::string& word) const {
    ACNode* node = this->root;

    for(const char c : word) {
        // search if the letter was already added
        ACNode* nextNode = node->searchNext(c);

        if(nextNode == nullptr) {
            // if not, insert it
            nextNode = node->addNext(c);
        }

        node = nextNode;
    }

    node->setOutput(word);
}
