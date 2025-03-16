 # Practica 0: Uso de Repositorios 

 ## Introduccion

 <!-- MARKDOWN -->
 ## ¿Qué es Markdown?
Lenguaje de marcado ligero que se utiliza para dar formato a documentos de texto plano. Sirve principalmente para escribir documentación, publicar contenido en sitios webs estáticos, crear notas, escribir mensajes formateados en foros y chats. Se creó en el año 2004 por John Gruber, siendo a día de hoy uno de los lenguajes de marcado más famosos debido a lo sencillo, ligero y fácil que es de aprender para aquellas personas que no cuentan con un perfil técnico.

## ¿Cómo se Utiliza?
1. Crear un archivo Markdown usando la extensión ".md".
2. Escribir el contenido usando sintaxis Markdown para agregar lo que queramos (listas,enlaces,código,etc).
3. Abrir el archivo usando algun editor compatible (VSCode, Obsidian) o directamente desde GitHub.
4. Renderizar el archivo.

## Sintaxis de Markdown

### Comentarios
```
 <!-- Esto es un comentario -->
 ```
### Encabezados
```
 # Titulo Principal
 ## Subtitulo
 ### Encabezado de Seccion
 #### Encabezado de Subseccion
 ##### Encabezado de Subseccion
```

### Italicas
```
 <!-- Italicas -->
 Este es un texto en "italica"
 Este es un exto en _italica_
```
### Negritas
```
 <!-- Negritas -->
 Este es un texto en **Negritas**
 Este es un texto en __negritas__
```
### Teclado
```
 <!-- Teclado -->
 Este es un texto ~~tachado~~
```
### UL
```
 <!-- UL -->
 * Elemento 1
 * Elemento 2
 * Elemento 3
   * Elemento 3.1
   * Elemento 3.2
     * Elemento 3.2.1
 * Elemento 4
```
### OL
```
 <!-- OL -->
 1. Elemento 1
 2. Elemento 2
 3. Elemento 3
    1. Elemento 3.1
    2. Elemento 3.2
 4. Elemento 4     
```
### Enlaces
```
<!-- Enlaces -->
[Texto de enlace](http://www.uabc.com "Texto de tooltip")
[UABC](http://www.uabc.mx)
[UABC](http://www.uabc.mx "Sitio Universitario")
```
### Imagenes
```
<!-- Imagenes -->
![Texto alternativo](https://i.blogs.es/637aa5/h2x1_nswitchds_hollowknightsilksong/1366_2000.jpeg)
```
### Bloque de Codigo
``````
<!-- Bloques de codigo -->
```
This is un code block
This is the second line of the code block
```


```python
print("Hola Mundo!")
```

```javascript
console.log('Hello World')
const test = ()
```

```html
<h1>Hola Mundo</h1>

``````
### Tablas
```
<!-- Tablas -->
| Producto | Precio | Cantidad |
|- | - | - |
| Laptop | 3.3 | 2 |
| Mouse | 13.3 | 1 |

| Productos | Precio | Cantidad |
| --------- | ------ | -------- |
| Laptop    | 3.3    |     2    | 
| Mouse     | 13.3   |     3    |
```
### Notas
```
<!-- Notas -->
> Esto es una nota
```
### Tareas
```
<!-- Tareas -->
* [x] Primera tarea
* [ ] Segunda tarea
* [x] Tercera tarea
* [ ] Cuarta tarea
```
### Divisiones
```
<!-- Divisiones -->

***

---

___
```
### Menciones
```
<!-- Menciones -->

@darhtrookie :+1: :smile:
```

 <!-- HUGO -->
## ¿Qué es Hugo?
Hugo es un generador de sitios webs estaticos que se escribe en Go. Es un proyecto de codigo abierto rapido que puede crear la mayoria de los sitios webs en cosa de segundos.

### ¿Cómo crear un sitio estático en Hugo?

1. Configurar el archivo hugo.toml en la raíz del proyecto.
2. Establecer el URL, el languageCode y el titulo.
3. Usar el servidor de Hugo para ver el sitio web localmente.
4. Alojar el sitio en un servicicio, en este caso GitHub Pages.

 <!-- GITHUB ACTIONS -->
## ¿Que es GitHub Actions?
GitHub es una plataforma en línea que permite automatizar los flujos de trabajo de compilación, pruebas e implementación.

### ¿Cómo configurar GitHub Actions para publicar el sitio en GitHub Pages?

1. Navegar al repositorio del sitio en GitHub
2. Hacer click en "Configuración".
3. Hacer click en "Páginas" en la sección "Código y atuomatización".
4. Seleccionar "GitHub Actions" en "Origen".
5. Elegir una plantilla de flujo de trabajo o crear uno personalizado.
6. Crear un archivo llamado hugo.yaml en un directorio llamado .github/workflows.
7. Copiar y pegar el código YAML.
8. Cambiar el nombre de la rama y la versión de Hugo.
9. Confirmar y enviar el cambio al repositorio de GitHub.
------------------------------


