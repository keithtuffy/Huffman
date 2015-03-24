#include "HuffmanTree.h"
#include<iostream>

using namespace std;

BinNode::BinNode(char dataToAdd, int frequency){
	data = dataToAdd;
	freq = frequency;
	left = right = root = NULL;
}

BinNode::BinNode(BinNode *lft, BinNode *rgt){

}


BinHeap::BinHeap(){}

// 
void BinHeap::buildHeap()
{
	map<char, int> ::iterator p;
	for (p = freqMap.begin(); p != freqMap.end(); p++)
	{
		BinNode *newNode = new BinNode(p->first, p->second);
		heap.push(*newNode);
	}
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
	for (p = freqMap.begin(); p != freqMap.end(); p++)
	{
		cout << p->first;
	}
}