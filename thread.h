typedef int bool;
#define true 1
#define false 0

typedef struct val
{
	int *num;
	bool selected;
}val;

void create_threads(int N, int T);
void *collatz(void *num);