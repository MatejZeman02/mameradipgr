# MÁME RÁDI PGR

>**mameradipgr aneb MÁME RÁDI PGR :-)**

Doplňkový materiál ke cvičení předmětu BI-PGR, jehož cílem je kolegům názorněji
přiblížit souvislosti mezi probíranou teorií a jejím využitím v praxi.
Může tak sloužit dobrý start pro tvorbu vlastní semestrální práce.

## Lekce

Jednotlivé lekce jsou umístěné na YouTube.
(Prosím, zkuste to moc nesdílet mimo organizaci.)

odkaz na playlist: [https://www.youtube.com/watch?v=AfeIe7gPTfA&list=PL8uMtryYBlUs3nrvy2y9QShdWlLqf3jIK&pp=gAQB](https://www.youtube.com/watch?v=AfeIe7gPTfA&list=PL8uMtryYBlUs3nrvy2y9QShdWlLqf3jIK&pp=gAQB)

videa:
0. [uvod](https://www.youtube.com/watch?v=AfeIe7gPTfA&list=PL8uMtryYBlUs3nrvy2y9QShdWlLqf3jIK&pp=gAQB)

## Fáze

Projekt je rozdělen do potenciálních fází:
- Vysvětlení kostry a startovní push ke tvorbě vlastního projektu.
- Video vysvětlující, jak toho využít v semestrálce.
- Teoretické věci ukázáné na příkladech:
  - PVM matice a transformace trojúhelníku.
  - 1 objekt, vyexportovaný z Blenderu.
- Tvorba ukázkové semestrálky (pokročilé). Extra věci pro více bodů.

Pravděpodobně ale nebudu stíhat všechno podle plánu.


## Instalace

Na začátek ukážeme, co všechno je potřeba udělat pro nastavení Visual Studia na Windows pro tvorbu semestrální práce.

**Vývoj pod Windows**

Na stránce PGR v [odkazy a návody](https://cent.felk.cvut.cz/courses/PGR/links.html) lze stáhnout pgr framework a najít postup pro nastavení IDE i Environment variables.

**Vývoj pod Linux/Mac OS**
Pro vývoj je potřeba stáhnout si zdrojáky pgr frameworku, pomocí cmake vytvořit knihovnu, shromáždit hlavičkové soubory. Dále do makefilu pomocí -L a -l říct linkeru, kde najde knihovny a také překladači, kde najde hlavičkové soubory. Alternativně je možné si 3rd party knihovny pomocí package manageru stáhnout dané knihovny (bez pgr). Jelikož jsem ale sám v tomto procesu selhal, nebudu se snažit o nějaký podrobnější postup.

***

## Trocha teorie

Fakta:
- OpenGl není open source
- OpenGl v současné době bylo nahrazeno Vulkánem, ale ten je složitější a obecně větší.
- jazyku OpenGl 'rozumí' téměř každé zařízení od Intel procesoru až po RTX karty, což zajišťuje multi-platformovost.
- Implementace OpenGl tedy je na výrobci dané grafické karty a může se tedy lišit v závistloti na hardwaru.
- OpenGl funkce jsou tedy pouze předpis a její implementace se liší podle zařízení, na kterém běží.
- V předmětu PGR se používají pouze novější verze OpenGl, jelikož už stejně není vyvíjené.

## Disclaimer

**Materiál vzniká průběžně a velmi pravděpodobně bude plný překlepů a chybiček.
Prosíme o jejich report skrz Issues.**
