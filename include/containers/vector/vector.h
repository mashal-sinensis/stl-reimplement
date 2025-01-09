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
		
		// -- Does not seem to work

		// explicit vector<T>(std::initializer_list<T> ilist) : _size(ilist.size()), _capacity(_size)
		// {
		// 	assign_range(ilist.begin(), ilist.end());
		// }
	
		void assign_range(T* first, T* last)
		{
			clear();
			_size = std::distance(first, last) + 1;
			std::cout << "Swap size: " << _size << std::endl;
			_capacity = _size;
			_memoryBlock = std::make_unique<T[]>(_size);
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
		

		T* begin() const { return _memoryBlock.get(); }

		T* end() const { return _memoryBlock.get() + _size - 1; } 

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

		void erase(T* position)
		{

		}

		void erase(T* begin, T* end)
		{

		}
	};
};
