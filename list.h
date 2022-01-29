// JAVIDSTL. Created By Javid Mamedov.
#pragma once

template<typename T>
class ListNode
{
public:

	ListNode()
	{

	}

	ListNode(const T& data)
	{
		this->data = data;
	}

	ListNode<T>* const getnext() const
	{
		return next;
	}

	ListNode<T>* getnext() 
	{
		return next;
	}

	void setnext(ListNode<T>* newnext)
	{
		next = newnext;
	}

	ListNode<T>* const getprev() const
	{
		return prev;
	}

	ListNode<T>* getprev()
	{
		return prev;
	}

	T& getdata()
	{
		return data;
	}

private:
	ListNode<T>* next = nullptr;
	ListNode<T>* prev = nullptr;
	T data;
};

template<typename T>
class List
{

public:

	List() {}

	List(const T& data)
	{
		if (!head)
		{
			head = new ListNode<T>(data);
			m_Size += 1;
		}
	}

	~List()
	{
		Clear(head);
	}

	ListNode<T>& operator[](size_t index)
	{
		ListNode<T>* copyhead = head;
		if (index == 0)
		{
			return *copyhead;
		}
		while (index != -1 && copyhead->getnext() != nullptr)
		{
			if (index == 0)
			{
				return *copyhead;
			}
			copyhead = copyhead->getnext();
			index -= 1;
	    }
	}

	void InsertNodeAtBeginning(const T& data)
	{
		ListNode<T>* newdata = new ListNode<T>(data);

		if (head != nullptr)
		{
			ListNode<T>* copyhead = head;
			head = newdata;
			head->setnext(copyhead); 
			m_Size += 1;
		}
		else
		{
			head = newdata;
			m_Size += 1;
		}
	}

	void InsertNode(const T& data, size_t position)
	{
		if (position == 0)
		{
			InsertNodeAtBeginning(data);
		}
		else if (position == GetSize() + 1)
		{
			ListNode<T>* copydata = head;
			ListNode<T>* newdata = new ListNode<T>(data);
			while (copydata != nullptr)
			{
				if (copydata->getnext() == nullptr)
				{
					copydata->setnext(newdata);
					return;
				}
				copydata = copydata->getnext();
			}
		}
		else if (position <= GetSize())
		{
			ListNode<T>* newdata = new ListNode<T>(data);

			if (position == 1)
			{
				newdata->setnext(head);
				head = newdata;
				return;
			}
			
			ListNode<T>* tempdata = head;
			for (size_t i = 0; i < position - 2; i++)
			{
				tempdata = tempdata->getnext();
			}
			newdata->setnext(tempdata->getnext());
			tempdata->setnext(newdata);
			m_Size += 1;
		}
	}

	/*SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {

		SinglyLinkedListNode* newdata = new SinglyLinkedListNode(data);
		if (!head)
		{
			head = newdata;
			return head;
		}
		else {
			head->next = insertNodeAtTail(head->next, data);
			return head;
		}
	} */



	/*Node* removeDuplicates(Node* head)
	{
		if (head)
		{
			if (head->next)
			{
				if (head->data == head->next->data)
				{
					Node* temp = head->next;
					head->next = head->next->next;
					delete temp;
					// if duplication is founded we still finding next to see if there's another duplication or not
					// if duplication if founded we checking with the same node to see if there's another duplication of this node or not
					return removeDuplicates(head);
				}
				else {
					// if we find 0 duplication then we run with next node
					// if next of this node is not duplication of this node we 
					// setting node to next
					removeDuplicates(head->next);
					return head;
				}
			}
			else {
				return head;
			}
		}
		{
			return nullptr;
		}
	} */


	/*
	
	SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
  SinglyLinkedListNode* temp = llist;
  
  while (temp != nullptr)
  {
      SinglyLinkedListNode* ptr = temp;
      
      if (temp->next != nullptr)
      {
         if (temp->data == temp->next->data)
         {
             SinglyLinkedListNode* ptr1 = temp->next;
             temp->next = temp->next->next;
             delete ptr1;
         }
         else {
            temp = temp->next;
         } 
      }
      else {
      
         return llist;
      }
  }
  
  return llist;
}
	
	*/


	/*
	
	The old "tortoise and the hare" problem. Essentially, the "fast" pointer moves 2x the speed as the "slow" pointer. If there is a cycle, they will meet.
	
	
	bool has_cycle(SinglyLinkedListNode* head) {

		if (head == nullptr) {
			return 0;
		}

		SinglyLinkedListNode* slow = head;
		SinglyLinkedListNode* fast = head;
		int i = 0;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			i++;
			if (slow == fast) {
				return 1;
			}
		}

		return 0;
	} */

