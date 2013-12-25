#include<stdio.h>
#include<time.h>
#include<random>

struct aile
{
	int peynir_id;
	int peynir_oy;
};

int main()
{
	srand(time(NULL));
	struct aile aile_liste[10];
	
	FILE *file;
	char puanlarisim[20];
	errno_t errorcode = fopen_s(&file,"puanlar.txt","w");
	int aileDeger[10]={0,0,0,0,0,0,0,0,0,0};
	int toplamPuan[8] = {0,0,0,0,0,0,0,0};

	if(file == NULL)
	{
		printf("Dosya acilamadi...\n");
	}
	else
	{
		for (int i = 0,j = 0; i < 10; i++)
		{
			
			for (; j < 8; j++)
			{
				aile_liste[i].peynir_id = j;
				aile_liste[i].peynir_oy = rand()%7+1;
				if(aile_liste[i].peynir_id == j)
					toplamPuan[j] = toplamPuan[j] + aile_liste[i].peynir_oy;
				
				fprintf(file,"%d %d %d\n",i,j,aile_liste[i].peynir_oy);
				aileDeger[i] = aileDeger[i] + aile_liste[i].peynir_oy;
			}
			j = 0;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("aileDeger[%d] = %d\n",i,aileDeger[i]);
	}


	int minAile = aileDeger[0];
	int iDeger;

	for (int i = 1; i < 10; i++)
	{
		if(aileDeger[i] < minAile)
		{
			minAile = aileDeger[i];
			iDeger = i;
		}
	}
	
	int max = toplamPuan[0];
	int indis;

	for (int i = 0; i < 8; i++)
	{
		printf("toplam[%d] = %d\n",i,toplamPuan[i]);
		if(toplamPuan[i] >= max)
		{
			max = toplamPuan[i];
			indis = i;
		}
	}
	printf("En cok begenilen urun = %d ve kodu : %d\n",max,indis);
	printf("En az begenen aile = %d ve kodu : %d\n",minAile,iDeger);
	fclose(file);

	fopen_s(&file,"puanlar.txt","r+");

	FILE *file2;
	errno_t errorcode2 = fopen_s(&file2,"sonuclar.txt","w");
	fprintf(file2,"En cok begenilen urun : %d ve degeri : %d\n",indis,max);
	fprintf(file2,"En az begenen aile : %d ve kodu : %d\n",minAile,iDeger);



	int aileNo=0;
	int peynirNo=0;
	int peynirPuan=0;

	while(!feof(file))//dosyaya yazılmış veriyi okuma.
	{
		fscanf_s(file,"%d%d%d",&aileNo,&peynirNo,&peynirPuan);
		//printf("%d %d %d\n",aileNo,peynirNo,peynirPuan);
	}

	return 0;
}
