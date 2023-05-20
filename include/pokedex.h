#ifdef POKEDEX_H
#define POKEDEX_H
#endif

#include <stdlib.h>

struct inicial_pokemon
{
    struct Pokemon *init;
    size_t size;
};

struct inicial_pokemon hash[26];

struct Pokemon *create_node(char *nome, char *raca, char *alimentacao, float peso, float tamanho);
struct inicial_pokemon create_cabeca();
int hash_i(char *nome);
void insert(char *nome, char *raca, char *alimentacao, float peso, float tamanho);
void print(struct Pokemon *pk);
struct Pokemon *search(char *name);