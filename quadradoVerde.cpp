#include <stdlib.h>
#include <GL/glut.h>

// ###############  

// pra compilar: g++ -o quadradoVerde quadradoVerde.cpp -lGL -lGLU -lglut

// ###############


void AlteraTamanhoJanela(GLsizei w, GLsizei h){
    GLsizei largura, altura;

    //evita divisao por zero
    if(h == 0){
        h = 1;
    }

    //atualiza as variaveis
    largura = w;
    altura = h;

    // especifica as dimensoes da Viewport
    glViewport(0, 0, largura, altura);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // EStabelece a janela de selecao mantendo a proporcao com a janela de visualizacao

    if(largura<= altura){
        gluOrtho2D(-40.0f, 40.0f, -40.0f * altura / largura, 40.0f * altura / largura);
    }
    else{
        gluOrtho2D(-40.0f * largura / altura, 40.0f * largura / altura, -40.0f, 40.0f);
    }
}

void DesenhaQuadrado(){
    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-20.0f, -20.0f);
        glVertex2f(20.0f, -20.0f);
        glVertex2f(20.0f, 20.0f);
        glVertex2f(-20.0f, 20.0f);
    glEnd();
}

void DesenhaCena(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    DesenhaQuadrado();
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Quadrado Verde");
    glutDisplayFunc(DesenhaCena);
    glutReshapeFunc(AlteraTamanhoJanela);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
