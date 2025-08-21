/*
Во входном файле задана ДНФ. 
Найти ДНФ, получающуюся из нее применением всех возможных операций поглощения (конец алгоритма Блейка). 
В выходном файле строки, соответствующие ЭК, должны быть упорядочены лексикографически.
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
    	int n, m;
    	fscanf( fin, "%d %d\n", &n, &m );
    	
    	char **arr = (char**) malloc (sizeof (char*) * m);  
    	
		for ( int i = 0; i < m; i++ ) 
		{
        	arr [i] = (char*) malloc (sizeof (char) * n);
		}
		
    	for( int i = 0; i < m; i++ )
    	{
    		for( int j = 0; j < n; j++ )
    		{
    			if( j == n - 1 ) fscanf( fin, "%c\n", &arr[i][j] );
    			else fscanf( fin, "%c", &arr[i][j] );
			}
		}
		int counter_major = 0, counter_minor = 0, star_major = 0, star_minor = 0, flag = 0, flag_major = 0;
		
		for( int i = 0; i < m; i++ ) 
		{
			flag_major = 0; 
			for( int j = 0; j < m; j++ )
    		{
    			for(int l = 0; l < n; l++)
				{
					if( ( arr[i][l] > arr[j][l] ) && ( arr[j][j] != '*' ) && ( arr[i][j] != '*' )) counter_major++;
					else if( ( arr[i][l] < arr[j][l] ) && ( arr[i][j] != '*' )&& ( arr[j][j] != '*' )) counter_minor++;
					
					if( arr[i][l] == '*' ) star_major++;
					if( arr[j][l] == '*' ) star_minor++;
					if( arr[i][l] == '*' && arr[j][l] == '*' ) flag = 1;
				 }
				
				 if( (counter_major > counter_minor && star_major >= star_minor && flag == 1) || ( counter_major < counter_minor && star_major > star_minor && flag == 1 ) )
				 {
				 	for( int a = j; a < j+1; a++ )
				 	{
				 		for (int b = 0; b < n; b++)
				 		{
				 			arr[a][b] = '#';
						 }
					 }
				 }
				 else if(( counter_major < counter_minor && star_major <= star_minor && flag == 1 ) || ( counter_major > counter_minor && star_major < star_minor && flag == 1 ) )
				 {
				 	flag_major = 1; 
				 	for( int a = i; a < i + 1; a++ )
				 	{
				 		for (int b = 0; b < n; b++)
				 		{
				 			arr[a][b] = '#';
						 }
					 }	
				 }
				 
				 
				 counter_major = 0;
				 counter_minor = 0;
				 star_major = 0;
				 star_minor = 0;
				 flag = 0;
				 if( flag_major == 1) break;
			}
		}
		int a = 0, b = 0;
		
		
		for(int i = 0; i < m; i++ )
		{
			if( arr[i][0] != '#') a++ ;
		}
		
		fprintf( fout, "%d %d\n", n, a );
		
			
		for(int i = 0; i < m; i++ )
		{
			if( arr[i][0] != '#')
			{
			
				for ( int j = 0; j < n; j++)
				{
					fprintf(fout, "%c", arr[i][j] );
				}
				fprintf(fout, "\n");
			}
		}
	}
	return 0;
}
