// JAVIDSTL. Created By Javid Mamedov.
#pragma once

namespace JAVIDSTL
{
	class Utilities
	{
	public:

		
		static size_t Max(size_t first, size_t second)
		{
			if (first > second)
			{
				return first;
			}
			else
			{
				return second;
			}
		}

		template<typename T>
		static void Swap(T& first, T& second)
		{
			//T* Ptr = second;
			T temp = first;
			first = second;
			second = temp;
		}
	};



};