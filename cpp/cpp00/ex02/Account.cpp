#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
	return (_totalAmount);
}

int Account::getNbDeposits() {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void printIndexAmount(int index, int amount) {
	std::cout << " index:" << index << ";amount:" << amount << ";";
}

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	printIndexAmount(_accountIndex, _amount);
	std::cout << "created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	printIndexAmount(_accountIndex, _amount);
	std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount() const {
	return (_amount);
}

void Account::displayStatus() const {
	_displayTimestamp();
	printIndexAmount(_accountIndex, _amount);
	std::cout << "deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
	std::time_t time = std::time(NULL);
	std::tm *l_time = localtime(&time);
	std::cout << '[' << l_time->tm_year + 1900;
	if (l_time->tm_mon < 10)
		std::cout << '0';
	std::cout << l_time->tm_mon + 1;
	if (l_time->tm_mday < 10)
		std::cout << '0';
	std::cout << l_time->tm_mday << '_';
	if (l_time->tm_hour < 10)
		std::cout << '0';
	std::cout << l_time->tm_hour;
	if (l_time->tm_min < 10)
		std::cout << '0';
	std::cout << l_time->tm_min;
	if (l_time->tm_sec < 10)
		std::cout << '0';
	std::cout << l_time->tm_sec << ']';
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
