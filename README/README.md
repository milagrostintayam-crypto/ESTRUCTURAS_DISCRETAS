# VERIFICACIÓN FORMAL BÁSICA DE ALGORITMOS USANDO LÓGICA

## Descripción

Mini sistema bancario desarrollado en C++ usando Programación Orientada a Objetos.  
El proyecto aplica lógica proposicional para verificar reglas de operaciones bancarias.

## Operaciones

- Inicio de sesión
- Depósito
- Retiro
- Transferencia

## Regla principal

La operación de retiro se verifica con la fórmula:

(A ∧ M ∧ F) -> R

Donde:

- A: cuenta activa
- M: monto positivo
- F: fondos suficientes
- R: retiro realizado

## Compilación

```bash
g++ src/main.cpp -o mini_banco