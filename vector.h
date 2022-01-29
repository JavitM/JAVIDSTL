// JAVIDSTL. Created By Javid Mamedov.
#pragma once
#include <iostream>
	template<typename Vector>
	class VectorIterator
	{
	public:
		using ValueType = typename Vector::ValueType;
		using PointerType = ValueType*;
		using ReferenceType = ValueType&;
	public:
		VectorIterator(PointerType ptr)
			: m_Ptr(ptr) {}

		VectorIterator& operator++()
		{
			printf("prefix");
			m_Ptr++;
			return *this;
		}

		VectorIterator operator++(int)
		{
			printf("postfix");
			VectorIterator iterator = *this;
			++(*this);
			return iterator;
		}

		VectorIterator& operator+(int amount)
		{
			m_Ptr += amount;

			return *this;
		}

		VectorIterator& operator-(int amount)
		{
			m_Ptr -= amount;

			return *this;
		}

		VectorIterator& operator--()
		{

			m_Ptr--;
			return *this;
		}

		VectorIterator operator--(int)
		{
			VectorIterator iterator = *this;
			--(*this);
			return iterator;
		}

		ReferenceType operator[](int index)
		{
			return *(m_Ptr[index]);
			// return *(m_Ptr + index);
		}

		PointerType operator->()
		{
			return m_Ptr;
		}

		ReferenceType operator*()
		{
			return *m_Ptr;
		}

		bool operator==(const VectorIterator& other) const
		{
			return m_Ptr == other.m_Ptr;
		}

		bool operator!=(const VectorIterator& other) const
		{
			//return m_Ptr != other.m_Ptr;
			return !(*this == other);
		}
		// check with couts to see what sintax is post and pre | look
		// with breakpoint to see what m_Ptr does in memory when we do
		// m_Ptr++ see if it is in a row 
	private:
		PointerType m_Ptr;

		friend Vector;
	};


namespace JAVIDSTL
{

	template<typename T>
	class Vector
	{

	public:
		using ValueType = T;
		using Iterator = VectorIterator<Vector<T>>;
	public:
		Vector()
		{
			// allocate 2 elements
			ReAlloc(2);
		}

		Vector(size_t Size)
		{
			ReAlloc(Size);
		}

		~Vector()
		{
			Clear();
			::operator delete(m_Data, m_Capacity * sizeof(T));
		}

		void PushBack(const T& value)
		{
			if (m_Size >= m_Capacity)
			{
				ReAlloc(m_Capacity + m_Capacity / 2);
			}

			m_Data[m_Size] = T();
			m_Data[m_Size] = value;
			m_Size++;
		}

		void PushBack(T&& value)
		{
			if (m_Size >= m_Capacity)
			{
				ReAlloc(m_Capacity + m_Capacity / 2);
			}

			m_Data[m_Size] = std::move(value);
			m_Size++;
		}

		template<typename... Args>
		T& EmplaceBack(Args&&... args)
		{
			if (m_Size >= m_Capacity)
			{
				ReAlloc(m_Capacity + m_Capacity / 2);
			}

			new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
			///m_Data[m_Size] = T(std::forward<Args>(args)...);
			return m_Data[m_Size++];
		}

		void PopBack()
		{
			if (m_Size > 0)
			{
				m_Data[m_Size--].~T();
			}
		}

		void Clear()
		{
			for (size_t i = 0; i < m_Size; i++)
			{
				m_Data[i].~T();
			}

			m_Size = 0;
		}

		void erase(Iterator position)
		{
			T* dest = const_cast<T*>(position.m_Ptr);
			T* first = dest + 1;
			T* last = m_Data + m_Size;

			if (first < last)
			{
				for (; first != last; ++first, ++dest)
				{
					*dest = std::move(*first);
				}
			}

			--last;
			last->~T();
			m_Size -= 1;
		}

		void insert(Iterator position,const T& data)
		{
			/*IMPORTANT: THIS FUNCTION IS NOT WORKING PROPERLY NEEDS IMPROVEMENT*/
#if 1
			if (!(m_Size >= m_Capacity))
			{
				T* dest0 = const_cast<T*>(position.m_Ptr);
				T* dest = const_cast<T*>(position.m_Ptr);
				T* first = dest + 1;
				T* last = m_Data + m_Size;


				T tempdata = *first;
				*first = std::move(*dest);
				++first;
				*dest = std::move(tempdata);

				for (; first != (last + 1); ++first)
				{
					if (first == last)
					{
						//*first = std::move(*dest0);
						//*first = std::string();
						//*first = *dest0;
					//	new(&(*first)) T(*dest0);
						new(&(*first)) T(std::move(*dest0));
						break;
					}

					T tempdata = *first;
					*first = std::move(*dest0);
					*dest0 = tempdata;
				}

				*dest0 = std::move(data);
				m_Size += 1;
			}
#endif
		}

		T& operator[](size_t index)
		{
			if (index >= m_Size)
			{
				// assert
			}
			return m_Data[index];
		}

		const T& operator[](size_t index) const
		{
			return m_Data[index];
		}

		size_t Size() const { return m_Size; }


		Iterator begin()
		{
			return Iterator(m_Data);
		} 

		Iterator end()
		{
			return Iterator(m_Data + m_Size);
		} 
	private:

		void ReAlloc(size_t newCapacity)
		{
			T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

			if (newCapacity < m_Size)
			{
				m_Size = newCapacity;
			}


			for (size_t i = 0; i < m_Size; i++)
			{
				new(&newBlock[i]) T(std::move(m_Data[i]));
			}

			for (size_t i = 0; i < m_Size; i++)
			{
				m_Data[i].~T();
			}

			::operator delete(m_Data, m_Capacity * sizeof(T));
			m_Data = newBlock;
			m_Capacity = newCapacity; 
		}

	private:
		T* m_Data = nullptr;

		T* m_TestIt = nullptr;

		size_t m_Size = 0;
		size_t m_Capacity = 0;
	};
}