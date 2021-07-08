# Darko
Repositorio para el trabajo de Informática Industrial

@Miguel
Changes v4.0
- Monedas con limite en 100, otorgando 2 vidas.
- Se ha incorporado fin de partida.

@Sofía
Changes v3.9
- Sprites de personajes editados y recolocados.
- Sprites rediseñados.
- Imágenes de transición rediseñadas.
- Código adaptado a la música nueva en cada estado. Comprobación de que cambia cuando se requiere.


@David y Diego
Changes v3.8
- Solucionadas colisiones entre disparosAmigos y enemigos
- Solucionadas colisiones entre bolaFuego y personaje
- Solucionadas interacciones con plataforma movil


@David
Changes v3.7
- Solucionadas colisiones con paredes verticales
- Solucionado movimiento de enemigos cuando hay varias plataformas en distintas alturas
- Solucionado espada y colisiones con espada


@Diego y Mica
Changes v3.6
    - Colocados los sprites de:
        - Sólidos (suelo, plataformas, pinchos y bolas de fuego)
        - Enemigos (faltan por mejorar babosas, tentaculos y bombers
        - Personaje darko (a modo de prueba)
    
    
@David
Changes v3.5
- Solucionadas las interacciones entre personaje y enemigos con el entorno


@Sofía:
Changes v3.4.
- Menú finalizado.
- Clases referente a este editadas.
- Comparación y unión de versiones de código.
- Imágenes de transición recolocadas.


@Diego y Mica
Changes v3.3
- Juntadas las listas de enemigos, solidos y el personaje en interacciones
- Comenzada la lista de disparos e interactuada con enemigops y el personaje
- Adaptados los mundos a los nuevos cambios introducidos
- Añadida a la lista de solidos la clase bola de fuego


@David
Changes v3.2
- Comenzadas las herencias de los enemigos
- Comenzadas las listas de objetos móviles


@Diego
Changes v3.1
- Comenzadas las herencias de las clases para pulir código
- Subidos los ficheros Solidos.h y Solidos.cpp con las clases Pincho, Pared, PlatMovil y Suelo como herencias suyas tamboén includias en estos ficheros
- Borradas por tanto las clases Pared, Pincho y PlatMovil de /src 


@Mica 
Changes v3.0
- Creados los niveles 6,7,8 y acabado el nivel 9 (solo falta añadir el boss)
- Revisados el resto de niveles (cambio de las posiciones de las monedas)
- Cambios en los parametros de pincho (mas pequeño) y hombre (cae desde más altura)


@Miguel
Changes v2.9
- Contadores de vida y dinero solucionado. (Pendiente crear función reduceVida() para más fácil implementación en el resto de codigo)


@Diego y Mica
Changes v2.8
- Terminados los niveles 4 y 5 (***)


@David
Changes v2.7
- Sistema de vida y daño contra enemigos 


@Sofía:
Changes v2.6.
- Menú editado.
- Canciones ubicadas.
- Sprites diseñados.
- Imágenes de transición diseñadas.


@David
Changes v2.5
- Solución de errores


@Diego y Mica
Changes v2.4
- Añadidas las plataformas móviles (***)
- Terminados los niveles 2 y 3 (***)


@Diego y Mica
Changes v2.3
- Añadido el método cargarnivel()
- Añadidos el nivel 2 y las bolas de fuego como lista
- Pulidas las llamadas a plataformas y otros elementos


@David
Changes v2.2
- Solucionada interaccion con paredes verticales
- Añadido bossFinal y sus interacciones


@Mica
Changes v2.1
- Añadida la clase bola de fuego
- Intento de interaccion de la misma con el pj


@David
Changes v2.0
- Añadida la espada
- Comentados los pozos para luego tratarlos como paredes verticales
- Interacciones entre espada y enemigos añadidas
- Interacciones de tentaculo


@Diego
Changes v1.9.2
- Terminado el diseño del nivel 1
- Separados los suelos de la caja y tratados como plataformas del nivel
- Quitados los bonus de manera temporal


@Mica
Changes v1.9.1 
- Añadir plataformas (sino no llega el hombre) y pinchos


@David
Changes v1.9
- Se han hecho listas de pinchos y bonus
- Se han hecho interacciones entre disparos amigos y casi todos los enemigos
- Se han hecho interacciones entre personaje principal y disparos enemigos
- Se han empezado las interacciones de personaje con bonus, pinchos, babosa y bomber


@David
Changes v1.8
- Se han unido DispEnem y DispTank en DisparosEnemigos por simplificacion
- Se ha empezado la interaccion DispEnem-Entorno
- Se han añadido disparosAmigo
- Se ha solucionado la caida del mundo por el borde derecho


@Miguel
Changes v1.7.
- Se han terminado la interaccion Hombre-EnemigoDisp
- Se ha añadido el aumento de Monedas (Faltaria un sprite de numeros para mejor implementacion)


@David
Changes v1.6.
- Se han añadido listas de tentáculo y babosa
- Se ha añadido nuevo enemigo bomber y su lista
- Se ha solucionado problema con tank y tentáculo


@Miguel
Changes v1.5.
- Se ha añadido sistema de vida y moneda renovado con listas y herencias. Ahora las vidas recolectadas aumenta.


@David
Changes v1.4.
- Se han añadido los enemigos tentaculo y babosa
- Se han añadido listas de plataformas y eneDisp
- Se han arreglado las colisiones entre plataformas, hombre y eneDisp usando las listas


@Diego
Changes v1.3.
- A falta de añadir los archivos referenciados, el menú está añadido
- Las vidas se mueven ahora en el eje x con el personaje pero no saltan con él


@Miguel:
Changes v1.2.
- Se ha comenzado la interacción entre enemigos.
- La vida ahora se mueve junto al personaje.
- Ajustado el ojo para moverse por el eje "y" también.


@Miguel:
Changes v1.1.
- Añadido clase Interfaz para englobar todo lo relacionado a objetos que aparecen en pantalla que no pertenece al mundo fisico (simbolos de vida, cantidad de dinero, distintos bonus activos, mapa de posicion, etc).
- Añadido clase Vidas.
- Añadido clase Dinero.
- Cambiado el sistema de movimiento para que se pare al soltar tecla. (solo wasd)


@Sofía:
Changes v1.0.
- Menú creado, añadido casi todo lo que podría ser necesario una vez se tengan los niveles. 
- .h adaptado.
- Imágenes de prueba incluídas en la carpeta de imágenes.
- Música de prueba incluída en la carpeta de música.
