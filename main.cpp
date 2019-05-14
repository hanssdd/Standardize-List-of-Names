#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

string changeB(string str);
string changeM(string str);

string changeB(string str) {
	if (str == "bin" || str == "Bin" || str == "b") {
		str = "B";
	}
	else if (str == "binti" || str == "Binti" || str == "bt") {
		str = "Bt";
	}

	return str;
}

string changeM(string str) {
	if (str == "Mohamad" || str == "Mohamed" || str == "Muhamad" || str == "Muhammad" 
		|| str == "Muhd" || str == "Mohd") {
		str = "M";
	}

	return str;
}

string changeA(string str) {

	if (str == "Abdul" || str == "Abd" || str == "Ab") {
		str = "A";
	}

	return str;
}

int main(int argc, char* argv) {

	ifstream fin;
	ofstream fout;
	string str;

	fin.open("isubset.txt");
	fout.open("osubset.txt");

	while (!fin.eof()) {
		for (string line; getline(fin, line);) {
			istringstream iss(line);
			while (iss >> str) {
				str = changeB(str);
				str = changeM(str);
				str = changeA(str);

				if (str[0] != '(') {
					fout << str << " ";
				}
				else {
					continue;
				}
			}
			fout << '\n';

		}
	
		
	}

	fin.close();
	fout.close();

	return 0;
	
}