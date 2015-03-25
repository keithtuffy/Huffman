#ifndef HUFFMANTREE_H


//based on http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
#define HUFFMANTREE_H
#include<queue>
#include<deque>
#include<map>
#include<string>
using namespace std;
// x00102013
class BinNode{
	friend class BinHeap;
	friend class CompareBinNode;
public:
	BinNode();
	BinNode(char, int);
	BinNode(BinNode *lft, BinNode *rgt);
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
	void buildFreqTable(string phrase);
	void preOrderTraversal();
	
private:
	BinNode *root;
	std::priority_queue<BinNode, vector<BinNode>,CompareBinNode > heap;
	map<char, int> freqMap; // get letters and frequency


};


class Huff{
public:
	Huff();
	
	

private:

};



#endif // !HUFFMANTREE_H
