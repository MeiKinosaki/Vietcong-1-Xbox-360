# Vietcong 1 — Xbox 360 Port

Projeto comunitário para investigar e desenvolver um port nativo de **Vietcong (PC, 2003)** para Xbox 360.

> **Estado atual:** base inicial de infraestrutura e código portátil. Ainda não há port jogável, integração com o motor original ou `default.xex` validado. Nenhuma porcentagem de compatibilidade ou desempenho é declarada sem testes reproduzíveis.

## Objetivo

Construir gradualmente uma base para Xbox 360 (PowerPC Xenon), separando a camada de plataforma dos sistemas do jogo e registrando o que foi implementado, compilado e testado.

## Versão

**v0.1b — fundação portátil**

A versão permanece v0.1b enquanto a primeira base não tiver execução de testes confirmada. Avançar sem pular versões.

## O que existe no repositório

- `src/core/port_state.h` e `src/core/port_state.c`: estado portátil mínimo de ciclo de vida, contador de frames, máscara de entrada e solicitação de parada.
- `tests/test_port_state.c`: testes unitários para essa interface.
- `Makefile`: alvo `make clean test` para compilação e testes no computador host.
- `.github/workflows/ci.yml`: workflow GitHub Actions para executar os testes do núcleo portátil.
- `docs/BUILD.md`: instruções de build e limite explícito entre testes host e build Xenon.
- `docs/STATUS.md`: inventário do que foi implementado e do que ainda falta.

**Importante:** os arquivos foram adicionados ao GitHub, mas a execução do CI ainda precisa ser verificada. O teste host não é um build de Xbox 360.

## Plano de desenvolvimento

1. **Auditoria de origem e licenças:** identificar fontes, documentação e formatos utilizáveis legalmente; não incluir dados proprietários ou SDKs redistribuídos sem autorização.
2. **Build reproduzível:** validar o núcleo portátil no CI e documentar separadamente a disponibilidade de uma toolchain Xenon real.
3. **Camada de plataforma:** inicialização, ciclo principal, logs, temporização e tratamento de erros.
4. **Entrada e apresentação:** mapear o controle Xbox 360 e implementar uma camada de vídeo apropriada.
5. **Sistemas do jogo:** investigar recursos, mapas, áudio, scripts, física e lógica com base em interfaces e formatos comprovados.
6. **Executável:** alvo final `default.xex`, somente após compilação real e testes em hardware compatível ou ambiente adequado.
7. **Validação:** guardar logs, resultados dos testes, limitações e problemas conhecidos por versão.

## Critérios para declarar progresso

- **Planejado:** tarefa documentada, sem implementação.
- **Implementado:** código presente no repositório.
- **Compilado:** build executado com sucesso e evidência verificável.
- **Testado:** teste executado e resultado registrado.
- **Validado no Xbox 360:** teste no hardware-alvo com evidência documentada.

## Estrutura atual

```text
Vietcong-1-Xbox-360/
├── .github/workflows/ci.yml
├── docs/
│   ├── BUILD.md
│   └── STATUS.md
├── src/core/
│   ├── port_state.c
│   └── port_state.h
├── tests/test_port_state.c
├── Makefile
└── README.md
```

## Limitações e riscos

- Um jogo de PC não se torna um port nativo apenas por recompilar alguns arquivos: APIs gráficas, áudio, arquivos, entrada, threading e dependências do motor precisam de adaptação.
- A disponibilidade do código-fonte e os direitos de uso do motor original ainda precisam ser verificados.
- Compilar um executável não comprova que o jogo inicia ou é jogável.
- Não distribuir arquivos comerciais do jogo. Use apenas arquivos e ferramentas que você tenha direito de utilizar.

## Como contribuir

Abra uma issue com o sistema a investigar, evidências, arquivos envolvidos e um critério de teste reproduzível. Mudanças de versão devem ser pequenas e sequenciais.

## Registro de versão

### v0.1b
- README atualizado com estado verificável e plano de desenvolvimento.
- Adicionada interface portátil mínima de estado do port.
- Adicionados testes unitários e alvo Makefile para o host.
- Adicionado workflow GitHub Actions para executar os testes.
- **Ainda não implementados:** motor do jogo, renderização, áudio, física, carregamento de mapas/recursos, entrada nativa Xbox 360, toolchain Xenon e `default.xex`.
- **CI:** configurado; resultado de execução ainda não confirmado.
