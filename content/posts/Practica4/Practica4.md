# Inrtoducción a Prolog

## Introducción
A continuación veremos una breve introducción a Prolog, sus caracteristicas principales y algunosa ejemplos de el como y para que su uso.

## ¿Qué es Prolog?
Prolog fue el primer lenguajde de progrgramacion basado en el paradigma de la programación lógica declaraiva y se implementó por primera vez a principos de los años 1960. Se basa en la lógica de predicados donde el programador define hechos y reglas.

### Caracteristicas Principales

* **Basado en logica de predicados**: A diferencia de ortos lenguajes imperativos como Python o Java, en Prolog no escribimos algoritmos paso a paso, si no que Prolog al basarse en la lógica de primer orden se definen hechos, reglas y consultas.
  
* **Declarativo**: El programador declara **QUE ES** lo que quiere lograr pero no necesariamente como hacerlo, ya que el motor de Prolog se encarga de buscar la solución.
  
* **Hechos y relgas**: En el programa el conocimiento se representa mediante hechos y **reglas** que definen **lógicas** entre elementos.

* **Motor de interferencia**: Utilizando un mecanismo llamado **resolucion** con unificacion y backtracking para responder preguntas basandose en los hechos y reglas definidos

### Usos Principales

* **Inteligencia artificial**: Diseño de sistemas expertos, razonamiento automatico, procesamiento de lenguaje natural.
* **Base de conocimientos**: Creación de bases de datos que pueden ser consultadas mediante lógica.
* **Educación**: Se utiliza para enseñar conceptos de lógica y programación.

## Ejemplo
A continuación veremos y analizaremos de manera breve un programa en Prolog para identificar sus partes y que es lo que hace.

```prolog
padre(juan, maria).
padre(juan, pedro).
madre(ana, maria).
madre(ana, pedro).
```
El siguiente bloque de programacion representan los hechos del programa. Hay que tener en cuenta ciertas reglas a la hora de codificar como por ejemplo:
* Los nombres de las relaciones **deben comenzar con letra minustcula**. 
* Los objetos se escriben separados por comas y encerrados entre parentesis.
* Al final del hecho debe ir un punto (para los que esten familiarizados con C, esto es equivalente al punto y coma).

```prolog
hermano() : - padre(P, X), padre(P, Y), madre(M, X), pmdre(M, Y), X \= Y.
```
Este bloque de programacion representa la regla, en la cual el Prolog junto con los hechos que el programador definio, vera si dos personas son hermanos mientras cumpla con:
* Tienen el mismo padre ( P ).
* Tienen la misma madre ( M ).
* No son la misma persona ( X \= Y ).
Si lo cumplen Prolog reasponera con un "true" y de no ser ese el caso con un "false".

```prolog
?- hermano(maria, pedro).
```
Esta es la consulta que el ususario codificara pregutando en este caso si "maria" y "pedro" son hermanos. La forma en que Prolog respondera a la pregunta es tratando de **coincidir** los terminos usando variables, usara las reglas y hechos disponibles para deducir si la consulta es verdadera y darle una **resolucion** para al final desplegar la respuesta. En caso de que haya alguna falla, Prolog intentara otras opciones disponibles haciendo uso del **Backtracking**.

## Conclusión
Prolog es un lenguaje unico que nos permite ver de otro modo la programacion para aquellos que estamos mas familiarizados a lenguajes como C o Python, invitandonos a razonar y usar cien por ciento la logica en lugar de un algoritmo con una serie de paso a seguir para resolver un problema. Si bien su uso es limitado es perfecto para aquellos que busquen aprender y reforzar la logica dentro de sus programas pero sobretodo, el conocimiento de este lenguaje es muy nutritivo para todos aquellos interesados en aprender mas acerca de una tecnologia tan emergente en nuestra actualidad como lo es la Inteligencia Artificial.