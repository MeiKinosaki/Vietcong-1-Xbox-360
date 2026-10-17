# Vietcong 1 — Xbox 360 Port

Projeto comunitário para investigar e desenvolver um port nativo de **Vietcong (PC, 2003)** para Xbox 360.

> **Estado atual:** fase de planejamento e estruturação. Este repositório ainda não contém um port jogável nem um `default.xex` validado. Nenhuma porcentagem de compatibilidade ou desempenho é declarada sem testes reproduzíveis.

## Objetivo

Construir gradualmente uma base para Xbox 360 (PowerPC Xenon), separando a camada de plataforma dos sistemas do jogo e registrando o que foi implementado, compilado e testado.

## Versão

**v0.1b — estrutura inicial / planejamento**

A versão só deve avançar quando houver uma alteração concreta no repositório e evidência correspondente. Não pular versões.

## Plano de desenvolvimento

1. **Auditoria de origem e licenças**
   - Identificar quais fontes, documentação e formatos podem ser usados legalmente.
   - Não incluir executáveis comerciais, dados proprietários do jogo ou SDKs redistribuídos sem autorização.
2. **Toolchain e build reproduzível**
   - Definir o ambiente Xenon/libXenon e registrar as dependências disponíveis.
   - Preparar CI para validar os componentes portáveis; não afirmar que gera XEX até que o toolchain apropriado esteja realmente configurado.
3. **Camada de plataforma**
   - Inicialização, ciclo principal, logs, temporização e tratamento de erros.
4. **Entrada e apresentação**
   - Mapeamento do controle Xbox 360 e uma camada de vídeo com limites bem documentados.
5. **Sistemas do jogo**
   - Investigar separadamente recursos, mapas, áudio, scripts, física e lógica.
   - Criar adaptadores apenas quando houver interfaces e formatos compreendidos.
6. **Executável**
   - Alvo final: `default.xex`, após compilação real e testes em hardware compatível ou ambiente de teste adequado.
7. **Validação**
   - Registrar logs de build, testes unitários, testes de inicialização, problemas conhecidos e resultados por versão.

## Critérios para declarar progresso

- **Planejado:** tarefa documentada, ainda sem implementação.
- **Implementado:** código presente no repositório.
- **Compilado:** build executado com sucesso, com log ou artefato verificável.
- **Testado:** teste executado e resultado registrado.
- **Validado no Xbox 360:** teste realizado no hardware-alvo e evidência documentada.

## Estrutura prevista

```text
Vietcong-1-Xbox-360/
├── README.md
├── docs/
│   ├── ARCHITECTURE.md
│   ├── BUILD.md
│   └── STATUS.md
├── src/
│   ├── platform/
│   └── core/
└── tests/
```

A estrutura acima é uma proposta de organização; diretórios só serão considerados implementados quando forem adicionados ao repositório.

## Limitações e riscos

- Um jogo de PC não se torna um port nativo apenas por recompilar alguns arquivos: APIs gráficas, áudio, sistema de arquivos, entrada, threading e dependências do motor precisam de adaptação.
- A disponibilidade do código-fonte e dos direitos de redistribuição do motor original precisa ser verificada.
- A compilação de um executável não comprova que o jogo inicia ou é jogável.
- Não distribuir arquivos comerciais do jogo. Use somente arquivos e ferramentas que você tenha direito de utilizar.

## Como contribuir

Abra uma issue com o sistema a investigar, evidências, arquivos envolvidos e um critério de teste reproduzível. Mudanças de versão devem ser pequenas e sequenciais.

## Registro de versão

### v0.1b
- Criado o README inicial com objetivo, limites, etapas e critérios verificáveis.
- Código do port, build Xenon e `default.xex`: **ainda não implementados/validados**.
