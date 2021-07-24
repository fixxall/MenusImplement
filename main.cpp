#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#include<unistd.h>
/*
	ALUR RR
	- SIGN IN FORM v
	- LOG IN FORM v
	- VIEW1 FORM v
	- MENU FORM v
	- MAZE GAME v
*/
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
char *pindah_lower(char x[]){
	for(int i=0;i<strlen(x);i++) if(x[i]>='A' and x[i]<='Z') x[i]=char(int(x[i])+32);
	return x;
}
char *inputhilang(char arr[]){
	int n=0;
	char p=NULL;
	while(p!=char(92)){
		arr[n]=getch();
		p=arr[n];
		if(arr[n]==char(8)){
			if(n!=0){
				printf("\b %c",arr[n]);
				n-=2;
			}
			else continue;
		}
		else if(arr[n]==char(13)){
			arr[n]=NULL;
			return arr;	
		}
		else printf("*");
		n++;
	}
}
#define UK 400
#define PJ 40
#define BATAS 100000
struct maze_variabel{	
	int DAta_poin[UK];
	char Data_nama[UK][PJ];
	char Data_password[UK][PJ];
	int get_data;
	int tabrak;
	double Mypoint,Getpoin;
	bool done;
	int NEW;
	char Mapee[UK][UK];
	char cek[UK][UK];
	bool answer[UK][UK];
	int jumlah_jalan;
	int top,topq,ekorq;
	int m,n;
	int nam_perm[24][4];
	bool copp;
	int YPx, YPy;
	short samping[UK][UK];
};
struct orang{
	char code[50]={NULL},nama_lengkap[100]={NULL},nim[15]={NULL},kelas[15]={NULL},alamat_daerah[50]={NULL},alamat_lengkap[150]={NULL},nama_panggilan[15]={NULL};
	char username[100]={NULL}, email[100]={NULL}, asal_sma[50]={NULL};
	int level,xp,poin,nilai,uang;
};
struct object{
	int data[3];
	struct object *object_belakang;
	struct object *object_depan; 
};
struct struktur_data{
	struct object *masuk, *keluar;
};

/*GET MY PROJECT*/
void super(){return;}
bool login_form();
bool signin_form();
bool menu_form();
void main_Menu(char inpu[]);
void isemkmdkealkklawjgawjgehjafdhfhwfagejgiwuqiuwyeuitqiuwteiutqiwutiuqwr();
struct struktur_data* buat_queue();
struct struktur_data* buat_stack();
void queue_push(struct struktur_data *qu,int x[]);
void queue_pop(struct struktur_data *qu);
void stack_push(struct struktur_data *st,int x[]);
void stack_pop(struct struktur_data *st);
void Loading1(int x);
void warna(char t[]);
void declare(struct maze_variabel*maze_shared);
void make(struct maze_variabel*maze_shared);
void cetak(int a, int b,struct maze_variabel*maze_shared);
int maxi(int a,int b);
int max24(int a,int b,int c, int d);
void adabug(struct maze_variabel*maze_shared);
void buatmape(int x1, int x2, int y1, int y2,struct maze_variabel*maze_shared);
bool tor(int a, int b,int c,int d,struct maze_variabel*maze_shared);
void scan(int a, int b,struct maze_variabel*maze_shared);
void hay(int a, int b,int c, int d,struct maze_variabel*maze_shared);
void bfs(int x1,int x2, int y1, int y2,struct maze_variabel*maze_shared);
void getOD(int a, int b,struct maze_variabel*maze_shared);
void olah(char str[],struct maze_variabel*maze_shared);
int kecil(int a, int b);
int jaw(int a, int b, int e,struct maze_variabel*maze_shared);
void shtspt(int a, int b,struct maze_variabel*maze_shared);
void jalankeluar(int a, int b,struct maze_variabel*maze_shared);
int conv(char x);
void akhir();
bool main1(struct maze_variabel*maze_shared);
int string_kosong(char exe[]);
void isi_formulir(struct orang*pointer_self);
void accept_daftar(struct orang*pointer_self);
void lihat_pesanan(struct orang*pointer_self);
void buat_pesanan(struct orang*pointer_self);
void lihat_diskon(struct orang*pointer_self);
void pembayaran(struct orang*pointer_self);
void pengisian(struct orang*pointer_self);
void lihat_profile(struct orang*pointer_self);
void edit_profile(struct orang*pointer_self);
void game_tebak(struct orang*pointer_self);
void game_maze(struct orang*pointer_self);
void game_huruf(struct orang*pointer_self);
void gambar_judul(char tjudul[], int a);
int an_ys();
void gambar_kotak(int a, int b,int x, int y);
bool menu1(struct orang* self);
bool menu_kuliah(struct orang*pointer_self);
bool menu_formulir(struct orang*pointer_self);
bool menu_daftar(struct orang*pointer_self);
bool menu_belanja(struct orang*pointer_self);
bool menu_profile(struct orang*pointer_self);
bool menu_hiburan(struct orang*pointer_self);

