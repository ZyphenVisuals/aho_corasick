//
// Created by rotar on 07/01/2025.
//

#include "ac-node.h"

ACNode::ACNode(const char c) {
    this->c = c;
}

ACNode * ACNode::searchNext(const char c) const {
    for(ACNode* node : this->next) {
        if(node->c == c) {
            return node;
        }
    }
    return nullptr;
}

char ACNode::getChar() const {
    return this->c;
}

ACNode * ACNode::addNext(const char c) {
    auto* node = new ACNode(c);
    this->next.push_back(node);
    return node;
}

std::vector<ACNode *> ACNode::getNext() const {
    return this->next;
}

void ACNode::setFailure(ACNode *failure) {
    this->failure = failure;
}

ACNode * ACNode::getFailure() const {
    return failure;
}

void ACNode::setDictionary(ACNode *dictionary) {
    this->dictionary = dictionary;
}

ACNode * ACNode::getDictionary() const {
    return dictionary;
}
