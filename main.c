#include<stdio.h>
#include<stdlib.h>

typedef struct proces{
	char nume[5];
	int timpOcupare;
	int timpInceput;
	int prioritate;
	int timpAsteptare,timpProcesare;
	int verificat;
}procese;


void b_sort(procese temp[],int n)
{
	procese t;
	int i,j;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++){
			if(temp[j].timpInceput > temp[j+1].timpInceput){
				t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}
}

int accept(procese P[]){
	int i,n;
	printf("\n Introdu numar procese : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\n PROCESUL [%d]",i+1);
		printf(" Introdu nume proces : ");
		scanf("%s",P[i].nume);
		printf(" Introdu timp ocupare : ");
		scanf("%d",&P[i].timpOcupare);
		printf(" Introdu timpul de inceput : ");
		scanf("%d",&P[i].timpInceput);
		printf(" Introdu prioritate : ");
		scanf("%d",&P[i].prioritate);
	}
	printf("\n PROC.\tB.T.\tA.T.\tPRIORITY");
	for(i=0;i<n;i++)
		printf("\n %s\t%d\t%d\t%d",P[i].nume,P[i].timpOcupare,P[i].timpInceput,P[i].prioritate);
	return n;
}

// FCFS Algorithm
void FCFS(procese P[],int n){
	procese temp[10];
	int sumaTimpAsteptare=0,sumaTimpProcesare=0;
	int x = 0;
	float timpMediuAsteptare=0.0,timpMediuProcesare=0.0;
	int i,j;
	for(i=0;i<n;i++)
		temp[i]=P[i];

	b_sort(temp,n);

		printf("\n\n PROC.\tB.T.\tA.T.");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t%d",temp[i].nume,temp[i].timpOcupare,temp[i].timpInceput);

		sumaTimpAsteptare = temp[0].timpAsteptare = 0;
		sumaTimpProcesare = temp[0].timpProcesare = temp[0].timpOcupare - temp[0].timpInceput;

		for(i=1;i<n;i++){
			temp[i].timpAsteptare = (temp[i-1].timpOcupare + temp[i-1].timpInceput + temp[i-1].timpAsteptare) - temp[i].timpInceput;;
			temp[i].timpProcesare = (temp[i].timpAsteptare + temp[i].timpOcupare);
			sumaTimpAsteptare+=temp[i].timpAsteptare;
			sumaTimpProcesare+=temp[i].timpProcesare;
		}
		timpMediuAsteptare = (float)sumaTimpAsteptare/n;
		timpMediuProcesare = (float)sumaTimpProcesare/n;
		printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t%d\t%d\t%d",temp[i].nume,temp[i].timpOcupare,temp[i].timpInceput,temp[i].timpAsteptare,temp[i].timpProcesare);

		printf("\n\n GANTT CHART\n ");
		for(i=0;i<n;i++)
			printf("   %s   ",temp[i].nume);
		printf("\n ");

		printf("0\t");
		for(i=1;i<=n;i++){
			x+=temp[i-1].timpOcupare;
			printf("%d      ",x);
		}
		printf("\n\n Timpul mediu de asteptare = %0.2f\n Timpul mediu de procesare = %0.2f.",timpMediuAsteptare,timpMediuProcesare);
}


