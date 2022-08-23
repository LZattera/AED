/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de cada variavel usando os ponteiros. Imprima os valores das variaveis antes e ap ´ os a ´
modificac¸ao*/

#include<stdio.h>
int main(){
    //variaveis
    int inteiro = 1;
    char caracter = 'a';
    float real = 0.5;
    //Ponteiros
    int *pInteiro;
    char *pCaracter;
    float *pReal;
    //Associando valores com os ponteiros
    pCaracter = &caracter;
    pInteiro = &inteiro;
    pReal = &real;
    //Modificando os valores usando ponteiros
    *pCaracter = 'b';
    *pInteiro = 5;
    *pReal = 1.5;
    //Imprimindo os valores
    printf("PONTEIRO: %d VARIVEL: %d\n", *pInteiro, inteiro);
    printf("PONTEIRO: %c VARIVEL: %c\n", *pCaracter, caracter);
    printf("PONTEIRO: %f VARIVEL: %f\n", *pReal, real);

    return 0;    
}