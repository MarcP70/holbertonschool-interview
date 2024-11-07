#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Finds the maximum value in an array
 * @array: The array of integers
 * @size: The number of elements in the array
 *
 * Return: The maximum integer in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Performs a counting sort based on a specific digit place
 * @array: The array to be sorted
 * @size: The number of elements in the array
 * @exp: The exponent representing the current digit place (1, 10, 100, ...)
 *
 * Description: This function performs counting sort on the array
 * based on the digit represented by exp (1 for units, 10 for tens, etc.).
 * It sorts the array in place and is stable for each digit place.
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};

	/* Count occurrences of each digit in the exp place */
	for (size_t i = 0; i < size; i++)
	{
		int digit = (array[i] / exp) % 10;

		count[digit]++;
	}

	/* Accumulate counts */
	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	/* Build output array */
	for (ssize_t i = size - 1; i >= 0; i--)
	{
		int digit = (array[i] / exp) % 10;

		output[count[digit] - 1] = array[i];
		count[digit]--;
	}

	/* Copy sorted numbers into the original array */
	for (size_t i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in asc order using LSD Radix Sort
 * @array: The array of integers to be sorted
 * @size: The number of elements in the array
 *
 * Description: This function uses the Least Significant Digit (LSD)
 * radix sort algorithm to sort the array. It processes each digit
 * from least significant to most significant, calling counting_sort
 * on each digit place. The array is printed after sorting by each
 * significant digit place to show progression.
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	int max = get_max(array, size);

	/* Sort for each digit place */
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		/* Print the array after each significant digit */
		print_array(array, size);
	}
}
