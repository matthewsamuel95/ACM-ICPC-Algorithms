import java.util.Scanner;

public class TreeSort {

    static BSTNode insert(BSTNode root, int data){

        if(root==null)
            return new BSTNode(data);

        if(data > root.data){
            if(root.right==null)
            {
                root.right = new BSTNode(data);

            }else{
                insert(root.right, data);
            }

        }else if (data< root.data){
            if(root.left == null){
                root.left = new BSTNode(data);
            }else{
                insert(root.left, data);
            }

        }

        return root;
    }

    static void inorder(BSTNode node){
        if(node==null)
            return;
        inorder(node.left);
        System.out.print(node.data + " ");
        inorder(node.right);
    }

    public static void main (String[] args) {
        System.out.println("Please enter elements of binary search tree: ");
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }

        BSTNode root = null;
        for(int i=0;i<n;i++){
            root =  insert(root, arr[i]);
        }

        inorder(root);
    }
}

class BSTNode{
    int data;
    BSTNode left, right;
    BSTNode(int data){
        this.data = data;
        this.left = this.right = null;
    }
}