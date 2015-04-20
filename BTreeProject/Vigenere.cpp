// Student Number - x00102013

#include "Vigenere.h"



Vigenere::Vigenere(){}


/***************************************************************************************
*	 Based on:
*    Title: Vigenere encryption
*    Author: arcomber via stackexchange.com
*    Date: 31/3/2015
*    Code version: n/a
*    Availability: http://codereview.stackexchange.com/questions/10894/vigenere-encryption
*
***************************************************************************************/

void Vigenere::decryptCipher(string message, string key){
	string decodedMessage;
	cout << "Secret text" << endl << "----------------------- " << endl << message << endl;
	for (int i = 0, j = 0; i < message.size(); ++i) {
		char ch;
		if (j >= key.length())
			j = 0;

		// used for lower case
		if (message[i] >= 'a' && message[i] <= 'z'){
			ch = ((message[i] - 'a') + 26 - (key[j] - 'a')) % 26;
			decodedMessage += ch + 'a';
			j++;
		} // used for upper case
		else if (message[i] >= 'A' && message[i] <= 'Z'){
			ch = ((message[i] - 'A') + 26 - (key[j] - 'A')) % 26;
			decodedMessage += ch + 'A';
			j++;
		}

		else{
			ch = message[i];  //keeps spaces, commas etc
			decodedMessage += ch;
		}
		
	}
	cout <<endl << "Decoded text" << endl << "----------------------- " << endl << decodedMessage << endl;
}