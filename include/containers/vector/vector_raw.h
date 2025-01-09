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
			if (_memoryBlock)
				delete[] _memoryBlock;	
			_memoryBlock = newMemoryBlock;
			_capacity = newCapacity;
		}

		T* erase(T* position)
		{			
			std::size_t remove_index = static_cast<std::size_t>(std::distance(begin(), position));
			
			T* newMemoryBlock = new T[_capacity];
			std::size_t j = 0;
			for (std::size_t i = 0; i < _size; i++)
			{
				if (i == remove_index) i++;

				newMemoryBlock[j] = _memoryBlock[i];
				j++;
			}
			_size--;
			if (_memoryBlock)
				delete[] _memoryBlock;

			_memoryBlock = newMemoryBlock;
			
			return (remove_index == _size) ? end() : begin()+remove_index;	
		}

		T* erase(T* start, T* finish)
		{
			std::size_t remove_index_first = static_cast<std::size_t>(std::distance(begin(), start));
			std::size_t remove_index_last = static_cast<std::size_t>(std::distance(begin(), finish));

			bool removed_last = remove_index_last >= (_size - 1);			
			
			T* newMemoryBlock = new T[_capacity];
			std::size_t j = 0;
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
				delete[] _memoryBlock;

			_memoryBlock = newMemoryBlock;

			return (removed_last)  ? end() : begin()+remove_index_last;
		}
	};
};
