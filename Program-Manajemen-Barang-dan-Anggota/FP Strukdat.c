#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a=0,c=0,e=0,f;

//membuat data anggota
struct node{
	char nama_ang[50];
	char alamat[50];
	char pekerjaan[50];
	char usia[50];
	
    int data;
    struct node *next;
}node [100];

// Membuat struct dalam konsep stack
typedef struct{
    struct node * top;
}STACK;

//membuat data barang dalam struct dengan konsep queue
struct barang {	
	char nama_bar[50];
	char id_bar[50];
	char tipe_bar[50];
	char jumlah_bar[50];
    int harga;
} barang[100],temp;

// Elemen dalam queue
typedef struct Elemen {
    struct barang brg;
    struct Elemen *next;
} Elemen;

// Konsep queueu dalam elemen 
typedef struct Queue {
	
    struct Elemen *front;
    struct Elemen *rear;
} Queue;

// Membuat struct data pembeli
struct pembeli{
	int ID_pem;
	char nama_pem[50];
	char jml_brg_dbl[50];
	char tot_hrg[50];
	struct mahasiswa *next;
};

struct pembeli *head = NULL;
struct pembeli *tail = NULL;

// Linked list dalam queue
insert(int nilai, Queue *Queue){
    Elemen *current = (Elemen*) malloc(sizeof(Elemen));
    current->brg.harga = nilai;

    if(Queue->front == NULL){
        Queue->front = current;
        Queue->rear = current;
        current->next = NULL;
        current = NULL;
    } else {
        Queue->rear->next = current;
        Queue->rear = current;
        current->next = NULL;
        current = NULL;
    }
}

// Menampilkan queue
display(Queue Queue){
    if(Queue.front == NULL){
        printf("\n  Data masih Kosong !\n");
    } 
	else{
        printf("\n  Data dalam queue adlah: \n");
        Elemen *current = Queue.front;
        int d=1;
        while(current != NULL){
        	printf("=================================================");
        	printf("\n  %d. Nama barang	: %s",d,barang[c].nama_bar);
        	printf("\n     Tipe barang	: %s",barang[c].tipe_bar);
        	printf("\n     Jumlah barang	: %s",barang[c].jumlah_bar);
            printf("\n     Harga barang	: %d\n",current->brg.harga);
            current = current->next;
        	d++;
		}
	}
}

// Hapus di awal queue
deleteQueue(Queue *Queue){
    Elemen *current = (Elemen*) malloc(sizeof(Elemen));
    if(Queue->front->next != NULL){
        current = Queue->front;
        Queue->front = current->next;
    } 
	else {
        Queue->front = NULL;
    }
    free(current);
    current = NULL;
}

//bagaian tambah data stack
int push(STACK *s,int v){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Stack penuh!");
        return 1;
    }
    temp->data=v;
    temp->next=s->top;
    s->top=temp;
    return 0;
}

//bagian hapus data stack
int pop(STACK *s,struct node **v){
    struct node *temp;
    if(s->top==NULL){
        printf("Stack masih kosong!");
        return 1;
    }
    temp=s->top;
    s->top=temp->next;
    *v=temp;
    return 0;
}

//bagian view data yang telah dimasukan
int traverse(STACK *s){
    if(s->top==NULL){
        printf("Stack masih kosong\n");
    }
    else{
        struct node *temp;
        printf("\n  Data dalam stack adalah:\n");
        int b=1;
        for(temp=s->top;temp!=NULL;temp=temp->next){
        	printf("==========================================");
            printf("\n  %d. Nama	: %s",b,node[a].nama_ang);
            printf("\n     Alamat	: %s",node[a].alamat);
            printf("\n     Pekerjaan	: %s",node[a].pekerjaan);
            printf("\n     Usia	: %s",node[a].usia);
			printf("\n     Nilai	: %d\n",temp->data);   
        b++;
		}
    }
}

//deklarasi untuk bagian-bagian fungsi yang ada dalam program
void anggota_stack();
void barang_queue();
void tambah_dt_pem(int ID_pem, char nama_pem[], char jml_brg_dbl[], char tot_hrg[]);
void tampilkan_dt_pem();
void cari_dt_pem(int ID_pem);

