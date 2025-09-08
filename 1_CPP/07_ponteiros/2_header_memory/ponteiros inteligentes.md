# 🔹 Smart Pointers (Ponteiros Inteligentes) em C++

Na linguagem C++, os **smart pointers** (ponteiros inteligentes) são classes template
que gerenciam automaticamente a alocação e liberação de memória.
Eles ajudam a evitar Erros comuns como _memory leaks_, uso de ponteiros inválidos e
liberações duplicadas de Memória, proporcionando um controle mais seguro e eficiente
de recursos, sendo eles:

---

## ✅ `std::unique_ptr<T>`

O `std::unique_ptr` representa **propriedade exclusiva** sobre um recurso. Ele
**não pode ser copiado**, mas pode ser movido, garantindo que apenas uma instância
seja responsável pela liberação do recurso.

### Características do `unique_ptr`

1. **Propriedade exclusiva**: Apenas um ponteiro pode ser o dono do recurso por vez.
2. **Destruição automática**: Elimina o objeto gerenciado automaticamente quando sai de escopo.
3. **Ideal para objetos com um único dono**: Perfeito para garantir que um recurso tenha um único proprietário.
4. **Movimentação (move semantics)**: Usa movimentação em vez de cópia, transferindo a posse do recurso.

### Quando Utilizar

1. **Propriedade única**: Use quando o recurso deve ter **um único** proprietário, evitando
   problemas de memória por referências múltiplas.
2. **Gerenciamento eficiente de memória**: Ideal para casos onde você quer que o objeto seja
   destruído automaticamente quando não houver mais referências a ele.
3. **Transferência de posse**: Quando você precisa transferir a posse de um objeto sem
   copiá-lo, utilizando as "move semantics" de C++.

---

## ✅ `std::shared_ptr<T>`

O `std::shared_ptr` permite a **propriedade compartilhada** de um recurso. Ele mantém uma
**contagem de referências** interna que rastreia quantos ponteiros compartilham o mesmo recurso.
O recurso é destruído automaticamente quando a última referência é destruída.

### Características do `shared_ptr`

1. **Propriedade compartilhada**: Permite que múltiplos `shared_ptr` compartilhem o mesmo recurso.
2. **Gerenciamento automático de memória**: A memória é gerenciada automaticamente por meio de
   contagem de referência.
3. **Destruição automática**: O recurso é liberado quando o último `shared_ptr` é destruído ou redefinido.

### USO

1. **Propriedade compartilhada**: Use quando múltiplos objetos precisarem compartilhar
   a responsabilidade pela memória de um recurso.
2. **Gerenciamento de recursos complexos**: Ideal para gerenciar recursos como arquivos
   ou conexões de rede, onde o ciclo de vida precisa ser automaticamente controlado.
3. **Garantir a liberação da memória**: Útil quando se quer garantir que a memória será
   liberada assim que não houver mais referências ativas ao recurso.

---

## ✅ `std::weak_ptr<T>`

O `std::weak_ptr` é uma **referência fraca** a um recurso gerenciado por um `shared_ptr`,
que **não participa da contagem de referências**. Ele é ideal para evitar
**referências circulares** que podem causar vazamentos de memória.

### Características do `weak_ptr`

1. **Não impede a destruição do recurso**: Não afeta a contagem de referência.
2. **Conversão em `shared_ptr`**: Pode ser convertido em um `shared_ptr` para acessar o recurso,
   se ele ainda existir.
3. **Prevenção de ciclos de referência**: Ideal para situações em que ciclos de referência
   podem surgir, como em grafos, árvores ou callbacks.

### QUANDO USAR

1. **Evitar ciclos de referência**: Para quebrar ciclos entre objetos com `shared_ptr`,
   usando `weak_ptr` em um dos objetos.
2. **Cache de objetos**: Para manter uma referência opcional a objetos, permitindo que
   sejam destruídos quando não necessários.
3. **Estruturas de dados complexas**: Em grafos ou árvores para evitar ciclos que impedem a
   liberação de memória.
4. **Callbacks e observadores**: Permite acessar objetos sem impedir sua destruição,
   evitando erros se o objeto for desalocado.

---

## ⚠️ `std::auto_ptr<T>` (Obsoleto)

O `auto_ptr` foi um precursor dos smart pointers modernos. No entanto, seu comportamento de
**transferência de propriedade por cópia** causava efeitos colaterais indesejáveis, sendo
considerado **inseguro**.

### Características do `auto_ptr`

1. **Removido no C++17**.
2. Substituído por `unique_ptr` com semântica de movimentação segura.

---

## ℹ️ Observação: `<T>` nos Smart Pointers

O `<T>` indica o tipo de conteúdo que vai ser inserido para gerenciar os recursos em
tempo de compilação, algo que será muito comum e utilizado em programação genérica
e metaprogramação (Templates).
Os tipos por se tratar de maneira genérica, podem ser quaisquer tipos de dados, como:

- `Datatypes` (int, float, etc...),
- `structs`,
- `unions`,
- `Containers` (vector, array, std::string, etc...),
- `class`.

Esses smart pointers são templates que podem trabalhar com **qualquer tipo de dado**,
permitindo criar código reutilizável e flexível, onde o tipo a ser manipulado é determinado
durante a instânciação do smart pointer, sem a necessidade de duplicar o código para cada
tipo de dado diferente.

---

## ℹ️ Observação — RAII (Resource Acquisition Is Initialization)

Os smart pointers seguem o princípio de **RAII** (Aquisição de Recursos é Inicialização).
Isso significa que os recursos são adquiridos no momento da criação do objeto (inicialização)
e liberados automaticamente quando o objeto sai de escopo. Esse padrão garante **segurança**,
**simplicidade** e **previsibilidade** no gerenciamento de recursos como memória,
arquivos e conexões.

---

## ❓ O que é semântica no contexto de smart pointers?

Na programação, semântica se refere ao **comportamento** ou **significado** de uma construção
ou expressão. Quando dizemos que um `unique_ptr` tem semântica de movimentação, estamos dizendo
que ele se comporta de uma maneira específica ao ser **passado ou atribuído** — ou seja, ele
**transfere a posse do recurso**, ao invés de copiá-lo.
