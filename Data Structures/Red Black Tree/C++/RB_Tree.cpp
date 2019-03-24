#include "RB_Tree.hpp"
#include <iostream>

using std::cout;

RBT::RBT()
{
    root = 0;
    _no_lv = 0;
    _no_in_nodes = 0;
    _height = 0;

    NIL = new Node(-1, BLACK);

    cout << "\n\nTREE CREATED :)";
}

Node *RBT::get_root_by_address()
{
    return root;
}

string RBT::get_node_prop(int data)
{
    Node *node = find_node(data);
    return node->getProps();
}

void RBT::left_rotate(Node *x)
{
    // Analysis :- O(1)
    // x is the node about which we have to left rotate by 1 notch

    Node *y = x->right;
    x->right = y->left;

    if (y->left != RBT::NIL)
        y->left->parent = x;

    if (x->parent == RBT::NIL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->parent = x->parent;
    x->parent = y;
    y->left = x;

    return;
}

void RBT::right_rotate(Node *x)
{
    // Analysis :- O(1)
    // x is the node about which we have to right rotate by 1 notch

    Node *y = x->left;
    x->left = y->right;

    if (y->right != RBT::NIL)
        y->right->parent = x;

    if (x->parent == RBT::NIL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->parent = x->parent;
    x->parent = y;
    y->right = x;

    return;
}

void RBT::insert(int data)
{

    // Analysis :- O(lgn)

    Node *node = new Node(data, RED, RBT::NIL, RBT::NIL, RBT::NIL);

    if (root)
    {
        Node *temp = root;
        Node *ptr;

        /* first we insert a new RED node at proper place 
           just like BST taking O(lgn) 
        */

        while (temp != RBT::NIL)
        {
            ptr = temp;

            if (temp->data < data)
                temp = temp->right;
            else
                temp = temp->left;
        }

        if (data > ptr->data)
            ptr->right = node;
        else
            ptr->left = node;

        node->parent = ptr;

        /* now due to this insertion there are chances
           of voilation of prop 4 so we call another 
           module to handle the dent named insert_fixup 
           taking O(lgn)
        */

        insert_fixup(node);
    }
    else
    {
        root = node;
        root->color = BLACK;
    }

    return;
}

void RBT::insert_fixup(Node *z)
{
    // Analysis :- O(lgn)

    while (z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            Node *y = z->parent->parent->right; // y is uncle of z
            if (y->color == RED)
            {
                /*
                case 1 :- when both z's parent and uncle are RED.
                solution :- make both z's parent and uncle BLACK 
                            and make z's grandparent RED and then
                            point z to it's grandparent ie., up
                            by a level of 2 in the RBT
                conclusion :- this case will not sures the loop to
                              terminate as we make z's grandparent
                              RED and again it may voilate property 
                              4 of RBT.
                */

                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else if (z == z->parent->right)
            {
                /*
                case 2 :- when z's parent is RED but uncle is BLACK
                          and z is it's parent's left child.
                solution :- point z to it's parent and then left-rotate
                            about z.
                conclusion :- this case will never let the loop to
                              terminate as now z and it's parent are
                              RED violating prop 4. This case always
                              take us to case 3.
                */

                z = z->parent;
                left_rotate(z);
            }
            else
            {
                /*
                case 3 :- when z's parent is RED but uncle is BLACK
                          and z is it's parent's left child.
                solution :- make z's parent BLACK and z's grandparent
                            RED and then right-rotate about z's grandp.
                            about z.
                conclusion :- this case will never let the loop to
                              terminate as now z and it's parent are
                              RED violating prop 4. This case always
                              take us to case 3.
                */

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(z->parent->parent);
            }
        }
        else
        {
            Node *y = z->parent->parent->left; // y is uncle of z

            if (y->color == RED)
            {
                //case 1
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else if (z == z->parent->left)
            {
                //case 2
                z = z->parent;
                right_rotate(z);
            }
            else
            {
                //case 3
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(z->parent->parent);
            }
        }
    }

    root->color = BLACK;

    return;
}

Node *RBT::find_node(int find)
{
    /*
    Submodule to return pointer to the first node
    containing find
    */

    // Analysis :- O(lgn)

    Node *temp = root;

    while (temp != RBT::NIL && temp->data != find)
    {
        if (temp->data > find)
            temp = temp->left;
        else
            temp = temp->right;
    }

    return temp;
}

Node *RBT::successor(Node *z)
{
    // Analysis :- O(lgx)  x are the nodes below z

    if (z->right == RBT::NIL)
        return RBT::NIL;

    Node *temp = z->right;

    while (temp->left != RBT::NIL)
        temp = temp->left;

    return temp;
}

void RBT::delete_node(int data)
{
    // Analysis :- O(lgn)

    Node *z = find_node(data);
    if (z != RBT::NIL)
    {
        /*
        z :- node which the user wants to delete
        y :- node which is actually deleted
        x :- y's child
        */

        Node *y, *x;

        if (z->left == RBT::NIL || z->right == RBT::NIL)
        {
            // If z has atmost 1 child
            y = z;
        }
        else
        {
            // If z has both children
            y = successor(z);
        }

        if (z->left != RBT::NIL)
            x = y->left;
        else
            x = y->right;

        /*
        As we actually delete y so before deleting it
        we need some arrangements. So we first make
        y's child x to point y's parent i.e., it's
        grandparent and then make grandparent to point 
        x, so after this x's grandparent becomes it's
        new parent and y is seprated out for safe deletion.
        */

        //make x's grandparent it's new parent
        x->parent = y->parent;

        //make x's new parent to point it
        if (y->parent == RBT::NIL)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        //copy data of y to z before deleting y
        if (y != z)
            z->data = y->data;

        /*
        Now this deletion is O(1) till now but
        due to all this we may cause violation of 
        prop 1,2 and 4. To tackle this dent we call
        a sub-module delete_fixup which take O(lgn).

        x either have RED-BLACK or BLACK-BLACK leading
        to violate prop 1 and preserving prop 5.
        */
        if (y->color == BLACK)
            delete_fixup(x);

        delete y; // add
    }
    else
        cout << "\nNo such data present";

    return;
}

void RBT::delete_fixup(Node *x)
{
    // Analysis :- O(lgn)

    while (x != root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            Node *w = x->parent->right; // w is x's sibling

            if (w->color == RED)
            {
                /*
                case 1 :- w is RED
                conclusion :- Always take control to case 2,3 or 4. 
                */

                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(x->parent);
                w = x->parent->right;
            }

            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                /*
                case 2 :- w and both it's children are BLACK.
                solution :- take BLACK from both x and w.
                conclusion :- terminates if came from case 1
                */

                w->color = RED;
                x = x->parent;
            }
            else if (w->right->color == BLACK)
            {
                /*
                case 3 :- w=BLACK , w->left=RED and w->right=BLACK
                conclusion :- case 3 take us to case 4
                */

                w->left->color = BLACK;
                w->color = RED;
                right_rotate(w);
                w = x->parent->right;
            }
            else
            {
                /*
                case 4 :- w is BLACK and w->right is RED
                conclusion :- terminates
               */

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(x->parent);
                x = root;
            }
        }
        else
        {
            Node *w = x->parent->left; // w is x's sibling

            if (w->color == RED)
            {
                //case 1
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(x->parent);
                w = x->parent->left;
            }

            if (w->right->color == BLACK && w->left->color == BLACK)
            {
                //case 2 :- w is BLACK and also it's both childs
                w->color = RED;
                x = x->parent;
            }
            else if (w->left->color == BLACK)
            {
                //case 3 :- w=BLACK , w.l=RED and w.r=BLACK
                w->right->color = BLACK;
                w->color = RED;
                left_rotate(w);
                w = x->parent->left;
            }
            else
            {
                //case 4 :- w is BLACK and w->r is RED
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(x->parent);
                x = root;
            }
        }
    }

    x->color = BLACK;
}

string RBT::get_tree_prop()
{
    no_of_leaves(get_root_by_address());
    no_of_internal_nodes(get_root_by_address());
    _height = height_tree(get_root_by_address());

    return "\nroot : " + to_string(root->data) +
           "\nno of leaves : " + to_string(_no_lv) +
           "\nno of internal nodes : " + to_string(_no_in_nodes) +
           "\nheight : " + to_string(_height);
}

int RBT::height_tree(const Node *curr_ptr)
{
    // Analysis :- O(n)

    if (curr_ptr != RBT::NIL)
    {
        int l = height_tree(curr_ptr->left);
        int r = height_tree(curr_ptr->right);

        return (l > r) ? l + 1 : r + 1;
    }
    else
        return 0;
}

void RBT::no_of_leaves(const Node *curr_ptr)
{
    // Analysis :- O(n)

    if (curr_ptr)
    {
        if (curr_ptr->data == RBT::NIL->data)
            ++_no_lv;

        no_of_leaves(curr_ptr->left);
        no_of_leaves(curr_ptr->right);
    }

    return;
}

void RBT::no_of_internal_nodes(const Node *curr_ptr)
{
    // Analysis :- O(n)

    if (curr_ptr != RBT::NIL)
    {
        ++_no_in_nodes;

        if (curr_ptr->left != RBT::NIL)
            no_of_internal_nodes(curr_ptr->left);
        if (curr_ptr->right != RBT::NIL)
            no_of_internal_nodes(curr_ptr->right);
    }

    return;
}

bool RBT::search(int find)
{
    return find_node(find) != RBT::NIL;
}

void RBT::show_tree(int type)
{
    show s = static_cast<show>(type);

    switch (s)
    {
    case full_horizontal:
        show_full_horizontal(get_root_by_address());
        break;

    case preorder:
        show_preorder(get_root_by_address());
        break;

    case inorder:
        show_inorder(get_root_by_address());
        break;

    case postorder:
        show_postorder(get_root_by_address());
        break;

    default:
        cout << "\nInvalid choice!";
    }

    return;
}

void RBT::show_full_horizontal(const Node *ptr, int space) const
{
    // Analysis :- O(n)

    if (!ptr)
        return;

    space++;

    show_full_horizontal(ptr->right, space);

    for (int i = 1; i < space; i++)
        std::cout << "	  ";

    if (ptr->color == RED)
        std::cout << "R " << ptr->data << "\n";
    else
        std::cout << "B " << ptr->data << "\n";

    show_full_horizontal(ptr->left, space);
}

void RBT::show_preorder(const Node *curr_ptr) const
{
    // Analysis :- O(n)

    if (curr_ptr != RBT::NIL)
    {
        cout << "  " << curr_ptr->data;
        show_preorder(curr_ptr->left);
        show_preorder(curr_ptr->right);
    }
}

void RBT::show_inorder(const Node *curr_ptr) const
{
    // Analysis :- O(n)

    if (curr_ptr != RBT::NIL)
    {
        show_inorder(curr_ptr->left);
        cout << "  " << curr_ptr->data;
        show_inorder(curr_ptr->right);
    }
}

void RBT::show_postorder(const Node *curr_ptr) const
{
    // Analysis :- O(n)

    if (curr_ptr != RBT::NIL)
    {
        show_postorder(curr_ptr->left);
        show_postorder(curr_ptr->right);
        cout << "  " << curr_ptr->data;
    }
}

void RBT::clear(Node *curr_ptr)
{
    // Analysis :- O(n)

    if (curr_ptr != RBT::NIL)
    {
        clear(curr_ptr->left);
        clear(curr_ptr->right);

        delete curr_ptr;
    }
    root = 0;
}

RBT::~RBT()
{
    clear(get_root_by_address());

    cout << "\n\nTREE DESTROYED... ";
}