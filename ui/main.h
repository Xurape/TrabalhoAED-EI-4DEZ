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

// Placas de rede
void placasderedeInserir();
void placasderedeMostrar();
void placasderedeAlterar();
void placasderedeEliminar();