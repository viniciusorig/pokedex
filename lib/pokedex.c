#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/pokedex.h"

//strutura onde vai ficar armezanados as informacoes do pokemon

struct Pokemon
{
    char *nome, *raca, *alimentacao;
    float peso, tamanho;
    struct Pokemon *previus, *next;
};

//criacao do no da pokedex

struct Pokemon *
create_node(char *nome, char *raca, char *alimentacao, float peso, float tamanho)
{
    struct Pokemon *aux = (struct Pokemon *)malloc(sizeof(struct Pokemon));
    strcpy(aux->alimentacao, alimentacao);
    strcpy(aux->nome, nome);
    strcpy(aux->raca, raca);
    aux->peso = peso;
    aux->tamanho = tamanho;
    aux->next = NULL;
    aux->previus = NULL;
    
    return aux;
}

//criacao da cabeca de cada lista encadiada

struct inicial_pokemon 
create_cabeca()
{
    struct inicial_pokemon aux;
    aux.init = NULL;
    aux.size = 0;
    return aux;
}

//criacao do no do hash

int
hash_i(char *nome)
{
    return (((int)nome[0]) - 97);
}

void 
insert(char *nome, char *raca, char *alimentacao, float peso, float tamanho)
{   
    if (hash[hash_i(nome)].init == NULL)
    {
        hash[hash_i(nome)].init = create_node(nome, raca, alimentacao, peso, tamanho);
        hash[hash_i(nome)].init->previus = NULL;
        hash[hash_i(nome)].init->next = NULL;
    }
    else
    {
        struct Pokemon *aux = hash[hash_i(nome)].init;
        while(aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = create_node(nome, raca, alimentacao, peso, tamanho);
        aux->next->previus = aux;
        aux->next->next = NULL;
    }
    return;
}

void
print(struct Pokemon *pk)
{
    fprintf(stdout, "nome do pokemon\traca\talimentacao\tpeso\ttamanho\n");
    fprintf(stdout, "%s\t%s\t%s\t%.2f\t%.2f\n", pk->nome, pk->raca, pk->alimentacao, pk->peso, pk->tamanho);
}

struct Pokemon *
search(char *name)
{
    struct Pokemon *aux = hash[hash_i(name)].init;
    if(aux == NULL)
    {
        fprintf(stderr, "Nao existem pokemons na sua lista");
        return ((struct Pokemon *)NULL);
    }
    if (strcmp(aux->nome, name) == 0)
    {        
        return aux;
    }
    aux = aux->next;
    while(aux != NULL)
    {
        if (strcmp(aux->nome, name) == 0)
        {          
            break;
        }
        aux = aux->next;
    }
    return aux;
}

void
save(struct inicial_pokemon tabela[])
{
    FILE *save = fopen("../save/pokedex.txt", "w");
    size_t tam = (sizeof(tabela)/sizeof(tabela[0]));
    struct Pokemon *aux = NULL;

    time_t start = time(NULL);

    for(int i = 0; i < tam; i++)
    {

        aux = hash[i].init;
        while (aux != NULL)
        {
            fprintf(save, "%s\t%s\t%s\t%.2f\t%.2f\n", aux->nome, aux->raca, aux->alimentacao, aux->peso, aux->tamanho);
            aux = aux->next;  
        }
    }
    return;
}

void load