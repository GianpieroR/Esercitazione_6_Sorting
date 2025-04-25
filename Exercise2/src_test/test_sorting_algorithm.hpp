#pragma once

#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp"

namespace SortLibrary {

/* Here, I test the bubble sort and the heap sort with vectors of int and doubles */

TEST(TestSorting, BubbleSortWithInt)
{
    vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    BubbleSort<int>(v);
    vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, BubbleSortWithDouble)
{
	vector<double> v = {12.3, -14.0, 1.7e-5, 1.8e+12, 35.3555, 12.0, 0.0};
	vector<double> sortedV = {-14.0, 0.0, 1.7e-5, 12.0, 12.3, 35.3555, 1.8e+12};
	BubbleSort<double>(v);
	EXPECT_EQ(v,sortedV);
}
	
TEST(TestSorting, HeapSortWithInt)
{
    vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    HeapSort<int>(v);
    vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, HeapSortWithDouble)
{
	vector<double> v = {12.3, -14.0, 1.7e-5, 1.8e+12, 35.3555, 12.0, 0.0};
	vector<double> sortedV = {-14.0, 0.0, 1.7e-5, 12.0, 12.3, 35.3555, 1.8e+12};
	HeapSort<double>(v);
	EXPECT_EQ(v,sortedV);
}

/* Now, I run some tests of the two algorithms using the best and the worst case */

TEST(TestSorting, BubbleSortBestCase)
{
	vector<double> v(100);
	for(int i = 0; i<100; i++)
		v[i] = 3*i + 4;
	
	/* This is just a copy of v inside sortedV, so if 
	something goes wrong inside the BubbleSort I can see it by 
	comparing v with this original copy (because v should remain equal to the 
	original copy in the best case) */
	
	vector<double> sortedV = v;
	BubbleSort(v);
	EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, BubbleSortWorstCase)
{
	vector<double> v(100);
	
	/*I initialize v in decreasing order */
	
	for(int i = 0; i<100; i++)
		v[i] = -4*i;
	
	/*Now i put in sortedV the reversed vector v */
	
	vector<double> sortedV(100);
	for(int i = 0; i<100; i++)
		sortedV[i] = v[100-i-1];
	BubbleSort(v);
	
	/*I expect v after the bubblesort to be equal to its reversed values */
	
	EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, HeapSortBestCase)
{
	vector<double> v(100);
	for(int i = 0; i<100; i++)
		v[i] = 3*i + 4;
	vector<double> sortedV = v;
	HeapSort(v);
	EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, HeapSortWorstCase)
{
	vector<double> v(100);
	for(int i = 0; i<100; i++)
		v[i] = -4*i;
	vector<double> sortedV(100);
	for(int i = 0; i<100; i++)
		sortedV[i] = v[100-i-1];
	HeapSort(v);
	EXPECT_EQ(v, sortedV);
}

/*Here, an idea should be to consider a randomized vector of 500 elements, and 
then create its copy, apply the two different methods on the vectors, and if the 
two algorithms work correctly, I should expect an equivalence between the two results, 
because the starting vector is the same */

TEST(TestSorting, HeapSort_and_BubbleSort)
{
	vector<double> v(500);
	vector<double> w(500);
	for(unsigned int i = 0; i<500; i++)
		v[i] = rand();
	w = v;
	BubbleSort<double>(v);
	HeapSort<double>(w);
	EXPECT_EQ(v,w);
}

/* Here, I test the case of HeapSort and BubbleSort with size 1 vectors and void vectors */
 
TEST(TestSorting, HeapSortSizeOne)
{
	vector<double> v = {4.0};
	vector<double> sortedV = {4.0};
	HeapSort(v);
	EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, BubbleSortSizeOne)
{
	vector<double> v = {2.0};
	vector<double> sortedV = {2.0};
	BubbleSort(v);
	EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, HeapSortVoidVector)
{
	vector<double> v;
	vector<double> sortedV;
	HeapSort(v);
	EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, BubbleSortVoidVector)
{
	vector<double> v;
	vector<double> sortedV;
	BubbleSort(v);
	EXPECT_EQ(v, sortedV);
}

}