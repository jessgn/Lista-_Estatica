#include <stdio.h>
#include <stdio.h>

#define MAX_VETOR 5

typedef struct Vetor
{
    int dados [MAX_VETOR];
    int inicio, fim;
}Tipo_lista;

int insere_fim(Tipo_lista *v, int dado)
{
 if(v->fim < MAX_VETOR)
 {
 v->dados[v->fim] = dado;
 (v->fim)++;
 return 1;
 }
 return 0;
}

int iniciar_lista(Tipo_lista *v)
{
    v->inicio=0;
    v->fim=0;
}

int inserir_inicio(Tipo_lista *v, int dado)
{
    int i;
    i=(v->fim);
    if (v->fim!=0)//verifica se o vetor está vazio
    {
    if(v->fim < MAX_VETOR-1)
        {
            for(;v->fim > 0;i--)
            {
                v->dados[i]=v->dados[i+1];
            }
            v->dados[0]=dado;
            (v->fim)++;
            return 1;
        }
    }
    if(v->fim == 0)
    {
        v->dados[v->fim]=dado;
        (v->fim)++;
        return 1;
    }
    return 0;
}

int inserir_ordenado()
{

}

int excluir_inicio(Tipo_lista *v)
{
    int i, dado;
    if(v->fim != 0)//verifica se a lista está vazia
    {
        for(i=0; i < v->fim; i++)
            v->dados[i] = v->dados[i+1];
        (v->fim)--;
        return 1;
    }
    return 0;
}

int excluir_fim(Tipo_lista *v)
{
    if(v->fim != 0)//verifica se a lista está vazia
    {
        (v->fim)--;
        return 1;
    }
    return 0;
}

int excluir_especifico(Tipo_lista *v, int indice)
{
    int i, dado;
    if(v->fim != 0)//verifica se a lista está vazia
    {
        if((indice >=0) && (indice < v->fim))//verifica se o indice está correto
        {
            for(i=indice; i < v->fim; i++)
                v->dados[i] = v->dados[i+1];
            (v->fim)--;
        }
        return 1;
    }
    return 0;
}

int imprimir_lista(Tipo_lista V)
{
    int i;
    if(V.fim != 0)//verifica se a lista está vazia
    {
        for(i=0; i < V.fim; i++)
            printf("\n[%d]", V.dados[i]);
        printf("\n");
        return 1;
    }
    return 0;
}

int main()
{
    int i,s,dado,r;
    char confirma;
    Tipo_lista v;
    iniciar_lista(&v);
    for(s=0;s==0;)
    {
        printf("escolha uma op??o:\n");
        printf("[1]inserir item no inicio da lista\n");
        printf("[2]inserir item no final da ista\n");
        printf("[3]inserir item em um determinado indice da lsita\n");
        printf("[4]excluir item no inicio da lista\n");
        printf("[5]excluir item no final da lista\n");
        printf("[6]excluir item em determidado indice da lista\n");
        printf("[7]imprimir lista\n");
        printf("[8]sair\n");
        scanf("%d",&i);
        printf("%d",i);

        switch(i)
        {
            case 1: printf("qual o dado a ser inserido?\n");
                    scanf("%d",&dado);
                    r=inserir_inicio(&v,dado);
                    if(r==0)
                        {
                        printf("error!");
                        }else{
                        printf("ação realizada com exito!");
                        }
                    break;
            case 2: printf("qual o dado a ser inserido?\n");
                    scanf("%d",&dado);
                    r=insere_fim(&v,dado);
                    if(r==0)
                        {
                        printf("error!");
                        }else{
                        printf("ação realizada com exito!");
                        }
                    break;
            case 3: inserir_ordenado(&v);
                    break;
            case 4: printf("confirmar exclusao no inicio(s/n)?\n");
                    fflush(stdin);
                    scanf("%c",&confirma);
                    if(confirma==s)
                        r=excluir_inicio(&v);
                    if(r==0)
                        {
                        printf("error!");
                        }else{
                        printf("ação realizada com exito!");
                        }
                    break;
            case 5: printf("confirmar exclusao no fim(s/n)?\n");
                    fflush(stdin);
                    scanf("%c",&confirma);
                    if(confirma==s)
                        r=excluir_fim(&v);
                    if(r==0)
                        {
                        printf("error!");
                        }else{
                        printf("ação realizada com exito!");
                        }
                    break;
            case 6: printf("qual o indice a ser excluido(0~%d)?",MAX_VETOR-1);
                    scanf("%d",&dado);
                    if(dado < v.fim)
                        r=excluir_especifico(&v,dado);
                    if(r==0)
                        {
                        printf("error!");
                        }else{
                        printf("ação realizada com exito!");
                        }
                    break;
            case 7: imprimir_lista(v);
                    break;
            case 8: s=1;
                    break;
        }
    }
}
