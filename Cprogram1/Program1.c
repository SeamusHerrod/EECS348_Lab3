/*
 * Program1.c
 *
 *  Created on: Feb 8, 2023
 *      Author: SeamusHerrod
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float* read_data_from(char *file_name)
{
	const int months = 12;
	float* month_sales_data = (float*)malloc(sizeof(float) * months);

	FILE *openfile = fopen(file_name, "r+");
	if (openfile == NULL)
	{
		printf("error opening file\n");
	}

	for( int i = 0; i < months; i++)
	{
		fscanf(openfile, "%f\n", &month_sales_data[i]);
	}
	return month_sales_data;
}

void monthlySales(const float* sales_data)
{
	char months[12][15]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	printf("Month\t\tSales\n");
	for (int i = 0; i < 12; i++)
	{
		printf("%-9s%15.2f\n", months[i], sales_data[i]);
	}
	printf("\n");

}
float minSales(const float* sales_data, int *month_ptr)
{
	float min = sales_data[0];
	*month_ptr = 0;
	for (int i = 0; i < 12; i++)
	{
		if (sales_data[i] < min)
		{
			min = sales_data[i];	
			*month_ptr = i; 
		}
	}
	return min;
}

float maxSales(const float* sales_data, int *month_ptr)
{
	float max = sales_data[0];
	for (int i = 0; i < 12; i++)
	{
		if (sales_data[i] > max)
		{
			max = sales_data[i];
			*month_ptr = i;
		}
	}
	return max;
}

float avgSales(const float* sales_data)
{
	float avg = 0;
	for (int i = 0; i < 12; i++)
	{
		avg += sales_data[i];
	}
	avg /= 12;
	return avg;
}

void movingAvgSales(const float* sales_data)
{
	const char months[12][15]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	float moving_avg;
	char dash = '-';
	printf("6-Month Moving Average:\n\n");
	for ( int i = 0; i < 7; i++)
	{
		for ( int j = i; j < (i + 6); j++)
		{
			
			moving_avg+= sales_data[j];
			
		}
		moving_avg /= 6;
		printf("%-12s%-2c%-12s$%-10.2f\n", months[i], dash, months[i + 5], moving_avg);
		moving_avg = 0;
	}
	return;
}

void HighLow( const float* sales_data )
{
	const char months[12][15]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	float temp[12];
	float high;
	int monthNum;
	int *month_ptr = &monthNum;

	printf("\nSales Report (Highest - Lowest)\n");
	printf("Month\tSales\n");
	//copy sales_data into temp
	for ( int i = 0; i < 12; i++ )
	{
		temp[ i ] = sales_data[ i ];
	}

	//instead of finding maxSales, it'll be simpler to sort the temp array 
	for ( int i = 0; i < 12; i++ )
	{
		for ( int j = i + 1; j < 12; j++ )
		{
			if ( temp[ i ] < temp[ j ] )
			{
				high = temp[ i ];
				temp[ i ] = temp[ j ];
				temp[ j ] = high;
			}
		}
	}
	
	for ( int i = 0; i < 12; i++ )//loop through temp, 
	{
		float find = temp[ i ];
		for ( int j = 0; j < 12; j++ )//loop through sales_data, if temp[i] == sales_data[j], print month[j]
		{
			//printf("j = %d\n", j);
			if ( find ==  sales_data[ j ])
			{
				//printf("condition met: j = %d\n", j);
				printf("%-12s$%-10.2f\n", months[ j ], temp[ i ]);
			}
		}
	}

	return;
}




int main()
{
	float* month_sales_data = read_data_from("sales.txt");

	/*for (int i = 0; i < 12; i++)
	{
		printf("%.2f\n", month_sales_data[i]);
	}*/

	printf("\nMonthly Sales Report for 2022:\n\n");
	
	int monthNum;
	int *month_ptr = &monthNum;
	
	monthlySales(month_sales_data);
	const char months[12][15]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	printf("Sales Summary:\n\n");
	printf("Minimum Sales: %.2f  (%s)\n", minSales(month_sales_data, month_ptr), months[ monthNum ]);
	printf("Maximum Sales: %.2f  (%s)\n", maxSales(month_sales_data, month_ptr), months[ monthNum ]);
	printf("Average Sales: %.2f\n\n", avgSales(month_sales_data));
	movingAvgSales(month_sales_data);
	HighLow(month_sales_data);
	return 0;
}
