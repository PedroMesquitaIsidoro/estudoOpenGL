#include <stdlib.h>
#include <GL/glut.h>
#include <cstdio>
#include <cmath>

void Desenha(void){
    float ang;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);

    // especifica o tamanho do ponto
    glPointSize(5.0f);

    // Desenha um circulo de pontos
    glBegin(GL_POINTS);
    for(ang=0;ang<2*M_PI;ang+=M_PI/7.0){
        glVertex2f(20*cos(ang), 20*sin(ang));
    }
    glEnd();

    glFlush();
}

int main(int argc, char **argv){
    //inicializa GLUT
    glutInit(&argc, argv);

    //Definir o mode de operacao da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    // Define a posicao inicial da janela GLUT
    glutInitWindowPosition(0, 0);

    //Define o tamanho inical em pixels: largura x altura da janela GLUT
    glutInitWindowSize(500, 400);

    // Cria a janela e define um nome da mesma
    glutCreateWindow("Pontinhos :)");

    // Define o sistema de coordenadas da janela
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50, 50, -50, 50);

    // REgistra a funcao callback de redesenho da janela de visualizacao
    glutDisplayFunc(Desenha);

    //Inicia o processamento e aguarda interacoes do usuario
    glutMainLoop();

    return 0;
}
