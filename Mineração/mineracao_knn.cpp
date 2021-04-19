#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <fstream> //para ler dataset
using namespace std;
struct criarInd{
	string estado;
	string grupoV;
	int populacaoGrupo;
	double taxa, taxaProx;
};
struct statusEstado{
	string nome, grupos;
};
struct grupo{
	int populcao;
	double taxaCont;
	int qtdLotes;
};
struct valOrdenacao{
	double distTaxa, taxaOrd, taxaFixaOrd, taxaProxOrd;
	string estadoTaxa, grupoTaxa;
};
struct estados{
	string nome;
	grupo grupo1;
	grupo grupo2;
	grupo grupo3;
	grupo grupo4;
	grupo grupo5;
	grupo grupo6;
	grupo grupo7;
	grupo grupo8;
	grupo grupo9;
	grupo grupo10;
	grupo grupo11;
	grupo grupo12;
	grupo grupo13;
	grupo grupo14;
	grupo grupo15;
	grupo grupo16;
	grupo grupo17;
	grupo grupo18;
};
class Individuo
{
public:
	string estado, gruposV;
	int qtdVacina, popGrupo;
	double taxa, taxaProx, taxaFixa;
public:

	Individuo(string estado, string gruposV, int qtdVacina, double taxa, double taxaProx, double taxaFixa, int popGrupo)
	{
		this->estado = estado;
		this->gruposV = gruposV;
		this->qtdVacina = qtdVacina;
		this->taxa = taxa;
		this->taxaProx = taxaProx;
		this->taxaFixa = taxaFixa;
		this->popGrupo = popGrupo;
							
	}
	string getEstado()
	{
		return estado;
	}

	string getGrupo()
	{
		return gruposV;
	}
	
	double getTaxaProx()
	{
		return taxaProx;
	}

	int getQtdVacina()
	{
		return qtdVacina;
	}

	double getTaxa()
	{
		return taxa;
	}
	double getTaxaFixa()
	{
		return taxaFixa;
	}
	int getPopGrupo(){
		return popGrupo;
	}
};
void bubble(criarInd vet[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(vet[j].taxa<vet[j+1].taxa){
				swap(vet[j],vet[j+1]);
			}
		}
	}
}
void bubbleOrdenaTaxa(valOrdenacao vet[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(vet[j].distTaxa<vet[j+1].distTaxa){
				swap(vet[j],vet[j+1]);
			}
		}
	}
}
double obterTaxa(Individuo ind1, Individuo ind2)
{
	/*
		Realiza a diferença entre as taxas
	*/
	double result_taxa = (ind1.getTaxa() - ind2.getTaxa());
	return result_taxa;
}

