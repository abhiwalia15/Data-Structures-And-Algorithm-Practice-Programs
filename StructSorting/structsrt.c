#include<stdio.h>
#include<conio.h>

struct student
 {
 int usn;
    char name[20];
	        int sem;
			 }s[10],temp;

void main( )
 {
   int i,n,j;

 printf("Enter n the number of students\n");
   scanf("%d",&n);

 for(i=0;i<n;i++)
   {
      printf("Enter the %d student details \n",i+1);
	     printf("Enter the USN: ");
		    scanf("%d",&s[i].usn);
			  fflush(stdin);
			    printf("\nEnter the student name: ");
				  scanf("%s",s[i].name);
				   printf("\nEnter the Semester:");
				    scanf("%d",&s[i].sem);
					   }

	 printf("Student before sort :\n");
	   printf("\nUSN\tName\tsemester\n");
	    for(i=0;i<n;i++)
		 printf("%d\t%s\t%d\n",s[i].usn,s[i].name,s[i].sem);
		  for(i=0;i<n-1;i++)
		   {
		      for(j=0;j<n-i-1;j++)
			    if(s[j].usn>s[j+1].usn)
				 {
				     temp= s[j];
					    s[j]=s[j+1];
						   s[j+1] = temp;
						        }

 }

  printf("Student After sort :\n");
    printf("\nUSN\tName\tsem\n");
	 for(i=0;i<n;i++)
	  printf("%d\t%s\t%d\n",s[i].usn,s[i].name,s[i].sem);
	    getch();

		 }
