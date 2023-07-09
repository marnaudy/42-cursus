#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <string>

typedef struct tree_s {
	unsigned int value;
	tree_t *max;
	tree_t *min;
} tree_t;

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &rhs);
	void sort(int argc, char **argv);
	void sort_vector(std::vector<unsigned int> &vec);
	void sort_vector_tree(std::vector<tree_t*> &vec);
	void sort_deque(std::deque<unsigned int> &deq);
	void sort_deque_tree(std::deque<tree_t*> &deq);
	void printVec(std::vector<unsigned int> &vec);

	//Exception
	class MergeException : public std::exception {
	public:
		MergeException(std::string message);
		virtual ~MergeException() throw();
		virtual const char *what() const throw();
	private:
		std::string _message;
	};
};

#endif
