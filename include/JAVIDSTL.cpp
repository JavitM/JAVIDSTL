// JAVIDSTL. Created By Javid Mamedov.
/*

#include <iostream>
#include "array.h"
#include "vector.h"
#include "list.h"
#include "stackarray.h"
#include "queuearray.h"
#include "tree.h"
#include "string.h"
#include "sort.h"

template<typename T>
void PrintVector(const JAVIDSTL::Vector<T>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}

	std::cout << "-----------------------\n";
}
struct Vector3
{
	int x = 0, y = 0, z = 0;
	int* m_MemoryBlock = nullptr;


	Vector3() { m_MemoryBlock = new int[5]; }
	Vector3(int scalar)
		: x(scalar), y(scalar), z(scalar) {

		m_MemoryBlock = new int[5];
	}

	Vector3(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		m_MemoryBlock = new int[5];
	}

	Vector3(const Vector3& other)
	{
		std::cout << other.x;
		m_MemoryBlock = new int[5];
		std::cout << " Copy Constructor\n";
		x = other.x;
		y = other.y;
		z = other.z;
	}

	Vector3(Vector3&& other)
		: x(other.x), y(other.y), z(other.z)
	{
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		std::cout << "Moved\n";
	}

	~Vector3()
	{
		std::cout << x << " Destroy\n";
		if (m_MemoryBlock)
		{
			delete[] m_MemoryBlock;
		}
	//	delete[] m_MemoryBlock;
	}

	Vector3& operator=(const Vector3& other)
	{
		*m_MemoryBlock = *other.m_MemoryBlock;
		std::cout << "Copy\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;

	}

	Vector3& operator=(Vector3&& other)
	{
		std::cout << "Move\n";
		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}
};


template<>
void PrintVector(const JAVIDSTL::Vector<Vector3>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
	}

	std::cout << "-----------------------\n";
}

void ReverseUsingStack(std::string& data,const size_t size)
{
	size_t tempsize = 0;
	JAVIDSTL::StackArray<char, 100> S;

	for (; tempsize != size; tempsize++)
	{
		S.Push(data[tempsize]);
	}

	for (size_t i = 0; i < size; i++)
	{
		std::cout << "For func : " << i << " " << S.Top() << "\n";
		data[i] = S.Top(); 
		S.Pop();
	}
}

void ReverseUsingStack(List<int> list, const size_t size)
{
	ListNode<int>* temp = list.GetHead();
	JAVIDSTL::StackArray<ListNode<int>*, 100> S;

	while (temp != nullptr)
	{
		S.Push(temp);
		temp = temp->getnext();
	}

	ListNode<int>* temp1 = S.Top();
	list.SetHead(temp1);
	S.Pop();

	while (S.IsEmpty())
	{
		std::cout << S.Top()->getdata() << "\n";
		temp1->setnext(S.Top());
		S.Pop();
		temp1 = temp1->getnext();
	}

	temp1->setnext(nullptr);
}

/*int main()
//{
//	JAVIDSTL::Vector<std::string> Vector;
//	Vector.EmplaceBack("Javit");
//	Vector.EmplaceBack("Javit1");
//	Vector.EmplaceBack("Javit2");
//	Vector.EmplaceBack("Javit4");
//	Vector.EmplaceBack("Javit5");

//	PrintVector(Vector);

//	std::string javit3 = "Javit3";
//	Vector.insert(Vector.begin() + 3, javit3);

//	PrintVector(Vector);  

	
/*	JAVIDSTL::Vector<int> VectorInt;
	VectorInt.EmplaceBack(1);
	VectorInt.EmplaceBack(2);
	VectorInt.EmplaceBack(3);
	VectorInt.EmplaceBack(4);
	VectorInt.EmplaceBack(5);
	VectorInt.EmplaceBack(7);
	VectorInt.EmplaceBack(8);
	VectorInt.EmplaceBack(9);
	VectorInt.EmplaceBack(10);
	VectorInt.EmplaceBack(11);

	PrintVector(VectorInt);

	VectorInt.insert(VectorInt.begin() + 5, 6);

	PrintVector(VectorInt); */


//	List<std::string> Listt(std::string("Kuzey"));
//	Listt.InsertNodeAtBeginning(std::string("Guney"));
//	Listt.InsertNodeAtBeginning(std::string("Simay"));
	//Listt.InsertNodeAtBeginning(std::string("Ferad"));
	//Listt.InsertNodeAtBeginning(std::string("Bagnu"));
//	Listt.InsertNodeAtBeginning(std::string("Handan"));
	//Listt.InsertNodeAtBeginning(std::string("Geri Bas Lan"));
	//Listt.InsertNodeAtBeginning(std::string("Step Back Lan"));

//	Listt.PrintElements(Listt.GetHead());
	//Listt.Clear(Listt.GetHead());
//	if (Listt.GetHead())
//	{
	//	std::cout << "head is valid \n";
//	}
/*	std::cout << "------------------------\n";

	Listt.DeleteNode(0);
	Listt.PrintElements();
	std::cout << "------------------------\n";

	std::cout << Listt.GetSize() << "\n";

	std::cout << "------------------------\n";

	Listt.InsertNode(std::string("TekinOgullari"), 3);

	Listt.PrintElements();
	std::cout << "------------------------\n";


	Listt.Reverse();

	Listt.PrintElements();
	std::cout << "------------------------\n";

	Listt.PrintElementsReverse(Listt.GetHead());

	std::cout << "------------------------\n";

	Listt.InsertNode(std::string("Tekinogullari Firin"), 9);

	Listt.PrintElements();
	std::cout << "------------------------\n";

	std::cout << Listt.Reverse(Listt.GetHead())->getdata(); */