//fungsi manajemen data anggota menggunakan konsep stack
void anggota_stack(){

	struct node *m;
    STACK s1;
    s1.top = NULL;
	
	//pil_ang = pilihan dalam bagian manajemen anggota
	//v = nilai
	int pil_ang,v,q,k;
    
	while(1){
    	system ("cls");
    	
    	printf("\n  + + + + + MANAJEMEN ANGGOTA + + + + +\n");
        printf("  -------------------------------------");
    	printf("\n  Silahkan pilih opsi manajemen data dibawah ini");
		printf("\n  (1). Tambah data anggota");
        printf("\n  (2). Hapus data anggota");
        printf("\n  (3). Tampilkan data anggota");
        printf("\n  (4). Update data anggota");
		printf("\n  (5). Keluar");
        printf("\n  Pilihan: ");
        scanf("%d",&pil_ang);

        switch(pil_ang){
            case 1:
            	// Pilihan Tambah adata anggota
                printf("\n  Masukan nama anggota	: ");
                scanf(" %[^\n]s",&node[a].nama_ang);
                
                printf("  Masukan alamat	: ");
                scanf(" %[^\n]s",&node[a].alamat);
                
                printf("  Masukan pekerjaan	: ");
                scanf(" %[^\n]s",&node[a].pekerjaan);
				
				printf("  Masukan usia		: ");
                scanf(" %[^\n]s",&node[a].usia);
                
                printf("  Masukan ID		: ");
                scanf("%d",&v);
                
				k=push(&s1,v);
                if(k==1){
            		printf("  Stack sudah penuh!\n");
            	sleep(2);
				}
				else{
                	printf("\n  Data berhasil ditambahkan kedalam stack\n");
            	sleep(2);
				}
				break;
            case 2:
            	// Bagian hapus data anggota
                q=pop(&s1,&m);
                if(q==1){
                    printf("  Stack masih kosong!\n");
                sleep(2);
				}
				else{
                    printf("  Data berhasil dihapus\n",m->data);
            	sleep(2);
				}	
				break;
            case 3:
            	
                traverse(&s1);
                sleep(3);
				break;
            case 4:
               	q=pop(&s1,&m);
               	
               	printf("\n  Masukan nama anggota baru	: ");
                scanf(" %[^\n]s",&node[a].nama_ang);
                
                printf("  Masukan alamat baru		: ");
                scanf(" %[^\n]s",&node[a].alamat);
                
                printf("  Masukan pekerjaan baru	: ");
                scanf(" %[^\n]s",&node[a].pekerjaan);
				
				printf("  Masukan usia baru		: ");
                scanf(" %[^\n]s",&node[a].usia);
                
                printf("  Masukan ID baru		: ");
                scanf("%d",&v);
                
				k=push(&s1,v);
                if(k==1){
            		printf("  Stack sudah penuh!\n");
            	sleep(2);
				}
				else{
                	printf("\n  Data berhasil diperbarui \n");
            	sleep(2);
				}
            	break;
			case 5: 
				exit(0);
                break;
            default:
                printf("  Pilihan tidak ditemukan\n");
        		sleep(2);
		}
    }
}

//fungsi manajemen data barang menggunakan konsep queue
void barang_queue(){

	struct barang *m;
	Elemen *current = (Elemen*) malloc(sizeof(Elemen));;

    //pil_bar = pilihan menu pada bagian manajemen barang
    //value = nilai
    //opsi = pilihan ya atau tidak
	int pil_bar;
    char opsi;
    int value;
    
    Queue Queue;
    Queue.front = NULL;

    while(1){
	
    	system ("cls");
    	
        printf("\n  + + + + + MANAJEMEN BARANG + + + + +\n");
        printf("  -------------------------------------");
    	printf("\n  Silahkan pilih opsi manajemen data dibawah ini");
		printf("\n  (1). Tambah data barang");
        printf("\n  (2). Hapus data barang");
        printf("\n  (3). Tampilkan data barang");
        printf("\n  (4). Keluar");
        printf("\n  Pilihan: ");
        scanf("%d",&pil_bar);
	
        if (pil_bar == 1){
			do{
                printf("\n  Masukan nama barang	: ");
                scanf(" %[^\n]s",barang[c].nama_bar);
                
                printf("  Masukan ID barang	: ");
                scanf(" %[^\n]s",barang[c].id_bar);
                
                printf("  Masukan tipe barang	: ");
                scanf(" %[^\n]s",barang[c].tipe_bar);
				
				printf("  Masukan jumlah barang	: ");
                scanf(" %[^\n]s",barang[c].jumlah_bar);
				
				printf("  Masukan harga barang	: ");
                scanf("%d", &value);fflush(stdin);
                
				insert(value, &Queue);
                printf("\n  Data berhasil ditambahkan !\n",value);
                
				printf("\n  Masukan lagi? [Y/T] : ");
                scanf("%c", &opsi);fflush(stdin);
                
				printf("\n");
			}
			while (opsi == 'Y' || opsi == 'y');
        } 
		else if (pil_bar == 2){
            if (Queue.front == NULL){
                printf("\n  Data belum ada !\n");
            } 
			else{
                deleteQueue(&Queue);
                printf("\n  Data berhasil dihapus !\n");
                sleep(3);
            }
        } 
		else if (pil_bar == 3){
            display(Queue);
            sleep(3);
        } 
		else if (pil_bar == 4){
            printf("  Keluar\n");
            return;
        } 
		else{
            printf("  Menu tidak tersedia !\n");
            sleep(3);
        }
    } 
	while (pil_bar != 4);
}

