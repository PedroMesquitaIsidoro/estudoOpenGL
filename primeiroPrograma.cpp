#include <stdlib.h>
#include <GL/glut.h>

// ###############  

// pra compilar: g++ -o primeiroPrograma primeiroPrograma.cpp -lGL -lGLU -lglut

// ############### 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



// funcao callback de redesenho da janela de visualizacao

void Desenha(void){
    // Limpa a janela de visualizacao com a cor branca
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    // DEFINE A COR DO DESENHO: VERMELHO
    glColor3f(1,0,0);

    //Desenha um triangulo no centro da janela
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f( 0.0, 0.5, 0);
        glVertex3f(0.5, -0.5, 0);
    glEnd();

    // EXecuta os comandos OpenGL
    glFlush();
}

// FUncao callback chamada para gerenciar eventos de teclas
void Teclado(unsigned char key, int x, int y){
    if(key == 27)
        exit(0);
}

// funcao resonsavel por iniciarlizar parametros e variaveis
void Inicializa(void){
    // Define a janela de visualizacao 2d
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

// Programa Principal
int main(int argc, char** argv){

    // inicializa GLUT
    glutInit(&argc, argv);

    //Define o modo de operacao da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // ESPECIFICA O TAMAHNO INICAL EM PIXELS DA JANELA GLUT
    glutInitWindowSize(400,400);

    //Cria a janela passando como argumento o titulo da mesma
    glutCreateWindow("Primeiro Programa");

    // REGISTRA A FUNCAO CALLBACK DE REDESENHO DA JANELA DE VISUALIZACAO
    glutDisplayFunc(Desenha);

    //Registra a funcao callback para tratamento das teclas ASCII
    glutKeyboardFunc(Teclado);

    // Chama a funcao responsavel por fazer as inicializacoes
    Inicializa();

    // Inicia o processamento e aguarda interacoes do usuario
    glutMainLoop();

    return 0;
}