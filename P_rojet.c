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

void ReserverVol(){
    printf("Bienvenue sur FlyNow\n");

    int trouve = 0;
    char codeVol[10];
    char ligne[100];



    FILE *fichier = fopen("InformationsVol.txt", "r+");
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }


    if (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        sscanf(ligne, "%d", &b);
    }


    for (i = 0; i < b && fgets(ligne, sizeof(ligne), fichier) != NULL; i++) {
        sscanf(ligne, "%s %d", v[i].code, &v[i].sieges);
    }
    printf("Veuillez entrer le code du vol pour reserver un siege : ");
    scanf("%s", codeVol);
    for (i = 0; i < b; i++) {
        if (strcmp(v[i].code, codeVol) == 0) {
            trouve = 1;
            if (v[i].sieges > 0) {
                v[i].sieges--;
                printf("Reservation reussie ! Il reste %d sieges disponibles pour le vol %s.\n",
                       v[i].sieges, v[i].code);
                rewind(fichier);
                fprintf(fichier, "%d\n", b);
                for (int j = 0; j < b; j++) {
                    fprintf(fichier, "%s %d\n", v[j].code, v[j].sieges);
                }
            } else {
                printf("Desole, il n'y a plus de sieges disponibles pour ce vol.\n");
            }
            break;
        }
    }

    if (!trouve) {
        printf("Vol non trouve.\n");
    }

    fclose(fichier);

    return 0;            
        }

void AnnulerVol(){
   printf("Bienvenue sur FlyNow\n");

    int trouve = 0;
    char codeVol[10];
    char ligne[100];



    FILE *fichier = fopen("InformationsVol.txt", "r+");
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }


    if (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        sscanf(ligne, "%d", &b);
    }


    for (i = 0; i < b && fgets(ligne, sizeof(ligne), fichier) != NULL; i++) {
        sscanf(ligne, "%s %d", v[i].code, &v[i].sieges);
    }
    printf("Veuillez entrer le code du vol pour annuler la réservation : ");
    scanf("%s", codeVol);
    for (i = 0; i < b; i++) {
        if (strcmp(v[i].code, codeVol) == 0) {
            trouve = 1;
            if (v[i].sieges > 0) {
                v[i].sieges++;
                printf("Annulation reussie ! Il reste %d sieges disponibles pour le vol %s.\n",
                       v[i].sieges, v[i].code);
                rewind(fichier);
                fprintf(fichier, "%d\n", b);
                for (int j = 0; j < b; j++) {
                    fprintf(fichier, "%s %d\n", v[j].code, v[j].sieges);
                }
            } else {
                printf("Tout les sieges sont disponibles.\n");
            }
            break;
        }
    }

    if (!trouve) {
        printf("Vol non trouve.\n");
    }

    fclose(fichier);

    return 0;
}
void AfficherVol()
{
    char ligne[100];
    printf("Vols disponibles:\n");

           FILE *fichier = fopen("InformationsVol.txt","r");
            if(fichier==NULL){
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

            if (fgets(ligne, sizeof(ligne), fichier) != NULL)
            {
                sscanf(ligne, "%d", &b);
            }
            for(i=0;i<=b && fgets(ligne, 100, fichier)!=NULL;i++)
            {
                if(sscanf(ligne,"%s %s %s %d",v[i].code,v[i].destination,v[i].date,&v[i].sieges)==4);
                printf("Code:%s\t Destination:%s\t Date:%s\t Nombre de sieges:%d\n",v[i].code,v[i].destination,v[i].date,v[i].sieges);
            }

           fclose(fichier);
            }

int main()
{

    int choix;
    do {
        printf("\nMenu :\n");
        printf("1. Ajouter un vol\n");
        printf("2. Réserver un siège\n");
        printf("3. Annuler un siège\n");
        printf("4. Afficher les vols\n");
        printf("5. Sauvegarder les données\n");
        printf("6. Charger les données\n");
        printf("7. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                EnregistrerVol();
                break;
            case 2:
                ReserverVol();
                break;
            case 3:
                AnnulerVol();
                break;
            case 4:
                AfficherVol();
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 5);

 return 0 ;
}
