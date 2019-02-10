/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<conio.h>

/*struct sparse to find the given key value in the given sparse matrix.
a struct sparse prog. by MRINAL*/

struct sparse
{
  int r;
  int c;
  int v;
} s[10];

int count = 0;
void
main ()
{
  int i, j, k = 1, m, n, a[20][20], key, flag = 0;


  /*enter the order of matrix and input values.*/
  printf ("Enter the order of the matrix\n");
  scanf ("%d%d", &m, &n);
  printf ("Enter the elements of the matrix\n");

  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  scanf ("%d", &a[i][j]);
	}			/*end for j*/
    }				/*end for i*/

  for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
	{
	  if (a[i][j] != 0)
	    {
	      s[k].r = m;
	      s[k].c = n;
	      s[k].v = a[i][j];
	      k++;
	      /*count is for counting the no. of non-zero values.*/
	      count++;
	    }

	  s[0].r = m;
	  s[0].c = n;
	  s[0].v = count;

	}
    }

  printf ("\nROW\tCO:UMN\tVALUE\n");

  for (i = 1; i <= count; i++)
    printf ("%d\t%d\t%d\n", s[i].r, s[i].c, s[i].v);

  printf ("Enter the key element\n");
  scanf ("%d", &key);

  for (i = 1; i <= count; i++)
    if (key == s[i].v)
      {
	printf ("%d value found at %d row and %d column\n", s[i].v, s[i].r,
		s[i].c);
	flag = 1;
      }
  if (flag == 1)
    printf ("key found\n");
  else
    printf ("Key not found\n");

  getch ();


}
