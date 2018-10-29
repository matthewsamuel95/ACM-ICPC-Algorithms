import java.util.Random;
import java.util.Scanner;

/**
 * @author avcbcoder last modified @29-Oct-2018 @3:10:34 AM Code Library - TODO
 */

/**
 * <===============================================About AVL class==================================================>
 * 
 * COMPLEXITIES = log(N) for every method ---------------------------------------------------------------------------
 * 
 * DESCRIPTION of all the functions in AVL class --------------------------------------------------------------------
 * 1.insert(x) -> increase frequency of x if its present in avl otherwise calls insertNode() to add Node containing x
 * 2.delete(x) -> decrease frequency of x and if its frequency becomes 0 then remove it from avl --------------------
 * 3.nodeOfKey(x) -> Return corresponding Node of x if present otherwise return null --------------------------------
 * 4.leftRotation(), RightRotation() -> these are the core of AVL : It keeps height balanced ------------------------
 * 5.lessThan(x) -> It finds count of elements less than or equal to x ----------------------------------------------
 * 6.greaterThan(x) -> It finds count of elements greater than or equal to x ----------------------------------------
 * 7.justSmaller(x) -> return node containing just smaller element than x or null if no small element is there in avl
 * 7.justGreater(x) -> return node containing just bigger element than x or null if no bigger element is there in avl
 * 
 * <============================================= For Testing AVL ==================================================>
 * main() => Query:{t x}---------------------------------------------------------------------------------------------
 * 1 x -> Increase freq of x-----------------------------------------------------------------------------------------
 * 2 x -> Decrease freq of x-----------------------------------------------------------------------------------------
 * 3 x -> Tells whether x is present or not (you can also query its frequency)---------------------------------------
 * 4 x -> Tells count integers greater than or equal to x------------------------------------------------------------
 * 5 x -> Tells count of integers lesser than or equal to x----------------------------------------------------------
 * 6 x -> prints just smaller element than x or "No" if doesn't exist -----------------------------------------------
 * 7 x -> prints just bigger element than x or "No" if doesn't exist  -----------------------------------------------
 * 8 x -> prints unique elements in AVL -----------------------------------------------------------------------------
 */

/**
 * 
 */
public class AVL_Implementation {
	public static Scanner sc = new Scanner(System.in);
	public static Random R = new Random();

	public static void main(String[] args) throws Exception {
		AVLTree avl = new AVLTree();

		int Q = 100;
		while (Q-- > 0) {
			int t = sc.nextInt();
			int x = sc.nextInt();
			switch (t) {
			case 1:
				avl.insert(x);
				break;
			case 2:
				avl.delete(x);
				break;
			case 3:
				System.out.println(avl.nodeOfKey(x) == null ? "NO" : "YES");
				break;
			case 4:
				System.out.println("less than " + x + " = " + avl.lessThan(x));
				break;
			case 5:
				System.out.println("greater than " + x + " = " + avl.greaterThan(x));
				break;
			case 6:
				System.out.println(avl.justGreater(x) == null ? "NO" : avl.justGreater(x).key);
				break;
			case 7:
				System.out.println(avl.justSmaller(x) == null ? "NO" : avl.justSmaller(x).key);
				break;
			case 8:
				System.out.println("Unique Integers in AVL => " + avl.uniqueIntegers);
				break;
			default:
				break;
			}
		}
	}

	public static class AVLTree {
		int uniqueIntegers = 0;
		private Node root;

		class Node {
			/**
			 * key -> Integer stored at that node-----------------------------
			 * frequency -> there's only one node corresponding to each integer
			 * height -> height of tree under this node-----------------------
			 * left_nodes, right_nodes -> count of nodes in left, right of the
			 * corresponding node---------------------------------------------
			 * elements -> it keeps track of count of elements (less than itself
			 * + more than itself + frequency of its own)
			 */
			int key, frequency, height;
			Node left, right;
			int left_nodes, right_nodes;
			int total_nodes;// left_nodes + right_nodes + 1 (itself)
			int elements;

			Node(int k) {
				key = k;
				height = 1;
			}

		}

		/**
		 * Insert Node if this key is not present in avl otherwise just increase
		 * the frequency
		 */
		void insert(int key) {
			Node nodeOfKey = nodeOfKey(this.root, key);
			if (nodeOfKey == null) { // this key is not present in avl
				this.root = this.insertNode(this.root, key);
				uniqueIntegers++;
			}
			increaseFrequency(this.root, key);
		}

