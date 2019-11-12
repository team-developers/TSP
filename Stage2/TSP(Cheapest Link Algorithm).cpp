#include <iostream>
#include <algorithm> 
#include <bits/stdc++.h>
#include <ctime> 
using namespace std;

class Edge {
	public:
		int source;
		int dest;
		int weight;
};

bool compare(Edge e1, Edge e2){
	return e1.weight < e2.weight;
}

int findParent(int v, int *parent){
	if(parent[v] == v){
		return v;
	}
	return findParent(parent[v], parent);
}

void TSP(Edge *input, int n, int E){
	//Sorting the input array in ascending order based on weights.
	// temp
	int *degree = new int[n];
	// temp
	
	for(int i=0; i<n; i++){
		degree[i]=0;
	}
	
	sort(input, input + E, compare);
	
	Edge *output = new Edge[n-1];
	
	//For Union Find.
	int *parent = new int[n];
	
	for(int i=0; i<n; i++){
		parent[i] = i;
	}
	
	int count = 0;
	int i=0;
	
	while(count!=(n-1)){
		Edge currentEdge = input[i];
		
		//Checking if it is forming cycle after adding currentEdge.
		int SourceParent = findParent(currentEdge.source, parent);
		int DestParent = findParent(currentEdge.dest, parent);
		
		
		if(SourceParent != DestParent && degree[currentEdge.source] < 2 && degree[currentEdge.dest] < 2){  
			
			output[count] = currentEdge;
			
			count++;
			parent[SourceParent] = DestParent;
			
			degree[currentEdge.source]++;
			degree[currentEdge.dest]++;
		}
		i++;
	}
						//For printing the last edge to complete Hamiltonian Circuit.
							int fin_source = 0;
							int fin_dest = 0;
							int fin_wt = 0;
							
							for(int i=0; i<n-1; i++){
								if(degree[output[i].source]==1)
									fin_source = output[i].source;
								if(degree[output[i].dest]==1){
									fin_dest = output[i].dest;
								}	
							}
							
							for(int i=0; i<E; i++){
								if((input[i].source==fin_source) && (input[i].dest==fin_dest)){
									fin_wt = input[i].weight;
								}
									
							}	
	
	int wt = 0;
	cout << "\n\nOutput:- \n\n";
	for(int i=0; i<n-1; i++){
		if(output[i].source<output[i].dest)
			cout << output[i].source << "--" << output[i].dest << " " << output[i].weight << endl;
		else{
			cout << output[i].dest << "--" << output[i].source << " " << output[i].weight << endl;
		}
		
		wt+=output[i].weight;	
	}
	
	cout << fin_source << "--" << fin_dest << " " << fin_wt << endl;
	
	wt += fin_wt;
	
	cout << "Total cost of Travel: "<< wt << "\n";
}

int main(){
	cout << "---------------------------------------------------" << "\n";
	cout << "**********"<< "Travelling Salesperson Problem" << "***********" << "\n";
	cout << "---------------------------------------------------" << "\n\n";
	int n, E;
	
	cout << "Enter no. of vertices: ";
	cin >> n;
	
	cout << "Enter no. of Edges: ";
	cin >> E;

	Edge *input = new Edge[E];   //Created an array of type Edge.
	 
	cout << "\nEnter Source, Destination and weight of the input graph:-"<< "\n";
	
	for(int i=0; i<E; i++){
		int s, d, w;
		cin >> s >> d >> w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	
	int start_s=clock();  // For execution time
	
	TSP(input, n, E);
	
	int stop_s=clock();
	
	cout << "Execution Time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " s" <<endl;
	return 0;
}
