//
// Created by rotar on 07/01/2025.
//

#ifndef AC_TREE_H
#define AC_TREE_H

#include <string>
#include <vector>

#include "ac-node.h"

struct ACMatch {
    std::string word;
    int start;
    int end;
};

class ACTree {
    ACNode *root;

    static void printSubtree(const ACNode *node, int depth);

public:
    /**
     * Initialize a new aho-corasick tree 
     */
    ACTree();

    /**
     * Add a new word into the tree
     * @param word String to add
     */
    void addWord(const std::string& word) const;

    /**
     * Tell the aho-corasick tree to generate all failure and dictionary links
     */
    void generateLinks();

    /**
     * Match all the words in the aho-corasick tree against the given text
     * @param text Text to search into
     * @return A vector containing all the matches
     */
    std::vector<ACMatch> match(std::string text);

    /**
     * Prints the tree to the terminal. For debug purposes.
     */
    void printTree() const;
};

#endif //AC_TREE_H
