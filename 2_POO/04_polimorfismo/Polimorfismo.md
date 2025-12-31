<!-- @format -->

# Polimorfismo

## Classes Abstratas

Antes de entendermos o conceito de **polimorfismo**, é importante compreender o que são **classes abstratas**.

Segundo diversas fontes da literatura e da documentação oficial:

- [Stack Overflow – O que é uma classe abstrata?](https://pt.stackoverflow.com/questions/87423)
- [Microsoft Learn – Abstract Classes em C++](https://learn.microsoft.com/pt-br/cpp/cpp/abstract-classes-cpp)
- [IBM Docs – Abstract Classes](https://www.ibm.com/docs/pt-br/i/7.5.0?topic=only-abstract-classes-c)
- [DevMedia – Conceitos de Classes Abstratas](https://www.devmedia.com.br/conceitos-classes-abstratas-programacao-orientada-a-objetos/18812)

---

### O que é uma classe abstrata?

Uma **classe abstrata** é uma classe que **não pode ser instanciada diretamente**.
Ela serve como um **modelo base** para outras classes, permitindo o compartilhamento de
atributos e comportamentos comuns através da herança.

> Classes abstratas podem conter métodos abstratos, que definem o que `deve ser feito`, mas `não como`,
> obrigando as classes filhas a fornecerem a implementação.

---

### Métodos abstratos

- Métodos abstratos **não possuem corpo**
- Apenas a **assinatura** do método é declarada
- Toda classe que herdar de uma classe abstrata **é obrigada a implementar esses métodos**

#### Exemplos por linguagem

- **Java:** métodos marcados com a palavra-chave `abstract`

```Java
public abstract class ContaAbstrata {
    private String numero;
    protected double saldo;

    public ContaAbstrata(String numero) {
        this.numero = numero;
        this.saldo = 0.0;
    }

    // método abstrato
    public abstract void atualizarMensal();

    // método concreto
    public void creditar(double valor) {
        this.saldo += valor;
    }

    public double getSaldo() {
        return this.saldo;
    }
}
```

---

- **C++:** métodos virtuais puros, declarados com `= 0`

```cpp
class ContaAbstrata {
protected:
    std::string numero;
    double saldo;

public:
    // construtor
    ContaAbstrata(const std::string& numero) : numero(numero), saldo(0.0) {}

    // método abstrato (virtual puro)
    virtual void atualizarMensal() = 0;

    // método concreto
    void creditar(double valor) {
        saldo += valor;
    }

    double getSaldo() const {
        return saldo;
    }

    // destrutor virtual (boa prática), para evitar vazamento de memória ao deletar via ponteiro da base.
    virtual ~ContaAbstrata() {}
};
```

---

Métodos que **não são abstratos** devem possuir corpo e:

- Podem ou não ser sobrescritos pelas classes filhas
- Servem como implementação padrão

---

### Relação com Polimorfismo

Classes abstratas são fundamentais para o polimorfismo, pois permitem que objetos de diferentes classes filhas
sejam tratados de forma uniforme através de uma classe base comum.

---

## Entendendo Polimorfismo

Polimorfismo (poli significa muitos e morfismo significa formas) é a capacidade de um mesmo tipo abstrato
representar diferentes comportamentos, de acordo com a implementação concreta associada a ele.
Em outras palavras, o polimorfismo permite que objetos de classes diferentes sejam tratados de forma uniforme
por meio de uma classe base ou interface comum.

Um exemplo clássico é uma classe abstrata chamada `Animal`. Todos os animais compartilham características e comportamentos básicos,
mas cada tipo de animal se comporta de maneira diferente.

Por exemplo:

- Um animal pode **voar nos céus** (aves)
- Outro pode **viver na terra** (mamíferos, répteis)
- Outro pode **viver na água** (peixes)
- Podem emitir **sons**

Em resumo, o polimorfismo permite escrever código mais flexível, extensível e desacoplado, pois o comportamento real do objeto
é determinado em tempo de execução.

---

## Interfaces

Este tópico é apresentado por curiosidade, pois diferentemente de **Java** e **C#**,
o **C++ não possui uma palavra-chave específica para a definição de interfaces**.

Em C++, o conceito de interface é implementado por meio de **classes abstratas** que
contêm **apenas métodos virtuais puros**, sem atributos ou implementações concretas.

Ou seja, uma interface em C++ é, na prática:

- Uma classe que **não pode ser instanciada**
- Possui **somente métodos virtuais puros (`= 0`)**
- Não mantém **estado interno**
- Define apenas **contratos de comportamento**

Esse padrão permite obter os mesmos benefícios das interfaces em Java e C#,
como desacoplamento, polimorfismo e maior flexibilidade no design do sistema.
