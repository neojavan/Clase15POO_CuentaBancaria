#include <iostream>
#include "CuentaBancaria.h"

/**
 * @file main.cpp
 * @brief Programa principal para simular el uso de la clase CuentaBancaria.
 */
int main() {
    std::cout << "===== SIMULACIÓN BANCARIA =====" << std::endl;

    // --- Creación de Objetos (Instanciación) ---
    // Se crean dos objetos utilizando los constructores sobrecargados.
    std::cout << "\n--- Creando Cuentas ---" << std::endl;
    CuentaBancaria cuentaDeCarolina("Carolina Carrascal", 101, 200000.0);
    CuentaBancaria cuentaDeCarlos("Carlos Calas", 102); // Usa el constructor que delega

    // --- Interacción con los Objetos ---
    std::cout << "\n--- Operaciones en la cuenta de Ana ---" << std::endl;
    // Usamos el getter para consultar el saldo.
    std::cout << "Saldo actual de Ana: $" << cuentaDeCarolina.getSaldo() << std::endl;
    // Usamos los setters para modificar el estado del objeto.
    cuentaDeCarolina.depositar(50000);
    cuentaDeCarolina.retirar(30000);

    // Intento de operación inválida (retiro con fondos insuficientes).
    cuentaDeCarolina.retirar(500000);

    std::cout << "\n--- Operaciones en la cuenta de Carlos ---" << std::endl;
    std::cout << "Saldo actual de Carlos: $" << cuentaDeCarlos.getSaldo() << std::endl;
    // Intento de operación inválida (depósito negativo).
    cuentaDeCarlos.depositar(-10000);
    cuentaDeCarlos.depositar(80000);
    cuentaDeCarlos.retirar(20000);

    std::cout << "\n===============================" << std::endl;
    std::cout << "Los destructores se llamarán automáticamente al salir de este ámbito." << std::endl;

    return 0;
}

