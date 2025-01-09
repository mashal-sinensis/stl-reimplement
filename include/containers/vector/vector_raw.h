#pragma once

#include <iostream>
#include <cstddef>

namespace sinensis
{
	template <typename T>
	class vector
	{
	private:
		T* _memoryBlock;
		std::size_t _size;
		std::size_t _capacity;
	public:
		vector() : _memoryBlock(nullptr), _size(0), _capacity(0) {}
		
		~vector()
		{
			if (_memoryBlock)
			{
				delete[] _memoryBlock;
			}
		}
	
		T& operator[](std::size_t index)
		{
			if (index >= _size) 
			{
				throw std::out_of_range("Index out of range");
			}
			return _memoryBlock[index];
		}
		
		// -- Does not seem to work

		// explicit vector<T>(std::initializer_list<T> ilist) : _size(ilist.size()), _capacity(_size)
		// {
		// 	assign_range(ilist.begin(), ilist.end());
		// }
	
		void assign_range(T* first, T* last)
		{
			clear();
			_size = std::distance(first, last) + 1;
			_capacity = _size;
			_memoryBlock = new T[_size];
			int count = 0;
			for (T* itr = first; itr != nullptr; itr++)
			{
				_memoryBlock[count] = *itr;
				count++;
				if (itr == last) break;
			}
		}
		
		void swap(vector<T>& other)
		{
			assign_range(other.begin(), other.end());
		}
		

		T* begin() const { return _memoryBlock; }

		T* end() const { return _memoryBlock + _size - 1; } 

		std::size_t size() const { return _size; }

		std::size_t capacity() const { return _capacity; }
	
		void push_back(T data)
		{
			if (_size == _capacity)
			{
				resize((_capacity == 0) ? 1 : _capacity * 2);
			}

			_memoryBlock[_size++] = data;
		}

		void pop_back()
		{
			if (_size > 0)
			{
				_size--;
			}
		}
		
		void clear()
		{
			_size = 0;
		}
		
		void resize(std::size_t newCapacity)
		{
			T* newMemoryBlock = new T[newCapacity];
			for (std::size_t i = 0; i < _size; i++)
			{
				newMemoryBlock[i] = _memoryBlock[i];
			}
			
			_memoryBlock = newMemoryBlock;
			_capacity = newCapacity;
		}

		void erase(T* position)
		{

		}

		void erase(T* begin, T* end)
		{

		}
	};
};
