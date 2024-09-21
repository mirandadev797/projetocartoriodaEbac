
#include <stdio.h> //biblioteca que printa a info pro usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o
#include <locale.h> //biblioteca de aloca��o de texto por l�ngua
#include <string.h> //biblioteca respons�vel por alocar as string


int registro()
{
	char arquivo [40]; //separa��o de quantidade de caracteres que ter�o dentro da string "arquivo"
	char cpf [40]; //separa��o de quantidade de caracteres que ter�o dentro da string "cpf"
	char nome [40]; //separa��o de quantidade de caracteres que ter�o dentro da string "nome"
	char sobrenome [40]; //separa��o de quantidade de caracteres que ter�o dentro da string "sobrenome"
	char cargo [40]; //separa��o de quantidade de caracteres que ter�o dentro da string "cargo"
	
	printf("Digite o CPF para cadastro: ");
	scanf ("%s", cpf); 
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings como valor principal para o arquivo
		
	FILE *file; //cria arquivo no caso, no computador
	file = fopen(arquivo, "w"); //cria o arquivo w= de whrite=escrever
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // a= de atualiza��o
	fprintf(file, ","); // "," usada como separador das vari�veis no banco de dados
	fclose(file); //fecha o arquivo
	
	printf ("Digite o NOME: ");
	scanf ("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf ("Digite o SOBRENOME: ");
	scanf ("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf ("Digite o CARGO: ");
	scanf ("%s", cargo);
	
	file = fopen (arquivo,"a");
	fprintf (file, cargo);
	fclose (file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	system("pause");
	
}

int consulta()

{
	setlocale(LC_ALL, "Portuguese"); //reconhece a l�ngua a ser usada
	
	char cpf [40];
	char conteudo [200];

	printf ("Digite o CPF para consulta: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file==NULL) //caso o cpf n�o exista no banco
	{	
		printf("CPF n�o localizado!\n");
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
		printf ("\nEssas s�o as informa��es do usu�rio:\n\n");
		printf ("\t%s\n",conteudo);
		printf ("\n\n");
	}
	
	system("pause");
	
	fclose(file);
	
}

	
int deletar()
{
	char cpf[40];
	printf ("Digite o CPF do usu�rio a ser deletado: ");
	
	scanf("%s", cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("CPF n�o encontrado.\n");
		system ("pause");
		return 0;
	}
	
	fclose(file);
	
	if (remove(cpf) ==0)
	{
		printf ("\nCPF deletado com sucesso!");
		printf ("\n\n");
	}
	
	system("pause");
	return 0;
}

int main ()
{
	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10];
	char correctsenhadigitada[]="admin";
	
	setlocale (LC_ALL, "Portuguese"); //Definindo a l�ngua
	printf("\t_____ CART�RIO DA EBAC_____\n\n");
	printf("Login de administrador\n\nDigite a sua senha:");
	int attempts = 0;
    int maxAttempts = 7;
	
	
    while (attempts < maxAttempts)
	{
		scanf("%s",senhadigitada);
        
		if (strcmp(senhadigitada, correctsenhadigitada) == 0 && strcmp(senhadigitada, correctsenhadigitada) == 0)
		{
			system("cls");
		
			for(laco=1; laco=1;)
			{
				system ("cls");
				setlocale (LC_ALL, "Portuguese"); //Definindo linguagem
				
				printf ("\t_____ CART�RIO DA EBAC_____\n\n"); //T�tulo
				printf ("Escolha a op��o desejada abaixo:\n\n");
				printf ("\t1. REGISTRAR nome \n"); //Op��es
				printf ("\t2. CONSULTAR nome \n"); //Op��es
				printf ("\t3. DELETAR nome \n"); //Op��es
				printf ("\t4. Sair do sistema \n\n"); //Op��es
				printf ("Digite sua op��o:\t"); 
				
				scanf ("%d" , &opcao); //loca��o de espa�o e espera para o usu�rio digitar a op��o desejada. Armazenamento da op��o do usu�rio
				
				system ("cls"); //Limpeza da tela
				
			
				switch (opcao)
				{
					case 1:
					registro();
					break;
				
					case 2:
					consulta();
					break;
					
					case 3:
					deletar();
					break;
				
					case 4:
					printf("Obrigado por utilizar o sistema!\n\n");
					return 0;
					break;
				
					default:
					printf("Essa op��o n�o est� dispon�vel.\n\n");
			
					system("pause");
					break;	
				}
	
			}

		}
					
		else
		{		
		printf("Senha Incorreta\n\nTente novamente\t\n\n");
		attempts++;
		system ("pause");
		system ("cls");
		printf("\t_____ CART�RIO DA EBAC_____\n\n");
		printf("Login de administrador\n\nDigite a sua senha:");
		
		}
		
		if (attempts == maxAttempts)
		{
        printf("\tN�mero de tentativas EXCEDIDO! O programa ser� fechado.\n");
        }
	}

    return 0;
    
printf("\t*Software desenvolvido por Marina Miran - Projeto 1 para EBAC.");	

}
	



