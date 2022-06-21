#pragma

#include "helper.h"

// returns the input std::string reversed
std::string reverseString(std::string rev)
{
    int temp = rev.length() - 1;
    for (int i = 0; i < rev.length() / 2; i++)
    {
        char temp2 = rev[i];
        rev[i] = rev[temp - i];
        rev[temp - i] = temp2;
    }
    return rev;
}

// returns shortest bit std::string for an int in reverse
std::string intToBitsR(int a)
{
    std::string bits;
    while (a > 0)
    {
        bits.append(std::to_string(a % 2));
        a /= 2;
    }
    return bits;
}

// returns shortest bit std::string for an int
std::string intToBits(int a)
{
    return reverseString(intToBitsR(a));
}

// returns 8-bit bit std::string for an int in reverse
std::string intToByteR(int a)
{
    int temp;
    (a < 0) ? temp = -(a - 127) : temp = a;
    std::string bits = intToBitsR(temp);
    for (int i = bits.length(); i < bitStringLength; i++)
    {
        bits.append(std::to_string(0));
    }
    return bits;
}

// returns 8-bit bit std::string for an int
std::string intToByte(int a)
{
    return reverseString(intToByteR(a));
}

// returns an int from a bit string
int bitsToInt(std::string bitstring)
{
    int m = 1;
    int res = 0;
    for (int i = bitstring.length() - 1; i >= 0; i--)
    {
        res += (bitstring[i] - '0') * m;
        m *= 2;
    }
    if (bitstring[0] == '1')
    {
        res = -(res - 127);
    }
    return res;
}

// returns true if given char is found in given string
bool hasChar(std::string s, char c)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            return true;
        }
    }
    return false;
}

// converts a bit std::string into its char string
std::string compressBitString(std::string bitstring)
{
    std::string compressed;
    for (int i = 0; i < bitstring.length(); i += bitStringLength)
    {
        compressed += (char)bitsToInt(bitstring.substr(i, bitStringLength));
    }
    return compressed;
}

// converts a char std::string to its bit string
std::string uncompressBitString(std::string compressedBitString)
{
    std::string bitstring;
    for (int i = 0; i < compressedBitString.length(); i++)
    {
        bitstring += intToByte((int)compressedBitString[i]);
    }
    return bitstring;
}

// returns the size of the file in fstream object passed
int fileSize(std::fstream& f)
{
    if (!f.is_open())
    {
        return 0;
    }
    std::string temp;
    int size = 0;
    while (!f.eof())
    {
        getline(f, temp);
        size += temp.size();
    }
    return size;
}

// returns the size of the file with the filename passed
int fileSize(std::string filename)
{
    std::fstream f(filename, std::ios::in);
    return fileSize(f);
}

// node class for the huffman tree
Node::Node(std::string c, int f = 0, Node* l = NULL, Node* r = NULL)
{
    chars = c;
    frequency = f;
    left = l;
    right = r;
}

// returns true if the node is a leaf
bool Node::isLeaf()
{
    if (left == NULL && right == NULL)
    {
        return true;
    }
    return false;
}

bool priority::operator()(Node* a, Node* b)
{
    return a->frequency > b->frequency;
}

// adds bits so the length of bitstring is a multiple of 8.
// for encoding of data in huffman compression.
void huffmanCompression::completeBits(std::string& bitstring)
{
    int bitsToAdd = (bitStringLength - (bitstring.length() % bitStringLength)) % bitStringLength;
    for (int i = 0; i < bitsToAdd; i++)
    {
        bitstring.append(std::to_string(0));
    }
    bitstring.append(intToByte(bitsToAdd));
}

// removes excess bits from the bit string.
// for retrieval of text after huffman compression.
void huffmanCompression::removeExcessBits(std::string& bitstring)
{
    std::string temp;
    for (int i = bitstring.length() - bitStringLength; i < bitstring.length(); i++)
    {
        temp += bitstring[i];
    }
    int bitsToRemove = bitsToInt(temp);
    for (int i = 0; i < bitsToRemove + bitStringLength; i++)
    {
        bitstring.pop_back();
    }
}

// fills a given table with the characters and their frequencies at which they appear in the given string
void huffmanCompression::fillQueue(std::string text, std::priority_queue<Node*, std::vector<Node*>, priority>& g)
{
    std::map<char, int> freq;
    for (int i = 0; i < text.length(); i++)
    {
        freq[text[i]]++;
    }
    for (auto it = freq.begin(); it != freq.end(); ++it)
    {
        std::string a;
        a.push_back(it->first);
        Node* temp = new Node(a, it->second);
        g.push(temp);
    }
}

// makes the tree required for huffman compression from the given table
Node* huffmanCompression::makeTree(std::priority_queue<Node*, std::vector<Node*>, priority>& g)
{
    while (g.size() > 1)
    {
        Node* a = g.top();
        g.pop();
        Node* b = g.top();
        g.pop();
        Node* c = new Node(a->chars + b->chars, a->frequency + b->frequency, a, b);
        g.push(c);
    }
    return g.top();
}

// returns bit string for a char from huffman tree
std::string huffmanCompression::getBitStringFromTree(Node* root, char c, std::string bitstring = "")
{
    if (root == NULL)
    {
        return "";
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (hasChar(root->chars, c))
        {
            return bitstring;
        }
        return "";
    }
    if (root->left != NULL)
    {
        if (hasChar(root->left->chars, c))
        {
            return getBitStringFromTree(root->left, c, bitstring + "0");
        }
    }
    if (root->right != NULL)
    {
        if (hasChar(root->right->chars, c))
        {
            return getBitStringFromTree(root->right, c, bitstring + "1");
        }
    }
    return "";
}

