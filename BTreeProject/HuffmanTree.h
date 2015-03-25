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
public:
	BinNode();
	BinNode(char, int);
	BinNode(BinNode *lft, BinNode *rgt);
	bool operator <(const BinNode &rhs)const;
private:
	char data;
	int freq;
	BinNode *root;
	BinNode *left;
	BinNode *right;
};



class BinHeap{
	
public :
	BinHeap();
	void buildHeap();
	void buildFreqTable(string phrase);
	
private:
	BinNode *root;
	std::priority_queue<BinNode> heap;
	map<char, int> freqMap; // get letters and frequency


};


class Huff{
public:
	Huff();
	
	

private:

};



#endif // !HUFFMANTREE_H
