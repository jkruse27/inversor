/* Data de submissao:
 * Nome: João Gabriel Segato Kruse
 * RA: 218615
 */

#include <stdio.h>
const int tam_buffer=100;

void invert_word(char *buffer, int start, int end){
	char tmp;

	for(int i = 0; start+i < end-i; i++){
		tmp = buffer[start+i];
		buffer[start+i] = buffer[end-i];
		buffer[end-i] = tmp;
	}
}

int main() {
	char buffer[tam_buffer];
	fgets(buffer, tam_buffer, stdin);

	int start = 0, i;

	for(i = 0; buffer[i] != '\n' && i < tam_buffer; i++){
 		if(buffer[i] == ' '){
			invert_word(buffer, start, i-1);
			start = i + 1;
		}
	}
	invert_word(buffer, start, i-1);

	printf("%s", buffer);
	return 0;
}
