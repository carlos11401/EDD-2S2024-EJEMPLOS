#include "../../simpleList/headers/simpleList.h"

class Matrix{
private:
  void move_lr_pointers(ListNode *rowNode, MatrixNode *newMatrixNode); // lr - left and right
  bool moveAt_first_lr_pointers(ListNode *rowNode, MatrixNode *newMatrixNode);
  MatrixNode* moveAt_middle_lr_pointers(ListNode *rowNode, MatrixNode *newMatrixNode);
  void moveAt_end_lr_pointers(MatrixNode *lastNode, MatrixNode *newMatrixNode);

  void move_ub_pointers(ListNode *colNode, MatrixNode *newMatrixNode); // ub = up and bottom
  bool moveAt_first_ub_pointers(ListNode *colNode, MatrixNode *newMatrixNode);
  MatrixNode* moveAt_middle_ub_pointers(ListNode *colNode, MatrixNode *newMatrixNode);
  void moveAt_end_ub_pointers(MatrixNode *lastNode, MatrixNode *newMatrixNode);

  
  string get_content();
  void align_col_nodes(stringstream &createNodes, stringstream &align, stringstream &linkNodes);
  string get_address_memory(MatrixNode* node);
  void write_dot(const string &code);
public:
  Matrix();
  ~Matrix();

  SimpleList *colHeader;
  SimpleList *rowHeader;

  void insert(int col, int row, int value);
  void create_dot();
};
