#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int verifierRegion(int k, int l, int table[9][9]);
int verifierLigneColonne(int num, const int dir, int table[9][9]);
/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1 
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/


// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls

// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/


int generer(int table[9][9]){
    int nbr = 0;
    for(int k = 0; k < 9; k++){
        for(int l = 0; l < 9; l++){
            if (table[k][l] != 0){
                nbr = nbr + 1;
            }
        }
    }
    return nbr;
}


/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/

int saisir(int remplissage, int table[9][9]){
    int i;
    int j;
    int v;

    do {
        printf("Enter the index i: ");
        scanf("%i", &i);
    }while (i > 10 || i < 0);

    do {
        printf("\nEnter the index j: ");
        scanf("%i", &j);
    }while(j > 10 || j < 0);

    do {
        printf("\nEnter the value: ");
        scanf("%i", &v);
    }while(v > 10 || v < 0);

    if(table[i][j] != 0){
        printf("\nThat slot is already taken \n \n");
    }
    else{
        table[i][j] = v;
        remplissage += 1;
        if(verifierRegion(i, j, table) == 0 || verifierLigneColonne(i, 0, table) == 0 || verifierLigneColonne(j, 1, table) == 0){
            table[i][j] = 0;
            remplissage -= 1;
            printf("\nThe entered value is not valid \n \n");
        }
    }

    return remplissage;

}


/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/

int verifierLigneColonne(int num, const int dir, int table[9][9]){
    int values[9][2] = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
    for(int i = 0; i < 9; i++){
        if(dir == 0){
            for(int h = 0; h < 9; h++){
                if(table[num][i] == values[h][0]){
                    values[h][1] += 1;
                }
            }
        }else{
            for(int a = 0; a < 9; a++){
                if(table[i][num] == values[a][0]){
                    values[a][1] += 1;
                }
            }
        }
    }
    //int len = sizeof(values) / sizeof(values[0]);
    for(int k = 0; k < 9; k++){
        if(values[k][1] > 1){ //checks if all numbers appear only once in the row or column, here being represented by the list values
            return 0;
        }
    }
    return 1;
}

/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/

int verifierRegion(int k, int l, int table[9][9]){
    int values[9][2] = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
    int x = k;
    int y = l;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int index = 0; index < 9; index++){
                if(table[x][y] == values[index][0]){
                    values[index][1] += 1;
                } 
            }
            y += 1;
        }
        x += 1;
        y = l;
    }
    //int len = sizeof(values) / sizeof(values[0]);
    for(int s = 0; s < 9; s++){
        if(values[s][1] > 1){ //checks if all numbers appear only once area, here being represented by the list values
            return 0;
        }
    }
    return 1;
}

//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon

int verifierGrille(int table[9][9]){
    int x = 0; //x and y are the coordinates for the region
    int y = 0;
    int totalRegion = 0;
    int totalRows = 0;
    int totalColumns = 0;
    for(int i = 0; i < 9; i++){

        int rows = verifierLigneColonne(i, 0, table);
        if(rows == 1){
            totalRows += 1;
        }

        int columns = verifierLigneColonne(i, 1, table);
        if(columns == 1){
            totalColumns += 1;
        }
    }

    for(int m = 0; m < 3; m++){
        for(int n = 0; n < 3; n++){
            int region = verifierRegion(x, y, table);
            y += 3;
            if(region == 1){
                totalRegion += 1;
            }
        }
    x += 3;
    y = 0;
    }

    if(totalColumns == 9 && totalRows == 9 && totalRegion == 9){
        return 1;
    }else{
        return 0;
    }
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
        solution[j][i] = (i + j*3 +j /3) %9 +1 ; 
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

    int random = rand() % 9 + 1; 
    int table[9][9] = {{0,9,0,2,0,0,6,0,5},{3,2,0,0,0,7,0,0,0},{0,7,0,9,0,5,0,0,8},
                       {0,1,0,0,0,0,0,0,0},{0,0,7,0,0,0,0,9,4},{6,0,0,0,0,0,0,0,0},
                       {0,0,8,0,0,0,0,0,7},{0,3,0,4,9,1,5,0,0},{0,0,0,0,0,3,0,0,0}};

    for(int z=0;z<9; ++z) //first display the unfilled table
    {
        for(int o=0; o<9; ++o)
            printf("%d ", table[z][o]);
        printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");

    int remplissage = generer(table);

    while(remplissage < 89){

        remplissage = saisir(remplissage, table);
    
        for(int m = 0;m < 9; ++m) //every time the user changes a value, print the updated table
        {
            for(int n = 0; n < 9; ++n)
                printf("%d ", table[m][n]);
            printf("\n");  
        }
        printf("---------------------------------");  
        printf("\n");

    }

    int result = verifierGrille(table);
    if(result == 1){
        printf("The table has been successfully completed with no errors \n");
        return 1; //stop the function when the table has successfully been completed
    }else{
        printf("The table contains errors \n");
    }

    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}

