#include <stdio.h>
char cel[100][100];

void setPixel(int i, int j, int tbl){
	int c;
	for(c=j;c<j+tbl;c++){
		cel[i][c]='*';
	}
}

void naive(int xA, int yA, int xB, int yB, int tbl){
	int xi,yi;
	float m;
	if(xB==xA){
		m=0;
	}else{
		m=(yB-yA)/(xB-xA);
	}
	if(xA>xB){
		for(xi=xA;xi>=xB;xi--){
			yi=(m*(xi-xA))+yA;
			printf("%d\t%d\t%.02f\n",xi,yi,m);
			setPixel(xi,yi,tbl);
		}
	}else{
		for(xi=xA;xi<=xB;xi++){
			yi=(m*(xi-xA))+yA;
			printf("%d\t%d\t%.02f\n",xi,yi,m);
			setPixel(xi,yi,tbl);
		}
	}
}

void dda(int xA, int yA, int xB, int yB, int tbl){
	int xi,yi;
	float m;
	if(xB==xA){
		m=0;
	}else{
		m=(yB-yA)/(xB-xA);
	}
	yi=yA;
	if(xA>xB){
		for(xi=xA;xi>=xB;xi--){
			printf("%d\t%d\t%.02f\n",xi,yi,m);
			setPixel(xi,yi,tbl);
			yi=yi+m;
		}
	}else{
		for(xi=xA;xi<=xB;xi++){
			printf("%d\t%d\t%.02f\n",xi,yi,m);
			setPixel(xi,yi,tbl);
			yi=yi+m;
		}
	}
}
int max(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

void midPoint(int xA, int yA, int xB, int yB, int tbl){
	int Dx,Dy,d,incE,incNE,xi,yi;
	Dx=xB-xA;
	Dy=yB-yA;
	d=2*(Dy-Dx);
	incE=2*Dy;
	incNE=2*(Dy-Dx);
	if(xA>xB){
			xi=xB;
			yi=yA;
		printf("%d\t%d\t%.02f\n",xi,yi,d);
		setPixel(xi,yi,tbl);
		while(xi<xA){
			if(d<=0){
				d=d+incNE;
			}else{
				d=d+incE;
				yi++;
			}
			xi++;
			printf("%d\t%d\t%.02f\n",xi,yi,d);
			setPixel(xi,yi,tbl);
		}
	}else{
			xi=xA;
			yi=yA;
		printf("%d\t%d\t%.02f\n",xi,yi,d);
		setPixel(xi,yi,tbl);
		while(xi<xB){
			if(d<=0){
				d=d+incNE;
			}else{
				d=d+incE;
				yi++;
			}
			xi++;
			printf("%d\t%d\t%.02f\n",xi,yi,d);
			setPixel(xi,yi,tbl);
		}
	}
}
void free(){
	int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			cel[i][j]=' ';
		}
	}	
}	

int main(){
	system("cls");
	printf("Program Membuat Garis MK Grafika Komputer 2015\n");
	printf("[1] Naive\n");
	printf("[2] DDA\n");
	printf("[3] Mid Point\n");
	printf("[any] Exit\n");
	printf("Pilih menu : ");
	int menu,i,j;
	scanf("%d", &menu);
	
	int xA,xB,yA,yB,tbl;
	switch(menu){
		case 1:
			printf("Masukkan nilai Koordinat awal [x,y] : ");
			scanf("%d,%d",&yA,&xA);
			printf("Masukkan nilai Koordinat akhir [x,y] : ");
			scanf("%d,%d",&yB,&xB);
			printf("Masukkan ketebalan : ");
			scanf("%d",&tbl);
			printf("--------------------------------------\n");
			printf("xi\tyi\tm\n");
			printf("--------------------------------------\n");
			naive(xA,yA,xB,yB,tbl);
			printf("--------------------------------------\n");
			printf("Grafik\n");
			printf("--------------------------------------\n");
			for(i=0;i<=max(xA,xB)+tbl;i++){
				for(j=0;j<=max(yA,yB)+tbl;j++){
					if(cel[i][j]!='*'){
						printf("-");
					}else{
						printf("*");
					}
				}printf("\n");
			}	
			//free
			free();
		printf("\n");
		system("pause");
		
		main();

		break;
		case 2:
			printf("Masukkan nilai Koordinat awal [x,y] : ");
			scanf("%d,%d",&yA,&xA);
			printf("Masukkan nilai Koordinat akhir [x,y] : ");
			scanf("%d,%d",&yB,&xB);
			printf("Masukkan ketebalan : ");
			scanf("%d",&tbl);
			printf("--------------------------------------\n");
			printf("xi\tyi\tm\n");
			printf("--------------------------------------\n");
			dda(xA,yA,xB,yB,tbl);
			printf("--------------------------------------\n");
			printf("Grafik\n");
			printf("--------------------------------------\n");
			for(i=0;i<=max(xA,xB);i++){
				for(j=0;j<=max(yA,yB);j++){
					if(cel[i][j]!='*'){
						printf(" ");
					}else{
						printf("*");
					}
				}printf("\n");
			}	
			//free
			free();	
			
		printf("\n");
		system("pause");
		
		main();

		break;
		case 3:
			printf("Masukkan nilai Koordinat awal [x,y] : ");
			scanf("%d,%d",&xA,&yA);
			printf("Masukkan nilai Koordinat akhir [x,y] : ");
			scanf("%d,%d",&xB,&yB);
			printf("Masukkan ketebalan : ");
			scanf("%d",&tbl);
			printf("--------------------------------------\n");
			printf("xi\tyi\tm\n");
			printf("--------------------------------------\n");
			midPoint(xA,yA,xB,yB,tbl);
			printf("--------------------------------------\n");
			printf("Grafik\n");
			printf("--------------------------------------\n");
			for(i=0;i<=max(xA,xB);i++){
				for(j=0;j<=max(yA,yB);j++){
					if(cel[i][j]!='*'){
						printf(" ");
					}else{
						printf("*");
					}
				}printf("\n");
			}
			//free
			free();
			
		printf("\n");
		system("pause");
		
		main();

		break;
		default:
			system("exit");
		break;
	}
 return 0;	
}
/*  ferdilarahmi - 1202315*/

