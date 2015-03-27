#include "HuffmanTree.h"
#include<iostream>
#include <fstream>
#include<sstream>
#include<cmath>
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
void BinHeap::buildFreqTable(){

	for (int i = 0; i < message.length(); i++)
	{
		// if char doesnt exist, add it to map
		if (freqMap.find(message[i]) == freqMap.end())
		{
			freqMap.insert(pair<char, int>(message[i], 1));
		}
		// if the char does exist, makes its frequency add 1
		else
		{
			freqMap.find(message[i])->second++;
		}
	}


	// test data went into freq map
	map<char, int> ::iterator p;
	
	cout << "Test Freq Map" << endl;
	for (p = freqMap.begin(); p != freqMap.end(); p++)
	{
		cout << p->first << p->second << endl;
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
// this gets each letters huffman code
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

void BinHeap::writeHuffCodeToFile(){
	map<char, string> ::iterator p;
	ofstream huffmanCode;
	huffmanCode.open("huffmanCode.txt");
	
	for (int i = 0; i < message.size(); i++){
		huffmanCode << huffMap.find(message[i])->second;

	}
	huffmanCode.close();
}

void BinHeap::decodeHuffCode(){
	ifstream readHuffCode("huffmanCode.txt");
	// gets the huffman code and puts it into a string
	while (getline(readHuffCode, code)){
		cout << "Huffman Code from file: " <<code << endl << endl;
	}
	readHuffCode.close();

	cout << "Decoded Huffman message: ";
	decodedMessage.open("decodedMessage.txt");
	// traverse the tree, 0 for left and 1 for right untilla leaf is reached
	if (!root){
		cout << " Error: Tree is empty" << endl;
	}
	else
	{
		decodeHuffCode(root, code);
	}
	cout << endl;
	decodedMessage.close();
}

void BinHeap::decodeHuffCode(BinNode *ptr,string direction){
	if (direction.size() != 0 ){
		if (ptr->data == NULL){
			if (direction[0] == '0'){
				direction.erase(direction.begin());
				decodeHuffCode(ptr->left, direction);
			}
			else{
				direction.erase(direction.begin());
				decodeHuffCode(ptr->right, direction);
			}
			
		}
		else if (ptr->data != NULL){
			decodedMessage << ptr->data;
			cout <<ptr->data;
			decodeHuffCode(root, direction);
		}
		
		
	}
	else{
		decodedMessage << ptr->data; // used for last char
		cout << ptr->data; // prints last char
	}
	
	

}
// get message to run program with
void BinHeap::getMessageToEncode(){
	ifstream originalMessage("originalMessage.txt");
	while (getline(originalMessage, message)){
		cout << "Original Message: " << message << endl;
	}
	originalMessage.close();
}





void BinHeap::compressCode(){
	ifstream readHuffCode("huffmanCode.txt"); // take coded message
	ofstream writeCompressCode("compressedCode.txt"); // write compressed message

	string codeToCompress; // coded message put into a string
	getline(readHuffCode, codeToCompress);

	//////////////////loop start
	
	while (codeToCompress.size() > 0){
		string charBinCode; // 8 bit charater code holder
		int intBinCode; // takes the string and makes it an int to hold binary num
		int intDecCode = 0; // holds the decimal num for binary code


		// takes first 8 charaters from the coded message
		if (codeToCompress.size() >= 8){
			for (int j = 0; j < 8; j++){
				charBinCode = charBinCode + codeToCompress[j];
			}
			codeToCompress.erase(0, 8); // erase 8 used chars(1s and 0s)
		}
		// when we reach the end of the codedfile and there is less than 8 chars left
		else {
			for (int j = 0; j < codeToCompress.size(); j++){
				charBinCode = charBinCode + codeToCompress[j];
			}
			codeToCompress.erase(0, codeToCompress.size()); // erase last of used chars(1s and 0s)
		}

		// converts string binary code to an int
		// based on http://www.cplusplus.com/forum/general/13135/
		intBinCode = atoi(charBinCode.c_str());


		//convert binary to decimal
		for (int i = 0; intBinCode > 0; ++i)
		{
			if ((intBinCode % 10) == 1)
				intDecCode += (1 << i);

			intBinCode /= 10;
		}

		// the char is given the value of the letter 
		//that equals to the decimal code passed to it
		unsigned char compressedChar = intDecCode; // unsigned stops minus
		cout << compressedChar << intDecCode<<endl;
		writeCompressCode << compressedChar; // write char to file
	}

	writeCompressCode.close();
	readHuffCode.close();
}

void BinHeap::decompressCode(){
	ifstream readCompressedCode("compressedCode.txt"); // get compressed code
	string compressedCode; // compressed message put into a string
	getline(readCompressedCode, compressedCode);

	string huffcodedMessage;
	cout << compressedCode[0];

		char decCode = compressedCode[0]; // gets the decimal number for the char at each position
		int charCode = decCode;
		//cout << decCode;

		int bin = 0, pos = 1;
		
		//used for positive values 
		if (charCode > 0){
			while (charCode > 0)
			{
				bin = bin + (charCode % 2) * pos;
				charCode = charCode / 2;
				pos *= 10;

			}
			huffcodedMessage = "0";
			ostringstream oss; // append int to string huffcodedmessage
			oss << bin;
			huffcodedMessage += oss.str();
			cout << huffcodedMessage;
		}

		//used for 2's complement when it is a minus 
		else{
			charCode = charCode + 1;
			while (charCode < 0)
			{
				bin = bin + (charCode % 2) * pos;
				charCode = charCode / 2;
				pos *= 10;

			}
			int bintemp = abs(bin);
			string temp = "0";
			ostringstream oss; // append int to string huffcodedmessage
			oss << bintemp;

		}

		


		//while (charCode != 0){
		//	int charBinValue = (charCode % 2);
		//	charCode /= 2;
		//	

		//	ostringstream oss; // append int to string huffcodedmessage
		//	oss << charBinValue;
		//	huffcodedMessage += oss.str();
		//}

	
	cout << huffcodedMessage;
	
}

