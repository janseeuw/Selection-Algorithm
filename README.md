#Selection Algorithm

An importent application related to sorting but for which a full sort is not required is the operation of finding the kth smallest of a set of numbers. Because an algorithm cannot guarantee that a particular item is the kth smallest without having examined and identified the k - 1 elements that are smaller and the N - k elements that are larger.

Ofcourse we can solve this by sorting the array and take the kth element, but there are faster methods.

#Find the kth smallest element in an array
depending on the value of k, there are different possibilities:
<!-- more -->
* if k is extremely small, then selection sort will work well.
	Also if k is extremely large (search for the largest).

* For slightly larger k, but not bigger than N/2 we have 2 options:
	
	1. Perform the first k steps of heapsort (with descending heap).
	
	2. Keep a ascending heap with the temporary k smallest elements. These will be initialized with the first k elements, and the remaining elements will be compared with the largest element in the heap one by one. Eventually the heap will contain the k smallest elements, with the kth smallest element at the root.
	
* for larger k there is a method based on the partitioning from quicksort. The partition divides the array in elements who are smaller (or equal to) than the pivot, and elements bigger than (or equal to) the pivot. To find the kth smallest element we do:
	
	* If k = i, then we have what we were looking for
	
	* If k < i, then we have to search further in the left part of the array, also after the kth smallest element.
	
	* If k > i, then we have to search further in the right part of the array, but now for the k - ith smallest element.
	
This approach leads immediately to a recursive implementation. We can easily remove the tail recursion.
This code fragment is the non-recursive implementation.

