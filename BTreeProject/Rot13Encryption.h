#ifndef Rot13Encryption_h
#define Rot13Encryption_h

class Rot13{
public:
	Rot13();
	void encodeRot13();
	void decodeRot13();


private:
	string lcase = "abcdefghijklmnopqrstuvwxyz";
	string ucase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};


#endif // !Rot13Encryption_h
