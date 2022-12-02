#ifndef DATA_HPP
#	define DATA_HPP

class Data {
private:
	int _a;
public:
	Data();
	Data(const Data &other);
	Data &operator=(const Data &rhs);
	~Data();
};

#endif
