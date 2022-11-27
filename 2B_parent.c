#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) 
{
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) 
  {
    if (array[j] <= pivot) 
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
  if (low < high) 
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}


void printArray(int array[], int size) 
{
  for (int i = 0; i < size; ++i) 
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main()
{
    char *myargs [] = {NULL};
    //quick
	    	int n;
		printf("Enter size of array : ");
		scanf("%d",&n);
		int a[n];
		char *c_array[7]={NULL};
		printf("Enter elements of array :\n");
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
  		printf("Unsorted Array\n");
  		printArray(a, n);
  		quickSort(a, 0, n - 1);
  		printf ("Parent(sorting)\n");
  		printArray(a, n);
		for (int i=0; i < n; i++)
    		{   
	    		char c[sizeof(int)];    
			snprintf(c, sizeof(int), "%d", a[i]);
			c_array[i] = malloc(sizeof(c)); 
			strcpy(c_array[i], c);
        	}   
        execve("./child",c_array,myargs); 
}
