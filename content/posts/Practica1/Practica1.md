 # Practica 1: Elementos basicos de los lenguajes de programacion

 ## Introduccion
A continuacion veremos los elementos fundamentales de los lenguajes de programacion como lo son: nombres, marcos de activacion, bloques de alcance, administracion de memoria, expresiones, comandos, control de secuencia (seleccion, iteracion y recursion), subprogramas y tipos de datos. Asi mismo, analizaremos partes de los tres programas en Python que en conjunto simulan una aplicacion web para una biblioteca que aplica todos los elementos anteriormente mencionados para una mayor claridad.

## Elementos Fundamentales
* Nombres: Identificadores pardarles un nombre simbólico a las variables, funciones, clases etc.

* Marcos de Activacion: Estructuras de pila que contiene la informacion necesaria para ejecutar un subprograma, como los parametros, variabes locales y la dirección de retorno.
  
* Bloques de Alcance: Son regiones del código donde un nombre es visible y accesible. Puede ser local o global.

* Administracion de Memoria: Es como el lenguaje asigna y libera memoria para variables y objetos.

* Expresiones: Son combinaciones de valores, variables y operadores que producen un resultado.
  
* Comandos: Unidades de accion en un programa (asignaciones, funciones, estructuras de control).
  
* Control de Secuencia: Determinan el orden en que se ejecutaran las instrucciones.

  * Selección: Son aquellas que permiten elegir que instrucciones ejecutar basandose en una condición.

  * Iteración: Permiten ejecutar un bloque de codigo repetidamente. mientras se cumpla con una condicion o se alcanza un limite definido.

  * Recursión: La funcion se llama a sí misma para resolver un problema dividiéndolo en sobproblemas más pequeños.

* Subprogramas: Bloques de codigo que realizan una tarea esspecífica y pueden ser llamados desde otras partes del programa.

* Tipos de Datos: Definen el tipo de valores que pueden tomar las vairables (entero, flotante, caracter, etc).

## Programas

```python

class Book:
    '''Clase para definir los libros de la biblioteca'''
    def __init__(self, book_id, title, author, publication_year, genre, quantity):
        self.id = book_id
        self.title = title
        self.author = author
        self.publication_year = publication_year
        self.genre = genre
        self.quantity = quantity
        memory_management.increment_heap_allocations(1)

    def __del__(self):
        memory_management.increment_heap_deallocations(1)

    def to_dict(self):
        '''Método para convertir los datos del libro en un diccionario'''
        return {
            "id": self.id,
            "title": self.title,
            "author": self.author,
            "publication_year": self.publication_year,
            "genre": self.genre,
            "quantity": self.quantity
        }

    @staticmethod
    def from_dict(data):
        '''Método para crear un objeto libro a partir de un diccionario'''
        return Book(
            int(data["id"]),
            data["title"],
            data["author"],
            int(data["publication_year"]),
            data["genre"],
            int(data["quantity"])
        )
```

En el siguiente bloque de codigo podemos observar como se esta definiendo la clase de nombre "book". A la hora de crearlo podemos notar como se le asignan diferentes tipos de datos como lo son enteros para su id o las cadenas para los titulos y el nombre. Tambien podemos ver diversos subprogramas (def).

```python
def add_book():
    '''Agregar un libro a la biblioteca'''
    data = request.json
    is_digital = data.get('is_digital', False)
    if is_digital:
        book = DigitalBook(
            int(data['id']), data['title'], data['author'], data['publication_year'],
            data['genre'], data['quantity'], data['file_format']
        )
    else:
        book = Book(
            int(data['id']), data['title'], data['author'], int(data['publication_year']),
            data['genre'], int(data['quantity'])
        )
    library.add_book(book)
    # Guardar datos después de agregar un libro
    library.save_library_to_file("library.json")
    memory_management.display_memory_usage()
    return jsonify(book.to_dict()), 201
```

El siguiente bloque de programacion es un subprograma de nombre "add_book" que se encarga de agregar un libro a la biblioteca. En el podemos ver algunas variables locales como lo son son "data", "is_digital" entre otros. Eso significa que solo son accesible dentros de este bloque de codigo y una vez que estemos fuera de este no podremos darle uso. Tambien podemos ver una secuencia de control (if/else) en donde pregunta si el libro es digital, si es falso lo agregara como un libro fisico.

```python
class MemoryManagement:
    '''Class to manage memory usage'''
    def __init__(self):
        self.heap_allocations = 0
        self.heap_deallocations = 0

    def increment_heap_allocations(self, size):
        '''Increment heap allocations'''
        self.heap_allocations += size

    def increment_heap_deallocations(self, size):
        '''Increment heap deallocations	'''
        self.heap_deallocations += size

    def display_memory_usage(self):
        '''Display memory usage'''
        print(f"Heap allocations: {self.heap_allocations} bytes")
        print(f"Heap deallocations: {self.heap_deallocations} bytes")


memory_management = MemoryManagement()
```

Este ultimo bloque de programación crea una clase de nombre "MemoryManagement" en donde controla el uso de memoria ya sea asgignada o liberada. Con la función "increment_heap_allocations" aumenta el contador de meoria asignada, "increment_heap_deallocations" aumenta el contador de la memoria liberada y "display_memory_usage" despliega en la consola cuandta memoria se ha asignado y liberado a lo largo de la ejecucion del programa.