		/**
		 * Decrease frequency of Node of this key but if frequency becomes 0,
		 * then simply delete this node from avl
		 */
		void delete(int key) {
			Node nodeOfKey = nodeOfKey(this.root, key);
			if (nodeOfKey == null) { // this key is not present in avl
				System.out.println("TERRIBLE ERROR");
			} else {
				decreaseFrequency(this.root, key);
				if (nodeOfKey.frequency == 0) {
					uniqueIntegers--;
					this.root = this.deleteNode(this.root, key);
				}
			}
		}

		/**
		 * Increase frequency of that node and element size of its parents
		 */
		private void increaseFrequency(Node node, int key) {
			if (node == null)
				return;
			else if (node.key > key)
				increaseFrequency(node.left, key);
			else if (node.key < key)
				increaseFrequency(node.right, key);
			else
				node.frequency += 1;
			node.elements = (node.right == null ? 0 : node.right.elements)
					+ (node.left == null ? 0 : node.left.elements) + node.frequency;
		}

		/**
		 * Decrease frequency of that node and element size of its parents
		 */
		private void decreaseFrequency(Node node, int key) {
			if (node == null)
				return;
			else if (node.key > key)
				decreaseFrequency(node.left, key);
			else if (node.key < key)
				decreaseFrequency(node.right, key);
			else
				node.frequency -= 1;
			node.elements = (node.right == null ? 0 : node.right.elements)
					+ (node.left == null ? 0 : node.left.elements) + node.frequency;
		}

		/**
		 * return node containing just bigger element than x or null if no
		 * bigger element is there in avl
		 */
		Node justGreater(int val) {
			return this.justGreater(this.root, val);
		}

		private Node justGreater(Node node, int val) {
			if (node == null)
				return null;
			if (node.key > val) {
				Node g = justGreater(node.left, val);
				if (g != null)
					return g;
				return node;
			} else if (node.key < val) {
				return justGreater(node.right, val);
			} else {
				return node;
			}
		}

		/**
		 * return node containing just smaller element than x or null if no
		 * small element is there in avl
		 */
		Node justSmaller(int val) {
			return this.justSmaller(this.root, val);
		}

		private Node justSmaller(Node node, int val) {
			if (node == null)
				return null;
			if (node.key < val) {
				Node g = justSmaller(node.right, val);
				if (g != null)
					return g;
				return node;
			} else if (node.key > val) {
				return justSmaller(node.left, val);
			} else {
				return node;
			}
		}

		/**
		 * a and b are also included
		 */
		int elementBTW(int a, int b) {
			int lessThanA = lessThan(this.root, a - 1);
			int lessThanB = lessThan(this.root, b);
			return lessThanB - lessThanA;
		}

		/**
		 * It finds count of elements less than or equal to 'val'
		 */
		int lessThan(int val) {
			return this.lessThan(this.root, val);
		}

		private int lessThan(Node node, int val) {
			if (node == null)
				return 0;
			else if (node.key < val)
				return (node.left == null ? 0 : node.left.elements) + node.frequency + lessThan(node.right, val);
			else if (node.key > val)
				return lessThan(node.left, val);
			else
				return (node.left == null ? 0 : node.left.elements) + node.frequency;
		}

		/**
		 * It finds count of elements greater than or equal to 'val'
		 */
		private int greaterThan(int val) {
			return this.greaterThan(this.root, val);
		}

		int greaterThan(Node node, int val) {
			if (node == null)
				return 0;
			else if (node.key < val)
				return greaterThan(node.right, val);
			else if (node.key > val)
				return (node.right == null ? 0 : node.right.elements) + node.frequency + greaterThan(node.left, val);
			else
				return (node.right == null ? 0 : node.right.elements) + node.frequency;
		}

		/**
		 * Extract corresponding node of the key
		 */
		Node nodeOfKey(int key) {
			return this.nodeOfKey(this.root, key);
		}

		private Node nodeOfKey(Node node, int key) {
			if (node == null)
				return null;
			if (node.key == key)
				return node;
			return (node.key > key) ? nodeOfKey(node.left, key) : nodeOfKey(node.right, key);
		}

