# Preguntas orientadoras
## 1.- Describa brevemente los diferentes perfiles de familias de microprocesadores/microcontroladores de ARM. Explique alguna de sus diferencias características.

1. **Cortex A:**
    - Diseñada para aplicaciones de procesamiento intensivo, como sistemas embebidos complejos, dispositivos móviles, sistemas de entretenimiento y más.
    - Soporte para sistemas operativos completos como Linux, Android, etc.
    - Ofrece una amplia gama de características, incluyendo múltiples núcleos, SIMD (NEON), caché, memoria grande, y potencia de procesamiento significativa.
    - Se enfoca en aplicaciones que requieren un alto rendimiento de procesamiento, con potencia y complejidad asociadas.
2. **Cortex R:**
    - Orientada a sistemas en tiempo real y críticos para la seguridad, como sistemas de control en tiempo real, sistemas de automoción, sistemas médicos, etc.
    - Ofrece capacidades de alta confiabilidad, baja latencia y funciones de seguridad integradas.
    - Está diseñada para garantizar una ejecución determinista y fiable en sistemas que necesitan respuesta en tiempo real y alta disponibilidad.
3. **Cortex M:**
    - Diseñada para sistemas embebidos de baja potencia y tiempo real, ampliamente utilizada en microcontroladores para una variedad de aplicaciones.
    - Ofrece un equilibrio entre rendimiento y eficiencia energética, adecuado para aplicaciones de electrónica de consumo, dispositivos médicos, automoción, etc.
    - Enfocada en aplicaciones que requieren baja potencia y alta eficiencia energética, sin comprometer el rendimiento en tareas en tiempo real.


# Cortex M

## 1.- Describa brevemente las diferencias entre las familias de procesadores Cortex M0, M3 y M4.

- **Cortex M0:** Utiliza una arquitectura de datos de Von Neumann, donde las instrucciones y los datos comparten la misma memoria principal. Basado en la arquitectura ARMv6-M. Utiliza el conjunto de instrucciones Thumb, incluyendo Thumb-1 y Thumb-2, que son instrucciones de 16 y 32 bits respectivamente. No tiene soporte para instrucciones de punto flotante.
- **Cortex M3:** Utiliza una arquitectura de datos de Harvard modificado, donde las instrucciones y los datos están en memorias separadas, pero comparten el mismo espacio de direcciones. Basado en la arquitectura ARMv7-M. Utiliza principalmente el conjunto de instrucciones Thumb-2, que incluye instrucciones de 16 y 32 bits, lo que mejora la densidad de código y el rendimiento. No tiene soporte para instrucciones de punto flotante en la configuración base, pero puede incluir una FPU en implementaciones opcionales.
- **Cortex M4:** Al igual que el Cortex-M3, utiliza una arquitectura de datos de Harvard modificado. Basado en la arquitectura ARMv7-M. Utiliza principalmente el conjunto de instrucciones Thumb-2, con extensiones DSP (procesamiento de señales digitales) y SIMD (NEON) para mejoras de rendimiento. Incluye instrucciones de punto flotante en Thumb-2 y puede incluir una unidad de punto flotante (FPU) en implementaciones opcionales para operaciones de punto flotante más rápidas.

## 2.- ¿Por qué se dice que el set de instrucciones Thumb permite mayor densidad de código? Explique
Los procesadores cortex M3 y M4 cuentan con la tecnologia THUMB-2 la cual permite mezclar instrucciones de 16 y 32 bits.
El porque permite la mayor densidad de codigo se debe a:
- En los clasicos procesadores ARM el procesador tenia dos estado de operacion; 32-bit ARM y 16-bit Thumb. Donde en una era soportada las instrucciones de 32 bits y en la otra las instrucciones de 16 bits. El cambio entre estados de operacion del procesador, provocaba que el tiempo de obtencion y ejecucion de instrucciones demore mas, adicional que las instrucciones de 32-bit ARM, ocupaban un mayor espacio en la memoria de programa. 
- Con las instrucciones clasicas, se tenia que especificar el estado del procesador antes de escribir la instruccion en el codigo fuente.
- Al implementar Thumb-2 se obtiene instrucciones optimizadas y velocidad, ademas que ya no se tendra que hacer el cambio de estado del procesador, logrando eficiencia y rendimiento al mismo tiempo.
- Las instrucciones Thumb son más cortas en longitud que las instrucciones ARM de 32 bits, lo que reduce la cantidad de memoria necesaria para almacenar el código. Cada instrucción Thumb es de 16 bits en longitud, mientras que las instrucciones ARM son de 32 bits.
- La estructura compacta de las instrucciones Thumb permite empaquetar más instrucciones en la misma cantidad de memoria.

## 3.- ¿Qué entiende por arquitectura load-store? ¿Qué tipo de instrucciones no posee este tipo de arquitectura?
Esto significa que los datos deben cargarse desde la memoria, procesarse y escribirse de nuevo en la memoria mediante una seria de instrucciones. Por ejemplo, si deseamos incrementar un valor de datos almacenado en la SRAM el procedimiento es el siguiente:
- Procesador necesita una instruccion para leer los datos de la SRAM y colocarlos en los registros de proposito general del procesador.
- Se necesita una segunda instruccion para aumentar el valor que ya esta almacenado en los registros del procesador.
- Se necesita una tercera instruccion para escribir el nuevo valor en la memoria SRAM.
Esta arquitectura no posee instrucciones donde se requiera operar directamente sobre datos almacenados en la memoria. Por ejemplo.
~~~
ADD [dirección], R1, R2   ; Sumar el contenido de la dirección con el contenido de R1 y almacenar el resultado en memoria
~~~
En lugar de eso, primero se debe cargar el contenido de la dirección y luego realizar la operación utilizando registros:
~~~
LDR R3, [dirección]       ; Cargar el contenido de la dirección en R3
ADD R3, R1, R2            ; Sumar R1 y R2 y almacenar el resultado en R3
STR R3, [dirección]       ; Almacenar el resultado en la dirección
~~~

