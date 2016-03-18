

	#include<stdio.h>
	#include<stdlib.h>
	#include<time.h>

	int main ()
	{
		double number, input;
		/* initialize random seed: */
		srand ( time(NULL) );
		/* Generate a random number: */
		number = rand() % 2;
		printf ("%lf \n", number);
		do {
				printf ("Guess the number (1 to 10): ");
				scanf ("%lf",&input);
				if (number > input)
					printf ("The number is higher\n");
			} while (number!=input);
		printf ("That is correct!\n");
		return 0;
	}
