#include <stdio.h>
#include <stdlib.h>


int main(){
	
	
	FILE *fp=fopen("input.txt","r");
	int nodeSayisi;
	int edgeSayisi;
	fscanf(fp,"%d %d",&edgeSayisi,&nodeSayisi);
	int*a=(int*)malloc(sizeof(int)*edgeSayisi); //kimden
	int*b=(int*)malloc(sizeof(int)*edgeSayisi); //kime
	int*c=(int*)malloc(sizeof(int)*nodeSayisi); //agirlik
	int*d=(int*)malloc(sizeof(int)*nodeSayisi); //dolasilan
	for(int i=0;i<=nodeSayisi;i++){
		d[i]=0;
	}
	int i=0;
	
	
	while(!feof(fp)){
		fscanf(fp,"%d %d %d", &a[i], &b[i], &c[i]);
		i++;
	}
	
	fclose(fp);
	
	for(int i=0;i<edgeSayisi;i++)
	{
		for(int j=0;j<edgeSayisi-1;j++)
		{
		
			if(c[j]>c[j+1])
			{
				int x=c[j];
				c[j]=c[j+1];
				c[j+1]=x;
				x=b[j];
				b[j]=b[j+1];
				b[j+1]=x;
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
		}
	}
	for(int i=0;i<edgeSayisi;i++){
		printf("edge:%d %d %d\n",a[i], b[i], c[i]);
	
	}
	
	
	i=0;
	int total=0;


	for (int j=0;j<edgeSayisi;j++){
		if(d[b[j]]==0 || d[a[j]]==0){
			printf("nodes:%d %d %d\n", a[j],b[j],c[j]);
			total+=c[j];
			d[b[j]]=1;d[a[j]]=1;
		}
	}
	printf("total:%d",total);
	return 0;
}







