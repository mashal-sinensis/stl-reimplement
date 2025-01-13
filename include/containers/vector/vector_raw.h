#pragma once

#include <iostream>
#include <cstddef>
#include <cmath>

namespace sinensis
{
	template <typename T>
	class vector
	{
	private:
		T* _memoryBlock;
		std::size_t _size;
		std::size_t _capacity;
	
		bool compare(T* other_itr) const
		{
			T* itr = begin();
			for (std::size_t i = 0; i < _size; i++)
			{
				if (*itr != *other_itr)
				{	
					return false;
				}
				other_itr++;
				itr++;
			}
			return true;
		}
	public:
		vector() : _memoryBlock(nullptr), _size(0), _capacity(0) {}	

		vector(std::initializer_list<T> other)
		{
			assign(other);
		}

		vector(std::size_t count, const T& value = T())
		{
			resize(count, value);
		}

		vector(T* first, T* last)
		{
			assign(first, last);
		}

		vector(vector<T>& other)
		{
			assign(other);
		}
		
		~vector()
		{
			if (_memoryBlock)
			{
				delete[] _memoryBlock;
			}
		}

		// Operator Overloads

		T& operator[](std::size_t index) const
		{
			if (index >= _size) 
			{
				throw std::out_of_range("Index out of range");
			}
			return _memoryBlock[index];
		}

		T* operator=(vector<T>& other)
		{
			assign(other.begin(), other.end());
			return begin();
		}

		T* operator=(std::initializer_list<T> other)
		{
			assign(other.begin(), other.end());
			return begin();
		}	

		bool operator==(vector<T>& other) const
		{
			return (_size == other.size()) ? compare(other.begin()) : false;
		}

		// Assign Functions
			
		void assign(std::size_t count, const T& value)
		{
			clear();

			_size = count;
			_capacity = _size;
			_memoryBlock = new T[_size];
			
			for (std::size_t i = 0; i < _size; i++)
			{
				_memoryBlock[i] = value;
			}
		}

		void assign(const T* first, const T* last)
		{
			clear();
			
			_size = std::distance(first, last);
			_capacity = _size;
			_memoryBlock = new T[_size];
			
			for (std::size_t i = 0; i < _size; i++)
			{
				_memoryBlock[i] = *(first + i);
			}
		}
			
		void assign(const std::initializer_list<T> ilist)
		{
			assign(ilist.begin(), ilist.end());			
		}	
	
		//	
	
		const T& at(std::size_t index) const
		{
			return _memoryBlock[index];
		}

		const T& front() const
		{
			return _memoryBlock[0];
		}

		const T& back() const
		{
			return _memoryBlock[_size-1];
		}

		const T* data() const
		{
			return _memoryBlock;
		}

		// Iterator Getters	

		T* begin() const { return _memoryBlock; }

		T* end() const { return _memoryBlock + _size; }
		
		const T* cbegin() const { return _memoryBlock; }
		
		const T* cend() const { return _memoryBlock + _size; }

		std::reverse_iterator<const T*> crbegin() const { return std::make_reverse_iterator(end()); }

		std::reverse_iterator<const T*> crend() const { return std::make_reverse_iterator(begin()); }

		std::reverse_iterator<T*> const rbegin() { return std::make_reverse_iterator(end()); }
		
		std::reverse_iterator<T*> const rend() { return std::make_reverse_iterator(begin()); }

		//
		
		bool empty() const { return (_size == 0); }
					
		std::size_t size() const { return _size; }
	
		std::size_t max_size() const { return ((pow(2, 64) / sizeof(T)) - 1); }	
		
		std::size_t capacity() const { return _capacity; }
		
		void reserve(std::size_t newCapacity)
		{
			if (newCapacity <= _capacity) 
			{
				return;
			}
			T* newMemoryBlock = new T[newCapacity];

			for (std::size_t i = 0; i < _size; i++)
			{
				newMemoryBlock[i] = _memoryBlock[i];
			}
			
			if (_memoryBlock)
			{
				delete[] _memoryBlock;	
			}
			_memoryBlock = newMemoryBlock;
			_capacity = newCapacity;
		}
		
		void shrink_to_fit()
		{
			T* newMemoryBlock = new T[_size];
			
			for (std::size_t i = 0; i < _size; i++)
			{
				newMemoryBlock[i] = _memoryBlock[i];
			}
			
			if (_memoryBlock)
			{
				delete[] _memoryBlock;
			}
			_memoryBlock = newMemoryBlock;
			_capacity = _size;
		}

		void clear()
		{
			_size = 0;
		}

		// Insert Functions

		T* insert(const T* position, const T& value)
		{
			return insert(position, 1, value);	
		}
		
		T* insert(const T* position, std::size_t count, const T& value)
		{
			std::size_t insert_index = std::distance(cbegin(), position);			
			std::size_t j = 0;

			_size += count;
			_capacity += count;
			T* newMemoryBlock = new T[_capacity];

			for (std::size_t i = 0; i < _size; i++)
			{
				if (i == insert_index)
				{
					for (std::size_t k = 0; k < count; k++)
					{
						newMemoryBlock[j] = value;
						j++;
					}
				}
				newMemoryBlock[j] = _memoryBlock[i];
				j++;
			}

			if (_memoryBlock) 
			{
				delete[] _memoryBlock;
			}
			_memoryBlock = newMemoryBlock;
			
			return (begin() + insert_index);
		}

