#include "HuffmanTree.h"
#include<iostream>

using namespace std;

BinNode::BinNode(){}


BinNode::BinNode(char dataToAdd, int frequency){
	data = dataToAdd;
	freq = frequency;
	left = right = root = NULL;
}

BinNode::BinNode(BinNode *lft, BinNode *rgt,BinNode *parent){
	data = NULL;
	root = parent;
	freq = lft->freq + rgt->freq;

}


BinHeap::BinHeap(){
	
}

// build the binary heap
void BinHeap::buildHeap()
{
	// takes everything from frequency table to priority queue
	map<char, int> ::iterator p;
	for (p = freqMap.begin(); p != freqMap.end(); p++)
	{
		BinNode *newNode = new BinNode(p->first, p->second);
		heap.push(*newNode);
	}
	
	BinNode lft;
	BinNode rgt;

	while (heap.size() > 1){
		lft = heap.top();
		cout << heap.top().data<< endl;
		heap.pop();
		rgt = heap.top();
		cout << heap.top().data << endl;
		heap.pop();
		BinNode *newInsert = new BinNode(&lft, &rgt, root);
		heap.push(*newInsert);
	}
	root = &heap.top(); /// save the root node of the tree
	heap.pop(); // take the tree off the queue

}


// build freqency table
void BinHeap::buildFreqTable(string phrase){

	for (int i = 0; i < phrase.length(); i++)
	{
		// if char doesnt exist, add it to map
		if (freqMap.find(phrase[i]) == freqMap.end())
		{
			freqMap.insert(pair<char, int>(phrase[i], 1));
		}
		// if the char does exist, makes its frequency add 1
		else
		{
			freqMap.find(phrase[i])->second++;
		}
	}


	// test data went into freq map
	map<char, int> ::iterator p;
	
	cout << "Test Freq Map" << endl;
	for (p = freqMap.begin(); p != freqMap.end(); p++)
	{
		cout << p->first << p->second;
	}
	cout  << endl;
}


bool CompareBinNode::operator()(BinNode& n1, BinNode& n2){
	if (n2.freq < n1.freq)
		return true;
	return false;
}

void BinHeap::preOrderTraversal(){
	if (!root){ // if the tree is empty
		cout << "Tree id Empty" << endl;
	}
	else{
		preOrderTraversal(root, NULL);
	}
}

void BinHeap::preOrderTraversal(BinNode *ptr, int huffcode){
	if (ptr)
	{
		if (ptr->data == NULL){
			preOrderTraversal(ptr->left, huffcode);
			preOrderTraversal(ptr->right, huffcode);
		}

	}

}