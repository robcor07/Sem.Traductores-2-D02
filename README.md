# Sem.Traductores-2-D02
Coronel Gonzalez Roberto Manuel 
214771077

Etapa del proyecto analizador léxico completo.

Este proyecto fue desarollado usado el lenguaje de programacion c++ y el compilador Qt.

Este es el reporte de la primera estapa de mi proyecto (compilador). Esta primera etapa corresponde a un analizador lexico el cual recibe simbolos los cuales
debe analizar e identificar correctamente a base de criterios previamente establecidos. En total son 24 diferentes tipos de simbolos los que mi analizador lexico debe 
identificar y a la vez es necesario asignarle su numero de tipo correspondiente (del 0 al 23). Este programa inicia con la obtencion de varios simbolos a analizar y se analiza
character a character usuando un automata el cual identifica el tipo de simbolo y una vez que todos los simbolos son analizados se muestran los resultados obtenidos del analisis.

Símbolo Tipo
identificador 0
entero 1
real 2
cadena 3
tipo 4 int,float,void
opSuma 5 +,-
opMul 6 *,/
opRelac 7 <,<=,>,>=
opOr 8 ||
opAnd 9 &&
opNot 10 !
opIgualdad 11 ==, !=
; 12
, 13
( 14
) 15
{ 16
} 17
= 18
if 19
while 20
return 21
else 22
$ 23

Para obtener una mejor interaccion con mi proyecto decidi agregar una interfaz grafica sencilla que en el transcurso de la elavoracion de mi proyecto tendra diferentes
mejoras. Por el momento mi interfaz cuenta con una ventana que tiene un Textedit para recibir entradas de simbolos, tiene un PushButton para activar el analisis de los simbolos,
y por ultimo tiene un Tablewidget donde se muestran los simbolos de entrada ya analizados.



