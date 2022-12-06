<p align="center">
    <img src="IPVC.png">
</p>

# Informações
Projeto em **C** para gestão de equipamentos numa rede informática com diversas funcionalidades e opções de filtração para uma melhor gestão.

# Funções
```c
// Time
int sleep(int);
int usleep(long);

// UI
void mainUI();

// Menus
void menuEquipamentos();
void menuAplicacoes();
void menuPlacasRede();

// Funções
void configuracaoInicial();
void limparJanela();
void quebrarLinhas(int);
void enviarTitulo(char*, bool );
void abrirMenu(int);
void finalizarMenu();
void gerarTabela();

// Equipamentos
void equipamentosInserir();
void equipamentosAlterar();
void equipamentosEliminar();
void equipamentosMostrar();
void equipamentosFiltrar();

// Aplicações
void aplicacoesInserir();
void aplicacoesMostrar();
void aplicacoesAlterar();
void apliacoesEliminar();

// Placas de rede
void placasderedeInserir();
void placasderedeMostrar();
void placasderedeAlterar();
void placasderedeEliminar();
```