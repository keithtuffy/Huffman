// Student Number - x00102013 

#include "Rot13Encryption.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
Rot13::Rot13(){}

/***************************************************************************************
*	 Based on:
*    Title: [C++] ROT-13 string encoder tutorial (beginner to intermediate)
*    Author: Nobel via facepunch.com
*    Date: 31/3/2015
*    Code version: n/a
*    Availability: http://facepunch.com/showthread.php?t=1094693
*
***************************************************************************************/

void Rot13::encodeRot13(){
	ifstream readPoem("poem.txt");
	string poem((std::istreambuf_iterator<char>(readPoem)), (std::istreambuf_iterator<char>()));;
	string rot13cipher;

	cout << "Original Poem" << endl << "----------------------- " << endl << poem << endl << endl;
	for (int i = 0; i < poem.size(); i++){
		
		if (poem[i] >= 'a' && poem[i] <= 'm'){
			rot13cipher +=  poem[i] += 13;
		}

		else if (poem[i] > 'm' && poem[i] <= 'z'){
			rot13cipher += poem[i] -= 13;
		}

		else if (poem[i] >= 'A' && poem[i] <= 'M'){
			rot13cipher += poem[i] += 13;
		}

		else if (poem[i] > 'M' && poem[i] <= 'Z'){
			rot13cipher += poem[i] -= 13;
		}
		else if (poem[i] == ' '){
			rot13cipher += ' ';
		}

	}
	readPoem.close();
	ofstream encrypedPoem("encryptedPoem.txt");
	encrypedPoem << rot13cipher;
	encrypedPoem.close();
	cout <<endl <<  "Encrypted Poem" << endl << "----------------------- " << endl << rot13cipher << endl << endl;


}

// this decode is exactly the same as the encode. it was seperated out to test it worked
void Rot13::decodeRot13(){
	ifstream readRot13("encryptedPoem.txt");
	string secret((std::istreambuf_iterator<char>(readRot13)), (std::istreambuf_iterator<char>()));
	string decrypedMessage;
	cout << "Rot13 code" << endl << "----------------------- " << endl << secret << endl << endl;
	for (int i = 0; i < secret.size(); i++){

		if (secret[i] >= 'a' && secret[i] <= 'm'){
			decrypedMessage += secret[i] += 13;
		}

		else if (secret[i] > 'm' && secret[i] <= 'z'){
			decrypedMessage += secret[i] -= 13;
		}

		else if (secret[i] >= 'A' && secret[i] <= 'M'){
			decrypedMessage += secret[i] += 13;
		}

		else if (secret[i] > 'M' && secret[i] <= 'Z'){
			decrypedMessage += secret[i] -= 13;
		}
		else if (secret[i] == ' '){
			decrypedMessage += ' ';
		}

	}
	readRot13.close();
	cout << "Decrypted Message" << endl << "----------------------- " << endl << decrypedMessage << endl << endl;
}