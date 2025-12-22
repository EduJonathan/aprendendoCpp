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

---

### Quando Utilizar

1. **Propriedade única**: Use quando o recurso deve ter **um único** proprietário, evitando
   problemas de memória por referências múltiplas.
2. **Gerenciamento eficiente de memória**: Ideal para casos onde você quer que o objeto seja
   destruído automaticamente quando não houver mais referências a ele.
3. **Transferência de posse**: Quando você precisa transferir a posse de um objeto sem
   copiá-lo, utilizando as "move semantics" de C++.

---

### ANALOGIA

A ideia de propriedade exclusiva é a chave. Imagine que você tem um cofre (que representa
o recurso alocado dinamicamente, como um bloco de memória ou um arquivo aberto) **LOGO**.

1. **Propriedade Exclusiva**: A std::unique_ptr é como a única chave para esse cofre.
2. **Não Pode Ser Copiada**: Você não pode simplesmente fazer uma cópia da chave (o que
   permitiria a duas pessoas diferentes tentarem esvaziar/destruir o cofre, levando a um desastre).
3. **Pode Ser Movida**: Você pode entregar a chave para outra pessoa (usando `std::move`).
   Quando você move a chave, a pessoa original não tem mais acesso ao cofre, e o novo
   proprietário é o único responsável.
4. **Liberação Garantida**: Quando o proprietário da chave (a `std::unique_ptr`) a coloca
   no bolso e sai do recinto (o ponteiro inteligente sai do escopo), a chave é automaticamente
   usada para destruir o cofre de forma segura, garantindo que não fique nenhum cofre abandonado
   (vazamento de memória).

---

**Exemplo Programático**: Gerenciamento de Recursos
Na programação, o `std::unique_ptr` é mais usado para garantir a liberação automática de recursos.

- Manipuladores de Arquivos `(Non-Memory Resources)`

> Embora o principal uso seja para memória, o unique_ptr pode gerenciar qualquer recurso
> que precise ser `limpo` (o que chamamos de Deleter personalizado).  
> **Recurso**: Um arquivo aberto (retornado por `fopen` em C).  
> **Ação de Limpeza**: Chamar `fclose` no arquivo.  
> Usando `std::unique_ptr` com um deleter personalizado, você garante que, assim que  
> a variável do ponteiro sair do escopo (seja por um retorno normal de função ou uma exceção),  
> a função `fclose` será chamada, evitando vazamentos de handles de arquivos.

---

- Memória Alocada Dinamicamente em um Container

> Este é um dos casos de uso mais comuns. Você tem uma coleção de objetos polimórficos,  
> mas cada objeto na coleção é distinto e possui sua própria vida útil:  
> **Cenário**: Um motor de jogo que gerencia uma coleção de entidade  
> (inimigos, itens, obstáculos). Cada entidade é única e deve ser destruída apenas uma vez.  
> **Implementação**: Um std::vector de std::unique_ptr.

---

## ✅ `std::shared_ptr<T>`

O `std::shared_ptr` permite a **propriedade compartilhada** de um recurso. Ele mantém uma
**contagem de referências** interna que rastreia quantos ponteiros compartilham o mesmo recurso.
O recurso é destruído automaticamente quando a última referência é destruída.

### Características do `shared_ptr`

1. **Propriedade compartilhada**: Permite que múltiplos `shared_ptr` compartilhem o mesmo recurso.
2. **Gerenciamento automático de memória**: A memória é gerenciada automaticamente por meio de contagem de referência.
3. **Destruição automática**: O recurso é liberado quando o último `shared_ptr` é destruído ou redefinido.

---

### USO

1. **Propriedade compartilhada**: Use quando múltiplos objetos precisarem compartilhar
   a responsabilidade pela memória de um recurso.
2. **Gerenciamento de recursos complexos**: Ideal para gerenciar recursos como arquivos
   ou conexões de rede, onde o ciclo de vida precisa ser automaticamente controlado.
3. **Garantir a liberação da memória**: Útil quando se quer garantir que a memória será
   liberada assim que não houver mais referências ativas ao recurso.

---

### ANALOGIA COM MUNDO REAL

Imagine um serviço de streaming de música ou um assinatura de revista.

