#include "CuentaBancaria.h"
#include <iostream>

/**
 * @file CuentaBancaria.cpp
 * @brief IMPLEMENTACIÓN de los métodos de la clase CuentaBancaria.
 * Este archivo contiene la lógica que define "cómo" funcionan los métodos.
 */

// Implementación del Constructor 1 (con saldo inicial).
// Usa la lista de inicializadores para asignar los valores a los atributos.
CuentaBancaria::CuentaBancaria(std::string titular, int id, double saldoInicial)
    : titular(titular), id(id), saldo(saldoInicial > 0 ? saldoInicial : 0.0) {
    std::cout << "CONSTRUCTOR: Se ha creado la cuenta #" << this->id
              << " para " << this->titular << " con un saldo inicial de $" << this->saldo << std::endl;
}

// Implementación del Constructor 2 (sin saldo inicial, se delega al primero).
// C++11 permite "delegar" a otro constructor de la misma clase para evitar duplicar código.
CuentaBancaria::CuentaBancaria(std::string titular, int id)
    : CuentaBancaria(titular, id, 0.0) { // Llama al primer constructor con saldo 0.
    std::cout << "CONSTRUCTOR (delegado): Cuenta creada con saldo cero." << std::endl;
}

// Implementación del Destructor.
// Se ejecuta cuando el objeto sale del ámbito (ej. al final de main()).
CuentaBancaria::~CuentaBancaria() {
    std::cout << "DESTRUCTOR: La cuenta #" << this->id << " de " << this->titular
              << " ha sido cerrada." << std::endl;
}

// Implementación del Getter para el saldo.
double CuentaBancaria::getSaldo() const {
    return this->saldo;
}

// Implementación del Setter para depositar, con validación.
void CuentaBancaria::depositar(double monto) {
    if (monto > 0) {
        this->saldo += monto;
        std::cout << ">> Deposito exitoso de $" << monto << ". Nuevo saldo: $" << this->saldo << std::endl;
    } else {
        std::cout << ">> ERROR: El monto a depositar debe ser positivo." << std::endl;
    }
}

// Implementación del Setter para retirar, con validación.
bool CuentaBancaria::retirar(double monto) {
    if (monto <= 0) {
        std::cout << ">> ERROR: El monto a retirar debe ser positivo." << std::endl;
        return false;
    }

    if (monto <= this->saldo) {
        this->saldo -= monto;
        std::cout << ">> Retiro exitoso de $" << monto << ". Nuevo saldo: $" << this->saldo << std::endl;
        return true;
    } else {
        std::cout << ">> ERROR: Fondos insuficientes. Intento de retirar $" << monto
                  << " pero solo hay $" << this->saldo << " disponible." << std::endl;
        return false;
    }
}
