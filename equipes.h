#define TAM 20


/* [INI]
 * Dados das Equipes */
typedef struct Equipe {
	int codigo;
	int gols;
	int saldoGol;
	int pontuacao;
} Equipe;

Equipe *novaEquipe(int codigo) {
	Equipe *nova = (Equipe *)malloc(sizeof(Equipe));
	nova->codigo = codigo;
	nova->gols = nova->saldoGol = nova->pontuacao = 0;
	return nova;
}
/* [FIM] */



/* [INI]
 * Dados do Campeonato */
typedef struct Champs {
	char nome[21];
	Equipe *times[TAM];
	int quant;
} Champs;

Champs *novaChamps(char nome[21]) {
	Champs *novo = (Champs *)malloc(sizeof(Champs));
	strcpy(novo->nome, nome);
	novo->quant = 0;
	return novo;
}
/* [FIM] */



/* [INI]
 * Procura se existe equipe igual
 * Retorno: retorna a posição caso sim, -1 caso não */
int search(Champs *c, int codigo) {
	int i;
	for(i=0; i<c->quant; i++) {
		if(c->times[i]->codigo == codigo) {
			return i;
		}
	}
	return -1;
}
/* [FIM] */



/* [INI]
 * Faz a inserção de um novo times */
int push(Champs *c, int codigo) {
	if(search(c, codigo) == -1) {
		c->times[c->quant] = novaEquipe(codigo);
		c->quant++;
		return 1;
	}
	return 0;
}
/* [FIM] */



/* [INI]
 * Faz a impressão do vetor de Equipes */
void toString(Champs *c) {
	printf("\n\n-> Campeonato %s:\n", c->nome);
	int i;
	for(i=0; i<c->quant; i++) {
		printf("==============================================\n");
		printf("Equipe %d\n", c->times[i]->codigo);
		printf("%d pontos\n", c->times[i]->pontuacao);
		printf("%d saldo de gols\n", c->times[i]->saldoGol);
	}
	printf("==============================================\n\n");
}
/* [FIM] */



/* [INI]
 * Faz esquema de partida
 * Coloca pontuaca em cada equipe e ajusta o saldo de gols */
void partida(Champs *c, int codigoTime_1, int golTime_1, int codigoTime_2, int golTime_2) {
	int indexTime_1 = search(c, codigoTime_1),
		indexTime_2 = search(c, codigoTime_2);
	if(golTime_1 > golTime_2) {
		c->times[indexTime_1]->pontuacao += 3;
	} else if(golTime_1 < golTime_2) {
		c->times[indexTime_2]->pontuacao += 3;
	} else {
		c->times[indexTime_1]->pontuacao += 1;
		c->times[indexTime_2]->pontuacao += 1;
	}
	c->times[indexTime_1]->gols += golTime_1;
	c->times[indexTime_1]->saldoGol = c->times[indexTime_1]->gols - golTime_2;
	c->times[indexTime_2]->gols += golTime_2;
	c->times[indexTime_2]->saldoGol = c->times[indexTime_2]->gols - golTime_1;
}
/* [FIM] */



/* [INI]
 * Reordena vetor com o ranking das equipes
 * Ideal para ser usado a cada nova partida ou a cada nova inserção */
void troca(Champs *c, int index, int novoIndex) {
	Equipe *aux = c->times[novoIndex];
	c->times[novoIndex] = c->times[index];
	c->times[index] = aux;
}

int verfPontuacao(Champs *c, int index, int novoIndex) {
	return (c->times[index]->pontuacao == c->times[novoIndex]->pontuacao) ? 1 : 0;
}
int verfSaldoGolMaior(Champs *c, int index, int novoIndex) {
	return (c->times[index]->saldoGol >= c->times[novoIndex]->saldoGol) ? 1 : 0;
}
int verifSaldoGolIgual(Champs *c, int index, int novoIndex) {
	return (c->times[index]->saldoGol == c->times[novoIndex]->saldoGol) ? 1 : 0;
}
int verifGolsMaior(Champs *c, int index, int novoIndex) {
	return (c->times[index]->gols >= c->times[novoIndex]->gols) ? 1 : 0;
}
int verifGolsIgual(Champs *c, int index, int novoIndex) {
	return (c->times[index]->gols == c->times[novoIndex]->gols) ? 1 : 0;
}
int verifCodigo(Champs *c, int index, int novoIndex) {
	return (c->times[index]->codigo < c->times[novoIndex]->codigo) ? 1 : 0;
}

void ranking(Champs *c, int index) {
	if(index > 0 && c->times[index]->pontuacao >= c->times[index-1]->pontuacao) {
		int novoIndex = index - 1;
		if(verfPontuacao(c, index, novoIndex)) {
			if(verfSaldoGolMaior(c, index, novoIndex)) {
				if(verifSaldoGolIgual(c, index, novoIndex)) {
					if(verifGolsMaior(c, index, novoIndex)) {
						if(verifGolsIgual(c, index, novoIndex)) {
							if(verifCodigo(c, index, novoIndex)) {
								troca(c, index, novoIndex);
								ranking(c, novoIndex);
							}
						} else {
							troca(c, index, novoIndex);
							ranking(c, novoIndex);
						}
					} else {
						troca(c, index, novoIndex);
						ranking(c, novoIndex);
					}
				} else {
					troca(c, index, novoIndex);
					ranking(c, novoIndex);
				}
			} else {
				troca(c, index, novoIndex);
				ranking(c, novoIndex);
			}
		} else {
			troca(c, index, novoIndex);
			ranking(c, novoIndex);
		}
	}
}

/*
void ranking(Champs *c, int index) {
	if(index > 0 && c->times[index]->pontuacao >= c->times[index-1]->pontuacao) {
		if(c->times[index]->pontuacao == c->times[index-1]->pontuacao) {
			if(c->times[index]->saldoGol >= c->times[index-1]->saldoGol) {
				if(c->times[index]->saldoGol == c->times[index-1]->saldoGol) {

				} else {
					troca(c, index, (index-1));
					ranking(c, (index-1));
				}
			}
		} else {
			troca(c, index, (index-1));
			ranking(c, (index-1));
		}
	} else if(index < c->quant - 1 && c->times[index]->pontuacao < c->times[index+1]->pontuacao) {
		if(c->times[index]->pontuacao == c->times[index+1]->pontuacao) {
			if(c->times[index]->saldoGol < c->times[index+1]->saldoGol) {
				troca(c, index, (index+1));
				ranking(c, (index+1));
			}
		} else {
			troca(c, index, (index+1));
			ranking(c, (index+1));
		}
	}
}
*/
/* [FIM] */
