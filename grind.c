// Sean Szumlanski
// COP 3502, Fall 2020

// grind.c
// =======
// This can be used as a framework to check actual runtimes for any functions
// you write. We call the grind() function several times to ensure that we get
// a good sample of runtimes. If we just call it once, it might look like its
// runtime was zero.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// This sneaky function is O(n^2), not O(n). How can we convert it to an O(n)
// function? How does that affect the actual runtimes printed by this program?
void grind(char *s)
{
	int i, k = 0;
	
	for (i = 0; i < strlen(s); i++)
		// I don't want to print anything here, because that'll produce tons
		// of output and really slow this program down. I'll just do a simple
		// increment.
		k++;
}

int main(void)
{
	int i, length, num_runs;
	
	// clock_t is a datatype defined in time.h.
	clock_t start, end;

	// Our string, to be dynamically allocated.
	char *s = NULL;

	// To store our average runtime per function call.
	double Tn;

	// We'll create our string at runtime so we can run the program with varying
	// input lengths without having to recompile.
	printf("How many characters do you want in your string? ");
	scanf("%d", &length);

	// We'll create our string at runtime so we can experiment with appropriate
	// values as we change the string length. For length = 5k, 10k, or 25k,
	// an appropriate value for num_runs might be in the 10 to 1000 range.
	printf("How many times shall we call the grind() function? ");
	scanf("%d", &num_runs);

	// Create our string.
	s = malloc(sizeof(char) * length);
	if (s == NULL)
	{
		printf("ERROR: Not enough memory in main().\n");
		return 1;
	}
	
	// Initialize string. Notice that position s[length - 1] is initialized to
	// '\0'. By the way, this is a terrible way to test runtimes in general.
	// You'd probably want to generate a bunch of different test cases to pass
	// to a function, just in case that function behaves differently with
	// different inputs of the same size or length. (I happen to know, though
	// that strlen() won't terminate early just because it sees a bunch of i's
	// in a string, so we're safe in this case.)
	for (i = 0; i < length - 1; i++)
		s[i] = 'i';
	s[i] = '\0';
	
	// Call grind() function num_runs number of times; track how long this takes.
	start = clock();
	for (i = 0; i < num_runs; i++)
		grind(s);
	end = clock();
	
	// Print average execution time for each call to the grind() function.
	// (converted to milliseconds). On your system, you might need to multiply
	// this by a greater scalar to get meaningful values to print to the screen.
	Tn = (double)(end - start) / CLOCKS_PER_SEC / num_runs * 1000.0;
	printf("n = %d\n", length);
	printf("T(n) = %0.8fms\n", Tn);
	printf("c = T(n)/(n^2) = %0.8f\n", ((Tn / length) / length));

	// Note: If we have n = 50,000 and we use Tn / (n * n) above, the (n * n)
	// will cause an integer overflow, and our result will be inaccurate.
	// ((Tn / n) / n) is algebraically equivalent to (Tn / (n * n)).

	// Also note: Because the program is about to terminate, we don't really
	// need to worry about freeing s, even though it would still be good
	// practice to do so.

	return 0;
}
