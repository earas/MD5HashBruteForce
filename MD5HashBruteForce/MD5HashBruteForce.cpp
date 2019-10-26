#include <iostream>
#include <fstream>
#include "md5.h"
#include <string>

using std::cout; using std::endl;
using namespace std;

const string wantedHash = "52e8b46e62a16485077396c8c70c0c11";
const char words[10] = "words.txt";


void printAllKLengthRec(char set[], string prefix,
	int n, int k)
{

	// Base case: k is 0, 
	// print prefix 
	if (k == 0)
	{

		string generetedHash = md5(prefix);

		if (wantedHash == generetedHash) {
			cout << (prefix) << endl;
			ofstream myfile;
			myfile.open("result.txt");
			myfile << prefix;
			myfile.close();

			exit(0);

		}

		return;
	}

	// One by one add all characters  
	// from set and recursively  
	// call for k equals to k-1 
	for (int i = 0; i < n; i++)
	{
		string newPrefix;

		// Next character of input added 
		newPrefix = prefix + set[i];

		// k is decreased, because  
		// we have added a new character 
		printAllKLengthRec(set, newPrefix, n, k - 1);
	}

}

void printAllKLength(char set[], int k, int n)
{
	printAllKLengthRec(set, "", n, k);
}



void readFile() {

	ifstream file(words);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {

		
			//std::cout << line << "\n";
			string generetedHash = md5(line);
			if (wantedHash == generetedHash) {
				cout << (line) << endl;
				ofstream myfile;
				myfile.open("result.txt");
				myfile << line;
				myfile.close();

				exit(0);

			}

		}
		file.close();



	};
}

int main(int argc, char* argv[])
{

	cout << "15 digit is testing..." << endl;
	char set1[] = { 'a', 'b' ,'c','d', 'e' ,'f','g', 'h' ,'i','j',
		'k' ,'l','m','n','o','p','q' ,'r','s', 't' ,'u','v', 'w',
		'x', 'y' ,'z','1', '2' ,'3','4', '5' ,'6','7','8','9', '0' };

	int size = sizeof(set1) / sizeof(set1[0]);
	
	for (int k = 1; k < 15; k++) {	
		cout << k << " digit is testing..." << endl;
		printAllKLength(set1, k, size);
	}
	
	//readFile();

	return 0;
}