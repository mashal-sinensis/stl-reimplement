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
	
	v.resize(10);
	
	assert(v.size()==2);
	assert(v.capacity()==10);

	v.clear();
	
	assert(v.size()==0);
	assert(v.capacity()==10);

	return 0;
}
