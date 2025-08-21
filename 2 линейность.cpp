/* Во входном файле задана функция вектором своих значений.Выяснить линейна ли она*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void xoring(int size, int *value , int*arr)
{
	int counter = 1;
	arr[0] = value[0];
	for( int i = 0; i < size; i++ )
	{
		for ( int j = 0; j < size - counter; j++ )
		{
			value[j] = ( value[j] + value[j+1] ) % 2; 
			//if(j==0)printf("%d ",value[0]);
			if ( j == 0  ) arr[i+1] = value[j];
		}
		counter++;
		//printf("\n");
	}	
}
int main(int argc, char* argv[])
{
    FILE* fin,*fout;
	fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    
    if (fin && fout)
    {
    	int n, k;
    	fscanf(fin, "%d", &k);
    	fscanf(fin, "%d ", &n);
    	
    	int size = 1;
    	for( int i= 0; i < n; i++ ) size = size * 2;
    	int *value = ( int* )malloc( size * sizeof(int) );
    	
    	for ( int i = 0; i < size; i++ ) fscanf( fin, "%1d", &value[i] );
    	//for ( int i = 0; i < size; i++ ) fprintf( fout, "%d ", value[i] );
		
		int *arr =  ( int* )malloc( size * sizeof( int ) );
		xoring(size, value, arr);
		//for ( int i = 0; i < size; i++ ) fprintf( fout, "%d ", arr[i] );
		int counter = 0, counter_all = 0;
		for( int i = 0; i < size; i++ )
		{ 
			counter_all = counter_all + arr[i];
			if(  i == 1 || i == 2 || i == 4 || i % 8 == 0 ) counter = counter + arr[i]; 
		}
		if(counter == counter_all) fprintf( fout, "1" );
		else fprintf( fout, "0" );
    }
    return 0;
}