/*	JAVIDSTL::StackArray<int, 10> SA;
	List<int> intlist;
	intlist.InsertNodeAtBeginning(1);
	intlist.InsertNode(2, intlist.GetSize() + 1);
	intlist.InsertNode(3, intlist.GetSize() + 1);
	intlist.InsertNode(4, intlist.GetSize() + 1);
	intlist.InsertNode(5, intlist.GetSize() + 1);
	intlist.InsertNode(6, intlist.GetSize() + 1);
	intlist.InsertNode(7, intlist.GetSize() + 1);


	SA.Push(20);
	SA.Push(21);
	SA.Push(22);
	SA.Push(23);
	SA.Push(24);
	SA.Push(25);
	SA.Push(26);

	std::cout << SA[0] << " " << SA[1] << " " << SA[2] << " " << SA[3] << " " << SA[4] << " " << SA[5] << " " << SA[6] << "\n";

	SA.Pop();
	SA.Pop();

	//std::cout << SA[0] << " " << SA[1] << " " << SA[2] << " " << SA[3] << " " << SA[4] << " " << SA[5] << " " << SA[6] << "\n";

	std::string teststring("Javit");
	ReverseUsingStack(teststring, teststring.length());
	std::cout << teststring << "\n";

	intlist.PrintElements();
	std::cout << "----------------\n";
	ReverseUsingStack(intlist, intlist.GetSize());
	intlist.PrintElements();

	std::cout << "----------------\n";

	queuearray<int, 10> qa;

	qa.Enqueue(5);
	qa.Enqueue(9);
	qa.Enqueue(0);

	qa.PrintElements(); */

/*	BST<int> testbst;
	testbst.root = new BSTNode<int>(8);
	testbst.Insert(testbst.root, 6);
	testbst.Insert(testbst.root, 5);
		testbst.Insert(testbst.root, 16);
		testbst.Insert(testbst.root, 17);
		testbst.Insert(testbst.root, 18);
		testbst.Insert(testbst.root, 19);
		testbst.Insert(testbst.root, 20);
	testbst.Insert(testbst.root, 25);
	testbst.Insert(testbst.root, 8);
	testbst.Insert(testbst.root, 9);

	BSTNode<int>* test = testbst.Find(testbst.GetRoot(), 10);

	if (test)
	{
		std::cout << "10 is founded in tree\n";
	}
	else
	{
		std::cout << "10 is not founded in tree\n";
	}

	std::cout << testbst.FindHeight(testbst.GetRoot());

/*	if (testbst.Search(testbst.GetRoot(), 5))
	{
		std::cout << "found: 5 \n";
	}
	else
	{
		std::cout << "not found: 5 \n";
	} */
/*	if (testbst.Search(testbst.GetRoot(), 10))
	{
		std::cout << "found: 10 \n";
	}
	else
	{
		std::cout << "not found: 10 \n";
	}
	if (testbst.Search(testbst.GetRoot(), 11))
	{
		std::cout << "found: 11 \n";
	}
	else
	{
		std::cout << "not found: 11 \n";
	}
	if (testbst.Search(testbst.GetRoot(), 12))
	{
		std::cout << "found: 12 \n";
	}
	else
	{
		std::cout << "not found: 12 \n";
	}
	if (testbst.Search(testbst.GetRoot(), 13))
	{
		std::cout << "found: 13 \n";
	}
	else
	{
		std::cout << "not found: 13 \n";
	}

	std::cout << "Min : " << testbst.FindMin() << " Max : " << testbst.FindMax() << "\n";

	testbst.LevelOrderTraversal(); 

	JAVIDSTL::Array<int, 10> array;
	std::cout << "\n";
	array[0] = 1;
	array[1] = 8;
	array[2] = 20;
	array[3] = 30;
	array[4] = -24;
	array[5] = 0;
	array[6] = 98;
	array[7] = 500;
	array[8] = 10000000;
	array[9] = 10;

	for (auto a : array)
	{
		std::cout << a << "\n";
	}

	//String str = "Test";
	//std::cout << str << "\n";
	//str = "rfafa";
	//std::cout << str << "\n";
	
	//str[0] = 's';

	//std::cout << str << "\n";

    BubbleSort<array.Size()>(array);
	std::cout << "--------------------\n";
	for (auto a : array)
	{
		std::cout << a << "\n";
	}

	JAVIDSTL::Array<int, 10> A;
	std::cout << "\n";
	A[0] = 1;
	A[1] = 8;
	A[2] = 20;
	A[3] = 30;
	A[4] = -24;
	A[5] = 0;
	A[6] = 98;
	A[7] = 500;
	A[8] = 10000000;
	A[9] = 10;

	std::cout << "\n-------------\n";

	for (int i = 0; i < 10; i++)
	{
	std::cout << A[i] << " ";
	}

	std::cout << "AFTER QUICK SORT-------------\n";

	//SelectionSort(A, 10);
	//BubbleSort(A, 10);
	//InsertionSort(A, 10);
	QuickSort<10>(A,0,9);

	for (int i = 0; i < 10; i++)
	{
	std::cout << A[i] << " ";
	}
}  */ 

