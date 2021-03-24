#include <stdio.h>

void	lotto(int n, array, size)
{
	array[4] = {1, 2, 3, 4};

	if (n == 3)
		return ;
	lotto(n - 1, array, size);	
}

int	main()
{
	array[size];
	lotto(4, array, size);
	return (0);
}
