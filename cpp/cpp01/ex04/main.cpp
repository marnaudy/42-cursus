#include <string>
#include <fstream>
#include <iostream>

void replace(std::ifstream &ifs, std::ofstream &ofs, std::string s1, std::string s2) {
	std::string str;
	std::string big_str;
	do {
		std::getline(ifs, str);
		if (!str.empty()) {
			big_str += str;
			big_str += "\n";
		}
	} while (str.length());
	unsigned int pos = 0;
	while (big_str.find(s1, pos) != big_str.npos) {
		pos = big_str.find(s1, pos);
		big_str.erase(pos, s1.length());
		big_str.insert(pos, s2);
		pos += s2.length();
	}
	ofs << big_str;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Wrong number of parameters" << std::endl;
		return (1);
	}
	std::string infile(argv[1]);
	std::string outfile = infile + ".replace";
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	if (s1.length() == 0) {
		std::cout << "First string cannot be empty" << std::endl;
		return (1);
	}
	std::ifstream ifs(infile.c_str());
	ifs.seekg(0, std::ios::end);
	if (!ifs.good() || ifs.bad() || !ifs.is_open()) {
		std::cout << "Can't open " << infile << std::endl;
		return (1);
	}
	ifs.seekg(0, std::ios::beg);
	std::ofstream ofs(outfile.c_str());
	if (!ofs) {
		std::cout << "Can't open " << outfile << std::endl;
		ifs.close();
		return (1);
	}
	replace(ifs, ofs, s1, s2);
	ifs.close();
	ofs.close();
}
