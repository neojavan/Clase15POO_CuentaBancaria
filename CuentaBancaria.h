#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <string>

/**
 * @class CuentaBancaria
 * @brief DECLARACIÓN de la clase CuentaBancaria.
 * Este archivo .h define la interfaz de la clase, es decir, qué atributos
 * tiene y qué métodos se pueden usar para interactuar con ella.
 */
class CuentaBancaria {
private:
    // Atributos privados para proteger la integridad de los datos (Encapsulamiento).
    std::string titular;
    int id;
    double saldo;

public:
    // --- Constructores (Sobrecargados) ---
    // Permiten crear objetos de diferentes maneras.

    /**
     * @brief Constructor para crear una cuenta con un saldo inicial.
     */
    CuentaBancaria(std::string titular, int id, double saldoInicial);

    /**
     * @brief Constructor para crear una cuenta con saldo en cero.
     */
    CuentaBancaria(std::string titular, int id);

    // --- Destructor ---
    /**
     * @brief Se ejecuta automáticamente cuando un objeto es destruido.
     */
    ~CuentaBancaria();

    // --- Getters (Accesores) ---
    /**
     * @brief Devuelve el saldo actual de la cuenta. Es 'const' porque no modifica el objeto.
     * @return El saldo de la cuenta.
     */
    double getSaldo() const;

    // --- Setters (Mutadores) con Validación ---
    /**
     * @brief Deposita un monto en la cuenta. Incluye validación.
     * @param monto El monto a depositar (debe ser positivo).
     */
    void depositar(double monto);

    /**
     * @brief Retira un monto de la cuenta. Incluye validación.
     * @param monto El monto a retirar (debe ser positivo y menor o igual al saldo).
     * @return true si el retiro fue exitoso, false en caso contrario.
     */
    bool retirar(double monto);
};

#endif //CUENTABANCARIA_H
