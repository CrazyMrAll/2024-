#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//char M,N;
	//scanf("%s%s",&M,&N);
	char a[50],b[50];
	int  c[50],d[50];
	int i,j,m,n;
	int x,y;
	int p,q,max,k,l,s,t;
	scanf("%s%s",a,b);
	m=strlen(a);
	n=strlen(b);
	for(i=0;i<=m-1;i++){
		if(a[i]>='A'){
			c[m-1-i]=10+a[i]-'A';
		}else{
			c[m-1-i]=a[i]-'0';
		}
	}
	for(i=0;i<=n-1;i++){
		if(b[i]>'A'){
			d[n-1-i]=10+b[i]-'A'; 
		}else{
			d[n-i-i]=b[i]-'0';
		}
	}
		for(i=0,max=c[0];i<=m-1;i++){
			if(c[i]>=max){
				max=c[i];
			}
			}
			 p=max+1;
		for(i=0,max=d[0];i<=n-1;i++){
			if(d[i]>=max){
				max=d[i];
			}
	}
		q=max+1;
		for(k=p;k<=36;k++){
			for(l=q;l<=36;l++){
				for(j=0,x=0;j<=m-1;j++){
					x=x+c[j]*(pow(k,j));
				}
				for(j=0,y=0;j<=n-1;j++){
					y=y+d[j]*(pow(l,j));
				}/*if(x==y){
					t=l;
					break;
					
				}
				
				
					
				
			}
			if(x==y){
				s=k;
				break;
				
			}
			
		}*/
			
	}
				if(x==y){
			for(i=0;i<=m-1;i++){
				printf("%c",a[i]);
			}
			printf(" (base %d)=",s);
			for(i=0;i<=n-1;i++){
				printf("%c",b[i]);
			} 
			printf(" (base %d)\n",t);
		//	printf("%s(base %d)=%s(base %d)\n",a,s,b,t); 
			
		}
		    break;
		}
	
		
	

		 if(x!=y){
			for(i=0;i<=m-1;i++){
				printf("%c",a[i]); 
			}
			printf(" is not equal to ");
			for(i=0;i<=n-1;i++){
				printf("%c",b[i]);
			}
			printf(" in any base 2..36\n");
			//printf("%s is not equal to %s in any base 2..36\n",a,b);
		}
	
	


	
	
	return 0;
}
