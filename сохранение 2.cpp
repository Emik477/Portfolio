/*
Во входном файле задан полином. 
Найти все одноэлементные множества, которые он сохраняет. 
Каждое множество записать в выходной файл в виде одного числа (числа разделены пробелом), предварительно упорядочить. 
Количество множеств не печатать.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char* argv[] )
{
	FILE* fin,*fout;
	fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    
    if (fin && fout)
    {
    	int k, n, m;
    	fscanf(fin,"%d %d %d\n", &k, &n, &m);
    	n++;
    	int **arr = (int**) malloc (sizeof (int*) * m);
    	
    	for ( int i = 0; i < m; i++ ) 
		{
        	arr [i] = (int*) malloc (sizeof (int) * n);
		}
		
    	for( int i = 0; i < m; i++ )
    	{
    		for( int j = 0; j < n; j++ )
    		{
    			if( j == n - 1 ) fscanf( fin, "%1d \n", &arr[i][j] );
    			else fscanf( fin, "%1d", &arr[i][j] );
			}
		}
		
		int sum = 1, total_sum = 0, powerg = 0, num = 0, remainder = 0;
		
		for(int temp = 0; temp < k; temp++) 
		{
			total_sum = 0;
			for(int i = 0; i < m; i++)
			{
				sum = 1;
				for(int j = 0; j < n; j++)
				{
					num = temp;
					if( j == n - 1 ) sum = sum * arr[i][j];
					else if( arr[i][j] == 0 ) 
					{
						num = 1;
						sum = sum * num;
					}
					else
					{
						powerg = arr[i][j];
						while( powerg > 1 )
						{
							num = num * num;
							powerg--;
						}
						sum = sum * num;
					}
					//printf(" %d ", sum);	
				}
				total_sum = total_sum + sum;
			}
			//printf("%d",total_sum);
			num = temp;
			if ( total_sum >= k && num != 0 ) remainder = total_sum % k;
			
			if( remainder == temp && remainder > 0 ) fprintf(fout,"%d\n", num);
			else if( total_sum == temp ) fprintf(fout,"%d\n", num);
		}		
	}
	return 0;
}
