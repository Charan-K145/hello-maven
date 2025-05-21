#include<stdio.h>
#include<stdlib.h>
void findindegree(int n,int indegree[10],int a[10][10]);
void topologicalsort(int n,int a[10][10]);

int main(){
	int a[10][10],i,j,n;
	printf("enter the number of vertices:");
	scanf("%d",&n);
	
	printf("enter the adjacency matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("The adajacency matrix is:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	topologicalsort(n,a);
	return 0;
}
void findindegree(int n,int indegree[10],int a[10][10]){
	for(int j=1;j<=n;j++){
		indegree[j]=0;
		for(int i=1;i<=n;i++){
			indegree[j]+=a[i][j];
		}
	}
}

void topologicalsort(int n,int a[10][10]){
	int i,k=0,u,v,top=-1,t[100],stack[20],indegree[10];
	findindegree(n,indegree,a);
	
	for(i=1;i<=n;i++){
		if(indegree[i]==0){
			stack[++top]=i;
		}
	}
	
	while(top!=-1){
		u=stack[top--];
		t[k++]=u;
		for(v=1;v<=n;v++){
			if(a[u][v]==1){
				indegree[v]--;
				if(indegree[v]==0){
					stack[++top]=v;
				}
			}
		}
	}
	if(k!=n){
		printf("Graph has a cycle. Toplogical sorting is not possible\n");
	}else{
		printf("Toplogical sequence is\n");
		for(int i=0;i<k;i++){
			printf("%d\n",t[i]);
		}
	}
	printf("\n");
}
