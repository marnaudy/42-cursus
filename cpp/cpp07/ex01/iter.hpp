#ifndef ITER_HPP
#	define ITER_HPP

#	include <stddef.h>

template <typename T>
void iter(T *array, size_t size, void (*f)(T &)) {
	for (unsigned int i = 0; i < size; i++) {
		(*f)(array[i]);
	}
}

#endif
