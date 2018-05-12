#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

/*void hastaEkle();
void hastaTaburcu();
void ekranaYazdir(short,)*/
void listeYazdir();
void listeGuncelle();
void taburcuOlanHasta(short,char[],char[],short,char[]);

void hastaEkle(){
	
	ofstream hastaCikti("hastaListe.txt", ios::app);
	
	cout<<"Hasta girisi yapiniz. Cikis yapmak icin Ctrl + Z kombinasyonunu kullaniniz."<<endl;
	
	cout<<"Gerekenler : adSoday, kan, yas, telNo. "<<endl;
	
	cout<<"Ornek giris : AliKum AB+ 40 5********* ";
	
	srand(time(0));
	
	char adSoyad[15], kan[5], telNo[10];
	
	short yas, hastaNo = rand() %1000;
	
	cout<<endl<<hastaNo<<" ";
	
	cin>>adSoyad>>kan>>yas>>telNo;
	
	hastaCikti<< endl
	<<hastaNo<<" "<<adSoyad<<" "
	<<kan<<" "<<yas<<" "<<telNo;
	
	hastaCikti.close();
	
}

void hastaTaburcu(){
	
	char adSoyad[15], kan[5], telNo[10];
	
	short yas, hastaNo, sorgu;
	bool kontrol = 0;
	
	listeYazdir();
	
	ifstream hastaGirdi("hastaListe.txt", ios::in);
	
	ofstream taburcuCikti("temp.txt", ios::trunc);
	
	cout<<"\n Taburcu edilecek hastaNo'yu giriniz : ";
	cin>>sorgu;
	
	cout<<endl;
	
	while(hastaGirdi >> hastaNo >> adSoyad >> kan >> yas >> telNo ){
		
		if(hastaNo == sorgu ){
			
			cout<<adSoyad<<" isimli hasta bulundu. "<<endl;
			kontrol = 1;
			
		}else{
			
			taburcuOlanHasta(hastaNo, adSoyad, kan, yas, telNo);
			
		}
		
	}
	
	if(!kontrol){
		cout<<"\a"<<"Taburcu edilmek istenen hasta bulunamadi "<<endl;
		
	}
	
	else{
		listeGuncelle();
	}
	
	hastaGirdi.close();
	
	}

void ekranaYazdir(short h, char a[], char k[], short y , char t[]){
	
	cout<<setw(3)<<h<<setw(15)<<a<<setw(6)<<k<<setw(6)<<y<<setw(15)<<t<<endl;
	
}

void listeYazdir(){
	
	char adSoyad[15], kan[5], telNo[10];
	short yas, hastaNo, sorgu;
	
	ifstream hastaGirdi("hastaListe.txt", ios::in);
	
	while(!hastaGirdi.eof()){
		
		hastaGirdi >> hastaNo >> adSoyad >> kan >> yas >> telNo;
		
		ekranaYazdir(hastaNo, adSoyad, kan, yas, telNo);
		
	}
	
	hastaGirdi.close();
	
}

void listeGuncelle(){
	
	char kaydet;
	cout<<"Hasta taburcu edilsinmi ? (y/any) Seciminiz : ";
	cin>>kaydet;
	
	if(kaydet == 'y' || kaydet == 'Y'){
		
		ifstream stream1("temp.txt");
		ofstream stream2("hastaListe.txt");
		
		stream2<<stream1.rdbuf();
		
		
		
	}
	
	
}

void taburcuOlanHasta( short h, char a[], char k[], short y, char t[] ){
	
	ofstream taburcuCikti("temp.txt", ios::app);
	taburcuCikti<<endl<<h<<" "<<a<<" "<<k<<" "<<" "<<y<<" "<<t;
	
	taburcuCikti.close();
	
}




int main(){
	
	int islem = 0;
	
	char secim;
	
	do{
		do{
			string tablo=
			"Islem seciniz. "
			"1 - Hasta Ekleme "
			"2 - Hasta Taburcu "
			"3 - Hasta Listeleme ";
			
			cout<<tablo<<endl;
			
			cout<<endl
			<<"Seciminiz : ";
			cin>>islem;
			
			
			
		}while(islem !=1 && islem !=2 && islem !=3 );
		
		
		cout<<endl;
		
		switch(islem){
			
			case 1:
				hastaEkle();
				break;
				
			case 2:
				hastaTaburcu();
				break;
				
			case 3:
			    listeYazdir();
				break;	
			
		}
		
		cin.clear();
		
		cout<<endl<<
		"Baska Islem Yapma istermisiniz ?"
		"(y/any) Seciminiz"
		":" ;
		
		
		cin>>secim;
		cout<<endl;
		
	}while(secim=='y' || secim =='Y' );
	
	return 0;
}










