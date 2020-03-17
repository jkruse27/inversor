/* Data de submissao:
 * Nome: João Gabriel Segato Kruse
 * RA: 218615
 */

#include <stdio.h>
#define tam_buffer 100

//Struct da Pilha
typedef struct Stack{
	char data[tam_buffer];
	int pos;
} Stack;

//Inicializa a pilha vazia
void init_stack(Stack *s){
	s->pos = 0;
}

//Adiciona elemento ao topo da pilha
void push(Stack *s, char c){
	if(s->pos < tam_buffer)
		s->data[(s->pos)++] = c;
} 

//Retira e retorna o elemento do topo da pilha
char pop(Stack *s){
	if(s->pos >= 0)
		return s->data[--(s->pos)];
}

//Imprime tudo o que tem na pilha
void print_stack(Stack *s){
	while(s->pos != 0)
		printf("%c", pop(s));
}


int main() {
	char buffer[tam_buffer];
	Stack stack;
	init_stack(&stack);
	fgets(buffer, tam_buffer, stdin);
	
	//Loop que adiciona cada letra a pilha e quando a palavra termina imprime a pilha
	for(int i = 0; buffer[i] != '\n'; i++){
		if(buffer[i] == ' '){
			print_stack(&stack);
			printf(" ");
		}
		else
			push(&stack, buffer[i]);
	}

	//imprime o que restou na pilha (ultima palavra)
	print_stack(&stack);
	printf("\n");
	
	return 0;
}