//SJF Non Pre-emptive
void SJF_NP(procese P[],int n){
	procese temp[10];
	procese t;
	int sumaTimpAsteptare=0,sumaTimpProcesare=0;
	int x = 0;
	float timpMediuAsteptare=0.0,timpMediuProcesare=0.0;
	int i,j;

	for(i=0;i<n;i++)
		temp[i]=P[i];

	b_sort(temp,n);

	for(i=2;i<n;i++)
		for(j=1;j<n-i+1;j++){
			if(temp[j].timpOcupare > temp[j+1].timpOcupare){
				t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}

	printf("\n\n PROC.\tB.T.\tA.T.");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t%d",temp[i].nume,temp[i].timpOcupare,temp[i].timpInceput);

		sumaTimpAsteptare = temp[0].timpAsteptare = 0;
		sumaTimpProcesare = temp[0].timpProcesare = temp[0].timpOcupare - temp[0].timpInceput;

		for(i=1;i<n;i++){
			temp[i].timpAsteptare = (temp[i-1].timpOcupare + temp[i-1].timpInceput + temp[i-1].timpAsteptare) - temp[i].timpInceput;;
			temp[i].timpProcesare = (temp[i].timpAsteptare + temp[i].timpOcupare);
			sumaTimpAsteptare+=temp[i].timpAsteptare;
			sumaTimpProcesare+=temp[i].timpProcesare;
		}
		timpMediuAsteptare = (float)sumaTimpAsteptare/n;
		timpMediuProcesare = (float)sumaTimpProcesare/n;
		printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t%d\t%d\t%d",temp[i].nume,temp[i].timpOcupare,temp[i].timpInceput,temp[i].timpAsteptare,temp[i].timpProcesare);

		printf("\n\n GANTT CHART\n ");
		for(i=0;i<n;i++)
			printf("   %s   ",temp[i].nume);
		printf("\n ");

		printf("0\t");
		for(i=1;i<=n;i++){
			x+=temp[i-1].timpOcupare;
			printf("%d      ",x);
		}
		printf("\n\n Timpul mediu de asteptare = %0.2f\n Timpul mediu de procesare = %0.2f.",timpMediuAsteptare,timpMediuProcesare);
}

//Priority Non Pre-emptive
void PRT_NP(procese P[],int n)
{
	procese temp[10];
	procese t;
	int sumaTimpAsteptare=0,sumaTimpProcesare=0;
	float timpMediuAsteptare=0.0,timpMediuProcesare=0.0;
	int i,j;
	int x = 0;

	for(i=0;i<n;i++)
		temp[i]=P[i];

	b_sort(temp,n);

	for(i=2;i<n;i++)
		for(j=1;j<n-i+1;j++){
			if(temp[j].prioritate > temp[j+1].prioritate){
				t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}

	printf("\n\n PROC.\tTimp Ocupare\tTimp Inceput");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t\t%d",temp[i].nume,temp[i].timpOcupare,temp[i].timpInceput);

		sumaTimpAsteptare = temp[0].timpAsteptare = 0;
		sumaTimpProcesare = temp[0].timpProcesare = temp[0].timpOcupare - temp[0].timpInceput;

		for(i=1;i<n;i++){
			temp[i].timpAsteptare = (temp[i-1].timpOcupare + temp[i-1].timpInceput + temp[i-1].timpAsteptare) - temp[i].timpInceput;;
			temp[i].timpProcesare = (temp[i].timpAsteptare + temp[i].timpOcupare);
			sumaTimpAsteptare+=temp[i].timpAsteptare;
			sumaTimpProcesare+=temp[i].timpProcesare;
		}
		timpMediuAsteptare = (float)sumaTimpAsteptare/n;
		timpMediuProcesare = (float)sumaTimpProcesare/n;
		printf("\n\n PROC.\tTimp Ocupare\tTimp Inceput\tTimp Asteptare\tTimp Procesare");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t\t%d\t\t%d\t\t%d",temp[i].nume,temp[i].timpOcupare,temp[i].timpInceput,temp[i].timpAsteptare,temp[i].timpProcesare);

		printf("\n\n GANTT CHART\n ");
		for(i=0;i<n;i++)
			printf("   %s   ",temp[i].nume);
		printf("\n ");

		printf("0\t");
		for(i=1;i<=n;i++){
			x+=temp[i-1].timpOcupare;
			printf("%d      ",x);
		}
		printf("\n\n Timpul mediu de asteptare = %0.2f\n Timpul mediu de procesare = %0.2f.",timpMediuAsteptare,timpMediuProcesare);
}

//Round Robin Scheduling
void RR(procese P[],int n)
{
	int nrProceseVerif=0,t,timpCurent=0,k,i,Q=0;
	int sumaTimpAsteptare=0,sumaTimpProcesare=0;
	float timpMediuAsteptare=0.0,timpMediuProcesare=0.0;
	procese temp1[10],temp2[10];

	for(i=0;i<n;i++)
		temp1[i]=P[i];

	b_sort(temp1,n);

	for(i=0;i<n;i++)
		temp2[i]=temp1[i];

	printf("\n Introdu quantum : ");
	scanf("%d",&Q);

	for(k=0;;k++){
		if(k>n-1)
			k=0;
		if(temp1[k].timpOcupare>0)
			printf("  %d  %s",timpCurent,temp1[k].nume);
		t=0;
		while(t<Q && temp1[k].timpOcupare > 0){
			t++;
			timpCurent++;
			temp1[k].timpOcupare--;
		}
		if(temp1[k].timpOcupare <= 0 && temp1[k].verificat != 1){
			temp1[k].timpAsteptare = timpCurent - temp2[k].timpOcupare - temp1[k].timpInceput;
			temp1[k].timpProcesare = timpCurent - temp1[k].timpInceput;
			nrProceseVerif++;
			temp1[k].verificat = 1;
			sumaTimpAsteptare+=temp1[k].timpAsteptare;
			sumaTimpProcesare+=temp1[k].timpProcesare;
		}
		if(nrProceseVerif == n)
			break;
	}
	printf("  %d",timpCurent);
	timpMediuAsteptare = (float)sumaTimpAsteptare/n;
	timpMediuProcesare = (float)sumaTimpProcesare/n;
	printf("\n\n Timpul mediu de asteptare = %0.2f\n Timpul mediu de procesare = %0.2f.",timpMediuAsteptare,timpMediuProcesare);
}

//Shortest Job First - Pre-emptive
void SJF_P(procese P[],int n){
	int i,t_total=0,timpCurent,b[10],min_timpInceput,j,x,min_timpOcupare;
	int sumaTimpAsteptare=0,sumaTimpProcesare=0;
	float timpMediuAsteptare=0.0,timpMediuProcesare=0.0;
	procese temp[10],t;

	for(i=0;i<n;i++){
		temp[i]=P[i];
		t_total+=P[i].timpOcupare;
	}

	b_sort(temp,n);

	for(i=0;i<n;i++)
		b[i] = temp[i].timpOcupare;

	i=j=0;
	printf("\n GANTT CHART\n\n %d %s",i,temp[i].nume);
	for(timpCurent=0;timpCurent<t_total;timpCurent++){

		if(b[i] > 0 && temp[i].timpInceput <= timpCurent)
			b[i]--;

		if(i!=j)
			printf(" %d %s",timpCurent,temp[i].nume);

		if(b[i]<=0 && temp[i].verificat != 1){

			temp[i].verificat = 1;
			temp[i].timpAsteptare = (timpCurent+1) - temp[i].timpOcupare - temp[i].timpInceput;
			temp[i].timpProcesare = (timpCurent+1) - temp[i].timpInceput;
			sumaTimpAsteptare+=temp[i].timpAsteptare;
			sumaTimpProcesare+=temp[i].timpProcesare;
		}
		j=i;	min_timpOcupare = 999;
		for(x=0;x<n;x++){

			if(temp[x].timpInceput <= (timpCurent+1) && temp[x].verificat != 1){

				if(min_timpOcupare != b[x] && min_timpOcupare > b[x]){
					min_timpOcupare = b[x];
					i=x;
				}
			}
		}

	}
	printf(" %d",timpCurent);
	timpMediuAsteptare = (float)sumaTimpAsteptare/n;	timpMediuProcesare = (float)sumaTimpProcesare/n;
	printf("\n\n Timpul mediu de asteptare = %0.2f\n Timpul mediu de procesare = %0.2f.",timpMediuAsteptare,timpMediuProcesare);
}


void PRT_P(procese P[],int n){
	int i,t_total=0,timpCurent,b[10],j,x,min_pr;
	int sumaTimpAsteptare=0,sumaTimpProcesare=0;
	float timpMediuAsteptare=0.0,timpMediuProcesare=0.0;
	procese temp[10],t;

	for(i=0;i<n;i++){
		temp[i]=P[i];
		t_total+=P[i].timpOcupare;
	}

	b_sort(temp,n);

	for(i=0;i<n;i++)
		b[i] = temp[i].timpOcupare;

	i=j=0;
	printf("\n GANTT CHART\n\n %d %s",i,temp[i].nume);
	for(timpCurent=0;timpCurent<t_total;timpCurent++)
	{

		if(b[i] > 0 && temp[i].timpInceput <= timpCurent)
			b[i]--;

		if(i!=j)
			printf(" %d %s",timpCurent,temp[i].nume);

		if(b[i]<=0 && temp[i].verificat != 1)
		{
			temp[i].verificat = 1;
			temp[i].timpAsteptare = (timpCurent+1) - temp[i].timpOcupare - temp[i].timpInceput;
			temp[i].timpProcesare = (timpCurent+1) - temp[i].timpInceput;
			sumaTimpAsteptare+=temp[i].timpAsteptare;
			sumaTimpProcesare+=temp[i].timpProcesare;
		}
		j=i;
		min_pr = 999;
		for(x=0;x<n;x++){

			if(temp[x].timpInceput <= (timpCurent+1) && temp[x].verificat != 1){

				if(min_pr != temp[x].prioritate && min_pr > temp[x].prioritate){
					min_pr = temp[x].prioritate;
					i=x;
				}
			}
		}

	}
	printf(" %d",timpCurent);
	timpMediuAsteptare = (float)sumaTimpAsteptare/n;
	timpMediuProcesare = (float)sumaTimpProcesare/n;
	printf("\n\n Timpul mediu de asteptare = %0.2f\n Timpul mediu de procesare = %0.2f.",timpMediuAsteptare,timpMediuProcesare);
}


int main(){

	procese P[10];
	int ch,n;
	do{
		printf("\n\n SIMULARE ALGORITMI DE SCHEDULING\n");
		printf("\n Optiuni:");
		printf("\n 0. Introdu informatiile procesului.");
		printf("\n 1. FCFS");
		printf("\n 2. SJF (Pre-emptive)");
		printf("\n 3. SJF (Non Pre-emptive)");
		printf("\n 4. Priority Scheduling (Pre-emptive)");
		printf("\n 5. Priority Scheduling (Non Pre-emptive)");
		printf("\n 6. Round Robin");
		printf("\n 7. Exit\n Optiunea ta : ");
		scanf("%d",&ch);
		switch(ch){
			case 0:
				n=accept(P);
				break;
			case 1:
				FCFS(P,n);
				break;
			case 2:
				SJF_P(P,n);
				break;
			case 3:
				SJF_NP(P,n);
				break;
			case 4:
				PRT_P(P,n);
				break;
			case 5:
				PRT_NP(P,n);
				break;
			case 6:
				RR(P,n);
				break;
			case 7:exit(0);
		}
	}while(ch != 7);
	return 0;
}
