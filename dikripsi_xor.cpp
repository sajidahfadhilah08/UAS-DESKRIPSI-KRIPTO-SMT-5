#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

main(int argc, char *argv[])
{
    FILE *Fin, *Fout;
    char p, c;
    string k;
    int i;

    Fin = fopen(argv[1], "rb");
    if (Fin == NULL){
       cout << "Berkas " << argv[1] << "tidak ada" << endl;
       exit(0);
    }

    Fout = fopen(argv[2], "wb");

    cout << "kata kunci : "; cin >> k;
    cout << "Dekripsi " << argv[1] << " menjadi " << argv[2] << "...";
    i = 0;
    while (!feof(Fin)){
        c = getc(Fin);
        p = c ^ k[i]; //operasi XOR
        putc(p, Fout);
        i = (i + 1) % k.length();
    }
    fclose(Fin);
    fclose(Fout);

    //return 0;
}
