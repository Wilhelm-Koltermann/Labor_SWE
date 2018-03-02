#include <stdio.h>

int main(){

	FILE *file;

	int c,i=0;
	
	int f[100];
	
	file = fopen("t.in","rb");
	
	//file1 = fopen("t.out","wb");
	
	if(file==NULL) printf("error\n");
	
	
	while(i<6){
		
		
	fscanf(file,"%d",&f[i]);
	
	i++;

	
	}
	
	printf("%d",f[5]);
	
}