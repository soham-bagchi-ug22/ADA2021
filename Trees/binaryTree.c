#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int id;
	int left;
	int right;
	int depth;
	int height;
	int degree;
	int sibling;
	int parent;
} Node;


void checkDegree(Node * tree, int n){
	for(int i = 0; i < n; i++){
		if(tree[i].left != -1 && tree[i].right != -1){
			tree[i].degree = 2;
		}	
		else if(tree[i].left != -1 || tree[i].right != -1){
			tree[i].degree = 1;
		}
		else tree[i].degree = 0;
	}
}

int checkHeight(Node * tree, int n){
	if(tree[n].left == -1 && tree[n].right == -1) return 0;
	else {
		int heightLeft = -1, heightRight = -1;
		if(tree[n].left != -1) heightLeft = 1 + checkHeight(tree, tree[n].left);
		if(tree[n].right != -1) heightRight = 1 + checkHeight(tree, tree[n].right);
		if(heightLeft > heightRight){
			tree[n].height = heightLeft;
			return heightLeft;
		} 
		else{
			tree[n].height = heightRight;
			return heightRight;
		} 
	}
}

int checkDepth(Node * tree, int n){
	if(tree[n].parent == -1) return 0;
	else {
		return 1 + checkDepth(tree, tree[n].parent);
	}
}

char * getStatus(Node * stat, int n){
	if(stat[n].parent == -1) return "root";
	else if(stat[n].left == -1 && stat[n].right == -1) return "leaf";
	else return "internal node";
}

int main(){
	int n;
	scanf("%d", &n);
	
	Node * head = (Node *) malloc(n * sizeof(Node));

	for(int i = 0; i < n; i++){
		head[i].parent = -1; 
		head[i].sibling = -1;
	} 
	
	for(int i = 0; i < n; i++){
		
		int num_id;
		int num_left;
		int num_right;
		
		scanf("%d", &num_id);
		scanf("%d", &num_left);
		scanf("%d", &num_right);
		
		head[num_id].id			= num_id;
		head[num_id].left		= num_left;
		head[num_id].right		= num_right;

		if(num_left != -1){
			head[num_left].parent	= num_id;
			head[num_left].sibling	= num_right;
		}
	
		if(num_right != -1){
			head[num_right].parent	= num_id;
			head[num_right].sibling	= num_left;
		}
	}


	checkDegree(head, n);
	int headIndex;
	for(int i = 0; i < n; i++){
		if(head[i].parent == -1) headIndex = i;
	}

	head[headIndex].height = checkHeight(head, headIndex);

	for(int i = 0; i < n; i++){
		head[i].depth = checkDepth(head, i);
	}

	for(int i = 0; i < n - 1; i++){
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", head[i].id, head[i].parent, head[i].sibling, head[i].degree, head[i].depth, head[i].height, getStatus(head, i));
	}

	int i = n - 1;
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s", head[i].id, head[i].parent, head[i].sibling, head[i].degree, head[i].depth, head[i].height, getStatus(head, i));


	return 0;
}