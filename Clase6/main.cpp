#include "./bst/bst.h"

int main()
{
	BST tree;
	tm *time = new tm;

	string date = "28-08-2001";
	tree.insert(&date);
	date = "28-07-2001";
	tree.insert(&date);
	date = "28-09-2001";
	tree.insert(&date);
	date = "28-10-2001";
	tree.insert(&date);
	date = "10-10-2001";
	tree.insert(&date);
	
  tree.graph();
	return 0;
}