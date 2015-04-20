// student number - x00102013

#include "HuffmanTree.h"
#include "Rot13Encryption.h"
#include "Vigenere.h"
#include<string>
#include <iostream>
#include <fstream>
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
	

	cout <<  endl << endl << "                 Rot13 Encryption - x00102013" << endl << "                 -----------------------" << endl << endl;
	Rot13 rot13Test;
	rot13Test.encodeRot13();
	rot13Test.decodeRot13();

	cout << endl << endl << "                 Vigenere secret.txt - x00102013" << endl << "                 -----------------------" << endl << endl;
	ifstream readSecret("secret71.txt");
	string secret((std::istreambuf_iterator<char>(readSecret)), (std::istreambuf_iterator<char>()));
	readSecret.close();
	Vigenere vig;
	string key;
	cout << "Please enter a key - (key is 'beatles' for secret71.txt)" << endl;
	cin >> key;
	vig.decryptCipher(secret, key);

	
	system("pause");
	return 0;
	
}