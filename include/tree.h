// JAVIDSTL. Created By Javid Mamedov.
#pragma once
#include "queuearray.h"
#include "core.h"

template<typename T>
class BSTNode
{

public:
	BSTNode()
	{

	}

	BSTNode(const T& data)
	{
		this->data = data;
	}

	T& GetData()
	{
		return data;
	}

	BSTNode<T>* GetLeft()
	{
		return left;
	}

	BSTNode<T>* GetRight()
	{
		return right;
	}

	BSTNode<T>* GetParent()
	{
		return parent;
	}

	void SetLeft(BSTNode<T>* newleft)
	{
		left = newleft;
	}
	
	void SetRight(BSTNode<T>* newright)
	{
		right = newright;
	}

	void SetParent(BSTNode<T>* newparent)
	{
		parent = newparent;
	}

	void SetData(const T& data)
	{
		this->data = data;
	}
private:
	T data;
	BSTNode<T>* left = nullptr;
	BSTNode<T>* right = nullptr;
	BSTNode<T>* parent = nullptr;
};

template<typename T>
class BST
{
public:

	BST()
	{

	}

	BSTNode<T>* Insert(BSTNode<T>* roott,const T& data)
	{
		BSTNode<T>** temp = &roott;
		if (*temp == nullptr)
		{
			std::cout << "Created Node With : " << data << "\n";
			*temp = new BSTNode<T>(data);
			return *temp;
		}
		else if (data <= (*temp)->GetData())
		{
			(*temp)->SetLeft(Insert((*temp)->GetLeft(), data));
		}
		else if (data > (*temp)->GetData())
		{
			(*temp)->SetRight(Insert((*temp)->GetRight(), data));
		} 
	}


	void LevelOrderTraversal()
	{
		/*STD LIBRARY USAGE*/
		if (root)
		{
			queuearray<BSTNode<T>*, 100> qa;
			qa.Enqueue(root);
			while (!qa.IsEmpty())
			{
				BSTNode<T>* current = qa.GetFrontData();
				std::cout << current->GetData() << " ";
				if (current->GetData() == 1)
				{
					qa.GetFront();
				}
				if (current->GetLeft() != nullptr)
				{
					qa.Enqueue(current->GetLeft());
				}
				if (current->GetRight() != nullptr)
				{
					qa.Enqueue(current->GetRight());
				}
				qa.Dequeue();
			}

		}
	}

	void PreorderTraversal(BSTNode<T>* root)
	{
		if (root)
		{
			printf("%c", root->GetData());

			PreorderTraversal(root->GetLeft());
			PreorderTraversal(root->GetRight());
		}
	}

	void PostorderTraversal(BSTNode<T>* root)
	{
		if (root)
		{
			PostorderTraversal(root->GetLeft());
			PostorderTraversal(root->GetRight());
			printf("%c", root->GetData());
		}
	}

	void InorderTraversal(BSTNode<T>* root)
	{
		if (root)
		{
			InorderTraversal(root->GetLeft());
			printf("%c", root->GetData());
			InorderTraversal(root->GetRight());
		}
	}

	BSTNode<T>* Getsuccessor(BSTNode<T>* root, const T& data)
	{
		BSTNode<T>* current = Find(root, data);
		if (current == nullptr) { return nullptr; }

		if (current->GetRight() != nullptr)
		{
			return FindMinNode(current->GetRight());
		}
		else
		{
			BSTNode<T>* successor = nullptr;
			BSTNode<T>* ancestor = root;

			while (ancestor != current)
			{
				if (current->GetData() < ancestor->GetData())
				{
					successor = ancestor;
					ancestor = ancestor->GetLeft();
				}
				else
				{
					ancestor = ancestor->GetRight();
				}
			}

			return successor;
		}
	}

