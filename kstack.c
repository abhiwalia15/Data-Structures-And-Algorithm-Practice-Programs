#include<stdio.h>
#include<conio.h>
/*The header stdbool.h in the C Standard Library is used for boolean type*/
#include<stdbool.h>
#include<stdlib.h>

/*All global variables with global scope*/

int *arr;   /* Array of size n to store actual content to be stored in stacks*/
int *top;   /* Array of size k to store indexes of top elements of stacks */
int *next;  /* Array of size n to store next entry in all stacks
                and free list*/
int i, n, k;
int fre,size; /* To store beginning index of free list */


/* A utility function to check if there is space available*/
bool isFull()
{
	return (fre == -1);
}

/* To push an item in stack number 'sn' where sn is from 0 to k-1*/
void push(int item, int sn);

/* To pop an item from stack number 'sn' where sn is from 0 to k-1*/
int pop(int sn);

/* To check whether stack number 'sn' is empty or not*/
bool isEmpty(int sn)  {
	 return (top[sn] == -1);
	  }


/*function to create K stacks with an array of size n*/
void CreatekStacks(int k1, int n1);

/*function to traverse the stack*/
void traverseStack(int sn);


int main()
{

	/* Let us create 3 stacks in an array of size 10*/
	    int k = 3, n = 12;

	    /*creating 3 stacks each with size 10*/
	    CreatekStacks(k, n);

	    /* Let us put some items in stack number 0*/
    	push(15,0);
    	push(19,0);
        push(20,0);
        push(15,0);

	    /* Let us put some items in stack number 1*/
   	    push(15, 1);
    	push(23, 1);
    	push(40, 1);
    	push(19, 1);

    	/* Let us put some items in stack number 2*/
   	    push(15, 2);
    	push(23, 2);
    	push(1, 2);
    	push(44, 2);

        printf("Popped element from stack 0 is %d\n",pop(0));
	    printf("Popped element from stack 1 is %d\n",pop(1));
	    printf("Popped element from stack 1 is %d\n",pop(1));
	    printf("Popped element from stack 2 is %d\n",pop(2));
	    printf("\n");

	    traverseStack(2);


	return 0;
}


void CreatekStacks(int k1, int n1)
{
    /* Initialize n and k, and allocate memory for all arrays*/
    k = k1, n = n1;

    /*creating and allocating memory dynamically for the 3 arrays */
    arr = (int*) malloc( n * sizeof(int));
    top = (int*) malloc(k * sizeof(int));
    next = (int*) malloc( n * sizeof(int));

    /* Initialize all stacks as empty*/
    for ( i = 0; i < k; i++)
        top[i] = -1;

    /* Initialize all spaces as free*/
    fre = 0;

    for (i=0; i<n-1; i++)
        next[i] = i+1;
    next[n-1] = -1;  /* -1 is used to indicate end of free list*/
}


/*function to push an item on top of stack*/
void push(int item, int sn)
{
    /* Overflow check*/
    if (isFull())
    {
        printf("\nThe Stack is full!\n");
        return;
    }

    i = fre;      /* Store index of first free slot*/

    /* Update index of free slot to index of next slot in free list*/
    fre = next[i];

    /* Update next of top and then top for stack number 'sn'*/
    next[i] = top[sn];
    top[sn] = i;

    /* Put the item in array*/
    arr[i] = item;
}


/*function to pop an item from stack*/
int pop(int sn)
{
    /* Underflow check*/
    if (isEmpty(sn))
    {
         printf("\nThe stack is empty!\n") ;
         return ;
    }


    /* Find index of top item in stack number 'sn'*/
    i = top[sn];

    top[sn] = next[i];  /* Change top to store next of previous top

    /* Attach the previous top to the beginning of free list*/
    next[i] = fre;
    fre = i;

    /* Return the previous top item*/
    return arr[i];
}


void traverseStack(int sn)
{
    if (isEmpty(sn))
    {
         printf("\nStack is Empty!!\n");
    }

     /* displaying the list*/
    printf("ARRAY LIST-->>\n");
    printf("\n");
    i = 0 ;
    while(i <= top[sn]+1)
    {
    	printf("%d\n",arr[i]);
    	i++;
    }


}
