#include <iostream>

using namespace std;

template <class T>
struct Node
{
	Node(T v) : value(v){}
	T value;
	Node *left = nullptr, *right = nullptr;
};

template <class T>
class BST
{
public:
	~BST()
	{
		while(top && remove(top->value));
	}
	
	void insert(T v)
	{
		insert(new Node(v), top);
	}
	
	bool remove(T v)
	{
		if(top)
		{
			if(top->value == v)
			{
				Node <T> *tmp = top;
				remove(tmp, top);
				top = tmp;
			}
			else
				remove(v, top);
			
			return true;
		}
		
		return false;
	}
	
	void preOrder()
	{
		preOrder(top);
	}
	
	void postOrder()
	{
		postOrder(top);
	}
	
	void inOrder()
	{
		inOrder(top);
	}
	
private:
	void insert(Node <T> *v, Node <T>* &top)
	{
		if(!top) top = v;
		else if(v->value < top->value) insert(v, top->left);
		else if(v->value > top->value) insert(v, top->right);
	}
	
	void remove(Node <T>* &top, Node <T>* &tmp)
	{
		if(tmp->left && tmp->right)
		{
			Node <T> *max = tmp->left, *old = max;
			for(; max->right; old = max, max = max->right);
			tmp->value = max->value;
			old->right = nullptr;
			if(max == tmp->left)
				tmp->left = max->left;
			tmp = max;
		}
		else if(!tmp->left && tmp->right)
			top = tmp->right;
		else if(tmp->left && !tmp->right)
			top = tmp->left;
		else
			top = nullptr;
		delete tmp;
	}
	
	Node <T> * remove(T v, Node <T> *top)
	{
		if(!top) return nullptr;
		Node <T> *tmp;
		if(v == top->value)
			return top;
		else if(v < top->value && (tmp = remove(v, top->left)))
			remove(top->left, tmp);
		else if(tmp = remove(v, top->right))
			remove(top->right, tmp);
		
		return nullptr;
	}
	
	void preOrder(Node <T> *top)
	{
		if(!top)
			return;
		
		cout<<top->value<<endl;
		preOrder(top->left);
		preOrder(top->right);
	}
	
	void postOrder(Node <T> *top)
	{
		if(!top)
			return;
		
		postOrder(top->left);
		postOrder(top->right);
		cout<<top->value<<endl;
	}
	
	void inOrder(Node <T> *top)
	{
		if(!top)
			return;
		
		inOrder(top->left);
		cout<<top->value<<endl;
		inOrder(top->right);
	}
	
	Node <T> *top = nullptr;
};

int main()
{
	BST <int> test;

	test.insert(4);
	test.insert(5);
	test.insert(2);
	test.insert(9);
	test.insert(1);
	test.insert(3);
	
	test.remove(2);
	
	cout<<"inorder:\n";
	test.inOrder();
	cout<<"preorder:\n";
	test.preOrder();
	cout<<"postorder:\n";
	test.postOrder();
}
