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
	int N = argv[1];
	int T = argv[2];

	pthread_t h_thread; //create a thread handle

	//start the thread and save the result
	int n_thread = pthread_create(&h_thread,0,collatz(N,T),0);

	//Validate the result
	if(ret!=0)
	{
		printf("Create thread failed! error: %d",ret);
		return 1;
	}

	//wait until the thread ends
	pthread_join(h_thread, 0);
	return 0;
}

int funct_n(int *n)
{
	if(n%2==1)                //think about this one, it doesn't do what you think it does.
		return n/2;
	else
		return 3*n+1;
	return 0;
}

int funct_ai(int i, int n, int prev)
{
	if(i==0)
		return n;
	else if(i>0)
		return funct_n(prev);
	return 0;
}

int collatz(int N, int T)
{
	int i,n=N;
	histogram[0]=n;
	for(i=1;i<N;i++)
	{
		n=funct_n(n);
		histogram[i] = n;       //think about this assignment
	}
}
