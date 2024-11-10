#include <stdio.h>
struct Estudante {
    char nome[50];
    int idade;
    float media;
};
// Função que altera a idade de um estudante
void atualizar_idade(struct Estudante *estudante, int nova_idade) {
    estudante->idade = nova_idade;  // Acessa e modifica o campo 'idade' da struct
}
int main() {
    struct Estudante aluno1 = {"Carlos", 20, 7.5};
    printf("Idade antes da atualização: %d\n", aluno1.idade);
    atualizar_idade(&aluno1, 21);   // Passa o endereço de 'aluno1' para a função
    printf("Idade após a atualização: %d\n", aluno1.idade);
    return 0;
}
