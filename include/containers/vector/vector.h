#pragma once

#include <iostream>
#include <cstddef>
#include <memory>

namespace sinensis
{
	template <typename T>
	class vector
	{
	private:
		std::unique_ptr<T[]> _memoryBlock;
		std::size_t _size;
		std::size_t _capacity;
	public:
		vector() : _size(0), _capacity(0) 
		{
			_memoryBlock = std::make_unique<T[]>(0);
		}
		
		~vector() = default;
	
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
			std::unique_ptr<T[]> newMemoryBlock = std::make_unique<T[]>(newCapacity);
			for (std::size_t i = 0; i < _size; i++)
			{
				newMemoryBlock[i] = _memoryBlock[i];
			}
			
			_memoryBlock = std::move(newMemoryBlock);
			_capacity = newCapacity;
		}
	};
};
