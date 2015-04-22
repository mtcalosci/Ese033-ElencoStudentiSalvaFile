#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definisci le costanti
#define N 5
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome [MAX_STRLEN];
    char cognome [MAX_STRLEN];
    unsigned int eta;
    char classe [MAX_STRLEN];
};

// Definisci studente come struct s_studente
struct s_studente studente[N];


int main(int argc, char** argv) {
    // Dichiara le variabili locali
    int i;
    FILE *puntaFile;
    
    
    // Codice per l'inserimento, da parte dell'utente, dei dati in un array
    for(i = 0; i < N; i++) {
        printf("Inserisci il nome del %d° alunno: ", i+1);
        scanf("%s", studente[i].nome);
        printf("Inserisci il cognome del %d° alunno: ", i+1);
        scanf("%s", studente[i].cognome);
        printf("Inserisci l'eta' del %d° alunno: ", i+1);
        scanf("%d", &(studente[i].eta));
        printf("Inserisci la classe del %d° alunno: ", i+1);
        scanf("%s", studente[i].classe);
    }
    
    // Codice per la scrittura dell'elenco su file
    puntaFile = fopen("elenco.dat","wb");
    if(puntaFile) {
    fwrite(&studente,sizeof(studente),N,puntaFile);
    fclose(puntaFile);
    }
    
    else 
        printf("Non sono riuscito a scrivere sul file");
    return (EXIT_SUCCESS);
}