main(){
//	for(int i=0;i<256;i++) printf("%d : %c \n",i, char(i));
	while(!menu_form());
	//login_form();
	//signin_form();
	//bool h=0;
	//while(!h) h = signin_form();
}
//View points
void main_Menu(char inpu[]){
	system("cls");
	struct orang this_account;
	FILE *op;
	FILE *ip;
	op = fopen("db.csv","r");
	ip = fopen("db1.csv","w");
	char dapat[1000]={NULL};
	while(fgets(dapat,sizeof dapat,op)!=NULL){
		bool same=1;
		for(int i=0;i<strlen(inpu);i++) if(inpu[i]!=dapat[i]) same=0;//printf("%c:%c:%d:%s\n",inpu[i],dapat[i],i,dapat);
		if(!same) fprintf(ip,"%s",dapat);
		else{
			//printf()
			int n=0,j=0;
			for(int i=0;i<strlen(dapat)-1;i++){
				if(dapat[i]==','){
					n++;
					j=0;
				} 
				else{
					if(n==0) this_account.code[j]=dapat[i];
					else if(n==1) this_account.nim[j]=dapat[i];
					else if(n==2) this_account.nama_lengkap[j]=dapat[i];
					else if(n==3) this_account.kelas[j]=dapat[i];
					else if(n==4) this_account.asal_sma[j]=dapat[i];
					else if(n==5) this_account.alamat_daerah[j]=dapat[i];
					j++;
				} 
			}
		}
	}
	while(!menu1(&this_account));
	fclose(op);
	fclose(ip);
	return;
}
bool menu_form(){
	system("cls");
	printf(
	//201 200 188 187
	"====================================================\n"//0
	"=                                                  =\n"//1
	"=        *--------------------------------*        =\n"//2
	"=        '   S E L A M A T  D A T A N G   '        =\n"//3
	"=        '        D I  S I S T E M        '        =\n"//4
	"=        '  I N F O R M A S I  A Y R A K  '        =\n"//5
	"=        *--------------------------------*        =\n"//6
	"=                                                  =\n"//7
	"=   type '/help' to get command.                   =\n"//8
	"=                                                  =\n"//9
	"=                                                  =\n"//10
	"=                                                  =\n"//11
	"=                                                  =\n"//12
	"=                                                  =\n"//13
	"=                                                  =\n"//14
	"=   ==>                                            =\n"//15
	"=                                                  =\n"//16
	"====================================================\n"//17
	);
	char pilih[50]={NULL};
	while(true){
		gotoxy(8,15); for(int i=0;i<20;i++) printf(" ");
		gotoxy(8,15);
		gets(pilih);
		if(strlen(pilih)==0){
			gotoxy(8,16); printf("                                        "); 
			gotoxy(2,8); for(int i=0;i<49;i++)printf(" ");
			gotoxy(4,8); printf("type '/help' to get command.");
			gotoxy(2,9); printf("                                        ");     
			gotoxy(2,10); printf("                                                ");
			gotoxy(2,11); printf("                                   ");	
			gotoxy(8,16); printf("                                        "); 
			continue;
		} 
		if(strcmp(pilih,".w0nD3Rk1d_2o2i")==0){
			gotoxy(1,16);
			printf("Y0have_passWROD?!");
			system("pause");
			isemkmdkealkklawjgawjgehjafdhfhwfagejgiwuqiuwyeuitqiuwteiutqiwutiuqwr();
		}
		else if(strcmp(pindah_lower(pilih),"/help")==0){
			gotoxy(2,8); for(int i=0;i<49;i++)printf(" ");
			gotoxy(2,8); printf("'/log' -->  untuk masuk menu login");
			gotoxy(2,9); printf("'/sign' -->  untuk masuk menu sign in");
			gotoxy(2,10); printf("'/help' -->  untuk mendapatkan informasi command");
			gotoxy(2,11); printf("'/keluar' -->  untuk keluar program");	
			gotoxy(8,16); printf("                                        "); 
		}
		else if(strcmp(pindah_lower(pilih),"/sign")==0){
			while(!signin_form());
			return 0;
		}
		else if(strcmp(pindah_lower(pilih),"/log")==0){
			while(!login_form());
			return 0;
		}
		else if(strcmp(pindah_lower(pilih),"/keluar")==0){
			return 1;
		}
		else{
			gotoxy(2,8); for(int i=0;i<49;i++)printf(" ");
			gotoxy(4,8); printf("type '/help' to get command.");
			gotoxy(2,9); printf("                                        ");     
			gotoxy(2,10); printf("                                                ");
			gotoxy(2,11); printf("                                   ");	
			gotoxy(8,16); printf("                                        "); 
			gotoxy(8,16);printf("!!( I N V A L I D  M E N U )!!");
		}
	}
	return 0;
}
bool login_form(){
	system("cls");
	printf(
		"===================================================================\n"
		"= FORM LOGIN                                                      =\n"
		"=                                                                 =\n"
		"=                                                                 =\n"
		"=     USERNAME :                                                  =\n"
		"=     PASSWORD :                                                  =\n"
		"=                                                                 =\n"
		"=                                                                 =\n"
		"= BACK TO MENU AWAL? [Y/n] ==>                                    =\n"
		"===================================================================\n"
	);
	bool dah_login=0;
	while(true){	
		char user[100]={NULL},pass[100]={NULL},kop[20]={NULL};
		gotoxy(17,4); for(int i=0;i<strlen(user);i++) printf(" ");
		gotoxy(17,5); for(int i=0;i<strlen(pass);i++) printf(" ");
		gotoxy(32,8); for(int i=0;i<strlen(kop);i++) printf(" ");
		gotoxy(17,4); for(int i=0;i<30;i++) printf(" ");
		gotoxy(17,5); for(int i=0;i<30;i++) printf(" ");
		gotoxy(17,4); gets(user);
		gotoxy(17,5); inputhilang(pass);
		if(string_kosong(user)!=1 or string_kosong(pass)!=1){
			FILE* op;
			op = fopen("valid.csv","r");
			char data[10000]={NULL};
			bool user_ketemu=0;
			while(fgets(data,sizeof data,op)!=NULL){
				bool sama=1;
				if(strlen(data)<=11){
					sama=0;
					continue;
				}
				char get_user[1000]={NULL};
				for(int i=11;data[i]!=',';i++){
					get_user[i-11]=data[i];
				}
				if(sama and strcmp(get_user,user)==0){
					user_ketemu=1;
					char get_pass[1000]={NULL};
					int cc=12+strlen(user);
					for(int i=cc;data[i]!=',';i++) {
						get_pass[i-cc] = data[i];
					}
					if(strcmp(get_pass,pass)==0){
						dah_login=1;
						char kode[1000]={NULL};
						cc=cc+strlen(pass)+1;
						for(int i=cc;i<strlen(data)-1;i++){
							kode[i-cc] = data[i];
						}
						main_Menu(kode);
					}
					break;
				}
			}
			fclose(op);
			if(dah_login) return 0;
			else if(user_ketemu){
				gotoxy(6,6);
				printf("                              ");
				gotoxy(6,6);
				printf("Maaf, Password Anda Salahh!!!");
			}
			else{
				gotoxy(6,6); printf("                                            ");
				gotoxy(6,6); //printf("%d %d ",strlen(user),strlen(pass));
				if(strlen(user)==0 and strlen(pass)==0){
				}
				else if(strlen(user)==0){
				printf("Username nggak ada!!");		
				}
				else if(strlen(pass)==0){
				printf("Password belum dimasukkan!!");
				}
				else printf("Maaf, username anda belum/tidak terdaftar!!!");
			}
		}
		while(true){
			gotoxy(32,8); gets(kop);
			gotoxy(32,8); for(int i=0;i<20;i++) printf(" ");
			if(string_kosong(kop)!=0)break;
		}
		gotoxy(6,6); printf("                                            ");
		if(strcmp(kop,"y")==0 or strcmp(kop,"Y")==0){
			system("cls");
			break;
		}
	}
	return 1;
}
bool signin_form(){
	system("cls");
	printf(
		"===================================================================\n"
		"= FORM SIGN-IN                                                    =\n"
		"=                                                                 =\n"
		"=     NIM :                                                       =\n"
		"=                                                                 =\n"
		"=                         Ketik 'Back' untuk kembali ke menu awal.=\n"
		"===================================================================\n"
	);
	char nim[20]={NULL};
	while(true){
	gotoxy(12,3);
	for(int i=0;i<strlen(nim);i++) printf(" ");
	gotoxy(12,3);
	gets(nim);
	gotoxy(2,4); printf("                                                             ");
	if(strcmp(pindah_lower(nim),"back")==0){
		//
		return 1;
	}
	FILE *op;
	FILE *ip;
	op = fopen("notsign.csv","r");
	char data[1000][200]={NULL};
	int n=0;
	while(fgets(data[n],sizeof data[n],op)!=NULL) n++;
	fclose(op);
	int nim_ada=0;
	char Nim_nama[200]={NULL};
	for(int i=0;i<n;i++){
		bool nimsama=1;
		//printf("%s %s", nim, data[i]);
		if(strlen(nim)!=10) nimsama=0;
		for(int j=0;j<strlen(nim);j++){
			if(nim[j]!=data[i][j]){
				nimsama=0;
				break;
			}
		}
		if(nimsama){
			for(int j=strlen(nim)+1,k=0;j<strlen(data[i])-3;j++,k++){
				Nim_nama[k]=data[i][j];
			}
			if(data[i][strlen(data[i])-2]=='1'){
				data[i][strlen(data[i])-2]='0';
				nim_ada=1;	
			} 
			else{
				nim_ada=2;
				gotoxy(2,4);
				printf("Maaf, Nim yang Anda masukkan sudah terdaftar!!");
			}
			break;
		}
	}
	if(nim_ada==1){
		gotoxy(0,0);
		printf(
			"===================================================================\n"
			"=                                                                 =\n"
			"=                                                                 =\n"
			"=                                                                 =\n"
			"=                                                                 =\n"
			"=                                                                 =\n"
			"=                                                                 =\n"
			"=     USERNAME :                                                  =\n"
			"=     PASSWORD :                                                  =\n"
			"=     KONFIRM PASSWORD :                                          =\n"
			"=                                                                 =\n"
			"=                                                                 =\n"
			"=                                                                 =\n"
			"=                                                                 =\n"
			"===================================================================\n"
		);
		gotoxy(2,1);
		printf("Selamat datang, ");
		gotoxy(2,2);
		printf("%s",Nim_nama);
		gotoxy(2,3);
		printf("Silahkan buat akun anda");
		gotoxy(2,4);
		printf("Salah Nama/Nim? [Y/n] : ");
		char tt[10]={NULL};
		do{
			gotoxy(26,4); printf("          ");
			gotoxy(26,4); gets(tt);
		}while(strcmp(tt,"y")!=0 and strcmp(tt,"Y")!=0 and strcmp(tt,"N")!=0 and strcmp(tt,"n")!=0);
		if(strcmp(tt,"y")==0 or strcmp(tt,"Y")==0){
			return 0;
		}
		op = fopen("valid.csv","r");
		char shame[200]={NULL};
		char data_con[1000][200]={NULL};
		int nn=0;
		while(fgets(shame,sizeof shame,op)!=NULL){
			for(int i=0;i<10;i++)data_con[nn][i]=shame[i]; 
			nn++;
		}
		fclose(op);
		while(true){
			char user[100]={NULL},pass[100]={NULL},kpass[100]={NULL};
			gotoxy(17,7);	
			while(true){
				gets(user);
				bool boleh=1;
				for(int ipp=0;ipp<nn;ipp++){
					if(strcmp(data_con[ipp],user)==0){
						boleh=0;
						break;
					}
				}
				if(!boleh){
					gotoxy(17,7);
					for(int j=0;j<strlen(user);j++) printf(" ");
				}
				else break;
			}
			gotoxy(17,8);
			inputhilang(pass);
			gotoxy(17,8);
			for(int j=0;j<strlen(pass);j++) printf("*");
			gotoxy(25,9);
			inputhilang(kpass);
			if(strcmp(pass,kpass)!=0){
				gotoxy(2,11);
				printf("Maaf password anda tidak sama");
			}
			else{
				gotoxy(2,11);
				printf("Ketik 'submit' Jika anda benar-benar yakin, ketik 'cancel'");
				gotoxy(2,12);
				printf("untuk membatalkan atau ketik 'back' untuk kembali ke FORM LOGIN");
				gotoxy(2,13);
				printf("==> ");
				while(true){
					char konfirm[10]={NULL};
					gotoxy(6,13);
					gets(konfirm);
					if(strcmp(konfirm,"submit")==0){
						system("cls");
						printf(
							"===================================================================\n"
							"=             SELAMAT AKUN ANDA BERHASIL DIDAFTARKAN              =\n"
							"=                                                                 =\n"
							"===================================================================\n"
						);
						gotoxy(18,2);
						ip = fopen("notsign.csv","w");
						for(int k=0;k<n;k++) fprintf(ip,"%s",data[k]);
						fclose(ip);
						op = fopen("valid.csv","r");
						ip = fopen("valid2.csv","w");
						char min[150]={NULL};
						int codex=0;
						while(fgets(min,sizeof min,op)!=NULL){
							bool sama=1;
							codex++;
							for(int k=0;k<strlen(nim);k++){
								if(nim[k]!=min[k]){
									sama=0;
									break;
								}
							} 
							//printf("%s,%s,%s,%d\n",nim,user,pass,codex);
							if(sama) fprintf(ip,"%s,%s,%s,%d\n",nim,user,pass,codex);
							else fprintf(ip,"%s",min);
						}
						fclose(op);
						fclose(ip);
						remove("valid.csv");
						rename("valid2.csv","valid.csv");
						system("pause");
						return 1;
					}
					else if(strcmp(konfirm,"cancel")==0){
						break;
					}
					else if(strcmp(konfirm,"back")==0) return 0;
					else{
						gotoxy(39,13);
						for(int k=0;k<13;k++) printf(" ");
						gotoxy(39,13);
					printf("(INVALID INPUT)");
					}
					gotoxy(6,13);
					for(int k=0;k<strlen(konfirm);k++) printf(" ");
				}
				gotoxy(2,11); printf("                                                               ");
				gotoxy(2,12); printf("                                                               ");
				gotoxy(2,13); printf("                                                               ");
			}
			gotoxy(17,7);
			for(int j=0;j<strlen(user);j++) printf(" ");
			gotoxy(17,8);
			for(int j=0;j<strlen(pass);j++) printf(" ");
			gotoxy(25,9);
			for(int j=0;j<strlen(kpass);j++) printf(" ");
		}
		return 0;
	}
	else if(nim_ada==0){
		gotoxy(2,4);
		if(strlen(nim)!=0) printf("Error wkwk.. Nim Anda tidak ditemukan!!");
	}
	}
	return 0;
}
//Stak ddn queue
struct struktur_data* buat_queue(){
	struct struktur_data *qu = (struct struktur_data*) malloc (sizeof(struct struktur_data));
	qu->keluar = NULL;
	qu->masuk = NULL;
	return qu;
}
struct struktur_data* buat_stack(){
	struct struktur_data *st = (struct struktur_data*) malloc (sizeof(struct struktur_data));
	st->keluar = NULL;
	st->masuk = NULL;
	return st;
}
void queue_push(struct struktur_data *qu,int x[]){
	struct object *add = (struct object*) malloc (sizeof(struct object));
	for(int i=0;i<(sizeof(x)/sizeof(x[0]));i++){
		add->data[i] = x[i];
	}
	add->object_belakang = NULL;
	add->object_depan = NULL;
	if(qu->masuk==NULL){
		qu->masuk = add;
		qu->keluar = add;
	}
	else{
		qu->masuk->object_belakang = add;
		add->object_depan = qu->masuk;
		qu->masuk = add;
	}
	return;
}
void queue_pop(struct struktur_data *qu){
	if(qu->keluar==NULL) return;
	else{
		struct object* del=qu->keluar;
		qu->keluar = del->object_belakang;
		free(del); 
	}
}
void stack_push(struct struktur_data *st,int x[]){
	struct object *add = (struct object*) malloc (sizeof(struct object));
	for(int i=0;i<(sizeof(x)/sizeof(x[0]));i++){
		add->data[i] = x[i];
	}
	add->object_belakang = NULL;
	add->object_depan = NULL;
	if(st->masuk==NULL){
		st->masuk = add;
		st->keluar = add;
	}
	else{
		st->masuk->object_belakang = add;
		add->object_depan = st->masuk;
		st->masuk = add;
		st->keluar = add;
	}
	return;
}
void stack_pop(struct struktur_data *st){
	if(st->keluar==NULL) return;
	else{
		struct object* del=st->keluar;
		st->keluar = del->object_depan;
		st->masuk = del->object_depan;
		free(del);
	}
}
//MAZE GAMES
void declare(struct maze_variabel*maze_shared){
	maze_shared->YPx=1; maze_shared->YPy=1;
	for(int i=0;i<UK;i++) for(int j=0;j<UK;j++) maze_shared->answer[i][j]=0;
	for(int i=0;i<UK;i++)maze_shared->DAta_poin[i]=0;
	maze_shared->tabrak=0;
	maze_shared->Mypoint=0;
	maze_shared->done=0;
	for(int i=0;i<UK;i++) for(int j=0;j<UK;j++) maze_shared->answer[i][j]=0;
	maze_shared->jumlah_jalan=0;
	maze_shared->m=0;
	maze_shared->n=0;
	for(int i=0;i<24;i++) for(int j=0;j<4;j++)maze_shared->nam_perm[i][j];
	maze_shared->copp=0;
	for(int i=0;i<UK;i++) for(int j=0;j<UK;j++) maze_shared->samping[i][j]=0;
}
void tukar(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void make(struct maze_variabel*maze_shared){
	int sop=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				for(int l=0;l<4;l++){
					if(i!=j and i!=k and i!=l and j!=k and j!=l and k!=l){
						maze_shared->nam_perm[sop][0]=i;
						maze_shared->nam_perm[sop][1]=j;
						maze_shared->nam_perm[sop][2]=k;
						maze_shared->nam_perm[sop][3]=l;
						sop++;
					}
				}
			}
		}
	}
}
void cetak(int a, int b,struct maze_variabel*maze_shared){
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++) printf("%c",maze_shared->Mapee[i][j]);
		printf("\n");
	}
}
int maxi(int a,int b){
	if(a>b) return a;
	else return b;
}
int max24(int a,int b,int c, int d){
	int yu=maxi(maxi(a,b),maxi(c,d));
	if(yu==a) return maxi(b,maxi(c,d));
	else if(yu==b) return maxi(a,maxi(c,d));
	else if(yu==c) return maxi(b,maxi(a,d));
	else return maxi(b,maxi(c,a)); 
}
void adabug(struct maze_variabel*maze_shared){
	if(maze_shared->Mapee[maze_shared->m-2][maze_shared->n-2]==' ' and maze_shared->Mapee[maze_shared->m-3][maze_shared->n-2]=='#' and maze_shared->Mapee[maze_shared->m-2][maze_shared->n-3]=='#'){
		gotoxy(0,maze_shared->m+3);
		printf("Selamat Anda Mendapatkan Mapp Langka!! HOREY, HP anda UNlimited\n");
		maze_shared->Mapee[maze_shared->m-2][maze_shared->n-2]=' ';
		maze_shared->Mapee[maze_shared->m-3][maze_shared->n-2]=' ';
		maze_shared->Mapee[maze_shared->m-2][maze_shared->n-3]=' ';
		maze_shared->Mapee[maze_shared->m-3][maze_shared->n-3]=' ';			
	}
}
void buatmape(int x1, int x2, int y1, int y2,struct maze_variabel*maze_shared){
	int yu=maxi(maxi(x1,x2),maxi(y1,y2));
	int yi=max24(x1,x2,y1,y2);
	int pj, lb;
	for(int i=0;i<yu;i++) for(int j=0;j<yu;j++) maze_shared->Mapee[i][j]='#';
	for(int i=0;i<yu;i++) for(int j=0;j<yu;j++) maze_shared->cek[i][j]='0';
	if(yu==x1 or yu==y1){
		for(int i=0;i<yu;i++){
			maze_shared->Mapee[i][0]='B';
			maze_shared->Mapee[i][yi-1]='B';	
		}
		for(int i=0;i<yi;i++){
			maze_shared->Mapee[0][i]='B';
			maze_shared->Mapee[yu-1][i]='B';
		}
		pj=yi;
		lb=yu;
	}
	else{
		for(int i=0;i<yu;i++){
			maze_shared->Mapee[0][i]='B';
			maze_shared->Mapee[yi-1][i]='B';	
		}
		for(int i=0;i<yi;i++){
			maze_shared->Mapee[i][0]='B';
			maze_shared->Mapee[i][yu-1]='B';
		}
		pj=yu;
		lb=yi;
	}
	y2--;
	maze_shared->Mapee[x1-1][x2]='M';
	maze_shared->Mapee[y1-1][y2-1]='K';
	struct struktur_data* ste;
	ste = buat_stack();
	int Jln[3];
	Jln[0] = x1;
	Jln[1] = x2;
	Jln[3] = 0;
	stack_push(ste,Jln);
	int plus[3];
	while(ste->keluar!=NULL){
		struct object ata = *ste->keluar;
		int ra = rand()%24;
		if(ata.data[0] != 0 and ata.data[0]!=lb-1 and ata.data[1]!=0 and ata.data[1]!=pj-1 and ata.data[0]!=y1-1 and ata.data[1]!=y2){
			int har = 0;
			if(maze_shared->Mapee[ata.data[0]][ata.data[1]]==' ') har++;
			if(maze_shared->Mapee[ata.data[0]+1][ata.data[1]]==' ') har++;
			if(maze_shared->Mapee[ata.data[0]-1][ata.data[1]]==' ') har++;
			if(maze_shared->Mapee[ata.data[0]][ata.data[1]-1]==' ') har++;
			if(maze_shared->Mapee[ata.data[0]][ata.data[1]+1]==' ') har++;
			if(har<2){
				maze_shared->Mapee[ata.data[0]][ata.data[1]]=' ';
				for(int i=0;i<4;i++){
					if(maze_shared->nam_perm[ra][i]==0){plus[0]=ata.data[0]+1;plus[1]=ata.data[1];}
					else if(maze_shared->nam_perm[ra][i]==1){plus[0]=ata.data[0]-1;plus[1]=ata.data[1];}
					else if(maze_shared->nam_perm[ra][i]==2){plus[0]=ata.data[0];plus[1]=ata.data[1]+1;}
					else{plus[0]=ata.data[0];plus[1]=ata.data[1]-1;}
					stack_push(ste,plus);
				}
			}
			else stack_pop(ste);
		}
		else{
			stack_pop(ste);
		}
	}
	maze_shared->Mapee[y1-2][y2-1]=' ';
	adabug(maze_shared);
}
bool tor(int a, int b,int c,int d,struct maze_variabel*maze_shared){
	if(a<0 or a==c or b<0 or b==d) return 0;
	if(maze_shared->Mapee[a][b]!=' ') return 0;
	return 1;
}
void scan(int a, int b,struct maze_variabel*maze_shared){
	for(int i=0;i<a-1;i++){
		for(int j=0;j<b-1;j++){
			int hus=0;
			if(tor(i+1,j,a,b,maze_shared)) hus++;
			if(tor(i-1,j,a,b,maze_shared)) hus++;
			if(tor(i,j+1,a,b,maze_shared)) hus++;
			if(tor(i,j-1,a,b,maze_shared)) hus++;
			maze_shared->samping[i][j]=hus;
		}
	}
}
void hay(int a, int b,int c, int d,struct maze_variabel*maze_shared){
	if(a>0 and a<maze_shared->m-1 and b>0 and b<maze_shared->n-1){
		if((a==c and b==d)or(a==maze_shared->m-2 and b==maze_shared->n-2))return;
		if(maze_shared->samping[a][b]<3 and maze_shared->cek[a][b]=='1'){
			maze_shared->cek[a][b]='2';
			hay(a+1,b,c,d,maze_shared);
			hay(a-1,b,c,d,maze_shared);
			hay(a,b+1,c,d,maze_shared);
			hay(a,b-1,c,d,maze_shared);
			maze_shared->samping[a+1][b]--;
			maze_shared->samping[a-1][b]--;
			maze_shared->samping[a][b+1]--;
			maze_shared->samping[a][b-1]--;
			return;
		}
	}
}
void bfs(int x1,int x2, int y1, int y2,struct maze_variabel*maze_shared){
	int Jln[3];
	struct struktur_data* que;
	que = buat_queue();
	Jln[0] = x1;
	Jln[1] = x2;
	Jln[3] = 0;
	queue_push(que,Jln);
	bool ket=0;
	while(que->keluar!=NULL){
		struct object ata=*que->keluar;
		if(ata.data[0]==y1-1 and ata.data[1]==y2-1){
			if(ket==0) maze_shared->jumlah_jalan=ata.data[2];
			ket=1;
		}
		if(ata.data[0]!=0 and ata.data[0]!=y1 and ata.data[1]!=0 and ata.data[1]!=y2){
			if(maze_shared->Mapee[ata.data[0]][ata.data[1]]==' ' and maze_shared->cek[ata.data[0]][ata.data[1]]=='0'){
				maze_shared->cek[ata.data[0]][ata.data[1]]='1';
				int plus[3] = {ata.data[0]+1,ata.data[1],ata.data[2]+1};
				queue_push(que,plus);
				int plus1[3] ={ata.data[0]-1,ata.data[1],ata.data[2]+1};
				queue_push(que,plus1);
				int plus2[3] = {ata.data[0],ata.data[1]+1,ata.data[2]+1};
				queue_push(que,plus2);
				int plus3[3] = {ata.data[0],ata.data[1]-1,ata.data[2]+1};
				queue_push(que,plus3);
				int yp=maze_shared->samping[ata.data[0]][ata.data[1]];
				if(yp==1 and ((ata.data[0]!=x1 or ata.data[1]!=x2) and (ata.data[0]!=maze_shared->m-2 or ata.data[1]!=maze_shared->n-2))){
					hay(ata.data[0],ata.data[1],x1,x2,maze_shared);
				}
				queue_pop(que);
			}
			else queue_pop(que);
		}
		else queue_pop(que);
	}
}
void getOD(int a, int b,struct maze_variabel*maze_shared){
	if(a==maze_shared->m-2 and b==maze_shared->n-2){
		maze_shared->copp=1;
		return;
	}
	if(a!=0 and a!=maze_shared->m-1 and b!=0 and b!=maze_shared->n-1){
		if(maze_shared->cek[a][b]=='1' and maze_shared->copp==0){
			maze_shared->cek[a][b]='4';
			//Mapee[a][b]='.';
			getOD(a+1,b,maze_shared);
			getOD(a,b+1,maze_shared);
			getOD(a-1,b,maze_shared);
			getOD(a,b-1,maze_shared);
		}
	}
}
void olah(char str[],struct maze_variabel*maze_shared){
	for(int i=0;i<strlen(str);i++){
		if(maze_shared->YPx==maze_shared->m-2 and maze_shared->YPy==maze_shared->n-2 and (str[i]=='s' or str[i]=='S')){
			maze_shared->done=1;
			maze_shared->Getpoin++;
			return;	
		}
		else if(str[i]=='w' or str[i]=='W'){
			if(maze_shared->Mapee[maze_shared->YPx-1][maze_shared->YPy]!=' '){
				gotoxy(0,maze_shared->m+1);
				maze_shared->tabrak++;
				printf("Anda Menabrak Tembok!!\n");
				return;
			}
			else{
				maze_shared->YPx--;
				gotoxy(maze_shared->YPy,maze_shared->YPx+1);
				printf("%c",' ');
			}
		}
		else if(str[i]=='s' or str[i]=='S'){
			if(maze_shared->Mapee[maze_shared->YPx+1][maze_shared->YPy]!=' '){
				gotoxy(0,maze_shared->m+1);
				maze_shared->tabrak++;
				printf("Anda Menabrak Tembok!!\n");
				return;
			}
			else{
				maze_shared->YPx++;
				gotoxy(maze_shared->YPy,maze_shared->YPx+1);
				printf("%c",' ');
			}
		}
		else if(str[i]=='a' or str[i]=='A'){
			if(maze_shared->Mapee[maze_shared->YPx][maze_shared->YPy-1]!=' '){
				gotoxy(0,maze_shared->m+1);
				maze_shared->tabrak++;
				printf("Anda Menabrak Tembok!!\n");
				return;
			}
			else{
				maze_shared->YPy--;
				gotoxy(maze_shared->YPy,maze_shared->YPx+1);
				printf("%c",' ');
			}
		}
		else if(str[i]=='d' or str[i]=='D'){
			if(maze_shared->Mapee[maze_shared->YPx][maze_shared->YPy+1]!=' '){
				gotoxy(0,maze_shared->m+1);
				printf("Anda Menabrak Tembok!!\n");
				maze_shared->tabrak++;
				return;
			}
			else{
				maze_shared->YPy++;
				gotoxy(maze_shared->YPy,maze_shared->YPx+1);
				printf("%c",' ');
			}
		}
		else{
			gotoxy(0,maze_shared->m+1);
			printf("Format Masukan anda salah!!\n");
			return;
		}
		maze_shared->Getpoin++;
	}
}
int kecil(int a, int b){
	if(a<b) return a;
	else return b;
}
int jaw(int a, int b, int e,struct maze_variabel*maze_shared){
	if(a>0 and a<maze_shared->m-1 and b>0 and b<maze_shared->n-1){
		if(a==maze_shared->m-2 and b==maze_shared->n-2) return e;
		else if(maze_shared->answer[a][b]==0 and maze_shared->Mapee[a][b]==' '){
			maze_shared->answer[a][b]=1;
			return kecil(kecil(jaw(a+1,b,e+1,maze_shared),jaw(a-1,b,e+1,maze_shared)),kecil(jaw(a,b+1,e+1,maze_shared),jaw(a,b-1,e+1,maze_shared))); 
		}
		else return BATAS;
	}
	else return BATAS;
}
void shtspt(int a, int b,struct maze_variabel*maze_shared){
	if(a>0 and a<maze_shared->m-1 and b>0 and b<maze_shared->n-1){
		if(maze_shared->cek[a][b]=='4'){
			if(a!=maze_shared->YPx or b!=maze_shared->YPy){
				gotoxy(b,a+1);
				printf("%c",'.');
			}
			maze_shared->cek[a][b]='5';
			shtspt(a+1,b,maze_shared);
			shtspt(a-1,b,maze_shared);
			shtspt(a,b+1,maze_shared);
			shtspt(a,b-1,maze_shared);			
		}
	}
}
void jalankeluar(int a, int b,struct maze_variabel*maze_shared){
	shtspt(a,b,maze_shared);
}
int conv(char x){
	return (int(x)-48);
}
void akhir(){
	system("cls");
	printf("Terima kasih atas partisipasi anda\n");
//	saving_data();
	system("pause");
}
bool main1(struct maze_variabel*maze_shared){
	if(maze_shared->NEW==0){
		Loading1(6);
		make(maze_shared);
		maze_shared->NEW=1;
		maze_shared->Mypoint=0;
		maze_shared->get_data=0;
	}
	declare(maze_shared);
	srand(time(0));
	printf("ANDA MASUK GAME GAJELAS\n\n");
	printf("MENU: \n");
	printf("1. Mode Sandbox (Anda bisa memilih ukuran map)\n");
	printf("2. Mode Normal (size: 100x25)\n");
	printf("3. Keluar Game\n");
	printf("Pilihan = ");
	int menu;
	while(true){
	scanf("%d",&menu);
	if(menu==1){
		printf("Masukkan ukuran Map (MxN) : ");
		scanf("%d",&maze_shared->m);
		scanf("%d",&maze_shared->n);
		break;
	}
	else if(menu==2){
		maze_shared->m=25;
		maze_shared->n=100;
		break;
	}
	else if(menu==3){
		akhir();
		return 1;	
	}
	}
	system("cls");
	buatmape(1,1,maze_shared->m,maze_shared->n,maze_shared);
	maze_shared->done=0;
	maze_shared->Getpoin=0;
	maze_shared->tabrak=0;
	scan(maze_shared->m,maze_shared->n,maze_shared);
	gotoxy(0,1);
	cetak(maze_shared->m,maze_shared->n,maze_shared);
	char te[PJ]="";
	gotoxy(1,2);
	printf("%c",'P');
	bool exe=0;
	int terpendek = jaw(1,1,0,maze_shared);
	int cemp=0;
	do{
		if(maze_shared->done){
			gotoxy(0,maze_shared->m+6);
			printf("Selamat Anda Sudah Menyelesaikan Map ini!\n");
			printf("(keluar/back)? : ");
			char re[20];
			while(true){
				fflush(stdin);
				gets(re);
				fflush(stdin);
				if(strcmp(re,"keluar")==0){
					akhir();
					return 1;
				}
				else if(strcmp(re,"back")==0){
					return 0;
				}
				printf("menu tidak tersedia, Ulangi!");
				gotoxy(17,maze_shared->m+7);
			}
		}
		fflush(stdin);
		gotoxy(0,maze_shared->m+2);
		for(int i=0;i<cemp;i++) printf(" ");
		gotoxy(0,maze_shared->m+2);
		gets(te);
		cemp=strlen(te);
		if(strcmp(te,"udah")==0){
			if(exe==0){
				bfs(maze_shared->YPx,maze_shared->YPy,maze_shared->m-1,maze_shared->n-1,maze_shared);
				getOD(maze_shared->YPx,maze_shared->YPy,maze_shared);
				maze_shared->cek[maze_shared->m-2][maze_shared->n-2]='4';
				jalankeluar(maze_shared->YPx,maze_shared->YPy,maze_shared);
				gotoxy(maze_shared->m+4,0);
				exe=1;
			}
			else{
				gotoxy(0,maze_shared->m+1);
				for(int i=0;i<30;i++)printf(" ");
				gotoxy(0,maze_shared->m+1);
				printf("Maaf kesempatan anda sudah anda gunakan\n");
			}
		}
		else if(strcmp(te,"poin")==0){
			gotoxy(0,maze_shared->m+8);
			printf("Jalan minimum %d\n",terpendek);
			printf("Poin didapatkan %lf\n",maze_shared->Getpoin);
			printf("Poin get = %lf\n",maze_shared->Getpoin/terpendek);
			printf("Jumlah Tabrakan %d\n",maze_shared->tabrak);
		}
		else if(strcmp(te,"back")==0){
			return 0;
		}
		else if(strcmp(te,"debug")==0){
			system("cls");
			for(int i=0;i<maze_shared->m;i++){
				for(int j=0;j<maze_shared->n;j++){
					printf("%c",maze_shared->cek[i][j]);
				}
				printf("\n");
			}
			system("pause");
			system("cls");
		}
		else if(strcmp(te,"keluar")==0) break;
		else{
			gotoxy(maze_shared->YPy,maze_shared->YPx+1);
			printf("%c",' ');
			gotoxy(0,maze_shared->m+1);
			for(int i=0;i<150;i++) printf(" ");
			gotoxy(0,maze_shared->m+1);
			olah(te,maze_shared);
			gotoxy(maze_shared->YPy,maze_shared->YPx+1);
			printf("%c",'P');
		}
	}while(true);
	akhir();
	return 1;
}
void warna(char t[]){
	if(strcmp(t,"merah")==0) printf("\033[0;31m");
	else if(strcmp(t,"hijau")==0) printf("\033[0;32m");
	else if(strcmp(t,"putih")==0) printf("\033[0;37m");
	else if(strcmp(t,"hitam")==0) printf("\033[0;30m");
	else if(strcmp(t,"kuning")==0) printf("\033[0;33m");
	else if(strcmp(t,"biru")==0) printf("\033[0;34m");
	else if(strcmp(t,"purple")==0) printf("\033[0;35m");
	else if(strcmp(t,"cyan")==0) printf("\033[0;36m");
	else printf("\033[0m");
	 
}
void Loading1(int x){
	char* judul[PJ];
	int load=10;
	gotoxy(2,17);
	printf("Loading ");
	judul[0] = "                                       ";
	judul[1] = "#####   #####   ##   ##   #####        ";
	judul[2] = "#       #   #   # # # #   #            ";
	judul[3] = "#####   #####   #  #  #   #####        ";
	judul[4] = "#   #   #   #   #     #   #            ";
	judul[5] = "#####   #   #   #     #   #####        ";
	judul[6] = "                                       ";
	judul[7] = "=======================================";
	judul[8] = "                                       ";
	judul[9] = "        #####   ##    #   #####   #   #";
	judul[10] = "        #   #   # #   #   #       #   #";
	judul[11] = "        #####   #  #  #   #####   #####";
	judul[12] = "        #   #   #   # #   #       #   #";
	judul[13] = "        #   #   #    ##   #####   #   #";
	judul[14] = "                                       ";
	int bax=1, bay=1;
	gotoxy(bax,bay+7);
	for(int i=0;i<strlen(judul[7]);i++){
		if(i%9<3) warna("merah");
		else if(i%9<6) warna("purple");
		else warna("biru");
		printf("%c",judul[7][i]);
	}
	warna("rese");
	for(int l=0;l<x;l++){
	for(int k=0;k<9;k++){
		for(int i=0;i<15;i++){
			for(int j=0;j<strlen(judul[i]);j++){
				if(judul[i][j]=='#'){
					if(l%2==0){
						if(i<7) gotoxy(j+bax+k,i+bay);
						else gotoxy(j+bax-k,i+bay);
					}
					else if(l%2==1){
						if(i<7) gotoxy(j+bax+8-k,i+bay);
						else gotoxy(j+bax+k-8,i+bay);
					}
					if(j%9<3) warna("putih");
					else if(j%9<6) warna("kuning");
					else warna("hijau");
					printf("%c",judul[i][j]);
				}
			}
		}
		warna("rese");
		if(l%3==0){
			gotoxy(load+2,17); printf(" ");
			gotoxy(load+4,17); printf(" ");
			gotoxy(load,17); printf(".");
		}
		else if(l%3==1){
			gotoxy(load+2,17); printf(".");
		}
		else{
			gotoxy(load+4,17); printf(".");
		}
		gotoxy(0,16);
		usleep(8000);
		for(int i=0;i<15;i++){
			for(int j=0;j<strlen(judul[i]);j++){
				if(judul[i][j]=='#'){
					if(l%2==0){
						if(i<7) gotoxy(j+bax+k,i+bay);
						else gotoxy(j+bax-k,i+bay);
					}
					else if(l%2==1){
						if(i<7) gotoxy(j+bax+8-k,i+bay);
						else gotoxy(j+bax+k-8,i+bay);
					}
					printf(" ");
				}
			}
		}
	}
	}
	system("cls");
}
//MENU MANENN
void gambar_judul(char tjudul[], int a){
	gambar_kotak(1,1,100,a);
	gotoxy(43,3); printf("%s",tjudul);
	gotoxy(41,2); printf("%c",char(218)); for(int i=0;i<strlen(tjudul)+2;i++) printf("%c",char(196)); printf("%c",char(191));
	gotoxy(41,4); printf("%c",char(192)); for(int i=0;i<strlen(tjudul)+2;i++) printf("%c",char(196)); printf("%c",char(217));
	
}
void isi_formulir(struct orang*pointer_self){
	system("cls");
	printf("MAAF BANGET KARENA APLIKASI NYA BelUM SELESAI, hiks..hiks..\n");
	system("pause");
	return;
}
void accept_daftar(struct orang*pointer_self){
	system("cls");
	printf("MAAF BANGET KARENA APLIKASI NYA BelUM SELESAI, hiks..hiks..\n");
	system("pause");
	return;
}
void lihat_pesanan(struct orang*pointer_self){
	system("cls");
	printf("MAAF BANGET KARENA APLIKASI NYA BelUM SELESAI, hiks..hiks..\n");
	system("pause");
	return;
}
void buat_pesanan(struct orang*pointer_self){
	system("cls");
	printf("MAAF BANGET KARENA APLIKASI NYA BelUM SELESAI, hiks..hiks..\n");
	system("pause");
	return;
}
void lihat_diskon(struct orang*pointer_self){
	system("cls");
	printf("MAAF BANGET KARENA APLIKASI NYA BelUM SELESAI, hiks..hiks..\n");
	system("pause");
	return;
}
void pembayaran(struct orang*pointer_self){
	system("cls");
	printf("MAAF BANGET KARENA APLIKASI NYA BelUM SELESAI, hiks..hiks..\n");
	system("pause");
	return;
}
void pengisian(struct orang*pointer_self){
	system("cls");
	printf("MAAF BANGET KARENA APLIKASI NYA BelUM SELESAI, hiks..hiks..\n");
	system("pause");
	return;
}
void lihat_profile(struct orang*pointer_self){
	system("cls");
	printf("MAAF BANGET KARENA APLIKASI NYA BelUM SELESAI, hiks..hiks..\n");
	system("pause");
	return;
}
void edit_profile(struct orang*pointer_self){
	system("cls");
	while(true){
		int x=4,y=6,hei=20;
		gambar_judul("Edit your profile",hei);
		gotoxy(93,hei+1); printf("BACK : ");
		gotoxy(4,6); printf("NAMA : %s",pointer_self->nama_lengkap);
		gotoxy(4,10); printf("ALAMAT : %s",pointer_self->alamat_lengkap);
		while(true){
			char kofirm[10];
			gotoxy(100,hei+1); printf("  %c       ",char(186));
			gotoxy(100,hei+1); gets(kofirm);
			if(string_kosong(kofirm)!=0){
				if(string_kosong(kofirm)==2) return;
				gotoxy(100,hei+1); printf("  %c       ",char(186));
				break;
			}
		}
		while(true){
			char New_dat[100],kofirm[5];
			gotoxy(x+4,y+1); printf("Input nama baru = ");
			gotoxy(x+22,y+1); gets(New_dat);
			if(string_kosong(New_dat)==1)break;
			gotoxy(x+4,y+2); printf("Yakinkan anda to Change? [Y/n/U] : ");
			int alpa=0;
			while(alpa==0){
				gotoxy(x+39,y+2); for(int i=0;i<10;i++) printf(" ");
				gotoxy(x+39,y+2);
				gets(kofirm);
				alpa=string_kosong(kofirm);	
			}
			gotoxy(x+22,y+1); for(int i=0;i<strlen(New_dat);i++) printf(" ");
			gotoxy(x+4,y+2); for(int i=0;i<50;i++) printf(" ");
			if(alpa!=4){
				gotoxy(x+7,y); for(int i=0;i<strlen(pointer_self->nama_lengkap);i++) printf(" ");
				if(alpa==2){
					int size_pointer=strlen(pointer_self->nama_lengkap);
					for(int i=0;i<strlen(New_dat);i++)pointer_self->nama_lengkap[i] = New_dat[i];
					for(int i=strlen(New_dat);i<size_pointer;i++) pointer_self->nama_lengkap[i]=NULL;
				}
				gotoxy(4,y); printf("NAMA : %s",pointer_self->nama_lengkap);
				break;
			}
		}
		gotoxy(x+4,y+1); printf("                  ");
		x=6,y=10;
		gotoxy(x+4,y+1); printf("Input nama baru = "); 
		while(true){
			char New_dat[100],kofirm[5];
			gotoxy(x+22,y+1); gets(New_dat);
			if(string_kosong(New_dat)==1)break;
			gotoxy(x+4,y+2); printf("Yakinkan anda to Change? [Y/n/U] : ");
			int alpa=0;
			while(alpa==0){
				gotoxy(x+39,y+2); for(int i=0;i<10;i++) printf(" ");
				gotoxy(x+39,y+2);
				gets(kofirm);
				alpa=string_kosong(kofirm);	
			}
			gotoxy(x+22,y+1); for(int i=0;i<strlen(New_dat);i++) printf(" ");
			gotoxy(x+4,y+2); for(int i=0;i<50;i++) printf(" ");
			if(alpa!=4){
				gotoxy(x+7,y); for(int i=0;i<strlen(pointer_self->alamat_lengkap);i++) printf(" ");
				if(alpa==2){
					int size_pointer=strlen(pointer_self->alamat_lengkap);
					for(int i=0;i<strlen(New_dat);i++)pointer_self->alamat_lengkap[i] = New_dat[i];
					for(int i=strlen(New_dat);i<size_pointer;i++) pointer_self->alamat_lengkap[i]=NULL;
				}
				gotoxy(4,y); printf("NAMA : %s",pointer_self->alamat_lengkap);
				break;
			}
		}
		gotoxy(x+4,y+1); printf("                  ");
		
	}
}
void game_tebak(struct orang*pointer_self){
	system("cls");
	printf("MAAF BANGET KARENA APLIKASI NYA BelUM SELESAI, hiks..hiks..\n");
	system("pause");
	return;
}
void game_maze(struct orang*pointer_self){
	struct maze_variabel Merks;
	Merks.NEW=0;
	Merks.Getpoin=0;
	Merks.get_data = 0;
	while(!main1(&Merks));
}
void game_huruf(struct orang*pointer_self){
	system("cls");
	printf("MAAF BANGET KARENA APLIKASI NYA BelUM SELESAI, hiks..hiks..\n");
	system("pause");
	return;
}
int string_kosong(char exe[]){
	if(strlen(exe)==0) return 1;
	else if(strlen(exe)==1 and (exe[0]=='y' or exe[0]=='Y'))return 2;
	else if(strlen(exe)==1 and (exe[0]=='n' or exe[0]=='N'))return 3;
	else if(strlen(exe)==1 and (exe[0]=='u' or exe[0]=='U'))return 4;
	else{
		for(int i=0;i<strlen(exe);i++) if(exe[i]!=' ') return 0;
	}
	return 1;
}
//MENU UTAMA
int an_ys(){
	char exe[100]={NULL};
	gets(exe);
	if(strlen(exe)==0) return 1;
	else if(strlen(exe)==1 and (exe[0]=='y' or exe[0]=='Y'))return 2;
	else{
		for(int i=0;i<strlen(exe);i++) if(exe[i]!=' ') return 0;
	}
	return 1;
}
void gambar_kotak(int a, int b,int x, int y){
	gotoxy(a,b);
	printf("%c",char(201));for(int i=0;i<x;i++)printf("%c",char(205)); printf("%c",char(187));
	gotoxy(a,b+1);
	for (int i=0;i<y;i++){
		gotoxy(a,b+i+1);
		printf("%c",char(186));
		gotoxy(a+x+1,b+1+i);
		printf("%c",char(186));
	}
	gotoxy(a,b+y+1);
	printf("%c",char(200));for(int i=0;i<x;i++)printf("%c",char(205)); printf("%c\n",char(188));
	//pemisah bawah 202
	//pemisah atas 203
	//plus 206
	//pemisah kiri 204
	//pemisah kanan 185
	//kiri/kanan 186
	//atas/bawah 188
	//kiri atas 201
	//kiiri bawah 200
	//kanan atas 187
	//kiri atas 188
}
bool menu1(struct orang *self){
	system("cls");
	struct orang my_self=*self;
	gambar_kotak(0,0,50,1);
	gambar_kotak(0,2,50,20);
	gotoxy(2,1);printf("D:%cMENU%c",char(92),char(92));
	gotoxy(51,2); printf("%c",char(185));
	gotoxy(0,2); printf("%c",char(204));
	gotoxy(51,18); printf("%c",char(185));
	gotoxy(0,18); printf("%c",char(204));
	gotoxy(1,18); for(int i=0;i<50;i++) printf("%c",char(205));
	gotoxy(2,19); printf("NAMA  : %s",my_self.nama_lengkap);
	gotoxy(2,20); printf("KELAS : %s",my_self.kelas);
	gotoxy(2,21); printf("CASH  : %d",my_self.uang);
	gotoxy(2,22); printf("LEVEL : %d",my_self.level);
	gotoxy(40,0); printf("%c",char(203));
	gotoxy(40,1); printf("%c",char(186));
	gotoxy(40,2); printf("%c",char(202));
	gotoxy(42,1); printf("EXIT : ");
	gotoxy(55,3); printf("HOW TO USE:");
	gotoxy(58,5); printf("1. Hanya dapat mengisi huruf 'Y' untuk lanjut");
	gotoxy(58,6); printf("2. Kosongkan ' ' untuk melewati");
	gotoxy(58,7); printf("3. Tekan 'ENTER' untuk submit");
	gotoxy(2,3); printf("Halo, %s",my_self.nama_lengkap);
	gotoxy(4,4); printf("Mau ngapain hari ini?");
	gotoxy(13,8); printf("%c PROFILE : ",char(254));
	gotoxy(13,9); printf("%c KULIAH : ",char(254));
	gotoxy(13,10); printf("%c FORMULIR : ",char(254));
	gotoxy(13,11); printf("%c DAFTAR/IZIN : ",char(254));
	gotoxy(13,12); printf("%c BELANJA : ",char(254));
	gotoxy(13,13); printf("%c HIBURAN : ",char(254));
	while(true){
		while(true){
			gotoxy(25,8); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){while(!menu_profile(self));return 0;} 
				gotoxy(25,8); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(25,8); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(24,9); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2) {while(!menu_kuliah(self)); return 0;}
				gotoxy(24,9); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(24,9); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(26,10);
			int loop = an_ys();
			if(loop!=0){
				if(loop==2) {while(!menu_formulir(self)); return 0;} 
				gotoxy(26,10); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(26,10); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(29,11); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2) {while(!menu_daftar(self));return 0;}
				gotoxy(29,11); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(29,11); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(25,12); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){while(!menu_belanja(self)); return 0;} 
				gotoxy(25,12); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(25,12); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(25,13);
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){while(!menu_hiburan(self)); return 0;}
				gotoxy(25,13); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(25,13); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(49,1);
			int loop = an_ys();
			if(loop!=0){
				if(loop==2) return 1;
				gotoxy(49,1); printf("  %c                                                          ",char(186));
				break;
			}
			gotoxy(49,1); printf("  %c                                                          ",char(186));
		}
	}
}
bool menu2(struct orang self){
	gambar_kotak(0,0,50,1);
	gambar_kotak(0,2,50,20);
	gotoxy(51,2); printf("%c",char(185));
	gotoxy(0,2); printf("%c",char(204));
	gotoxy(40,0); printf("%c",char(203));
	gotoxy(40,1); printf("%c",char(186));
	gotoxy(40,2); printf("%c",char(202));
	gotoxy(42,1); printf("EXIT : ");
	gotoxy(55,3); printf("HOW TO USE:");
	gotoxy(58,5); printf("1. Hanya dapat mengisi huruf 'Y' untuk lanjut");
	gotoxy(58,6); printf("2. Kosongkan ' ' untuk melewati");
	gotoxy(58,7); printf("3. Tekan 'ENTER' untuk submit");
	while(true){
		while(true){
			gotoxy(49,1);
			int loop = an_ys();
			if(loop!=0){
				if(loop==2) return 1;
				gotoxy(49,1); printf("  %c                                                          ",char(186));
				break;
			}
			gotoxy(49,1); printf("  %c                                                          ",char(186));
		}
	}
}
bool menu_kuliah(struct orang*pointer_self){gambar_kotak(0,0,50,1);
	system("cls");
	gambar_kotak(0,0,50,1);
	gambar_kotak(0,2,50,20);
	gotoxy(2,1);printf("D:%cMENU%cKULIAH%c",char(92),char(92),char(92));
	gotoxy(51,2); printf("%c",char(185));
	gotoxy(0,2); printf("%c",char(204));
	gotoxy(51,18); printf("%c",char(185));
	gotoxy(0,18); printf("%c",char(204));
	struct orang my_self = *pointer_self;
	gotoxy(1,18); for(int i=0;i<50;i++) printf("%c",char(205));
	gotoxy(2,19); printf("NAMA  : %s",my_self.nama_lengkap);
	gotoxy(2,20); printf("KELAS : %s",my_self.kelas);
	gotoxy(2,21); printf("CASH  : %d",my_self.uang);
	gotoxy(2,22); printf("LEVEL : %d",my_self.level);
	gotoxy(40,0); printf("%c",char(203));
	gotoxy(40,1); printf("%c",char(186));
	gotoxy(40,2); printf("%c",char(202));
	gotoxy(42,1); printf("BACK : ");
	gotoxy(55,3); printf("HOW TO USE:");
	gotoxy(58,5); printf("1. Hanya dapat mengisi huruf 'Y' untuk lanjut");
	gotoxy(58,6); printf("2. Kosongkan ' ' untuk melewati");
	gotoxy(58,7); printf("3. Tekan 'ENTER' untuk submit");
	FILE* filedaftar;
	filedaftar = fopen("perkuliahan.txt","r");
	char all_form[30][100]={NULL};
	int k=0;
	while(fgets(all_form[k],sizeof all_form[k],filedaftar)!=NULL){all_form[k][strlen(all_form[k])-1]=NULL;k++;}
	for(int i=0;i<k;i++){
		gotoxy(3,4+i); printf("%c %s : ",char(254),all_form[i]);
	}
	fclose(filedaftar);
	while(true){
		for(int i=0;i<k;i++){
		while(true){
			int cc=8+strlen(all_form[i]);
			gotoxy(cc,4+i); 
			int loop = an_ys();
			if(loop!=0){
				//if(loop==2){pilih_kuliah(pointer_self,k);return;} 
				gotoxy(cc,4+i);  for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(cc,4+i); ; for(int i=0;i<20;i++) printf(" ");
		}
		}
		while(true){
			gotoxy(49,1);
			int loop = an_ys();
			if(loop!=0){
				if(loop==2) return 1;
				gotoxy(49,1); printf("  %c                                                          ",char(186));
				break;
			}
			gotoxy(49,1); printf("  %c                                                          ",char(186));
		} 
	}
}
bool menu_formulir(struct orang*pointer_self){
	system("cls");
	gambar_kotak(0,0,50,1);
	gambar_kotak(0,2,50,20);
	gotoxy(2,1);printf("D:%cMENU%cFORMULIR%c",char(92),char(92),char(92));
	gotoxy(51,2); printf("%c",char(185));
	gotoxy(0,2); printf("%c",char(204));
	gotoxy(51,18); printf("%c",char(185));
	gotoxy(0,18); printf("%c",char(204));
	struct orang my_self = *pointer_self;
	gotoxy(1,18); for(int i=0;i<50;i++) printf("%c",char(205));
	gotoxy(2,19); printf("NAMA  : %s",my_self.nama_lengkap);
	gotoxy(2,20); printf("KELAS : %s",my_self.kelas);
	gotoxy(2,21); printf("CASH  : %d",my_self.uang);
	gotoxy(2,22); printf("LEVEL : %d",my_self.level);
	gotoxy(40,0); printf("%c",char(203));
	gotoxy(40,1); printf("%c",char(186));
	gotoxy(40,2); printf("%c",char(202));
	gotoxy(42,1); printf("BACK : ");
	gotoxy(55,3); printf("HOW TO USE:");
	gotoxy(58,5); printf("1. Hanya dapat mengisi huruf 'Y' untuk lanjut");
	gotoxy(58,6); printf("2. Kosongkan ' ' untuk melewati");
	gotoxy(58,7); printf("3. Tekan 'ENTER' untuk submit");
	gotoxy(3,4); printf("FORMULIR");
	FILE* filedaftar;
	filedaftar = fopen("formulir.txt","r");
	char all_form[1000][100]={NULL};
	int k=0;
	while(fgets(all_form[k],sizeof all_form[k],filedaftar)!=NULL){all_form[k][strlen(all_form[k])-1]=NULL;k++;}
	for(int i=0;i<k;i++){
		gotoxy(3,6+i); printf("%c %s : ",char(254),all_form[i]);
	}
	fclose(filedaftar);
	while(true){
		for(int i=0;i<k;i++){
		while(true){
			int cc=8+strlen(all_form[i]);
			gotoxy(cc,6+i); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){isi_formulir(pointer_self);return 0;} 
				gotoxy(cc,6+i); ; for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(cc,6+i); ; for(int i=0;i<20;i++) printf(" ");
		}
		}
		while(true){
			gotoxy(49,1);
			int loop = an_ys();
			if(loop!=0){
				if(loop==2) return 1;
				gotoxy(49,1); printf("  %c                                                          ",char(186));
				break;
			}
			gotoxy(49,1); printf("  %c                                                          ",char(186));
		} 
	}
}
bool menu_daftar(struct orang*pointer_self){
	system("cls");
	gambar_kotak(0,0,50,1);
	gambar_kotak(0,2,50,20);
	gotoxy(2,1);printf("D:%cMENU%cDAFTAR/IZIN%c",char(92),char(92),char(92));
	gotoxy(51,2); printf("%c",char(185));
	gotoxy(0,2); printf("%c",char(204));
	gotoxy(51,18); printf("%c",char(185));
	gotoxy(0,18); printf("%c",char(204));
	struct orang my_self = *pointer_self;
	gotoxy(1,18); for(int i=0;i<50;i++) printf("%c",char(205));
	gotoxy(2,19); printf("NAMA  : %s",my_self.nama_lengkap);
	gotoxy(2,20); printf("KELAS : %s",my_self.kelas);
	gotoxy(2,21); printf("CASH  : %d",my_self.uang);
	gotoxy(2,22); printf("LEVEL : %d",my_self.level);
	gotoxy(40,0); printf("%c",char(203));
	gotoxy(40,1); printf("%c",char(186));
	gotoxy(40,2); printf("%c",char(202));
	gotoxy(42,1); printf("BACK : ");
	gotoxy(55,3); printf("HOW TO USE:");
	gotoxy(58,5); printf("1. Hanya dapat mengisi huruf 'Y' untuk lanjut");
	gotoxy(58,6); printf("2. Kosongkan ' ' untuk melewati");
	gotoxy(58,7); printf("3. Tekan 'ENTER' untuk submit");
	gotoxy(3,4); printf("PENDAFTARAN YANG TERSEDIA ");
	FILE* filedaftar;
	filedaftar = fopen("pendaftaran.txt","r");
	char all_form[1000][100]={NULL};
	int k=0;
	while(fgets(all_form[k],sizeof all_form[k],filedaftar)!=NULL){all_form[k][strlen(all_form[k])-1]=NULL;k++;}
	for(int i=0;i<k;i++){
		gotoxy(3,6+i); printf("%c %s : ",char(254),all_form[i]);
	}
	
	fclose(filedaftar);
	while(true){
		for(int i=0;i<k;i++){
		while(true){
			int cc=8+strlen(all_form[i]);
			gotoxy(cc,6+i); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){accept_daftar(pointer_self);return 0;} 
				gotoxy(cc,6+i); ; for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(cc,6+i); ; for(int i=0;i<20;i++) printf(" ");
		}
		}
		while(true){
			gotoxy(49,1);
			int loop = an_ys();
			if(loop!=0){
				if(loop==2) return 1;
				gotoxy(49,1); printf("  %c                                                          ",char(186));
				break;
			}
			gotoxy(49,1); printf("  %c                                                          ",char(186));
		} 
	}
}
bool menu_belanja(struct orang*pointer_self){
	system("cls");
	gambar_kotak(0,0,50,1);
	gambar_kotak(0,2,50,20);
	gotoxy(2,1);printf("D:%cMENU%cBELANJA%c",char(92),char(92),char(92));
	gotoxy(51,2); printf("%c",char(185));
	gotoxy(0,2); printf("%c",char(204));
	gotoxy(51,18); printf("%c",char(185));
	gotoxy(0,18); printf("%c",char(204));
	struct orang my_self = *pointer_self;
	gotoxy(1,18); for(int i=0;i<50;i++) printf("%c",char(205));
	gotoxy(2,19); printf("NAMA  : %s",my_self.nama_lengkap);
	gotoxy(2,20); printf("KELAS : %s",my_self.kelas);
	gotoxy(2,21); printf("CASH  : %d",my_self.uang);
	gotoxy(2,22); printf("LEVEL : %d",my_self.level);
	gotoxy(40,0); printf("%c",char(203));
	gotoxy(40,1); printf("%c",char(186));
	gotoxy(40,2); printf("%c",char(202));
	gotoxy(42,1); printf("BACK : ");
	gotoxy(55,3); printf("HOW TO USE:");
	gotoxy(58,5); printf("1. Hanya dapat mengisi huruf 'Y' untuk lanjut");
	gotoxy(58,6); printf("2. Kosongkan ' ' untuk melewati");
	gotoxy(58,7); printf("3. Tekan 'ENTER' untuk submit");
	gotoxy(3,4); printf("%c LIHAT PESANAN : ",char(254));
	gotoxy(3,5); printf("%c BUAT PESANAN : ",char(254));
	gotoxy(3,6); printf("%c LIHAT DISKON : ",char(254));
	gotoxy(3,7); printf("%c PEMBAYARAN : ",char(254));
	gotoxy(3,8); printf("%c PENGISIAN : ",char(254));
	while(true){
		while(true){
			gotoxy(21,4); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){lihat_pesanan(pointer_self);return 0;} 
				gotoxy(21,4); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(21,4); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(20,5); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){buat_pesanan(pointer_self);return 0;} 
				gotoxy(20,5); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(20,5); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(20,6); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){lihat_diskon(pointer_self);return 0;} 
				gotoxy(20,6); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(20,6); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(18,7); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){pembayaran(pointer_self);return 0;} 
				gotoxy(18,7); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(18,7); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(17,8); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){pengisian(pointer_self);return 0;} 
				gotoxy(17,8); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(17,8); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(49,1);
			int loop = an_ys();
			if(loop!=0){
				if(loop==2) return 1;
				gotoxy(49,1); printf("  %c                                                          ",char(186));
				break;
			}
			gotoxy(49,1); printf("  %c                                                          ",char(186));
		} 
	}
}
bool menu_profile(struct orang*pointer_self){
	system("cls");
	gambar_kotak(0,0,50,1);
	gambar_kotak(0,2,50,20);
	gotoxy(2,1);printf("D:%cMENU%cPROFILE%c",char(92),char(92),char(92));
	gotoxy(51,2); printf("%c",char(185));
	gotoxy(0,2); printf("%c",char(204));
	gotoxy(51,18); printf("%c",char(185));
	gotoxy(0,18); printf("%c",char(204));
	struct orang my_self = *pointer_self;
	gotoxy(1,18); for(int i=0;i<50;i++) printf("%c",char(205));
	gotoxy(2,19); printf("NAMA  : %s",my_self.nama_lengkap);
	gotoxy(2,20); printf("KELAS : %s",my_self.kelas);
	gotoxy(2,21); printf("CASH  : %d",my_self.uang);
	gotoxy(2,22); printf("LEVEL : %d",my_self.level);
	gotoxy(40,0); printf("%c",char(203));
	gotoxy(40,1); printf("%c",char(186));
	gotoxy(40,2); printf("%c",char(202));
	gotoxy(42,1); printf("BACK : ");
	gotoxy(55,3); printf("HOW TO USE:");
	gotoxy(58,5); printf("1. Hanya dapat mengisi huruf 'Y' untuk lanjut");
	gotoxy(58,6); printf("2. Kosongkan ' ' untuk melewati");
	gotoxy(58,7); printf("3. Tekan 'ENTER' untuk submit");
	gotoxy(3,4); printf("%c LIHAT PROFILE : ",char(254));
	gotoxy(3,5); printf("%c EDIT PROFILE : ",char(254));
	while(true){
		while(true){
			gotoxy(21,4); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){lihat_profile(pointer_self);return 0;} 
				gotoxy(21,4); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(21,4); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(20,5); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){edit_profile(pointer_self);return 0;} 
				gotoxy(20,5); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(20,5); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(49,1);
			int loop = an_ys();
			if(loop!=0){
				if(loop==2) return 1;
				gotoxy(49,1); printf("  %c                                                          ",char(186));
				break;
			}
			gotoxy(49,1); printf("  %c                                                          ",char(186));
		} 
	}
}
bool menu_hiburan(struct orang*pointer_self){
	system("cls");
	gambar_kotak(0,0,50,1);
	gambar_kotak(0,2,50,20);
	gotoxy(2,1);printf("D:%cMENU%cHIBURAN%c",char(92),char(92),char(92));
	gotoxy(51,2); printf("%c",char(185));
	gotoxy(0,2); printf("%c",char(204));
	gotoxy(51,18); printf("%c",char(185));
	gotoxy(0,18); printf("%c",char(204));
	struct orang my_self = *pointer_self;
	gotoxy(1,18); for(int i=0;i<50;i++) printf("%c",char(205));
	gotoxy(2,19); printf("NAMA  : %s",my_self.nama_lengkap);
	gotoxy(2,20); printf("KELAS : %s",my_self.kelas);
	gotoxy(2,21); printf("CASH  : %d",my_self.uang);
	gotoxy(2,22); printf("LEVEL : %d",my_self.level);
	gotoxy(40,0); printf("%c",char(203));
	gotoxy(40,1); printf("%c",char(186));
	gotoxy(40,2); printf("%c",char(202));
	gotoxy(42,1); printf("BACK : ");
	gotoxy(55,3); printf("HOW TO USE:");
	gotoxy(58,5); printf("1. Hanya dapat mengisi huruf 'Y' untuk lanjut");
	gotoxy(58,6); printf("2. Kosongkan ' ' untuk melewati");
	gotoxy(58,7); printf("3. Tekan 'ENTER' untuk submit");
	gotoxy(3,4); printf("%c TEBAK-TEBAKAN : ",char(254));
	gotoxy(3,5); printf("%c MAZE GAMES!! : ",char(254));
	gotoxy(3,6); printf("%c SUSUN HURUF!! : ",char(254));
	while(true){
		while(true){
			gotoxy(21,4); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){game_tebak(pointer_self);return 0;} 
				gotoxy(21,4); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(21,4); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(20,5); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){game_maze(pointer_self);return 0;} 
				gotoxy(20,5); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(20,5); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(21,6); 
			int loop = an_ys();
			if(loop!=0){
				if(loop==2){game_huruf(pointer_self);return 0;} 
				gotoxy(21,6); for(int i=0;i<20;i++) printf(" ");
				break;
			}
			gotoxy(21,6); for(int i=0;i<20;i++) printf(" ");
		}
		while(true){
			gotoxy(49,1);
			int loop = an_ys();
			if(loop!=0){
				if(loop==2) return 1;
				gotoxy(49,1); printf("  %c                                                          ",char(186));
				break;
			}
			gotoxy(49,1); printf("  %c                                                          ",char(186));
		} 
	}
}













