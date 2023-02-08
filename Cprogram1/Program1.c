/*
 * Program1.c
 *
 *  Created on: Feb 8, 2023
 *      Author: SeamusHerrod
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

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
		printf("%-9s%18f\n", months[i], sales_data[i]);
	}
	printf("\n");

}
float minSales(const float* sales_data)
{
	float min = sales_data[0];
	for (int i = 0; i < 12; i++)
	{
		if (sales_data[i] < min)
		{
			min = sales_data[i];
		}
	}
	return min;
}

float maxSales(const float* sales_data)
{
	float max = sales_data[0];
	for (int i = 0; i < 12; i++)
	{
		if (sales_data[i] > max)
		{
			max = sales_data[i];
		}
	}
	return max;
}



int main()
{
	float* month_sales_data = read_data_from("sales.txt");

	/*for (int i = 0; i < 12; i++)
	{
		printf("%.2f\n", month_sales_data[i]);
	}*/

	printf("Monthly Sales Report for 2022:\n\n");

	monthlySales(month_sales_data);
	printf("Sales Summary:\n\n");
	printf("Minimum Sales: %f\n", minSales(month_sales_data));
	printf("Maximum Sales: %f\n", maxSales(month_sales_data));

	return 0;
}