	/*
	
	bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

  SinglyLinkedListNode* h1 = head1;
  SinglyLinkedListNode* h2 = head2;
  
  while(h1 && h2)
  {
      if (h1->data == h2->data)
      {
          h1 = h1->next;
        h2 = h2->next;
      }
      else {
        return false;
      }

  }
  if (h1 && !h2)
  {
              return false;
  }
    if (h2 && !h1)
  {
              return false;
  }
  return true;
}
	
	*/

/*

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
  DoublyLinkedListNode* temp = llist;
  while (temp)
  {
	  if (temp->next == nullptr)
	  {
		  llist = temp;
	  }
	  DoublyLinkedListNode* ptr = temp->next;
	  temp->next = temp->prev;
	  temp = ptr;
  }

  return llist;
}

*/

/*

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

  SinglyLinkedListNode* h1 = head1;
  SinglyLinkedListNode* h2 = head2;

  if (h1 == nullptr)
  {
	  return h2;
  }
  if (h2 == nullptr)
  {
	  return h1;
  }

  while (h1->next != nullptr)
  {
	  h1 = h1->next;
  }

  h1->next = head2;

  SinglyLinkedListNode* c = head1;

  while (c != nullptr)
  {
		SinglyLinkedListNode* n = c;
		SinglyLinkedListNode* d = c;
		while (n != nullptr)
		{
			if (n->data < d->data)
			{
				d = n;
			}
			n = n->next;
		}

		int t = c->data;
		c->data = d->data;
		d->data = t;

	  c = c->next;
  }

  return head1;
}

*/

/*

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {

  SinglyLinkedListNode* current = llist;
  int size = 0;
  while (current != nullptr)
  {
	  size++;
	  current = current->next;
  }
  std::cout << size << " " << positionFromTail << " " << size - positionFromTail << "\n";
  int newsize = size - positionFromTail;
	SinglyLinkedListNode* current1 = llist;
  while (newsize != 1)
  {
	  --newsize;
	  current1 = current1->next;
  }
  return current1->data;
}

*/

/*

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

 SinglyLinkedListNode* currentA = head1;
  SinglyLinkedListNode* currentB = head2;

	//Do till the two nodes are the same
	while(currentA != currentB){
		//If you reached the end of one list start at the beginning of the other one
		//currentA
		if(currentA->next == nullptr){
			currentA = head2;
		}else{
			currentA = currentA->next;
		}
		//currentB
		if(currentB->next == nullptr){
			currentB = head1;
		}else{
			currentB = currentB->next;
		}
	}
	return currentB->data;
  }

*/

/*

bool has_cycle(Node* head) {
	Node* arr[100];
	Node* temp = head;
	bool bfound = false;
	int i = 0;
	while (!bfound || i < 100)
	{
		if (temp)
		{
		for (int j =0; j < i; j++)
		{
			if (arr[j])
			{

			if (temp == arr[j])
			{
				bfound = true;
				return true;
				break;
			}
			}
		 }

		arr[i] = temp;
		temp = temp->next;

		i++;
		continue;
		}
		break;
	}

	return false;
}

*/

	void DeleteNode(size_t position)
	{
		ListNode<T>* tempdata = head;
		while (position != 0)
		{
			position -= 1;
			if (position == 0)
			{
				ListNode<T>* tempdata1 = tempdata->getnext();
				tempdata->setnext(tempdata->getnext()->getnext());
				delete tempdata1;
				return;
			}
			tempdata = tempdata->getnext();
		}
		if (position == 0)
		{
			if (tempdata->getnext() != nullptr)
			{
				head = head->getnext();
				delete tempdata;
			}
			else
			{
				delete head;
			}
		}
	}

	void Reverse()
	{
		ListNode<T>* current, *prev, *next;
		current = head;
		prev = nullptr;
		while (current != nullptr)
		{
			next = current->getnext();
			current->setnext(prev);
			prev = current;
			current = next;
		}
		head = prev;
	}

	void Clear(ListNode<T>* node)
	{
		if (node)
		{
			ListNode<T>* nextnode = node->getnext();
			Clear(nextnode);
			std::cout << "deleted : " << node->getdata() << "\n";
			delete node;
			//node.~T();
			// delete node;
		}
		head = nullptr;
	}

	ListNode<T>* Reverse(ListNode<T>* p)
	{
		if (p->getnext() == nullptr)
		{
			head = p;
			return head;
		}
		Reverse(p->getnext());
		ListNode<T>* q = p->getnext();
		q->setnext(p);
		p->setnext(nullptr);
		return head;
	}

	void PrintElements()
	{
		ListNode<T>* copydata = head;

		while (copydata != nullptr)
		{
			std::cout << copydata->getdata() << std::endl;
			copydata = copydata->getnext();
		}
	}

	void PrintElements(ListNode<T>* p)
	{
		if (p != nullptr)
		{
			std::cout << p->getdata() << std::endl;
			PrintElements(p->getnext());
		}
	}

	void PrintElementsReverse(ListNode<T>* p)
	{
		if (p != nullptr)
		{
			PrintElementsReverse(p->getnext());
			std::cout << p->getdata() << std::endl;
		}
	}

	void SetHead(ListNode<T>* p)
	{
		head = p;
	}

	size_t GetSize()
	{
		size_t size = 0;
		ListNode<T>* copydata = head;
		while (copydata != nullptr)
		{
			size += 1;
			copydata = copydata->getnext();
		}

		return size;
	}

	ListNode<T>* GetHead() 
	{
		return head;
	}

	const ListNode<T>* GetHead() const
	{
		return head;
	}

	size_t Size()
	{
		return m_Size;
	}
private:
	size_t m_Size = 0;
	ListNode<T>* head;
	ListNode<T>* tail;
};