valOrdenacao classificarAmostra(vector<Individuo>& individuos, Individuo novo_exemplo, int K)
{
	
	
	
	// obtém o tamanho do vetor
	int tam_vet = individuos.size();
	
	/*
		set de pairs da diferança de cada indivíduo
		do conjunto de treinamento para o novo exemplo
		cada pair é composto pela diferança e o índice
		do indivíduo no vetor
	*/
	set<pair<double, string> > dif_individuos;
	
	valOrdenacao vetorOrdena[tam_vet];
	/*
		calcula-se a diferença das taxas do novo exemplo
		para cada amostra do conjunto de treinamento
	*/
	for(int i = 0; i < tam_vet; i++)
	{
		if(individuos[i].getPopGrupo() > 0){
			double dist = obterTaxa(individuos[i], novo_exemplo);
			dif_individuos.insert(make_pair(dist, individuos[i].getEstado()));
		}
		
	}

	int it = tam_vet-1;
	int n = 0;
	for (auto const &x : dif_individuos)
	{
		vetorOrdena[n].distTaxa = x.first;
		vetorOrdena[n].grupoTaxa = individuos[it].getGrupo();
		vetorOrdena[n].taxaOrd = individuos[it].getTaxa();
		vetorOrdena[n].taxaProxOrd = individuos[it].getTaxaProx();
		vetorOrdena[n].taxaFixaOrd = individuos[it].getTaxaFixa();
		vetorOrdena[n].estadoTaxa = x.second;
		it--;
		n++;
	}
	bubbleOrdenaTaxa(vetorOrdena, n);

	return vetorOrdena[0];
	
		
}
double pegaTaxaFixa(estados vetEstados[], string estadoC, string grupoC ){
	double taxaC;
	for(int z = 0; z < 27; z++){
		if(vetEstados[z].nome == estadoC){
			if(grupoC == "1" ){
				taxaC = vetEstados[z].grupo1.taxaCont;
				break;
			}
			else if(grupoC == "2" ){
				taxaC = vetEstados[z].grupo2.taxaCont;
				break;
			}
			else if(grupoC == "3" ){
				taxaC = vetEstados[z].grupo3.taxaCont;
				break;
			}
			else if(grupoC == "4" ){
				taxaC = vetEstados[z].grupo4.taxaCont;
				break;
			}
			else if(grupoC == "5" ){
				taxaC = vetEstados[z].grupo5.taxaCont;
				break;
			}
			else if(grupoC == "6" ){
				taxaC = vetEstados[z].grupo6.taxaCont;
				break;
			}
			else if(grupoC == "7" ){
				taxaC = vetEstados[z].grupo7.taxaCont;
				break;
			}
			else if(grupoC == "8" ){
				taxaC = vetEstados[z].grupo8.taxaCont;
				break;
			}
			else if(grupoC == "9" ){
				taxaC = vetEstados[z].grupo9.taxaCont;
				break;
			}
			else if(grupoC == "10" ){
				taxaC = vetEstados[z].grupo10.taxaCont;
				break;
			}
			else if(grupoC == "11" ){
				taxaC = vetEstados[z].grupo11.taxaCont;
				break;
			}
			else if(grupoC == "12" ){
				taxaC = vetEstados[z].grupo12.taxaCont;
				break;
			}
			else if(grupoC == "13" ){
				taxaC = vetEstados[z].grupo13.taxaCont;
				break;
			}
			else if(grupoC == "14" ){
				taxaC = vetEstados[z].grupo14.taxaCont;
				break;
			}
			else if(grupoC == "15" ){
				taxaC = vetEstados[z].grupo15.taxaCont;
				break;
			}
			else if(grupoC == "16" ){
				taxaC = vetEstados[z].grupo16.taxaCont;
				break;
			}
			else if(grupoC == "17" ){
				taxaC = vetEstados[z].grupo17.taxaCont;
				break;
			}
			else if(grupoC == "18" ){
				taxaC = vetEstados[z].grupo18.taxaCont;
				break;
			}
		}
	}
	return taxaC;		
}

