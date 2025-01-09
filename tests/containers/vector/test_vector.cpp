#include <cassert>
#include "vector.h"
// #include "vector_raw.h" -- raw pointers

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

	v.resize(10);
	
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
	assert(*v.end()==3);
	
	checkpoint(10);
	
	v1.swap(v);

	assert(v1[0]==30);
	assert(v1[1]==2);
	assert(v1[2]==3);

	std::cout << "All tests have been passed!" << std::endl;

	return 0;
}