void tambah_dt_pem(int ID_pem, char nama_pem[], char jml_brg_dbl[], char tot_hrg[]){
	struct pembeli* newData = (struct pembeli*)malloc(sizeof(struct pembeli));
	newData->ID_pem = ID_pem;
	strcpy(newData->nama_pem, nama_pem);
	strcpy(newData->jml_brg_dbl, jml_brg_dbl);
	strcpy(newData->tot_hrg, tot_hrg);
	
	if(head==NULL){
		head = newData;
		head->next = NULL;
	}
	else{
		newData->next = head;
		head = newData;
	}
}

void tampilkan_dt_pem(){
	printf("======================================================\n");
	printf("\t\tShow List Data\n");
	printf("======================================================\n");
	int i=1;
	struct pembeli* temp = head;
	while(temp != NULL){
		printf("Data ke - %d\n", i);
		printf("NPM\t\t: %lli\n", temp->ID_pem);
		printf("Name\t\t: %s\n", temp->nama_pem);
		printf("Fakultas\t: %s\n", temp->jml_brg_dbl);
		printf("Fakultas\t: %s\n", temp->tot_hrg);
		printf("\n");
		temp = temp->next;
		i++;
	}
}

void cari_dt_pem(int ID_pem){
	struct pembeli* temp = head;
	while(temp != NULL){
		if(temp->ID_pem == ID_pem){
			printf("NPM\t\t: %d\n", temp->ID_pem);
			printf("Name\t\t: %s\n", temp->nama_pem);
			printf("Fakultas\t: %s\n", temp->jml_brg_dbl);
			printf("Fakultas\t: %s\n", temp->tot_hrg);
			printf("\n");
		}
		temp = temp->next;
	}
}

/*
struct node_tr{
  int car;
  char nama[25];
  struct node_tr *left, *right;
};

struct node_tr *root = NULL;

struct node_tr *newNode(int item, char *matkul)
{
	struct node1 *temp = (struct node *)malloc(sizeof(struct node));
  	
	temp->key = item;
  	strcpy(temp->nama, matkul);
  	temp->left = NULL;
  	temp->right = NULL;
  	return temp;
}

void inorder(struct node *root)
{
	if (root != NULL) {
    	inorder(root->left);
    	printf("| %d | %s\n", root->key, root->nama);
    	inorder(root->right);
  	}
}

void saveMatkul(struct node *root){
	if(root!=NULL){
		saveMatkul(root->left);
		fprintf(fp,"%i#%s\n",root->key, root->nama);
		saveMatkul(root->right);
	}
}

struct node *insert(struct node *node, int key, char *matkul)
{
	if (node == NULL) return newNode(key, matkul);

  	if (key < node->key)
    	node->left = insert(node->left, key, matkul);
  	else
    	node->right = insert(node->right, key, matkul);
  	return node;
}

struct node* search(struct node *root, int x)
{
    if(root==NULL) 
        printf("\nData tidak ditemukan\n");
    else if(x > root->key) 
        return search(root->right, x);
    else if(x < root->key) 
        return search(root->left, x);
    else
      printf("| %d | %s\n", root->key, root->nama);
}

struct node *minValueNode(struct node *node)
{
  	struct node *current = node;

  	while (current && current->left != NULL)
    current = current->left;
	return current;
}

struct node *deleteNode(struct node *root, int key)
{
	if (root == NULL) return root;

  	if (key < root->key)
    	root->left = deleteNode(root->left, key);
  	else if (key > root->key)
    	root->right = deleteNode(root->right, key);

  	else {
    	if (root->left == NULL) {
      		struct node *temp = root->right;
      		free(root);
      		return temp;
    	} else if (root->right == NULL) {
      		struct node *temp = root->left;
      		free(root);
      		return temp;
   		}

    struct node *temp = minValueNode(root->right);

    root->key = temp->key;
	strcpy(root->nama, temp->nama);

    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
*/

//program utama
int main() {
	int pil_menu;
	
	printf("  =============== MENU UTAMA ===============");
	printf("\n  Silahkan pilih menu dibawah ini: ");
	printf("\n  [1]. Manajemen Data Anggota");
	printf("\n  [2]. Manajemen Data Barang");
	printf("\n  [3]. Cari ID Pelanggan");
	printf("\n  [4]. Exit");
	
	printf("\n  ===========================================");
	printf("\n  Pilihan: ");
	scanf("%i",&pil_menu);
	
	switch (pil_menu){
		case 1:
			anggota_stack();
			break;
		case 2:
			barang_queue();
			break;
		case 3:
			printf(" Ini BST");
			return 0;
			break;
		case 4:
			return 0;
		default:
			printf("  Pilihan tidak ditemukan");
			
	}
	
	return 0;
}
