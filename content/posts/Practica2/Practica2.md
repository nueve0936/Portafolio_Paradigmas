# Practica 2: Analizando Programas

## Introducción
En el siguiente reporte analizaremos y describiremos el funcionamiento de tres programas relacionandolo con los temas que vimos en clase para poder entenderlos mejor. Para que haya una mejor visualizacion lo que haremos sera dividirlo en las partes mas importantes destacando lo mas particulara de cada uno de estos.

***

### Programa 1
El siguiente programa esta escrito en Java y simula un sistema de insripción para estudiantes en actividades/materias. Muestra los diferentes conceptos de  Clases, Objetos, Herencia, Sobrecarga y sobreescritura de metodos y encapsulamiento basico.

```javascript
public class Persona {
  String nombre;
  int ine;

  public Persona(String nombre, int ine){
    this.nombre = nombre;
    this.ine = ine;
  }

  public String inscribirse(String actividad){
    return "La inscripción de "+nombre+" para "+actividad+" se ha realizado satisfactoriamente.";
  }
}
```
Esta clase representa a una persona. Cuenta con dos atributos y un constructor para inicializar esos valores asi como tambien cuenta con un metodo. 

Atributos:
* nombre:  El nombre de la persona.
* ine: La identificacion de la persona.

Metodos:
* inscribirse(String actividad): El metodo devuelve un mensaje para darnos a entender que la inscripcion se realizo de manera correcta. 

```javascript
public class Materia {
    String titulo;
    String carrera;
    int cupo;

    public Materia(String titulo, String carrera) {
      this.titulo=titulo;
      this.carrera=carrera;
      this.cupo=40;
    }

    public int getCupo() {
      return cupo;
    }

    public int tomarCupo() {
      if(cupo==0) return cupo;
      return this.cupo=cupo-1;
    }

    public String getTitulo() {
      return titulo;
    }
  }
```
Esta clase representa una materia. Cuenta con tres atributos y tres metodos.

Atributos:
* titulo: El nombre de la materia.
* carrera: La carrera a la que pertenece.
* cupo: La cantidad de estudiantes que pueden inscribirse (inicia en 40).

Metodos:
* getCupo(): Regresa el cupo disponible de la materia.
* tomarCupo(): Diminuye el cupo en 1 si es que se encuentran lugares disponibles.
* getTitulo(): Regresa el titulo.

```javascript
public class Estudiante extends Persona {
  String carrera;
  int matricula;
  String ciclo;

  public Estudiante(String nombre, int ine, String carrera, int matricula, String ciclo) {
    super(nombre, ine);
    this.nombre=nombre;
    this.ine=ine;
    this.carrera=carrera;
    this.matricula=matricula;
    this.ciclo=ciclo;
  }

  public boolean verificar_cupo(Materia materia) {
    if (materia.getCupo()>= 1) return true;
    return false;
  }

  //método heredado que exhibe conducta propia de la clase hija
  //sobreescritura de método padre
  @Override
  public String inscribirse(String actividad) {
    return "El alumno "+nombre+" INE "+ine+" perteneciente a la carrera "+carrera+" ha completado su inscripción";
  }

  //sobrecarga de método padre
  public String inscribirse(String actividad, LocalDate fecha) {
    return "Inscripción realizada para la actividad "+actividad+" a tener lugar el "+fecha;
  }

  public String inscribirse(Materia materia) {
    if(verificar_cupo(materia)){
        materia.tomarCupo();
        return "Se completó la inscripción en "+materia.titulo;
      }else{
        return "No hay cupo disponible";
      }
  }
}
```

Se Hereda de Persona y tiene. Tiene 3 atributos y un constructor para inicializar con esos datos asi como tambien tiene 4 metodos.

Atributos:
* carrera: En que carrera es que esta inscrito.
* matricula: El numero de la matricula.
* ciclo: Su ciclo escolar.

