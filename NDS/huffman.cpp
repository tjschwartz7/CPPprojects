#include "huffman.h"



void huffmanDecoding::BuildCharacterFrequencyTable(std::string inputString, std::map<char, int>* table) {
        for (int i = 0; i < inputString.length(); i++) {
            char currentCharacter = inputString[i];
                if (table->find(currentCharacter) != table->end()) {
                    table->at(currentCharacter)++;
                }
                else {
                    table->emplace(currentCharacter, 1);
                }
        }
}

std::map<char, int>* huffmanDecoding::BuildCharacterFrequencyTable(std::string inputString) {
    std::map<char, int>* table = new std::map<char, int>();
    for (int i = 0; i < inputString.length(); i++) {
        char currentCharacter = inputString[i];
        if (table->find(currentCharacter) != table->end()) {
            table->at(currentCharacter)++;
        }
        else {
            table->emplace(currentCharacter, 1);
        }
    }
    return table;
}

HuffmanTree* huffmanDecoding::HuffmanBuildTree(std::string inputString) {
    // First build the frequency table
    std::map<char, int>* table = BuildCharacterFrequencyTable(inputString);

    // Make a priority queue of nodes
    PriorityQueue<HuffmanTree*> nodes;
	for (auto iter = table->begin(); iter != table->end(); ++iter ) {
        //std::cout << "first-" << iter->first << "second-" << iter->second << std::endl;
        HuffmanLeaf *newLeaf = new HuffmanLeaf(iter->second, iter->first);
        nodes.enqueue(newLeaf);
	}
    // Make parent nodes up to the root
    while (nodes.getLength() > 1) {
        // Dequeue 2 lowest-priority nodes
        HuffmanTree* left = nodes.dequeue();
        HuffmanTree* right = nodes.dequeue();

            // Make a parent for the two nodes
        int freqSum = right->frequency + left->frequency;
        //std::cout << freqSum << std::endl;
        HuffmanNode* parent = new HuffmanNode(freqSum, left, right);

            // Enqueue parent back into priority queue
        nodes.enqueue(parent);
    }
    return nodes.dequeue();
}

std::map<char, std::string>* huffmanDecoding::HuffmanGetCodes(HuffmanTree* node, std::string prefix, std::map<char, std::string>* output) {
    if (node->left == nullptr && node->right == nullptr) {
        //std::cout << node->character << std::endl;
        output->emplace(node->character, prefix);
    }
    else {
        HuffmanGetCodes(node->left, prefix + "0", output);
        HuffmanGetCodes(node->right, prefix + "1", output);
    }
    return output;
}

std::string huffmanDecoding::HuffmanDecompress(std::string compressedString, HuffmanTree* treeRoot) {
    HuffmanTree* node = treeRoot;
    std::string result = "";
        for (char bit : compressedString) {
            // Go to left or right child based on bit value
            if (bit == '0')
                node = node->left;
            else
                node = node->right;

            // If the node is a leaf, add the character to the 
            // decompressed result and go back to the root node
            if (node->left == nullptr && node->right == nullptr) {
                result += node->character;
                node = treeRoot;
            }
        }
        return result;
}

std::string huffmanDecoding::HuffmanCompress(std::string inputString) {
    // Build the Huffman tree
    HuffmanTree* root = HuffmanBuildTree(inputString);
    this->root = root;
    // Get the compression codes from the tree
    std::map<char, std::string>* codes = HuffmanGetCodes(root, "", new std::map<char, std::string>());
    // Build the compressed result
    std::string result = "";
    for( char c : inputString){
        result += codes->at(c);
    }
    return result;
}


//BuildCharacterFrequencyTable("APPLES AND BANANAS")


