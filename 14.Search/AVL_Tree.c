#include<stdio.h> 
#include<stdlib.h> 
#define MAX(a, b) (a)

// AVL 트리 구조체
typedef struct AVLNode{
	int key;
	struct AVLNode* left;
	struct AVLNode* right;
} AVLNode;

// 높이 찾기
int get_height(AVLNode* node){
	int height = 0;

	if(node != NULL)
		height = 1 + MAX(get_height(node->left), get_height(node->right));
	return height;
}

// 균형 인수(balance factor) 찾기
int get_balance(AVLNode* node){
	if (node == NULL) return 0;

	return get_height(node->left) - get_height(node->right);
}

// 노드 생성
AVLNode* create_node(int key){
	AVLNode* node = (AVLNode *)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

// LL타입일 때 경우
AVLNode* rotate_right(AVLNode* parent){
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	// root가 child이므로 child를 반환
	return child;
}

// RR타입일 때 경우
AVLNode* rotate_left(AVLNode* parent){
	AVLNode* child = parent->right;
	parent->right = child->left;
	child->left = parent;

	// root가 child이므로 child를 반환
	return child;
}

// AVL 트리의 삽입 연산 
AVLNode* insert(AVLNode* node, int key){
	// 트리가 비어있을 때
	if(node == NULL)
		return(create_node(key));

	if(key < node->key)
		node->left = insert(node->left, key);
	else if(key > node->key)
		node->right = insert(node->right, key);
	else	// node와 key가 같을 때
		return node;

	// 균형 인수
	int balance = get_balance(node);

	// LL 타입일 때
	if(balance > 1 && key < node->left->key)
		return rotate_right(node);

	// RR 타입일 때
	if(balance < -1 && key > node->right->key)
		return rotate_left(node);

	// LR 타입일 때
	if(balance > 1 && key > node->left->key){
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}

	// RL 타입일 때
	if(balance < -1 && key < node->right->key){
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}

	return node;
}

// preorder traversal
void preorder(AVLNode* root){
	if(root != NULL){
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main(){
	AVLNode* root = NULL;

	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 29);

	printf("AVL Tree Traversal \n");
	preorder(root);
    printf("\n");

	return 0;
}