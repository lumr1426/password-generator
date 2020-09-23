/* 
 * Warning!
 * This algorithm is fairly simple and not to be used for important, personal stuff like mail or bank credentials.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned int input(const char *prompt);


int main(void) {
	printf("Warning! This algorithm is fairly simple and not to be used for important, personal stuff like mail or bank credentials.\n\n");

	// to get a different output every time the program is launched
	srand((unsigned)time(NULL));

	unsigned int length = 0;
	const unsigned int min_length = 8;

	// asks for the desired password's length
	length = input("Password length: ");
	// handles invalid input
	if (length == 0) {
		printf("Invalid length. Set to %u by default.\n", min_length);
		length = min_length;
	}

	// allocates the memory needed for the string
	char *password = (char *)malloc(sizeof(char)*(length+1));

	// (considering the ASCII Table) this loop gets a random character between '!' (33) and 'z' (122) for each character of the string
	for (unsigned short int i = 0; i < length; i++)
		password[i] = (rand() % 90) + 33;
	// closes the string
	password[length] = '\0';

	printf("\nYour password is: %s\n\n", password);
	
	// frees the memory allocated before
	free(password);
	return (EXIT_SUCCESS);
}



unsigned int input(const char *prompt) {
	char inputString[30];

	/* keeps repeating if the string is empty */
	do {
		printf("%s", prompt);
		fgets(inputString, sizeof(inputString), stdin);
	} while (inputString[0] == '\n');
	
	/* the fgets() function is safer than scanf() but it also reads the final newline.
	 * The newline is replaced with the '\0' marker to close the string. */
	if (inputString[strlen(inputString) - 1] == '\n')
		inputString[strlen(inputString) - 1] = '\0';

	/* returns the number correspondent to the input. If the string is not a number then atoi() will return 0. */
	return atoi(inputString);
}
