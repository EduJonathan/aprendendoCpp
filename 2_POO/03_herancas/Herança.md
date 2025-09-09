# HERANÇA EM C++

## HERANÇA, CLASSE BASE E CLASSE DERIVADA

- **Herança(Inheritance):** É um dos pilares da POO trata-se da possibilidade de uma
  classe nova(Derivada) herde(compartilhe) propriedades e comportamentos pertencente
  a outras classes a uma classe já existente(classe Base).

  Isso ajuda a evitar a duplicação de código e facilita a manutenção do sistema,
  além de permitir a criação de hierarquias de classes. Usa-se este mecanismo de
  herança quando houver uma relação de pertencimento; quando a classe derivada é
  uma entidade da mesma categoria que a classe de base.

- **Classe Base:** A classe que fornece atributos e métodos para ser reutilizado.
  Ela é conhecida como classe "mãe" de outras classes.

- **Classe Derivada:** A classe que herda os atributos e métodos da classe base.
  E esta é conhecida como a classe "filha".

---

## TIPOS DE HERANÇA EM C++

- **Herança Simples:**  
  Herança simples é quando só uma classe(derivada) herda uma classe (base).

- **Herança Múltipla:**
  Herança Múltipla é quando uma classe pode herdar de mais de uma classe, ou seja,
  uma subclasse é herdada de mais de uma classe base.

- **Herança Multinível:**  
  Herança multinível uma classe derivada é criada a partir de outra classe derivada e
  essa classe derivada pode ser derivada de uma classe base ou de qualquer outra classe
  derivada. Pode haver qualquer número de níveis. Exemplo, um veículo pode ser um
  veículo de quatro rodas e um veículo de quatro rodas pode ser um carro.

- **Herança Hierárquica:**
  Herança hierárquica, é quando mais de uma subclasse é herdada de uma única classe base,
  ou seja, mais de uma classe derivada é criada a partir de uma única classe base.
  Por exemplo, carros e ônibus são veículos.

- **Herança Híbrida:**
  Herança híbrida é implementada combinando mais de um tipo de herança.
  Por exemplo: A combinação de herança hierárquica e herança múltipla criará
  herança híbrida em C++. Não há sintaxe específica de herança híbrida.
  Podemos apenas combinar dois dos tipos de herança acima

- **Herança Virtual:**  
  Em C++, uma classe pode herdar de várias classes, o que é comumente chamado
  de herança múltipla, isso pode causar problemas às vezes, pois você pode ter
  várias instâncias da classe base. E Para resolver esse problema, no C++ usa
  uma técnica que garante que apenas uma instância de uma classe base esteja presente.
  Técnica essa chamada de herança virtual.

---

## Diferenças Entres Heranças

| Tipo de Herança | Característica Principal                                                      |
| --------------- | ----------------------------------------------------------------------------- |
| **Simples**     | Uma única classe derivada herda de uma única classe base.                     |
| **Múltipla**    | Uma classe derivada herda de duas ou mais classes base.                       |
| **Multinível**  | Uma classe é derivada de uma classe que já é derivada de outra.               |
| **Hierárquica** | Múltiplas classes derivadas herdam de uma única classe base.                  |
| **Híbrida**     | Combinação de dois ou mais tipos de herança (ex: múltipla + hierárquica).     |
| **Virtual**     | Utilizada para evitar ambiguidade na herança múltipla (Problema do Diamante). |

**CURIOSIDADE: Problema de Diamante 💎**:

- O problema do diamante ocorre em herança múltipla quando duas classes derivadas
  herdam da mesma classe base, e uma terceira classe herda dessas duas classes derivadas.
  Isso pode causar ambiguidade na hora de acessar membros da classe base, pois há
  duas "cópias" herdadas da mesma classe.

- E com a herança virtual isso garante que exista apenas uma única instância da classe
  base `A` na hierarquia de herança, mesmo que ela seja herdada múltiplas vezes. Isso
  evita duplicação e ambiguidade.

---

## Herança Vs Composição

Em certos momentos, tenha preferência sobre composição sobre herança quando possível,
pois reduz o acoplamento e aumenta a flexibilidade do código.

| Critério          | Herança                           | Composição                |
| ----------------- | --------------------------------- | ------------------------- |
| **Relação**       | "é um" (is-a)                     | "tem um" (has-a)          |
| **Acoplamento**   | Forte                             | Fraco                     |
| **Reutilização**  | Código da classe base             | Reutiliza funcionalidades |
| **Flexibilidade** | Menos flexível (hierarquias fixa) | Mais flexível             |
| **Polimorfismo**  | Suporta                           | Não suporta diretamente   |

---

## Herança Vs Friend

Friend: O metódo ou classe `friend` pode acessar todos os membros, inclusive os private,
da classe onde foi declarada como amiga. O friend não herda nada. Ele só recebe permissão
de acesso especial. Pode ser uma função ou outra classe.
