#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int m,n,i,j;
	int flag=1; 
	char a[1000][1000];
	char num[1000][1000];
	int leishu=0;
	scanf("%d %d",&m,&n);
	getchar();//消除回车符的影响 
	while(1){
		//scanf("%d %d",&m,&n); 
		if(m==0&&n==0){
			break;
		}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%c",&a[i][j]);
			//getchar();//同理 
		}
		getchar();
		//printf("\n");
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]=='*'){
				num[i][j]=a[i][j];
				continue;
			}
			if(i-1>=0){     //看看上仨点啥情况 
				if(a[i-1][j]=='*'){
					leishu++;
				}
				if(j-1>=0&&a[i-1][j-1]=='*'){
					leishu++;
				}
				if(j+1<n&&a[i-1][j+1]=='*'){
					leishu++;
				} 
			}
			if(j-1>=0&&a[i][j-1]=='*'){  //看看左右两个点是不是雷 
				leishu++;
			}
			if(j+1<n&&a[i][j+1]=='*'){
				leishu++;
			}
			if(i+1<m){    //看看下面三个点有木有雷 
				if(a[i+1][j]=='*'){
					leishu++;
				}
				if(j-1>0&&a[i+1][j-1]=='*'){
					leishu++;
				}
				if(j+1<n&&a[i+1][j+1]=='*'){
					leishu++;
				} 
			}
			switch(leishu){
				case 0:
				num[i][j]='0';
				break;
				case 1:
				num[i][j]='1';
				break;
				case 2:
				num[i][j]='2';
				break;
				case 3:
				num[i][j]='3';
				break;
				case 4:
				num[i][j]='4';
				break;
				case 5:
				num[i][j]='5';
				break;
				case 6:
				num[i][j]='6';
				break;
				case 7:
				num[i][j]='7';
				break;
				case 8:
				num[i][j]='8';
				break;	
			}
			leishu=0;//重置雷数，进入下一次循环判断 
		}
	}
	/*if(flag==1){
		putchar('\n');
		printf("Field #1:\n");
	}*/
	if(flag==1){
		printf("Field #1:\n");
	}
	if(flag!=1){
		putchar('\n');
		printf("Field #%d:\n",flag);
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%c",num[i][j]);
		}
		if(i!=m-1){
			printf("\n");
	}
		//
		//getchar();
    }
    printf("\n");
	scanf("%d %d",&m,&n);
	getchar();
	flag++;
	}
	
	return 0;
}