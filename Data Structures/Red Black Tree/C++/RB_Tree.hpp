#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include "Node.hpp"

// This is just for display purpose
enum show
{
  full_horizontal,
  preorder,
  inorder,
  postorder
};

class RBT
{
private:
  //tree props
  Node *root;
  Node *NIL;
  int _no_lv;
  int _no_in_nodes;
  int _height;

  //atomic modules
  Node *get_root_by_address();
  void left_rotate(Node *);
  void right_rotate(Node *);
  Node *successor(Node *);
  Node *find_node(int);

public:
  //constructor
  RBT();

  //getter modules
  string get_node_prop(int);
  string get_tree_prop();
  int height_tree(const Node *);
  void no_of_leaves(const Node *);
  void no_of_internal_nodes(const Node *);

  //fundamental modules
  void insert(int);
  void insert_fixup(Node *);
  void delete_node(int);
  void delete_fixup(Node *);

  //application module
  bool search(int);
  void show_tree(int);
  void show_full_horizontal(const Node *, int space = 0) const;
  void show_preorder(const Node *) const;
  void show_inorder(const Node *) const;
  void show_postorder(const Node *) const;
  void clear(Node *);

  //destructor
  ~RBT();
};

#endif
