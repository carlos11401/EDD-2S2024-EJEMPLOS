#include "tree.h"
#include <queue>

BTree::BTree(){
  root = nullptr;
}
void BTree::insert(int key){
  insert(&root, key);
}

void BTree::insert(Page** root, int key){
  bool goUp = false;
  int median;
  Page* newPage;

  push(*root, key, goUp, median, &newPage);

  if(goUp){
    Page* newRoot = new Page();
    newRoot->count = 1;
    newRoot->keys[1] = median; 
    newRoot->branches[0] = *root;
    newRoot->branches[1] = newPage;
    *root = newRoot;
  }
}

void BTree::push(Page* currentPage, int key, bool &goUp, int &median, Page** newPage){
  int k = 0;
  if(currentPage == nullptr){
    goUp = true;
    median = key;
    *newPage = nullptr;
  }else{
    // search the node where the value should be inserted
		// k is the position of the branch
		bool node_repeated = searchNodeOnPage(currentPage, key, k);
		if (node_repeated) {
			cout << "Clave Duplicada: " << key << endl;
			goUp = false;
			return;
		}
		push(currentPage->branches[k], key, goUp, median, newPage);
		/* devuelve control vuelve por el camino de busqueda*/
		if(goUp) {
			if(currentPage->fullPage()){
				split(currentPage, median, *newPage, k, median, newPage);
			} else {
				goUp = false;
				pushNode(currentPage, median, *newPage, k);
			}
		}
  }
}

void BTree::split(Page* current, int key, Page* rd, int k, int &median, Page** newPage){
	// newPage is the new node (right) that will be created
	// currentPage is the original node (left)
	int medianPosition = (k<=degree/2) ? degree/2 : degree/2+1;
	*newPage = new Page();
  for (int i = medianPosition + 1; i < degree; i++)
  {
    // move the keys and branches to the new node (right)
    (*newPage)->keys[i-medianPosition] = current->keys[i];
    (*newPage)->branches[i-medianPosition] = current->branches[i];
  }
  (*newPage)->count = (degree - 1) - medianPosition; // keys in the new node
	current->count = medianPosition; // keys in the original node

	// Insert the key and the branch in the corresponding node
	if(k <= degree/2) {
		pushNode(current, key, rd, k); // insert the new value in the original node(left)
	} else {
		pushNode(*newPage, key, rd, k-medianPosition); // insert the new value in the new node(right)
	}

	// save the median key
	median = current->keys[current->count];

	// the branch of the new node (right) is the last branch of the original node (left)
  (*newPage)->branches[0] = current->branches[current->count];

	current->count--;
}

bool BTree::searchNodeOnPage(Page* current, int key, int &k){
	// k is the position of the branch
	bool repeated;
	// if the value is less than the first key
	if(key < current->keys[1]) {
		k = 0; // the branch is the first one
		repeated = false;
	} else // if the value is greater than the last key
	{
		k = current->count;
		while (key < current->keys[k] && k > 1)
    {
      k--;
    }    
		repeated = key == current->keys[k]; // if the value is equal to the key
	}
	return repeated;
}

void BTree::pushNode(Page* current, int key, Page* rd, int k){
	// move the keys and branches to the right
  for (int i = current->count; i >= k+1; i--)
  {
    current->keys[i+1] = current->keys[i];
		current->branches[i+1] = current->branches[i];
  }

	current->keys[k+1] = key;
	current->branches[k+1] = rd;
	current->count++;
}

void BTree::graph(){
	stringstream outfile, accumLinks;
	outfile << "digraph G {\n" <<
					"node	[shape = record,height=.1];\n"
					<< endl;

	if (root != nullptr)
	{
		int countNode = 0;
		int countAux = 0;

		queue<Page*> myqueue;
		myqueue.push(root);

		while(myqueue.size() > 0){
			Page* current = myqueue.front();
			myqueue.pop();

			getContent(current, outfile, countNode, countAux, accumLinks);
			for(int i = 0; i <= current->count; i++){
				if(current->branches[i] != nullptr) {
					myqueue.push(current->branches[i]);
				}
			}
			countNode++;
		}
		outfile << "\n" << accumLinks.str();
	}
	string test = outfile.str();
	outfile << "}" << endl;
	write_dot(outfile.str());
}

void BTree::getContent(Page* current, stringstream& accum, int& countNode, int& countAux, stringstream& accumLink) {
	accum << "node" << countNode << "[label=\"";
	accum << "<r0>";
	if (current->branches[0] != nullptr) {
		accumLink << "\"node" << countNode << "\":r0 ->";
		countAux++;
		accumLink << "\"node" << countAux << "\"\n";
	}
	for(int i = 1; i <= current->count; i++) {
		accum << "|";
		accum << "<c" << i << "> " << current->keys[i];
		accum << "|<r" << i << ">";
		if (current->branches[i] != nullptr) {
			accumLink << "\"node" << countNode << "\":r" << i << " -> ";
			countAux++;
			accumLink << "\"node" << countAux << "\"\n";
		}
	}
	accum << "\"];\n";
	cout << accum.str() << endl;
	cout << accumLink.str();
}
void BTree::write_dot(string code) {
    ofstream outfile("graph.dot");
    if (outfile.is_open()) {
        outfile << code;
        outfile.close();

				int returnCode = system("dot -Tpng ./graph.dot -o ./graph.png");
				if (returnCode == 0){
					cout << "Command executed successfully." << endl;
				}else{
					cout << "Command execution failed or returned non-zero: " << returnCode << endl;
				}
    } else {
        cerr << "Unable to open file";
    }
}
