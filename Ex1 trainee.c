/*Considere a posi��o inicial do rob� como as coordenadas 0,0 de um plano
cartesiano, e que ele inicialmente est� olhando para o norte. O rob� n�o pode
atravessar paredes, ent�o as coordenadas do rob� devem ser sempre maiores ou
iguais a zero, e a posi��o X do rob� deve ser sempre menor que a largura da sala, e
a posi��o Y sempre menor que o comprimento.

Entrada: A entrada cont�m v�rios casos de teste, sendo cada um especificado por
um par de linhas. A primeira linha � composta por dois n�meros separados por um
espa�o, indicando a largura e comprimento do ambiente, e a segunda cont�m uma
sequ�ncia composta pelos caracteres F (indicando um passo para a frente), T
(indicando um passo para tr�s), E (indicando uma rota��o 90� � esquerda sem se
deslocar) e D (indicando uma rota��o de 90� para a direita sem se deslocar).

Sa�da: Para cada caso de teste da entrada o programa dever� devolver uma linha
correspondente, indicando a orienta��o final do rob� (N para norte, S para sul, O
para oeste e L para leste) e as coordenadas X e Y.*/

#include <stdio.h>
#include <stdlib.h>





//n=1,l=2,o=3,s=4

int main(){
	int x=0,y=0,largu,comprim,rodando=1,regula=1;
	char letra_pos, dir;
	
	while(rodando){
		scanf("%d %d",&largu,&comprim);
		getchar();	
			letra_pos = getchar();
			while(letra_pos != '\n'){
				if(letra_pos == 'D')
					regula++;
					if(regula>4)
						regula=1;
				else
					if(letra_pos == 'E')
						regula--;
						if(regula<1)
							regula=4;
				if(regula==1){
					dir = 'N';
					if (letra_pos == 'F')
						y++;
					else
						if(letra_pos == 'T')
							y--;
					}
				if(regula==2){
					dir = 'L';
					if (letra_pos == 'F')
						x++;
					else
						if(letra_pos == 'T')
							x--;
					}
				if(regula==3){
					dir = 'S';
					if (letra_pos == 'F')
						y--;
					else
						if(letra_pos == 'T')
							y++;
					}
				if(regula==4){
					dir = 'O';
					if (letra_pos == 'F')
						x--;
					else
						if(letra_pos == 'T')
							x++;
						
					}
				letra_pos = getchar();
			}
			if(x<0)
				x=0;
			if(y<0)
				y=0;
			if(y>largu)
				y=largu;
			if(x>comprim)
				x=comprim;
			
		printf("%c %d %d\n",dir,x,y);
		x=0;
		y=0;
		regula=1;
	}
}