Metodos:
* verificar_cupo(Materia materia): Verifica si hay cupo disponible en la materia.
* inscribirse(String): Reescribe el metodo del padre (osea, Persona) para personalizar el mensaje en Estudiante
* inscribirse(String actividad, LocalDate fecha): Sobrecarga el metodo de inscribirse, ahora tambien recibe una fecha.
* inscribirse(Materia materia): Si es que hay cupo, reduce el cupo en 1 y confirma la inscripcion. De no ser ese el caso indica que no hay lugar.

```javascript
public class Main {
  public static void main(String[] args) {
    Materia informatica = new Materia("Informática", "Sociología");
    Estudiante gabriel = new Estudiante("Gabriel Mena", 1323220, "Sociología", 90239102, "2022-1");

    gabriel.inscribirse("Rubgy");

    gabriel.inscribirse(informatica);
    gabriel.inscribirse("Jornadas Estudiantiles", LocalDate.of(2022, java.time.Month.NOVEMBER, 23));
  }
}
```

En el programa main lo que pasa es que se crea un objeto Maateria llamado "informatica y un Estudiante llamado "gabriel". A lo largo del main se llama a 3 versiones distintas de "inscribirse()":
* Solo con String se manda a llamar la escritura.
* Con Materia revisa si hay cupo, y si es que lo hay lo inscribe.
* Con String y LocalDate invocamos la sobrecarga.
 
## Programa 2
El siguiente programa esta escrito en Java y define una estructura para representar cursos universitarios que son dictados po diferentes tipos de entidades. Usa clases genericas para lograr flexibilidad.

```javascript
public class Curso<T> {
  private String titulo;
  private T entidad;
  private String semesetre;

    public Curso(String titulo, T entidad, String semestre){
    this.titulo = titulo;
    this.entidad = entidad;
    this.semestre = semestre;
    }

    public String inscribirse(){
      return "El alumno "+nombre+" se ha inscrito exitosamente en el curso"+titulo+" ofrecido por la/el "+entidad.toString()+"durante el periodo lectivo"+semestre;
    }
}
```
Esta clase la puede aceptar cualquier tipo como entidad, en pocas palabras es una clase generica. Cuenta con tres atributos y un constructor que inicializa los atributos ademas de un metodo.

Atributos:
* titulo: El nombre del curso.
* entidad: La entidad que ofrece el curso.
* semestre: El periodo en el que se dicta el curso

Metodos:
* public String inscribirse(): Devuelve el mensaje de inscripcion cuando se realiza de manera exitosa. Utiliza "etnidad.toString() para mostrar que entidad ofrece el curso".
  
```javascript
public class Facultad{
  String nombre;
  int nroEscuelas;

  public Facultad(String nombre, int nroEscuelas){
    this.nombre=nombre;
    this.nroEscuelas=nroEscuelas;
  }

  @Override
  public String toString(){
    return nombre;
  }
  public class Escuela{
  Facultad facultad;
  String nombre;

  public Escuela(Facultad facultad, String nombre){
    this.facultad=facultad;
    this.nombre=nombre;
  }

  @Override
  public String toString(){
    return nombre;
  }
}

public class Instituto{
Facultad facultad;
String nombre;
int nroInvestigadores;

  public Instituto(Facultad facultad, String nombre, int nroInvestigadores){
    this.facultad=facultad;
    this.nombre=nombre;
    this.nroInvestigadores=nroInvestigadores;
  }

  @Override
  public String toString(){
      return nombre;
    }
  }
}
```
Estas clase representan entidades academicas y cuentan conatributos en donde se les asigna el numero de invstigadores nombres de la facultad, el instututo etc. Tanto "Escuela" como "Instituto" estan asociadas a una "Facultad" e implementan toString() para devolver su nombre.

