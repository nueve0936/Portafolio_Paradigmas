# Practica 3: Introducción a Haskell

## Introducción
A continuacion veremos una breve introduccion al lenguaje de programación Haskell. Aprendermos lo que es, algunas de sus caracteristicas y veremos el funcionamiento de una aplicacion hecha con este lenguaje de programación.

***

### ¿Qué es Haskell?
Haskell es un lenguaje de programacion de proposito general y funcional que aparecio por primera vez en el año 1990. Es conocido por us enfasis en la seguridad de tipos, la precisión matematica y la facilidad de evaluación.

Algunos de sus usos principales son:
* Proyectos a gran escala.
* Sistemas criticos.
* Infraestructura y blockchain.

***

### Caracteristicas
Indagando un poco mas en sus caracteristicas principales podemos decir que:

* **Es puramente funcional**: No tienen efectos secundarios, por lo que el valor de retorno siempre es el mismo para una entrada dada.
* **Tipado estático**: Los tipos se determinan durante la compilación.
* **Perezoso**: Las expresiones no se evaluan hasya que son realmente necesarias.
* **Polimorfico**: Las funciones pueden trabajar con diferentes tipos de datos sin necesidad de sobrecargas. 

***

### Ventajas
Algunas de las ventajas que ofrece Haskell son:

* **Mayor productividad**: Como Haskell tiende a ser mas conciso y expresivo, le permite a los desarrolladores escribir más código en menos tiempo.
* **Menor número de errores**: Al ser puramente funcional reduce la posibilidad de errores y hace que el código sea más predecible y f+ácil de depurar.
* **Sistema de tipo estático**: Al ser estático permite que el compilaor detecte errores de tipo en tiempo de compilación, evitando problemas en tiempo de ejecución.
* **Gesstión de memoria**: Haskell utiliza una gestión de memoria automática, lo que elimina la necesidad de realizar una gestión manual de memoria.

### Desventajas
Algunas desventajas con las que Haskell carga son:

* **Actualizaciones de compilador**: Las actualizaciones pueden introducir cambios en la sintaxis.
* **Curva de aprendizaje**: Haskell puede ser un lenguaje mas dificil de aprender que otros, sobretodo para quellos que no esten familiarizados con la programación funcional. 
* **Conocimiento de la comunidad**: Al no tener tanto conocimiento por parte de la comunidad a comparación de lenguajes cono Python o Java puede que la búsqueda de soluciones a problemas sea algo mas dificil.
* **Herramientas y biblioteccas**: Haskell tiene menos herramientas y bibliotecas a comparación de otros lenguajes de programación.

***

## Programa ToDo
La aplicación ToDo es un ejemplo practico en el cual se creara una aplicación de consola interactiva para gestionar tareas en la cual abrira una página web. Todo esto ccon el objetivo de aprender y reforzar conocimientos acerca de Haskell. A continuacion veremos un breve resumen y analisis acerca de este programa.

### Main
```haskell
-- https://www.fpcomplete.com/haskell/tutorial/stack-script/
-- #!/usr/local/bin/env stack
-- stack --resolver lts-12.21 script
```

El siguiente encabezado nos permite ejecutar el archivo directamente como un script usanto Stack.

```haskell
module Main where

import Configuration.Dotenv (defaultConfig, loadFile)
import Lib (prompt)
import System.Environment (lookupEnv)
import Web.Browser (openBrowser)
```

El programa depende de los siguientes modulos:
* Configuration.Dotenv: Se usa para cargar variables del archivo ".md"
* System.Environment: Se usa para acceder a las variables de entorno.
* web.Browser: Se usa para abrir URL en el navegador.
* Lib: Aqui se define la logica de TODO.

### Lib
Este modulo contiene la lógica que permite manejar una lista interactiva de atreas desde ka terminal y es llamado por el main que vimos anteriormente para iniciar una sesión interactiva donde el usuario puede introducrir comandos para gestionar la lista.

```haskell
module Lib
  ( prompt,
    editIndex,
  )
```
Las funciones que exporta Lib son:
* prompt: FUncion principal que maneja los comanos del usuarrio y es llamada desde el main con una lista vacia para iniciar el programa.
* editIndex: Función auxiliar que actualiza un elemento de una lista en una posición dada.

```haskell
interpret :: String -> [String] -> IO ()
```
Esta funcion analiza el comando del usuario y actua en consecuencia dependiendo lo que ponga:
* + tarea: Agrega una tarea al inicio de la lista.
* - n: Elimina la tarea con indice n usando delteOne.
* s n: Muestra la taea con indice n usando showOne.
* l : Lista todas las tareas.
* r : Miestra todas las tareas en orden inverso sin modificar la original.
* c : Limpia la lista de tareas
* q : Termina el programa.

Cualquier otro comando que el usuario intente ingresar sera considerado como invalido.

## Conclusión
El lenguaje de programación Haskell es una herramienta muy poderosa si sabemos el como usarlo y se adapta a las necesidades u objetivos que tengamos. La aplicacion anterior nos demuestra su eficacia  la hora de ser usado para aplicaciones web seguras y funcionales gracias a todas las caracteristicas que hemos visto a lo largo del reporte. Su aprendizaje es necesario en caso de que queramos saber las bases del desarrollo web funcional.





Enlace del portafolio: https://github.com/nueve0936/Portafolio_Paradigmas.git 
Enlace de la pagina: https://nueve0936.github.io/Portafolio_Paradigmas/