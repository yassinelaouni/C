#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
int main(){ 
 FILE *pFile1, *pFile2; 
 char nom[30], newNom[30]; 
 int i,n,newMatricule, matricule, trouve; 
  
 
 pFile1 = fopen("file1.txt", "w+"); 
 if(pFile1==NULL){ 
 printf("erreur d ouverture du fichier\n"); 
 } 
 printf("indiquez le nombre d enregistrements\n"); 
 scanf("%d",&n); 
  for(i=1; i<=n; i++){ 
 printf("pour l enregistrement %d:\n",i); 
 printf("donner le nom: \n"); 
 scanf("%s",nom); 
 printf("donner la matricule: "); 
 scanf("%d",&matricule); 
 fprintf(pFile1,"%s %d\n",nom,matricule); 
 } 
 fclose(pFile1); 
 

 
 pFile1 = fopen("file1.txt", "r"); 
 if(pFile1==NULL){ 
 printf("erreur d ouverture du fichier\n"); 
 } 
 
 while(feof(pFile1)==0){ 
 fscanf(pFile1,"%s %d\n",nom,&matricule); 
 printf("nom: %s\n", nom); 
 printf("Matricule: %d\n", matricule); 
 } 
 fclose(pFile1); 

 
 printf("Saisir un nouvel enregistrement\n"); 
 printf("Saisir le nom: "); 
 scanf("%s", newNom); 
 printf("Saisir la matricule: "); 
 scanf("%d",&newMatricule); 
 
 pFile1 = fopen("file1.txt", "r"); 
 if(pFile1==NULL){ 
 printf("Erreur d ouverture du fichier"); 
 } 
 pFile2 = fopen("file2.txt", "w"); 
 if(pFile2==NULL){ 
 printf("Erreur d ouverture du fichier"); 
 } 
 
 trouve = 0; 
 while(feof(pFile1)==NULL && trouve==0){ 
 fscanf(pFile1, "%s %d\n",nom, &matricule); 
 if(strcmp(nom,newNom)>0){ 
 trouve = 1; 
 } 
 else{ 
 fprintf(pFile2,"%s %d\n",nom, matricule); 
 } 
 } 
 fprintf(pFile2,"%s %d\n",newNom, newMatricule); 
 if(trouve==1){ 
 fprintf(pFile2,"%s %d\n",nom, matricule); 
 } 
 while(feof(pFile1)==NULL){ 
 fscanf(pFile1, "%s %d\n",nom, &matricule); 
 fprintf(pFile2,"%s %d\n",nom, matricule); 
 } 
 
 fclose(pFile1); 
 fclose(pFile2); 
 printf("voisi le contenu du file2.txt /n ");
 pFile2 = fopen("file2.txt", "r"); 
 if(pFile2==NULL){ 
 printf("erreur d ouverture du fichier\n"); 
 }
 else{
 
 while(feof(pFile2)==0){ 
 fscanf(pFile2,"%s %d\n",nom,&matricule); 
 printf("nom: %s\n", nom); 
 printf("Matricule: %d\n", matricule); 
 } 
 }
 fclose(pFile2); 
 
}