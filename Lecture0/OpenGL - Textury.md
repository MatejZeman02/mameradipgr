#### Textury
![img](media/Pasted-image-20240413150937.png)
![img](media/Pasted-image-20240413150948.png)

- Když specifikujeme souřadnice venku z (0,1) ->
	- ![img](media/Pasted-image-20240413151023.png)
	- ![img](media/Pasted-image-20240413151029.png)
	- můžeme nastavit pro každou osu zvlášť
		- ![img](media/Pasted-image-20240413151111.png)
		- ![img](media/Pasted-image-20240413151216.png)
##### Texture Filtering
- GL_NEAREST -> vybere barvu pixelu co je nejblíž k specifikované souřadnici
- GL_LINEAR -> udělá průměr z barev okolo podle toho jak jsou blízko
- ![img](media/Pasted-image-20240413151402.png)
#### Mipmaps
- když je objekt daleko, využijeme menší verzi dané textury místo složitému vypočítávání z velké textury.
- ![img](media/Pasted-image-20240413154417.png)
- mipmapu můžeme vytvořit snadno pomocí glGenerateMipmap
- když se mezi úrovněmi vybírají různé mipmapy, můžou být vidět artefakty. mezi mipmap vrstvami můžeme také vybrat Linear nebo Nearest filtering
- ![img](media/Pasted-image-20240413154547.png)
