#include <stdio.h>

/*

--------1. Lösung selber erarbeitet
Jedoch wenn eine ungüeltige Note eingegeben wird, wiederholt es
den Step nicht, sondern springt zur nächsten Eingabe.
Via Chat GPT habe ich mir erklären lassen, dass mit einer while schleife in der for schleife
dies gelöst werden kann.


int main() {
    float noten[10];    // Array für die 10 Noten
    float summe =0;        // Variable für die Summe
    float durchschnitt; // Variable für den Durchschnitt
    int i;

    for (int i = 0; i < 10; i++) {
        printf("Geben Sie die %d. Note ein:", i+1);     // Noten vom Benutzer eingeben
        scanf("%f", &noten[i]);

        if (noten[i] < 1 || noten[i] > 6) {		                  // Abbruch mit break, wenn Note ungültig
            printf("Ungueltige Eingabe, Note muss zwischen 1 und 6 sein.");
            continue;
        }

        summe += noten[i];                                    // Noten zur Summe hinzufügen
    }
// Durchschnitt berechnen
durchschnitt = summe/i;

printf("\nSumme aller Noten ist: %.2f\n", summe);
printf("Durchschnitt aller Noten ist: %.2f\n", durchschnitt);

// Array (Noten) ausgeben
printf("Eingegebene Noten: ");
for (int i = 0; i < 10; i++) {
    printf("%.2f ", noten[i]);
}
printf("\n");

return 0;
}
*/

int main() {
    float noten[10];    // Array für die 10 Noten
    float summe = 0;    // Variable für die Summe
    float durchschnitt; // Variable für den Durchschnitt
    int gültigeNoten = 0; // Zähler für gültige Noten

    // Noten vom Benutzer eingeben
    for (int i = 0; i < 10; i++) {
        float note;

        // Schleife zur Sicherstellung einer gültigen Eingabe
        while (1) {
            printf("Geben Sie die %d. Note ein (zwischen 1 und 6): ", i + 1);
            scanf("%f", &note);

            // Überprüfung, ob die Note im gültigen Bereich liegt
            if (note >= 1 && note <= 6) {
                noten[i] = note;   // Gültige Note speichern
                summe += note;     // Note zur Summe hinzufügen
                gültigeNoten++;    // Anzahl der gültigen Noten erhöhen
                break;             // Schleife verlassen und zur nächsten Note gehen
            } else {
                printf("Ungueltige Eingabe, Note muss zwischen 1 und 6 sein.\n");
            }
        }
    }

    // Durchschnitt berechnen, wenn gültige Noten vorhanden sind
    durchschnitt = (gültigeNoten > 0) ? (summe / gültigeNoten) : 0;

    // Ergebnis ausgeben
    printf("\nSumme aller Noten ist: %.2f\n", summe);
    printf("Durchschnitt aller Noten ist: %.2f\n", durchschnitt);

    // Array (Noten) ausgeben
    printf("Eingegebene Noten: ");
    for (int j = 0; j < gültigeNoten; j++) {
        printf("%.2f ", noten[j]);
    }
    printf("\n");

    return 0;
}

