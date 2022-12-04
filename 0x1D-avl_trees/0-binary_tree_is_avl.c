#include "binary_trees.h"

/**
 * isBSTUtil - checking is it is a BTS
 * @node: is a pointer to node
 * @min: minimum number
 * @max: maximum number
 *
 * Return: true if the given tree is BST and
 * its values are >= min and <= max
 */
int isBSTUtil(const binary_tree_t *node, int min, int max)
{
	if (!node)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return (isBSTUtil(node->left, min, node->n - 1) &&
		isBSTUtil(node->right, node->n + 1, max));
}


/**
 * height - compute the height of a tree.
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: if tree is not empty the height = 1 + max of left,
 * height and right heights
 */
int height(binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (0);

	lh = height(tree->left);
	rh = height(tree->right);
	if (lh >= rh)
		return (1 + lh);
	else
		return (1 + rh);
}

/**
 * isAVL - function that checks if a binary tree
 * is a valid AVL Tree
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise or
 * If tree is NULL, return 0
 */
int isAVL(const binary_tree_t *tree)
{
	int lh, rh, diff;

	if (!tree)
		return (1);
	lh = height(tree->left);
	rh = height(tree->right);
	diff = lh > rh ? lh - rh : rh - lh;
	if (diff <= 1 &&  isAVL(tree->left) && isAVL(tree->right))
		return (isBSTUtil(tree, INT_MIN, INT_MAX));

	return (0);
}

/**
 * binary_tree_is_avl - function that checks if a binary tree
 * is a valid AVL Tree
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise or
 * If tree is NULL, return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (isAVL(tree));
}