//last koding kok gajelas

#define opqwoekqopmrmfksnalknsdklnwklaenkwal void 
opqwoekqopmrmfksnalknsdklnwklaenkwal isemkmdkealkklawjgawjgehjafdhfhwfagejgiwuqiuwyeuitqiuwteiutqiwutiuqwr(){
	{
	#define popsfksldknlanldwa char
	#define n3k1240_daslkfanlk while
	#define klkldsa_weqea true
	#define qpomnjknjbakjbjawawwwwwwwwwwwwwwwwwwwwwwwwwwwwjbjbjbwewe 0
	#define kanwklenaklwneklads false
	#define kweonqone2i9410924D_sawraw BATAS
	#define oipfpdsfawmklmwlekqkwjeklqwjkdmklawjiji23ij231nk3kn gets
	#define pqmrkwnqkndarwlmwqkrnklwqnkrnklqnwlknqlkwtnlkqnwtklnlqw "cls"
	#define qwprkqojwmkljkwakrhjkawhjkbawkjebajkwbjbjkbakjdbjwjgqjgehjwgqjhrjhwbqhrjbwqhjbrhjwq system
	#define ejwbkqjbkjbahgwhejhagwheaw if
	#define popqwrhwhqiuhruiwqurgubwdwubbdawjhkjehawkhekjawhekjaw "lah_wkwkw"
	#define popoqweknakwebjbjhvqhjwvehgcqghwcfgrcfgwrcqjwlknlkdakwjrljawlkjrlkwjlkqnknrkjbhjgjsbpdsvp strcmp
	#define jwkejklwjqlekjqwklejlkqladnfnwaini_qweiniqwne super
	#define qpweooqpjrwqjiriqwhihwquhruiwqhuhqwiuheuiqwhurwuqnduinauweghuawgrjgwarjygawygyjwagrwyjgjarwawr break
	}
	popsfksldknlanldwa awjoihaiugiwuae[kweonqone2i9410924D_sawraw];
	n3k1240_daslkfanlk(klkldsa_weqea){
		qwprkqojwmkljkwakrhjkawhjkbawkjebajkwbjbjkbakjdbjwjgqjgehjwgqjhrjhwbqhrjbwqhjbrhjwq(pqmrkwnqkndarwlmwqkrnklwqnkrnklqnwlknqlkwtnlkqnwtklnlqw);
		oipfpdsfawmklmwlekqkwjeklqwjkdmklawjiji23ij231nk3kn(awjoihaiugiwuae);
		ejwbkqjbkjbahgwhejhagwheaw(popoqweknakwebjbjhvqhjwvehgcqghwcfgrcfgwrcqjwlknlkdakwjrljawlkjrlkwjlkqnknrkjbhjgjsbpdsvp(awjoihaiugiwuae,popqwrhwhqiuhruiwqurgubwdwubbdawjhkjehawkhekjawhekjaw)==qpomnjknjbakjbjawawwwwwwwwwwwwwwwwwwwwwwwwwwwwjbjbjbwewe){jwkejklwjqlekjqwklejlkqladnfnwaini_qweiniqwne();qpweooqpjrwqjiriqwhihwquhruiwqhuhqwiuheuiqwhurwuqnduinauweghuawgrjgwarjygawygyjwagrwyjgjarwawr;} 
	}
}
