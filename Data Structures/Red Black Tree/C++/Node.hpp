#ifndef NODE_HPP
#define NODE_HPP

#define RED 1
#define BLACK 0

#include <string>

using std::string;
using std::to_string;

class Node
{
  /*
 A RB node will have two properties associated with it namely the data it contain and it's color.
 A RB node will have three pointers associated with it namely left, right and parent.
*/

private:
  int data;
  int color;
  Node *left;
  Node *right;
  Node *parent;

  friend class RBT;

public:
  Node(int, int, Node *left = 0, Node *right = 0, Node *parent = 0);
  string getProps();
  ~Node();
};

#endif