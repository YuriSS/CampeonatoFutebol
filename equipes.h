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
 * Faz a impressão do vetor de Equipes */
void toString(Champs *c) {
	printf("\n\n-> Campeonato %s:\n", c->nome);
	int i;
	for(i=0; i<c->quant; i++) {
		printf("==============================================\n");
		printf("Equipe %d\n", c->times[i]->codigo);
		printf("%d pontos\n", c->times[i]->pontuacao);
		printf("%d gols\n", c->times[i]->gols);
		printf("%d saldo de gols\n", c->times[i]->saldoGol);
	}
	printf("==============================================\n\n");
}
/* [FIM] */



/* [INI]
 * Reordena vetor com o ranking das equipes
 * Ideal para ser usado a cada nova partida ou a cada nova inserção com cada equipe */
void troca(Champs *c, int index, int novoIndex) {
	Equipe *aux = c->times[novoIndex];
	c->times[novoIndex] = c->times[index];
	c->times[index] = aux;
}

int verifCodigo(Champs *c, int index, int novoIndex) {
	return (c->times[index]->codigo > c->times[novoIndex]->codigo) ? 1 : 0;
}

int verifGolsIgual(Champs *c, int index, int novoIndex) {
	return (c->times[index]->gols == c->times[novoIndex]->gols) ? verifCodigo(c, index, novoIndex) : 0;
}
int verifGols(Champs *c, int index, int novoIndex) {
	return (c->times[index]->gols >= c->times[novoIndex]->gols) ? verifGolsIgual(c, index, novoIndex) : 1;
}

int verifSaldoGolIgual(Champs *c, int index, int novoIndex) {
	return (c->times[index]->saldoGol == c->times[novoIndex]->saldoGol) ? verifGols(c, index, novoIndex) : 0;
}
int verfSaldoGol(Champs *c, int index, int novoIndex) {
	return (c->times[index]->saldoGol >= c->times[novoIndex]->saldoGol) ? verifSaldoGolIgual(c, index, novoIndex) : 1;
}

int verfPontuacao(Champs *c, int index, int novoIndex) {
	return (c->times[index]->pontuacao == c->times[novoIndex]->pontuacao) ? verfSaldoGol(c, index, novoIndex) : 0;
}

void ranking(Champs *c, int index) {
	int novoIndex = index - 1;
	if(index > 0 && c->times[index]->pontuacao >= c->times[novoIndex]->pontuacao) {
		if(verfPontuacao(c, index, novoIndex) == 0) {
			troca(c, index, novoIndex);
			ranking(c, novoIndex);
		}
	}
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
 * Faz a inserção de um novo time, caso ja tenha, exclui e insere no final do array */
void pop(Champs *c, int index) {
	int j=c->quant-1;
	for(; index<j; index++) {
		c->times[index] = c->times[index+1];
	}
	c->quant--;
}

void push(Champs *c, Equipe *e) {
	int index = search(c, e->codigo);
	if(index != -1) {
		e->gols += c->times[index]->gols;
		e->pontuacao += c->times[index]->pontuacao;
		e->saldoGol = c->times[index]->saldoGol + e->saldoGol;
		pop(c, index);
	}
	c->times[c->quant] = e;
	c->quant++;
	ranking(c, c->quant-1);
}
/* [FIM] */



/* [INI]
 * Faz esquema de partida
 * Coloca pontuaca em cada equipe e ajusta o saldo de gols */
void partida(Champs *c, int codigoTime_1, int golTime_1, int codigoTime_2, int golTime_2) {
	Equipe  *time_1 = novaEquipe(codigoTime_1),
			*time_2 = novaEquipe(codigoTime_2);
	if(golTime_1 > golTime_2) {
		time_1->pontuacao += 3;
	} else if(golTime_1 < golTime_2) {
		time_2->pontuacao += 3;
	} else {
		time_1->pontuacao += 1;
		time_2->pontuacao += 1;
	}
	time_1->gols += golTime_1;
	time_1->saldoGol = time_1->gols - golTime_2;
	time_2->gols += golTime_2;
	time_2->saldoGol = time_2->gols - golTime_1;
	push(c, time_1);
	push(c, time_2);
}
/* [FIM] */
