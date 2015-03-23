#include "HuffmanTree.h"


BinNode::BinNode(char dataToAdd){
	data = dataToAdd;
	freq = 1;
	left = right = NULL;
}

BinNode::BinNode(BinNode *lft, BinNode *rgt){

}


Huff::Huff(){}

void Huff::fillQueue(char letters[], int size)
{
	for (int i = 0; i < size; i++){
		q.push(letters[i]);
	}
}