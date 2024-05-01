#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

// A Huffman tree node
struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char data, int freq) : data(data), freq(freq), left(NULL), right(NULL) {}
};

// Comparison function for priority queue
struct Compare {
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) {
        return lhs->freq > rhs->freq;
    }
};

// Traverse the Huffman tree and store codes
void encode(HuffmanNode* root, string code, map<char, string>& codes) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        codes[root->data] = code;
    }

    encode(root->left, code + "0", codes);
    encode(root->right, code + "1", codes);
}

// Construct Huffman tree and encode the input
void huffmanEncode(string input) {
    // Count the frequency of each character
    map<char, int> freq;
    for (size_t i = 0; i < input.size(); ++i) {
        freq[input[i]]++;
    }

    // Create a priority queue to store nodes
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        pq.push(new HuffmanNode(it->first, it->second));
    }

    // Construct the Huffman tree
    while (pq.size() != 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* merge = new HuffmanNode('$', left->freq + right->freq);
        merge->left = left;
        merge->right = right;

        pq.push(merge);
    }

    // Get the root of the Huffman tree
    HuffmanNode* root = pq.top();

    // Traverse the Huffman tree to get codes for each character
    map<char, string> codes;
    encode(root, "", codes);

    // Print the Huffman codes
    cout << "Huffman Codes:\n";
    for (map<char, string>::iterator it = codes.begin(); it != codes.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    // Encode the input string
    cout << "Encoded String:\n";
    for (size_t i = 0; i < input.size(); ++i) {
        cout << codes[input[i]];
    }
    cout << endl;

    // Free memory
    delete root;
}

int main() {
    string input;
    cout << "Enter the string to encode: ";
    getline(cin, input);

    huffmanEncode(input);

    return 0;
}

