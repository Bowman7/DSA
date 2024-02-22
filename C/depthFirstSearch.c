#include<stdio.h>
#include<stdlib.h>

//node
struct node{
  int vertex;
  struct node* next;
};

//graph
struct graph{
  int totalVertices;
  struct node** adjList;
  int* visited;
  int* stack;
  int top;
};

//create graph
struct graph* createGraph(int numVertices){
  struct graph* temp = (struct graph*)malloc(sizeof(struct graph));

  temp->totalVertices = numVertices;
  temp->adjList = malloc(numVertices * sizeof(struct node*));
  temp->visited = malloc(numVertices * sizeof(int));
  temp->stack   = malloc(numVertices * sizeof(int));
  temp->top = -1;
  for(int i =0;i<numVertices;i++){
    temp->adjList[i] = NULL;
    temp->visited[i] =0;
    temp->stack[i]=0;
  }

  return temp;
}

//create a new node
struct node* createNode(int val){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->vertex = val;
  temp->next = NULL;

  return temp;
}
//add Edges
void addEdge(struct graph* g,int src,int dst){
  struct node* temp = createNode(dst);
  temp->next = g->adjList[src];
  g->adjList[src] = temp;

  temp= createNode(src);
  temp->next = g->adjList[dst];
  g->adjList[dst] = temp;
}
//print edges
void printEdges(struct graph* g){
  for(int i=0;i<g->totalVertices;i++){
    struct node* p =g->adjList[i];
    printf("Vertex %d :",i);
    while(p){
      printf(" <- %d ",p->vertex);
      p=p->next;
    }
    printf("\n");
  }
}

//perform dfs recursively
void dfs(struct graph* g,int vertex){
  struct node* adjList = g->adjList[vertex];
  struct node* temp = adjList;

  //set starting vertex visited to 1
  printf("Visited : %d \n",vertex);
  g->stack[++g->top] = vertex;

  g->visited[vertex] = 1;
    while(temp){
    int connectedVertex = temp->vertex;
    if(g->visited[connectedVertex] == 0){
      dfs(g,connectedVertex);
    }
    temp=temp->next;
  }					    
}

//print visited nodes
void printStack(struct graph* g){
  printf("\n Visited : ");
  for(int i=0;i<g->totalVertices-1;i++){
    printf(" %d -> ",g->stack[i]);
  }
  printf(" %d ",g->stack[g->totalVertices-1]);
  printf("\n");
}
int main(){
  int numVertices = 5;
  //create a graph
  struct graph* g = createGraph(numVertices);
  //add edges of nodes
  addEdge(g,0,1);
  addEdge(g,0,2);
  addEdge(g,0,3);
  addEdge(g,1,2);
  addEdge(g,2,4);

  printEdges(g);

  dfs(g,0);
  printStack(g);

  return 0;

}
