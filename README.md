# MÁME RÁDI PGR

>**mameradipgr aneb MÁME RÁDI PGR :-)**

Doplňkový materiál ke cvičení k předmětu BI-PGR, jehož cílem je kolegům názorněji
přiblížit souvislosti mezi probíranou teorií a jejím využitím v praxi.
Materiál tak může sloužit jako dobrý start pro tvorbu vlastní semestrální práce.

## Lekce

Jednotlivé lekce jsou umístěné na YouTube.
> Prosím, zkuste to moc nesdílet mimo organizaci. Ne, že to budete posílat Felklovi do kvízu jako odkaz na zajímavé video! 🫠

videa:

1. [Úvodní video](https://www.youtube.com/watch?v=AfeIe7gPTfA&list=PL8uMtryYBlUs3nrvy2y9QShdWlLqf3jIK&pp=gAQB)
2. [Vysvětlení kostry semestrálky](https://youtu.be/EtryIrACrJU?si=1I7fpNJBY-5X_SfU)
3. [Změna barvy trojúhelníku - poslání barvy na grafiku](https://youtu.be/gljCizTtyA0?si=TW6ZlbWIYj6_k3K7)
4. [PVM matice a kamera](https://youtu.be/QPY3kJ6vtqI?si=hBMJEPxD10rHfbvr)

odkaz na celý playlist: [https://www.youtube.com/...](https://www.youtube.com/watch?v=AfeIe7gPTfA&list=PL8uMtryYBlUs3nrvy2y9QShdWlLqf3jIK&pp=gAQB)

## Potenciální fáze tohoto projektu:

Projekt je rozdělen do více pracovních částí:
- Vysvětlení kostry a startovní push ke tvorbě vlastního projektu. ✅
- Jak využít znalostí z jednotlivých cvik v semestrálce. ❌
- Teoretické věci ukázáné na příkladech:
  - PVM matice a transformace trojúhelníku/tvorba kamery. ✅ 
  - Import objektu, vyexportovaného z Blenderu. ❌ (tak trochu)
- Tvorba ukázkové semestrálky: (pokročilé). Extra věci pro více bodů... ❌.

Pravděpodobně ale nebudu stíhat všechno podle plánu.


## Instalace PGR Frameworku

Co všechno je potřeba udělat pro nastavení Visual Studia pro tvorbu semestrální práce?

Nejdříve je potřeba si stáhnout samotnou kostru [starou](https://cent.felk.cvut.cz/courses/PGR/seminars/04/kostra.zip), nebo [novou](https://gitlab.fit.cvut.cz/weisstom/pgr-skeleton).

**Vývoj pod Windows**

Na stránce PGR v [odkazy a návody](https://cent.felk.cvut.cz/courses/PGR/links.html) lze stáhnout pgr framework a najít postup pro nastavení IDE i Environment variables.

**Vývoj pod Linux**

Pro vývoj je potřeba stáhnout si zdrojáky pgr frameworku. Pomocí `cmake` zkompilovat knihovnu a shromáždit hlavičkové soubory.

Dále do makefilu pomocí `-L` a `-l` přepínačů říci linkeru kde najde knihovny (zkompilované). A také sdělit překladači, kde najde hlavičkové soubory `.h`. Alternativně je možné si 3rd party knihovny pomocí package manageru stáhnout (dané knihovny bez pgr).


Pokud ale přemýšlíte o vývoji pod Linuxem, tak bych rovnou doporučil používat modernější knihovny, jako např. `GLFW`.
Nebudu se tu ale snažit o nějaký podrobnější postup. Pro Vás možná bude vhodnější rovnou použít novou kostru semestrálky od Tomáše Weisse [pgr-skeleton](https://gitlab.fit.cvut.cz/weisstom/pgr-skeleton).

***

## Pár faktů o OpenGl:
- OpenGl není open source.
- OpenGl v současné době bylo nahrazeno Vulkánem, ale ten je složitější a obecně větší. Spousta funkcí v OpenGL si musíte naimplementovat sami.
- jazyku OpenGl 'rozumí' téměř každé zařízení od Intel procesoru až po RTX karty, což zajišťuje multi platformovost.
- Implementace OpenGl je na výrobci dané grafické karty a může se tedy lišit v závistloti na hardwaru.
- OpenGl funkce jsou tedy pouze nějaký předpis a konkrétní implementace se liší podle zařízení na kterém běží.
- V předmětu PGR se používají pouze novější verze OpenGl, jelikož už stejně není dále podporované (od 4.5 myslím).

## Disclaimers

- Možná nejsem nejvhodnější člověk pro vysvětlování věcí. Materiály berte, "*jak jsou*".
- ❗ V současnosti (a budocnosti) existuje nová, lepší kostra od kolegy Tomáše Weisse. [pgr-skeleton](https://gitlab.fit.cvut.cz/weisstom/pgr-skeleton). Nová kostra je super, ale bohužel doteď ještě úplně neexistovala. A dle slov Tomáše není potřeba dělat nějaké nové video, jelikož: *"Ta nová je už přehledná a navíc k ní ještě budu psát extenzivní dokumentaci."*. Takže s ní si budete muset poradit sami. (Ty `.yaml` soubory mi nepřišly až zas tak intuitivní.)
- V sekci [odkazy a návody/Blender export plugin](https://cent.felk.cvut.cz/courses/PGR/download/blender-export/) najdete mnou aktualizovaný (pro Blender 4) addon do Blenderu, který vyexportuje jeden objekt do kódu. Pokud již kód není aktuální a pro nové verze Blenderu padá, prosím, vězměte to zase někdo do vlastních rukou a přepiště ho, aby fungoval i pro novou verzi. (předem se omlouvám za svůj kód). Tento addon moc nefunguje pro složitější meshe (například jako konverze z geometry nodes, nebo metaballs).
- Pokud jste někdo náhodou přemýšlel, že byste se konečně naučil s `c++20 moduly`, tak v adresáři `src-kostra-moduly/` je mnou pozměněná stará kostra na moduly. V roce 2025, několik let po vydání této nové funkcionality je vývoj pod moduly stále v experimentálním režimu. Ale doufám, že v tom leží budoucnost c++, takže jsem si to vyzkoušel. Zároveň Vám to v současné situaci nedoporučuji.
- Nebojte se podívat do [archivu semestrálních prací](https://cent.felk.cvut.cz/courses/PGR/archives) z ostatních studentských semestrálek. Pro vás to může být skvělý zdroj *inspirace* a ti učitelé s tím tak trochu počítají (jinak by Vám to ani nezpřístupnili).
- Svoují semestrálku jsem psal v létě. Ale teď už toho z té teorie vím mnohem víc. Takže jsem si vědom toho, že ve videích jsou drobné chybky nebo jsem nejistý a zmatený, ale co už...

- **Pokud se v materiálech vyskytují chyby, můžete je nahlásit přes Issues, nebo upozornit do komentáře pod video.** (Ale pokud je rok >= 2026, asi už se mi to nebude moc chtít opravovat. :) )
Pro rozšíření těchto materiálů pro další ročníky bych stejně doporučil používat novou kostru. 
