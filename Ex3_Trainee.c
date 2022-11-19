/*O Banco Central de Financiamentos perdeu muitos cadastros ap?s uma falha de
servidor que aconteceu em setembro, no anivers?rio da empresa. Alguns dados do
ano passado foram encontrados e voc? foi escolhido para:
- Selecionar o nome, dia do m?s e valor da parcela para clientes que est?o
inadimplentes.
- Selecionar o nome e valor total pago de clientes com pagamento completo.
*/
#include <stdio.h>
#include <stdlib.h>
#define tam 4
struct{
	int ID_pess;
	char nome[100];
	char inadim;
	int contrato_id;
	int ano_pag_completo;
	int mes_pag_completo;
	int data_pag_completo;
}pessoas[tam];

struct{
	int ID_contr;
	int valor_parce;
	int parcelas;
}contratos[tam];

struct{
	int ID_paga;
	int ID_pess;
	int ano_pag;
	int mes_pag;
	int data_pag;
}pagamentos[tam];
void preenchendo(void);
int main(){
	int i,j;
	preenchendo();
	printf("Insira os dados de cada pessoa:\n");
	for(i=0;i<tam;i++){
		pessoas[i].ID_pess = i+1;
		printf("1-Seu nome: ");
		scanf("%[^\n]",pessoas[i].nome);
		printf("2-ID do contrato: ");
		scanf("%d",&pessoas[i].contrato_id);
		getchar();
		printf("3-Cliente Inadimplente?(S ou N): ");
		scanf("%c",&pessoas[i].inadim);	
		if(pessoas[i].inadim=='N'){
			printf("4-Ano-Mes-Dia da conclusao do pagamento:\n");
			scanf("%d-%d-%d",&pessoas[i].ano_pag_completo,&pessoas[i].mes_pag_completo,&pessoas[i].data_pag_completo);
		}
		getchar();
	}
	printf("--------------------------------------------------------------------------------------\n");
	
	printf("Clientes Inadimplentes:");
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			if(pessoas[i].contrato_id==contratos[j].ID_contr)
				if(pessoas[i].inadim=='S')
					printf("Nome: %s\nDia/Mes de pagamento: %d\nValor da Parcela: %d\n",pessoas[i].nome,pagamentos[i].data_pag,contratos[j].valor_parce);		
			}
		}
	printf("\nClientes com pagamento completo:\n");
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			if(pessoas[i].contrato_id==contratos[j].ID_contr)
				if(pessoas[i].inadim=='N')
					printf("\nNome: %s\nValor Total: %d\n",pessoas[i].nome,(contratos[j].valor_parce*contratos[j].parcelas));
			}
		}
}



void preenchendo(void){
	int i;
	//preenchendo a tabela de contratos
	for(i=0;i<tam;i++){
		contratos[i].ID_contr = i+1;
		pagamentos[i].ID_paga = i+1;
		pagamentos[i].ano_pag = 2021;
		pagamentos[i].mes_pag = 9;
	}
	//preenchimento do valor de cada parcela
	contratos[0].valor_parce=150;
	contratos[1].valor_parce=300;
	contratos[2].valor_parce=550;
	contratos[3].valor_parce=1000;
	//preenchimento da quantidade de cada parcelas
	contratos[0].parcelas=100;
	contratos[1].parcelas=48;
	contratos[2].parcelas=24;
	contratos[3].parcelas=12;
	//preenchendo a tabela de pagamentos
	pagamentos[0].ID_pess=4;
	pagamentos[1].ID_pess=3;
	pagamentos[2].ID_pess=1;
	pagamentos[3].ID_pess=2;
	//preenchimento da data dos pagamentos dos clientes
	pagamentos[0].data_pag= 1;
	pagamentos[1].data_pag= 5;
	pagamentos[2].data_pag= 19;
	pagamentos[3].data_pag= 25;
}

