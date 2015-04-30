#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "champs.h"


int main() {
	Champs *bra = novaChamps("Brasileiro");
	char string[100];
	
	FILE *f = fopen("texto.txt", "r");
	if(f == NULL) {
		printf("veio");
		return 0;
	}

	int i=0, codigo_1, codigo_2, gols_1, gols_2, sh;
	while(fscanf(f, "%s", string) != EOF) {
		if(i%4==0) {
			codigo_1 = atoi(string);
		} else if(i%4==1) {
			gols_1 = atoi(string);
		} else if(i%4==2) {
			codigo_2 = atoi(string);
		} else if(i%4==3) {
			gols_2 = atoi(string);
		}
		i++;
		printf("%d\n", gols_1);
		push(bra, codigo_1);
		push(bra, codigo_2);
		partida(bra, codigo_1, gols_1, codigo_2, gols_2);
		sh = search(bra, codigo_1);
		ranking(bra, sh);
		sh = search(bra, codigo_2);
		ranking(bra, sh);
	}
	fclose(f);
	toString(bra);

	/*
	int sh;
	push(bra, 300);
	push(bra, 301);

	partida(bra, 301, 1, 300, 2);
	
	sh = search(bra, 300);
	ranking(bra, sh);
	
	sh = search(bra, 301);
	ranking(bra, sh);
	
	push(bra, 302);
	push(bra, 303);
	
	partida(bra, 302, 2, 303, 0);
	
	sh = search(bra, 302);
	ranking(bra, sh);
	
	sh = search(bra, 303);
	ranking(bra, sh);
	
	toString(bra);*/

	return 0;
}
