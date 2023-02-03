#include <stdio.h> // biblioteca de comunicação com o usuário 
#include <stdlib.h> // biblioteca de alocação de espaço em memória 
#include <locale.h> // biblioteca de alocações de texto por região 
#include <string.h> // biblioteca responsável por cuidar dos string



int registro ()  // Início da seleção
{
	int opcao = 0;                // Definindo variável opção   
	
	setlocale(LC_ALL,"Portuguese"); // Definindo linguagem 
	
	printf("\n\n");
	printf("Digite 1 para registro de funcionários\n");
	printf("Digite 2 para registro de alunos\n\n");
	
	printf("Opção: ");
	scanf("%d", &opcao);           // Guardando a opção desejada 
	
	system("cls");

	
		switch(opcao)     // Escolha das opções registro de funcionário e aluno       
    	{ 
    	   case 1:    // Início da seleção registro de funcionário 
    	   { 
            char arquivo [40];    // Definindo variáveis 
            char cpf [40];
            char nome [40];
            char sobrenome [40];
            char cargo [40];
 
            printf("\tVocê escolheu a opção registro de funcionário!\n\n");
 
            printf("Digite seu CPF para cadastro: ");
            scanf( "%s", cpf);
 
            strcpy(arquivo, cpf);   // responsãvel por igualar o arquivo ao cpf 

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
            fprintf(file,nome);    // Adicionando a variável no arquivo
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
            
            system("cls");    // limpar informações 
            
            printf("\n");
            printf("\tUsuário cadastrado com sucesso!\n\n");
   
            system("pause");   
    	    break;          // fim da seleção 
    	   
    	   case 2:
    	   
            printf("\tVocê escolheu a opção registro de aluno!\n\n"); // Início da seleção registro de aluno 
 
            printf("Digite seu CPF para cadastro: ");
            scanf( "%s", cpf);
 
            strcpy(arquivo, cpf); // responsãvel por igualar o arquivo ao cpf 

             
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
            printf("\tUsuário cadastrado com sucesso!\n\n");
            system("pause");
    	    break; 
    	    
    	    default :
    	    printf("\tEsta opção não existe\n\n"); 
    	    system("pause");
    	    break;                 // final da seleção de registro de aluno 
    	
    	    }
        }
	} // Início da seleção


int consulta()    // Início da seleção
{
    setlocale(LC_ALL,"Portuguese"); // Definindo linguagem  
    char cpf[40];
    char conteudo [200];

    printf("\tVocê escolheu a opção consultar nomes\n\n");
    printf ("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    system("cls");

    FILE *file;
    file = fopen(cpf,"r");

       if(file == NULL)     // Caso não achar o cpf inserido
       {
  	     int opcao = 0;
    
         printf("\tCPF não cadastrado, gostaria de cadastrar?\n\n");
         printf("Opção 1 sim \n");
	     printf("Opção 2 não \n\n");
	     printf("Opção: ");
	     scanf("%d", &opcao);
	
	     system("cls");
	
	     switch(opcao)  //        
       	{ 
    	     case 1: registro();      // Caso deseje cadastrar voltar em registro
    	     system("pause");
    	     break;
    	   
    	     case 2:                  // Caso não deseje cadastrar voltar em menu
    	     break;
    	   
        	  default :
    	     printf("\tEsta opção não existe\n\n");  // Caso não existir a opção inserida 
    	     system("pause");
    	     break; 
    	   
        }
    }
         while(fgets(conteudo,200,file) !=NULL)   // Caso achar o cpf onserido 
    { 

         printf ("\tEssas são as informações do usuário: \n\n");  
         printf ("%s", conteudo);                     // Mostrando as informações para o usuário 
         printf ("\n\n");

    }
    fclose(file);         // fechar o arquivo
    system("pause");	  // final da seleção
}

int deletar ()    // Início da seleção
{ 

    char cpf[40];               // definindo variáveis 
    int opcao = 0;
    
    printf("\tVocê escolheu a opção deletar nomes\n\n");
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
   	system("cls");   // limpar informações 

	printf("\t Deseja deletar este cpf?\n\n");   // confirmação do cpf 
	printf("CPF: %s \n\n", cpf);
	
	printf("Opção 1 sim\n");
	printf("Opção 2 não\n");
	
    printf("Opção: ");
	scanf("%d", &opcao); // Armazenando opção 
	system("cls");
	
		switch(opcao)  // Escolha das opções       
    	{ 
    	   case 1:                        
    	   remove(cpf);      // Remover o cpf
    	   
    	   FILE* file;
    	   file = fopen(cpf,"r");     // Abrir e ler o arquivo 
    	   
    	   if(file == NULL)    // Caso não achar o arquivo 
    	     { 
    	     printf("\tO usuário deletado do sistema com sucesso!\n\n"); 
    	     system("pause");  
    	     }
    	   break;
           
           default :
    	   printf("\tEsta opção não existe\n\n"); 
    	   system("pause");
    	   break; 
		  }   
}  // Final da seleção 


int main() 
{
	int opcao = 0; // Definindo variáveis 
	int laco=1;
	
	for(laco=1;laco=1;) // Definindo rapetição
	{
		system("cls");   // Limpar as informações 
	
	   setlocale(LC_ALL,"Portuguese"); // Definindo linguagem 
	
     	printf("\tCartório da EBAC\n\n"); // Início do  menu
    	printf("Escolha a opção desejada no menu:\n\n ");
	    printf("- Digite 1 para registrar nomes\n ");
    	printf("- Digite 2 para consultar nomes\n ");
    	printf("- Digite 3 para deletar nomes \n\n\n"); 
    	printf("Opção:"); // Fim do menu
	
    	scanf("%d", &opcao); // Armazenando a escolha do usuário 
	
    	system("cls");   // Limpar as informações
    	
    	switch(opcao)  // Escolha das opções       
    	{ 
    	   case 1:                        // Início da seleção
    	   registro ();
    	   break;
    	   
    	   case 2:
    	   consulta ();
    	   break;
    	   
    	   case 3:
    	   deletar ();
    	   break;
    	   
    	   default :
    	   printf("\tEsta opção não existe\n"); 
    	   system("pause");
    	   break;                         // Fim da seleção
    	   
        }
	}
}
	
