#include <jni.h>
#include <string>
#include <GLES2/gl2.h>
#include <GLES/gl.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_user_lab5_JNIWrapper_onsurfacecreated(JNIEnv *env, jclass cls) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrthof(-8, 8, -8, 8, -8, 8);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1, 1, 0, 0);
    glClearDepthf(1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_user_lab5_JNIWrapper_onsurfacechanged(JNIEnv *env, jclass cls, jint width,
                                                       jint height) {
}

GLfloat a[12] = {
        -1, 1, 0,
        -1, -1, 0,
        1, -1, 0,
        1, 1, 0
};

GLfloat texCoords[8] = { // Texture coords for the above face (NEW)
        0.0f, 1.0f,  // A. left-bottom (NEW)
        1.0f, 1.0f,  // B. right-bottom (NEW)
        0.0f, 0.0f,  // C. left-top (NEW)
        1.0f, 0.0f   // D. right-top (NEW)
};

int angle = 0;

int textureid;

extern "C"
JNIEXPORT void JNICALL Java_com_example_user_lab5_JNIWrapper_ondrawframe(JNIEnv *env, jclass cls) {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0, 0, -1);
    //glScalef(0.5, 0.5, 0.5);

    glColor4f(1, 1, 1, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_TEXTURE_2D);

    //glEnableClientState(GL_COLOR_ARRAY);
    angle = (angle == 360) ? 0 : angle + 2;
    glRotatef(angle, 1, 1, 0);

    //лицевая грань
    glPushMatrix();
    //glColor4f(1, 1, 0, 1);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();


    //задняя
    glPushMatrix();
    //glColor4f(1, 0, 1, 1);
    glTranslatef(0, 0, -2);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();
//верхняя
    glPushMatrix();
    //glColor4f(1, 1, 1, 1);
    glTranslatef(0, 1, -1);
    glRotatef(90, 1, 0, 0);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();

//нижняя
    glPushMatrix();
    //glColor4f(0, 1, 1, 1);
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, -1, 1);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();
//левая

    glPushMatrix();
    //glColor4f(1, 0, 0, 1);
    glRotatef(90, 0, 1, 0);
    glTranslatef(1, 0, -1);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();

//правая
    glPushMatrix();
    //glColor4f(0, 0, 1, 1);
    glRotatef(90, 0, 1, 0);
    glTranslatef(1, 0, 1);
    glVertexPointer(3, GL_FLOAT, 0, a);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    //glDisableClientState(GL_COLOR_ARRAY);
}