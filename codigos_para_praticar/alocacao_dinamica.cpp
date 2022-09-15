#include <iostream>

struct cliente{
    char nome[50];
    int id;
};

int main(){

    cliente *c;

    c = (cliente*) malloc(50*sizeof(cliente));

    free(c);

    return 0;
}