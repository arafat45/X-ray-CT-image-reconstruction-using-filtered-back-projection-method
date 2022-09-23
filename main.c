#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define xpos 0.98
#define ypos 0.98
#define nx  128
#define ny  128
#define pi  3.14159265
#define n   256
#define m  256

FILE *fp_d,*fp_p;

void main(void){
    int i,j,k,kr,kabs,iy,ix,p;
	double thj,costhj,sinthj,cosdel;
	double s,t1,t2,y;
	double kei,delta,pin,a;
	double length1,length2;
	double spec1_r,spec2_r;
	double spec1,spec2;
	double phi[m+2],proj[m+2],conv[m+2];
	double fimg[nx+2][ny+2];

	char fname_d[12]="recon_d.csv";
	char fname_p[11]="proj_d.csv";

	delta=2.0*xpos/nx;   /* n-1*/
	a=2.0/m;     /* m-1 */                /* projection inside unit circle */
	pin = pi/n;    /* n-1*/
	kei = 1.0 / (m*m);  /* n-1*/

	for(iy=0;iy<=ny;iy++){
		for(ix=0;ix<=nx;ix++){
			fimg[ix][iy]=0.0;
		}
	}
	for(i=0;i<=m+1;i++){
		proj[i]=0.0;
		conv[i]=0.0;
		phi[i]=0.0;
	}

	/* filter function:Shepp filter */
	for(k=0;k<=m-1;k++){
		phi[k+1]=kei/(pi*a*a*(0.25-k*k));
	}
/* Projection data */             /* object inside unit circle */
	for(i=(int)(m/2);i>=0;i--){
		t1=a*((int)(m/2)-i);  //a=2.0/m
		t2=a*((int)(m/2)-i);
		spec1=0.5;
		spec1_r=0.4;
		spec2=0.75;
		spec2_r=0.2;
		if(t1<=spec1_r){
			length1= (sqrt(spec1_r*spec1_r - t1*t1));
			proj[i+1]=2.0*( spec1*length1 );
			if(t1<=spec2_r){
				length2= (sqrt(spec2_r*spec2_r - t1*t1));
				proj[i+1]=2.0*((spec2*length2)+spec1*(length1-length2));
			}
		}else{
			proj[i+1]=0.0;
		}
	}
	for(i=2;i<=(int)(m/2);i++){
		proj[(int)(m/2)+i]=proj[(int)(m/2)-(i)];
	}
if((fopen_s(&fp_p, fname_p ,"a")) != NULL){
		fprintf(stderr,"%s Open err !!",fname_p);
		_getch();exit(1);
	}
	for(i=1;i<=m;i++){
		fprintf(fp_p,"%4d , %4.2f\n",i,proj[i]);
	}
	fprintf(fp_p,"%% \n");
	fclose(fp_p);
/* Convolution */
	for(kr=1;kr<=m;kr++){
		for(k=1;k<=m;k++){
			if( (kr-k) >= 0){
				kabs=(int)(kr-k)+1;
			}else{
				kabs=(int)(k-kr)+1;
			}
			conv[kr]=conv[kr]+proj[k]*phi[kabs];
		}
	}

	if((fopen_s(&fp_d, fname_d, "a")) != NULL){
		fprintf(stderr,"%s Open err !!",fname_d);
		_getch();exit(1);
	}

//　Image reconstruction
	for(j=1;j<=(int)(2*n);j++){
		thj=(j-1)*pin;
		costhj=cos(thj);
		sinthj=sin(thj);
		cosdel=costhj*delta/a;

		for(iy=1;iy<=ny;iy++){
			y=-1.0*ypos + 2*ypos*(iy-1)/ny;  //-1 - 1
			s=(-xpos*costhj+sinthj*y+1.0)/a-cosdel;
			for(ix=1;ix<=nx;ix++){
				s = s + cosdel;
				p=(int)(s);
				if( (p > 0) && (p < m) ){
				fimg[ix][iy]=fimg[ix][iy]+((p+1-s)*conv[p]+(s-p)*conv[p+1]);
				}
			}
		}
	}
	for(iy=1;iy<=ny;iy++){
		for(ix=1;ix<=nx;ix++){
			fprintf(fp_d,"%6.4f,",fimg[ix][iy]/2.0);
		}
	fprintf(fp_d,"\n");
	}
	fclose(fp_d);
}

