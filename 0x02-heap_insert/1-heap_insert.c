#include "binary_trees.h"

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap
 * @root: a double pointer to the root node of the Heap
 * @value: the value to store in the node to be inserted
 * return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t nNode;
	heap_t *ptr;

	if (*root == NULL)
		return (*root = binary_tree_node(NULL, value));
	nNode = HeapSize(*root) + 1;
	ptr = LevelInsert(*root, value, 1, nNode);

    while (ptr && ptr->parent && ptr->n > ptr->parent->n)
    {
		ptr->n = ptr->parent->n;
		ptr->parent->n = value;
		ptr = ptr->parent;
	}
	return (ptr);
}
/**
 * LevelInsert - Inserts node level ordered
 * @root: Type binary_tree pointer of the parent node
 * @value: Type int value of value inserted into node
 * @index: index of node
 * @nNode: number the nodes + 1
 * Return: Node inserted
 */
heap_t *LevelInsert(binary_tree_t *root, int value, size_t index, size_t nNode)
{
	heap_t *left_node, *right_node;
	size_t parent = nNode / 2;

	if (!root)
		return (NULL);
	if (index == parent)
	{
		if (nNode % 2)
			return (root->right = binary_tree_node(root, value));
		else
			return (root->left = binary_tree_node(root, value));
	}
	left_node = LevelInsert(root->left, value, 2 * index, nNode);
	right_node = LevelInsert(root->right, value, 2 * index + 1, nNode);
	if (left_node)
		return (left_node);
	else
		return (right_node);
}
/**
 * HeapSize - fn to get the size of the heap
 * @root: pointer to root node
 * Return: number of nodes
 */
size_t HeapSize(heap_t *root)
{
	int left = 0, right = 0;

	if (root == NULL)
		return (0);
	left = HeapSize(root->left);
	right = HeapSize(root->right);
	return (1 + left + right);
}