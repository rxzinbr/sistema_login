# sistema_login
Desenvolvimento de um Sistema de Login - Linguagem C



# Portal de Serviços — README

## Descrição do projeto

Este é um programa em C que funciona como um portal de serviços para o usuário. Ele reúne operações matemáticas, verificações lógicas e classificações, organizadas em diferentes módulos: Pessoal, Financeiro, Acadêmico e Utilidades. Antes de acessar esses recursos, o usuário deve realizar um cadastro e login com senha validada.

O projeto foi desenvolvido de forma simples, adequado para estudantes iniciantes em programação em C. Não há uso de ponteiros explícitos e todas as funções foram escritas retornando `int`, em vez de `void`, seguindo boas práticas para clareza no aprendizado.

---

## Funcionalidades implementadas

1. **Cadastro e Login**

   * Permite criar login e senha.
   * A senha precisa ser considerada forte: mínimo de 6 caracteres, não pode ser vazia ou a sequência "123456".
   * O acesso ao portal só é liberado após autenticação correta.

2. **Módulo Pessoal**

   * Solicita a idade do usuário e informa se é maior ou menor de idade.
   * Avalia a condição de voto conforme a faixa etária (não vota, voto opcional, voto obrigatório).
   * Calcula o IMC (peso / altura²), exibindo o resultado com duas casas decimais.

3. **Módulo Financeiro**

   * Calcula a renda anual com base no salário mensal informado.
   * Permite calcular a remuneração de acordo com dias trabalhados e valor da diária.
   * Faz a conversão de valores em reais para dólares e euros (com taxas fixas definidas no código).

4. **Módulo Acadêmico**

   * Recebe as notas do aluno e determina sua situação: aprovado, recuperação ou reprovado.
   * Mostra a soma das notas, a média e também o dobro da média.

5. **Módulo Utilidades**

   * Verifica se um número é par ou ímpar.
   * Confere se um número está dentro do intervalo \[10, 50].
   * Calcula área e perímetro de figuras simples (círculo e retângulo).
   * Converte segundos em horas e minutos.

---

## Constantes de câmbio

* `DOLAR = 5.00` (exemplo; pode ser atualizado manualmente)
* `EURO  = 5.50` (exemplo; pode ser atualizado manualmente)

> Observação: os valores de câmbio são fixos no código apenas para fins de exercício.

---

## Estrutura de arquivos sugerida

* `README.md` (documentação do projeto)
* `src/main.c` (código-fonte em C)
* `LICENSE` (opcional)

---

## Como compilar

No terminal (Linux, macOS ou Windows com MinGW):

```bash
gcc -o portal src/main.c -lm
./portal
```

(O `-lm` é necessário para a biblioteca matemática `math.h` usada nos cálculos de área do círculo.)

---

## Como usar

1. Execute o programa.
2. Cadastre um login e senha.
3. Faça login com as credenciais criadas.
4. Navegue pelo menu principal e explore os módulos disponíveis.

---

## Exemplos de uso

### Cadastro e Login

```text
--- CADASTRO ---
Digite um login (sem espaços): joao123
Digite uma senha: seguran9
Cadastro realizado com sucesso!

--- LOGIN ---
Login: joao123
Senha: seguran9
Login bem-sucedido!
```

### Módulo Pessoal

```text
--- MÓDULO PESSOAL ---
Digite sua idade: 20
Classificação: Maior de idade.
Situação do voto: Voto obrigatório.
Digite seu peso (kg): 70
Digite sua altura (m, ex: 1.75): 1.75
Seu IMC: 22.86
```

### Módulo Financeiro

```text
--- MÓDULO FINANCEIRO ---
Digite seu salário (mensal): R$2000
Recebimento em 12 meses: R$ 24000.00
Digite quantos dias trabalhou: 10
Digite o valor da diária: R$150
Salário do período: R$ 1500.00
Digite um valor em reais para converter: R$100
Em dólares (taxa fixa): $ 20.00
Em euros  (taxa fixa): € 18.18
```

### Módulo Acadêmico

```text
--- MÓDULO ACADÊMICO ---
Digite a nota 1: 7
Digite a nota 2: 8
Digite a nota 3: 6
Soma: 21.00
Média: 7.00
Dobro da média: 14.00
Resultado: Aprovado
```

### Módulo Utilidades

```text
--- MÓDULO UTILIDADES ---
1) Par/Ímpar
2) Verificar intervalo [10,50]
3) Área/Perímetro (círculo/retângulo)
4) Converter segundos em h/m
Escolha: 1
Digite um número inteiro: 12
12 é par.
```

---

## Observações

* Este código é apenas um exercício acadêmico. Não implementa segurança real para senhas ou dados do usuário.
* Foi desenvolvido de forma didática, com validações básicas e foco em lógica de programação.
* Sugestões de melhorias incluem: interface gráfica, armazenamento persistente e integração com valores de câmbio em tempo real.
