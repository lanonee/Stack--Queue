#include <stdio.h>
#define MAX 3 

typedef struct{
	int data[MAX];
	int head; 
	int tail;
} Queue;

Queue antrian;

void awal(){

	antrian.head=antrian.tail=-1;
}

int kosong(){
	if(antrian.tail==-1)
		return 1;
	else
		return 0;
}

int Penuh() {
	if(antrian.tail==MAX-1)
		return 1;
	else
	 	return 0;
}


int enqueue(int data){
	if(kosong()==1){
		antrian.head=antrian.tail=0;
		antrian.data[antrian.tail]=data;
		printf("%d masuk!\n", antrian.data[antrian.tail]);
		void tampil();
		{
			int i;
			if(kosong()==0){
				for(i=antrian.head;i<=antrian.tail; i++){
					printf("%d", antrian.data[i]);
				}
			}
			else
				printf("Isi antrian kosong!");
		}
	}
	else if (Penuh()==0){
		antrian.tail++;
		antrian.data[antrian.tail]=data;
		printf("%d masuk!\n",antrian.data[antrian.tail]);
	}
}


int dequeue(){
	int antri=antrian.data[antrian.head];
	int i;
	for(i=antrian.head;i<=antrian.tail;i++){
		antrian.data[i] = antrian.data[i+1];
	}
	antrian.tail--;
	return antri;
}

void tampil(){
    if(kosong()==0){
        for(int i=antrian.head; i<=antrian.tail; i++){
            printf("%d", antrian.data[i]);
        }
    }
    else
    printf("tidak ada data dalam antrian");
}

void hapus(){
    antrian.head=antrian.tail=-1;
    printf("data sudah dibersihkan\n");
}


void main(){
	int pilihan, data;
	awal();
	do{
	printf("\n");
	printf("1. Masuk Satu Data\n");
	printf("2. Keluarkan Satu Data\n");
	printf("3. Lihat Isi Antrian\n");
	printf("4. Hapus Isi Antrian\n");
	printf("5. Keluar\n");
	printf("Pilihan Anda?\n");
	scanf("%d", &pilihan);
	switch(pilihan){
		case 1: printf("Data = ");
		scanf("%d", &data);
		enqueue(data);
		break;
		case 2:
			printf("data yang keluar: %d", dequeue());
			break;
        case 3:
		    tampil();
		    break;
		case 4:
		    hapus();
		    break;
		}
	}while(pilihan!=5);
}

