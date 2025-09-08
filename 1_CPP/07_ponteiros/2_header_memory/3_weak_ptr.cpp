#include <iostream>
#include <string>
#include <vector>
#include <memory>

/**
 * std::weak_ptr<T>: Ponteiro Observador em C++, é um ponteiro inteligente que não
 * possui o objeto que referencia, mas pode observar um objeto gerenciado por
 * std::shared_ptr sem interferir em seu ciclo de vida. Seus principais aspectos:
 *
 * - Não possui ownership (não gerencia tempo de vida do objeto).
 * - Observa recursos gerenciados por std::shared_ptr.
 * - Usos principais: Quebrar referências cíclicas entre shared_ptrs, Verificar se objeto
 * ainda existe antes de acessar.
 *
 * FUNCIONAMENTO: Criado a partir de shared_ptr para acessar o objeto:
 * std::shared_ptr<T> temp = weak.lock(); // Retorna shared_ptr válido ou nullptr
 *
 * VANTAGENS:
 * - Evita memory leaks por ciclos de referência
 * - Permite verificação segura de objetos destruídos
 * - Não interfere no contador de referências do shared_ptr
 */

// Dispositivos que podem ser monitorados
enum class DeviceType
{
    Printer,
    Scanner,
    Storage
};

// Union para armazenar dados específicos do dispositivo
union DeviceData
{
    int pagesPrinted;     // Para impressoras
    int scansCompleted;   // Para scanners
    double storageUsedGB; // Para armazenamento

    DeviceData() : storageUsedGB(0.0) {} // Inicialização padrão
    ~DeviceData() {}                     // Destrutor trivial necessário
};

// Classe base para dispositivos
class Device
{
public:
    DeviceType type;
    std::string id;
    DeviceData data;

    Device(DeviceType t, std::string i) : type(t), id(i) {}
    virtual ~Device() = default;

    virtual void printStatus() const = 0;
    virtual void useDevice() = 0;
};

// Observador que usa weak_ptr para monitorar dispositivos sem possuí-los
class DeviceObserver
{
private:
    std::vector<std::weak_ptr<Device>> observedDevices;

public:
    void observe(std::shared_ptr<Device> device)
    {
        observedDevices.push_back(device);
    }

    void checkDevices()
    {
        std::cout << "\n=== Verificando dispositivos observados ===\n";

        for (auto &weakDev : observedDevices)
        {
            if (auto sharedDev = weakDev.lock())
            {
                std::cout << "Dispositivo " << sharedDev->id << " ainda ativo: ";
                sharedDev->printStatus();
            }
            else
            {
                std::cout << "Dispositivo foi desalocado\n";
            }
        }
    }
};

// Implementações específicas de dispositivos
class Printer : public Device
{
public:
    Printer(std::string id) : Device(DeviceType::Printer, id)
    {
        data.pagesPrinted = 0;
    }

    void printStatus() const override
    {
        std::cout << "Impressora (" << id << ") - Páginas impressas: "
                  << data.pagesPrinted << '\n';
    }

    void useDevice() override
    {
        data.pagesPrinted++;
        std::cout << "Imprimindo página na impressora " << id << '\n';
    }
};

class Scanner : public Device
{
public:
    Scanner(std::string id) : Device(DeviceType::Scanner, id)
    {
        data.scansCompleted = 0;
    }

    void printStatus() const override
    {
        std::cout << "Scanner (" << id << ") - Digitalizações completas: "
                  << data.scansCompleted << '\n';
    }

    void useDevice() override
    {
        data.scansCompleted++;
        std::cout << "Digitalizando documento no scanner " << id << '\n';
    }
};

class Node
{
public:
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev; // Referência fraca para evitar ciclo de referência

    Node() { std::cout << "Node criado" << '\n'; }
    ~Node() { std::cout << "Node destruído" << '\n'; }
};

int main(int argc, char **argv)
{
    std::weak_ptr<int> weakPtr; // weak_ptr não pode ser inicializado com nullptr
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(10); // shared_ptr inicializado com 10

    weakPtr = sharedPtr; // weak_ptr agora aponta para o mesmo objeto que shared_ptr
    std::cout << "Valor do shared_ptr: " << *sharedPtr << '\n';

    std::cout << "--------------------------------" << '\n';

    // Criando dispositivos com shared_ptr
    auto printer1 = std::make_shared<Printer>("HP-001");
    auto scanner1 = std::make_shared<Scanner>("Epson-001");

    // Criando observador
    DeviceObserver observer;

    // Adicionando dispositivos para observação
    observer.observe(printer1);
    observer.observe(scanner1);

    // Usando os dispositivos
    printer1->useDevice();
    printer1->useDevice();
    scanner1->useDevice();

    // Verificando status
    observer.checkDevices();

    // Liberando um dispositivo
    std::cout << "\nLiberando a impressora...\n";
    printer1.reset();

    // Verificando status novamente
    observer.checkDevices();

    std::cout << "--------------------------------" << '\n';

    auto node1 = std::make_shared<Node>();
    auto node2 = std::make_shared<Node>();

    node1->next = node2;
    node2->prev = node1; // Aqui, o `weak_ptr` evita ciclo de referência

    // Podemos acessar o `prev` de node2 sem manter a contagem de referência.
    if (auto prevNode = node2->prev.lock())
    { // lock() cria um `shared_ptr` temporário
        std::cout << "prevNode ainda está vivo" << '\n';
    }

    // Quando as referências `shared_ptr` saem de escopo, a memória é desalocada corretamente.

    return 0;
}
