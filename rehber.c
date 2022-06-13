 include<stdio.h>
# include<conio.h>  
# include<string.h>

FILE *dosya1;
FILE *dosya2;

	char ad[20], soyadi[20],ads[20],tel[15];
	char devam,s;
	int Z;
	void GIRIS(void);
    void DUZELT(void);


    void ARA(void);
   
   
   void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
}
   void MENU(){
system("cls");
   	
   	do{
   		gotoxy(10,6);
   		printf("ANA MENU\n");
   		
   			gotoxy(10,4);
   		printf("1-GİRİS\n");
   		
   			gotoxy(10,5);
   		printf("2-DUZELTME\n");
   		
   			gotoxy(10,8);
   		printf("3-SILME\n");
   		
   			gotoxy(10,9);
   		printf("4-ARAMA\n");
   		
   			gotoxy(10,10);
   		printf("5-LISTELEME\n");
   		
   			gotoxy(10,11);
   		printf("6-CIKIS\n");
   		
   		s=getch();
   		
   		switch(s){
   			case '1' : {
   				GIRIS();
				break;
			   }
			   case '2' : {
			   	DUZELT(); 
			   	break;
			   }
	            case '3' : {
			   	ARA();
				break;
			   }
			   
			   default:
			   	gotoxy(10,24);
			   	printf("yanlıs deger girildi");
                system("cls");
			   	break;}
		  
	   }
	   while(s!='6');
  
   
   }
   
   void GIRIS (){
   system("cls");
   	dosya1 = fopen("rehber.txt","w+");
    if(ferror(dosya1)){
    	fclose(dosya1);
    	dosya1 = fopen("rehber.txt","w+");
    	
	}
	
	do{
		gotoxy(5,5);
		printf("KAYIT GIRISI \n");
		
		gotoxy(5,6);
		printf("----------- \n");
		
		gotoxy(5,7);
		printf("ADI................:\n");
		
		scanf("%s",ad);
		
		gotoxy(5,8);
		printf("SOYADI................:\n");
		
		scanf("%s",soyadi);
				
		gotoxy(5,9);
		printf("TELEFON................:\n");
		
				scanf("%s",tel);
				
				fprintf(dosya1,"%s\n",ad);
				fprintf(dosya1,"%s\n",soyadi);
				fprintf(dosya1,"%s\n",tel);
				fflush(stdin);
				
				gotoxy(25,24);
				printf("devam edecek misiniz..........");
				devam=getch();
				}
	while(system("cls"),devam!='h');
	fclose(dosya1);
   }
   
   void DUZELT(){
  system("cls");
   	do{
   		dosya1=fopen("rehber.dat","r+");
   		dosya2=fopen("yedek.dat","w+");
   		gotoxy(1,1);
   		printf("düzeltilecek kaydın adı");
   		scanf("%s",ads);
   	system("cls");
   		
   		while(feof(dosya1)==0){
   			fflush(stdin);
   			fscanf(dosya1,"%s\n",ad);
   			fscanf(dosya1,"%s\n",soyadi);
   			fscanf(dosya1,"%s\n",tel);
   			if(strcmp(ad,ads)==0){
   				gotoxy(3,2);
   				printf("ADI\t:%s\n",ad);
   				   				gotoxy(3,3);
   				printf("SOYADI\t:%s\n",soyadi); 
   					gotoxy(3,4);
				   	printf("TELEFON\t:%s\n",tel);   
					   	gotoxy(3,5);		
			printf("=========================");   
							   	gotoxy(3,9);	
	printf("YENI \n");
	gotoxy(3,10);
				printf("ADI...............");   
				scanf("%s",ad);
					gotoxy(3,11);
	printf("SOYADI..............."); 								  
				scanf("%s",soyadi);
							gotoxy(3,12);
	printf("TELEFON..............."); 								  
				scanf("%s",tel);
 }
 fprintf(dosya2,"%s\n",ad);
 fprintf(dosya2,"%s\n",soyadi);
  fprintf(dosya2,"%s\n",tel);
}
gotoxy(25,24);
printf("devam edicek misiniz?");
devam=getch();
	   }
	   while(system("cls"),devam!='h');
	   fclose(dosya1);
	   fclose(dosya2);
	   unlink("rehber.dat");
	   do{
	   	dosya1 = fopen("rehber.dat","r+");
	   system("cls");
	   	while(feof(dosya1)==0){
	   		fflush(stdin);
	   	 fscanf(dosya1,"%s\n",ad);
 fscanf(dosya1,"%s\n",soyadi);
  fscanf(dosya1,"%s\n",tel);
  
  gotoxy(1,3);
  printf("adi soyadi telefon");
  
gotoxy(1,4);
printf("-----------------------------------------------------------------");
gotoxy(2,Z);
printf("%s\n",ad);
gotoxy(18,Z);
printf("%s\n",soyadi);

gotoxy(35,Z);
printf("%s\n",tel);
Z++;if(Z==22){
	printf("devam icin bir tusa basınız");
	devam=getch();
	Z=5;system("cls");
	continue;
}
		   }
		   gotoxy(10,24);
		   printf("liste sonu devam icin bir tusa basınız");
		   getch();
	   }while(system("cls"),kbhit());fclose(dosya1);
}
   void ARA(){
  system("cls");
   	do{
   		dosya1= fopen("rehber.dat","r+");
   		dosya2 = fopen("yedek.dat","wt");
   		gotoxy(1,1);
   		printf("aranan kayıdin adi.........");
   		scanf("%s",ads);
  system("cls");
   		while(feof(dosya1)==0){
   			fflush(stdin);
   			fscanf(dosya1,"%s\n",ad);
   			fscanf(dosya1,"%s\n",soyadi);
   			fscanf(dosya1,"%s\n",tel);
   			if(strcmp(ad,ads)==0){
   				gotoxy(3,2);
   				printf("ADI\t:%s\n",ad);
   				   				gotoxy(3,3);
   				printf("SOYADI\t:%s\n",soyadi); 
   					gotoxy(3,4);
				   	printf("TELEFON\t:%s\n",tel); 
			   }
		   }
   		gotoxy(25,24);
   		printf("devam edecek misiniz?....\n");
   		devam=getch();
   		
	   }while(system("cls"),devam!='h');
	   fclose(dosya1);
   };
void main(void){
system("cls");
	MENU();
}