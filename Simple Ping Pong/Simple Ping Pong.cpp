#include <gl/glut.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


static GLint windowSizeX = 800, windowSizeY = 1200;
static GLint orthoSizeX = 600, orthoSizeY = 400;

// game variables
static char sc1[20], score_2[20];
static GLint p1_score = 0, p2_score = 0;
static GLint p1_life = 3, p2_life = 3;
static GLint paddle_boundary = 350, paddle_height = 100, paddile_v = 8.0;
static GLint p1_paddile_y = 0, p2_paddile_y = 0, paddle_x = 595;
static GLfloat ball_v_x = 0, ball_v_y = 0;
static GLint ball_pos_x = 0, ball_pos_y = 0, ball_radius = 20;

void init(void) {
    // initalise display with green colors
    glClearColor(0.0, 0.5, 0.0, 0.0);
    glShadeModel(GL_FLAT);

    srand(time(NULL));   // should only be called once
}

// draw text on screen
void drawStrokeText(char* string, int x, int y, int z)
{
    char* c;
    glPushMatrix();
    glTranslatef(x, y + 8, z);
    // glScalef(0.09f,-0.08f,z);
    for (c = string; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();
}

// draw the center lines spaces 20 pixels apart and with a width of 4 px
void drawCenterLines() {
    // center lines start
    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-1, -350);
    glVertex2f(3, -350);
    glVertex2f(3, -320);
    glVertex2f(-1, -320);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-1, -300);
    glVertex2f(3, -300);
    glVertex2f(3, -250);
    glVertex2f(-1, -250);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, -330);
    glVertex2f(2, -330);
    glVertex2f(2, -310);
    glVertex2f(-2, -310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, -290);
    glVertex2f(2, -290);
    glVertex2f(2, -270);
    glVertex2f(-2, -270);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, -250);
    glVertex2f(2, -250);
    glVertex2f(2, -230);
    glVertex2f(-2, -230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, -210);
    glVertex2f(2, -210);
    glVertex2f(2, -190);
    glVertex2f(-2, -190);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, -170);
    glVertex2f(2, -170);
    glVertex2f(2, -150);
    glVertex2f(-2, -150);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, -130);
    glVertex2f(2, -130);
    glVertex2f(2, -110);
    glVertex2f(-2, -110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, -90);
    glVertex2f(2, -90);
    glVertex2f(2, -70);
    glVertex2f(-2, -70);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, -50);
    glVertex2f(2, -50);
    glVertex2f(2, -30);
    glVertex2f(-2, -30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, -10);
    glVertex2f(2, -10);
    glVertex2f(2, 10);
    glVertex2f(-2, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, 30);
    glVertex2f(2, 30);
    glVertex2f(2, 50);
    glVertex2f(-2, 50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, 70);
    glVertex2f(2, 70);
    glVertex2f(2, 90);
    glVertex2f(-2, 90);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, 110);
    glVertex2f(2, 110);
    glVertex2f(2, 130);
    glVertex2f(-2, 130);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, 150);
    glVertex2f(2, 150);
    glVertex2f(2, 170);
    glVertex2f(-2, 170);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, 190);
    glVertex2f(2, 190);
    glVertex2f(2, 210);
    glVertex2f(-2, 210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, 230);
    glVertex2f(2, 230);
    glVertex2f(2, 250);
    glVertex2f(-2, 250);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, 270);
    glVertex2f(2, 270);
    glVertex2f(2, 290);
    glVertex2f(-2, 290);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, 310);
    glVertex2f(2, 310);
    glVertex2f(2, 330);
    glVertex2f(-2, 330);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, 350);
    glVertex2f(2, 350);
    glVertex2f(2, 370);
    glVertex2f(-2, 370);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.2, 1.2, 1.2);
    glVertex2f(-2, 390);
    glVertex2f(2, 390);
    glVertex2f(2, 410);
    glVertex2f(-2, 410);
    glEnd();
    // center lines end
}

// x, y is the top left corodinate of the paddle
void drawPaddle(int x, int y) {
    glPushMatrix();

    glTranslatef(x, y, 0);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    int height = paddle_height / 2;
    glVertex2f(-5, height);
    glVertex2f(5, height);
    glVertex2f(5, -height);
    glVertex2f(-5, -height);
    glEnd();

    glPopMatrix();
}

