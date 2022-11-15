/* Programa para encontrar la subsecuencia comun más larga entre una especie nueva y otras especies conocidas */

//Librerias utiliazadas
#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

//Funcion para encontrar la LCS más larga
int lcs(char* X, char* Y, int m, int n, string NX , string N)
{
    int L[m + 1][n + 1]; //Se crea una matriz para ir encontrando las subsecuencias
    int i, j;
    //Se recorren ambas secuecuencias de ADN
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) // En la primera posicion de la matriz
                L[i][j] = 0; //se pone un cero
  
            else if (X[i - 1] == Y[j - 1]) //Si coinciden los elementos en la misma posicion
                L[i][j] = L[i - 1][j - 1] + 1; //Se suma uno a la posicion en la matriz
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);//Se busca el numero mas grande entre la posicion actual de la matriz y su antecesor
        }
    }

    int index = L[m][n];
    char lcs[index + 1]; //Se crea el arreglo con la subsecuencia encontrada
    lcs[index] = '\0';  // se pone el indice en el elemento final
    i = m; 
    j = n;

    //Se comienza  la matriz en la esquina inferior derecha.
    while (i > 0 && j > 0) {
        //Si los elementos en ambos arreglos coinciden se guarda este valor en el nuevo arreglo de subsecuencia 
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1]
                = X[i - 1]; 
            i--;
            j--;
            index--; 
        }
        else if (L[i - 1][j] > L[i][j - 1]) //Si no se encientra el mayor entre ambos y se reocorre en ese sentido
            i--;
        else
            j--;
    }
    //Se imprime la subsecuencia
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout << "            LCS of " << NX << " and " << N << " is " << lcs<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    
    //Se regresa el tamaño de la subsecuencia
    return L[m][n];
}
  
//Funcion para encontrar el valor maximo entre dos numeros
int max(int a, int b)
{
    return (a > b) ? a : b;
}

//Funcion para encontrar el 35% porciento del tamaño de la secuencia
int percent(int m){
    int p=(m*35)/100;
    return p;
}

int main(){
    //Declaracion del nombre de la nueva especie
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------The new species found is called: Mr. Potato Head---------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;

    //Deckaracion de secuencias de ADN
    char NS[] = "VLREVQLPIWEHEACRQAYEKDLNITNVYMCAGFADGGKDACQGDSGGPMMLPVKTGEFYLIGIVSFGKKCALPGFPGVYTKVTEFLDWIAEHMV";
    char SB[] = "MIILWSLIVHLQLTCLHLILQTPNLEALDALEIINYQTTKYTIPEVWKEQPVATIGEDVDDQDTEDEESYLKFGDDAEVRTSVSEGLHEGAFCRRSFDGRSGYCILAYQCLHVIREYRVH";
    char BP[] = "WMTAVYIKQGGIRSVQCGGALVTNRHVITASHCVVNSAGTDVMPADVFSVRLGEHNLYSTDDDSNPIDFAVTSVKHHEHFVLATYLNDIAILTLNDTVTFTDRIRPICLPYRKLRYDDLAMRKPFITGWGTTAFNGPSSA";
    char PS[] = "EPKKVKDHCSKHSPCQKGGTCVNMPSGPHCLCPQHLTGNHCQKEKCFEDKSKTCYEELHQVPSNCD";
    char PP[] = "GTRIDICTHRNNVPVICCPLADKHVLAQRISATKCQEYNAAARRLHLTDTGRTFSGKQCVPSVPLIVGGTPTRHGLFPHMAALGWTQGSGSKDQDIKWGCGGALVSELYVLTAAHCATSG";
    char PK[] = "IEGQFCAGYLPGGRDTCQGDSGGPIHALLPEYNCVAFVVGITSFGKFCAAPNAPGVYTRLYSYLDWIEKIAFKQH";
    char RS[] = "GTRIDSKPPDMVRLGARQLNETSATQQDIKILIIVLHPKYRSSAYYHDIALLKLTRRVKFSEQVRPACLWQLPELQIPTVVAAGWGRTEFLGAKSNALRQVDLDVVPQMTCKQIYRKERRLPRGI";
    char SP[] = "MLVNNVFSLLCFPLLMSVVRCSTLSRQRRQFVFPDEEELCSNRFTEEGTCKNVLDCRILLQKNDYNLLKESICGFEGITPKVCCPKSSHVISSTQAPPETTTTERPPKQIPPNLPEVCGIHNTTTTRIIGGREAPIGAWP";

    //Arreglo de nombres de esecies
    string species[] = {"Sponge Bob","Black Panther","Patrick Star", "Perry the Platypus", "Pickachu", "Rick Sapiens", "Spiderman"};
    string name="Mr. Potato Head";

    //Calculo del tamaño de cada cadena de caracteres
    int m = strlen(NS);
    int nsb = strlen(SB);
    int nbp = strlen(BP);
    int nps = strlen(PS);
    int npp = strlen(PP);
    int npk = strlen(PK);
    int nrs = strlen(RS);
    int nsp = strlen(SP);
    //Arreglo de tamaño de especies
    int nss[]={nsb,nbp,nps,npp,npk,nrs,nsp};

    //Calculo de subsecuencias de cada especie con la nueva
    int lcsSB = lcs(NS, SB, m, nsb, name, species[0]);
    int lcsBP = lcs(NS, BP, m, nbp, name, species[1]);
    int lcsPS = lcs(NS, PS, m, nps, name, species[2]);
    int lcsPP = lcs(NS, PP, m, npp, name, species[3]);
    int lcsPK = lcs(NS, PK, m, npk, name, species[4]);
    int lcsRS = lcs(NS, RS, m, nrs, name, species[5]);
    int lcsSP = lcs(NS, SP, m, nsp, name, species[6]);
    //Arreglo de subsecuencias de especies
    int lcss[]={lcsSB,lcsBP,lcsPS,lcsPP,lcsPK,lcsRS,lcsSP};


    int lcsMAX=0;
    int indice;
    int p;
    //Se busca la subsecuencia más larga y que sea al menos el 35% del tamaño de la especie
    for (int i=0; i<7;i++){
        p=percent(nss[i]);
        if(lcss[i]>=p){
            if (lcss[i]>lcsMAX){
                indice=i;
                lcsMAX=lcss[i];
            }
        }
    }
    if(lcsMAX==0){
        cout<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"              Mr. Potato Head can't be associated with any known species "<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    }
    else{
        cout<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"      The longest LCS is between Mr. Potato Head and "<<species[indice]<<" with a lenght of: "<<lcsMAX<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    }
  
    return 0;
}
