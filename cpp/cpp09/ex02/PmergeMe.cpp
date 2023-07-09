#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	(void) other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	return (*this);
}

void PmergeMe::sort(int argc, char **argv) {
	std::vector<unsigned int> vec;
	std::deque<unsigned int> deq;
	for (int i = 1; i < argc; i++) {
		int j = atoi(argv[i]);
		if (j < 0) {
			throw MergeException("negative number");
		}
		std::string str(argv[i]);
		if (str.find_first_not_of("0123456789") != std::string::npos) {
			throw MergeException("invalid number");
		}
		if (find(vec.begin(), vec.end(), j) != vec.end()) {
			throw MergeException("duplicate element");
		}
		vec.push_back(j);
		deq.push_back(j);
	}
	std::cout << "Before:  ";
	printVec(vec);
	sort_vector(vec);
	sort_deque(deq);
	std::cout << "After:   ";
	printVec(vec);
}

void PmergeMe::sort_vector(std::vector<unsigned int> &vec) {
	std::vector<tree_t*> tree_vec;
	for (int i = 0; i < vec.size(); i++) {
		tree_t *new_tree = new tree_t;
		new_tree->value = vec[i];
		new_tree->max = NULL;
		new_tree->min = NULL;
		tree_vec.push_back(new_tree);
	}
	sort_vector_tree(tree_vec);
	for (int i = 0; i < tree_vec.size(); i++) {
		vec[i] = tree_vec[i]->value;
	}
	//ToDo: Free tree_vec
}

void PmergeMe::sort_vector_tree(std::vector<tree_t*> &vec) {
	//ToDo: Check if it's already sorted
	//ToDo: Sort by hand if it is small
	std::vector<tree_t*> pairs;
	for (int i = 0; 2 * i + 1 < vec.size(); i++) {
		tree_t *new_tree = new tree_t;
		if (vec[2 * i]->value > vec[2 * i + 1]->value) {
			new_tree->value = vec[2 * i]->value;
			new_tree->max = vec[2 * i];
			new_tree->min = vec[2 * i + 1];
		} else {
			new_tree->value = vec[2 * i + 1]->value;
			new_tree->max = vec[2 * i + 1];
			new_tree->min = vec[2 * i];
		}
		pairs.push_back(new_tree);
	}
	sort_vector_tree(pairs);
	//ToDo: Recombine pairs into vec
	//ToDo: free pairs
}

void PmergeMe::sort_deque(std::deque<unsigned int> &deq) {
	std::deque<tree_t*> deq_tree;
	for (int i = 0; i < deq.size(); i++) {
		tree_t *new_tree = new tree_t;
		new_tree->value = deq[i];
		new_tree->max = NULL;
		new_tree->min = NULL;
		deq_tree.push_back(new_tree);
	}
	sort_deque_tree(deq_tree);
	for (int i = 0; i < deq_tree.size(); i++) {
		deq[i] = deq_tree[i]->value;
	}
}

void PmergeMe::sort_deque_tree(std::deque<tree_t*> &deq) {

}

void PmergeMe::printVec(std::vector<unsigned int> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}
