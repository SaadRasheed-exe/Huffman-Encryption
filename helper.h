#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <string>

#define bitStringLength 8

std::string reverseString(std::string);

std::string intToBitsR(int);

std::string intToBits(int);

std::string intToByteR(int);

std::string intToByte(int);

int bitToInt(std::string);

bool hasChar(std::string, char);

std::string compressBitString(std::string);

std::string uncompressBitString(std::string);

int fileSize(std::fstream&);

int fileSize(std::string);

class Node
{
public:
    Node(std::string c, int f, Node* l, Node* r);

    std::string chars;
    int frequency;
    Node* left;
    Node* right;

    bool isLeaf();
};

struct priority
{
    bool operator()(Node* a, Node* b);
};

class huffmanCompression
{
private:
    static void completeBits(std::string& bitstring);

    static void removeExcessBits(std::string& bitstring);

    static void fillQueue(std::string text, std::priority_queue<Node*, std::vector<Node*>, priority>& g);

    static Node* makeTree(std::priority_queue<Node*, std::vector<Node*>, priority>& g);

    static std::string getBitStringFromTree(Node* root, char c, std::string bitstring);

    static std::string textToBits(std::string oText, Node* tree);

    static std::string bitsToText(std::string bitstring, Node* tree);

    static void recreateTree(Node* n, char c, std::string bitstring);

    static void storeTree(Node* root, std::fstream& f, std::string bitstring);

    static void storeTree(Node* root, std::string& d, std::string bitstring);

    static void deleteTree(Node* n);

public:
    static void compressFile(std::string file);

    static void decompressFile(std::string file);

    static std::string compressString(std::string data);

    static std::string decompressString(std::string compressedText);
};
