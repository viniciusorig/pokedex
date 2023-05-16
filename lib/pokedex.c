#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct inicial_pokemo *
create_cabeca()
{
    struct inicial_pokemon *aux = (struct inicial_pokemon *)malloc(sizeof(struct inicial_pokemon));
    aux->init = NULL;
    aux->size = 0;
    return aux;
}

//criacao do no do hash

int
hash_i(char *nome)
{
    return (((int)nome[0]) - 97);
}

