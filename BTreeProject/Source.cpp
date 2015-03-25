#include "HuffmanTree.h"
#include<string>
#include <iostream>
#include <map>
using namespace std;


int main(){
	BinHeap test;
	test.buildFreqTable("hello there how are youaaaaaaa");
	test.buildHeap();
	system("pause");
	return 0;
	
}