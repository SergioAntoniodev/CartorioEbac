#include <stdio.h> //biblioteca de comunica��o com usuario
#include <stdlib.h> //biblioteca de aloca��o em espa�o de memoria
#include <locale.h> // biblioteca de aloca�ao de texto por regiao
#include <string.h> // biblioteca respons�vel por cuidar das strings


int registro()
{
	
	char arquivo[40];
	char CPF[40];
	char NOME[40];
	char SOBRENOME[40];
	char CARGO[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",CPF); //%s salvar a string
	
	strcpy(arquivo,CPF); //respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); // cria o arquivo e "w"(escrever)
	fprintf(file,CPF); // salva o valor da variavel
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"/");
	fclose(file);
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s",NOME);
	
	file = fopen(arquivo,"a");
	fprintf(file,NOME);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"/");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s,",SOBRENOME);
	
	file = fopen(arquivo,"a");
	fprintf(file,SOBRENOME);
	fclose(file);
		
	file = fopen(arquivo,"a");
	fprintf(file,"/");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s,",CARGO);
	
	file = fopen(arquivo,"a");
	fprintf(file,CARGO);
	fclose(file);
	
	system("pause");
		
	
	
}

int consulta()
{
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s,", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF n�o localizado!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("O usu�rio foi deletado com sucesso!\n");
		system("pause");
	}
}


int main()
    {
	
    setlocale(LC_ALL, "portuguese");
	
	 
    int opcao = 0;
    char senha[10];
    char confirmasenha[10];
    int tentativas = 3; // N�mero m�ximo de tentativas

    printf("### Cart�rio da EBAC ### \n\n");
    
        while (tentativas > 0) {
        printf("Login de Administrador\n\nDigite sua senha: ");
        scanf("%s", senha);
        
        // Verifica se a senha est� correta
        if (strcmp(senha, "admin") == 0) 
		{
            printf("Digite novamente a senha para confirmar: ");
            scanf("%s", confirmasenha);
            
            if (strcmp(senha, confirmasenha) == 0) {
                printf("\nAcesso concedido!\n");
                break;
            } else {
                printf("\nAs senhas n�o correspondem. Tente novamente.\n\n");
            }
        } else {
            printf("\nSenha incorreta. Tente novamente.\n\n");
        }
        
        tentativas--;
        
        if (tentativas == 0) {
            printf("Voc� excedeu o n�mero m�ximo de tentativas. Encerrando o programa.\n");
            return 0;
        }
    }
    
	{
	
	    system("cls");
	
	    setlocale(LC_ALL, "portuguese"); //Defini�ao de linguagem
	
	    printf("### Cart�rio da EBAC ### \n\n"); // Inicio do menu
	    printf("Escolha a op��o desejada no menu: \n\n");
        printf("\t1 - Registrar nomes\n");
     	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Op��o: "); // Final do menu
	
	
	    scanf("%d", &opcao); // Armazenando escolha do usu�rio
	
	    system("cls"); // respons�vel por limpar a tela 
	
	    switch(opcao)
	    {
	    	case 1:
	        registro(); // chamada de fun��o
	        break;
	        
	        case 2:
	        consulta();
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        case 4:
	        printf("Obrigado por utilizar o sistema.\n");
	        return 0;
	        break;
	        	
	        default:
	        printf("Op��o n�o disponivel!\n");
	        system("pause");
		    break;
	    		
		}
   
      }
      
    }
      
      
    

   


