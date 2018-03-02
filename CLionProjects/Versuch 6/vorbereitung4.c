#include <stdio.h>
#include "screen_transform.h"

void find_min_max(double *min, double *max, double *x, size_t size);

size_t get_number_of_lines_in_file(FILE *file);

int main(){
	
	size_t number;
	
	screen_transform_t trans;
	
	int i,k=0,j=0;
	
	double minx,maxx,miny,maxy;
	
	FILE *file,*file1;
	
	file = fopen("vorbereitung.data", "rb");
	
	file1 = fopen("Bildkoordinaten", "wb");
	
	if(file == NULL || file1 == NULL) printf("error\n");
	
	number = get_number_of_lines_in_file(file);
	
	double f[number*2],x[number],y[number];
	
	for(i=0; i<(2*number); i++){
		
		fscanf(file, "%lf", &f[i]);
		
	}
	
	for(i=0; i<(2*number);i++){
		
		if(i%2 != 0){	
		
		y[j] = f[i];
		
		j++;
		
		}
		
		else{
		
		x[k] = f[i];

		k++;
			
		}
	}
	
	k=0;
	j=0;

	find_min_max(&minx,&maxx,x,number);
	
	find_min_max(&miny,&maxy,y,number);

	
	screen_transform_set_screen_range_x (&trans, 0, 799);
	
	screen_transform_set_screen_range_y (&trans, 0, 599); 
	
	screen_transform_set_world_range_x (&trans, minx, maxx);

	screen_transform_set_screen_range_y(&trans,miny,maxy);
	
	for(i=0;i<14;i++){
	
	if(i%2 !=0){
	
	fprintf(file1,"%d\t",screen_transform_get_screen_y(&trans, f[i]));
	
	j++;
	
	}
	
	else{
		
		fprintf(file1,"%d\t",screen_transform_get_screen_x(&trans,f[i]));
		
	}
	
	
	}
	
	
}


//Funktionen

void find_min_max(double *min, double *max, double *x, size_t size){

	size_t i;
	
	*min = x[0];
	
	*max = x[0];
	
	for(i = 1; i < size; ++i){
		
	if(x[i] < *min){

	*min = x[i];
	}
	
	if(x[i] > *max){


	*max = x[i];
	}
}
} 


size_t get_number_of_lines_in_file(FILE *file)  {

	size_t cnt=0;
	
	char line[1024];

    while (fgets(line, sizeof(line), file) != NULL) cnt++;

    rewind(file);

    return cnt; 
	
	}


	
 