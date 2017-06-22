#include "../includes/lem_in.h"
#define MAXV            1000     /* maximum number of vertices */

typedef struct {
	int y;                   /* adjacency info */
	int weight;              /* edge weight, if any */
	struct edgenode *next;   /* next edge in list */
} edgenode;

typedef struct s_graph	{
	edgenode *edges[MAXV+1]; /* adjacency info */
	int degree[MAXV+1];      /* outdegree of each vertex */
	int nvertices;           /* number of vertices in graph */
	int nedges;              /* number of edges in graph */
}				t_graph;

t_graph initialize_graph(t_graph *graph)
{
	int i;                          /* counter */

	i = 0;
	graph -> nvertices = 0;
	graph -> nedges = 0;

	while (i <= MAXV)
	{
		graph->degree[i] = 0;
		i++;
	}
	i = 0;
	while (i <= MAXV)
	{
		graph->edges[i] = NULL;
		i++;
	}
	return (*graph);
}

read_graph(t_graph *graph)
{

	int i;                         /* counter */
	int m;                         /* number of edges */
	int x, y;                      /* vertices in edge (x,y) */

	initialize_graph(g, directed);

	scanf("%d %d",&(g->nvertices),&m);

	for (i=1; i<=m; i++) {
		scanf("%d %d",&x,&y);
		insert_edge(g,x,y,directed);
	}
}

insert_edge(graph *g, int x, int y, bool directed)
{
	edgenode *p;                  /* temporary pointer */

	p = malloc(sizeof(edgenode)); /* allocate edgenode storage */

	p->weight = NULL;
	p->y = y;
	p->next = g->edges[x];

	g->edges[x] = p;    /* insert at head of list */

	g->degree[x] ++;

	if (directed == FALSE)
		insert_edge(g,y,x,TRUE);
	else
		g->nedges ++;
}

print_graph(graph *g)
{
	int i;                         /* counter */
	edgenode *p;                   /* temporary pointer */

	for (i=1; i<=g->nvertices; i++) {
		printf("%d: ",i);
		p = g->edges[i];
		while (p != NULL) {
			printf(" %d",p->y);
			p = p->next;
		}
		printf("\n");
	}
}
