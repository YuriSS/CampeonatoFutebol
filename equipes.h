#define TAM 20


/* [INI] Estrutura de Dados */
typedef struct Equipe {
	int codigo;
	int golsMarcados;
	int golsSofridos;
	int saldoGols;
	int pontuacao;

} Equipe;



typedef struct Champs {
	char nome[31];
	Equipe* champ[TAM];	

} Champs;
/* [FIM] Estrutura de Dados */



/* [INI] Inicializadores */
Equipe* novaEquipe(int codigo) {
	Equipe* nova = (Equipe *)malloc(sizeof(Equipe));
	nova->codigo = codigo;
	nova->golsMarcados = nova->golsSofridos = nova->saldoGols = nova->pontuacao = 0;
	return nova;

}

Champs* novoChamp(char nome[31]) {
	Champs* novo = (Champs*)malloc(sizeof(Champs));
	strcpy(novo->nome, nome);
	int i;
	for(i=0; i<TAM; i++) {
		novo->champ[i] = NULL;
	}
	return novo;

}
/* [FIM] Inicializadores */



/* [INI] Insercao */
int search(Champs *c, int codigo) {

	int i = 0;
	while(c->champ[i]) {
		if(c->champ[i]->codigo == codigo) {
			return 1;
		}
		i++;
	}
	return 0;

}



int push(Champs *c, int codigo) {
	if(!(search(c, codigo))) {
		int i = 0, flag = 0;
		while(c->champ[i] && i > 0 && flag == 0) {
			printf("veio");
			if(c->champ[i] == NULL) {
				c->champ[i] = novaEquipe(codigo);
				flag = 1;
			}
			i++;
		}	
	}
	return 0;

}
/* [FIM] Insercao */



/* [INI] Impressao */
void print(Champs *c) {
	int i = 0;
	printf("---> Campeonato %s\n\n", c->nome);
	while(c->champ[i]) {
		printf("Equipe: %d\n", c->champ[i]->codigo);
		printf("Gols Marcados: %d\n", c->champ[i]->golsMarcados);
		printf("Gols Sofridos: %d\n", c->champ[i]->golsSofridos);
		printf("Saldo de Gols: %d\n", c->champ[i]->saldoGols);
		printf("Pontuacao: %d\n", c->champ[i]->pontuacao);
		printf("===================================================");
		i++;
	}

}
/* [FIM] Impressao */