void drawBall(int x, int y) {
    glPushMatrix();

    glTranslatef(x, y, 0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(ball_radius, 20, 16);

    glPopMatrix();
}

// main display functions
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // create center lines
    drawCenterLines();

    // draw left paddle at (-paddle_x, p1_paddile_y)
    drawPaddle(-paddle_x, p1_paddile_y);
    // draw right paddle at (paddle_x, p2_paddile_y)
    drawPaddle(paddle_x, p2_paddile_y);

    // draw the ball (ball_pos_x, ball_pos_y) - varies in each frame
    drawBall(ball_pos_x, ball_pos_y);

    // draw the score on the left for p 1
    snprintf(sc1, sizeof(sc1), "%d", p1_score);
    drawStrokeText(sc1, -300, 200, 0);

    // draw the score on the left for p 1
    snprintf(score_2, sizeof(score_2), "%d", p2_score);
    drawStrokeText(score_2, 200, 200, 0);

    // swap the current frame with the drawn frame
    glutSwapBuffers();
    glFlush();
}

void startGame(void) {

    // move the ball
    ball_pos_x += ball_v_x;
    ball_pos_y += ball_v_y;

    // ball hits the top or bottom
    if (ball_pos_y + ball_radius > orthoSizeY || ball_pos_y - ball_radius < -orthoSizeY)
        ball_v_y = -ball_v_y;

    // ball hits the left paddle
    if (ball_pos_x - ball_radius - 5 < -paddle_x && ball_pos_x - ball_radius < -paddle_x)
        if (ball_pos_y < p1_paddile_y + paddle_height && ball_pos_y > p1_paddile_y - paddle_height) {
            ball_v_x = -ball_v_x;
        }

    // ball hits the right paddle
    if (ball_pos_x + ball_radius + 5 > paddle_x && ball_pos_x + ball_radius < paddle_x)
        if (ball_pos_y < p2_paddile_y + paddle_height && ball_pos_y > p2_paddile_y - paddle_height)
            ball_v_x = -ball_v_x;

    // p 1 scores
    if (ball_pos_x + ball_radius > orthoSizeX) {
        p1_score++;
        printf("P 1 = %d \n", p1_score);
        ball_v_x = -ball_v_x;
    }

    // p 2 scores
    if (ball_pos_x - ball_radius < -orthoSizeX) {
        p2_score++;
        printf("P 2 = %d \n", p2_score);
        ball_v_x = -ball_v_x;
    }

    glutPostRedisplay();
}

// reshape the display
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-orthoSizeX, orthoSizeX, -orthoSizeY, orthoSizeY, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// on mouse button click
void mouse(int button, int state, int x, int y) {
    switch (button) {
        // left button - initialize random v between (ran(5) - rand(3))
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            ball_v_x = (rand() % 5) - (rand() % 3);
        ball_v_y = (rand() % 5) - (rand() % 3);

        // keep on calling the callback to move the ball and check boundary conditions
        glutIdleFunc(startGame);
        break;
        // middle button to reset the ball, paddle and score
    case GLUT_MIDDLE_BUTTON:
        // reset ball, paddle and p scores
        ball_pos_x = ball_pos_y = 0;
        p1_paddile_y = p2_paddile_y = 0;
        p1_score = p2_score = 0;
        if (state == GLUT_DOWN)
            // remove the call back so that game stops
            glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // move p 1 paddile up
    case 'q':
        if (p1_paddile_y < paddle_boundary)
            p1_paddile_y += paddile_v;
        glutPostRedisplay();
        break;
        // move p 1 paddile down
    case 'a':
        if (p1_paddile_y > -paddle_boundary)
            p1_paddile_y -= paddile_v;
        glutPostRedisplay();
        break;
        // move p 2 paddile up
    case 'o':
        if (p2_paddile_y < paddle_boundary)
            p2_paddile_y += paddile_v;
        glutPostRedisplay();
        break;
        // move p 2 paddile down
    case 'l':
        if (p2_paddile_y > -paddle_boundary)
            p2_paddile_y -= paddile_v;
        glutPostRedisplay();
        break;
        // exit on esc
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

/*
* Request double buffer display mode.
* Register mouse input callback functions
*/
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(10, 10);
    glutCreateWindow(argv[0]);
    init();

    // call back functions for rendering, reshape
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // callback on mouse click and keyboard input
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}