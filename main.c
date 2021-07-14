#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 255

typedef struct
{
	char nome[255];
} Dado;

typedef struct no
{
	Dado dado;
	struct no *prox;
} No;

typedef struct
{
	No *inicio;
	int qtd;
} Lista;

Lista *tabela[TAM];

Dado criar_dado()
{
	Dado d;
	printf("Digite uma palavra\n");
	scanf("%*c");
	fgets(d.nome, 255, stdin);
	return d;
}

void imprimir(Dado d)
{
	printf("\nPalavra: %s", d.nome);
}

Lista *criar_lista()
{
	Lista *l = (Lista *)malloc(sizeof(Lista));
	l->inicio = NULL;
	l->qtd = 0;
	return l;
}

void inserir_inicio(Lista *li, Dado d)
{
	No *no = (No *)malloc(sizeof(No));
	no->dado = d;
	no->prox = li->inicio;
	li->inicio = no;
	li->qtd++;
}

void remove_inicio(Lista *li)
{
	No *no = li->inicio;
	*li->inicio = no->prox;
	free(no);
	li->qtd--;
}

No *buscar_no(No *inicio, char *c)
{
	while (inicio != NULL)
	{
		if (!strcmp(inicio->dado.nome, c))
		{
			return inicio;
		}
		else
		{
			inicio = inicio->prox;
		}
	}
	return NULL;
}

void imprimir_lista(No *inicio)
{
	while (inicio != NULL)
	{
		imprimir(inicio->dado);
		inicio = inicio->prox;
	}
}

/////////////////////////////
int string_hash(char *s)
{
	char c;
	int p = 31, m = 97;
	int hash_value = 0, p_pow = 1;

	while (c = *s++)
	{
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return (hash_value);
}

void inicia_tb()
{
	for (int i = 0; i < TAM; i++)
	{
		tabela[i] = criar_lista();
	}
}

void inserir_tb()
{
	Dado d = criar_dado();
	int ind = string_hash(d.nome);
	inserir_inicio(tabela[ind], d);
}

void remover_tb()
{
	int ind = string_hash(d.nome);
	remove_inicio(tabela[ind]->inicio);
}

Dado *buscar_dado_tabela(char *c)
{
	int ind = string_hash(c);
	No *no = buscar_no(tabela[ind]->inicio, c);
	if (no)
		return &no->dado;
	else
		return NULL;
}

void imprimir_tb()
{
	for (int i = 0; i < TAM; i++)
	{
		printf("\nind %d TAM lista %d\n", i, tabela[i]->qtd);
		imprimir_lista(tabela[i]->inicio);
	}
}

void main()
{
	Dado *d;
	char s[255];

	inicia_tb();

	// inserir_tb();

	fgets(s, 255, stdin);
	s[strcspn(s, "\n")] = '\0';
}
