#include "shell.h"
/**
 * add_node_end - a function that adds a new node at the end
 * of a list_dir list.
 * @head: a list_dir list.
 * @str: the element to add.
 * Return: the address of the new element, or NULL if it faile.
 */
list_path *add_node_end(list_path **head, const char *str)
{
	list_path *new_node, *tmp;

	if (head == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_path));
	if (new_node == NULL)
		return (NULL);

	new_node->dir = _strdup(str);
	if (new_node->dir == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	/* if the list is empty set the head to the new node */
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	/* Otherwise find the last node in the list and add new node */
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new_node;
	return (*head);
}
/**
 * free_list_dir - Frees a list_dir list
 * @head: Start of the list
 * Return: (void)
 */
void free_list_dir(list_path *head)
{
	list_path *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head->next;
		free(head->dir);
		free(head);
		head = tmp;
	}
}
