#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocações de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // bilbioteca responsável pelas strings

int registro() ////implementação da função de cadastro
{
	//inicio da criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/strings
	
	printf("Informe o CPF a ser registrado: "); //coletando dados do usuário
	scanf("%s",cpf); //armazenando os dados na string %s
	
	strcpy(arquivo,cpf); //copia os valores das strings
	
	FILE *file; //cria/acessa o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo na pasta onde o sistema foi criado
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //adiciona informação ao arquivo já criado
	fprintf(file,", ");//salva a informação no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Informe o seu primeiro nome: ");// msg para o usuário
	scanf("%s",nome);//armazena o dado na string
	
	file = fopen(arquivo, "a");//abre e adiciona informação ao arquivo já criado
	fprintf(file,nome);//salva a informação no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre e adiciona informação ao arquivo já criado
	fprintf(file," ");//salva a informação no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Informe o seu sobrenome: ");//msg para o usuário
	scanf("%s",sobrenome);//armazena o dado na string
	
	file = fopen(arquivo, "a");//abre e adiciona informação ao arquivo já criado
	fprintf(file,sobrenome);//salva a informação no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre e adiciona informação ao arquivo já criado
	fprintf(file,", ");//salva a informação no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Informe o seu cargo: ");//msg para o usuário
	scanf("%s",cargo);//armazena o dado na string
	
	file = fopen(arquivo, "a");//abre e adiciona informação ao arquivo já criado
	fprintf(file,cargo);//salva a informação no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre e adiciona informação ao arquivo já criado
	fprintf(file,".");//salva a informação no arquivo
	fclose(file);//fecha o arquivo
	
	system("pause");//msg pausada até interação do usuário
}

int consulta() //implementação da função consulta
{
	setlocale(LC_ALL, "Portuguese");//define o idioma
	
	//incio das strings
	char cpf[40];
	char conteudo[200];
	//final das strings
	
	printf ("Digite o CPF a ser consultado: ");//msg para o usuário
	scanf("%s",cpf);//armazena o dado na string
	
	FILE *file;//cria/acessa o arquivo
	file = fopen(cpf,"r");//lê o arquivo
	
	if(file == NULL)//condição
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");//msg para o usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)//condição
	{
		printf("\nEssas são as informações do usuário: ");//retorno do dado consultado
		printf("%s",conteudo);
		printf("\n\n");//msg para o usuário
	}
	
	system("pause"); //msg pausada até interação do usuário
}

int deletar()//implementação da função deletar
{
	//incio das strings
	char cpf[40];
	char conteudo[200];
	//fim das strings
		
	printf("Informe o CPF do usuário a ser deletado: ");//msg ao usuário
	scanf("%s",cpf);//armazena o dado na string
	
	remove(cpf);//função nativa da biblioteca
	FILE*file; 
	file = fopen(cpf,"r");//abre e lê o arquivo
	
	if (file == NULL)//condição
		{
			printf("O CPF do usuário foi deletado com sucesso!\n");//msg ao usuário
		}
		
	system("pause");//msg pausada até interação do usuário
}

int main()
{
	int opcao=0; //definição de variável
	int laco=1; //define o laço repetição
	
	for(laco=1;laco=1;)
	{
		system("cls");//limpar dados da tela
			
		setlocale(LC_ALL, "Portuguese"); //definição de idioma
	
		printf("***** Bem-vindo ao Cartório da EBAC! *****\n\n"); //início do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1. Registrar nomes\n");
		printf("\t2. Consultar nomes\n");
		printf("\t3. Remover nomes\n\n");
		printf("Opção desejada: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");//limpar dados da tela
		
		switch(opcao) //inicio da seleção
		{
			case 1:
			registro();//execução da função
			break;//fim do laço de repetição
			
			case 2:  
			consulta();//execução da função
			break;//fim do laço de repetição		
			
			case 3:
			deletar();//execução da função
			break; //fim do laço de repetição
			
			//fim da seleção
			
			default:
			printf("Essa opção está indisponível!\n");//msg ao usuário
			system("pause"); //msg pausada até interação do usuário
			break;//fim do laço de repetição
		}
	}
}


