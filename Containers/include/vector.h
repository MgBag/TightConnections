#pragma once

namespace tc
{
	template<class T>
	class Vector
	{
	public:
		// TODO: Rule of 5 (6)
		// TODO: Write allocator?
		
		Vector();
		Vector(size_t capacity);
		virtual ~Vector();

		// Constructor using the curely brackets 
		// Consturctor that sets the capacity 
		// Constructor that takes a allocator 

		size_t Size();
		
		void PushBack(T& item);
		void PopBack();

		// Start
		// End
		// RStart
		// REnd

		// Operators 
		T& operator[](const size_t pos);

		inline size_t Capacity() const
		{
			return m_capacity;
		}

		void Resize(size_t size);
		void Reserve(size_t size);

		void PushBack(const T& item);
		// push_back variadic args 

	private:
		T* m_data;
		size_t m_capacity;
		size_t m_size;

		
	};
}