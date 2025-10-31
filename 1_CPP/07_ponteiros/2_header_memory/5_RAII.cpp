#include <iostream>
#include <memory>

/**
 * RAII (Resource Acquisition Is Initialization) é um paradigma fundamental em C++
 * que significa: "Aquisição de Recurso é Inicialização".
 * RAII É a ideia de que a aquisição de um recurso deve acontecer durante a construção
 * de um objeto e a liberação deve acontecer durante a destruição.
 *
 * Como funciona:
 * 1. Recurso é adquirido no construtor
 * 2. Recurso é liberado no destrutor
 * 3. Garantia de liberação quando o objeto sai de escopo
 *
 * -----------------------------------
 *
 * Vantagens do RAII:
 *
 * Prevenção de vazamentos de recursos
 * Segurança contra exceções
 * Código mais limpo e maintainable
 * Determinismo (sabe exatamente quando recursos são liberados)
 *
 * TESE: RAII é a base filosófica por trás dos smart pointers e de todo gerenciamento moderno de recursos em C++.
 * É o que permite escrever código exception-safe e livre de vazamentos de forma elegante.
 * É por causa do RAII que podemos dizer: "em C++, não usamos delete manualmente" na maioria dos casos!
 */