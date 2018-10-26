/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Ramon Griffo Costa
Matricula: 201622040112
Descricao do programa: Algoritmo guloso para resolver o problema da mochila usando ordenação por custo benefício
Data: 14/09/2017
************************************************/

#include<stdio.h>
#include<time.h>

void ordena(float cb[], int p[], int v[], int n[], int q) { 	//algoritmo de ordenação por seleção
	int i, j, min, aux; float faux;
	for (i = 0; i < (q-1); i++){
		min = i;
		for (j = (i+1); j < q; j++) {							//esse algoritmo ordena os itens e seus dados em ordem crescente de valor/peso, o número dos itens também é armazenado
			if(cb[j] < cb[min])
				min = j;
		}
		if (cb[i] != cb[min]) {
			faux = cb[i];
			cb[i] = cb[min];
			cb[min] = faux;
			aux = v[i];
			v[i] = v[min];
			v[min] = aux;
			aux = p[i];
			p[i] = p[min];
			p[min] = aux;
			aux = n[i];
			n[i] = n[min];
			n[min] = aux;
		}
	}
}

int main(){
	clock_t tempos[4];		 									//variáveis usadas para armazenar e medir o tempo gasto
	tempos[0] = clock();										//armazenando tempo inicial
	FILE *arqin, *arqout;//, *arqaux; 							//arquivos a serem manipulados
	arqin = fopen("In.txt", "rt");
    if (arqin == NULL){
    		printf("Problemas na CRIACAO do arquivo\n");
    		return -1;
    }
	int tMochila, qProdutos;
	fscanf(arqin, "%d", &tMochila);
	fscanf(arqin, "%d", &qProdutos);							//armazenando quantidade de itens
	int peso[qProdutos], valor[qProdutos], nItem[qProdutos];	//vetores para armazenar os dados de cada produto i
	float cb[qProdutos];										//vetor onde serão salvos as razões entre o valor e o peso de cada produto i
	int i;														//iterador
	for(i=0; i<qProdutos; i++){									//esse for armazena em cada posição dos vetores peso, valor e cb os valores dos pesos, valores e valor/peso de cada item i
		fscanf(arqin, "%d", &peso[i]);
		fscanf(arqin, "%d", &valor[i]);
		cb[i] = (float)valor[i]/(float)peso[i];
		nItem[i] = i+1;
	}
	fclose(arqin);												//fecha o arquivo de entrada
	tempos[1] = clock();										//armazena o tempo gasto até esse instante
	ordena(cb, peso, valor, nItem, qProdutos);					//executa o algoritmo de ordenação por seleção para deixar os itens separados por ordem crescente de valor/peso
	tempos[2] = clock();										//armazena o tempo gasto até esse instante
	arqout = fopen("Out.txt", "w");								//arquivo onde será armazenada a saída
	//arqaux = fopen("AuxOut.txt", "w");						//arquivo aux de saída onde são colocados os itens e seus valores em ordem crescente de valor/peso, somente para fins de análise

	/*for(i=0; i<qProdutos; i++){								//esse for coloca os itens na saída auxiliar em ordem crescente de valor/peso
		fprintf(arqaux, "Peso item %d:    %d\nPreço item %d:    %d\nCusto/Beneficio item %d:    %.2f\n\n", nItem[i], peso[i], nItem[i], valor[i], nItem[i], cb[i]);
	}*/

	fprintf(arqout, "Capacidade da mochila: %d\nQuantidade de produtos disponíveis: %d\n\nItens colocados na mochila:\n\n", tMochila, qProdutos);
	int pesoTotal, valorTotal;									//variáveis para armazenar o peso e o valor total do que foi colocado na mochila
	for(i=qProdutos-1, pesoTotal=0;i>=0; i--){					//esse for salva os itens com maior valor/peso até estourar o limite da mochila, quando estoura ele para e o resultado está dado
     	pesoTotal+=peso[i];
		valorTotal+=valor[i];
		if(pesoTotal<=tMochila){
			fprintf(arqout, "Peso item %d:    %d\nPreço item %d:    %d\n\n", nItem[i], peso[i], nItem[i], valor[i]);
		}
			else{
			pesoTotal-=peso[i];
			valorTotal-=valor[i];
		}
	}
	fprintf(arqout, "Peso total colocado na mochila: %d\nValor total arrecadado: %d\n", pesoTotal, valorTotal); //salva no arquivo o peso total e o valor total do que foi colocado na mochila
	fclose(arqout);//fclose(arqaux);							//fecha os arquivos de saída
	tempos[3] = clock();										//armazena o tempo gasto até esse instante (final)
	double Tempo12 = (tempos[1] - tempos[0]) * 1000.0 / CLOCKS_PER_SEC;		//calcula os tempos gastos em milissegundos
	double Tempo23 = (tempos[2] - tempos[1]) * 1000.0 / CLOCKS_PER_SEC;
	double Tempo34 = (tempos[3] - tempos[2]) * 1000.0 / CLOCKS_PER_SEC;
	double Tempo14 = (tempos[3] - tempos[0]) * 1000.0 / CLOCKS_PER_SEC;
	double Tempo13 = (tempos[2] - tempos[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo de leitura de arquivos e calculo do custo benefício: %g ms.\nTempo de ordenação dos produtos: %g ms.\nTempo de escrita de arquivos: %g ms.\nTempo total: %g ms.\nTempo total sem escrita de arquivos: %g ms.\n", Tempo12, Tempo23, Tempo34, Tempo14, Tempo13);												//printa tempo total gasto
	return 0;
}
