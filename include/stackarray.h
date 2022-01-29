// JAVIDSTL. Created By Javid Mamedov.
#pragma once


namespace JAVIDSTL
{

	template<typename T, size_t S>
	class StackArray
	{

	public:

		void Push(const T& data)
		{
			m_Data[++m_Size] = data;
		}

		void Pop()
		{
			m_Size--;
		}

		bool IsEmpty()
		{
			if (m_Size > -1)
				return true;
			return false;
		}

		T& Top()
		{
			return m_Data[m_Size];
		}

		T& operator[](size_t index) 
		{
			if (index <= m_Size)
				return m_Data[index];
			else
				throw std::invalid_argument("index is out of range !"); /*STD usage*/
		}

	private:
		int m_Size = -1;
		T m_Data[S];
	};

}
