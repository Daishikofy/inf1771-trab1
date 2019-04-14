//https://stackoverflow.com/questions/5493474/graph-implementation-c/50379457
#include "Grafo.h"

using namespace std;

//Custom Constructor da classe Vertice
Vertice::Vertice(int id, int x, int y, int demanda)
{
	Vertice::id = id;
	Vertice::x = x;
	Vertice::y = y;
	Vertice::demanda = demanda;
}

//Getters para ID, X, Y e demanda
int Vertice::getId()
{
	return Vertice::id;
}
int Vertice::getX()
{
	return Vertice::x;
}
int Vertice::getY()
{
	return Vertice::y;
}
int Vertice::getDemanda()
{
	return Vertice::demanda;
}

//Adicionar vertice no grafo 
//Parametros: int id, int x, int y, int demanda
void Grafo::GRF_adicionarVertice(int id, int x, int y, int demanda)
{
	//Iterator para o mapa de vertices eh gerado,
	// para isso eh encontrado o vertice por seu identificador ID
	VertMap::iterator iterador = mapaDeCaminhos.find(id);
	//Se o iterador chega ao fim do mapa,
	//um novo vertice eh gerado com o ID do parametro
	if (iterador == mapaDeCaminhos.end())
	{
		Vertice *vert;
		vert = new Vertice(id, x, y, demanda);
		mapaDeCaminhos[id] = vert;
		return;
	}
	//aviso de que o vertice com o ID do parametro
	// ja existe
	cout << "\nVertice ja existente" << endl;
}

//Da definicao no enunciado -> E : (i,j) in E, onde i == origem; 
// j == destino; custo == valor entre i e j
//Parametros int origem, int destino, float custo
void Grafo::GRF_adicionarAresta(int origem, int destino, float custo)
{
	//Vertices Origem & Destino 
	//recebem o segundo - second - valor armazenado do Mapa
	Vertice * Origem = mapaDeCaminhos.find(origem)->second;
	Vertice * Destino = mapaDeCaminhos.find(destino)->second;
	//Uma nova aresta eh criada, uma aresta eh um par ordenado com 
	//custo e destino
	pair<int, Vertice *> aresta = make_pair(custo, Destino);
	//Origem recebe uma nova adjacencia que eh a aresta criada anteriormente
	Origem->adjacencia.push_back(aresta);
}