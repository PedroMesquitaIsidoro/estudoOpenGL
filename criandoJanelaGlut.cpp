#include <stdlib.h>
#include <GL/glut.h>

// ###############  

// pra compilar: g++ -o criandoJanelaGlut criandoJanelaGlut.cpp -lGL -lGLU -lglut

// ###############

int main(int argc, char **argv){

    //Inicializa a GLUT
    glutInit(&argc, argv);
    
    // Define do modo de operacao da glut
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Define a posicao inicial da janela GLUT
    glutInitWindowPosition(0, 0);

    //Define o tamanho inical em pixels: largura x altura da janela GLUT
    glutInitWindowSize(400, 400);

    // Cria a janela e define um nome da mesma
    glutCreateWindow("Criando Janela Glut");


    // loop de eventos
    glutMainLoop();

    return 0;

}