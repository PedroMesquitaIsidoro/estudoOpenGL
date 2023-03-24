#include <stdlib.h>
#include <GL/glut.h>
#include <cstdio>


// ###############  

// pra compilar: g++ -o exemploGLUT exemploGLUT.cpp -lGL -lGLU -lglut

// ############### 

void Desenha(void){
    printf("*** Callback de redesenho de tela\n");

    //Define a cor de fundo de tela como azul
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    //Limpa a janela de visualizacao com a cor de fundo
    glClear(GL_COLOR_BUFFER_BIT);

    //Exibe o desenho na janela
    glutSwapBuffers();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){
    printf("*** Callback de redimensionamento da tela\n");
    printf(">>> Novo tamanho da janela: %d x %d \n\n", w, h);
}

void Teclado(unsigned char tecla, int x, int y){
    int modificadores;
    printf("*** Tratamento de teclas comuns\n");
    printf(">>> Tecla: %c\n", tecla);

    if(tecla == 27){
        exit(0);
    }

    if(tecla == 'a') //muda para tela cheia
        glutFullScreen();
    
    if(tecla == 'A'){
        glutReshapeWindow(500, 400);
        glutPositionWindow(100, 100);
    }

    int glutGetModifiers(void);

    // trata    SHIFT, CTRL, ALT
    modificadores = glutGetModifiers();

    if(modificadores & GLUT_ACTIVE_SHIFT){
        printf("(SHIFT PRESSIONADO)\n");
    }

    if(modificadores & GLUT_ACTIVE_CTRL){
        printf("(ctrl PRESSIONADO)\n");
    }

    if(modificadores & GLUT_ACTIVE_ALT){
        printf("(ALT PRESSIONADO)\n");
    }
}

void TeclasEspeciais(int tecla, int x, int y){
    printf("*** Tratamento de teclas especiais\n");

    switch(tecla){
        case GLUT_KEY_F1: printf(">>> Tecla F1 pressionada\n");
            break;
        case GLUT_KEY_F2: printf(">>> Tecla F2 pressionada\n");
            break;
        case GLUT_KEY_F3: printf(">>> Tecla F3 pressionada\n");
            break;
    }
}

void GerenciaMouse(int button, int state, int x, int y){
    printf("*** Tratamento de Cliques de mouse\n");
    if(state == GLUT_DOWN){
        printf(">>> Botao %d pressionado\n", button);
    }
    if(state == GLUT_UP){
        printf(">>> Botao %d liberado\n", button);
    }
}

void MenuCor(int op){
    printf("*** Menu COR: ");
    switch(op){
        case 0:
            printf("Opcao VERMELHO");
            break;
        case 1:
            printf("Opcao VERDE");
            break;
        case 2:
            printf("Opcao AZUL");
            break;
    }
    printf("\n");
    glutPostRedisplay();
}

void CriaMenu(){
    int menu, submenu1, submenu2;

    //Cria submenu para selecao de cor
    submenu1 = glutCreateMenu(MenuCor);
    glutAddMenuEntry("Vermelho", 0);
    glutAddMenuEntry("Verde", 1);
    glutAddMenuEntry("Azul", 2);

   

    

    //Associa o menu ao botao direito do mouse
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}

int main(int argc, char **argv){

    //inicializa GLUT
    glutInit(&argc, argv);

    //Definir o mode de operacao da GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Define a posicao inicial da janela GLUT
    glutInitWindowPosition(0, 0);

    //Define o tamanho inical em pixels: largura x altura da janela GLUT
    glutInitWindowSize(500, 400);

    // Cria a janela e define um nome da mesma
    glutCreateWindow("Programa de teste da GLUT");

    // REgistra a funcao callback de redesenho da janela de visualizacao
    glutDisplayFunc(Desenha);
    
    //Registra a funcao callback de redimenseionamento da janela de visualizacao
    glutReshapeFunc(AlteraTamanhoJanela);
    
    //Registra a funcao callback para tratamento das teclas asciiii
    glutKeyboardFunc(Teclado);
    
    //Registra a funcao callback que gerencia os eventos do mouse
    glutMouseFunc(GerenciaMouse);

    // REGISTRA A FUNCAO CALLBACK PARA TRATAMENTO DAS TECLAS ESPECIAIS
    glutSpecialFunc(TeclasEspeciais);
    
    //chama a funcao para criar o menu
    CriaMenu();

    //Inicia o processamento e aguarda interacoes do usuario
    glutMainLoop();

    return 0;

}
