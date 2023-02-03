#include <stdio.h> // biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> // biblioteca de aloca��es de texto por regi�o 
#include <string.h> // biblioteca respons�vel por cuidar dos string



int registro ()  // In�cio da sele��o
{
	int opcao = 0;                // Definindo vari�vel op��o   
	
	setlocale(LC_ALL,"Portuguese"); // Definindo linguagem 
	
	printf("\n\n");
	printf("Digite 1 para registro de funcion�rios\n");
	printf("Digite 2 para registro de alunos\n\n");
	
	printf("Op��o: ");
	scanf("%d", &opcao);           // Guardando a op��o desejada 
	
	system("cls");

	
		switch(opcao)     // Escolha das op��es registro de funcion�rio e aluno       
    	{ 
    	   case 1:    // In�cio da sele��o registro de funcion�rio 
    	   { 
            char arquivo [40];    // Definindo vari�veis 
            char cpf [40];
            char nome [40];
            char sobrenome [40];
            char cargo [40];
 
            printf("\tVoc� escolheu a op��o registro de funcion�rio!\n\n");
 
            printf("Digite seu CPF para cadastro: ");
            scanf( "%s", cpf);
 
            strcpy(arquivo, cpf);   // respons�vel por igualar o arquivo ao cpf 

            FILE *file;  //criando o arquivo 
            file = fopen(arquivo, "w");
            fprintf(file,cpf);  // salvo o valor do cpf  
            fclose(file);  // fechar o arquivo 
 
            file= fopen(arquivo, "a");   // Abrindo arquivo e atualizando 
            fprintf (file,", ");  // Adicionando "," no arquivo
            fclose (file);    // fechando o arquivo 
 
            printf("Digite o nome a ser cadastrado: ");
            scanf("%s", nome);

            file = fopen(arquivo, "a");  
            fprintf(file,nome);    // Adicionando a vari�vel no arquivo
            fclose(file);
 
            file = fopen(arquivo, "a");
            fprintf(file,", ");
            fclose (file);
 
            printf("Digite o sobrenome a ser cadastrado: ");
            scanf("%s", sobrenome);

            file = fopen(arquivo, "a");
            fprintf (file, sobrenome);
            fclose (file);
 
            file= fopen(arquivo, "a");
            fprintf(file,", ");
            fclose (file);
 
            printf("Digite o cargo a ser cadastrado: ");
            scanf("%s", cargo);
 
            file = fopen(arquivo, "a");
            fprintf(file, cargo);
            fclose(file);
            
            system("cls");    // limpar informa��es 
            
            printf("\n");
            printf("\tUsu�rio cadastrado com sucesso!\n\n");
   
            system("pause");   
    	    break;          // fim da sele��o 
    	   
    	   case 2:
    	   
            printf("\tVoc� escolheu a op��o registro de aluno!\n\n"); // In�cio da sele��o registro de aluno 
 
            printf("Digite seu CPF para cadastro: ");
            scanf( "%s", cpf);
 
            strcpy(arquivo, cpf); // respons�vel por igualar o arquivo ao cpf 

             
            file = fopen(arquivo, "w");
            fprintf(file,cpf);  
            fclose(file);  
 
            file= fopen(arquivo, "a");
            fprintf (file,", ");
            fclose (file);
 
            printf("Digite o nome a ser cadastrado: ");
            scanf("%s", nome);

            file = fopen(arquivo, "a");
            fprintf(file,nome);
            fclose(file);
 
            file = fopen(arquivo, "a");
            fprintf(file,", ");
            fclose (file);
 
            printf("Digite o sobrenome a ser cadastrado: ");
            scanf("%s", sobrenome);

            file = fopen(arquivo, "a");
            fprintf (file, sobrenome);
            fclose (file);
            system("pause");

    	    system("cls");
            
            printf("\n");
            printf("\tUsu�rio cadastrado com sucesso!\n\n");
            system("pause");
    	    break; 
    	    
    	    default :
    	    printf("\tEsta op��o n�o existe\n\n"); 
    	    system("pause");
    	    break;                 // final da sele��o de registro de aluno 
    	
    	    }
        }
	} // In�cio da sele��o


