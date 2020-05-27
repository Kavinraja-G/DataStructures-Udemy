

/*     void getInOrder(Node root, ArrayList<Integer> arr)
    {
        if(root == null)
            return;
        getInOrder(root.left,arr);
        arr.add(root.data);
        getInOrder(root.right,arr);
    }

    boolean checkBST(Node root) {
        ArrayList<Integer> inOrder = new ArrayList<Integer>();
        getInOrder(root,inOrder);
        for(int i=1;i<inOrder.size();i++)
        {
            if(inOrder.get(i)>inOrder.get(i-1))
                continue;
            else
                return false;
        }
        return true;
    }
 */