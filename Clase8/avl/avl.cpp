#include "avl.h"

AVL::AVL(){
  root = nullptr;
}

void AVL::insert(int value){
  bool increase = false;
  root = insert(this->root, value, increase);
}

Node* AVL::insert(Node* root, int value, bool &increase){
  if(root == nullptr){
    root = new Node(value);
    increase = true;
  }else if(value < root->value){
    root->left = insert(root->left, value, increase);
    if(increase){
      switch (root->factor){
        case RIGHT_HEAVY:
          root->factor = 0;
          increase = false;
          break;
        case BALANCED:
          root->factor = -1;
          break;
        case LEFT_HEAVY:
          Node* n1 = root->left;
          if(n1->factor == -1){
            root = l_rotation(root, n1);
          }else{
            root = lr_rotation(root, n1);
          }
          increase = false;
          break;
      }
    }
  }else if(value > root->value){
    root->right = insert(root->right, value, increase);
    if(increase){
			Node* n1;
      switch (root->factor){
        case RIGHT_HEAVY:
          n1 = root->right;
          if(n1->factor == 1){
            root = r_rotation(root, n1);
          }else{
            root = rl_rotation(root, n1);
          }
          increase = false;
          break;
        case BALANCED:
          root->factor = 1;
          break;
        case LEFT_HEAVY:
          root->factor = 0;
          increase = false;
          break;
      }
    }
  }
	return root;
}

Node* AVL::l_rotation(Node* n, Node* n1){
  n->left = n1->right;
	n1->right = n;

	n->factor = 0;
	n1->factor = 0;
	return n1;
}
Node* AVL::r_rotation(Node* n, Node* n1){
  n->right = n1->left;
	n1->left = n;

	n->factor = 0;
	n1->factor = 0;
	return n1;
}
Node* AVL::rl_rotation(Node* n, Node* n1){
  Node* n2 = n1->left;

	n1->left = n2->right;
	n2->right = n1;
  n->right = n2->left;
	n2->left = n;
  
	n2->factor = 0;
  n1->factor = 0;
	n->factor = 0;
	return n2;
}
Node* AVL::lr_rotation(Node* n, Node* n1){
  Node* n2 = n1->right;

	n1->right = n2->left;
	n2->left = n1;
  n->left = n2->right;
  n2->right = n;

	n2->factor = 0;
	n1->factor = 0;
	n->factor = 0;
	return n2;
}


void AVL::graph(){
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
void AVL::graph(Node *root, ofstream &content)
{
	if (root != nullptr)
	{
		char s[100];

		content << "Nodo" << root << "[label = \"" << root->value << "\" xlabel=" << root->factor << "]" << endl;

		if (root->left != nullptr)
		{
			content << "Nodo" << root << "->Nodo" << root->left << endl;
		}

		if (root->right != nullptr)
		{
			content << "Nodo" << root << "->Nodo" << root->right << endl;
		}

		this->graph(root->left, content);
		this->graph(root->right, content);
	}
}
