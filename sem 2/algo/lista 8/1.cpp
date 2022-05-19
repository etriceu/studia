#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
	Node(int v, string n, Node *l, Node *r, int height)
		: value(v), osoba(n), h(height), left(l), right(r){}
	int value;
	string osoba;
	int h;
	Node *left, *right;
};

int getHeight(Node *node)
{
	return !node ? -1 : node->h;
}

Node* RR(Node *node)
{
	Node *left = node->left;
	node->left = left->right;
	left->right = node;
	node->h = max(getHeight(node->left), getHeight(node->right))+1;
	left->h = max(getHeight(left->left), node->h)+1;
	return left;
}

Node* LL(Node *node)
{
	Node *right = node->right;
	node->right = right->left;
	right->left = node;
	node->h = max(getHeight(node->left), getHeight(node->right))+1;
	right->h = max(getHeight(right->right), node->h)+1;
	return right;
}

Node * LR(Node *node)
{
	node->left = LL(node->left);
	return RR(node);
}

Node * RL(Node *node)
{
	node->right = RR(node->right);
	return LL(node);
}

Node* insert(int value, string osoba, Node *node)
{
	if(!node) return node = new Node(value, osoba, nullptr, nullptr, 0);
	else if(value < node->value) node->left = insert(value, osoba, node->left);
	else if(value > node->value) node->right = insert(value, osoba, node->right);
	
	node->h = max(getHeight(node->left), getHeight(node->right))+1;
	if(getHeight(node->left) - getHeight(node->right) == 2)
		node = value < node->left->value ? RR(node) : LR(node);
	else if(getHeight(node->right) - getHeight(node->left) == 2)
		node = value < node->right->value ? RL(node) : LL(node);
	
	return node;
}

Node* remove(int value, Node *node)
{
	if(!node)
		return nullptr;
	
	if(value == node->value)
	{
		if(!node->right)
		{
			Node *tmp = node;
			node = node->left;
			delete tmp;
			return node;
		}
		
		Node *tmp = node->right;
		for(; tmp->left; tmp = tmp->left);
		node->value = tmp->value;
		node->osoba = tmp->osoba;
		node->right = remove(tmp->value, node->right);
	}
	else if(value < node->value)
		node->left = remove(value, node->left);
	else
		node->right = remove(value, node->right);
	
	node->h = max(getHeight(node->left), getHeight(node->right))+1;
	if(getHeight(node->right) - getHeight(node->left) == 2)
		node = getHeight(node->right->right) >= getHeight(node->right->left) ?
			LL(node) : RL(node);
	else if(getHeight(node->left) - getHeight(node->right) == 2)
		node = getHeight(node->left->left) >= getHeight(node->left->right) ?
			RR(node) : LR(node);
	
	return node;
}

Node* edit(int value, int newValue, string n, Node* node)
{
	Node *tmp = remove(value, node);
	return insert(newValue, n, tmp);
}

void save(fstream &file, Node *node)
{
	if(!node)
		return;
	
	save(file, node->left);
	save(file, node->right);
	file.write((const char*)&node->value, sizeof(node->value));
	size_t size = node->osoba.size();
	file.write((const char*)&size, sizeof(size));
	file<<node->osoba;
}

Node* read(fstream &file)
{
	Node *node = nullptr;
	while(!file.eof())
	{
		int v;
		size_t s;
		file.read((char*)&v, sizeof(v));
		file.read((char*)&s, sizeof(s));
		char *tmp = new char[s];
		file.read(tmp, s);
		node = insert(v, string(tmp, tmp+s), node);
		delete tmp;
	}
	return node;
}

void preOrder(Node *top)
{
	if(!top)
		return;
	
	cout<<top->value<<" "<<top->osoba<<endl;
	preOrder(top->left);
	preOrder(top->right);
}

void postOrder(Node *top)
{
	if(!top)
		return;
	
	postOrder(top->left);
	postOrder(top->right);
	cout<<top->value<<" "<<top->osoba<<endl;
}

void inOrder(Node *top)
{
	if(!top)
		return;
	
	inOrder(top->left);
	cout<<top->value<<" "<<top->osoba<<endl;
	inOrder(top->right);
}

int main()
{
	Node *test = nullptr;

	test = insert(4, "Aas", test);
	test = insert(5, "Sdf", test);
	test = insert(2, "Gsd", test);
	test = insert(9, "Tsd", test);
	test = insert(1, "Gfdg", test);
	test = insert(3, "Hsd", test);
	
	test = edit(9, -1, "Ggg", test);
	
	test = remove(2, test);
	
	fstream file;
	file.open("test", ios::out);
	save(file, test);
	file.close();
	
	cout<<"inorder:\n";
	inOrder(test);
	cout<<"preorder:\n";
	preOrder(test);
	cout<<"postorder:\n";
	postOrder(test);
}
