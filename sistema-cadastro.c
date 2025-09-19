#include <stdio.h>
#include <stdlib.h>

int main(){

    char login;
    int senha;

    printf("Digite seu login: ");
    scanf("%s", &login);

    printf("Digite sua senha: ");
    scanf("%d", &senha);

     if (senha == 123456) {
        printf("Senha invalida! Nao pode ser 123456.\n");
    }
    else if (senha < 100000) {
        printf("Senha invalida! Deve ter pelo menos 6 digitos.\n");
    }
    else {
        printf("Senha valida! Acesso permitido. \n");
    }

    

    return 0;
}
