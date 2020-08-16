#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int input(const char *prompt);


int main(void) {
	printf("Warning! This algorithm is fairly simple and not to be used for important, personal stuff like mail or bank credentials.\n\n");

	/* to get a different output every time the program is launched */
	srand((unsigned)time(NULL));

	int length = 0;
	const int min_len = 8;

	/* asks for the desired password's length */
	length = input("Password length: ");
	/* handles invalid input */
	if (length <= 0) {
		printf("Invalid length. Set to %d by default.\n", min_len);
		length = min_len;
	}

	/* allocates the memory needed for the string */
	char *password = (char *)malloc(sizeof(char)*(length+1));

	/* (considering the ASCII Table) this loop gets a random character between '!' (33) and 'z' (122)
	 * for each spot in the password's string */
	for (unsigned short int i = 0; i < length; i++)
		password[i] = (rand() % 90) + 33;
	/* closes the string */
	password[length] = '\0';

	printf("\nYour password is: %s\n\n", password);
	return (EXIT_SUCCESS);
}



int input(const char *prompt) {
	char inputString[30];

	printf("%s", prompt);
	fgets(inputString, sizeof(inputString), stdin);

	/* the fgets() function is safer than scanf() but it also reads the final newline.
	 * The newline is replaced with the '\0' marker to close the string. */
	if (inputString[strlen(inputString) - 1] == '\n')
		inputString[strlen(inputString) - 1] = '\0';

	/* returns the number correspondent to the input. If the string is not a number atoi() returns 0. */
	return atoi(inputString);
}