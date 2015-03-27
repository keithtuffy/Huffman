#include "Rot13Encryption.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
Rot13::Rot13(){}

void Rot13::encodeRot13(){
	ifstream readPoem("poem.txt");
	string poem((std::istreambuf_iterator<char>(readPoem)), (std::istreambuf_iterator<char>()));;
	string rot13cypher;

	for (int i = 0; i < poem.size(); ++i) {
		if (isalpha(poem[i])) {
			if ((tolower(poem[i]) - 'a') < 14)
				rot13cypher.append(1, poem[i] + 13);
			else
				rot13cypher.append(1, poem[i] - 13);
		}
		else {
			rot13cypher.append(1, poem[i]);
		}
	}


}