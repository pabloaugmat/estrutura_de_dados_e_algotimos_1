

#include <iostream>

//Função para alocar memoria dinamicamente em um ponteiro de inteiro
//Parâmetros: v - ponteiro de inteiro
//            n - tamanho do vetor
void alocarVetor(int **v, int n){

    *v = (int*) malloc( n*sizeof(int) );

}

//Função para alocar memoria dinamicamente em um ponteiro de ponteiro de inteiro
//Parâmetros: l - linhas
//            c - colunas
//Retorno:    m - matriz alocada
int** alocarMatriz(int l, int c){

    int i, **m;

    m = (int**) malloc(l * sizeof(int));

    for(i = 0; i < l; i++){
        m[i] = (int*) malloc(c * sizeof(int));
    }

    return m;

}

//Função para preencher vetor de inteiros via teclado
//Parâmetros: v - ponteiro de inteiro
//            n - tamanho do vetor
void preencherVetor(int *v, int n){
    int i;

    std::cout << "Preencha o vetor V:" << std::endl;

    for(i = 0; i < n; i++){
        std::cin>>v[i];
    }

}

//Função para imprimir vetor de inteiros na tela
//Parâmetros: v - ponteiro de inteiro
//            n - tamanho do vetor
void imprimirVetor(int *v, int n){
    int i;

    std::cout << "CONTEUDO DO VETOR v:" << std::endl;

    for(i = 0; i < n; i++){
        std::cout << v[i] << " ";
    }
    std::cout<<std::endl;

}

//Função para copiar sequencialmente o vetor de inteiros para a matriz de inteiros
//Parâmetros: m - ponteiro de ponteiro de inteiro
//            v - ponteiro de inteiro
//            l - numero de linhas
//            c - numero de colunas
void preencherMatriz(int **m, int *v, int l, int c){

    int i, j, k=0;

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            m[i][j] = v[k++];
        }
    }

}

//Função para imprimir matriz de inteiros na tela
//Parâmetros: m - ponteiro de ponteiro de inteiro
//            l - numero de linhas
//            c - numero de colunas
void imprimirMatriz(int **m, int l, int c){

    int i, j;

     std::cout << "MATRIZ:" << std::endl;

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

int main(){
    
    int i, j, l, c, *v, **m;

    std::cout<<"Digite o numero de linhas: ";
    std::cin>>l;

    std::cout<<"Digite o numero de colunas: ";
    std::cin>>c;

    alocarVetor(&v, (l*c));

    m = alocarMatriz(l, c);

    preencherVetor(v, (l*c));

    imprimirVetor(v, (l*c));

    preencherMatriz(m, v, l, c);

    imprimirMatriz(m, l, c);

    free(v);

    for(i = 0; i < l; i++){
        free(m[i]);
    }
    free(m);

    return 0;
}