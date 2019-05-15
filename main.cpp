#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

string changeB(string str);
string changeM(string str);
string changeA(string str);

string checkAll(string str);

string changeB(string str) {
	if (str == "bin" || str == "Bin" || str == "b") {
		str = "";
	}
	else if (str == "binti" || str == "Binti" || str == "bt") {
		str = "";
	}

	return str;
}

string changeM(string str) {
	if (str == "Mohamad" || str == "Mohamed" || str == "Muhamad" || str == "Muhammad" 
		|| str == "Muhd" || str == "Mohd" || str == "Md") {
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

string checkAll(string str) {
	str = changeB(str);
	str = changeM(str);
	str = changeA(str);

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
				string str2;

				for (auto it : str) {
					if (!(('A' <= it && it <= 'Z') || ('a' <= it && it <= 'z'))) {
						continue;
					}
					else {
						str2 += it;
					}
				}
				str2 = checkAll(str2);

				if (str[0] != '(' && str2 != "") {
					fout << str2 << " ";
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
