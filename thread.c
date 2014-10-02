/*Project 2
	Multi-Threaded Collatz Stopping Time Generator
	Mark Humes, David Hunt
/*

/*Objectives
	Quantize how threads are useful
	Encounter Race Condition
*/

/*The Program
	Produce a list of Collatz sequences (1->N)
	Two command line args
		N - number range
		T - number of threads to computer the results in parallel

	ex: ./mt-collatz 10000 8
		uses 8 threads to compute Collatz numbers
		between 2 and 10,000

	Formula:
		//(.(i) = sub(i))
			  { n         , i=0
	   a.(i)={ 
			  { f(a.(i-1)), i>0

	  		  { n/2       , n is even
		f(n)={ 
			  { 3n+1      , n is odd

	Stopping Time (stime):
		The smallest value for i for which a.(i)==1
	
	Count stime for each Collatz sequence in
		a global array to compute a histogram of 
		stimes across a range of numbers
			x-axis: stopping times
			y-axis: frequency values

	Zero out this array before using

	Thread Tasks:
		Select a number in a specified range
		Compute the Collatz stime
		Records the results in global histogram
			array before it chooses the next
			number that is not yet selected
			by another thread

		Continues until all threads have computed
			stimes up to N

	Print stdout:
		<k=1,...,N>,<freq of Collatz stimes where i = k>

		Each line contains a val k in range of 1 to 1000
			and the corresponding frequency of Collatz
			stimes for i = k
				(Collatz nums tat stop at k, (a.(k)=1))
		
		stderr > time required to produce histogram
			Format:
				N,T,time(s).time(ns)
*/

#include <stdio.h>
#include <pthread.h> //include pthread
#include "thread.h"

int histogram[10000];

int main(int argc, char **argv)
{
	create_threads(atoi(argv[1]),atoi(argv[2]));
	
	return 0;
}

void create_threads(int N, int T)
{
	printf("Creating threads\n");
	//create "T" number of threads to run
	pthread_t thread_h[T];
	int i,ret = 0;
	val newv;
	newv->num=N;
	newv->selected = false;
	for(i=0;i<T;i++)
	{	
		ret = pthread_create(&thread_h[T],0,collatz,(void*)&newV);
		if(ret != 0)
			printf("ERROR");
		pthread_join(thread_h[T], 0);
	}
}

void *collatz(void *num)
{
	int *n = (int*)num;
	int i;
	for(i=0;i<*n;i++)


}