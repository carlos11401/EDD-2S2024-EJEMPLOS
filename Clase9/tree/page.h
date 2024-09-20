#define degree 5

class Page
{
private:
  /* data */
  
public:
  Page(/* args */);
  bool fullPage();
  int keys[degree];
  Page* branches[degree];
  int count;
};

