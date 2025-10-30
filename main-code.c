#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {


   char usuarioCadastrado[50];
   char senhaCadastrada[50];
   char usuarioLogin[50];
   char senhaLogin[50];
   int opcao;


   printf("=== SISTEMA COMPLETO ===\n");


   // Cadastro
   printf("\n--- CADASTRO ---\n");
   int senhaValida = 0;
   do {
       printf("Digite o usuario:    ");
       scanf("%s", usuarioCadastrado);
       printf("Digite a senha (minimo 6 caracteres): ");
       scanf("%s", senhaCadastrada);


       if (strlen(senhaCadastrada) < 6) {
           printf("Senha muito curta! Tente novamente.\n");
       } else if (strcmp(senhaCadastrada, "123456") == 0) {
           printf("Senha muito fraca! Tente novamente.\n");
       } else {
           senhaValida = 1;
           printf("Cadastro realizado com sucesso!\n");
       }
   } while (!senhaValida);


   //login
   printf("\n--- LOGIN ---\n");
   int loginRealizado = 0;
   for (int tentativas = 3; tentativas > 0; tentativas--) {
       printf("Usuario: ");
       scanf("%s", usuarioLogin);
       printf("Senha:   ");
       scanf("%s", senhaLogin);


       if (strcmp(usuarioLogin, usuarioCadastrado) == 0 && strcmp(senhaLogin, senhaCadastrada) == 0) {
           loginRealizado = 1;
           break;
       } else {
           printf("Usuario ou senha incorretos. Tentativas restantes: %d\n\n", tentativas - 1);
       }
   }


   if (!loginRealizado) {
       printf("Numero de tentativas excedido. Encerrando o programa.\n");
       return 1;
   }


   // MENU (apos login bem sucedido)
   printf("\n Login realizado com sucesso!\n");
   printf("\n Bem-vindo, %s!\n", usuarioCadastrado);
   do {
       printf("\n MENU PRINCIPAL\n");
       printf("1. Modulo Pessoal\n");
       printf("2. Modulo Financeiro\n");
       printf("3. Modulo Academico\n");
       printf("4. Modulo Utilidades\n");
       printf("5. Sair\n");
       printf("Escolha uma opcao: ");
       scanf("%d", &opcao);


       switch (opcao) {
           case 1:
               printf("Acessando o Modulo Pessoal...\n");
              
               int opcaoPessoal;


               printf("Bem vindo ao Modulo Pessoal!\n");
               printf("Escolha uma opcao:\n");
               printf("1. Verificar idade para votar\n");
               printf("2. Calcular IMC\n");
               printf("3. Voltar ao menu principal\n");
               printf("Digite a opcao desejada: ");
               scanf("%d", &opcaoPessoal);


               if (opcaoPessoal == 1) {
                   printf("Digite a sua idade: ");
                   int idade;
                   scanf("%d", &idade);
                   if (idade < 18) {
                       printf("Voce e menor de idade.\n");
                       printf("Voce nao pode votar.\n");
                   } else if (idade >= 16 && idade < 18) {
                       printf("Voce e menor de idade.\n");
                       printf("Voce pode votar, mas nao e obrigatorio.\n");
                   }else if (idade >= 18 && idade < 65) {
                       printf("Voce e maior de idade.\n");
                       printf("Voce pode votar e e obrigatorio.\n");
                   }else {
                       printf("Voce e idoso.\n");
                       printf("Voce pode votar, mas nao e obrigatorio.\n");
                   }
               } else if  (opcaoPessoal == 2) {
                   float peso, altura, imc;
                   printf("Digite seu peso em kg: ");
                   scanf("%f", &peso);
                   printf("Digite sua altura em metros: ");
                   scanf("%f", &altura);
                   imc = peso / (altura * altura);
                   printf("Seu IMC e: %.2f\n", imc);
                   if (imc < 18.5) {
                       printf("Classificacao: Abaixo do peso\n");
                   } else if (imc >= 18.5 && imc < 24.9) {
                       printf("Classificacao: Peso normal\n");
                   } else if (imc >= 25 && imc < 29.9) {
                       printf("Classificacao: Sobrepeso\n");
                   } else {
                       printf("Classificacao: Obesidade\n");
                   }
               } else if (opcaoPessoal == 3) {
                   printf("Voltando ao menu principal...\n");
               } else if (opcaoPessoal < 1 || opcaoPessoal > 3) {
                   printf("Opcao invalida! Retornando ao menu principal...\n");
               }
               break;
           case 2:
               printf("Acessando o Modulo Financeiro...\n");


               int opcaoFinanceiro;


               printf("Bem vindo ao Modulo Financeiro!\n");
               printf("Escolha uma opcao:\n");
               printf("1. Salario mensal\n");
               printf("2. Salario por dias trabalhados\n");
               printf("3. Conversao de moedas\n");
               printf("4. Voltar ao menu principal\n");
               printf("Digite a opcao desejada: ");


               scanf("%d", &opcaoFinanceiro);


               switch (opcaoFinanceiro) {
                   case 1:
                       printf("Calculo do salario mensal...\n");
                       printf("Qual o valor do seu salario em 12 meses? R$ ");
                      
                       float salarioAnual, salarioMensal;
                       scanf("%f", &salarioAnual);
                       salarioMensal = salarioAnual / 12;
                       printf("Seu salario mensal e: R$ %.2f\n", salarioMensal);


                       printf("Pressione Enter para continuar...");
                       getchar();
                       getchar();
                       break;
                   case 2:
                       printf("Calculo do seu salario por dias trabalhados...\n");
                       printf("Qual o valor do seu salario anual? R$ ");
                       float salario;
                       scanf("%f", &salario);
                       float salarioMensal2 = salario / 12;
                       float salarioDiario = salarioMensal2 / 22; // considerando 22 dias uteis por mes
                       printf("Quantos dias voce trabalhou esse mes? ");
                       int diasTrabalhados;
                       scanf("%d", &diasTrabalhados);
                       float salarioFinal = salarioDiario * diasTrabalhados;
                       printf("Seu salario dos dias trabalhados e: R$ %.2f\n", salarioFinal);


                       printf("Pressione Enter para continuar...");
                       getchar();
                       getchar();  
                       break;
                   case 3:
                       printf("Convertendo moedas...\n");


                       printf("Escolha a moeda para conversao:\n");
                       printf("1. Dolar (USD)\n");
                       printf("2. Euro (EUR)\n");
                       int moedaEscolhida;
                       printf("Digite a opcao desejada: ");
                       scanf("%d", &moedaEscolhida);


                       float valorReal, valorConvertido;
                       if (moedaEscolhida == 1) {
                           printf("Digite o valor em Reais (BRL) para converter em Dolares (USD): R$ ");
                           scanf("%f", &valorReal);
                           valorConvertido = valorReal / 5.0; // Exemplo de taxa de cambio
                           printf("R$ %.2f equivalem a $ %.2f USD\n", valorReal, valorConvertido);
                       } else if (moedaEscolhida == 2) {
                           printf("Digite o valor em Reais (BRL) para converter em Euros (EUR): R$ ");
                           scanf("%f", &valorReal);
                           valorConvertido = valorReal / 6.0; // Exemplo de taxa de cambio
                           printf("R$ %.2f equivalem a € %.2f EUR\n", valorReal, valorConvertido);
                       } else {
                           printf("Opcao de moeda invalida!\n");
                       }


                       printf("Pressione Enter para continuar...");
                       getchar();
                       getchar();
                       break;
                   case 4:
                       printf("Voltando ao menu principal...\n");
                       break;
                   default:
                       printf("Opcao invalida! Retornando ao menu principal...\n");
               }


               break;
           case 3:
               printf("Acessando o Modulo Academico...\n");


               int opcaoAcademico;
               printf("Bem vindo ao Modulo Academico!\n");
               printf("Escolha uma opcao:\n");
               printf("1. Verificar aprovacao\n");
               printf("2. Medias\n");
               printf("3. Voltar ao menu principal\n");
               printf("Digite a opcao desejada: ");
               scanf("%d", &opcaoAcademico);


               if (opcaoAcademico == 1) {
                   float nota1, nota2, media;
                   printf("Digite a primeira nota: ");
                   scanf("%f", &nota1);
                   printf("Digite a segunda nota: ");
                   scanf("%f", &nota2);
                   media = (nota1 + nota2) / 2;
                   printf("Media: %.2f\n", media);
                   if (media >= 7.0) {
                       printf("Aprovado!\n");
                   } else if (media >= 5.0) {
                       printf("Recuperacao!\n");
                   } else {
                       printf("Reprovado!\n");
                   }
               } else if (opcaoAcademico == 2) {
                   int numNotas;
                   printf("Quantas notas voce quer inserir? ");
                   scanf("%d", &numNotas);
                   float soma = 0.0, nota;
                   for (int i = 0; i < numNotas; i++) {
                       printf("Digite a nota %d: ", i + 1);
                       scanf("%f", &nota);
                       soma += nota;
                   }
                   float media = soma / numNotas;
                   printf("Media das notas: %.2f\n", media);
               } else if (opcaoAcademico == 3) {
                   printf("Voltando ao menu principal...\n");
               } else if (opcaoAcademico < 1 || opcaoAcademico > 3) {
                   printf("Opcao invalida! Retornando ao menu principal...\n");
               }
               break;
           case 4:
               printf("Acessando o Modulo Utilidades...\n");
               printf("Bem vindo ao Modulo Utilidades!\n");
               printf("Escolha uma opcao:\n");
               int opcaoUtilidades;
               printf("1. Par ou Impar\n");
               printf("2. Intervalo de 10 a 50\n");
               printf("3. Area e perimetro de um circulo ou retangulo\n");
               printf("4. Segundos em horas ou minutos\n");
               printf("5. Voltar ao menu principal\n");
               scanf("%d", &opcaoUtilidades);


               if (opcaoUtilidades == 1) {
                   int numero;
                   printf("Digite um numero inteiro: ");
                   scanf("%d", &numero);
                   if (numero % 2 == 0) {
                       printf("O numero %d e Par.\n", numero);
                   } else {
                       printf("O numero %d e Impar.\n", numero);
                   }
               } else if (opcaoUtilidades == 2) {
                   int numero;
                   printf("Digite um numero inteiro: ");
                   scanf("%d", &numero);
                   if (numero >= 10 && numero <= 50) {
                       printf("O numero %d esta no intervalo de 10 a 50.\n", numero);
                   } else {
                       printf("O numero %d nao esta no intervalo de 10 a 50.\n", numero);
                   }
               } else if (opcaoUtilidades == 3) {
                   int forma;
                   printf("Escolha a forma para calcular area e perimetro:\n");
                   printf("1. Circulo\n");
                   printf("2. Retangulo\n");
                   scanf("%d", &forma);
                   if (forma == 1) {
                       float raio, area, perimetro;
                       printf("Digite o raio do circulo: ");
                       scanf("%f", &raio);
                       area = 3.14159 * raio * raio;
                       perimetro = 2 * 3.14159 * raio;
                       printf("Area do circulo: %.2f\n", area);
                       printf("Perimetro do circulo: %.2f\n", perimetro);
                   } else if (forma == 2) {
                       float comprimento, largura, area, perimetro;
                       printf("Digite o comprimento do retangulo: ");
                       scanf("%f", &comprimento);
                       printf("Digite a largura do retangulo: ");
                       scanf("%f", &largura);
                       area = comprimento * largura;
                       perimetro = 2 * (comprimento + largura);
                       printf("Area do retangulo: %.2f\n", area);
                       printf("Perimetro do retangulo: %.2f\n", perimetro);
                   } else {
                       printf("Opcao invalida!\n");
                   }
               } else if (opcaoUtilidades == 4) {
                   int segundos;
                   printf("Digite o tempo em segundos: ");
                   scanf("%d", &segundos);
                   int horas = segundos / 3600;
                   int minutos = (segundos % 3600) / 60;
                   int segRestantes = segundos % 60;
                   printf("%d segundos equivalem a %d horas, %d minutos e %d segundos.\n", segundos, horas, minutos, segRestantes);
               } else if (opcaoUtilidades == 5) {
                   printf("Voltando ao menu principal...\n");
               } else if (opcaoUtilidades < 1 || opcaoUtilidades > 5) {
                   printf("Opcao invalida! Retornando ao menu principal...\n");
               }
               break;
           case 5:
               printf("Saindo do sistema. Ate logo!\n");
               break;
           default:
               printf("Opcao invalida! Tente novamente.\n");
       }
   } while (opcao != 5);




   return 0;


}
