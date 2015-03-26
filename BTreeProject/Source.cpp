#include "HuffmanTree.h"
#include<string>
#include <iostream>
#include <map>
using namespace std;


int main(){
	BinHeap test;
	test.buildFreqTable("hello");
	test.buildHeap();
	test.preOrderTraversal();
	test.writeHuffCodeToFile();
	test.decodeHuffCode();
	system("pause");
	return 0;
	
}