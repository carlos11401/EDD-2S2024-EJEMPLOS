
class MatrixNode{
  private:
    /* data */
  public:
    MatrixNode(int col, int row, int value);

    int value;
    int col;
    int row;
    MatrixNode *up;
    MatrixNode *bottom;
    MatrixNode *right;
    MatrixNode *left;
};
