#include "binary_trees.h"
#include "limits.h"

/**
 * minValueNode - Searches bst for node to remove
 * @node: pointer to BST tree node
 * Return: Pointer to node with value or NULL
*/
bst_t *minValueNode(bst_t *node)
{
bst_t *current = node;

while (current && current->left != NULL)
current = current->left;

return (current);
}

/**
 * bst_remove - Searches bst for node to remove
 * @root: pointer to BST tree node
 * @value: value to search for
 * Return: Pointer to node with value or NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
bst_t *temp;

if (root == NULL)
return (root);

if (value < root->n)
root->left = bst_remove(root->left, value);

else if (value > root->n)
root->right = bst_remove(root->right, value);

else
{
if (root->left == NULL)
{
temp = root->right;
free(root);
return (temp);
}
else if (root->right == NULL)
{
temp = root->left;
free(root);
return (temp);
}

temp = minValueNode(root->right);

root->n = temp->n;

root->right = bst_remove(root->right, temp->n);
}
return (root);
}
