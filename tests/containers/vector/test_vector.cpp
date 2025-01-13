#include <cassert>
#include <algorithm>
#include <iostream>
#include "vector_raw.h"

void printList(sinensis::vector<int>& v)
{
	for (std::size_t i = 0; i < v.size(); i++)
		std::cout << "Element #" << i << ": " << v[i] << std::endl;
}

void checkpoint(int count)
{
	std::cout << "Checkpoint: " << count << std::endl;
}

int main()
{
	int count = 0;

	std::cout << "\nRunning Tests..." << std::endl;

	sinensis::vector<int> v;

	checkpoint(count);

	assert(v.size()==0);
	assert(v.capacity()==0);	

	checkpoint(1);

	v.push_back(1);

	assert(v.size()==1);
	assert(v.capacity()==1);	
	assert(v[0]==1);	

	checkpoint(2);

	v.push_back(2);

	assert(v.size()==2);
	assert(v.capacity()==2);	
	assert(v[0]==1);
	assert(v[1]==2);
	
	checkpoint(3);

	v.push_back(3);

	assert(v.size()==3);
	assert(v.capacity()==4);
	assert(v[0]==1);
	assert(v[1]==2);
	assert(v[2]==3);
	
	checkpoint(4);

	v.pop_back();

	assert(v.size()==2);
	assert(v.capacity()==4);
	assert(v[0]==1);
	assert(v[1]==2);

	checkpoint(5);

	sinensis::vector<int> v1;

	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);
	
	assert(v1.size()==3);
	assert(v1.capacity()==4);
	assert(v1[0]==3);
	assert(v1[1]==2);
	assert(v1[2]==1);

	checkpoint(6);

	v1.swap(v);

	assert(v1.size()==2);
	assert(v1.capacity()==2);
	assert(v1[0]==1);
	assert(v1[1]==2);
	
	checkpoint(7);

	v.reserve(10);
	
	assert(v.size()==2);
	assert(v.capacity()==10);

	checkpoint(8);

	v.clear();
	
	assert(v.size()==0);
	assert(v.capacity()==10);		

	checkpoint(9);

	v.push_back(30);
	v.push_back(2);
	v.push_back(3);

	assert(*v.begin()==30);
	assert(*(v.end()-1)==3);
	
	checkpoint(10);
	
	v1.swap(v);

	assert(v1[0]==30);
	assert(v1[1]==2);
	assert(v1[2]==3);

	checkpoint(11);

	assert(v1.erase(v1.begin()) == v1.begin());
	assert(v1[0]==2);
	assert(v1[1]==3);
	assert(v1.size()==2);

	checkpoint(12);

	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);

	assert(v1.size()==6);
	
	assert(v1.erase(v1.begin()+2, v1.begin()+4) == v1.begin()+4);
	assert(v1.size()==3);
	assert(v1[0]==2);	
	assert(v1[1]==3);
	assert(v1[2]==7);

	checkpoint(13);

	sinensis::vector<int> v2 = {1, 2, 3};

	assert(v2[0]==1);
	assert(v2[1]==2);
	assert(v2[2]==3);
	assert(v2.size()==3);
	assert(v2.capacity()==3);

	checkpoint(14);
	v2 = {5, 4, 3, 2, 1};

	assert(v2[0]==5);
	assert(v2[1]==4);
	assert(v2[2]==3);
	assert(v2[3]==2);
	assert(v2[4]==1);	
	assert(v2.size()==5);
	assert(v2.capacity()==5);

	checkpoint(15);

	v2 = v1;
	assert(v2[0]==v1[0]);
	assert(v2[1]==v1[1]);
	assert(v2[2]==v1[2]);
	assert(v2.size()==3);
	assert(v2.capacity()==3);

	checkpoint(16);

	sinensis::vector<int> v4{10, 9, 8, 7};
	assert(v4[0]==10);
	assert(v4[1]==9);
	assert(v4[2]==8);
	assert(v4[3]==7);
	assert(v4.size()==4);
	assert(v4.capacity()==4);

	sinensis::vector<int> v5;
	v5.assign(10, 5);

	assert(v4.at(3)==7);

	std::cout << "Reverse Iterator Output:" << std::endl << '\t';
	std::for_each(v4.rbegin(), v4.rend(), [](const int n) { std::cout << n << ' '; });
	std::cout << std::endl;

	checkpoint(17);

	v4.assign(v2.begin(), v2.end());
	
	assert(v4 == v2);

	sinensis::vector<int> v6;
	v6.resize(5, 10);
	assert(v6.size()==5);
	assert(v6.capacity()==5);
	for (int i = 0; i < 5; i++)
		assert(v6[i]==10);
	v6.reserve(100);
	assert(v6.capacity()==100);
	v6.shrink_to_fit();
	assert(v6.size()==5);
	assert(v6.capacity()==5);
	for (int i = 0; i < 5; i++)
		assert(v6[i]==10);

	sinensis::vector<int> v7;
	v7.push_back(1);
	v7.push_back(5);
	v7.push_back(2);
	v7.push_back(5);
	v7.push_back(3);
	v7.push_back(5);
	v7.erase_if(v7.begin(), v7.end(), 5);
	assert(v7[0]==1);
	assert(v7[1]==2);
	assert(v7[2]==3);
	assert(v7.size()==3);

	v7.insert(v7.begin(), 2, 2);
	assert(v7[0]==2);
	assert(v7[1]==2);
	assert(v7[2]==1);
	assert(v7[3]==2);
	assert(v7[4]==3);
	assert(v7.size()==5);

	v7.insert(v7.begin(), {1, 2, 3});
	assert(v7[0]==1);
	assert(v7[1]==2);
	assert(v7[2]==3);
	assert(v7[3]==2);
	assert(v7[4]==2);
	assert(v7[5]==1);
	assert(v7[6]==2);
	assert(v7[7]==3);
	assert(v7.size()==8);

	std::cout << "All tests have been passed!" << std::endl;

	return 0;
}
