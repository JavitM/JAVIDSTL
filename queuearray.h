// JAVIDSTL. Created By Javid Mamedov.
#pragma once



template<typename T, size_t S>
class queuearray
{

public:

	void Enqueue(const T& data)
	{
		GetFront();
		if (IsEmpty())
		{
			front = 0;
			rear = 0;
			m_Data[rear] = data;
		}
		else if (IsFull() == false)
		{
			int s = front;
			m_Data[++rear] = data;
			front = s;
		}
		else
		{
			throw std::invalid_argument("index is out of range !"); /*STD usage*/
		}
	}

	void Dequeue()
	{
		if (IsEmpty())
		{
			return;
		}
		else if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front += 1;
		}
	}

	void PrintElements()
	{
		for (size_t i = GetFront() + 1; i <= GetRear(); i++) // 0 | 0;
		{
			std::cout << m_Data[i] << std::endl;
		}
	}

	size_t GetFront()
	{
		return front;
	}

	T& GetFrontData()
	{
		return m_Data[front];
	}

	size_t GetRear()
	{
		return rear;
	}

	bool IsFull()
	{
		if (rear == (S))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsEmpty()
	{
		if (front == -1 && rear == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	T m_Data[S];
	size_t front = -1;
	size_t rear = -1;
};