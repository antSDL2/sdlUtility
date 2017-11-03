//Renderer.cpp
#include "Renderer.h"
#include <iostream>
#include <math.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <string.h>

namespace AtUtility {
    namespace Renderer {
        void Clear() {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        SDL_Cursor *CreateCursorFromData(Uint8 *Pixels, int Width, int Height) {
            SDL_Cursor *Cursor = NULL;

            //Make custom array from pixel data
            if (Width > 32 || Height > 32)
                std::cerr << "(Graphics/Functions.cpp) CreateCursorFromData(): Cursor width/height exceeds the recommended maximum of 32x32. Cursor may not display properly." << std::endl;

            Uint8 PixelArray[Width][Height];

            Uint8 Color[4] = {0x00, 0x00, 0x00, 0x00};
            int Column = 0, Row = 0, Counter = 0;

            for (int i=0; i<4*Width*Height; i++) {
                Color[Counter] = Pixels[i];

                Counter++;
                if (Counter >= 4) {
                    //Black
                    if (Color[0] == 0x00 && Color[1] == 0x00 && Color[2] == 0x00 && Color[3] == 0xFF) {
                        PixelArray[Row][Column] = 1;
                    //White
                    } else if (Color[0] == 0xFF && Color[1] == 0xFF && Color[2] == 0xFF && Color[3] == 0xFF) {
                        PixelArray[Row][Column] = 2;
                    //Transparent
                    } else {
                        PixelArray[Row][Column] = 0;
                    }

                    Column++;
                    if (Column >= Width) {
                        Column = 0;
                        Row ++;
                    }

                    Counter = 0;
                    Color[0] = Color[1] = Color[2] = Color[3] = 0x00;
                }
            }

            //Make cursor data from custom array
            Uint8 Data[4*Width];
            Uint8 Mask[4*Width];

            int i = -1;
            for (Row=0; Row<Height; ++Row) {
                for (Column=0; Column<Width; ++Column) {
                    if (Column%8) {
                        Data[i] <<= 1;
                        Mask[i] <<= 1;
                    } else {
                        ++i;
                        Data[i] = Mask[i] = 0;
                    }

                    switch (PixelArray[Row][Column]) {
                        //Black
                        case 1:
                            Data[i] |= 0x01;
                            Mask[i] |= 0x01;
                            break;
                        //White
                        case 2:
                            Mask[i] |= 0x01;
                            break;
                        default:
                            break;
                    }
                }
            }

            Cursor = SDL_CreateCursor(Data, Mask, Width, Height, 0, 0);

            return Cursor;
        }

        void GetStringSize(std::string FontPath, int Size, std::string Text, int &Width, int &Height) {
            if (TTF_Init() != -1) {
                TTF_Font *Font = TTF_OpenFont(FontPath.c_str(), Size);
                if (Font) {
                    if (!TTF_SizeUTF8(Font, Text.c_str(), &Width, &Height)) {
                        //Success
                    }
                    TTF_CloseFont(Font);
                }
            }
        }

        int GetViewportHeight() {
            int Viewport[4];
            glGetIntegerv(GL_VIEWPORT, Viewport);
            return Viewport[3];
        }

        int GetViewportWidth() {
            int Viewport[4];
            glGetIntegerv(GL_VIEWPORT, Viewport);
            return Viewport[2];
        }

        SDL_Surface *LoadImage(std::string Location) {
            return IMG_Load(Location.c_str());
        }

        void RenderDisk(float TargetX, float TargetY, float OuterRadius, float InnerRadius, float Angle, bool Filled) {
            bool InnerDisk = (InnerRadius && InnerRadius != OuterRadius)?true:false;
            bool Sector = (Angle>0)?true:false;

            if (!Angle) Angle = 2*M_PI;

            int Segments = Angle*180.f/M_PI*2;
            float AngleMin = 3*M_PI_2-Angle/2.f;

            float Sin0 = sinf(AngleMin), Cos0 = cosf(AngleMin);
            float OuterX = OuterRadius*Cos0, OuterY = OuterRadius*Sin0, TempX = OuterX;
            float InnerX = InnerRadius*Cos0, InnerY = InnerRadius*Sin0;
            float dSin = sinf(Angle/(float)Segments), dCos = cosf(Angle/(float)Segments);

            //OuterRadius
            if (Filled) glBegin(GL_LINES); else { if (Sector) glBegin(GL_LINE_STRIP); else glBegin(GL_LINE_LOOP); }
            for (int i=0; i<Segments; i++) {
                if (Filled) { if (InnerDisk) glVertex2f(TargetX+InnerX, TargetY+InnerY); else glVertex2f(TargetX, TargetY);}
                glVertex2f(TargetX+OuterX, TargetY+OuterY);

                TempX = OuterX;
                OuterX = dCos*OuterX-dSin*OuterY;
                OuterY = dSin*TempX+dCos*OuterY;

                if (InnerDisk) {
                    TempX = InnerX;
                    InnerX = dCos*InnerX-dSin*InnerY;
                    InnerY = dSin*TempX+dCos*InnerY;
                }

                if (Sector) {
                    if (i == 0 || i == Segments-1) {
                        if (InnerDisk) glVertex2f(TargetX+InnerX, TargetY+InnerY); else glVertex2f(TargetX, TargetY);
                    }
                }
            }
            glEnd();

            //InnerRadius
            if (InnerDisk) {
                InnerX = InnerRadius*Cos0, InnerY = InnerRadius*Sin0;

                if (Sector) glBegin(GL_LINE_STRIP); else glBegin(GL_LINE_LOOP);
                for (int i=0; i<Segments; i++) {
                    glVertex2f(TargetX+InnerX, TargetY+InnerY);

                    TempX = InnerX;
                    InnerX = dCos*InnerX-dSin*InnerY;
                    InnerY = dSin*TempX+dCos*InnerY;
                }
                glEnd();
            }
        }

        void RenderRectangle(float TargetX, float TargetY, float Width, float Height, bool Filled) {
            if (Filled) glBegin(GL_QUADS); else glBegin(GL_LINE_LOOP);
                glVertex2f(TargetX, TargetY); glVertex2f(TargetX+Width, TargetY); glVertex2f(TargetX+Width, TargetY+Height); glVertex2f(TargetX, TargetY+Height);
            glEnd();
        }

        void RenderTriangle(float TargetX, float TargetY, float Width, float Height) {
            //std::cout << "test" << std::endl;
            glBegin(GL_TRIANGLES);
              glVertex2f(TargetX, TargetY);
              glVertex2f(TargetX+Width, TargetY);
              glVertex2f(TargetX+Width/2.f, TargetY+Height);
            glEnd();
        }

        void Reset(GLenum Mode) {
            glMatrixMode(Mode);
            glLoadIdentity();
        }

        void Rotate(GLenum Mode, float Angle, float CenterX, float CenterY) {
            glMatrixMode(Mode);
            glTranslatef(CenterX, CenterY, 0);
            glRotatef(Angle, 0, 0, 1);
            glTranslatef(-CenterX, -CenterY, 0);
        }

        bool SaveScreenshot(std::string Location) {
            bool SaveScreenshot = false;

            int Width = GetViewportWidth();
            int Height = GetViewportHeight();

            SDL_Surface *Screenshot = SDL_CreateRGBSurface(SDL_SWSURFACE, Width, Height, 24, 0x000000FF, 0x0000FF00, 0x00FF0000, 0);
            if (Screenshot) {
                char *Pixels = new char[3*Width*Height];

                glReadBuffer(GL_FRONT);
                glReadPixels(0, 0, Width, Height, GL_RGB, GL_UNSIGNED_BYTE, Pixels);

                for (int i=0; i<Height; i++) {
                    memcpy(((char *)Screenshot->pixels)+Screenshot->pitch *i, Pixels + 3 *Width *(Height-i-1), Width *3);
                }

                if (SDL_SaveBMP(Screenshot, Location.c_str())) {
                    std::cerr << "(Graphics/Functions.cpp) SaveScreenshot(): Screenshot could not be saved. " << SDL_GetError() << "." << std::endl;
                } else SaveScreenshot = true;

                SDL_FreeSurface(Screenshot);
                if (Pixels) delete Pixels;
            } else {
                std::cerr << "(Graphics/Functions.cpp) SaveScreenshot(): Error in creating screenshot surface. " << SDL_GetError() << "." << std::endl;
            }

            return SaveScreenshot;
        }

        void Scale(GLenum Mode, float ScaleX, float ScaleY, float CenterX, float CenterY) {
            glMatrixMode(Mode);
            glTranslatef(-CenterX*(ScaleX-1), -CenterY*(ScaleY-1), 0);
            glScalef(ScaleX, ScaleY, 1);
        }

        void SetClearColor(float R, float G, float B, float A) {
            glClearColor(R, G, B, A);
        }

        void SetClearColor(int R, int G, int B, int A) {
            glClearColor((float)R/255, (float)G/255, (float)B/255, (float)A/255);
        }

        void SetColor(float R, float G, float B, float A) {
            glColor4f(R, G, B, A);
        }

        void SetColor(int R, int G, int B, int A) {
            glColor4f((float)R/255.f, (float)G/255.f, (float)B/255.f, (float)A/255.f);
        }

        void Setup2D(int Width, int Height) {
            glDisable(GL_DEPTH_TEST);
            glEnable(GL_BLEND);
            glEnable(GL_ALPHA_TEST);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_TEXTURE_2D);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            glOrtho(0, Width, Height, 0, 0, 1);

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
        }

        void Setup3D(int Width, int Height) {
            glClearColor(0.f, 0.f, 0.f, 0.f);
            glClearDepth(1.f);
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LEQUAL);
            glShadeModel(GL_SMOOTH);
            glViewport(0, 0, Width, Height);
            glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(90, 1, 0.1, 100);

            /*
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();*/
        }

        void SetViewport(int Width, int Height) {
            glViewport(0, 0, Width, Height);
        }

        void Who() {
            std::cout << "Rendering with OpenGL v" << glGetString(GL_VERSION) << "." << std::endl;
        }
    }
}
