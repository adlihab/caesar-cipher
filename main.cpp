#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

const string oldAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int findShift(char c);
string generateNewAlphabet(string oldAlphabet, char c);
string encrypt(string inputWord, int shift);
string decrypt(string inputWord, int shift);

int main(){
	char c;
	string inputWord;
	int shift = 0;
	
	cout <<"Enter which cipher to use (a-Z)."<<endl;
	cin >> c;
	while (true){
		if (!isalpha(c)){
			cout <<"["<< c <<"]" << " is not an alphabet. Please enter alphabets from (A-Z)."<<endl;
		}
		else if (islower(c)){
			c = toupper(c);
			break;
		}
		else {
			break;
		}
		cin >> c;
	}
	cout <<"Enter word to encode."<<endl;
	cin.get(); //remove \n from buffer
	getline(cin,inputWord);

	shift = findShift(c);
	cout <<"Old alphabet: "<<oldAlphabet<<endl;
	cout <<"New alphabet: "<<generateNewAlphabet(oldAlphabet,c)<<endl;
	cout <<"Encoded Text: "<<encrypt(inputWord,shift);
	cout <<"\nDecoded Text: "<<decrypt(encrypt(inputWord,shift),shift);
}
//Returns the index of where the letter is from the original alphabet
int findShift(char c){
	for (int i=0;i<oldAlphabet.length();i++){
		if (c == oldAlphabet[i]){
			return i;
		}
	}
}
string generateNewAlphabet(string oldAlphabet, char c){
	string newAlphabet;
	for (int i=0;i<26;i++){
		newAlphabet += c;
		c = c+1;
		if (c > 'Z'){
			c = 'A';
		}
	}
	return newAlphabet;
}
string encrypt(string inputWord, int shift){
	string result = "";
	for (int i=0;i<inputWord.length();i++){
		if (!isalpha(inputWord[i])){
			result += inputWord[i];
			continue;
		}
		if (isupper(inputWord[i])){
			char c;
			c = inputWord[i]+shift;
			if (c > 'Z'){
				c = char(int(c % 90) + 64);
				result += c;
			} else {result += c;}
		}
		else {
			char c;
			int k = inputWord[i]+shift;
			if (k > 'z'){
				c = char(k % 122 + 96);
				result += c;
			} else {result += char(k);}
		}
	}
	return result;
}
string decrypt(string inputWord, int shift){
	string result = "";
	for (int i=0;i<inputWord.length();i++){
		if (!isalpha(inputWord[i])){
			result += inputWord[i];
			continue;
		}
		if (isupper(inputWord[i])){
			char c = inputWord[i] - shift;
			if (c < 'A'){
				int temp = 65 - int(c);
				c = char(int(91 - temp));
				result += c;
			} else {result += c;}
		}
		else {
			char c = inputWord[i] - shift;
			if (c < 'a'){
				int temp = 97 - int(c);
				c = char(int(123 - temp));
				result += c;
			} else { result += c;}
		}
	}
	return result;
}