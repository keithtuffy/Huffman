// student number - x00102013

#include "HuffmanTree.h"
#include<string>
#include <iostream>
#include <map>

using namespace std;


int main(){

	cout << "                 Huffman Tree - x00102013" << endl << "                 -----------------------" << endl<<endl;
	BinHeap test;
	test.getMessageToEncode();
	test.buildFreqTable();
	test.buildHeap();
	test.preOrderTraversal();
	test.writeHuffCodeToFile();
	test.decodeHuffCode();
	test.compressCode();
	test.decompressCode();
	system("pause");
	return 0;
	
}