int main()
{
	ifstream contaminadosEstados ("dados_contaminados.txt");
	int tam_treinamento = 487; 
	string f, g, h, i, j;
	string a, e;
	int b, c;
	double d;
	contaminadosEstados >> f >> g >> h >> i >> j;
	estados vetEstados[27];
	vetEstados[0].nome = "DF";
	vetEstados[1].nome = "ES"; 
	vetEstados[2].nome = "MG"; 
	vetEstados[3].nome = "RJ"; 
	vetEstados[4].nome = "SC"; 
	vetEstados[5].nome = "SP"; 
	vetEstados[6].nome = "AC"; 
	vetEstados[7].nome = "AL"; 
	vetEstados[8].nome = "AM"; 
	vetEstados[9].nome = "BA"; 
	vetEstados[10].nome = "CE"; 
	vetEstados[11].nome = "GO"; 
	vetEstados[12].nome = "MA"; 
	vetEstados[13].nome = "PA"; 
	vetEstados[14].nome = "PE"; 
	vetEstados[15].nome = "PI"; 
	vetEstados[16].nome = "RO"; 
	vetEstados[17].nome = "SE"; 
	vetEstados[18].nome = "TO"; 
	vetEstados[19].nome = "MS"; 
	vetEstados[20].nome = "RN"; 
	vetEstados[21].nome = "RS"; 
	vetEstados[22].nome = "AP"; 
	vetEstados[23].nome = "MT"; 
	vetEstados[24].nome = "PB"; 
	vetEstados[25].nome = "PR"; 
	vetEstados[26].nome = "RR";
	 
	for(int i = 0; i < tam_treinamento; i++){
		contaminadosEstados >> a >> b >> c >> d >> e;
		if (e == "Indigena")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo1.populcao = c;
					vetEstados[i].grupo1.taxaCont = d;
					vetEstados[i].grupo1.qtdLotes = 0;
				}
			}

		}
		else if (e == "Saude")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo2.populcao = c;
					vetEstados[i].grupo2.taxaCont = d;
					vetEstados[i].grupo2.qtdLotes = 0;
				}
			}

		}
		else if (e == "Maior80")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo3.populcao = c;
					vetEstados[i].grupo3.taxaCont = d;
					vetEstados[i].grupo3.qtdLotes = 0;
				}
			}

		}
		else if (e == "Maior75")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo4.populcao = c;
					vetEstados[i].grupo4.taxaCont = d;
					vetEstados[i].grupo4.qtdLotes = 0;
				}
			}

		}
		else if (e == "Maior70")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo5.populcao = c;
					vetEstados[i].grupo5.taxaCont = d;
					vetEstados[i].grupo5.qtdLotes = 0;
				}
			}

		}
		else if (e == "Maior65")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo6.populcao = c;
					vetEstados[i].grupo6.taxaCont = d;
					vetEstados[i].grupo6.qtdLotes = 0;
				}
			}

		}
		else if (e == "Maior60")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo7.populcao = c;
					vetEstados[i].grupo7.taxaCont = d;
					vetEstados[i].grupo7.qtdLotes = 0;
				}
			}

		}
		else if (e == "Agente")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo8.populcao = c;
					vetEstados[i].grupo8.taxaCont = d;
					vetEstados[i].grupo8.qtdLotes = 0;
				}
			}

		}
		else if (e == "EnsinoBasico")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo9.populcao = c;
					vetEstados[i].grupo9.taxaCont = d;
					vetEstados[i].grupo9.qtdLotes = 0;
				}
			}

		}
		else if (e == "EnsinoSuperior")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo10.populcao = c;
					vetEstados[i].grupo10.taxaCont = d;
					vetEstados[i].grupo10.qtdLotes = 0;
				}
			}

		}
		else if (e == "ForcaSalv")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo11.populcao = c;
					vetEstados[i].grupo11.taxaCont = d;
					vetEstados[i].grupo11.qtdLotes = 0;
				}
			}

		}
		else if (e == "ForcaArm")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo12.populcao = c;
					vetEstados[i].grupo12.taxaCont = d;
					vetEstados[i].grupo12.qtdLotes = 0;
				}
			}

		}
		else if (e == "TransRod")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo13.populcao = c;
					vetEstados[i].grupo13.taxaCont = d;
					vetEstados[i].grupo13.qtdLotes = 0;
				}
			}

		}
		else if (e == "TransMet")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo14.populcao = c;
					vetEstados[i].grupo14.taxaCont = d;
					vetEstados[i].grupo14.qtdLotes = 0;
				}
			}

		}
		else if (e == "TransAer")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo15.populcao = c;
					vetEstados[i].grupo15.taxaCont = d;
					vetEstados[i].grupo15.qtdLotes = 0;
				}
			}

		}
		else if (e == "Camin")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo16.populcao = c;
					vetEstados[i].grupo16.taxaCont = d;
					vetEstados[i].grupo16.qtdLotes = 0;
				}
			}

		}
		else if (e == "Port")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo17.populcao = c;
					vetEstados[i].grupo17.taxaCont = d;
					vetEstados[i].grupo17.qtdLotes = 0;
				}
			}

		}
		else if (e == "Indus")
		{
			for (int i = 0; i < 27; i++)
			{			
				if (vetEstados[i].nome == a)
				{
					vetEstados[i].grupo18.populcao = c;
					vetEstados[i].grupo18.taxaCont = d;
					vetEstados[i].grupo18.qtdLotes = 0;
				}
			}

		}
	}
	
	statusEstado vetStatus[27];
	
	vetStatus[0].nome = "DF";
	vetStatus[1].nome = "ES"; 
	vetStatus[2].nome = "MG"; 
	vetStatus[3].nome = "RJ"; 
	vetStatus[4].nome = "SC"; 
	vetStatus[5].nome = "SP"; 
	vetStatus[6].nome = "AC"; 
	vetStatus[7].nome = "AL"; 
	vetStatus[8].nome = "AM"; 
	vetStatus[9].nome = "BA"; 
	vetStatus[10].nome = "CE"; 
	vetStatus[11].nome = "GO"; 
	vetStatus[12].nome = "MA"; 
	vetStatus[13].nome = "PA"; 
	vetStatus[14].nome = "PE"; 
	vetStatus[15].nome = "PI"; 
	vetStatus[16].nome = "RO"; 
	vetStatus[17].nome = "SE"; 
	vetStatus[18].nome = "TO"; 
	vetStatus[19].nome = "MS"; 
	vetStatus[20].nome = "RN"; 
	vetStatus[21].nome = "RS"; 
	vetStatus[22].nome = "AP"; 
	vetStatus[23].nome = "MT"; 
	vetStatus[24].nome = "PB"; 
	vetStatus[25].nome = "PR"; 
	vetStatus[26].nome = "RR";
	
	for (int i = 0; i < 27; i++)
	{
		vetStatus[i].grupos = "1";
	}

	criarInd vetCriarInd[27];
	
	vetCriarInd[0].estado = "DF";
	vetCriarInd[1].estado = "ES"; 
	vetCriarInd[2].estado = "MG"; 
	vetCriarInd[3].estado = "RJ"; 
	vetCriarInd[4].estado = "SC"; 
	vetCriarInd[5].estado = "SP"; 
	vetCriarInd[6].estado = "AC"; 
	vetCriarInd[7].estado = "AL"; 
	vetCriarInd[8].estado = "AM"; 
	vetCriarInd[9].estado = "BA"; 
	vetCriarInd[10].estado = "CE"; 
	vetCriarInd[11].estado = "GO"; 
	vetCriarInd[12].estado = "MA"; 
	vetCriarInd[13].estado = "PA"; 
	vetCriarInd[14].estado = "PE"; 
	vetCriarInd[15].estado = "PI"; 
	vetCriarInd[16].estado = "RO"; 
	vetCriarInd[17].estado = "SE"; 
	vetCriarInd[18].estado = "TO"; 
	vetCriarInd[19].estado = "MS"; 
	vetCriarInd[20].estado = "RN"; 
	vetCriarInd[21].estado = "RS"; 
	vetCriarInd[22].estado = "AP"; 
	vetCriarInd[23].estado = "MT"; 
	vetCriarInd[24].estado = "PB"; 
	vetCriarInd[25].estado = "PR"; 
	vetCriarInd[26].estado = "RR";
	
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 27; j++)
		{
			if (vetCriarInd[i].estado == vetStatus[j].nome)
			{
				vetCriarInd[i].grupoV = vetStatus[j].grupos;
				for(int k = 0; k < 27; k++)
				{
					if (vetCriarInd[i].estado == vetEstados[k].nome)
					{
						if(vetCriarInd[i].grupoV == "1" ){			
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo1.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo1.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo2.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "2" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo2.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo2.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo3.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "3" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo3.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo3.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo4.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "4" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo4.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo4.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo5.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "5" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo5.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo5.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo6.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "6" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo6.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo6.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo7.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "7" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo7.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo7.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo8.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "8" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo8.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo8.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo9.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "9" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo9.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo9.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo10.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "10" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo10.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo10.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo11.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "11" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo11.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo11.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo12.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "12" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo12.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo12.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo13.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "13" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo13.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo13.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo14.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "14" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo14.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo14.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo15.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "15" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo15.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo15.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo16.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "16" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo16.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo16.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo17.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "17" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo17.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo17.taxaCont;
							vetCriarInd[i].taxaProx = vetEstados[k].grupo18.taxaCont;
						}
						else if(vetCriarInd[i].grupoV == "18" ){
							vetCriarInd[i].populacaoGrupo = vetEstados[k].grupo18.populcao;
							vetCriarInd[i].taxa = vetEstados[k].grupo18.taxaCont;
						}
					}
				}
			}
		}
	}

	bubble(vetCriarInd, 27);

	char valida;
	int quantVacina;
	cout<< "Insira os dados"<<endl;
	Individuo ind();
	vector<Individuo> individuos; //já classificados
	FILE *arq;

	char buf[BUFSIZ];
    int linhas = 0;

    arq = fopen("dados_entradas.txt","r");
	 while(fgets(buf, BUFSIZ, arq) != NULL) {
        linhas++;
    }

    fclose(arq);
	
	FILE *dados;
	dados = fopen("dados_entradas.txt", "a");
	int popInicial = linhas;
	bool entrou = false;
	bool sobrou = false;
	int restoVacina = 0;
	cout<<"Deseja inserir um lote de vacinas(S/N): ";
	cin>> valida;
	if(valida == 's'){
		cout<<"Quantidade vacinas: ";
		cin>> quantVacina;
	}
	if(quantVacina>0){
		while (valida == 'S' or valida == 's')
		{
			if (popInicial < 27)
			{	
				
				for (int i = 0; i < 27; i++)
				{
					char estadoAtual[10];
					char grupoAtual[10];
					
					strcpy(estadoAtual, vetCriarInd[popInicial].estado.c_str());
					strcpy(grupoAtual, vetCriarInd[popInicial].grupoV.c_str());
					fprintf (dados, "%s %s %i %f %f %i \n", estadoAtual, grupoAtual, 0, vetCriarInd[popInicial].taxa, vetCriarInd[popInicial].taxaProx, vetCriarInd[popInicial].populacaoGrupo);
					popInicial++;
				}
			}
			if(quantVacina>0){
				if(popInicial >=27)
				{	
					if(!entrou)
					{
						fclose(dados);
						ifstream arqPer("dados_entradas.txt");
						FILE *arq;
						char buf[BUFSIZ];
						arq = fopen("dados_entradas.txt","r");
						 while(fgets(buf, BUFSIZ, arq) != NULL) {
							if(arqPer)
							{
								string estadoKnn, grupoKnn;
								int qtdKnn = 0, popGrupoKnn = 0;
								double taxaKnn = 0, taxaProxKnn = 0, taxaFixaKnn = 0;
								arqPer  >> estadoKnn>> grupoKnn>> qtdKnn>> taxaKnn>> taxaProxKnn >> popGrupoKnn;
								taxaFixaKnn = pegaTaxaFixa(vetEstados, estadoKnn, grupoKnn);
								individuos.push_back(Individuo(estadoKnn, grupoKnn, qtdKnn, taxaKnn, taxaProxKnn, taxaFixaKnn, popGrupoKnn));

								for (int z = 0; z < 27; z++)
								{
									if(vetEstados[z].nome == estadoKnn){
										if(grupoKnn == "1" ){
											vetEstados[z].grupo1.qtdLotes++; 
											break;
										}
										else if(grupoKnn == "2" ){
											vetEstados[z].grupo2.qtdLotes++;
											break;
										}
										else if(grupoKnn == "3" ){
											vetEstados[z].grupo3.qtdLotes++;
											break;
										}
										else if(grupoKnn == "4" ){
											vetEstados[z].grupo4.qtdLotes++;
											break;
										}
										else if(grupoKnn == "5" ){
											vetEstados[z].grupo5.qtdLotes++;
											break;
										}
										else if(grupoKnn == "6" ){
											vetEstados[z].grupo6.qtdLotes++;
											break;
										}
										else if(grupoKnn == "7" ){
											vetEstados[z].grupo7.qtdLotes++;
											break;
										}
										else if(grupoKnn == "8" ){
											vetEstados[z].grupo8.qtdLotes++;
											break;
										}
										else if(grupoKnn == "9" ){
											vetEstados[z].grupo9.qtdLotes++;
											break;
										}
										else if(grupoKnn == "10" ){
											vetEstados[z].grupo10.qtdLotes++;
											break;
										}
										else if(grupoKnn == "11" ){
											vetEstados[z].grupo11.qtdLotes++;
											break;
										}
										else if(grupoKnn == "12" ){
											vetEstados[z].grupo12.qtdLotes++;
											break;
										}
										else if(grupoKnn == "13" ){
											vetEstados[z].grupo13.qtdLotes++;
											break;
										}
										else if(grupoKnn == "14" ){
											vetEstados[z].grupo14.qtdLotes++;
											break;
										}
										else if(grupoKnn == "15" ){
											vetEstados[z].grupo15.qtdLotes++;
											break;
										}
										else if(grupoKnn == "16" ){
											vetEstados[z].grupo16.qtdLotes++;
											break;
										}
										else if(grupoKnn == "17" ){
											vetEstados[z].grupo17.qtdLotes++;
											break;
										}
										else if(grupoKnn == "18" ){
											vetEstados[z].grupo18.qtdLotes++;
											break;
										}
									}
								}
							}
						}

						fclose(arq);
						arqPer.close();	
						entrou=true;
					}
					
					Individuo ind("Teste", "5", quantVacina, 10.2113, 12.453, 10.2113, 29002010);
					//Chamada de função para execução do KNN com o k=1
					valOrdenacao vetorInd = classificarAmostra(individuos, ind, 1);
					sobrou = false;
					ind.estado = vetorInd.estadoTaxa;
					ind.gruposV = vetorInd.grupoTaxa;
					ind.taxa = vetorInd.taxaOrd;
					ind.taxaProx = vetorInd.taxaProxOrd;
					ind.taxaFixa = pegaTaxaFixa(vetEstados, ind.estado, ind.gruposV);
					cout<<endl;
					cout<<"Estado para onde vacina ira: "<<ind.estado<<" Para o subgrupo: "<<ind.gruposV<<endl;
					cout<<endl;
					int tamI = individuos.size()-1;
					for (int t = tamI; t >=0; t--)
					{
						if (ind.estado == individuos[t].getEstado())
						{
							if (ind.gruposV == individuos[t].getGrupo())
							{
								
								restoVacina = quantVacina-individuos[t].getPopGrupo();
								if (restoVacina > 0 )
								{
									sobrou = true;
								}
								
								if (quantVacina > individuos[t].getPopGrupo())
								{
									ind.qtdVacina = individuos[t].getPopGrupo();
									ind.popGrupo = 0;
									cout<<"Essa quantidade de vacina e maior que a poulacao do estado mais necessitado por isso o restante de vacinas, "<<restoVacina <<" und, sera distribuido para o proximo estado do grupo com a taxa de contaminacao maior"<<endl;
									cout<<endl;
									string estadoNovo, grupoNovo;
									int popGrupoNovo;
									double taxaNovo, taxaProxNova, taxaFixaNova;
									
									for(int k = 0; k < 27; k++)
									{
										if (ind.estado == vetEstados[k].nome)
										{
											if(ind.gruposV == "1" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "2";
												taxaNovo = vetEstados[k].grupo2.taxaCont;
												taxaProxNova = vetEstados[k].grupo3.taxaCont;
												taxaFixaNova = vetEstados[k].grupo2.taxaCont;
												popGrupoNovo = vetEstados[k].grupo2.populcao;										
												break;
												
											}
											else if(ind.gruposV == "2" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "3";
												taxaNovo = vetEstados[k].grupo3.taxaCont;
												taxaProxNova = vetEstados[k].grupo4.taxaCont;
												taxaFixaNova = vetEstados[k].grupo3.taxaCont;
												popGrupoNovo = vetEstados[k].grupo3.populcao;
												break;
											}
											else if(ind.gruposV == "3" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "4";
												taxaNovo = vetEstados[k].grupo4.taxaCont;
												taxaProxNova = vetEstados[k].grupo5.taxaCont;
												taxaFixaNova = vetEstados[k].grupo4.taxaCont;
												popGrupoNovo = vetEstados[k].grupo4.populcao;
												break;
											}
											else if(ind.gruposV == "4" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "5";
												taxaNovo = vetEstados[k].grupo5.taxaCont;
												taxaProxNova = vetEstados[k].grupo6.taxaCont;
												taxaFixaNova = vetEstados[k].grupo5.taxaCont;
												popGrupoNovo = vetEstados[k].grupo5.populcao;
												break;
											}
											else if(ind.gruposV == "5" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "6";
												taxaNovo = vetEstados[k].grupo6.taxaCont;
												taxaProxNova = vetEstados[k].grupo7.taxaCont;
												taxaFixaNova = vetEstados[k].grupo6.taxaCont;
												popGrupoNovo = vetEstados[k].grupo6.populcao;
												break;
											}
											else if(ind.gruposV == "6" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "7";
												taxaNovo = vetEstados[k].grupo7.taxaCont;
												taxaProxNova = vetEstados[k].grupo8.taxaCont;
												taxaFixaNova = vetEstados[k].grupo7.taxaCont;
												popGrupoNovo = vetEstados[k].grupo7.populcao;
												break;
											}
											else if(ind.gruposV == "7" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "8";
												taxaNovo = vetEstados[k].grupo8.taxaCont;
												taxaProxNova = vetEstados[k].grupo9.taxaCont;
												taxaFixaNova = vetEstados[k].grupo8.taxaCont;
												popGrupoNovo = vetEstados[k].grupo8.populcao;
												break;
											}
											else if(ind.gruposV == "8" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "9";
												taxaNovo = vetEstados[k].grupo10.taxaCont;
												taxaProxNova = vetEstados[k].grupo9.taxaCont;
												taxaFixaNova = vetEstados[k].grupo9.taxaCont;
												popGrupoNovo = vetEstados[k].grupo9.populcao;
												break;
											}
											else if(ind.gruposV == "9" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "10";
												taxaNovo = vetEstados[k].grupo11.taxaCont;
												taxaProxNova = vetEstados[k].grupo12.taxaCont;
												taxaFixaNova = vetEstados[k].grupo11.taxaCont;
												popGrupoNovo = vetEstados[k].grupo11.populcao;
												break;
											}
											else if(ind.gruposV == "10" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "11";
												taxaNovo = vetEstados[k].grupo11.taxaCont;
												taxaProxNova = vetEstados[k].grupo12.taxaCont;
												taxaFixaNova = vetEstados[k].grupo11.taxaCont;
												popGrupoNovo = vetEstados[k].grupo11.populcao;
												break;
											}
											else if(ind.gruposV == "11" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "12";
												taxaNovo = vetEstados[k].grupo12.taxaCont;
												taxaProxNova = vetEstados[k].grupo13.taxaCont;
												taxaFixaNova = vetEstados[k].grupo12.taxaCont;
												popGrupoNovo = vetEstados[k].grupo12.populcao;
												break;
											}
											else if(ind.gruposV == "12" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "13";
												taxaNovo = vetEstados[k].grupo13.taxaCont;
												taxaProxNova = vetEstados[k].grupo14.taxaCont;
												taxaFixaNova = vetEstados[k].grupo13.taxaCont;
												popGrupoNovo = vetEstados[k].grupo13.populcao;
												break;
											}
											else if(ind.gruposV == "13" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "14";
												taxaNovo = vetEstados[k].grupo14.taxaCont;
												taxaProxNova = vetEstados[k].grupo15.taxaCont;
												taxaFixaNova = vetEstados[k].grupo14.taxaCont;
												popGrupoNovo = vetEstados[k].grupo14.populcao;
												break;
											}
											else if(ind.gruposV == "14" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "15";
												taxaNovo = vetEstados[k].grupo15.taxaCont;
												taxaProxNova = vetEstados[k].grupo16.taxaCont;
												taxaFixaNova = vetEstados[k].grupo15.taxaCont;
												popGrupoNovo = vetEstados[k].grupo15.populcao;
												break;
											}
											else if(ind.gruposV == "15" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "16";
												taxaNovo = vetEstados[k].grupo16.taxaCont;
												taxaProxNova = vetEstados[k].grupo17.taxaCont;
												taxaFixaNova = vetEstados[k].grupo16.taxaCont;
												popGrupoNovo = vetEstados[k].grupo16.populcao;
												break;
											}
											else if(ind.gruposV == "16" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "17";
												taxaNovo = vetEstados[k].grupo16.taxaCont;
												taxaProxNova = vetEstados[k].grupo17.taxaCont;
												taxaFixaNova = vetEstados[k].grupo16.taxaCont;
												popGrupoNovo = vetEstados[k].grupo16.populcao;
												break;
											}
											else if(ind.gruposV == "17" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "18";
												taxaNovo = vetEstados[k].grupo18.taxaCont;
												taxaProxNova = vetEstados[k].grupo18.taxaCont;
												taxaFixaNova = vetEstados[k].grupo18.taxaCont;
												popGrupoNovo = vetEstados[k].grupo18.populcao;
												break;
											}
											else if(ind.gruposV == "18" ){
												estadoNovo = vetEstados[k].nome;
												grupoNovo = "18";
												taxaNovo = vetEstados[k].grupo18.taxaCont;
												taxaProxNova = vetEstados[k].grupo18.taxaCont;
												taxaFixaNova = vetEstados[k].grupo18.taxaCont;
												popGrupoNovo = vetEstados[k].grupo18.populcao;
												break;
											}
										}

									}
									individuos.push_back(Individuo(estadoNovo, grupoNovo, 0, taxaNovo, taxaProxNova, taxaFixaNova, popGrupoNovo));
									
								}
								else if(quantVacina <= individuos[t].getPopGrupo())
								{	
									ind.popGrupo = individuos[t].getPopGrupo()-quantVacina;
								}
								//cout<<"Pop n vacinada: "<<ind.popGrupo<<endl;
							}
								break;
						}
					}
									
					individuos.push_back(ind);			
					for (int z = 0; z < 27; z++)
					{
						if(vetEstados[z].nome == ind.getEstado()){
							if(ind.gruposV == "1" ){
								vetEstados[z].grupo1.qtdLotes++; 
								break;
							}
							else if(ind.gruposV == "2" ){
								vetEstados[z].grupo2.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "3" ){
								vetEstados[z].grupo3.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "4" ){
								vetEstados[z].grupo4.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "5" ){
								vetEstados[z].grupo5.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "6" ){
								vetEstados[z].grupo6.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "7" ){
								vetEstados[z].grupo7.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "8" ){
								vetEstados[z].grupo8.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "9" ){
								vetEstados[z].grupo9.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "10" ){
								vetEstados[z].grupo10.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "11" ){
								vetEstados[z].grupo11.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "12" ){
								vetEstados[z].grupo12.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "13" ){
								vetEstados[z].grupo13.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "14" ){
								vetEstados[z].grupo14.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "15" ){
								vetEstados[z].grupo15.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "16" ){
								vetEstados[z].grupo16.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "17" ){
								vetEstados[z].grupo17.qtdLotes++;
								break;
							}
							else if(ind.gruposV == "18" ){
								vetEstados[z].grupo18.qtdLotes++;
								break;
							}
						}
					}
					
					int tamanho = individuos.size();
					for (int i = 0; i<tamanho; i++)
					{
						if(individuos[i].getEstado()==ind.getEstado() and individuos[i].getGrupo() == ind.getGrupo()){
							for (int j = 0; j < 27; j++)
							{
								if(vetEstados[j].nome == individuos[i].getEstado()){
									if(ind.gruposV == "1" ){
										////cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo1.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "2" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo2.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "3" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo3.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "4" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo4.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "5" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo5.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "6" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo6.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "7" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo7.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "8" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo8.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "9" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo9.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "10" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo10.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "11" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo11.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "12" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo12.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "13" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo13.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "14" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo14.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "15" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo15.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "16" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo16.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "17" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo17.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
									else if(ind.gruposV == "18" ){
										//cout<<"fixa: "<< individuos[i].getTaxaFixa() <<endl;
										individuos[i].taxa = individuos[i].getTaxaFixa()/vetEstados[j].grupo18.qtdLotes;
										ind.taxa = individuos[i].taxa;
										//cout<<"TAXA/: "<<individuos[i].taxa<<endl;
										break;
									}
								}
							}			
						}
					}
					
					ofstream dados;
					dados.open("dados_entradas.txt");

					int tamInd = individuos.size();
					
					for (int a = 0; a < tamInd; a++)
					{
						if(individuos[a].getEstado()==ind.getEstado() and individuos[a].getGrupo() == ind.getGrupo()){
							individuos[a].popGrupo = ind.getPopGrupo();
						}
						dados<<individuos[a].getEstado()<<"	"<<individuos[a].getGrupo()<<"	"<<individuos[a].getQtdVacina()<<"	"<<individuos[a].getTaxa()<<"	"<<individuos[a].getTaxaProx()<<"	"<<individuos[a].getPopGrupo()<<"\n";
					}
					dados.close();
					
				}
			}	
			if(!sobrou){
				cout<<"Deseja inserir outro lote de vacinas(S/N): ";
				cin>> valida;
				if(valida == 's'){
					cout<<"Quantidade vacinas: ";
					cin>> quantVacina;
				}
			}
			else{
				valida = 'S';
				quantVacina=restoVacina;
			}
		}
	}
	return 0;
}
