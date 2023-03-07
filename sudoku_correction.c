#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1 
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/

/*int verifyContinue(int tab[9][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(tab[i][j]){

            }else{

            }
        }
    }
}*/

int isTurning(int tab[9][9]){
    int nbr = 0;
    for(int i = 0; i < 9; i++){
        for(int k = 0; k < 9; k++){
            if(tab[i][k] == 0){
                nbr += 1;
            }
        }
    }
    return nbr;
}


void copyArray(int tab[9][9], int copy[9][9] ){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            copy[i][j] = tab[i][j];
        }
    }
}


void afficher(int tab[9][9]){
    // printf("|X,Y");
    printf("| Y\\X  ");

    for(int i = 0; i < 9; i++){
        printf("| %d ", i);
    }
        printf("|\n");

    for(int i = 0; i < 10; i++){
        printf("----");
    }


    for(int i = 0; i < 9; i++){
        printf("\n");
        printf("| %d >  ", i);
        for(int j = 0; j < 9; j++){
            printf("| %d ", tab[i][j]);
        }
        printf("|\n");
    }
        printf("\n");

}

/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
 Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/
int verifierLigneColonne(int tab[9][9], int ligne, int ligneOrCol ){

    int choices[9] = {0,0,0, 0,0,0, 0,0,0};
    int result = 0;
    if(ligneOrCol){
        for(int i = 0; i < 9; i++){
            int numero = tab[i][ligne];
            if(tab[i][ligne] > 0){
                int numero = tab[i][ligne];
                // printf( "\n\n NUM %d", numero -1 );
                choices[numero - 1] = choices[numero- 1] + 1 ;
            }
        }
    } else {
        for(int i = 0; i < 9; i++){
            if(tab[ligne][i]){
                int numero = tab[ligne][i];
                choices[numero - 1] = choices[numero- 1] + 1 ;
            }
        }
    }
    for(int i = 0; i < 9; i++){
        if(choices[i] > 1){
            result = 1; 
        } 
    }
return result;
}
/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/
int verifierRegion(int tab[9][9],int i ,int j){
    int values[9][2] = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
    int x = i;
    int y = j;
    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3; b++){
            for(int c = 0; c < 9; c++){
                if(values[c][0] = tab[x][y]){
                    values[c][1] += 1;
                }
            }
            x += 1;
        }
        y += 1;
    }

    for(int d = 0; d < 9; d++){
        if(values[d][1] > 1){
            return 0;
        }
    }

    return 1;
}

// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls
void generate(int tab[9][9], int copyTableau[9][9]){
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            // if(!(rand() % 2)){
            if((rand() % 100) < 97){
                copyTableau[i][j] = tab[i][j];
            }
        }
    }

}
// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/
//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon
int verifierGrille(int tab[9][9]){

    int isCorrect =1;
    for(int i = 0; i < 9; i++ ){
    int verifLigne = verifierLigneColonne(tab, i, 1);
    int verifCol = verifierLigneColonne(tab, i, 0);
    if(verifCol || verifLigne){
        printf("\n\nAhrf, il semblerait que votre solution ne corresponde pas aux regles, reessayez !\n\n");
        isCorrect = 0;
    }
    }
    for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
        if(verifierRegion(tab, i, j ) == 0){
            isCorrect = 0;
        }else{
            isCorrect = 1;
        }
    }
    }



    return isCorrect;
}

/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/
int saisir(int tab[9][9]){

    int result = 0;

    while (result == 0)
    {
        int tableauTest[9][9] = {
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},

            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0}
        };
        copyArray(tab, tableauTest);
        int saisie = 0;
        // int saisieX = 0;
        // int saisieY = 0;

        printf("Veuillez saisir un Y\n");
        scanf("%d", &saisie);
        int saisieX = saisie;
        printf("Veuillez saisir un X\n");
        scanf("%d", &saisie);
        int saisieY = saisie;

        if(tab[saisieX][saisieY]){
            printf("Cette case est deja remplie Reessayez\n");
        } else {
            printf("Quelle valeur souhaitez vous inserer ?\n");
            scanf("%d", &saisie);
            int saisieVal = saisie;
            tableauTest[saisieX][saisieY] = saisieVal;
        
            result = verifierGrille(tableauTest);
            if(result == 1 ){
                tab[saisieX][saisieY] = saisieVal;
            }
        }
    }
    return result;
} 







//Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)


int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    int solution[9][9];
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  
    for(j=0;j<9; ++j) 
    {
    for(i=0; i<9; ++i)
        solution[j][i] = (i + j*3 +j /3) % 9 +1 ; 
    }
    
    for(i=0;i<9; ++i) 
    {
    for(j=0; j<9; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 
    int tableauJoueur[9][9] = {
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},

        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
    };

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d ", tableauJoueur[i][j]);
        }
        printf("\n");
    }
    int isTurning = 0;
    generate(solution, tableauJoueur);
    do{
        afficher(tableauJoueur);
        saisir(tableauJoueur);
        //isTurning = verifyContinue(tableauJoueur);
        isTurning = verifierGrille(tableauJoueur);
    } while(isTurning);
    printf("Bravo, vous avez reussi l'epreuve du sudoku");
    // while (verifierGrille(tableauJoueur) != 0)
    // {
        
    // }
    

    // printf("%d",rand() % 2);
    
  



    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}