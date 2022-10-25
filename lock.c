#include <stdio.h>
#include <stdlib.h>

int word_check(char *word, char **lock_combo);
int letter_check(char c, char *wheel);
int *find_max(int *, int);
char *lock_gen();

int main()
{
	int i, k, j, T, count;
	char **lock_combo;
	char **word;
	int *arr;
	int *max;

	T = 2;

	arr = malloc(sizeof(int) * T);
	

	for (k = 0; k < T; k++)
	{
		lock_combo = lock_gen;
		
		word = malloc(sizeof(char *) * 4);
		for (i = 0; i < 4; i++)
		{
			word[i] = malloc(sizeof(char) * 4);
		}

	
		word[0] = "word";
		word[1] = "beat";
		word[2] = "love";
		word[3] = "beak";

		count = 0;
		for (i = 0; i < 4; i++)
		{
			j = word_check(word[i], lock_combo);
			if (j == 1)
			{
				count += 1;
			}
		}
		arr[k] = count;
	}

	max = find_max(arr, T);
	printf("%d : %d \n", max[0], max[1]);

	return (0);
}
int word_check(char *word, char **lock_combo)
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		j  = letter_check(word[i], lock_combo[i]);
		if (j == 0)
		{
			return (0);
		}

	}
	return (1);
}
int letter_check(char c, char *wheel)
{
	int i;
	
	for (i = 0; i < 4; i++)
	{
		if (wheel[i] == c)
		{
			return(1);
			break;
		}
	}
	return (0);
}
int* find_max(int *arr, int n)
{
	int *max;
	int i;

	max = malloc(sizeof(int) * 2);
	max[0] = 0;
	max[1] = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max[0])
		{
			max[0] = arr[i];
			max[1] = i;
		}
	}
	return (max);

}
char *lock_gen()
{
	int i, j , k;
	char **lock_combo;

	lock_combo = malloc(sizeof(char *) * 4);
	for(i = 0; i < 4; i++)
	{
		lock_combo[i] = malloc(sizeof(char) * 4);
	}

	lock_combo[0] = "wlbb";
	lock_combo[1] = "ooee";
	lock_combo[2] = "rvaa";
	lock_combo[3] = "detk";

	return (lock_combo);
}
