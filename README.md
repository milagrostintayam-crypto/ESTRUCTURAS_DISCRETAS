# Verificación formal básica de algoritmos usando lógica proposicional

## Descripción

Este proyecto implementa un mini sistema bancario en C++ y aplica conceptos de Estructuras Discretas para verificar formalmente una regla algorítmica mediante lógica proposicional.

La operación principal analizada es el retiro bancario. Para realizar un retiro, el algoritmo debe comprobar tres condiciones:

* La cuenta está activa.
* El monto ingresado es positivo.
* Existen fondos suficientes.

Estas condiciones se representan mediante proposiciones simples y se formalizan con la siguiente expresión lógica:

[
(A \land M \land F) \rightarrow R
]

donde:

* (A): la cuenta está activa.
* (M): el monto ingresado es positivo.
* (F): existen fondos suficientes.
* (R): el retiro se realiza.

También se considera la especificación reforzada:

[
R \leftrightarrow (A \land M \land F)
]

Esto significa que el retiro debe realizarse si y solo si las tres condiciones son verdaderas.

## Objetivo

Aplicar lógica proposicional para verificar formalmente una regla algorítmica de retiro mediante proposiciones, fórmulas lógicas, tablas de verdad, cobertura lógica y cumplimiento de especificación.

## Contenidos aplicados del curso

* Lógica proposicional.
* Conectivos lógicos.
* Tablas de verdad.
* Implicación lógica.
* Bicondicional.
* Equivalencias lógicas.
* Leyes de De Morgan.
* Conjuntos.
* Producto cartesiano.
* Combinatoria básica.
* Precondiciones y postcondiciones.
* Cobertura lógica.

## Estructura del proyecto

```text
ESTRUCTURAS_DISCRETAS
│
├── capturas
├── docs
├── resultados
├── src
│   ├── CuentaBancaria.cpp
│   ├── CuentaBancaria.h
│   ├── SistemaBancario.cpp
│   ├── SistemaBancario.h
│   ├── VerificadorLogico.cpp
│   ├── VerificadorLogico.h
│   └── main.cpp
│
├── .gitignore
└── README.md
```

## Compilación

Desde la carpeta principal del proyecto, ejecutar:

```bash
g++ src/main.cpp src/CuentaBancaria.cpp src/SistemaBancario.cpp src/VerificadorLogico.cpp -o programa.exe
```

## Ejecución

En Windows:

```bash
.\programa.exe
```

## Funcionamiento esperado

El programa debe contar con dos partes principales:

1. Menú interactivo para que el usuario pueda realizar operaciones:

   * Iniciar sesión.
   * Depositar.
   * Retirar.
   * Transferir.
   * Ver saldos.

2. Verificación formal automática:

   * Generar los 8 casos posibles de la regla de retiro.
   * Evaluar la fórmula lógica.
   * Comparar el resultado esperado con el resultado obtenido.
   * Calcular casos correctos, casos fallidos y cobertura lógica.

## Regla lógica evaluada

La regla principal es:

[
(A \land M \land F) \rightarrow R
]

El número de casos posibles se calcula con:

[
2^n = 2^3 = 8
]

Por tanto, se evalúan 8 combinaciones lógicas.

## Métricas esperadas

* Casos posibles: 8.
* Casos evaluados: 8.
* Casos correctos: 8.
* Casos fallidos: 0.
* Cobertura lógica: 100 %.
* Cumplimiento de especificación: 100 %.

## Autor

Diana Milagros Tintaya Mamani

## Curso

Estructuras Discretas

## Universidad

Universidad Nacional de Juliaca
Escuela Profesional de Ingeniería de Software y Sistemas
