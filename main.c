#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipes.h"


int main() {
	Champs *bra = novaChamps("Brasileiro");
	char string[100];
	
	FILE *f = fopen("texto.txt", "r");
	if(f == NULL) {
		return 0;
	}

	int i=0, codigo_1, codigo_2, gols_1, gols_2;
	while(fscanf(f, "%s", string) != EOF) {
		if(i > 0) {
			if(i%4==1) {
				codigo_1 = atoi(string);
			} else if(i%4==2) {
				gols_1 = atoi(string);
			} else if(i%4==3) {
				codigo_2 = atoi(string);
			} else if(i%4==0) {
				gols_2 = atoi(string);
				partida(bra, codigo_1, gols_1, codigo_2, gols_2);
			}
		}
		i++;
	}
	fclose(f);
	toString(bra);

	return 0;
}
