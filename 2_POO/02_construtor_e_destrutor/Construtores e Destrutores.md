<!-- @format -->

# Construtores e Destrutores

Construtores (do inglês _constructors_) são métodos especiais responsáveis por **inicializar objetos**,
garantindo que uma instância da classe seja criada em um estado válido e consistente.

Diferentemente de métodos `setter` comuns, os construtores:

- São executados **automaticamente** no momento da criação do objeto.
- Permitem inicialização **obrigatória** de atributos.
- Impedem que o objeto exista em um estado inválido.
- Tornam o código mais seguro, claro e expressivo.

---

Já os Destrutores (do inglês _destructors_) são métodos especiais executados **automaticamente** quando
o objeto sai de escopo ou é explicitamente deletado. Em C++, o destrutor é declarado com o nome da classe
**prefixado por `~`** e não possui parâmetros nem valor de retorno.

Eles são responsáveis por:

- Liberar recursos adquiridos (memória dinâmica, arquivos abertos, conexões de rede, etc.).
- Executar limpeza necessária ao finalizar o objeto.

> Em **C++**, destrutores são especialmente importantes porque a linguagem não possui garbage collector — o programador é responsável pelo gerenciamento de recursos (princípio RAII).

---

> Exemplo de construtor

```cpp
class Arquivo {
private:
    std::ofstream arquivo;

public:
    // Construtor: abre o arquivo
    Arquivo(const std::string& nome) {
        arquivo.open(nome);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo!\n";
        } else {
            std::cout << "Arquivo aberto com sucesso.\n";
        }
    }

    // Destrutor: fecha o arquivo automaticamente
    ~Arquivo() {
        if (arquivo.is_open()) {
            arquivo.close();
            std::cout << "Arquivo fechado automaticamente.\n";
        }
    }

    void escrever(const std::string& texto) {
        if (arquivo.is_open()) {
            arquivo << texto << '\n';
        }
    }
};
```

---

> Exemplo de construtor inicializando instâncias

```cpp
class Pessoa {
private:
    std::string nome;
    int idade;

public:
    // Construtor com parâmetros
    Pessoa(const std::string nome, int age)
    {
        // Use this-> quando houver conflito de nomes ou para clareza
        this->nome = nome;
        idade = age;
        std::cout << "Pessoa criada: " << nome << ", " << idade << " anos\n";
    }

    // Construtor com parâmetros + lista de inicialização (forma adotada mais recomendada)
    Pessoa(const std::string& n, int i) : nome(n), idade(i) {
        std::cout << "Pessoa criada: " << nome << ", " << idade << " anos\n";
    }

    // Destrutor
    ~Pessoa() {
        std::cout << "Pessoa destruída: " << nome << '\n';
    }

    void exibir() const {
        std::cout << "Nome: " << nome << ", Idade: " << idade << '\n';
    }
};
```

## Vantagens e Desvantagens de Construtores e Destrutores

✅ Vantagens

### Inicialização garantida

- Construtores asseguram que o objeto seja criado sempre em um estado válido, evitando erros causados por atributos não inicializados.

### Maior segurança

- Reduzem a necessidade de múltiplas chamadas a métodos setter, diminuindo o risco de uso incorreto do objeto.

### Código mais expressivo e legível

- A criação do objeto deixa claro quais dados são obrigatórios, tornando a intenção do código mais evidente.

### Gerenciamento seguro de recursos (RAII)

- Em C++, construtores e destrutores permitem o controle automático de recursos como memória, arquivos, sockets e texturas.

### Facilitam manutenção e evolução

- Centralizam a lógica de inicialização e finalização do objeto, tornando mudanças futuras mais simples e seguras.

---

⚠️ Desvantagens

### Construtores complexos

- Construtores com muitas responsabilidades podem se tornar longos, difíceis de manter e testar.

### Dificuldade de tratamento de erros

- Em C++, exceções lançadas em construtores exigem cuidado, pois o objeto ainda não foi totalmente criado.

### Dependências implícitas

- Se o construtor inicializa muitos recursos externos, a classe pode se tornar fortemente acoplada.

### Destrutores mal projetados

- Um destrutor que executa lógica complexa pode gerar comportamentos inesperados, especialmente em hierarquias com polimorfismo.

### Ordem de destruição

- Em C++, a ordem de destruição de membros e objetos pode causar erros se não for bem compreendida.