1. **Recurso**: O serviço de streaming em si (o objeto na memória).
   `std::shared_ptr`: Cada usuário pagante ou dispositivo que está acessando o serviço.
2. **Shared Ownership (Propriedade Compartilhada)**: Você pode "copiar" o acesso
   (dar a senha ao seu cônjuge/colega).
3. **Referência**: Enquanto houver pelo menos um usuário ativo (um `shared_ptr` apontando
   para o recurso), o serviço deve permanecer ativo. O contador de referências rastreia
   quantos usuários estão ativos.
4. **Liberação**: Se todos os usuários cancelarem ou pararem de usar (todos os
   `shared_ptr` forem destruídos), o contador chega a zero, e somente nesse momento o
   serviço é desativado (o recurso é destruído).

---

**Exemplo Programático**: Um cache de dados onde múltiplas partes do programa precisam
de acesso ao mesmo objeto em tempo de execução. O objeto só deve ser removido do cache
quando nenhuma parte do código o estiver usando ativamente.

---

## ✅ `std::weak_ptr<T>`

O `std::weak_ptr` é uma **referência fraca** a um recurso gerenciado por um `shared_ptr`,
que **não participa da contagem de referências**. Ele é ideal para evitar
**referências circulares** que podem causar vazamentos de memória.

### Características do `weak_ptr`

1. **Não impede a destruição do recurso**: Não afeta a contagem de referência.
2. **Conversão em `shared_ptr`**: Pode ser convertido em um `shared_ptr` para acessar o recurso, se ele ainda existir.
3. **Prevenção de ciclos de referência**: Ideal para situações em que ciclos de referência
   podem surgir, como em grafos, árvores ou callbacks.

---

### QUANDO USAR

1. **Evitar ciclos de referência**: Para quebrar ciclos entre objetos com `shared_ptr`, usando `weak_ptr` em um dos objetos.
2. **Cache de objetos**: Para manter uma referência opcional a objetos, permitindo que sejam destruídos quando não necessários.
3. **Estruturas de dados complexas**: Em grafos ou árvores para evitar ciclos que impedem a liberação de memória.
4. **Callbacks e observadores**: Permite acessar objetos sem impedir sua destruição, evitando erros se o objeto for desalocado.

---

### SITUAÇÃO ANALÓGICA

Imagine que o recurso é um evento importante (o objeto na memória).

- `std::shared_ptr`: São os organizadores do evento (eles mantêm o evento vivo).
- `std::weak_ptr`: É um convite temporário ou um cartão de visita para o evento.

1. **Não-Proprietário**: Se você rasgar seu convite (weak_ptr é destruído), o evento principal não é cancelado.
2. **Monitoramento**: Antes de ir ao evento, você precisa verificar se ele ainda está
   acontecendo (chamar o método `.lock()` do `weak_ptr` para obter um `shared_ptr` temporário).
3. **Risco**: Se o evento tiver sido cancelado pelos organizadores (`shared_ptrs` destruídos),
   seu convite é inútil, e você evita ir a um local vazio (evitando o acesso a uma memória já liberada).

---

**Exemplo Programático (O Caso de Uso Principal)**: Referências Circulares

O `weak_ptr` é crucial para resolver o problema de referências circulares entre objetos gerenciados por shared_ptr.

Imagine 2 classes `Pai` e `Filho`

- Uma chamada `Pai` tem um `shared_ptr` para Filho.
- E uma chamada `Filho` tem um shared_ptr para `Pai`.

**Ao sair do escopo**:

- O `Pai` não pode ser destruído porque o `Filho` ainda tem um shared_ptr para ele.
- O `Filho` não pode ser destruído porque o `Pai` ainda tem um shared_ptr para ele.

**Resultado**: Ambos têm um contador de referências preso em 1, e a memória vaza!
**Solução**: Mude uma das referências para weak_ptr.

> `Pai` tem um `shared_ptr<Filho>`. `Filho` tem um `weak_ptr<Pai>`.  
> Agora, o `Filho` pode `olhar` para o `Pai` sem impedir que ele seja destruído.  
> Se o `Filho` precisar acessar o `Pai`, ele usa `pai_ptr.lock()` para verificar  
> se o `Pai` ainda está vivo e obter um acesso seguro (temporário `shared_ptr`).

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
