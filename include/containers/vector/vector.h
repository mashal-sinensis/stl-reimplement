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

		std::size_t size()
		{
			return _size;
		}

		std::size_t capacity()
		{
			return _capacity;
		}
	
		void push_back(T data)
		{
			std::cout << "\npush_back has been passed: " << data << std::endl;
			std::cout << "size: " << _size << std::endl;
			std::cout << "capacity: " << _capacity << std::endl;
			
			if (_size != 0)
				std::cout << "Element #1: " << _memoryBlock[0] << std::endl;
			
			if (_size+1 > _capacity)
			{
				resize((_capacity == 0) ? 1 : _capacity * 2); // double capacity for efficiency
			}	

			_memoryBlock[_size] = data; // assign data to next available slot
			_size++;
	
			std::cout << "new size: " << _size << std::endl;
			std::cout << "new capacity: " << _capacity << std::endl;
			std::cout << std::endl;
		}

		void pop_back()
		{
			delete (_memoryBlock + _size - 1);
			_size--;
		}
		
		void clear()
		{
			_size = 0;
			resize(_capacity);
		}
		
		void resize(std::size_t newCapacity)
		{
			std::cout << "Resizing: current size = " << _size << ", current capacity = " << _capacity << ", new capacity = " << newCapacity	<< std::endl;
		
			T* newMemoryBlock = new T[newCapacity];
			for (std::size_t i = 0; i < _size; i++)
			{
				newMemoryBlock[i] = _memoryBlock[i];
				std::cout << "Previous: _memoryBlock[" << i << "] = " << _memoryBlock[i] << std::endl;
				std::cout << "Copied: newMemoryBlock[" << i << "] = " << newMemoryBlock[i] << std::endl;
			}
			
			for (std::size_t i = 0; i < _size; i++)
			{
				std::cout << "Before delete: _memoryBlock[" << i << "] = " << _memoryBlock[i] << std::endl;
			}

			if (_memoryBlock)
				delete[] _memoryBlock;
			_memoryBlock = newMemoryBlock;
			_capacity = newCapacity;
			
			std::cout << "Resized: current size = " << _size << ", current capacity = " << _capacity << std::endl;
		}
	};
};
