#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - stack_head linked list representation of a stack or queue
 * @n: integer
 * @prev: points to the previous element of the stack or queue
 * @next: points to the next element of the stack or queue
 *
 * Description: stack_head linked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: stack_head linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: stack_head linked list node structure
*/

typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t vglo;

/* opcode_instructuions*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack_head, unsigned int line_num);
void _pop(stack_t **stack_head, unsigned int line_num);
void _swap(stack_t **stack_head, unsigned int line_num);
void _queue(stack_t **stack_head, unsigned int line_num);
void _stack(stack_t **stack_head, unsigned int line_num);
void _add(stack_t **stack_head, unsigned int line_num);
void _nop(stack_t **stack_head, unsigned int line_num);
void _sub(stack_t **stack_head, unsigned int line_num);
void _div(stack_t **stack_head, unsigned int line_num);
void _mul(stack_t **stack_head, unsigned int line_num);
void _mod(stack_t **stack_head, unsigned int line_num);
void _pchar(stack_t **stack_head, unsigned int line_num);
void _pstr(stack_t **stack_head, unsigned int line_num);
void _rotl(stack_t **stack_head, unsigned int line_num);
void _rotr(stack_t **stack_head, unsigned int line_num);

/*get function*/
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);

/* stack_head linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main */
void free_vglo(void);

#endif
