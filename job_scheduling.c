#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max(a,b) a > b ? a : b

/*
 * comparator takes a void pointer of the object in the 
 * arr / pointer that it is storing. in this case
 * we want to sort the jobs by their end time
 * from least to greatest
 *
 * schedule takes the job array / pointer and the
 * number of jobs
 *
 * a table is created for memoizing the max profit
 * up to that i of n job (inclusive)
 *
 * we initialize the first string to be done, so 
 * we just include its profits
 *
 * for every other job we find the max of including
 * or excluding it. if we exclude it the current
 * table value for the ith job will just be a repeat
 * of table i-1, otherwise if we chooes include it
 * the profit value will be the current job done
 * plus the first previous amount from table whose
 * end time of job does not overlap with start time
 * of current job
 *
 * then just return the last value of the table for
 * max profit during the job scheduling 
 */

typedef struct job job;
struct job
{
	int start, end, profit;
};

int comparator(const void *arg1, const void *arg2)
{
	job *a = *((job**) arg1);
	job *b = *((job**) arg2);
	return a->end > b->end;
}

int schedule(job **arr, int n)
{
	int *table = (int*)malloc(sizeof(int)*n);
	table[0] = arr[0]->profit;
	for(int i = 1; i < n; i++)
	{
		int profit_included = arr[i]->profit;
		for(int j = i-1; j >= 0; j--)
		{
			if(arr[j]->end <= arr[i]->start)
			{
				profit_included += arr[j]->profit;
				break;
			}
		}
		int profit_excluded = table[i-1];
		table[i] = max(profit_included, profit_excluded);
	}
	return table[n-1];
}

int main()
{
	int n;
	scanf("%d", &n);
	job **arr = (job**)malloc(sizeof(job*)*n);
	for(int i = 0; i < n; i++)
	{
		int s, e, p;
		scanf("%d %d %d", &s, &e, &p);
		arr[i] = (job*)malloc(sizeof(job));
		*arr[i] = (job) 
		{
			.start  = s,
			.end    = e,
			.profit = p
		};
	}
	qsort(arr, n, sizeof(job*), comparator);
	printf("sorted joblist:\n");
	for(int i = 0; i < n; i++)
	{
		printf("start: %d end: %d profit: %d\n", arr[i]->start, arr[i]->end, arr[i]->profit);
	}
	printf("max profit: %d\n", schedule(arr, n));
	return 0;
}