	BSTNode<T>* Delete(BSTNode<T>* root, const T& data)
	{
		if (root == nullptr) { return nullptr; }

		else if (data < root->GetData()) { root->SetLeft(Delete(root->GetLeft(), data)); } // { root->SetLeft(Delete(root->GetLeft(), data)); return Delete(root->GetLeft(), data); } 
		else if (data > root->GetData()) { root->SetRight(Delete(root->GetRight(), data)); } // { root->SetRight(Delete(root->GetRight(), data));  return Delete(root->GetRight(), data); } 

		else
		{
			if (root->GetLeft() == nullptr && root->GetRight() == nullptr)
			{
				delete root;
				root = nullptr; // after deletion, to get read of dangling, we set root to NULL, since root's pointed data is deleted, however it still holds that deleted adress
				return root;
			}

			else if (root->GetLeft() == nullptr)
			{
				BSTNode<T>* temp = root;
				root = root->GetRight();
				delete temp;
				return root;
			}

			else if (root->GetRight() == nullptr)
			{
				BSTNode<T>* temp = root;
				root = root->GetLeft();
				delete temp;
				return root;
			}

			else
			{
				BSTNode<T>* temp = (BSTNode<T>*)FindMin(root->GetRight());
				root->SetData((*temp).GetData());
				root->SetRight(Delete(root->GetRight(), (*temp).GetData()));
			}
		}
	}

	bool Search(BSTNode<T>* root, const T& data)
	{
		if (root == nullptr) { std::cout << "BST Search : node is null \n"; return false; }
		else if (root->GetData() == data) { std::cout << "Search :" << root->GetData() << " " << data << " \n"; return true; }
		else if (data <= root->GetData()) { return Search(root->GetLeft(), data); }
		else { return Search(root->GetRight(), data); }
	}

	bool IsBSTUtil(BSTNode<T>* root, int MINValue, int MAXValue)
	{
		if (!root) { return true; }

		if (root->GetData() > MINValue && root->GetData() < MAXValue)
		{
			if (IsBSTUtil(root->GetLeft(), MINValue, root->GetData()) && IsBSTUtil(root->GetRight(), root->GetData(), MAXValue))
			{
				return true;
			}
		}
		return false;
	}

	bool IsBinarySearchTree(BSTNode<T>* root)
	{
		return IsBSTUtil(root, INT_MIN, INT_MAX);
	}

	BSTNode<T>* CreateNode(const T& data)
	{
		BSTNode<T>* newNode(data);
		return newNode;
	}

	T& FindMin(BSTNode<T>* root)
	{
		BSTNode<T>* current = root;

		while (current->GetLeft() != nullptr)
		{
			current = current->GetLeft();
		}
		return current->GetData();
	}

	BSTNode<T>* FindMinNode(BSTNode<T>* root)
	{
		if (root == nullptr) { return nullptr; }

		while (root->GetLeft() != nullptr)
		{
			root = root->GetLeft();
		}
		return root;
	}

	T& FindMax(BSTNode<T>* root)
	{
		BSTNode<T>* current = root;

		while (current->GetRight() != nullptr)
		{
			current = current->GetRight();
		}
		return current->GetData();
	}

	BSTNode<T>* Find(BSTNode<T>* root, const T& data)
	{
		if (root == nullptr) { return nullptr; }

		if (root->GetData() < data) { return Find(root->GetRight(), data); }
		else if (root->GetData() > data) { return Find(root->GetLeft(), data); }
		else if (root->GetData() == data) { return root; }

	}

	size_t FindHeight(BSTNode<T>* root)
	{
		if (root == nullptr) { return -1; }

		return JAVIDSTL::Utilities::Max(FindHeight(root->GetLeft()), FindHeight(root->GetRight())) + 1;
	}

	BSTNode<T>* GetRoot()
	{
		return root;
	}

	void SetRoot(BSTNode<T>* newroot)
	{
		root = newroot;
	}

	const BSTNode<T>* GetRoot() const
	{
		return root;
	}

public:
	BSTNode<T>* root = nullptr;
};
