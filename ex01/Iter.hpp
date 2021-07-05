#ifndef ITER_HPP
# define ITER_HPP

template <typename TArr>
void	Iter(TArr  arr[], int const & len, void fun(TArr *)) {
	for (int i = 0; i < len; i++)
		fun(&arr[i]);
}

#endif /********************************************************** ITER_HPP*/