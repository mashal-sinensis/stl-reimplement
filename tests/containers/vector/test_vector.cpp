#include <iostream>
#include <cassert>
#include "vector.h"

void printList(sinensis::vector<int> list)
{
	if (list.size() == 0)
	{
		std::cout << "The list is empty!" << std::endl;
	}

	for (std::size_t i = 0; i < list.size(); i++)
	{
		std::cout << "Element #" << i << ": " << list[i] << std::endl;
	}
}

void checkpoint(int &count)
{
	count++;
	std::cout << "Checkpoint " << count << std::endl;
}


int main()
{
	int count = -1;

	sinensis::vector<int> v;

	std::cout << "Running Tests..." << std::endl;
	
	printList(v);
	
	checkpoint(count);

	assert(v.size()==0);
	assert(v.capacity()==0);

	checkpoint(count);
	
	v.push_back(1);

	assert(v.size()==1);
	assert(v.capacity()==1);	
	assert(v[0]==1);

	checkpoint(count);
	printList(v);
	
	v.push_back(2);

	assert(v.size()==2);
	assert(v.capacity()==2);
	
	printList(v);
	
	assert(v[0]==1);
	assert(v[1]==2);
	
	checkpoint(count);
	printList(v);
	
	v.push_back(3);

	assert(v.size()==3);
	assert(v.capacity()==3);
	assert(v[0]==1);
	assert(v[1]==2);
	assert(v[2]==3);
	
	checkpoint(count);
	printList(v);
	
	v.pop_back();

	assert(v.size()==2);
	assert(v.capacity()==3);
	assert(v[0]==1);
	assert(v[1]==2);

	checkpoint(count);
	printList(v);
	
	v.resize(10);
	
	assert(v.size()==2);
	assert(v.capacity()==10);

	checkpoint(count);
	printList(v);

	v.clear();
	
	assert(v.size()==0);
	assert(v.capacity()==10);
		
	checkpoint(count);
	printList(v);		

	return 0;
}
