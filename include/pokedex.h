#include <stdlib.h>

struct inicial_pokemon
{
    struct Pokemon *init;
    size_t size;
};

struct inicial_pokemon hash[26];

struct Pokemon *
create_node(char *nome, char *raca, char *alimentacao, float peso, float tamanho);