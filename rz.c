#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE* fp=fopen("rz.txt", "w");
    int n, A;
    scanf("%d%d", &n, &A);
    int a[n], b[100*n];
    int i, j;
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(i=0; i<n; i++){
        if(a[i]==1){
            for(j=100*i; j<(100*i)+50; j++){
                b[j]=A;
            }
            for(j=(100*i)+50; j<(100*i)+100; j++){
                b[j]=0;
            }
        }
        else{
            for(j=100*i; j<(100*i)+100; j++){
                b[j]=0;
            }
        }
    }
    for(i=0; i<100*n; i++){
		fprintf(fp, "%d %d\n", i, b[i]);
	}
	fclose(fp);
	return 0;
}