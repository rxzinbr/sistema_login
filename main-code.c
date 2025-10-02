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
       printf("Digite o usuário:    ");
       scanf("%s", usuarioCadastrado);
       printf("Digite a senha (mínimo 6 caracteres): ");
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
       printf("Usuário: ");
       scanf("%s", usuarioLogin);
       printf("Senha:   ");
       scanf("%s", senhaLogin);


       if (strcmp(usuarioLogin, usuarioCadastrado) == 0 && strcmp(senhaLogin, senhaCadastrada) == 0) {
           loginRealizado = 1;
           break;
       } else {
           printf("Usuário ou senha incorretos. Tentativas restantes: %d\n\n", tentativas - 1);
       }
   }


   if (!loginRealizado) {
       printf("Número de tentativas excedido. Encerrando o programa.\n");
       return 1;
   }


   // MENU (apos login bem sucedido)
   printf("\n Login realizado com sucesso!\n");
   printf("\n bem-vindo, %s!\n", usuarioCadastrado);
   do {
       printf("\n MENU PRINCIPAL\n");
       printf("1. Modulo Pessoal\n");
       printf("2. Modulo Financeiro\n");
       printf("3. Modulo Acadêmico\n");
       printf("4. Modulo Utilidades\n");
       printf("5. Sair\n");
       printf("Escolha uma opção: ");
       scanf("%d", &opcao);


       switch (opcao) {
           case 1:
               printf("Acessando o Módulo Pessoal...\n");
              
               int opcaoPessoal;


               printf("Bem vindo ao Módulo Pessoal!\n");
               printf("Escolha uma opção:\n");
               printf("1. Verificar idade para votar\n");
               printf("2. Calcular IMC\n");
               printf("3. Voltar ao menu principal\n");
               printf("Digite a opção desejada: ");
               scanf("%d", &opcaoPessoal);


               if (opcaoPessoal == 1) {
                   printf("Digite a sua idade: ");
                   int idade;
                   scanf("%d", &idade);
                   if (idade < 18) {
                       printf("Você é menor de idade.\n");
                       printf("você não pode votar.\n");
                   } else if (idade >= 16 && idade < 18) {
                       printf("Você é menor de idade.\n");
                       printf("você pode votar, mas não é obrigatório.\n");
                   }else if (idade >= 18 && idade < 65) {
                       printf("Você é maior de idade.\n");
                       printf("você pode votar e é obrigatório.\n");
                   }else {
                       printf("Você é idoso.\n");
                       printf("você pode votar, mas não é obrigatório.\n");
                   }
               } else if  (opcaoPessoal == 2) {
                   float peso, altura, imc;
                   printf("Digite seu peso em kg: ");
                   scanf("%f", &peso);
                   printf("Digite sua altura em metros: ");
                   scanf("%f", &altura);
                   imc = peso / (altura * altura);
                   printf("Seu IMC é: %.2f\n", imc);
                   if (imc < 18.5) {
                       printf("Classificação: Abaixo do peso\n");
                   } else if (imc >= 18.5 && imc < 24.9) {
                       printf("Classificação: Peso normal\n");
                   } else if (imc >= 25 && imc < 29.9) {
                       printf("Classificação: Sobrepeso\n");
                   } else {
                       printf("Classificação: Obesidade\n");
                   }
               } else if (opcaoPessoal == 3) {
                   printf("Voltando ao menu principal...\n");
               } else if (opcaoPessoal < 1 || opcaoPessoal > 3) {
                   printf("Opção inválida! Retornando ao menu principal...\n");
               }
               break;
           case 2:
               printf("Acessando o Módulo Financeiro...\n");


               int opcaoFinanceiro;


               printf("Bem vindo ao Módulo Financeiro!\n");
               printf("Escolha uma opção:\n");
               printf("1. salario mensal\n");
               printf("2. salario por dias trabalhados\n");
               printf("3. Conversao de moedas\n");
               printf("4. Voltar ao menu principal\n");
               printf("Digite a opção desejada: ");


               scanf("%d", &opcaoFinanceiro);


               switch (opcaoFinanceiro) {
                   case 1:
                       printf("Calculo do salário mensal...\n");
                       printf("Qual o valor do seu salário em 12 meses? R$ ");
                      
                       float salarioAnual, salarioMensal;
                       scanf("%f", &salarioAnual);
                       salarioMensal = salarioAnual / 12;
                       printf("Seu salário mensal é: R$ %.2f\n", salarioMensal);


                       printf("Pressione Enter para continuar...");
                       getchar();
                       getchar();
                       break;
                   case 2:
                       printf("Calculo do seu salário por dias trabalhados...\n");
                       printf("Qual o valor do seu salário anual? R$ ");
                       float salario;
                       scanf("%f", &salario);
                       float salarioMensal2 = salario / 12;
                       float salarioDiario = salarioMensal2 / 22; // considerando 22 dias úteis por mês
                       printf("Quantos dias você trabalhou esse mês? ");
                       int diasTrabalhados;
                       scanf("%d", &diasTrabalhados);
                       float salarioFinal = salarioDiario * diasTrabalhados;
                       printf("Seu salário dos dias trabalhados é: R$ %.2f\n", salarioFinal);


                       printf("Pressione Enter para continuar...");
                       getchar();
                       getchar();  
                       break;
                   case 3:
                       printf("Convertendo moedas...\n");


                       printf("Escolha a moeda para conversão:\n");
                       printf("1. Dólar (USD)\n");
                       printf("2. Euro (EUR)\n");
                       int moedaEscolhida;
                       printf("Digite a opção desejada: ");
                       scanf("%d", &moedaEscolhida);


                       float valorReal, valorConvertido;
                       if (moedaEscolhida == 1) {
                           printf("Digite o valor em Reais (BRL) para converter em Dólares (USD): R$ ");
                           scanf("%f", &valorReal);
                           valorConvertido = valorReal / 5.0; // Exemplo de taxa de câmbio
                           printf("R$ %.2f equivalem a $ %.2f USD\n", valorReal, valorConvertido);
                       } else if (moedaEscolhida == 2) {
                           printf("Digite o valor em Reais (BRL) para converter em Euros (EUR): R$ ");
                           scanf("%f", &valorReal);
                           valorConvertido = valorReal / 6.0; // Exemplo de taxa de câmbio
                           printf("R$ %.2f equivalem a € %.2f EUR\n", valorReal, valorConvertido);
                       } else {
                           printf("Opção de moeda inválida!\n");
                       }


                       printf("Pressione Enter para continuar...");
                       getchar();
                       getchar();
                       break;
                   case 4:
                       printf("Voltando ao menu principal...\n");
                       break;
                   default:
                       printf("Opção inválida! Retornando ao menu principal...\n");
               }


               break;
           case 3:
               printf("Acessando o Módulo Acadêmico...\n");


               int opcaoAcademico;
               printf("Bem vindo ao Módulo Acadêmico!\n");
               printf("Escolha uma opção:\n");
               printf("1. Verificar aprovação\n");
               printf("2. Médias\n");
               printf("3. Voltar ao menu principal\n");
               printf("Digite a opção desejada: ");
               scanf("%d", &opcaoAcademico);


               if (opcaoAcademico == 1) {
                   float nota1, nota2, media;
                   printf("Digite a primeira nota: ");
                   scanf("%f", &nota1);
                   printf("Digite a segunda nota: ");
                   scanf("%f", &nota2);
                   media = (nota1 + nota2) / 2;
                   printf("Média: %.2f\n", media);
                   if (media >= 7.0) {
                       printf("Aprovado!\n");
                   } else if (media >= 5.0) {
                       printf("Recuperação!\n");
                   } else {
                       printf("Reprovado!\n");
                   }
               } else if (opcaoAcademico == 2) {
                   int numNotas;
                   printf("Quantas notas você quer inserir? ");
                   scanf("%d", &numNotas);
                   float soma = 0.0, nota;
                   for (int i = 0; i < numNotas; i++) {
                       printf("Digite a nota %d: ", i + 1);
                       scanf("%f", &nota);
                       soma += nota;
                   }
                   float media = soma / numNotas;
                   printf("Média das notas: %.2f\n", media);
               } else if (opcaoAcademico == 3) {
                   printf("Voltando ao menu principal...\n");
               } else if (opcaoAcademico < 1 || opcaoAcademico > 3) {
                   printf("Opção inválida! Retornando ao menu principal...\n");
               }
               break;
           case 4:
               printf("Acessando o Módulo Utilidades...\n");
               printf("Bem vindo ao Módulo Utilidades!\n");
               printf("Escolha uma opção:\n");
               int opcaoUtilidades;
               printf("1. Par ou Impar\n");
               printf("2. intervalo de 10 a 50\n");
               printf("3. area e prímetro de um circulo ou retângulo\n");
               printf("4. segundos em horas ou minutos\n");
               printf("5. Voltar ao menu principal\n");
               scanf("%d", &opcaoUtilidades);


               if (opcaoUtilidades == 1) {
                   int numero;
                   printf("Digite um número inteiro: ");
                   scanf("%d", &numero);
                   if (numero % 2 == 0) {
                       printf("O número %d é Par.\n", numero);
                   } else {
                       printf("O número %d é Ímpar.\n", numero);
                   }
               } else if (opcaoUtilidades == 2) {
                   int numero;
                   printf("Digite um número inteiro: ");
                   scanf("%d", &numero);
                   if (numero >= 10 && numero <= 50) {
                       printf("O número %d está no intervalo de 10 a 50.\n", numero);
                   } else {
                       printf("O número %d não está no intervalo de 10 a 50.\n", numero);
                   }
               } else if (opcaoUtilidades == 3) {
                   int forma;
                   printf("Escolha a forma para calcular área e perímetro:\n");
                   printf("1. Círculo\n");
                   printf("2. Retângulo\n");
                   scanf("%d", &forma);
                   if (forma == 1) {
                       float raio, area, perimetro;
                       printf("Digite o raio do círculo: ");
                       scanf("%f", &raio);
                       area = 3.14159 * raio * raio;
                       perimetro = 2 * 3.14159 * raio;
                       printf("Área do círculo: %.2f\n", area);
                       printf("Perímetro do círculo: %.2f\n", perimetro);
                   } else if (forma == 2) {
                       float comprimento, largura, area, perimetro;
                       printf("Digite o comprimento do retângulo: ");
                       scanf("%f", &comprimento);
                       printf("Digite a largura do retângulo: ");
                       scanf("%f", &largura);
                       area = comprimento * largura;
                       perimetro = 2 * (comprimento + largura);
                       printf("Área do retângulo: %.2f\n", area);
                       printf("Perímetro do retângulo: %.2f\n", perimetro);
                   } else {
                       printf("Opção inválida!\n");
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
                   printf("Opção inválida! Retornando ao menu principal...\n");
               }
               break;
           case 5:
               printf("Saindo do sistema. Até logo!\n");
               break;
           default:
               printf("Opção inválida! Tente novamente.\n");
       }
   } while (opcao != 5);




   return 0;


}
