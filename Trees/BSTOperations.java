package Trees;
class TreeNode{
    int val;
    TreeNode right;
    TreeNode left;
    TreeNode(int data){
        val=data;
        right=null;
        left=null;
    }
}
public class BSTOperations{
   public TreeNode insertNode(TreeNode root,int data){
    if(root==null) {
        TreeNode newnode=new TreeNode(data);
        return newnode;
   }
    if(root.val>data){
       root.left=insertNode(root.left,data);
   }else{
        root.right=insertNode(root.right,data);
   }
   return root;
}
   public boolean search(TreeNode root,int data){
        if(root==null) return false;
        if(root.val==data) return true;
        if(root.val>data) return search(root.left,data);
        return search(root.right,data);
   }
   public int minval(TreeNode root){
        TreeNode temp=root;
        while(temp.left!=null){
            temp=temp.left;
        }
        return temp.val;
   }
   public int maxval(TreeNode root){
    TreeNode temp=root;
        while(temp.right!=null){
            temp=temp.right;
        }
        return temp.val;
   }
   public TreeNode deleteNode(TreeNode root,int data){
    //base case
    if(root==null) return null;
    //search
    if(root.val>data){
        root.left=deleteNode(root.left,data);
    }else if(root.val<data){
        root.right=deleteNode(root.right,data);
    }else{
    //0 children
        if(root.left==null && root.right==null){
            return null;
        }
    //1 children
        if(root.left==null&&root.right!=null){
            TreeNode temp=root.right;
            return temp;
        }else if(root.right==null && root.left!=null){
            TreeNode temp=root.left;
            return temp;
        }
    //2 children
        if(root.left!=null && root.right!=null){
            int mini=minval(root.right);
            root.val=mini;
            root.right=deleteNode(root.right,mini);
        }
    }
    return root;
   }
    public static void main(String[] args) {
        BSTOperations bst=new BSTOperations();
        TreeNode root=null;
        root=bst.insertNode(root,1);
         root = bst.insertNode(root, 50);
        root = bst.insertNode(root, 30);
        root = bst.insertNode(root, 70);
        root = bst.insertNode(root, 20);
        root = bst.insertNode(root, 40);
        root = bst.insertNode(root, 60);
        root = bst.insertNode(root, 80);
    }
}

