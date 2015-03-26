#ifndef HUFFMANTREE_H


//based on http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
#define HUFFMANTREE_H
#include<queue>
#include<deque>
#include<map>
#include<string>
#include <fstream>
using namespace std;
// x00102013
class BinNode{
	friend class BinHeap;
	friend class CompareBinNode;
public:
	BinNode();
	BinNode(const BinNode&);
	BinNode(char, int);
	BinNode(BinNode *lft, BinNode *rgt, BinNode *parent);
private:
	char data;
	int freq;
	BinNode *root;
	BinNode *left;
	BinNode *right;
};

class CompareBinNode{
public:
	bool operator()(BinNode& n1, BinNode& n2);
};

class BinHeap{
	
public :
	BinHeap();
	void buildHeap();
	void buildFreqTable();
	void preOrderTraversal();
	void preOrderTraversal(BinNode*, string); // gets huffman codes - recursive O(logn)
	void getMessageToEncode();
	void writeHuffCodeToFile();
	void decodeHuffCode();
	void BinHeap::decodeHuffCode(BinNode *, string direction);
	
private:
	BinNode *root;
	std::priority_queue<BinNode, vector<BinNode>,CompareBinNode > heap;
	map<char, int> freqMap; // get letters and frequency
	map<char, string> huffMap; // contains codes for each letter in tree
	ofstream decodedMessage;
	string message;
	string code;



};


class Huff{
public:
	Huff();
	
	

private:

};



#endif // !HUFFMANTREE_H