```python
public class Main {
  public static void main(String[] args) {
    Facultad facultad_de_ciencias = new Facultad("Facultad de Ciencias", 4);
    Instituto instituto_avanzado = new Instituto(facultad_de_ciencias, "Instituto de Estudios Avanzados", 40);
    Curso<Escuela> python_per_tutti = new Curso<>("Python per tutti", new Escuela(facultad_de_ciencias, "Escuela de Computación"), "2022-2");
    Curso<Facultad> curso_inductorio = new Curso<>("Curso inductorio", facultad_de_ciencias, "2022-1");
    Curso<Instituto> algoritmos_geneticos = new Curso<>("Algoritmos genéticos", instituto_avanzado, "2022-1");

    python_per_tutti.inscribirse("Juan Linares");
    algoritmos_geneticos.inscribirse("Pino Piatelli");
    curso_inductorio.inscribirse("Mario Balotelli");
  }
}
```

Lo que hace el programa "main" es crear una facultad, un instituto asociado a esa facultad y tres cursos, cada uno dictado por una entidad distinta: una esccuela, una faultad y un instituto. AL final se inscriben los estudiantes en los cursos.

## Programa 3
EL siguiente y ultimo programa define una estructura basica para representar tanto a personas como estudiantes mediante el uso de clases.

```python
class Persona:
  def __init__(self, nombre, ine):
    self.nombre=nombre
    self.ine=ine
  def inscribirse(self, actividad):
    raise NotImplementedError
```

La siguiente clase base representa a una persona. Cuenta con dos atributos y un metodo.

Atributos:
* nombre: Representa el nombre de la persona.
* ine: Representa la identificacion de la persona.

Metodos:
* inscribirse(self, actividad): Lanza una excepcion ya que si vemos bien, no esta implementado. Esto es porque seran las clases hijas las que vayan a sobreescribirlo.

```python
class Estudiante(Persona):
  def __init__(self, nombre, ine, carrera):
    super().__init__(nombre, ine)
    self.carrera=carrera

  def inscribirse(self, curso):
    return "El alumno "+self.nombre+" documento de identidad nro "+str(self.ine)+" se ha inscrito exitosamente en el curso "+curso
```

Esta clase derivada hereda de la clase anterior, osea, "Persona". Tiene un atributo y un metodo.

Atributos:
* carrera: Representa el nombre de la carrera que cursa el estudante.

Metodo:
* inscribirse(self, actividad): Devuelve un mensaje indicando que el estudiante se ha inscrito con exito en un curso en concreto. Como podemos observar, aqui el metodo si esta implementado.
  
```python
def inscribir(nombre, ine, curso = "Matemáticas", periodo ="2022-II"):
  return "El alumno "+nombre+" ine nro "+str(ine)+" se ha inscrito en el curso "+curso+" en el periodo lectivo "+periodo
```

El siguiente bloque de programacion es una funcion que no pertenece a ninguna clase y que cuenta con dos parametros obligatorios (nombre e ine) y otros dos por default (curso y periodo). Lo que hace esta funcion es devolver una cadena indicando que el alumno se ha inscrito con exito en el curso y periodos indicados.


```python
st = Estudiante("Juan Moreno", 54458, "Ciencias de la Computación")
st.inscribirse("Python para todos")

inscribir("Juan Martir", 2323343)
inscribir("Juan Martir", 2323343, "Ciencias Sociales")
inscribir("Juan Martir", 2323343, "Ciencias Sociales", "2022-I")
```

En el programa main lo que hacemos es crear un objeto tipo estudiante, luego llamamos a su metodo "inscribirse" y nos devuelve el mensaje indicando que el alumno se ha inscrito en un curso (Python para todos).
Ya en los siguientes mantiene sus datos personales pero cambia lo que es el curso y periodo escolar.

***

## Conclusion
A lo largo de los tres programas pudimos ver el uso de multitples temas vistos en lase y podemos observar el como su uso de manera correcta nos facilitan mucho la codificacion a la hora de implementarlo en un programa principal sin tener muchas complicaciones. Aprender, mejorar y perfeccionar estos temas es de suma importancia para nosotros como programadores si lo que queremos es no solo conocer todas las herramientas que tenemos a nuestra disposicion, si no tambien hacer los programas lo mejor posible tanto en funcionamiento como en rendimiento.
