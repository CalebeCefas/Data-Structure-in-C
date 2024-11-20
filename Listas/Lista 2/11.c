/*11.Structs e Funções:
Crie um programa que defina um struct para um livro com título, autor e
ano de publicação. Escreva uma função que receba um array de livros e
retorne o título do livro mais recente.*/

#include <stdio.h>

struct Livro {
    char titulo[100];
    char autor[100];
    int anoPublicacao;
};

void livroRecente(struct Livro *livros, int tamanho) {
    int indiceRecente = 0;

    for (int i = 1; i < tamanho; i++) {
        if (livros[i].anoPublicacao > livros[indiceRecente].anoPublicacao) {
            indiceRecente = i;
        }
    }

    printf("\nLivro mais recente:\n");
    printf("Título: %s\n", livros[indiceRecente].titulo);
    printf("Autor: %s\n", livros[indiceRecente].autor);
    printf("Ano de Publicação: %d\n", livros[indiceRecente].anoPublicacao);
}

int main() {
    struct Livro livros[10] = {
        {"Dom Casmurro", "Machado de Assis", 1899},
        {"1984", "George Orwell", 1949},
        {"O Pequeno Príncipe", "Antoine de Saint-Exupéry", 1943},
        {"A Revolução dos Bichos", "George Orwell", 1945},
        {"Harry Potter e a Pedra Filosofal", "J.K. Rowling", 1997},
        {"O Senhor dos Anéis: A Sociedade do Anel", "J.R.R. Tolkien", 1954},
        {"O Alquimista", "Paulo Coelho", 1988},
        {"Capitães da Areia", "Jorge Amado", 1937},
        {"Memórias Póstumas de Brás Cubas", "Machado de Assis", 1881},
        {"Orgulho e Preconceito", "Jane Austen", 1813}
    };

    char op;
    printf("Deseja visualizar qual livro é mais recente? (s/n): ");
    scanf(" %c", &op);

    if (op == 's' || op == 'S') {
        livroRecente(livros, 10);
    } else {
        printf("Até mais!!!\n");
    }

    return 0;
}