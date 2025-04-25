#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {
	
    template<typename T>
    
    /*Implementation of the BubbleSort */
    
    void BubbleSort(vector<T>& v)
    {	const int n = v.size();
        for(int i=0; i < n-1; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                /*Here the situation is very simple, if the element in the j-th position is smaller than
                the one in the i-th position, I perform the swap */
    
                if(v[j]<v[i])
                {
                    T a = v[i];
                    v[i] = v[j];
                    v[j] = a;
                }
            }
        }
    }
        
    /*For implementing the HeapSort, we need two functions, 
    one that transforms the vector in a valid Heap, and another
    that executes the dequeue operation on the Heap (used to sort the vector) */
    
    template<typename T>
    
    /*the value of n is the number of the elements to be considered on the right of the vector 
    (the nodes below the root from which I want to start the rearrangement), i is the first element from which
    the rearrangment starts (the highest in the part of the heap I'm considering). 
    So the function starts from node i, and forms a valid heap of n elements from the i-th node going downward. */
    
    void Heapify(vector<T>& v, unsigned int n, unsigned int i) 
    {
       while (true) {
           
           /* Here, I search the largest node between the current root and its two children,
            if the root i is not the largest among the three, I perform the exchange and put 
            on the top the greatest of the three nodes */
           
            unsigned int largest = i;
            unsigned int left = 2 * i + 1;
            unsigned int right = 2 * i + 2;
            
            if (left < n && v[left] > v[largest])
                largest = left;
    
            if (right < n && v[right] > v[largest])
                largest = right;
            
            /*If there are no swaps to perform, I stop this cycle, meaning that the heap
            has been correctly organized, if i is different from largest, I perform the
            swap, and then i becomes the position in which the largest node was, so I continue
            to control the heap going downward */
            
            if (largest == i)
                break;
    
            T a = v[i];
            v[i] = v[largest];
            v[largest] = a;
            i = largest;
            
            /* the cycles starts back going downward until the last level of the heap
            has been organized, when this function ends I have a valid heap from the i-th node (the value passed to the function)
            to the bottom of the heap*/
        }
    }
      
    template<typename T>
    
    void HeapSort(vector<T>& v) 
    {
        
        const int n = v.size();
        
        /* First of all, I transform the vector in a valid Heap, 
        to do this, I start from the lowest level of the heap and rearrage its elements,
        then by decrementing i, I go to the upper level, until I reach the top of the heap, 
        always using the heapify function to perform swaps in the heap. The heapify function (see above)
        creates a valid heap from node i to the bottom, and by decrementing i up to zero I'm creating step by step 
        a valid heap; after the last for loop, the heap will be complete. 
        Note that the first value of i is n/2-1, this is because I start the rearrangment from 
        the last parents having children, I don't consider the leaves which have no children
        to compare them with */
        
        for (int i = n / 2 - 1; i >= 0; i--)
            Heapify(v, n, i);
        
        /* After having heapified the vector, I start by permorming n dequeue operations on 
        the heap, as taught by professor Vicini, we swap the root with the last element of 
        the heap, and then remove that element and heapify back the vector (in order to always 
        have a valid heap) */
        
        for (int i = n - 1; i >= 0; i--) 
        {
            T a = v[i];
            v[i] = v[0];
            v[0] = a;
            
            /* Here, I have exchanged the root with the last leaf, and I want to heapify 
            the first i elements of the vector v, I don't consider the previously switched roots because they 
            are the ordered part of the vector, the heap rearrangment doesn't have to consider these elements 
            (as they are dequeued, the Heap only goes from 0 to the i-th position) */
            
            Heapify(v, i, 0);
            
            /*i gets decremented, so the program switches the new root with the last leaf and dequeues the root, then
            repeats */
        }
    }
        
    
    }
