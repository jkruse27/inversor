/* Data de submissao:
 * Nome: João Gabriel Segato Kruse
 * RA: 218615
 */

#include <stdio.h>
#define tam_buffer 100

typedef struct Stack{
	char data[tam_buffer];
	int pos;
} Stack;

void init_stack(Stack *s){
	s->pos = 0;
}

void push(Stack *s, char c){
	if(s->pos < tam_buffer)
		s->data[(s->pos)++] = c;
} 

char pop(Stack *s){
	if(s->pos >= 0)
		return s->data[--(s->pos)];
}

void print_stack(Stack *s){
	while(s->pos != 0)
		printf("%c", pop(s));
}

int main() {
	char buffer[tam_buffer];
	Stack stack;
	init_stack(&stack);
	fgets(buffer, tam_buffer, stdin);
	
	for(int i = 0; buffer[i] != '\n'; i++){
		if(buffer[i] == ' '){
			print_stack(&stack);
			printf(" ");
		}
		else
			push(&stack, buffer[i]);
	}

	print_stack(&stack);
	printf("\n");
	
	return 0;
}
