#include "tree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void tree_print_node(Node *node) {
	if (node == NULL){
	return;
	}
    tree_print_node(node->left);
    printf("%d %d\n", node->count, node->key);
    tree_print_node(node->right);
}

void tree_print(Tree *tree) {
    if (tree == NULL || tree->root == NULL){
	    return;
    }
	tree_print_node(tree->root);
}

Tree *tree_alloc(void) {
    Tree *new_tree = (Tree*)calloc(1, sizeof(Tree));
    assert (new_tree != NULL);
	return new_tree;
}

void tree_add(Tree *tree, int key) {
    assert(tree);

    if (tree->root == NULL){
	tree->root = (Node *)malloc(sizeof(Node));
	assert(tree->root != NULL);
	tree->root->key = key;
	tree->root->count = 1;
	tree->root->left = NULL;
	tree->root->right = NULL;
	return;
    }

    Node *curNode = tree->root;
    Node *parNode = NULL;

    while (curNode != NULL){
	parNode = curNode;
	if (key == curNode->key){
		curNode->count++;
		return;
	}
	else if (key < curNode->key){
		curNode = curNode->left;
	}
	else {
		curNode = curNode->right;
	}
    }

    Node *new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->key = key;
    new->count = 1;
    new->left = NULL;
    new->right = NULL;

    if (key < parNode->key){
	parNode->left = new;
    }
    else{
	parNode->right = new;
    }
	

}

void tree_free_node(Node *node) {
	if (node == NULL){
		return;
	}
	tree_free_node(node->left);
	tree_free_node(node->right);
	free(node);
}
void tree_free(Tree **p) {
    assert(p);
    if (*p == NULL){
	return;
    }
    tree_free_node((*p)->root);
    (*p)->root = NULL;
    free(*p);
    *p = NULL;
}
void tree_dump_node(Node *node, int level, char prefix) {
    if (node) {
        tree_dump_node(node->right, level + 1, '/');
        printf("%*c %d (x%d)\n", 4 * level + 1, prefix, node->key,
                node->count);
        tree_dump_node(node->left, level + 1, '\\');
    } else {
        printf("%*c NULL\n", 4 * level + 1, prefix);
    }
}

void tree_dump(Tree *tree) {
    assert(tree);
    tree_dump_node(tree->root, 0, '<');
}

