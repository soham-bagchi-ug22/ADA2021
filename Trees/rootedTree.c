#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int id;
	int depth;
	int parent;
	int * siblings;
	int numSiblings;
} Node;

int checkDepth(Node * tree, int n){
	if(tree[n].parent == -1) return 0;
	else {
		return 1 + checkDepth(tree, tree[n].parent);
	}
}

char * getStatus(Node * stat, int n){
	if(stat[n].parent == -1) return "root";
	else if(stat[n].numSiblings == 0) return "leaf";
	else return "internal node";
}

int main(){
	int n;
	scanf("%d", &n);
	
	Node * head = (Node *) malloc(n * sizeof(Node));

	for(int i = 0; i < n; i++){
		head[i].parent = -1; 
	} 

	for(int i = 0; i < n; i++){
		
		int num_id;
		int num_siblings;

		scanf("%d", &num_id);
		scanf("%d", &num_siblings);

		head[num_id].id				= num_id;
		head[num_id].numSiblings	= num_siblings;

		if(num_siblings > 0){
			int * arr = (int *) malloc(num_siblings * sizeof(int));
			for(int i = 0; i < num_siblings; i++){
				scanf("%d", &arr[i]);
				head[arr[i]].parent = num_id;
			}
			head[num_id].siblings = arr;
		}
	}

	for(int i = 0; i < n; i++){
		head[i].depth = checkDepth(head, i);
	}

	for(int i = 0; i < n - 1; i++){
		printf("node %d: parent = %d, depth = %d, %s, [", head[i].id, head[i].parent, head[i].depth, getStatus(head, i));
		if(head[i].numSiblings > 0){
			for(int j = 0; j < head[i].numSiblings - 1; j++){
				printf("%d, ", head[i].siblings[j]);
			}
			int j = head[i].numSiblings - 1;
			printf("%d]\n", head[i].siblings[j]);
		}
		else printf("]\n");
	}

	int i = n - 1;
	printf("node %d: parent = %d, depth = %d, %s, [", head[i].id, head[i].parent, head[i].depth, getStatus(head, i));
	if(head[i].numSiblings > 0){
		for(int j = 0; j < head[i].numSiblings - 1; j++){
			printf("%d, ", head[i].siblings[j]);
		}
		int j = head[i].numSiblings - 1;
		printf("%d]", head[i].siblings[j]);
	}
	else printf("]");

	return 0;


}