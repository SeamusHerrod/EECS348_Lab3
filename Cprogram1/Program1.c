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

/*float movingAvgSales(const float* sales_data)
{
	const char months[12][15]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	const int window = 6;
	for ( int i = 0; i < 12; i++)
	{
		for ( int j = 0; j < 6; j++)
		{
			
		}
	}


}*/


int main()
{
	float* month_sales_data = read_data_from("sales.txt");

	/*for (int i = 0; i < 12; i++)
	{
		printf("%.2f\n", month_sales_data[i]);
	}*/

	printf("Monthly Sales Report for 2022:\n\n");
	
	int monthNum;
	int *month_ptr = &monthNum;
	
	monthlySales(month_sales_data);
	const char months[12][15]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	printf("Sales Summary:\n\n");
	printf("Minimum Sales: %.2f  (%s)\n", minSales(month_sales_data, month_ptr), months[ monthNum ]);
	printf("Maximum Sales: %.2f  (%s)\n", maxSales(month_sales_data, month_ptr), months[ monthNum ]);
	printf("Average Sales: %.2f\n", avgSales(month_sales_data));
	return 0;
}
