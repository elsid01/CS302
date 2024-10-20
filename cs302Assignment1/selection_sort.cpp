/*
Test main that uses the linked list object and set of iterators
to implement selection sort
*/

#include <iostream>
#include "LL.hpp"
#include "LL.cpp"
using namespace std;

int main()
{
	LL<int> numbers;
	LL<int>::iterator i, max, k;
	int x;

	//read in the numbers from the file
	//and populate the numbers list
	while (cin >> x)
		numbers.push_back(x);

	//set k to the end of the list
	k = numbers.end();

	//once k moves all the way to the beginning
	//we are done and the list is sorted
	while (k != numbers.begin())
	{
		//assume the first element of the list is the max
		max = numbers.begin();

		//iterate from the second node all the way to the
		//end of the unsorted array, if a bigger value is
		//found, set the max iterator to this node
		for (i = ++numbers.begin(); i != k; i++)
			if (*i > *max)
				max = i;

		//swap the max with the end of the unsorted array
		k--;
		numbers.swapNodes(max, k);
	}


	for (i = numbers.begin(); i != numbers.end(); i++)
		cout << *i << endl;

	return 0;
}