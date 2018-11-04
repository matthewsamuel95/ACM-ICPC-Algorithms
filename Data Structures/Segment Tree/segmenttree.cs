using System; 

public class GFG { 
	
	// limit for array size 
	static int N = 100000; 
	
	static int n; // array size 
	
	// Max size of tree 
	static int []tree = new int[2 * N]; 
	
	// function to build the tree 
	static void build( int []arr) 
	{ 
		
		// insert leaf nodes in tree 
		for (int i = 0; i < n; i++) 
			tree[n + i] = arr[i]; 
		
		// build the tree by calculating 
		// parents 
		for (int i = n - 1; i > 0; --i) 
			tree[i] = tree[i << 1] + 
					tree[i << 1 | 1]; 
	} 
	
	// function to update a tree node 
	static void updateTreeNode(int p, int value) 
	{ 
		// set value at position p 
		tree[p + n] = value; 
		p = p + n; 
		
		// move upward and update parents 
		for (int i = p; i > 1; i >>= 1) 
			tree[i >> 1] = tree[i] + tree[i^1]; 
	} 
	
	// function to get sum on 
	// interval [l, r) 
	static int query(int l, int r) 
	{ 
		int res = 0; 
		
		// loop to find the sum in the range 
		for (l += n, r += n; l < r; 
							l >>= 1, r >>= 1) 
		{ 
			if ((l & 1) > 0) 
				res += tree[l++]; 
		
			if ((r & 1) > 0) 
				res += tree[--r]; 
		} 
		
		return res; 
	} 
	
	// driver program to test the 
	// above function 
	static public void Main () 
	{ 
		int []a = {1, 2, 3, 4, 5, 6, 7, 8, 
							9, 10, 11, 12}; 
	
		// n is global 
		n = a.Length; 
		
		// build tree 
		build(a); 
		
		// print the sum in range(1,2) 
		// index-based 
		Console.WriteLine(query(1, 3)); 
		
		// modify element at 2nd index 
		updateTreeNode(2, 1); 
		
		// print the sum in range(1,2) 
		// index-based 
		Console.WriteLine(query(1, 3)); 
	} 
} 

// This code is contributed by vt_m. 
