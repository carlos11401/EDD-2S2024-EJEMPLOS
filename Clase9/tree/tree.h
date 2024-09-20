#include "page.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class BTree
{
private:
  Page* root;
  void insert(Page** root, int key);
  void push(Page* actualPage, int key, bool &goUp, int &median, Page** newPage);
  bool searchNodeOnPage(Page* current, int value, int &k);
  void split(Page* current, int key, Page* rd, int k, int &median, Page** newPage);
  void pushNode(Page* current, int key, Page* rd, int k);
  void getContent(Page* current, stringstream& accum, int& countNode, int& countAux, stringstream& accumLink);
  void write_dot(string code);
public:
  BTree(/* args */);
  void insert(int key);
  void graph();
};

