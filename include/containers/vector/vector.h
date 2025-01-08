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
			
			delete[] _memoryBlock;
			_memoryBlock = newMemoryBlock;
			_capacity = newCapacity;
		}
	};
};
