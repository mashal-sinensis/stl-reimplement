#include <memory>

namespace sinensis
{
	class string
	{
	private:
		static const std::size_t npos = -1;
		
		std::unique_ptr<char[]> _data;
		std::size_t _size;
		std::size_t _capacity;
	public:
		string() : _size(0), _capacity(0) // default
		{
			_data = std::make_unique<char[]>(0);
		}

		string(const string& str) // copy
		{	
		}

		string(const string& str, std::size_t pos, std::size_t len = npos) // substring
		{	
		}

		string(const char* s) // c-string
		{
		}

		string(const char* s, std::size_t n) // sequence
		{
		}

		string(std::size_t n, char c) // fill
		{
		}

		string (char* first, char* last) // range
		{
		}
					 
		~string() = default;
	
		string& operator=(const string& str) // string
		{
		}
		
		string& operator=(const char* s) // c-string
		{
		}

		string& operator=(char c) // character
		{
		}

		// Iterators (Near-Identical Implementation to vector.h)	

		char* begin() const { return _data.get(); }

		char*  end() const { return _data.get() + _size; }
		
		const char* cbegin() const { return _data.get(); }
		
		const char* cend() const { return _data.get() + _size; }

		std::reverse_iterator<const char*> crbegin() const { return std::make_reverse_iterator(end()); }

		std::reverse_iterator<const char*> crend() const { return std::make_reverse_iterator(begin()); }

		std::reverse_iterator<char*> const rbegin() { return std::make_reverse_iterator(end()); }
		
		std::reverse_iterator<char*> const rend() { return std::make_reverse_iterator(begin()); }
		
		// Capacity

		std::size_t size() const
		{
		}

		std::size_t length() const
		{
		}

		std::size_t max_size() const
		{
		}
		
		std::size_t capacity() const
		{
		}

		void clear()
		{
		}

		bool empty() const
		{
		}
		
		void resize(std::size_t n)
		{
		}

		void resize(std::size_t n, char c)
		{
		}
		
		void reserve(std::size_t n = 0)
		{
		}
		
		void shrink_to_fit()
		{
		}
		
		// Element Access

		char& operator[](std::size_t pos) const
		{		
		}

		char& at(std::size_t pos) const
		{
		}
		
		char& back() const
		{
		}

		char& front() const
		{
		}

		// Modifiers

		string& operator+=(const string& str) // string
		{
		}
	
		string& operator+=(const char* s) // c-string
		{
		}

		string& operator+=(char c) // character
		{
		}

		string& append(const string& str) // string
		{
		}

		string& append(const string& str, std::size_t subpos, std::size_t sublen) // substring
		{
		}
		
		string& append(const char* s) // c-string
		{
		}
		
		string& append(const char* s, std::size_t n) // buffer
		{
		}

		string& append(std::size_t n, char c) // fill
		{
		}

		string& append(char* first, char* last) // range
		{
		}

		void push_back(char c)
		{
		}

		string& assign(const string& str) // string
		{
		}
		
		string& assign(const string& str, std::size_t subpos, std::size_t sublen) // substring
		{
		}
		
		string& assign(const char* s) // c-string
		{
		}

		string& assign(const char* s, std::size_t n) // buffer
		{
		}
		
		string& assign(std::size_t n, char c) // fill
		{
		}
		
		string& assign(char* first, char* last) // range
		{
		}

		string& insert(std::size_t pos, const string& str) // string
		{ 
		}
		
		string& insert(std::size_t pos, const string& str, std::size_t subpos, std::size_t sublen) // substring
		{
		}
		
		string& insert(std::size_t pos, const char* s) // c-string 
		{ 
		}

		string& insert(std::size_t pos, const char* s, std::size_t n) // buffer
		{
		}
		
		string& insert(std::size_t pos, std::size_t n, char c) // fill
		{
		}
		
		void insert(char* p, std::size_t n, char c) // fill
		{
		}

		char* insert(char* p, char c) // single character
		{
		}
		
		string& insert(char* first, char* last) // range
		{
		}
		
		string& erase(std::size_t pos = 0, std::size_t len = npos) // sequence
		{
		}

		char* erase(char* p) // character
		{
		}

		char* erase(char* first, char* last) // range
		{
		}		

		string& replace(std::size_t pos, std::size_t len, const string& str) // string
		{
		}
		
