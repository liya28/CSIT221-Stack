#include "stack.h"
#include "node.h"
#include <iostream>

using namespace std;

class StackSingly : public Stack
{
	private:
		node *head;
		int size;
		
	public:
		StackSingly()
		{
			head = NULL;
			size = 0;	
		}
		
		~StackSingly()
		{
			node *temp;
			while (head)
			{
				temp = head;
				head = head->next;
				delete temp;
			}
			size = 0;
		}
		
		void push(int num)
		{
			node *n = new node;
			n->elem = num;
			n->next = head;
			head = n;
			
			size++;	
			cout << "Element " << num << " is added successfully.\n";
		}
		
		int pop() 
		{
			if (isEmpty())
			{
				cout << "Stack underflow.\n";
				return -1;
			}
			
			node *del = head;
			int ret = head->elem;
			head = head->next;
			size--;
			
			if (!isEmpty())
			{
				cout << ret << " is removed.\n";
				cout << "New head of the stack: " << head->elem;
			}
			else
			{
				cout << ret << " is removed. Stack is now empty.\n";
			}
			
			delete del;
			return ret;
		}
		
		int top()
		{
			if (isEmpty())
			{
				cout << "Stack is empty.\n";
				return -1;
			}
			return head->elem;
		}
		
		bool isEmpty()	
		{
			return size == 0;
		}
		
		void print()
		{
			if (isEmpty())
			{
				cout << "Stack is empty.\n";
				return;
			}
			node *curr = head;	
			cout << "STACK ELEMENTS (SIZE: " << size << ")" << endl;
			while (curr)
			{
				cout << curr->elem << " ";
				curr = curr->next;
			}
			cout << endl;
		}
};


