Talevici Adela-Laura 324CA

# PROBLEMA 1 - SERVERE

Pentru a rezolva aceasta problema am apelat la o metoda matematica , folosind
grafice pentru a calcula puterea de alimentare. Am incercat sa gasesc punctul
A(x,y),x fiind curentul iar y puterea generata. Pentru a gasi valoarea puterii
de alimentare , am facut suma si diferenta dintre vectorii P si C si am
incercat sa reduc cat mai mult posibil intervalul in care caut in grafic pentru
putere astfel incat valorile pt grafice sa fie pozitive . Pentru asta am
calculat maximul pentru diferenta dintre al doilea vector si primul,
(reprezentand maximul pentru partea din stanga a graficului) si minimul pentru
suma dintre cei doi vectori ,(reprezentand minimul din partea dreapta a
graficului).Din grafic am observat ca valoarea puterii de alimentare se gaseste
facand media dintre minimul si maximul gasite anterior.Astfel am gasit valoarea
curentului de alimentare necesar. Am calculat apoi puterile individuale , iar
valoarea de care aveam nevoie este minimul acestora .

![Imagine-grafic](<Screenshot from 2024-04-22 01-52-49.png>)

* Complexitate temporala:O(n)
* Complexitate spatiala:O(n)

# PROBLEMA 2 - COLORARE

Scopul problemei este sa vedem in cate moduri se poate colora tabloul.
Pentru a face asta eficient am folosit functia power care face ridicarea la
putere in timp logaritmic.Pentru a rezolva aceasta problema am definit o
structura in care retin perechile de forma "X T",unde X reprezinta lungimea
segmentului iar T reprezinta tipul de segment si am abordat o rezolvare
bazata pe programare dinamica . Am utilizat un vector dp pentru a stoca
rezultatele intermediare ale subproblemelor. Am observat ca pentru cazul de
baza daca este initial H sunt 6 variante de colorare(fiind vorba de 3 culori),
iar pentru V sunt 3 . Pentru fiecare segment urmator am calculat numarul de
optiuni de colorare utilizand rezultatele anterioare, verificand pentru fiecare
tipul de segment. Dupa V se dubleaza numarul de obtiuni . Dupa H , daca avem
tot H se tripleaza , iar daca dupa H urmeaza V ramane la fel.
(VV - 2 , HV - 1, VH -2 , HH - 3). 

* Complexitate temporala:O(k*log(nr. patratele)),k-nr regiuni.
* Complexitate spatiala:O(n)

# PROBLEMA 3 - COMPRESIE

Pentru a rezolva aceasta problema am parcurs ambii vectori in acelasi timp
folosind indicii i si j si fac compresia elementelor necomune .Daca suma
elementelor din primul vector nu este egala cu suma elementelor din al doilea
vector atunci compresia nu se poate realiza si afisez -1 , pentru asta am
folosit o functie auxiliara pentru a calcula suma elementelor din vector.
Verific daca elementul de pe pozitia i din primul vector este diferit de pe
pozitia j din al doilea vector prin intermediul a doua if uri pentru ca avem
doua variante . Atunci cand elementul din primul vector este mai mare , facem
compresia in al doilea vector deci facem suma dintre el si urmatorul element in
al doilea vector si incrementam lungimea maxima , apoi trecem la urmatoarele
elemente. La fel si pentru cazul cand elementul din al doilea vector este mai
mare , facem suma in primul vector .

* Complexitate temporala:O(m + n)
* Complexitate spatiala:O(m+n)

# PROBLEMA 4 - CRIPTAT

Pentru rezolvarea acestei probleme am utilizat o matrice de frecvente pentru
fiecare cuvant. Am folosit functia maxlen pentru a calcula lungimea maxima a
secventei cu litera dominanta . Pentru asta am abordat o rezolvare bazata pe
programare dinamica . Am iterat prin fiecare litera de la a la z , iar pentru
fiecare litera am calculat un indice ch corespunzator in matricea de frecvente.
Am utilizat un array dp pentru programare dinamica cu lungimea maxima si l am
initializat cu 0. Am parcurs apoi toate cuvintele pentru a calcula lungimea
maxima a parolei care respecta conditia specificata . 
Initializez variabila remaining_len cu maxlen - 1 pentru a putea itera prin
lungimile posibile.In interiorul buclei while verific daca pot adauga
frecventele literelor din cuvantul curent la solutia existenta pentru o lungime
ramasa mai mica , sau daca trebuie sa iau in considerare si cuvantul curent in
sine pentru a forma o secventa cu litera dominanta. Dupa ce am actualizat dp ul
parcurg din nou array ul pt a gasi lungimea maxima a parolei care indeplineste
conditia specificata in enunt.

* Complexitate temporala:O(n*m*maxLen)
* Complexitate spatiala:O(n + maxLen)

# PROBLEMA 5 - OFERTA

Pentru aceasta problema am definit functia find_minim pentru a calcula costul
minim pentru achizitionarea produselor avand in vedere ofertele existente.
In vectorul min_cost am stocat costul minim pentru fiecare pas . Apoi calculez
costul minim pentru achizitionarea primelor i produse. Verific apoi daca pot
obtine un cost mai mic prin aplicarea unei oferte speciale pentru 2 produse
consecutive. Astfel daca i>=1 adica daca am doua produse verific mai intai care
este cel mai ieftin pentru a stii pe care trebuie sa aplic reducerea de 50% ,
apoi fac minimul dintre costul obtinut prin aceasta reducere si costul anterior
si actualizez in vectorul meu de min_cost in care stochez la fiecare pas costul
minim . La fel si pentru 3 produse , daca i>=2 verific mai intai care dintre
cele 3 produse este cel mai ieftin apoi actualizez costul minim daca este mai
mic prin aplicarea acestei oferte . La final returnez ultimul cost minim
obtinut pentru ca l am actualizat la fiecare pas.

* Complexitate temporala:O(n)
* Complexitate spatiala:O(n)