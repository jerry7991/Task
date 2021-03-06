#include <iostream>
#include <queue>
using namespace std;
void printBFS(int ** isPath , int nVertices , int startVertex,bool* isVisited)
{
	
	//make a queue to append same level of vertex............... OK!!!!
	queue<int> pendingVertex;
	//let's append start vertex int queue and make startVertex as visited and start exploring startVertex
	pendingVertex.push(startVertex);//appended
	isVisited[startVertex]=true;//marked as visited
	while( !pendingVertex.empty())
	{
		//let's find the vertex which has to be explored i.e. front of queue
		int currentVertex = pendingVertex.front();
		//and pop this front vertex
		pendingVertex.pop();
		//print this current vertex
		cout<<currentVertex<<" ";
		//now let's search first non visited vertex from current node
		for (int i = 0; i < nVertices; ++i)
		{
            if(i==currentVertex)
                continue;
			//if there is a path from currentVertex to i-th vertex
			if (isPath[currentVertex][i]==1)
			{
				//if i-th vertex is not visited
				if ( ! isVisited[i])
				{
					//append it to the queue
					pendingVertex.push(i);
					//and make i-th vertex as visited
					isVisited[i]=true;
				}
			}
		}
	}
}
int main()
{
	int nVertices,nEdges;
	//cout<<"Enter the number of veriteces and number of edges \n";
	cin>>nVertices>>nEdges;
	int ** isPath=new int*[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isPath[i]=new int[nVertices];
		for(int j=0  ; j<nVertices ; j++)
		{
			isPath[i][j]=0;
		}
	}
	//cout<<"enter path (source destination)"<<endl;
	for (int i = 0; i < nEdges; ++i)
	{
		int source,destination;
		cin>>source>>destination;
		//store the path from source to destination ok!!!!!!!!!
		isPath[source][destination]=1;
		isPath[destination][source]=1;//cause of undirected graph
	}	
	int startVertex=0;
    bool *isVisited=new bool[nVertices];
	for (int i = 0; i < nVertices; ++i)
	{
		isVisited[i]=false;
	}
    for(int i=0;i< nVertices;++i){
        if(!isVisited[i])
			printBFS(isPath , nVertices, i ,isVisited);
    }
}