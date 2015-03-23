#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include<queue>
// x00102013
class BinNode{

public:
	BinNode(char);
	BinNode(BinNode *lft, BinNode *rgt);

private:
	char data;
	int freq;
	BinNode *left;
	BinNode *right;
};



class Huff{
public :
	Huff();
	void fillQueue(char[], int size);

private:
	std::priority_queue<BinNode> q;
};



#endif // !HUFFMANTREE_H
