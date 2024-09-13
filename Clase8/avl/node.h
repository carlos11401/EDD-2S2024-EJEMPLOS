class Node
{
private:
  /* data */
public:
  Node(int value);
  ~Node();

  int value;
  int factor;
  Node *left;
  Node *right;
};
