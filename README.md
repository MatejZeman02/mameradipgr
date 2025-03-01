# MÁME RÁDI PGR

>**mameradipgr aneb MÁME RÁDI PGR :-)**

Doplňkový materiál ke cvičení předmětu BI-PGR, jehož cílem je kolegům názorněji
přiblížit souvislosti mezi probíranou teorií a jejím využitím v praxi.
Může tak sloužit dobrý start pro tvorbu vlastní semestrální práce.

## Lekce

Jednotlivé lekce jsou umístěné na YouTube.
> Prosím, zkuste to moc nesdílet mimo organizaci.

videa:

1. [Úvodní video](https://www.youtube.com/watch?v=AfeIe7gPTfA&list=PL8uMtryYBlUs3nrvy2y9QShdWlLqf3jIK&pp=gAQB)
2. [Výsvětlení kostry semestrálky](https://youtu.be/EtryIrACrJU?si=1I7fpNJBY-5X_SfU)
3. [Změna barvy trojúhelníku](https://youtu.be/gljCizTtyA0?si=TW6ZlbWIYj6_k3K7)
4. [Výsvětlení PVM matice a kamery](https://youtu.be/QPY3kJ6vtqI?si=hBMJEPxD10rHfbvr)

odkaz na celý playlist: [https://www.youtube.com/...](https://www.youtube.com/watch?v=AfeIe7gPTfA&list=PL8uMtryYBlUs3nrvy2y9QShdWlLqf3jIK&pp=gAQB)

## Fáze

Projekt je rozdělen do potenciálních částí:
- Vysvětlení kostry a startovní push ke tvorbě vlastního projektu.
- Jak využít znalostí ze cvik v semestrálce.
- Teoretické věci ukázáné na příkladech:
  - PVM matice a transformace trojúhelníku/tvorba kamery.
  - Import objektu, vyexportovaného z Blenderu.
- Tvorba ukázkové semestrálky: (pokročilé). Extra věci pro více bodů... -> není v plánu.

Pravděpodobně ale nebudu stíhat všechno podle plánu.


## Instalace PGR Frameworku

Co všechno je potřeba udělat pro nastavení Visual Studia pro tvorbu semestrální práce?

**Vývoj pod Windows**

Na stránce PGR v [odkazy a návody](https://cent.felk.cvut.cz/courses/PGR/links.html) lze stáhnout pgr framework a najít postup pro nastavení IDE i Environment variables.

**Vývoj pod Linux**

Pro vývoj je potřeba stáhnout si zdrojáky pgr frameworku. Pomocí cmake zkompilovat knihovnu a shromáždit hlavičkové soubory. Dále do makefilu pomocí -L a -l říct linkeru, kde najde knihovny a také překladači, kde najde hlavičkové soubory. Alternativně je možné si 3rd party knihovny pomocí package manageru stáhnout dané knihovny (bez pgr). Jelikož jsem ale sám v tomto procesu selhal, nebudu se snažit o nějaký podrobnější postup.

***

## Pár faktů o OpenGl:
- OpenGl není open source.
- OpenGl v současné době bylo nahrazeno Vulkánem, ale ten je složitější a obecně větší.
- jazyku OpenGl 'rozumí' téměř každé zařízení od Intel procesoru až po RTX karty, což zajišťuje multi platformovost.
- Implementace OpenGl tedy je na výrobci dané grafické karty a může se tedy lišit v závistloti na hardwaru.
- OpenGl funkce jsou tedy pouze předpis a její implementace se liší podle zařízení, na kterém běží.
- V předmětu PGR se používají pouze novější verze OpenGl, jelikož už stejně není vyvíjené.

## Disclaimer

**Pokud se v materiálech vyskytují chyby, můžete je nahlásit přes Issues, nebo upozornit do komentáře pod video.**
