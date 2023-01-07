#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
public :
	//Constructors and destructor
	Array<T>() {
		_array = new T[0]();
		_size = 0;
	}
	Array<T>(unsigned int n) {
		_array = new T[n]();
		_size = n;
	}
	Array<T>(const Array<T> &other) {
		_array = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	}
	~Array<T>() {
		delete[] _array;
	}
	//Operators
	Array<T> &operator=(const Array<T> &rhs) {
		delete[] _array;
		_array = new T[rhs._size];
		_size = rhs._size;
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = rhs._array[i];
		}
	}
	T &operator[](unsigned int n) {
		if (n >= _size) {
			throw std::exception();
		}
		return (_array[n]);
	}
	//Accessors
	unsigned int size() const {
		return (_size);
	}
private :
	unsigned int _size;
	T *_array;
};

#endif
