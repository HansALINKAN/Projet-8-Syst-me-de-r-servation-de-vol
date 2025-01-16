#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct vol {
    char code[10];
    char destination[50];
    char date[11];
    int sieges;
};
int b, i;
struct vol v[100];
void EnregistrerVol()
    {

    char admin_choice;
    char buffer[2];


        printf("Bienvenue admin\n");
        printf("Combien de vols voulez vous enregistrer ? ");
        scanf("%d", &b);
        gets(buffer);


        FILE *fichier = fopen("InformationsVol.txt", "a");
        if (fichier == NULL)
            {
            perror("Erreur d'ouverture du fichier");
            return 1;
        }


        fprintf(fichier, "%d\n", b);

        for (i = 0; i < b; i++)
            {
            printf("\n=== Vol %d ===\n", i + 1);

            printf("Code du vol : ");
            scanf("%9s", v[i].code);
            gets(buffer);

            printf("Destination : ");
            scanf("%49s", v[i].destination);
            gets(buffer);

            printf("Date de depart (JJ/MM/AAAA) : ");
            scanf("%10s", v[i].date);
            gets(buffer);

            printf("Nombre de sieges disponibles : ");
            scanf("%d", &v[i].sieges);
            gets(buffer);


            fprintf(fichier, "%s %s %s %d\n",v[i].code,v[i].destination,v[i].date,v[i].sieges);
        }

        fclose(fichier);
        printf("\nEnregistrement des vols termine avec succes!\n");


}
