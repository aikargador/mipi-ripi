#include <unistd.h> // for write
#include <stdio.h> // for perror
#include <limits.h> // for the size PATH_MAX and other Maxs or Mins

//tmp
#include <string.h>

int	main() {
	char	buffer[PATH_MAX];
	
	if (getcwd(buffer, sizeof(buffer)))
		write(1, &buffer, strlen(buffer));  // change strlen into ur own strlen
	else
	{
		perror("getcwd() error");
		return (1);
	}
	write(1, "\n", 1);
	return (0);
}
