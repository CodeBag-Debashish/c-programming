#include <stdio.h>
typedef struct tree_node {
	int data;
	struct tree_node * left_child;
	struct tree_node * right_child;
}tnode;
int get_max(int x,int y) { return ( x^( (x^y) & -(x<y) ) ); }
void insert_node(int step,int flag,tnode * root,int data) {
	int i=0;

	tnode * new_node = (node *)malloc(sizeof(node));
	new_node->data = data;
	new_node->left_child = NULL;
	new_node->right_child = NULL;

	if(flag) {
		if(root->left_child != NULL) {
			root = root->left_child;
			i++;
		}else {
			root->left_child = new_node;
			return ; // go out //task done
		}
	} else {
		if(root->right_child != NULL) {
			root = root->right_child;
			i++;
		}else {
			root->right_child = new_node;
			return ; // go out //task done
		}
	}
	// we come to one level down
	int ok = 0;
	{
		for(i=1;i<step && !ok;i++) {
			// odd_ go _to left
			if(i&1) {
				if(root->left_child != NULL) {
					root = root->left_child;
				}else {
					root->left_child = new_node;
					ok = 1;
				}
			}else {
				if(root->right_child != NULL) {
					root = root->right_child;
				}else {
					root->right_child = new_node;
					ok= 1;
				}
			}
		}
	}

	//.....................................

}
int get_height(tnode * root) {
	int left_height=0,right_height=0;
	if(root->left_child != NULL) left_height = 1 + get_height(root->left_child);
	if(root->right_child != NULL) right_height = 1 + get_height(root->right_child);
	return (get_max(left_height,right_height));
}
int main() {
	printf("%d\n",get_max(-3,-2) );
}