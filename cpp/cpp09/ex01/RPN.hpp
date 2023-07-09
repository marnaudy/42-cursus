#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <cctype>
#include <cstdlib>
#include <string>

class RPN {
private:
	std::stack<int> _stack;
	bool isOperator(char c);
	void add();
	void subtract();
	void multiply();
	void divide();
public:
	RPN();
	RPN(const RPN &other);
	~RPN();
	RPN &operator=(const RPN &rhs);
	int evaluate(char *str);

	//Exception
	class RpnException : public std::exception {
	public:
		RpnException(std::string message);
		virtual ~RpnException() throw();
		virtual const char *what() const throw();
	private:
		std::string _message;
	};
};

#endif
