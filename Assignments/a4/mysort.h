/*
-------------------------------------
File:    mysort.h
Project: sure3530_a04
-------------------------------------
Author:  Sanjae Suresh Kumar
ID:      210523530
Email:   sure3530@mylaurier.ca
Version  2023-02-06
-------------------------------------
 */
/*
Define an enumeration type named BOOLEAN with name false as 0 and true as 1.
*/
enum BOOLEAN {false = 0, true = 1};
/*
This function tests if float array a[] is sorted in increasing order between index left and right, and returns true if yes, otherwise false.
*/
enum BOOLEAN is_sorted(float *a, int left, int right);
/*
This function sorts the elements of float array a[] from index left to right in increasing order, using the selection sort algorithm. 
*/
void select_sort(float *a, int left, int right);
 
/*
This function sorts the elements of float array a[] from index left to right in increasing order, using the quick sort algorithm. 
*/ 
void quick_sort(float *a, int left, int right); 