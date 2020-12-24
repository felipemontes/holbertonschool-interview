#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_size -measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	int size_left, size_right, total_size;

	if (!tree)
		return (0);

	size_left = binary_tree_size(tree->left);
	size_right = binary_tree_size(tree->right);
	total_size = size_left + size_right;
	return (total_size + 1);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it is null, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_is_full(tree->left) &&
		binary_tree_is_full(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_nodes, right_nodes;

	if (!tree)
		return (0);

	left_nodes = binary_tree_size(tree->left);
	right_nodes = binary_tree_size(tree->right);

	if (binary_tree_is_full(tree) && (left_nodes == right_nodes))
		return (1);

	return (0);
}

/**
 * findParent - finds the parent node
 * @root: double pointer to the root node
 * Return: a pointer to the parent node
 */
heap_t *findParent(heap_t *root)
{
	heap_t *p;
	int l, r, ld, rd;

	if (!root)
		return (NULL);

	p = root;
	l = binary_tree_size(p->left);
	r = binary_tree_size(p->right);
	ld = binary_tree_is_perfect(p->left);
	rd = binary_tree_is_perfect(p->right);
	if (!l || !r)
		return (p);
	if (!ld || (ld && rd && l == r))
		return (findParent(p->left));
	else if (!rd || (ld && rd && l > r))
		return (findParent(p->right));
	return (p);
}

/**
 * swap - swaps the nodes
 * @node: pointer to the node
 */
void swap(heap_t **node)
{
	heap_t *current;
	int tmp;

	current = *node;
	while (current->parent)
	{
		if (current->parent->n < current->n)
		{
			tmp = current->parent->n;
			current->parent->n = current->n;
			current->n = tmp;
			*node = current->parent;
		}
		current = current->parent;
	}
}

/**
 * heap_insert - inserts a max-heap
 * @root: pointer to a root.
 * @value: value to put in the new node.
 * Return: return a pointer to the new node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *parent;

	parent = findParent(*root);
	new = binary_tree_node(parent, value);
	if(!new)
		return (NULL);
	if (!parent)
		*root = new;
	else if (!parent->left)
		parent->left = new;
	else
		parent->right = new;
	swap(&new);
	return (new);
}
