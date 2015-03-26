#include "HuffmanTree.h"
#include<iostream>

using namespace std;

BinNode::BinNode(){}

BinNode::BinNode(const BinNode& rhs){
	if (rhs.left != NULL){
		left = new BinNode();
		left = rhs.left;
	}
	if (rhs.right != NULL){
		right = new BinNode();
		right = rhs.right;
	}
	data = rhs.data;
	freq = rhs.freq;
	root = rhs.root;

}


BinNode::BinNode(char dataToAdd, int frequency){
	data = dataToAdd;
	freq = frequency;
	left = right = root = NULL;
}

BinNode::BinNode(BinNode *lft, BinNode *rgt,BinNode *parent){
	data = NULL;
	root = parent;
	left = lft;
	right = rgt;
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


	//pointer problem

	while (heap.size() > 1){
		BinNode *lft =new BinNode(heap.top());
		heap.pop();
		BinNode *rgt = new BinNode(heap.top());
		heap.pop();
		BinNode *newInsert = new BinNode(lft, rgt, root);
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
		cout << "Tree is Empty" << endl;
	}
	else{
		cout << "here"<<endl;
		preOrderTraversal(root, "");

		// test data went into freq map
		map<char, string> ::iterator p;

		cout << "Test huff Map" << endl;
		for (p = huffMap.begin(); p != huffMap.end(); p++)
		{
			cout << p->first << p->second<<endl;
		}
		cout << endl;
		
	}
}

void BinHeap::preOrderTraversal(BinNode *ptr, string huffcode){
	if (ptr !=NULL)
	{
		if (ptr->data == NULL){
			
			preOrderTraversal(ptr->left, huffcode + "0");
			preOrderTraversal(ptr->right, huffcode+ "1");
		}
		else
		{
			huffMap.insert(pair<char, string>(ptr->data, huffcode));
		}

	}

}