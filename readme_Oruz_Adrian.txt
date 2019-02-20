Mi-am citit din fisierul date datele de intrare.
Am folosit long long pentru valorile matricelor si a sumei, maximului admis pentru a nu avea probleme cu ultimele teste. Mi-am alocat memorie pentru cele 2 matrice. Cea de-a doua fiind ajutatoare pentru a calcula costul minim.

Cerinta1
  - e o functie de tip int ce returneaza suma(fara punctul de plecare si destinatia, le-am adaugat dupa) pe care am apelat o recursiv daca nu e pe margine
  -practic alege varianta mai buna dintre sus si stanga
  -in cazul in care ajunge pe margine l-am tratat separat si am folosit for uri pentru a ajunge la elementul din varf

Cerinta2
  -pentru cerinta 2 m-am ajutat de matricea b; pe ultima linie si ultima coloana am pus sumele calculate folosind b[n][j-1]=b[n][j-1]+b[n][j], respectiv b[i-1][n]=b[i-1][n]+b[i][n]( asta am facut in main deoarece am folosit fuctia recursiv si am vrut sa evit problemele).
  -functia alege minimul dintre variante(la care aduna elementul corespunzator din matricea initiala) si completeaza cate o coloana in noua matrice de costuri
  -in main am apelat functia pentru toate coloanele
  -in urma acestei apicari, elementul b[0][0] a devenit drumul de cost minim 
cu conditiile impuse

Cerinta3
  -am bagat intr un vector suficient de lung valorile date de fuctia rand
  -cat timp numarul de incercari facute e mai mic decat numarul maxim de incercari este apelata functia( am dat ca parametru poz adica pozitia la care am ramas in vectorul cu valorile date de rand)
  -plecand de la pozitia respectiva cat timp nu ma aflam pe prima linie sau prima coloana merg in sus pentru 1 sau in stanga pentru 0
  -cand am ajuns pe prima linie sau coloana, se opreste si trateaza separat cazurile
  -functia returneaza pozitia la care a ramas
  -daca suma calculata e mai mica decat maximul admis se opreste si afisaza numarul incercarii, altfel continua pana epuizeaza incercarile

																Oruz Adrian
