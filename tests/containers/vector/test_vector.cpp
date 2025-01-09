#include <cassert>
#include "vector.h"

int main()
{
	sinensis::vector<int> v;

	assert(v.size()==0);
	assert(v.capacity()==0);
	
	v.push_back(1);

	assert(v.size()==1);
	assert(v.capacity()==1);	
	assert(v[0]==1);

	v.push_back(2);

	assert(v.size()==2);
	assert(v.capacity()==2);
	
	assert(v[0]==1);
	assert(v[1]==2);
	
	v.push_back(3);

	assert(v.size()==3);
	assert(v.capacity()==4);
	assert(v[0]==1);
	assert(v[1]==2);
	assert(v[2]==3);
	
	v.pop_back();

	assert(v.size()==2);
	assert(v.capacity()==4);
	assert(v[0]==1);
	assert(v[1]==2);

	sinensis::vector<int> v1;
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);
	
	assert(v1.size()==3);
	assert(v1.capacity()==4);
	assert(v1[0]==3);
	assert(v1[1]==2);
	assert(v1[2]==1);

	v1.swap(v);

	assert(v1.size()==2);
	assert(v1.capacity()==2);
	assert(v1[0]==1);
	assert(v1[1]==2);
	
	std::cout << v[0] << std::endl;
	std::cout << v[1] << std::endl;	

	v.resize(10);
	
	assert(v.size()==2);
	assert(v.capacity()==10);

	v.clear();
	
	assert(v.size()==0);
	assert(v.capacity()==10);		

	v.push_back(30);
	v.push_back(2);
	v.push_back(3);

	assert(v.begin()!=nullptr);
	assert(v.end()!=nullptr);
	
	std::cout << *v.begin() << std::endl;
	std::cout << *v.end() << std::endl;

	v1.swap(v);

	assert(v1[0]==30);
	assert(v1[1]==2);
	assert(v1[2]==3);

	return 0;
}
