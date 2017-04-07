#define BIGGER 1
#define SMALLER -1
#define EQUAL 0

int compare(int x,int y) {
	return (x==y)?EQUAL:(x<y)?
}


struct node* find_LCA(struct node *root,int a,int b) {
	
	// I have assumed that a and b exist in the tree already
	
	if(root != NULL) {
		// compare this node with a
		int res1 = compare(root->data,a);
		// compare this node with b 	
		int res2 = compare(root->data,b); 	
	}
	// is any one of a,b is equal to this node value
	// then return this node 
	if(res1 == EQUAL || res2 == EQUAL) {  	
		return root;						
	}
	// both a and b left and right subtree
	// then return this node
	else if(res1 != res2) {					
		return root;					  
	}
	else {
		// one of the following recursive call will execute
		if(res1 == BIGGER) { // or res2 == 1 same thing				
			return find_LCA(root->right_child,a,b);
		}else {
			return find_LCA(root->left_child,a,b);
		}
	}




}