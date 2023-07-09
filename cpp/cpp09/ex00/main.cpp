#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	BitcoinExchange bitcoinExchange;
	bitcoinExchange.loadData("data.csv");
	if (argc == 2) {
		bitcoinExchange.convert(argv[1]);
	} else {
		bitcoinExchange.convert("");
	}
}
