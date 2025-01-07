//
// Created by rotar on 07/01/2025.
//

#include "ac-tree.h"

#include <iostream>
#include <queue>

ACTree::ACTree() {
    auto* rootNode = new ACNode(' ');
    this->root = rootNode;
}

void ACTree::printSubtree(const ACNode *node, const int depth) { // NOLINT(*-no-recursion)
    for(int i = 0; i < depth; i++) {
        std::cout<<"-";
    }
    std::cout<<"("<<node->getChar()<<") (failure: " <<node->getFailure()->getChar()<<")";
    if(node->getDictionary() != nullptr ) {
        std::cout<<" (dictionary output: "<<node->getDictionary()->getOutput()<<")";
    }
    if(!node->getOutput().empty()) {
        std::cout<<" (output: "<<node->getOutput()<<")";
    }
    std::cout<<"\n";
    for(const ACNode* nextNode : node->getNext()) {
        printSubtree(nextNode, depth+1);
    }
}

ACNode * ACTree::find(const std::string &word) const {
    ACNode* node = this->root;

    for(const char c : word) {
        ACNode* nextNode = node->searchNext(c);
        if(nextNode == nullptr) {
            return nullptr;
        }
        node = nextNode;
    }

    return node;
}

void ACTree::generateFailureLinks(ACNode* node, std::string word) const { // NOLINT(*-no-recursion)
    // find the failure link of the current node
    ACNode* failureNode = nullptr;

    std::string wordCopy = word;

    if(!word.empty()) word = word.substr(1, word.size() - 1);

    while(failureNode == nullptr && !word.empty()) {
        failureNode = this->find(word);
        word = word.substr(1, word.size() - 1);
    }

    if(word.empty() && failureNode == nullptr) {
        failureNode = this->root;
    }

    node->setFailure(failureNode);

    // recurse
    for(ACNode* nextNode : node->getNext()) {
        generateFailureLinks(nextNode, wordCopy + nextNode->getChar());
    }
}

void ACTree::generateDictionaryLinks() const {
    std::queue<ACNode*> q;
    q.push(this->root);

    while(!q.empty()) {
        // get a node from the queue
        ACNode* node = q.front();
        q.pop();

        // add its children to the queue
        for(ACNode* nextNode : node->getNext()) {
            q.push(nextNode);
        }

        // find potential output links
        ACNode* dictionaryNode = node->getFailure();

        while(dictionaryNode->getOutput().empty() && dictionaryNode != this->root) {
            dictionaryNode = dictionaryNode->getFailure();
        }

        if(dictionaryNode != this->root) {
            node->setDictionary(dictionaryNode);
        }
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

void ACTree::generateLinks() const {
    this->generateFailureLinks(this->root, "");
    this->generateDictionaryLinks();
}

std::vector<ACMatch> ACTree::match(const std::string& text) const {
    const ACNode* node = this->root;
    std::vector<ACMatch> matches;

    int i=0;
    for(const char c : text) {
        // make a move
        ACNode* nextNode = node->searchNext(c);

        while(nextNode == nullptr && node != this->root) {
            node = node->getFailure();
            nextNode = node->searchNext(c);
        }

        if(nextNode != nullptr) {
            node = nextNode;
        }

        // check for output
        if(!node->getOutput().empty()) {
            matches.push_back(ACMatch(node->getOutput(), i - node->getOutput().length() + 1, i));
        }

        // check dictionary path
        const ACNode *ghostNode = node;
        while(ghostNode->getDictionary() != nullptr) {
            ghostNode = ghostNode->getDictionary();
            matches.push_back(ACMatch(ghostNode->getOutput(), i - ghostNode->getOutput().length() + 1, i));
        }

        // increment counter
        i++;
    }

    return matches;
}
