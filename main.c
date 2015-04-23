#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipes.h"

int main() {
	Champs* br = novoChamp("Brasileiro");
	push(br, 400);
	push(br, 401);
	push(br, 401);

	printf("\n\n");
	print(br);
	printf("\n\n");

	return 0;
}
