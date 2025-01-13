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
	
		bool compare(T* other_itr)
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
		
		~vector()
		{
			if (_memoryBlock)
			{
				delete[] _memoryBlock;
			}
		}

		vector(std::initializer_list<T> other)
		{
			assign(other.begin(), other.end());
		}
	
		T& operator[](std::size_t index)
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

		bool operator==(vector<T>& other)
		{
			return (_size == other.size()) ? compare(other.begin()) : false;
		}

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

		void assign(std::initializer_list<T> ilist)
		{
			assign(ilist.begin(), ilist.end());			
		}
		
		T& at(std::size_t index)
		{
			return _memoryBlock[index];
		}

		T& front()
		{
			return _memoryBlock[0];
		}

		T& back()
		{
			return _memoryBlock[_size-1];
		}

		T* data()
		{
			return _memoryBlock;
		}

		bool empty()
		{
			return (_size == 0);
		}
		
		void assign(const T* first, const T* last)
		{
			clear();
			_size = std::distance(first, last);
			_capacity = _size;
			_memoryBlock = new T[_size];
			
			const T* itr = first;
			for (std::size_t  i = 0; i < _size; i++)
			{
				_memoryBlock[i] = *itr;
				++itr;
			}
		}
		
		void swap(vector<T>& other)
		{
			assign(other.begin(), other.end());
		}
		

		T* begin() const { return _memoryBlock; }

		T* end() const { return _memoryBlock + _size; }
		
		std::reverse_iterator<const T*> crbegin() const { return std::make_reverse_iterator(end()); }

		std::reverse_iterator<const T*> crend() const { return std::make_reverse_iterator(begin()); }

		std::reverse_iterator<T*> rbegin() { return std::make_reverse_iterator(end()); }
		
		std::reverse_iterator<T*> rend() { return std::make_reverse_iterator(begin()); }

		const T* cbegin() const { return _memoryBlock; }
		
		const T* cend() const { return _memoryBlock + _size; }

		std::size_t size() const { return _size; }

		std::size_t capacity() const { return _capacity; }
	
		void push_back(T data)
		{
			if (_size == _capacity)
			{
				reserve((_capacity == 0) ? 1 : _capacity * 2);
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

		void resize(std::size_t newCapacity, T value = T())
		{
			if (newCapacity <= _capacity) return;
			T* newMemoryBlock = new T[newCapacity];
			for (std::size_t i = 0; i < newCapacity; i++)
			{
				newMemoryBlock[i] = (i < _size) ? _memoryBlock[i] : value;
			}
			if (_memoryBlock)
				delete[] _memoryBlock;	
			_memoryBlock = newMemoryBlock;
			_capacity = newCapacity;
			_size = newCapacity;
		}
		
		void reserve(std::size_t newCapacity)
		{
			if (newCapacity <= _capacity) return;
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

		std::size_t erase_if(T* begin, T* end, T value)
		{
			std::size_t dist = std::distance(begin, end);
			std::size_t* remove_indices = new size_t[dist];
			std::size_t remove_indices_size{};
			T* itr = begin;
			
			for (std::size_t i = 0; i < dist; i++)
			{
				if (*itr == value)
				{
					remove_indices[remove_indices_size] = i;
					remove_indices_size++;
				}
				itr++;
			}

			if (remove_indices_size == 0)
			{
				delete[] remove_indices;
				return 0;
			}
			
			T* newMemoryBlock = new T[_capacity];
			std::size_t j = 0;
			std::size_t remove_indices_index = 0;
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
			if (_memoryBlock) delete[] _memoryBlock;
			_memoryBlock = newMemoryBlock;
			delete[] remove_indices;
			return remove_indices_size;
		}

		T* insert(T* position, T value)
		{
			return insert(position, 1, value);	
		}

		T* insert(T* position, std::initializer_list<T> ilist)
		{
			return insert(position, ilist.begin(), ilist.end());
		}

		T* insert(T* position, const T* first, const T* last)
		{
			std::size_t insert_index = std::distance(begin(), position);			
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
			if (_memoryBlock) delete[] _memoryBlock;
			_memoryBlock = newMemoryBlock;
			return (begin() + insert_index);

		}

		T* insert(T* position, std::size_t count, T value)
		{
			std::size_t insert_index = std::distance(begin(), position);			
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
			if (_memoryBlock) delete[] _memoryBlock;
			_memoryBlock = newMemoryBlock;
			return (begin() + insert_index);
		}
		
		std::size_t max_size()
		{
			return ((pow(2, 64) / sizeof(T)) - 1);
		}

		void shrink_to_fit(std::size_t newCapacity)
		{
			if (newCapacity >= _capacity) return;
			T* newMemoryBlock = new T[newCapacity];
			for (std::size_t i = 0; i < newCapacity; i++)
			{
				newMemoryBlock[i] = _memoryBlock[i];
			}
			if (_memoryBlock)
				delete[] _memoryBlock;
			_memoryBlock = newMemoryBlock;
			_capacity = newCapacity;
			_size = newCapacity;
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
