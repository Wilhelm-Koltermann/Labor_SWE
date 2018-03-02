#include <stdio.h>
#include "screen_transform.h"
#include "polynom.h"
#include "simple_rgb_image.h"
#include <stdlib.h>
#include <math.h>

void find_min_max(double *min, double *max, double *x, size_t size);

size_t get_number_of_lines_in_file(FILE *file);

int main(){
	
	FILE *file,*file1;
	
	int image_width=600, image_height=800;
	
	screen_transform_t trans;
	
	simple_rgb_image_t image;
	
	file = fopen("labor.data", "rb");
	
	int i,j=0,k=0;
	
	size_t sizearray = get_number_of_lines_in_file(file);
	
	double minx,maxx,miny,maxy;
	
	double f[sizearray*2],x[sizearray],y[sizearray];
	
	
	for (i = 0; i < (sizearray*2); i++){
		
        fscanf(file, "%lf", &f[i] );
    }
	
	for(i=0;i < (sizearray*2);i++){

		if(i%2==0){
		
		x[j]=f[i]; 
		
		j++;
		
		}else{
	
		y[k]=f[i];
		
		k++;
	}
	
}
	
	find_min_max(&minx,&maxx,x,sizeof(x)/8);
	
	find_min_max(&miny,&maxy,y,sizeof(y)/8);
	
	
	screen_transform_set_screen_range_x (&trans, 0, 599);
	
	screen_transform_set_screen_range_y (&trans, 0, 799); 
	
	screen_transform_set_world_range_x (&trans, minx, maxx);

	screen_transform_set_world_range_y (&trans,  miny, maxy);
	
	if ((file1 = fopen("punktwolke.bmp", "wb")) == NULL) {

        printf("open error\n");

        return -1;
    }

    simple_rgb_image_init(&image, image_width, image_height);
	
	for(j=0; j<sizearray; j++){ 
	
	simple_rgb_image_put_pixel(&image,screen_transform_get_screen_x(&trans, x[j]),screen_transform_get_screen_y(&trans,y[j]),0,0,255);
	
	}
	
	simple_rgb_image_to_bitmap_stream(&image, file1);
	
	simple_rgb_image_clear(&image);
	
	fclose(file1);
	
	fclose(file);

}

//Funktionen

//Findet max und min einer Zahlenmenge

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

//Ermittelt Anzahl der Zeilen eines Files

size_t get_number_of_lines_in_file(FILE *file){
	
	size_t cnt = 0;
	
	char line[1024];
	
	while (fgets(line, sizeof(line), file) != NULL) cnt++;
	
	rewind(file);
	
	return cnt;
}

	