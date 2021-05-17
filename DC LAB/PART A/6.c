#include<stdio.h>
#include<stdlib.h>
#include<gd.h>
#include<omp.h>

int main()
{
	char *inputf = "a1.png";
	char *outputf = "a2.png";
	
	int color,x,y,i;
	int r,g,b,combined;
	
	FILE *fp;
	
	fp = fopen(inputf,"r");
	gdImagePtr img = gdImageCreateFromPng(fp);
	int width = gdImageSX(img);
	int height = gdImageSY(img);
	
	#pragma omp parallel for private(y,color,r,g,b)
	for(x=0;x<width;x++){
		#pragma omp critical
		{
			for(y=0;y<height;y++){
				color = gdImageGetPixel(img,x,y);
				r=gdImageRed(img,color);
				g=gdImageGreen(img,color);
				b=gdImageBlue(img,color);
				combined=0.3*r+0.59*g+0.11*b;
				color= gdImageColorAllocate(img, combined, combined, combined);
				gdImageSetPixel(img,x,y,color);
			}
		}
	}
	fp = fopen(outputf,"w");
	gdImagePng(img,fp);
	gdImageDestroy(img);
	fclose(fp);
}
