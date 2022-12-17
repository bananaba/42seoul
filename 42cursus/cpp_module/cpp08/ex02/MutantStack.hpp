#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {}
        MutantStack(MutantStack const & other): std::stack<T>(other) {}
        ~MutantStack() {}

        MutantStack & operator=(MutantStack const & obj) {
            if (obj != *this)
			{
                std::stack<T>::operator=(obj);
            }
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

        iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}

		reverse_iterator rbegin() {
			return this->c.rbegin();
		}
		reverse_iterator rend() {
			return this->c.rend();
		}

		const_iterator cbegin() const {
			return this->c.cbegin();
		}
		const_iterator cend() const {
			return this->c.cend();
		}

		const_reverse_iterator crbegin() const {
			return this->c.crbegin();
		}
		const_reverse_iterator crend() const {
			return this->c.crend();
		}
};

#endif /* ***************************************************** MUTANTSTACK_H */