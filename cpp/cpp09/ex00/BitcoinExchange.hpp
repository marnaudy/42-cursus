#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, float> _rates;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	//Conversion
	void loadData(std::string fileName);
	void addExchangeRate(std::string &line);
	void addExchangeRate(std::string &date, float rate);
	void convert(std::string fileName);
	void printConversion(std::string &line);
	void printConversion(std::string &date, float amount);
	float getValue(std::string &date, float amount);
	float getExchangeRate(std::string &date);

	//Validation
	void checkValidDate(std::string &date);
	bool isValidFloat(std::string &str);
	void checkValidAmount(float amount);
	void checkValidRate(float rate);

	//Exception
	class BitcoinExchangeException : public std::exception {
	public:
		BitcoinExchangeException(std::string message);
		virtual ~BitcoinExchangeException() throw();
		virtual const char *what() const throw();
	private:
		std::string _message;
	};
};

#endif
