#ifndef UNIT_HPP
# define UNIT_HPP

# include <iostream>
# include <string>

class Unit
{

	public:
		// Constructors
		Unit( std::string const & name ) : _name(name) {}
		Unit( Unit const & src ) { *this = src; }
		
		// Destructor
		~Unit() {}

		// Overload
		Unit &		operator=( Unit const & rhs ) {
			if (this != &rhs)
				_name = rhs._name;
			return *this;
		}

		// Getters
		std::string	getName( void ) const {
			return (_name);
		}

	private:
		Unit( void ) {}
		std::string _name;
};

std::ostream &			operator<<( std::ostream & o, Unit const & i ) {
	o << i.getName() << std::endl;
	return (o);
}

#endif /* ************************************************************ UNIT_H */