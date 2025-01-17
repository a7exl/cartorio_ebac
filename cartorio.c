#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��es de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // bilbioteca respons�vel pelas strings

int registro() ////implementa��o da fun��o de cadastro
{
	//inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/strings
	
	printf("Informe o CPF a ser registrado: "); //coletando dados do usu�rio
	scanf("%s",cpf); //armazenando os dados na string %s
	
	strcpy(arquivo,cpf); //copia os valores das strings
	
	FILE *file; //cria/acessa o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo na pasta onde o sistema foi criado
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //adiciona informa��o ao arquivo j� criado
	fprintf(file,", ");//salva a informa��o no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Informe o seu primeiro nome: ");// msg para o usu�rio
	scanf("%s",nome);//armazena o dado na string
	
	file = fopen(arquivo, "a");//abre e adiciona informa��o ao arquivo j� criado
	fprintf(file,nome);//salva a informa��o no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre e adiciona informa��o ao arquivo j� criado
	fprintf(file," ");//salva a informa��o no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Informe o seu sobrenome: ");//msg para o usu�rio
	scanf("%s",sobrenome);//armazena o dado na string
	
	file = fopen(arquivo, "a");//abre e adiciona informa��o ao arquivo j� criado
	fprintf(file,sobrenome);//salva a informa��o no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre e adiciona informa��o ao arquivo j� criado
	fprintf(file,", ");//salva a informa��o no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Informe o seu cargo: ");//msg para o usu�rio
	scanf("%s",cargo);//armazena o dado na string
	
	file = fopen(arquivo, "a");//abre e adiciona informa��o ao arquivo j� criado
	fprintf(file,cargo);//salva a informa��o no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre e adiciona informa��o ao arquivo j� criado
	fprintf(file,".");//salva a informa��o no arquivo
	fclose(file);//fecha o arquivo
}

int consulta() //implementa��o da fun��o consulta
{
	setlocale(LC_ALL, "Portuguese");//define o idioma
	
	//incio das strings
	char cpf[40];
	char conteudo[200];
	//final das strings
	
	printf ("Digite o CPF a ser consultado: ");//msg para o usu�rio
	scanf("%s",cpf);//armazena o dado na string
	
	FILE *file;//cria/acessa o arquivo
	file = fopen(cpf,"r");//l� o arquivo
	
	if(file == NULL)//condi��o
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");//msg para o usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL)//condi��o
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");//msg para o usu�rio
	}
}

int deletar()//implementa��o da fun��o deletar
{
	//incio das strings
	char cpf[40];
	char conteudo[200];
	//fim das strings
		
	printf("Informe o CPF do usu�rio a ser deletado: ");//msg ao usu�rio
	scanf("%s",cpf);//armazena o dado na string
	
	remove(cpf);//fun��o nativa da biblioteca
	FILE*file; 
	file = fopen(cpf,"r");//abre e l� o arquivo
	
	if (file == NULL)//condi��o
		{
			printf("O CPF do usu�rio foi deletado com sucesso!\n");//msg ao usu�rio
		}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //defini��o de vari�vel
	int laco=1; //define o la�o repeti��o
	char senhadigitada[40];
	const char senhaCorreta[] = "admin";	
	
	printf("Cart�rio EBAC | Login Administrador\n\n");
	printf("Informe a sua senha: ");
	scanf("%s", senhadigitada);
		
		
	if(strcmp(senhadigitada, senhaCorreta) == 0)
	{ do
		{
			system("cls");//limpar dados da tela				
			printf("***** Bem-vindo ao Cart�rio da EBAC! *****\n\n"); //in�cio do menu
			printf("Escolha a op��o desejada no menu:\n\n");
			printf("\t1. Registrar nomes\n");
			printf("\t2. Consultar nomes\n");
			printf("\t3. Remover nomes\n");
			printf("\t4. Encerrar\n\n");
			printf("Op��o desejada: "); //fim do menu
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
			
			system("cls");//limpar dados da tela
		
			switch(opcao)//inicio da sele��o
			{ 
				case 1:
					registro();//execu��o da fun��o
					break;//fim do la�o de repeti��o
					
				case 2:  
					consulta();//execu��o da fun��o
					break;//fim do la�o de repeti��o		
					
				case 3:
					deletar();//execu��o da fun��o
					break; //fim do la�o de repeti��o
					
				case 4:
					printf("Obrigado por o usar o nosso sistema. At� logo!");
					return 0;
					break;//fim da sele��o
					
				default:
					printf("Essa op��o est� indispon�vel!\n");
					system("pause"); //msg pausada at� intera��o do usu�rio
					break;//fim do la�o de repeti��o
			}
			system("pause");
			
		}
		while (opcao != 4);
	}
	
	else
	{
		printf("Senha incorreta! Verifique e tente novamente.");
	}
		
}


