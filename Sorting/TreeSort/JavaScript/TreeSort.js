class BSTNode{
  constructor(data){
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class TreeSort{
  insert(root, data){
    if(root==null){
        return new BSTNode(data);
      }

    if(data > root.data){
      if(root.right == null){
        root.right = new BSTNode(data);
      }else{
        this.insert(root.right, data);
      }
    }else if (data< root.data){
            if(root.left == null){
                root.left = new BSTNode(data);
            }else{
                this.insert(root.left, data);
            }
        }
    return root;
  }

  inorder(root){
    if(root==null)
      return;
    this.inorder(root.left);
    console.log(root.data + " ");
    this.inorder(root.right);
  }

  printSortedTree(){
    var arr = [];
    var n = prompt("Enter the number of nodes on the tree")

    for(var i = 0; i < n; i++){
      arr[i] = prompt("Enter the next node element");
    }

    var root = null;
    for(var i = 0;i < arr.length; i++){
      root = this.insert(root,arr[i]);
    }

    this.inorder(root);
  }
}

var treeSort = new TreeSort();
treeSort.printSortedTree();
