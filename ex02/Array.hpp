#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{

public:
	//-> Constructors
	Array(void) : _size(0)
	{
		_array = new T[0];
	}

	Array(unsigned int const &n) : _size(n)
	{
		_array = new T[n];
	}

	Array(const Array &src)
	{
		*this = src;
	}

	//-> Destructor
	~Array() {}

	//-> Overloads
	Array<T> &operator=(Array<T> const &rhs)
	{
		if (this != &rhs)
		{
			this->_size = rhs._size;
		}
		return *this;
	}

	T &operator[](int i)
	{
		if (i >= _size || i < 0)
			throw out_of_range;
		return (_array[i]);
	}

	T operator[](int i) const
	{
		if (i >= _size || i < 0)
			throw out_of_range;
		return (_array[i]);
	}

	//->Getters
	int size(void) const
	{
		return (_size);
	}

	//-> Exceptions
	class OutOfRange : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("This index is out of range");
		};
	} out_of_range;

private:
	int _size;
	T *_array;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &arr)
{
	o << "{";
	for (int i = 0; i < arr.size(); i++)
	{
		o << arr[i];
		if (i < arr.size() - 1)
			o << ", ";
	}
	o << "}";
	return o;
}

#endif /* *********************************************************** ARRAY_H */