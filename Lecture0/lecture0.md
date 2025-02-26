# Lekce 0

## Úvodem

Na začátek ukážeme, co všechno je potřeba udělat pro nastavení Visual Studia na Windows pro tvorbu semestrální práce.

**Windows development**

Na stránce PGR v [odkazy a návody](https://cent.felk.cvut.cz/courses/PGR/links.html) lze stáhnout pgr framework a najít postup pro nastavení IDE i Environment variables.

**Linux/Mac OS development**
Pro vývoj na Linuxu je potřeba stáhnout si zdrojáky pgr frameworku, pomocí cmake vytvořit knihovnu, shromáždit hlavičkové soubory. Dále do makefilu pomocí -L a -l říct linkeru, kde najde knihovny a také překladači, kde najde hlavičkové soubory. Alternativně je možné si 3rd party knihovny pomocí package manageru stáhnout dané knihovny (bez pgr). Jelikož jsem ale sám v tomto procesu selhal, nebudu se snažit o nějaký podrobnější postup.

***

## Trocha teorie

Fakta:
- OpenGl není open source
- OpenGl v současné době bylo nahrazeno Vulkánem, ale ten je složitější a obecně větší.
- jazyku OpenGl 'rozumí' téměř každé zařízení od Intel procesoru až po RTX karty, což zajišťuje multi-platformovost.
- Implementace OpenGl tedy je na výrobci dané grafické karty a může se tedy lišit v závistloti na hardwaru.
- OpenGl funkce jsou tedy pouze předpis a její implementace se liší podle zařízení, na kterém běží.
- V předmětu PGR se používají pouze novější verze OpenGl ( >= 3.4? )