		string& replace(char* i1, char* i2, const string& str) // string (iterator)
		{
		}
		
		string& replace(std::size_t pos, std::size_t len, const string& str, std::size_t subpos, std::size_t sublen) // substring
		{	
		}

		string& replace(std::size_t pos, std::size_t len, const char* s) // c-string
		{
		}
	
		string& replace(char* i1, char* i2,  const char* s) // c-string (iterator)
		{
		}

		string& replace(std::size_t pos, std::size_t len, const char* s, std::size_t n) // buffer
		{
		}	
			
		string& replace(char* i1, char* i2, const char* s, std::size_t n) // buffer (iterator)
		{
		}
		
		string& replace(std::size_t pos, std::size_t len, std::size_t n, char c) // fill
		{
		}
		
		string& replace(char* i1, char* i2, std::size_t n, char c) // fill (iterator)
		{
		}

		string& replace (char* i1, char* i2, char* first, char* last) // range
		{
		}

		void swap(string& str)
		{
		}

		void pop_back()
		{
		}

		// String Operations

		const char* c_str() const
		{
		}

		const char* data() const
		{
		}

		std::size_t copy(char* s, std::size_t len, std::size_t pos = 0) const
		{
		}

		std::size_t find(const string& str, std::size_t pos = 0) const // string
		{
		}
			
		std::size_t find(const char* s, std::size_t pos = 0) const // c-string
		{
		}	
		
		std::size_t find(const char* s, std::size_t pos, std::size_t n) const // buffer
		{
		}	
		
		std::size_t find(char c, std::size_t pos = 0) const // character
		{
		}

		std::size_t rfind(const string& str, std::size_t pos = npos) const // string
		{
		}
			
		std::size_t rfind(const char* s, std::size_t pos = npos) const // c-string
		{
		}	
		
		std::size_t rfind(const char* s, std::size_t pos, std::size_t n) const // buffer
		{
		}	
		
		std::size_t rfind(char c, std::size_t pos = npos) const // character
		{
		}
		
		std::size_t find_first_of(const string& str, std::size_t pos = 0) const // string
		{
		}
			
		std::size_t find_first_of(const char* s, std::size_t pos = 0) const // c-string
		{
		}	
		
		std::size_t find_first_of(const char* s, std::size_t pos, std::size_t n) const // buffer
		{
		}	
		
		std::size_t find_first_of(char c, std::size_t pos = 0) const // character
		{
		}
		
		std::size_t find_last_of(const string& str, std::size_t pos = 0) const // string
		{
		}
			
		std::size_t find_last_of(const char* s, std::size_t pos = 0) const // c-string
		{
		}	
		
		std::size_t find_last_of(const char* s, std::size_t pos, std::size_t n) const // buffer
		{
		}	
		
		std::size_t find_last_of(char c, std::size_t pos = 0) const // character
		{
		}
		
		std::size_t find_first_not_of(const string& str, std::size_t pos = 0) const // string
		{
		}
			
		std::size_t find_first_not_of(const char* s, std::size_t pos = 0) const // c-string
		{
		}	
		
		std::size_t find_first_not_of(const char* s, std::size_t pos, std::size_t n) const // buffer
		{
		}	
		
		std::size_t find_first_not_of(char c, std::size_t pos = 0) const // character
		{
		}
		
		std::size_t find_last_not_of(const string& str, std::size_t pos = 0) const // string
		{
		}
			
		std::size_t find_last_not_of(const char* s, std::size_t pos = 0) const // c-string
		{
		}	
		
		std::size_t find_last_not_of(const char* s, std::size_t pos, std::size_t n) const // buffer
		{
		}	
		
		std::size_t find_last_not_of(char c, std::size_t pos = 0) const // character
		{
		}
	
		string substr(std::size_t pos = 0, std::size_t len = npos) const
		{
		}

		int compare(const string& str) const // string
		{
		}

		int compare(std::size_t pos, std::size_t len, const string& str) const // substring
		{
		}

		int compare(std::size_t pos, std::size_t len, const string& str, std::size_t subpos, std::size_t sublen) const // substring
		{
		}

		int compare(const char* s) const // c-string
		{
		}

		int compare(std::size_t pos, std::size_t len, const char* s) const // c-string
		{
		}
		
		int compare(std::size_t pos, std::size_t len, const char* s, std::size_t n) const // buffer
		{
		}

		//

	};
};
