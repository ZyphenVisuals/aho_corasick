// Created by Iulian R.

/* Important note:
 * In addition to the failure links described in our class, this code also implements dictionary links.
 * This is because, to my understanding, on slide 46 of "course10.pdf",
 * the word "at" would not be found in the word "potato".
 * This implementation is partially based on the following explanations:
 * https://www.youtube.com/watch?v=O7_w001f58c
 * https://www.youtube.com/watch?v=OFKxWFew_L0
 * from Mr. Niema Moshiri, Associate Professor at the University of California, Sn Diego (UCSD).
 */

#include <iostream>
#include <fstream>
#include <string.h>

#include "ac-tree.h"

int main(int argc, char *argv[]) {
    // variables
    std::string filename;
    int wordCount;
    std::string text;
    const ACTree ac;
    std::string word;
    bool debug = false;

    // handle flags
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "--debug") == 0 || strcmp(argv[i], "-d") == 0) {
                debug = true;
            }
        }
    }

    // handle user input
    std::cout << "Enter the source file for the text: ";
    std::cin >> filename;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Can't open input file!";
        return 1;
    }
    // https://stackoverflow.com/a/2912614
    text.assign((std::istreambuf_iterator<char>(file)),
                (std::istreambuf_iterator<char>()));
    file.close();
    std::cout << "Enter the number of patterns: ";
    std::cin >> wordCount;
    for (int i = 0; i < wordCount; i++) {
        std::cout << "Enter the pattern " << i + 1 << ": ";
        std::cin >> word;
        ac.addWord(word);
    }

    // aho-corasick stuff
    ac.generateLinks();
    if (debug) {
        std::cout << std::endl;
        ac.printTree();
    }
    std::cout << std::endl;
    for (std::vector<ACMatch> matches = ac.match(text); const ACMatch& match: matches) {
        std::cout << "Pattern " << match.word << " occurs at positions " << match.start << " ... " << match.end <<
                std::endl;
    }
    return 0;
}
