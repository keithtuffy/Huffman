#include "HuffmanTree.h"
#include<string>
#include <iostream>
#include <map>
using namespace std;


int main(){
	BinHeap test;
	test.buildFreqTable("this is a test message");
	test.buildHeap();
	system("pause");
	return 0;
	
}