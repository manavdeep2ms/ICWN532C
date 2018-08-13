#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	FILE* fp=fopen("fsk.txt", "w");
	int n, i, j;
	scanf("%d", &n);
	float a[n];
	for(i=0; i<n; i++){
		scanf("%f", &a[i]);
	}
	float b[100*n];
	float old = 0, old1=0;
	for(i=0; i<n; i++){
		if(a[i]==0){
			for(j=100*i; j<(100*i)+100; j++){
				b[j]=sin(old1);
                old1 += 0.6;
			}
		}
		else if(a[i]==1){
			for(j=100*i; j<(100*i)+100; j++){
				b[j]=sin(old);
				old += 0.2;
			}
		}
	}
	for(i=0; i<100*n; i++){
		fprintf(fp, "%d %f\n", i, b[i]);
	}
	fclose(fp);
	return 0;
}
