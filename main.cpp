//
//  Created by Jonas Anseeuw
//  Copyright (c) 2014 Jonas Anseeuw. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template <class T>
T k_smallest(vector<T> &v,int l, int r, int k){
	while(l<r){
		int random = l+rand()%(r-l);
		swap(v[random], v[l]);
		int pivot = v[l];
		int i = l;
		int j= r;
		
		while(v[j]>pivot)
			j--;
		while(i<j){
			swap(v[i], v[j]);
			i++;
			while(v[i]<pivot)
				i++;
			j--;
			while(v[j]>pivot)
				j--;
		}
		if(k<i)
			r = j;
		else if(k>i)
			l = i;
		else
			return pivot;
	}
	return 0; //
}

int main(int argc, const char * argv[])
{
	int temp[] = {16,2,77,29,6,19,15,88};
	vector<int> array (temp, temp + sizeof(temp) / sizeof(int) );
	
	int thirdSmallest = k_smallest(array, 0, 8, 3);
	cout<<"Third-smallest element is "<<thirdSmallest;
	
    return 0;
}

