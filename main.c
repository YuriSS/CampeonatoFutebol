#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "champs.h"


int main() {
	Champs *bra = novaChamps("Brasileirao");
	push(bra, 300);
	push(bra, 301);
	partida(bra, 301, 1, 300, 2);
	ranking(bra, search(bra, 300));
	ranking(bra, search(bra, 301));
	push(bra, 302);
	push(bra, 303);
	partida(bra, 302, 2, 303, 0);
	ranking(bra, search(bra, 302));
	ranking(bra, search(bra, 303));
	toString(bra);

	printf("\n%d\n", bra->quant);

	return 0;
}