// returns the bit string for the given text and tree
std::string huffmanCompression::textToBits(std::string oText, Node* tree)
{
    std::string bitstring = "";
    for (int i = 0; i < oText.length(); i++)
    {
        bitstring += getBitStringFromTree(tree, oText[i]);
    }
    completeBits(bitstring);
    return bitstring;
}

// returns the original text with the given bit string and tree
std::string huffmanCompression::bitsToText(std::string bitstring, Node* tree)
{
    std::string text;
    Node* temp = tree;
    removeExcessBits(bitstring);
    for (int i = 0; i < bitstring.length(); i++)
    {
        if (bitstring[i] == '1')
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
        if (temp->chars.length() == 1)
        {
            text.append(temp->chars);
            temp = tree;
        }
    }
    return text;
}

// partially recreates the tree on the given node with the bitstring places the char at the leaf
void huffmanCompression::recreateTree(Node* n, char c, std::string bitstring)
{
    for (char bit : bitstring)
    {
        if (bit == '1')
        {
            if (n->right == NULL)
            {
                n->right = new Node("");
            }
            n = n->right;
            continue;
        }
        if (bit == '0')
        {
            if (n->left == NULL)
            {
                n->left = new Node("");
            }
            n = n->left;
            continue;
        }
    }
    n->chars += c;
}

// stores the given tree in the given fstream object
void huffmanCompression::storeTree(Node* root, std::fstream& f, std::string bitstring = "")
{
    if (root == NULL)
    {
        return;
    }
    if (root->isLeaf())
    {
        f << root->chars << ' ' << bitstring << '`' << std::endl;
        return;
    }
    storeTree(root->left, f, bitstring + "0");
    storeTree(root->right, f, bitstring + "1");
}

// appends the given tree in the given string object
void huffmanCompression::storeTree(Node* root, std::string& d, std::string bitstring = "")
{
    if (root == NULL)
    {
        return;
    }
    if (root->isLeaf())
    {
        d.append(root->chars + " " + bitstring + "`\n");
        return;
    }
    storeTree(root->left, d, bitstring + "0");
    storeTree(root->right, d, bitstring + "1");
}

// deletes the tree if there is one
void huffmanCompression::deleteTree(Node* n)
{
    if (n == NULL)
    {
        return;
    }

    deleteTree(n->left);
    deleteTree(n->right);

    delete n;
}

// compresses the txt in a file and stores the compressed text in another file
void huffmanCompression::compressFile(std::string file)
{
    std::fstream f(file, std::ios::in);
    std::string data, temp;
    while (!f.eof())
    {
        getline(f, temp);
        data.append(temp + "\n");
    }
    std::priority_queue<Node*, std::vector<Node*>, priority> q;
    fillQueue(data, q);
    Node* tree = makeTree(q);
    temp = compressBitString(textToBits(data, tree));

    std::string newFile;
    for (char c : file)
    {
        if (c == '.')
        {
            break;
        }
        newFile += c;
    }
    newFile.append("-compressed.txt");

    std::fstream nf(newFile, std::ios::out);
    nf << temp << "\n"
        << "`````"
        << "\n";
    storeTree(tree, nf);
    deleteTree(tree);
}

// stores the decompressed text of a file in another text file
void huffmanCompression::decompressFile(std::string file)
{
    std::fstream f(file, std::ios::in | std::ios::binary);
    std::string data, temp, temp2;
    Node* tree = new Node("");
    getline(f, temp);
    temp.erase(temp.size() - 1);
    while (temp != "`````")
    {
        data.append(temp + "\n");
        getline(f, temp);
        temp.erase(temp.size() - 1);
    }

    while (!f.eof())
    {
        getline(f, temp);
        if (temp.size() > 0)
        {
            temp.erase(temp.size() - 1);
        }
        if (temp[temp.size() - 1] != '`')
        {
            getline(f, temp2);
            if (temp2.size() > 0)
            {
                temp2.erase(temp2.size() - 1);
            }
            temp.append("\n" + temp2);
            temp2 = "";
        }
        if (temp == "\n")
        {
            break;
        }
        recreateTree(tree, temp[0], temp.substr(2, temp.size() - 3));
    }

    std::string newFile;
    for (char c : file)
    {
        if (c == '.')
        {
            break;
        }
        newFile += c;
    }
    newFile.append("-uncompressed.txt");

    std::fstream nf(newFile, std::ios::out);
    std::string decompressed = bitsToText(uncompressBitString(data), tree);
    nf << decompressed;
    deleteTree(tree);
}

std::string huffmanCompression::compressString(std::string data)
{
    std::priority_queue<Node*, std::vector<Node*>, priority> q;
    fillQueue(data, q);
    Node* tree = makeTree(q);
    std::string compressedText = compressBitString(textToBits(data, tree)) + "\n`````\n";
    storeTree(tree, compressedText);
    return compressedText;
}

std::string huffmanCompression::decompressString(std::string compressedText)
{
    std::string data, temp;
    int i;
    for (i = 0; i < compressedText.length() - 5; i++)
    {
        if (compressedText.substr(i, 5) == "`````")
        {
            break;
        }
        data += compressedText[i];
    }
    compressedText.erase(0, data.size() + 6);

    Node* tree = new Node("");

    for (int i = 0; i < compressedText.size(); i++)
    {
        if (compressedText[i] != '`')
        {
            temp += compressedText[i];
        }
        else
        {
            recreateTree(tree, temp[0], temp.substr(2, temp.size() - 2));
            temp = "";
            i++;
        }
    }
    std::string decompressed = bitsToText(uncompressBitString(data), tree);
    return decompressed;
}