		/**
		 * Actual code to insert a node Uses rotations internally
		 */
		private Node insertNode(Node node, int key) {
			if (node == null)
				return (new Node(key));

			if (key < node.key) {
				node.left = insertNode(node.left, key);
				node.left_nodes += 1;
				node.total_nodes = node.left_nodes + node.right_nodes;
			} else if (key > node.key) {
				node.right = insertNode(node.right, key);
				node.right_nodes += 1;
				node.total_nodes = node.left_nodes + node.right_nodes;
			} else
				return node;

			node.height = 1 + Math.max(height(node.left), height(node.right));

			int balance = getBalance(node);

			if (balance > 1 && key < node.left.key)
				return rightRotate(node);

			if (balance < -1 && key > node.right.key)
				return leftRotate(node);

			if (balance > 1 && key > node.left.key) {
				node.left = leftRotate(node.left);
				return rightRotate(node);
			}

			if (balance < -1 && key < node.right.key) {
				node.right = rightRotate(node.right);
				return leftRotate(node);
			}

			return node;
		}

		/**
		 * Actual code to delete a node Uses rotations internally
		 */
		private Node deleteNode(Node node, int key) {
			if (node == null)
				return node;

			if (key < node.key) {
				node.left = deleteNode(node.left, key);
				node.left_nodes -= 1;
				node.total_nodes = node.left_nodes + node.right_nodes;
			} else if (key > node.key) {
				node.right = deleteNode(node.right, key);
				node.right_nodes -= 1;
				node.total_nodes = node.left_nodes + node.right_nodes;
			} else {

				if ((node.left == null) || (node.right == null)) {
					Node temp = null;
					if (temp == node.left)
						temp = node.right;
					else
						temp = node.left;

					if (temp == null) {
						temp = node;
						node = null;
					} else
						node = temp;
				} else {

					Node temp = minValueNode(node.right);

					node.key = temp.key;
					node.right_nodes -= 1;
					node.total_nodes = node.left_nodes + node.right_nodes;
					node.right = deleteNode(node.right, temp.key);
				}
			}

			if (node == null)
				return node;

			node.height = Math.max(height(node.left), height(node.right)) + 1;

			int balance = getBalance(node);

			if (balance > 1 && getBalance(node.left) >= 0)
				return rightRotate(node);
			if (balance > 1 && getBalance(node.left) < 0) {
				node.left = leftRotate(node.left);
				return rightRotate(node);
			}
			if (balance < -1 && getBalance(node.right) <= 0)
				return leftRotate(node);
			if (balance < -1 && getBalance(node.right) > 0) {
				node.right = rightRotate(node.right);
				return leftRotate(node);
			}
			return node;
		}

		/**
		 * Right Rotation
		 */
		private Node rightRotate(Node node) {
			Node y = node.left;
			Node temp = y.right;

			node.left = temp;
			node.left_nodes = (temp == null) ? 0 : (temp.total_nodes + 1);
			node.total_nodes = node.left_nodes + node.right_nodes;
			y.right = node;
			y.right_nodes = node.total_nodes + 1;
			y.total_nodes = y.right_nodes + y.left_nodes;

			node.height = Math.max(height(node.left), height(node.right)) + 1;
			y.height = Math.max(height(y.left), height(y.right)) + 1;

			return y;
		}

		/**
		 * Left Rotation
		 */
		private Node leftRotate(Node node) {
			Node y = node.right;
			Node temp = y.left;

			node.right = temp;
			node.right_nodes = (temp == null) ? 0 : (temp.total_nodes + 1);
			node.total_nodes = node.left_nodes + node.right_nodes;
			y.left = node;
			y.left_nodes = node.total_nodes + 1;
			y.total_nodes = y.left_nodes + y.right_nodes;

			node.height = Math.max(height(node.left), height(node.right)) + 1;
			y.height = Math.max(height(y.left), height(y.right)) + 1;

			return y;
		}

		/**
		 * Used while deletion
		 */
		private Node minValueNode(Node node) {
			while (node.left != null)
				node = node.left;
			return node;
		}

		/**
		 * Returns difference of height of left and right child
		 */
		private int getBalance(Node N) {
			if (N == null)
				return 0;
			return height(N.left) - height(N.right);
		}

		/**
		 * Returns height of node if not null
		 */
		private int height(Node N) {
			if (N == null)
				return 0;
			return N.height;
		}
	}
}
