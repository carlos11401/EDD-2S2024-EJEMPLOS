#include "bst.h"

BST::BST(){
	this->root = nullptr;
}

void BST::insert(string *value)
{
	tm *newTime = new tm;
	if (!parseDateString(*value, newTime)){
		cout << "Error at insert: " << value << endl;
		return;
	}else{
		this->root = insert(this->root, newTime);
	}
}

Node *BST::insert(Node *root, tm *newDate){
	time_t newTime = mktime(newDate);
	time_t currentTime;
	if(root != nullptr){
		currentTime = mktime(root->getValue());
	}

	if(root == nullptr){
		root = new Node(newDate);
	}else if( newTime < currentTime ){
		root->setLeft(insert(root->getLeft(), newDate));
	}else if(newTime > currentTime){
		root->setRight(insert(root->getRight(), newDate));
	}
	return root;
}

bool BST::parseDateString(string &date, tm *time)
{
	istringstream ss(date);
	ss >> get_time(time, "%d-%m-%Y");
	time->tm_hour = 0;
	time->tm_sec = 0;
	time->tm_min = 0;
	time->tm_isdst = -1;
	return !ss.fail();
}

void BST::graph(){
	ofstream outfile("bst.dot");
	outfile << "digraph G {" << endl;

	if (root != nullptr)
	{
		graph(root, outfile);
	}

	outfile << "}" << endl;
	outfile.close();
	int returnCode = system("dot -Tpng ./bst.dot -o ./bst.png");

	if (returnCode == 0){
		cout << "Command executed successfully." << endl;
	}else{
		cout << "Command execution failed or returned non-zero: " << returnCode << endl;
	}
}
void BST::graph(Node *root, ofstream &content)
{
	if (root != nullptr)
	{
		ostringstream oss;


		char s[100];
		strftime(s, sizeof(s), "%d-%m-%Y", root->getValue());

		content << "Nodo" << root << "[label = \"" + string(s) + "\"]" << endl;

		if (root->getLeft() != nullptr)
		{
			content << "Nodo" << root << "->Nodo" << root->getLeft() << endl;
		}

		if (root->getRight() != nullptr)
		{
			content << "Nodo" << root << "->Nodo" << root->getRight() << endl;
		}

		this->graph(root->getLeft(), content);
		this->graph(root->getRight(), content);
	}
}
