#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* left ;
    Node* right;

	Node(int value)
	{
		data = value;
		left = right = NULL;
	}
};

class BST
{
public:
	Node* root;

	BST()
	{
		root = NULL;
	}

	Node* Insert(Node* r, int item)
	{
		if (r == NULL)
		{
			Node* newnode = new Node(item);
			r = newnode;
		}

		else if(item < r->data)
		r->left = Insert(r->left, item);

		else
		r->right= Insert(r->right, item);
	
		return r;
	}
	void Insert(int item)
	{
	  root = Insert(root, item);
	}


	void Preorder(Node* r) // root ->left->right
	{
		if (r == NULL)
		return;

		cout << r->data << "\t"; //r->data means that print the root data 
		Preorder(r->left);
		Preorder(r->right);
	}

	void Inorder(Node* r) // left->root -> right
	{
		if (r == NULL)
		return;
		
		Inorder(r->left);
		cout << r->data << "\t";
		Inorder(r->right);
	}
	
	void Postorder(Node* r) // left--> right->root 
	{
		if (r == NULL)
		return;

		Postorder(r->left);
		Postorder(r->right);
		cout << r->data << "\t";
	}


	Node* Search(Node* r, int key)
	{
		if (r == NULL)
		return NULL;

		else if (r->data == key)
		return r;

		else if (key < r->data)
		return	Search(r->left, key);

		else
		return Search(r->right, key);
	}
	bool Search(int key)
	{
		Node* result = Search(root, key);

		if (result == NULL)
			return false;
		else
			return true;
	}

	Node* Findmin(Node* r)
	{
		if (r == NULL)
			return NULL;
		else if (r->left == NULL)
			return r;
		else
			return Findmin(r->left);
	}

	Node* Findmax(Node* r)
	{
		if (r == NULL)
			return NULL;
		else if (r->right == NULL)
			return r;
		else
			return Findmax(r->right);
	}

	Node*  Delete(Node* r, int key)
	{
		if (r == NULL) // Empty Tree
			return NULL;
		if (key < r->data) // Item exists in left sub tree
			r->left = Delete(r->left, key);
		else if (key > r->data) // item exists in right sub tree
			  r->right =Delete(r->right, key);
		else
		{
			if (r->left == NULL && r->right == NULL) // leaf node
				r = NULL;
				// r = NULL
			else if (r->left != NULL && r->right == NULL) // one child on the left
			{
				r->data = r->left->data;
				delete r->left;
				r->left = NULL;
			}
			//r->left = NULL
			else if (r->left == NULL && r->right != NULL) // one child on the right
			{
				r->data = r->right->data;
				delete r->right;
				r->right = NULL;
			}
			//r->right = NULL
			else
			{
				Node* max = Findmax(r->left);
				r->data = max->data;
			   r->left=	Delete(r->left, max->data);
			}
		}
	    return r;
	}
};

int main()
{
	//45, 15, 79, 90, 10, 55, 12, 20, 50
	BST btree;
	btree.Insert(45);
	btree.Insert(15);
	btree.Insert(79);
	btree.Insert(90);
	btree.Insert(10);
	btree.Insert(55);
	btree.Insert(12);
	btree.Insert(20);
	btree.Insert(50);

	cout << " Display the Tree Contenet \n";
	btree.Preorder(btree.root);
	cout << "\n..............................................................................\n";
	btree.Inorder(btree.root);
	cout << "\n..............................................................................\n";
	btree.Postorder(btree.root);
	cout << "\n..............................................................................\n";

	int key;
	cout << " Enter item to search for \n";
	cin >> key ;
	if (btree.Search(key))
		cout << "Item Found \n";
	else
		cout << "Sorry , item not found \n";
	
	cout << "Find Minimum \n";
	Node *min = btree.Findmin(btree.root);
	if (min == 0)  
		cout << "No Items Exist";
	else
		cout << "Minimum is  " << min->data << "\n";

	cout << "Find Maximum \n";
	Node* max = btree.Findmax(btree.root);
	if (max == 0)
		cout << "No Items Exist \n";
	else
		cout << "Maximum is  " << max->data << "\n";

	cout << " \n Delete Items \n ";
	Node *result = btree.Delete (btree.root , 12);
	cout << "\n preorder After Delete 12 \n ";
	btree.Preorder(result);

	result = btree.Delete(btree.root, 15);
	cout << "\n preorder After Delete 15 \n ";
	btree.Preorder(result);
}