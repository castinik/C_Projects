#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>

/// dati del personaggio.
float eta, esperienza, patrimonio, entrate, uscite, amorte, gmorte, psuccesso = 50, pinsuccesso = 50;

/// dati di modifica ed esecuzione.
void cvfare(int i);
void mex (int i);
int azione;
int messaggi;
char stringa[200];
// scuola
float anniscuola, giornoscolastico;
int scuola;
// lavoro
float annilavoro, giornolavoro, paga;
int lavoro, qualita;


int main()
{
    printf("\n Benvenuto nel gioco della vita");
    printf("\n\n Quanti anni hai?\n");
    scanf("%f", &eta);
    printf("\n\nCon quanto vuoi iniziare?\n");
    scanf("%f", &patrimonio);
    system("cls");

    //amorte per default, 80 anni complessivi.
    gmorte = 364.25*80 - eta*364.25;
    amorte = gmorte/364.25;
    //variabili inizializzate.
    scuola = 0;
    giornoscolastico = 0;
    psuccesso = 50;
    pinsuccesso = 50;
    azione = 0;

    for (float giorno = 0; giorno < gmorte; giorno++) {

        system("cls");
        printf(" %f anni - - - - - Patrimonio: %f € - - - - - Presumibile dipartita tra: %f anni - %f giorni\n\n", eta, patrimonio, amorte, gmorte);
        printf(" Probabilità di successo: %f % - - - - - Probabilità di insuccesso: %f % \n\n", psuccesso, pinsuccesso);

        //gestione messaggi all'utente.
        printf(" Messaggi: ");
        mex(messaggi);

        //gestione processo lavoro
        switch (lavoro) {
            case 1: //lavoro bassa qualità
                paga = 1100;
                giornolavoro++;
                psuccesso = psuccesso + (psuccesso / 100) * 0.01;
                pinsuccesso = pinsuccesso - ((psuccesso / 100) * 0.01);
                printf("\n Paga media: 1100 euro \n");
                printf(" Lavoro da %f  anni \n\n", giornolavoro/364.25);
                patrimonio = patrimonio + (paga / 30.35);
                break;
        }

        //gestione processo scuola
        if (scuola != 0) {
            giornoscolastico++;
            psuccesso = psuccesso + (psuccesso / 100) * 0.03;
            pinsuccesso = pinsuccesso - ((psuccesso / 100) * 0.03);
            printf(" \nScuola %f su %f anni \n\n", giornoscolastico/364.25, anniscuola);
            if (anniscuola <= giornoscolastico/364.25) {
                scuola = 0;
                giornoscolastico = 0;
                messaggi = 1;
                getch();
            }
        }
        printf("------------------------------------------------------------------------------------------------------\n\n");

        //chiamata del void azione con qualsiasi tasto premuto in qualsiasi momento
        if(kbhit()) {
            azione = 1;
            cvfare(azione);
            azione = 0;
        }

        //gestione dei giorni di vita
        eta = eta + (1/364.25);
        gmorte--;
        amorte = gmorte/364.25;
    }
    printf("\n\n\n ---Sei morto--- \n\n\n");

    printf("\n\n\n\n\n\n\n\n\n");
    return 0;
}
void cvfare(int i) {
    int risposta;
    if (i = 1) {
        system("cls");
        printf(" Per iniziare . . . \n Cosa vuoi fare?\n Andare a studiare o andare a lavorare?");
        printf("\n O smettere di studiare o lavorare?\n premi reciprocamente 0 - 1 - 2 - 3 per rispondere ");
        scanf("%d", &risposta);
        switch (risposta) {
            case 0: //scuola
               system("cls");
               scuola = 1;
               printf(" Per quanti anni vuoi studiare? \n");
               scanf("%f", &anniscuola);
            break;
            case 1: //lavoro
               system("cls");
               printf(" Che tipo di lavoro cerchi? \n Qalita' bassa -> 0\n Qualita' media -> 1\n Qualita' alta -> 2 \n");
               scanf("%d", &qualita);
               switch (qualita) {
                   case 0: // bassa
                       if(psuccesso > 45) {
                           lavoro = 1;
                       }
                       else system("cls"); mex(2);
                       break;
                   case 1: // media
                       if(psuccesso > 75) {
                           lavoro = 2;
                       }
                       else system("cls"); mex(2);
                       break;
                   case 2: // alta
                       if(psuccesso > 90) {
                           lavoro = 3;
                       }
                       else system("cls"); mex(2);
                }
                break;
            case 2:
               scuola = 0;
               break;
            case 3:
               lavoro = 0;
               break;
        }
        azione = 0;
    }
    else return;
}
void mex(int i) {
    switch (i) {
    case 0:
        printf(" Premi qualsiasi tasto per eseguire un'azione!\n\n");
        break;
    case 1:
        printf(" Hai finito la scuola!\n\n\n\n Premi qualsiasi tasto per continuare \n\n");
        messaggi = 0;
        getch();
        break;
    case 2:
        printf(" Non hai avuto abbastanza successo per ottenere questo lavoro! \n Premi qualsiasi tasto per continuare\n\n");
        getch();
        break;
        }
    return;
}
