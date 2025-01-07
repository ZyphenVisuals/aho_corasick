//
// Created by rotar on 07/01/2025.
//

#ifndef AC_NODE_H
#define AC_NODE_H

#include <vector>

class ACNode {
    char c;

    std::vector<ACNode *> next;
    ACNode *failure = nullptr;
    ACNode *dictionary = nullptr;

public:
    /**
     * A node on an Aho-Corasick tree will contain the character that was used to get to it, on the normal path
     * @param c Character of the node
     */
    explicit ACNode(char c);

    /**
     * Search the next nodes for a given character
     * @param c Character to search for
     * @return Pointer of the next node
     */
    [[nodiscard]] ACNode *searchNext(char c) const;

    /**
     * Insert a new node with a given character
     * @param c Character for the next node
     * @return Pointer of the next node
     */
    ACNode *addNext(char c);

    /**
     * Set the fail link
     * @param failure Pointer of the failure node
     */
    void setFailure(ACNode *failure);

    /**
     * Get the failure node, if set
     * @return Pointer to the failure node
     */
    [[nodiscard]] ACNode *getFailure() const;

    /**
     * Set the dictionary link
     * @param dictionary Pointer of the dictionary node
     */
    void setDictionary(ACNode *dictionary);

    /**
        * Get the dictionary node, if set
        * @return Pointer to the dictionary node
        */
    [[nodiscard]] ACNode *getDictionary() const;
};

#endif //AC_NODE_H
