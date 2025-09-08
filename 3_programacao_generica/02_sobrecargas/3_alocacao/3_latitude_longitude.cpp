#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <memory>

/**
 * @class Loc
 * @brief Classe que representa uma localização geográfica.
 *
 * Esta classe armazena informações de latitude e longitude e fornece métodos para exibir
 * esses dados. Além disso, implementa operadores personalizados para alocação e desalocação
 * de memória.
 */
class Loc
{
private:
    double latitude;  ///< Latitude da localização
    double longitude; ///< Longitude da localização

public:
    /**
     * @brief Construtor que inicializa a localização com latitude e longitude.
     *
     * @param lat Latitude da localização.
     * @param lon Longitude da localização.
     */
    Loc(double lat, double lon);

    /**
     * @brief Construtor padrão que inicializa a localização como (0, 0).
     */
    Loc();

    /**
     * @brief Método que exibe a latitude e a longitude.
     */
    void print() const;

    /**
     * @brief Sobrecarga do operador `new` para alocação de memória para um único objeto.
     *
     * Este operador chama a alocação global de memória e verifica se a alocação foi bem-sucedida.
     *
     * @param size Tamanho do bloco de memória a ser alocado.
     * @return Ponteiro para o bloco de memória alocado.
     * @throws std::bad_alloc Se a alocação de memória falhar.
     */
    static void *operator new(std::size_t size);

    /**
     * @brief Sobrecarga do operador `new[]` para alocação de memória para um array de objetos.
     *
     * Este operador chama a alocação global de memória para um array e verifica se a alocação
     * foi bem-sucedida.
     *
     * @param size Tamanho do bloco de memória a ser alocado.
     * @return Ponteiro para o bloco de memória alocado.
     * @throws std::bad_alloc Se a alocação de memória falhar.
     */
    static void *operator new[](std::size_t size);

    /**
     * @brief Sobrecarga do operador `delete[]` para desalocação de memória de um array de objetos.
     *
     * Este operador chama a desalocação global de memória para um array de objetos.
     *
     * @param p Ponteiro para o bloco de memória a ser desalocado.
     */
    static void operator delete[](void *p);

    /**
     * @brief Sobrecarga do operador `delete` para desalocação de memória de um único objeto.
     *
     * Este operador chama a desalocação global de memória para um único objeto.
     *
     * @param p Ponteiro para o bloco de memória a ser desalocado.
     */
    static void operator delete(void *p);
};

Loc::Loc(double lat, double lon) : latitude(lat), longitude(lon) {}
Loc::Loc() : latitude(0), longitude(0) {}

void *Loc::operator new(std::size_t size)
{
    // Usa o operador global `new` para alocar memória
    void *ptr = ::operator new(size);

    if (!ptr)
    {
        throw std::bad_alloc(); // Lança uma exceção se a alocação falhar
    }
    return ptr;
}

void Loc::print() const
{
    std::cout << "Latitude: " << std::fixed << std::setprecision(2) << latitude << '\n';
    std::cout << "Longitude: " << std::fixed << std::setprecision(2) << longitude << '\n';
}

void *Loc::operator new[](std::size_t size)
{
    // Usa o operador global `new[]` para alocação de memória para um array
    void *ptr = ::operator new[](size);

    if (!ptr)
    {
        throw std::bad_alloc(); // Lança uma exceção se a alocação falhar
    }
    return ptr;
}

void Loc::operator delete[](void *p)
{
    // Usa o operador global `delete[]` para desalocar memória do array
    ::operator delete[](p);
}

void Loc::operator delete(void *p)
{
    // Usa o operador global `delete` para desalocar memória do objeto
    ::operator delete(p);
}

int main(int argc, char **argv)
{
    std::unique_ptr<Loc> point1;
    std::unique_ptr<Loc[]> point2;

    try
    {
        // Aloca memória para um único objeto Loc
        point1 = std::make_unique<Loc>(10.0, 20.0);
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
        return 1; // Retorna um código de erro se a alocação falhar
    }

    // Exibe as coordenadas de point1
    point1->print();

    std::cout << "\n--------------------------------" << '\n';

    try
    {
        // Aloca memória para um array de 5 objetos Loc
        point2 = std::make_unique<Loc[]>(5);
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
        point1.reset(); // Desaloca memória de point1 caso ocorra erro
        return 1;       // Retorna um código de erro
    }

    // Inicializa os valores de latitude e longitude para os objetos do array
    for (int i = 0; i < 5; ++i)
    {
        point2[i] = Loc(10.0 + i, 20.0 + i); // Atribui valores específicos para cada Loc
    }

    // Exibe as coordenadas dos objetos do array
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "ponto[" << i << "]: " << '\n';
        point2[i].print();
        std::cout << '\n';
    }

    // Desaloca a memória dos objetos
    point1.reset(); // Desaloca a memória de um único objeto Loc
    point2.reset(); // Desaloca a memória do array de objetos Loc

    return 0;
}
