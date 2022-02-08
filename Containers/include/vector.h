#pragma once

namespace tc
{
	template<class T>
	class Vector
	{
	public:
		// TODO: Rule of 5 (6)
		// TODO: Iterator types
		// TODO: Write allocator?
		
		Vector();
		~Vector();

		// Constructor using the curely brackets 
		// Consturctor that sets the capacity 
		// Constructor that takes a allocator 

		size_t Size();
		
		void PushBack(T& item);
		T PopBack();

		// Start
		// End
		// RStart
		// REnd

		// Operators 

		


	private:
		// some resize func
		// The actual pointer to internal storage 
	};
}