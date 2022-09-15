

#include <iostream>

struct aluno
{
    int matricula;
    char nome[50];
    int dia_nasc;
    int mes_nasc;
    int ano_nasc;
    float nota;
};

// Função para alocar dinamicamente um ponteiro de inteiro
// Parâmetros: v - ponteiro de ponteiro de inteiro
//             n - tamanho do vetor
void alocar(aluno **v, int n)
{

    *v = (aluno *)malloc(n * sizeof(aluno));
}

// Função para preencher um registro
// Parâmetros: v - ponteiro de aluno(struct)
void cadastrarAluno(aluno *v)
{

    std::cout << "Matricula: ";
    std::cin >> v->matricula;
    std::cout << "Nome: ";
    getchar();
    std::cin.getline(v->nome, 50);
    std::cout << "Dia de nascimento: ";
    std::cin >> v->dia_nasc;
    std::cout << "Mes de nascimento: ";
    std::cin >> v->mes_nasc;
    std::cout << "Ano de nascimento: ";
    std::cin >> v->ano_nasc;
    std::cout << "Nota: ";
    std::cin >> v->nota;
    std::cout << "==========================" << std::endl;
}

// Função para preencher vetor de aluno(struct)
// Parâmetros: v - ponteiro de aluno(struct)
//             n - tamanho do vetor
void preencherVetor(aluno *v, int n)
{

    int i;

    for (i = 0; i < n; i++)
    {

        std::cout << "ALUNO " << i + 1 << ":" << std::endl;
        cadastrarAluno(&v[i]);
    }
}

// Função para imprimir um registro
// Parâmetros: v - registro de aluno(struct)
void imprimeAprovado(aluno v)
{

    if (v.nota >= 6)
    {
        std::cout << "Matricula: " << v.matricula << std::endl;
        std::cout << "Nome: " << v.nome << std::endl;
        std::cout << "data de nascimento: " << v.dia_nasc;
        std::cout << "/" << v.mes_nasc;
        std::cout << "/" << v.ano_nasc << std::endl;
        std::cout << "Nota " << v.nota << std::endl;
        std::cout << "==========================" << std::endl;
    }
}

// Função para ler vetor de aluno(struct)
// Parâmetros: v - ponteiro de aluno(struct)
//             n - tamanho do vetor
void lerVetor(aluno *v, int n)
{

    int i;

    std::cout << "ALUNOS APROVADOS:" << std::endl;
    for (i = 0; i < n; i++)
    {
        imprimeAprovado(v[i]);
    }
}

int main()
{

    int n, i;
    aluno *v;

    std::cout << "Digite o numero de alunos a serem cadastrados:";
    std::cin >> n;

    alocar(&v, n);

    preencherVetor(v, n);

    lerVetor(v, n);

    free(v);

    return 0;
}