int consulta()    // In�cio da sele��o
{
    setlocale(LC_ALL,"Portuguese"); // Definindo linguagem  
    char cpf[40];
    char conteudo [200];

    printf("\tVoc� escolheu a op��o consultar nomes\n\n");
    printf ("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    system("cls");

    FILE *file;
    file = fopen(cpf,"r");

       if(file == NULL)     // Caso n�o achar o cpf inserido
       {
  	     int opcao = 0;
    
         printf("\tCPF n�o cadastrado, gostaria de cadastrar?\n\n");
         printf("Op��o 1 sim \n");
	     printf("Op��o 2 n�o \n\n");
	     printf("Op��o: ");
	     scanf("%d", &opcao);
	
	     system("cls");
	
	     switch(opcao)  //        
       	{ 
    	     case 1: registro();      // Caso deseje cadastrar voltar em registro
    	     system("pause");
    	     break;
    	   
    	     case 2:                  // Caso n�o deseje cadastrar voltar em menu
    	     break;
    	   
        	  default :
    	     printf("\tEsta op��o n�o existe\n\n");  // Caso n�o existir a op��o inserida 
    	     system("pause");
    	     break; 
    	   
        }
    }
         while(fgets(conteudo,200,file) !=NULL)   // Caso achar o cpf onserido 
    { 

         printf ("\tEssas s�o as informa��es do usu�rio: \n\n");  
         printf ("%s", conteudo);                     // Mostrando as informa��es para o usu�rio 
         printf ("\n\n");

    }
    fclose(file);         // fechar o arquivo
    system("pause");	  // final da sele��o
}

int deletar ()    // In�cio da sele��o
{ 

    char cpf[40];               // definindo vari�veis 
    int opcao = 0;
    
    printf("\tVoc� escolheu a op��o deletar nomes\n\n");
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
   	system("cls");   // limpar informa��es 

	printf("\t Deseja deletar este cpf?\n\n");   // confirma��o do cpf 
	printf("CPF: %s \n\n", cpf);
	
	printf("Op��o 1 sim\n");
	printf("Op��o 2 n�o\n");
	
    printf("Op��o: ");
	scanf("%d", &opcao); // Armazenando op��o 
	system("cls");
	
		switch(opcao)  // Escolha das op��es       
    	{ 
    	   case 1:                        
    	   remove(cpf);      // Remover o cpf
    	   
    	   FILE* file;
    	   file = fopen(cpf,"r");     // Abrir e ler o arquivo 
    	   
    	   if(file == NULL)    // Caso n�o achar o arquivo 
    	     { 
    	     printf("\tO usu�rio deletado do sistema com sucesso!\n\n"); 
    	     system("pause");  
    	     }
    	   break;
           
           default :
    	   printf("\tEsta op��o n�o existe\n\n"); 
    	   system("pause");
    	   break; 
		  }   
}  // Final da sele��o 


int main() 
{
	int opcao = 0; // Definindo vari�veis 
	int laco=1;
	
	for(laco=1;laco=1;) // Definindo rapeti��o
	{
		system("cls");   // Limpar as informa��es 
	
	   setlocale(LC_ALL,"Portuguese"); // Definindo linguagem 
	
     	printf("\tCart�rio da EBAC\n\n"); // In�cio do  menu
    	printf("Escolha a op��o desejada no menu:\n\n ");
	    printf("- Digite 1 para registrar nomes\n ");
    	printf("- Digite 2 para consultar nomes\n ");
    	printf("- Digite 3 para deletar nomes \n\n\n"); 
    	printf("Op��o:"); // Fim do menu
	
    	scanf("%d", &opcao); // Armazenando a escolha do usu�rio 
	
    	system("cls");   // Limpar as informa��es
    	
    	switch(opcao)  // Escolha das op��es       
    	{ 
    	   case 1:                        // In�cio da sele��o
    	   registro ();
    	   break;
    	   
    	   case 2:
    	   consulta ();
    	   break;
    	   
    	   case 3:
    	   deletar ();
    	   break;
    	   
    	   default :
    	   printf("\tEsta op��o n�o existe\n"); 
    	   system("pause");
    	   break;                         // Fim da sele��o
    	   
        }
	}
}
	
