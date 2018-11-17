#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int s[50],top[50],min[50],max[50];
int ns,size;

void init(void)
{   int i;
   for(i=0;i<50;++i)
      {    s[i]=min[i]=max[i] = 0;
            top[i]=-1;
	 	 }

}

void hero()
{    int i ;

	min[0]= -1;
	max[0] = size -1;
	top[0]=-1;
	for(i=1;i<ns;++i)
	{
		min[i]= min[i-1] + size;
		top[i]  = min [i];
 	} 
 	for(i=1;i<ns;++i)
 	{
 		max[i]= min[i+1];
 		
	 }
    	
}

void push(int ele,int k)
{      int i = k-1; 
       if(top[i]==max[i])
           {printf("Stack no %d is full",k);
           return;
           }
            ++top[i];
        s[top[i]] = ele;
}

void pop(int k)
{    int i = k-1;
      
      if(top[i]==min[i])
      {    printf("\nStack no %d is empty",k);
          return;
	  }
      
      printf("%d from %d is deleted",s[top[i]],k);
       --top[i];
	
	
}
  
  
void display(int k)
{     int i = k-1;
          int  j;
if(top[i]==min[i])
      {    printf("\nStack no %d is empty",k);
          return;
	  }

        printf("\nTHe stack is  : ");
      for(j=min[i]+1;j<=top[i];++j)
      {   printf("  %d",s[j] );
	  }
    	
}        
		  
           



int main() {
	   int ele,ch,skn;
	 init();
	
	printf("\nEnter the number of Stacks");
	scanf("%d",&ns);
	size = 50/ns;
	hero();
	do{
		
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{    case  1:  printf("\nEnter the stack no : ");
						scanf("%d",&skn);
						printf("\nEnter the element : ");
						scanf("%d",&ele);
						push(ele,skn);
						break;
			case 2 :  printf("\nEnter the stack no to pop : ");
			          scanf("%d",&skn);
					  pop(skn);
					  break;
			case 3: printf("\nEnter the stack no to pop : ");
			          scanf("%d",&skn);
					  display(skn);
					  break;
			case 4 : printf("\nProgram Terminating");
			         break;
			default : printf("\nInvalid Entry");
		}
		
	}while(ch!=4);
	
		return 0;
}
		
		
		
		
	