		T* insert(const T* position, const T* first, const T* last)
		{
			std::size_t insert_index = std::distance(cbegin(), position);			
			std::size_t j = 0;
			std::size_t count = std::distance(first, last);
			
			_size += count;
			_capacity += count;
			T* newMemoryBlock = new T[_capacity];
			
			for (std::size_t i = 0; i < _size; i++)
			{
				if (i == insert_index)
				{
					for (std::size_t k = 0; k < count; k++)
					{
						newMemoryBlock[j] = *(first + k);
						j++;
					}
				}
				newMemoryBlock[j] = _memoryBlock[i];
				j++;
			}
			
			if (_memoryBlock)
			{	
				delete[] _memoryBlock;
			}
			_memoryBlock = newMemoryBlock;
			
			return (begin() + insert_index);
		}

		T* insert(const T* position, const std::initializer_list<T> ilist)
		{
			return insert(position, ilist.begin(), ilist.end());
		}

		// Erase Functions

		T* erase(const T* position)
		{			
			std::size_t remove_index = static_cast<std::size_t>(std::distance(cbegin(), position));
			std::size_t j = 0;
			
			T* newMemoryBlock = new T[_capacity];

			for (std::size_t i = 0; i < _size; i++)
			{
				if (i == remove_index) 
				{
					i++;
				}
				newMemoryBlock[j] = _memoryBlock[i];
				j++;
			}
			_size--;

			if (_memoryBlock)
			{
				delete[] _memoryBlock;
			}
			_memoryBlock = newMemoryBlock;
			
			return (remove_index == _size) ? end() : begin() + remove_index;	
		}

		T* erase(const T* start, const T* finish)
		{
			std::size_t remove_index_first = static_cast<std::size_t>(std::distance(cbegin(), start));
			std::size_t remove_index_last = static_cast<std::size_t>(std::distance(cbegin(), finish));
			std::size_t j = 0;
			bool removed_last = remove_index_last >= (_size - 1);			
			
			T* newMemoryBlock = new T[_capacity];
			
			for (std::size_t i = 0; i < _size; i++)
			{
				if (i < remove_index_first || i > remove_index_last) 
				{
					newMemoryBlock[j] = _memoryBlock[i];
					j++;
				}
			}
			_size -= (remove_index_last - remove_index_first) + 1;
			
			if (_memoryBlock)
			{	
				delete[] _memoryBlock;
			}
			_memoryBlock = newMemoryBlock;

			return (removed_last)  ? end() : begin()+remove_index_last;
		}

		//

		std::size_t erase_if(const T* start, const T* finish, const T& value)
		{
			std::size_t dist = std::distance(start, finish);
			std::size_t* remove_indices = new size_t[dist];
			std::size_t remove_indices_size{};
			std::size_t itr_index{};
			
			for (std::size_t i = 0; i < dist; i++)
			{
				if (*(start + itr_index) == value)
				{
					remove_indices[remove_indices_size] = i;
					remove_indices_size++;
				}
				itr_index++;
			}

			if (remove_indices_size == 0)
			{
				delete[] remove_indices;
				return 0;
			}
			
			std::size_t j = 0;
			std::size_t remove_indices_index = 0;
			
			T* newMemoryBlock = new T[_capacity];
			
			for (std::size_t i = 0; i < _size; i++)
			{
				if ((remove_indices_index < remove_indices_size) && (i == remove_indices[remove_indices_index])) 
				{
					remove_indices_index++;
					i++;
				}
				newMemoryBlock[j] = _memoryBlock[i];
				j++;
			}
			_size -= remove_indices_size;	
			
			if (_memoryBlock) 
			{
				delete[] _memoryBlock;
			}
			delete[] remove_indices;
			_memoryBlock = newMemoryBlock;
			
			return remove_indices_size;
		}	
		
		void push_back(const T& value)
		{
			if (_size == _capacity)
			{
				reserve((_capacity == 0) ? 1 : _capacity * 2);
			}
			_memoryBlock[_size++] = value;
		}

		void pop_back()
		{
			if (_size > 0)
			{
				_size--;
			}
		}	

		void resize(std::size_t newCapacity, const T& value = T())
		{
			if (newCapacity <= _capacity)
			{ 
				return;
			}
			T* newMemoryBlock = new T[newCapacity];
			
			for (std::size_t i = 0; i < newCapacity; i++)
			{
				newMemoryBlock[i] = (i < _size) ? _memoryBlock[i] : value;
			}
			
			if (_memoryBlock)
			{
				delete[] _memoryBlock;	
			}
			_memoryBlock = newMemoryBlock;
			_capacity = newCapacity;
			_size = newCapacity;
		}

		void swap(const vector<T>& other)
		{
			assign(other.begin(), other.end());
		}
	};
};
