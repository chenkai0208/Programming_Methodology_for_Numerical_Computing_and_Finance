#include <string>
#include <iostream>
using namespace std;

Node::Node(string name, int no)
   :itemName(name), itemNo(no)
{
	this->next=NULL;
}

void Node::print()
{
	cout << itemNo << " " << itemName << " " << endl;
}