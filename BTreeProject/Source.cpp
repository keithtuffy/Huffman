#include "HuffmanTree.h"
#include<string>
#include <iostream>
#include <map>

using namespace std;


int main(){
	BinHeap test;
	test.getMessageToEncode();
	test.buildFreqTable();
	test.buildHeap();
	test.preOrderTraversal();
	test.writeHuffCodeToFile();
	test.decodeHuffCode();
	test.compressCode();
	system("pause");
	return 0;
	
}