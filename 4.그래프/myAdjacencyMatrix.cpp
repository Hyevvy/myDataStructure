//인접행렬을 이용한 그래프 추상 데이터 타입의 구현

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

typedef struct GraphType{
    int n; //정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void init(GraphType* g){
    int r, c;
    g->n =0;
    for(r=0; r<MAX_VERTICES; r++){
        for(c=0; c<MAX_VERTICES; c++){
            g->adj_mat[r][c] = 0;
        }
    }
}

//정점 삽입 연산
void insert_vertex(GraphType* g, int v){
    if((g->n) +1 > MAX_VERTICES){
        fprintf(stderr,"그래프 정점의 개수 초과");
        return ;
    }
    g->n++;
}

void insert_edge(GraphType* g, int start, int end){
    if(start >= g->n || end >= g->n){
        fprintf(stderr,"그래프 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;
}

void print_adj_mat(GraphType* g){
    for(int i=0; i<g->n; i++){
        for(int j=0; j<g->n; j++){
            printf("%2d", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    GraphType *g;
    g=(GraphType *) malloc(sizeof(GraphType));
    init(g);
    for(int i=0; i<4; i++){
        insert_vertex(g, i);
    }
    insert_edge(g, 0, 1);
    insert_edge(g, 3, 2);
    print_adj_mat(g);
    return 0;
}
