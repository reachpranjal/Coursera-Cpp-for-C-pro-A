/*Minimum Spanning Tree algorithms*/

#include<iostream>
#include<queue>
#include<iterator>
#include<fstream>
#include<vector>
#include<numeric>										

using namespace std;
using pi = pair<float,int> ;			

//A large value to illustrate the absence of an edge
const int inf=9999;									
class graph{
	
	private:
		int number_vertex,number_edge;
		int *vertex_value;
		float **adj;								
		
	public:
		
		int num_ver()									
			return number_vertex;
		
		
		int num_edge()								
			return number_edge;
		
		
		int adjacent(int x, int  y)					
		{
			if((adj[x][y]!= inf) && (x!=y)) return 1;
			else return 0;
		}
		
		
		vector <int> neighbours(int x)			
		{
			vector <int> n;
			for(int i=0;i<number_vertex;i++)
			{
				if(adjacent(x,i)) n.push_back(i); 
			}
			return n;	
		}
		
		
		void e_add(int x, int y)						
			if(adj[x][y]==inf) adj[x][y]=get_edge_value(x,y);
		
		
		void e_delete(int x, int y)					
			if(adj[x][y]!=inf) adj[x][y]=inf;
		
		
		int get_node_value(int x)						
			return vertex_value[x];
		
		
		void set_node_value(int x, int a)				
			vertex_value[x]=a;
		
		
		float get_edge_value(int x, int y)				
			return adj[x][y];
		
		
		void set_edge_value(int x, int y, float v)		
		{
			adj[x][y]=v;
			adj[y][x]=v;
		}
		
		float** get_adj()								
			return adj;
		
		graph() 												
		{
			int m,n,i,j;
      
			//please enter the input file name here
			ifstream my_file("example.txt");											
			istream_iterator<int> start(my_file),eos;
			vector <int> raw_data(start,eos);									 	
			vector <int>::iterator p=raw_data.begin();
			
			/*for(auto val: raw_data) cout<<val<<" ";
			cout<<endl<<endl;*/
			
			number_vertex=*p;
	
			adj= new float*[number_vertex];
	
			for(m=0;m<number_vertex;m++)
				adj[m]=new float [number_vertex];								
			
			for(m=0;m<number_vertex;m++)
			{	
				for(n=0;n<number_vertex;n++)
				{
					if(m!=n) adj[m][n]=inf;					
					else adj[m][n]=0;
				}
			}
	
			p++;
			while(p!=raw_data.end())
			{
				i=*p;														 
				p++;
				j=*p;
				p++;
				adj[i][j]=*p;
				p++;
			}
		}										
};	

class MST_algo{																	
	
	private:
		float *key;
		int *process_status,*parent;
		int u,v,nv,source_node;											
		vector <int> u_neighbours;
		
	public:

		MST_algo() {};															
		MST_algo(int source, int num_vertices)			
		{
			source_node=source;
			nv= num_vertices;
			process_status= new int[nv];							
			key = new float[nv];
			parent= new int[nv];
		}
		
		void prims(graph* G)
		{
			priority_queue <pi, vector <pi>, greater <pi>> PQ;					
	
			for(int i=0;i<nv;i++)
			{
				process_status[i]=0;
				parent[i]=-1;																																
				if(i!=source_node) 
				{
					key[i]=inf;
					PQ.push(make_pair(key[i],i));				
				}
				else 
				{
					key[i]=0;
					PQ.push(make_pair(key[i],i));
				} 
			}
			while(!PQ.empty())													
			{
				u=(PQ.top()).second;
				PQ.pop();
				if(process_status[u]==0)									
				{
					process_status[u]=1;
					u_neighbours=G->neighbours(u);
					while(!u_neighbours.empty())						
					{
						v=u_neighbours.back();
				
						if((key[v]>G->get_edge_value(u,v)) && process_status[v]!=1) 
						{
							key[v]=G->get_edge_value(u,v);					
							parent[v]=u;
						}	 
						PQ.push(make_pair(key[v],v));								
						u_neighbours.pop_back();
					}
				}
			}
		}
		float* get_key()
			return key;															
		
    int* get_parent()
			return parent;													
		
    float MST_cost()
			return accumulate(key,key+nv,0);				
};

/*
void view_distance(float **arr, int vertices)
{
	int i,j;
	for(i=0;i<vertices;i++)
	{
		cout<<endl;
		
		for(j=0;j<vertices;j++)													
		{
			if(arr[i][j]==inf) cout<<"INF\t";
			else cout<<arr[i][j]<<"\t";
		}
	}
}*/
template <class T>
void view_distance(T *arr, int vertices)
{
	int j;		
	for(j=0;j<vertices;j++)
	{																			
		if(arr[j]==inf) cout<<"INF\t";
		else cout<<arr[j]<<"\t";
	}
}


int main()																				
{
	int source_node=0,num_nodes;
	int* parents;
	float** dist;
	
	graph g1;
	num_nodes=g1.num_ver();
	
	MST_algo pa(source_node,num_nodes);
	pa.prims(&g1);
	
	/*view_distance(pa.get_key(),num_nodes);cout<<endl<<endl;
	view_distance(pa.get_parent(),num_nodes);*/
	dist=g1.get_adj();
	
	
	parents=pa.get_parent();
	
	cout<<"\nThe minimum spanning tree cost is: "<<pa.MST_cost()<<endl;;
	cout<<"\nThe MST is constructed with";
	for(int i=0;i<num_nodes;i++)
	{
		cout<<endl;
		if(i!=source_node)
		{
			cout<<"edge:("<<i<<","<<parents[i]<<")\t cost:"<<dist[i][parents[i]];
		}
	}
	return 0;
}
