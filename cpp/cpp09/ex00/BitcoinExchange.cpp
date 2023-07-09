#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	_rates = other._rates;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	_rates = rhs._rates;
	return (*this);
}


//Conversion

std::string trimWhiteSpace(std::string &str) {
	size_t begin = str.find_first_not_of(" \f\t\n\r\v");
	if (begin == std::string::npos) {
		return ("");
	}
	size_t end = str.find_last_not_of(" \f\t\n\r\v");
	return (str.substr(begin, end - begin + 1));
}

void BitcoinExchange::loadData(std::string fileName) {
	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open()) {
		std::cout << "Error: could not open database." << std::endl;
		return;
	}
	std::string line;
	std::getline(ifs, line);
	while (!ifs.eof()) {
		std::getline(ifs, line);
		if (line.length() > 0) {
			addExchangeRate(line);
		}
	}
}

void BitcoinExchange::addExchangeRate(std::string &line) {
	size_t comma = line.find(',');
	std::string date = line.substr(0, comma);
	std::string rate_str = line.substr(comma + 1);
	date = trimWhiteSpace(date);
	rate_str = trimWhiteSpace(rate_str);
	float rate = atof(rate_str.c_str());
	try {
		if (comma == std::string::npos) {
			throw BitcoinExchangeException("bad database line => " + line);
		}
		if (!isValidFloat(rate_str) && rate >= 0) {
			throw BitcoinExchangeException("bad rate => " + rate_str);
		}
		addExchangeRate(date, rate);
	}
	catch(const std::exception& e) {
		std::cout << "Error in database: " << e.what() << "." << std::endl;
	}
}

void BitcoinExchange::addExchangeRate(std::string &date, float rate) {
	checkValidDate(date);
	checkValidRate(rate);
	_rates.insert(std::pair<std::string, float>(date, rate));
}

void BitcoinExchange::convert(std::string fileName) {
	std::ifstream ifs(fileName.c_str());
	if (!ifs.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	std::getline(ifs, line);
	while (!ifs.eof()) {
		std::getline(ifs, line);
		if (line.length() > 0) {
			printConversion(line);
		}
	}
}

void BitcoinExchange::printConversion(std::string &line) {
	size_t pipe = line.find('|');
	std::string date = line.substr(0, pipe);
	std::string amount_str = line.substr(pipe + 1);
	date = trimWhiteSpace(date);
	amount_str = trimWhiteSpace(amount_str);
	float amount = strtof(amount_str.c_str(), NULL);
	try {
		if (pipe == std::string::npos) {
			throw BitcoinExchangeException("bad input => " + line);
		}
		if (!isValidFloat(amount_str) && amount >= 0) {
			throw BitcoinExchangeException("bad amount => " + amount_str);
		}
		printConversion(date, amount);
	}
	catch(const std::exception& e) {
		std::cout << "Error: " << e.what() << "." << std::endl;
	}
}

void BitcoinExchange::printConversion(std::string &date, float amount) {
	float value = getValue(date, amount);
	std::cout << date << " => " << amount << " = " << value << std::endl;
}

float BitcoinExchange::getValue(std::string &date, float amount) {
	checkValidAmount(amount);
	return (amount * getExchangeRate(date));
}

float BitcoinExchange::getExchangeRate(std::string &date) {
	checkValidDate(date);
	std::map<std::string, float>::iterator it = _rates.find(date);
	if (it != _rates.end()) {
		return (it->second);
	}
	it = _rates.lower_bound(date);
	if (it == _rates.begin()) {
		throw BitcoinExchangeException("no exchange rate for " + date);
	}
	it--;
	return (it->second);
}

//Validation
bool isLeapYear(unsigned int year) {
	return ((year % 4 == 0) && (!(year % 100 == 0) || (year % 400 == 0)));
}

unsigned int daysInMonth(unsigned int year, unsigned int month) {
	if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
		return (30);
	}
	if (month == 2) {
		return (isLeapYear(year) ? 29 : 28);
	}
	return (31);
}

bool isNumerical(std::string &str) {
	return (str.find_first_not_of("0123456789") == std::string::npos);
}

void BitcoinExchange::checkValidDate(std::string &date) {
	std::string year, month, day;
	size_t hyphen1, hyphen2;
	int year_i = 0;
	int month_i = 0;
	int day_i = 0;

	hyphen1 = date.find_first_of('-');
	hyphen2 = date.find_first_of('-', hyphen1 + 1);
	if (hyphen1 != std::string::npos && hyphen2 != std::string::npos) {
		year = date.substr(0, hyphen1);
		month = date.substr(hyphen1 + 1, hyphen2 - hyphen1 - 1);
		day = date.substr(hyphen2 + 1);
	}
	if (isNumerical(year) && isNumerical(month) && isNumerical(day)
		&& (month.length() == 2) && (day.length() == 2)) {
		year_i = atoi(year.c_str());
		month_i = atoi(month.c_str());
		day_i = atoi(day.c_str());
	}
	if ((year_i > 0) && (month_i > 0)  && (month_i < 13) && (day_i > 0)
		&& ((unsigned int) day_i <= daysInMonth((unsigned int) year_i, (unsigned int) month_i))) {
		return;
	}
	throw BitcoinExchangeException("bad date => " + date);
}

bool BitcoinExchange::isValidFloat(std::string &str) {
	size_t decimalPos = str.find('.');
	std::string whole_str = str.substr(0, decimalPos);
	if (decimalPos == std::string::npos) {
		return (isNumerical(whole_str));
	}
	std::string decimal_str = str.substr(decimalPos + 1);
	return (isNumerical(whole_str) && isNumerical(decimal_str));
}

void BitcoinExchange::checkValidAmount(float amount) {
	if (amount < 0) {
		throw BitcoinExchangeException("not a positive number");
	}
	if (amount > 1000) {
		throw BitcoinExchangeException("too large a number");
	}
}

void BitcoinExchange::checkValidRate(float rate) {
	if (rate < 0) {
		throw BitcoinExchangeException("negative rate");
	}
}

BitcoinExchange::BitcoinExchangeException::BitcoinExchangeException(std::string message) : _message(message) {}

BitcoinExchange::BitcoinExchangeException::~BitcoinExchangeException() throw() {}

const char *BitcoinExchange::BitcoinExchangeException::what() const throw() {
	return (_message.c_str());
}

