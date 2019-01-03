#include<stdio.h>
#include<conio.h>

void main()

{
  
    int array[20], i, largest1, largest2=0, temp,n;
	float avg;    
 
 
    printf("Enter the integer numbers \n");    
	 scanf("%d",&n);    
	  printf("Enter the array elements \n"); 
	     for (i = 0; i < n; i++)
		       scanf("%d", &array[i]); 
 
    largest1 = array[0];  /*  assume first element of array is the first larges t*/     
	
	for (i = 1; i < n;i++)  
	   {  
	   if (array[i] > largest1) 
	    {
		      largest2 = largest1;
			  largest1 = array[i]; 
					 
					 }
					 
	   else if (array[i] > largest2) 
	   {
	   
	   		 largest2 = array[i];    
}
			  }
			       
		avg = (largest1 + largest2) / 2.0; 
		
        printf("\n%d is the first largest \n", largest1); 
		printf("%d is the second largest \n", largest2);   
	    printf("\nAverage of %d and %d = %f \n", largest1, largest2,avg);
				 
    getch(); 
	 
}
