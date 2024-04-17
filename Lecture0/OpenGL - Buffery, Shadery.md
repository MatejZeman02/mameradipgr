#### Buffery
- ukládají data
- VBO, VAO, a EBO proměnné drží jen unsigned int IDčka korespondující k bufferu
	- ![img](media/Pasted-image-20240412213324.png)
- Pak akorát přibindujeme toto IDčko k typu bufferu, který chceme
	- ![img](media/Pasted-image-20240412213423.png)
	- Nyní vždy když budeme něco měnit s GL_ARRAY_BUFFER to budeme vlastně měnit ve VBO proměnné, dokud ho neodbindujeme
- glBufferData -> překopírování našich dat do bufferu
	- ![img](media/Pasted-image-20240412213722.png)[Obrazky PGR/Pasted-image-20240412213722.png"]
#### Shadery
##### Vertex Shader
- ![img](media/Pasted-image-20240412215112.png)
- ![img](media/Pasted-image-20240412215126.png)
- pro kompilační chyby:
	- ![img](media/Pasted-image-20240412215204.png)
##### Fragment Shader
- ![img](media/Pasted-image-20240412215452.png)
#### Shader Program
1. Vytvořit program, jeho ID uložit do proměnné
2. Připojit shadery
3. Slinkovat je (failne, pokud nesedí in a out proměnné)
4. Použít program
5. Vymazat shadery
- ![img](media/Pasted-image-20240412222648.png)
- ![img](media/Pasted-image-20240412222657.png)
- ![img](media/Pasted-image-20240412222706.png)
- ![img](media/Pasted-image-20240412222713.png)
#### Vertex atributy
![img](media/Pasted-image-20240412225213.png)
![img](media/Pasted-image-20240412225232.png)
- id, počet, typ, normalizace, počet bytů mezi vertex daty, offset
#### EBO
- když chceme určit indexy jak by se měly kreslit trojúhelníky
![img](media/Pasted-image-20240412235543.png)
#### VAO
- když ho bindneme, a potom děláme všechny vbo a ebo příkazy, uloží se do vao a místo opakování všech vbo a ebo příkazů můžeme v budoucnu jen bindnout a unbindnout vao.![img](media/Pasted-image-20240412230855.png)![img](media/Pasted-image-20240412235608.png)