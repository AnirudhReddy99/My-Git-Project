#include<iostream>
using namespace std;
class node
{
	public:
	int row;
	int column;
	int Data;
	node *next;
};
void create_newnode(node **p, int row_index,
					int column_index, int x)
{
	node *temp_v = *p;
	node *r;
	if (temp_v == NULL)
	{
		temp_v = new node();
		temp_v->row = row_index;
		temp_v->column = column_index;
		temp_v->Data = x;
		temp_v->next = NULL;
		*p = temp_v;
	}
	else
	{
		while (temp_v->next != NULL)
			temp_v = temp_v->next;
		r = new node();
		r->row = row_index;
		r->column = column_index;		r->Data = x;
		r->next = NULL;
		temp_v->next = r;
	}
}
void printList(node *start)
{
	node *ptr = start;
	cout << "Row-Position:";
	while (ptr != NULL)
	{
		cout << ptr->row << " ";
		ptr = ptr->next;
	}
	cout << endl;
	cout << "Column-Position:";

	ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->column << " ";
		ptr = ptr->next;
	}
	cout << endl;
	cout << "Value:";
	ptr = start;
	
	while (ptr != NULL)
	{
		cout << ptr->Data << " ";
		ptr = ptr->next;
	}
}
int main()
{
	int SparseMatrix[4][5] = { { 0 , 0 , 3 , 0 , 4 },
							{ 0 , 0 , 5 , 7 , 0 },
							{ 0 , 0 , 0 , 0 , 0 },
							{ 0 , 2 , 6 , 0 , 0 } };

	node *first = NULL;
	for(int I = 0; I< 4; I++)
	{
		for(int J = 0; J < 5; J++)
		{
			if (SparseMatrix[I][J] != 0)
				create_newnode(&first, I, J,
								SparseMatrix[I][J]);
		}
	}
	printList(first);

	return 0;
}
